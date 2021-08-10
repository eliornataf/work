#include <stdio.h>
#include <stdlib.h> /* system, malloc */
#include <string.h> /* strcpy */
#include "clientManager.h" /* Client_t Manager Header */
#include "genericDoublyLinkedList.h" /* Generic Doubly Linked List Header */
#include "tcpClient.h" /* TCP Client_t Header */
#include "protocol.h" /* Protocol Header */
#include "ui.h" /* UI Header */

#define SERVER_PORT (1025)
#define SOCKET_ERROR (-1)
#define BUFFER_SIZE (4096)
#define USER_SIZE (256)
#define CMD_LENGTH (1024)

/******************************************************/

struct Client
{
    byte m_clientName[MAX_LENGTH];
    int m_clientSocket;
    List_t *m_clientPidsList;
} Client_t;

struct ClientGroupsPID
{
    byte m_groupName[MAX_LENGTH];
    int m_chatSenderPID;
    int m_charReceiverPID;
} ClientGroupsPID_t;

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void StartMainMenu(Client_t *client);
static ClientManagerError_t RegisterAndlogin(Client_t *client, MainMenuOptions_t mainMenuOption);
static int ChooseNameAndPassword(UserData_t *userData);
static void PrintResponseMessageRegisterOrLogin(ResponseMessage_t *responseMessage);
static void StartGroupMenu(Client_t *client);
static ClientManagerError_t GroupCreate(Client_t *client);
static ClientManagerError_t JoinGroup(Client_t *client);
static int ChooseUserAndGroupName(GroupData_t *groupData);
static ClientManagerError_t LeaveGroup(Client_t *client);
static ClientManagerError_t ClientLogOut(Client_t *client);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Status_t RunClientManager(void)
{
    Client_t newClient;
    int clientSocket;

    clientSocket = ClientInit("127.0.0.1", SERVER_PORT);
    if (ERROR == clientSocket)
    {
        PrintFailedToConnectServer();
        return FAILURE; 
    }

    newClient.m_clientSocket = clientSocket;
    newClient.m_clientPidsList = ListCreate();
    if (!newClient.m_clientPidsList)
    {
        DestroyClient(clientSocket);
        return FAILURE;
    }

    StartMainMenu(&newClient);

    PrintExitingApp();

    ListDestory(&newClient.m_clientPidsList, NULL);
    DestroyClient(clientSocket);
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void StartMainMenu(Client_t *_client)
{
    int userInput = MAIN_MENU_OPTION_START_MENU;
    ClientManagerError_t status;

    while (1)
    {
        PrintMainMenu();
        UIChooseMenuOption(&userInput);

        switch(userInput)
        {
            case MAIN_MENU_OPTION_REGISTER:
                if (CLIENT_MANAGER_CRITICAL_ERROR == Register(_client, MAIN_MENU_OPTION_REGISTER))
                {
                    return;
                }
                break;

            case MAIN_MENU_OPTION_LOGIN:
                status = Login(_client, MAIN_MENU_OPTION_LOGIN);
                if (CLIENT_MANAGER_SUCCESS == status)
                {
                    if (FAILURE == startGroupMenu(_client))
                    {
                        return;
                    }
                }
                break;

            case MAIN_MENU_OPTION_EXIT:
                return;

            default: 
                PrintUserChooseIllegalInput();
        }
    }
}

static ClientManagerError_t Register(Client_t *_client, MainMenuOptions_t _mainMenuOption)
{
    UserData_t userData;
    ResponseMessage_t responseMessage;
    byte buffer[MAX_LENGTH];
    size_t packSize, sentSize, receivedSize, unpackSize;

    if (SUCCESS != ChooseNameAndPassword(&userData))
    {
        return CLIENT_MANAGER_ILLEGAL_INPUT;
    }

    strcpy(_client->m_userName, userData.m_userName);

    packSize = PackMessage(TAG_USER_REGISTER, &userData, buffer);        

    if (!packSize)
    {
        return CLIENT_MANAGER_PACK_FAILED;
    }

    sentSize = SendMessageToServer(_client->m_clientSocket, buffer, packSize);

    if (!IsCompleteMassage(buffer, sentSize)) 
    {
        return CLIENT_MANAGER_SEND_MESSAGE_FAILED;
    }

    receivedSize = ReceiveMessageFromServer(_client->m_clientSocket, buffer, sizeof(buffer));

    unpackSize = UnPackMessage(buffer, &responseMessage); 

    if (!unpackSize)
    {
        return CLIENT_MANAGER_UNPACK_FAILED;
    }

    if (!IsCompleteMassage(buffer, unpackSize))
    {
        return CLIENT_MANAGER_RECEIVED_FAILED;
    }

    switch (_responseMessage.m_responeMessage)
    {
        case REGISTER_USER_CREATE_ERROR:
            PrintRegisterCreationErr();
            return CLIENT_MANAGER_CRITICAL_ERROR;

        case REGISTER_USER_ALREADY_EXIST:
            PrintRegisterUserExists();
            return CLIENT_MANAGER_FAILED;
    }

    PrintRegisterSuccess();

    return CLIENT_MANAGER_SUCCESS;
}

static ClientManagerError_t Login(Client_t *_client, MainMenuOptions_t _mainMenuOption)
{
    UserData_t userData;
    ResponseMessage_t responseMessage;
    byte buffer[MAX_LENGTH];
    size_t packSize, sentSize, receivedSize, unpackSize;

    if (SUCCESS != ChooseNameAndPassword(&userData))
    {
        return CLIENT_MANAGER_ILLEGAL_INPUT;
    }

    packSize = PackMessage(TAG_USER_LOGIN, &userData, buffer);

    if (!packSize)
    {
        return CLIENT_MANAGER_PACK_FAILED;
    }

    sentSize = SendMessageToServer(_client->m_clientSocket, buffer, packSize);

    if (!IsCompleteMassage(buffer, sentSize)) 
    {
        return CLIENT_MANAGER_SEND_MESSAGE_FAILED;
    }

    receivedSize = ReceiveMessageFromServer(_client->m_clientSocket, buffer, sizeof(buffer));

    unpackSize = UnPackMessage(buffer, &responseMessage); 

    if (!unpackSize)
    {
        return CLIENT_MANAGER_UNPACK_FAILED;
    }

    if (!IsCompleteMassage(buffer, unpackSize))
    {
        return CLIENT_MANAGER_RECEIVED_FAILED;
    }

    switch (_responseMessage.m_responeMessage)
    {
        case LOGIN_USER_NOT_FOUND:
            PrintLoginUserNotFound();
            return CLIENT_MANAGER_FAILED;

        case LOGIN_USER_INCORRECT_PASSWORD:
            PrintLoginWrongPassword();
            return CLIENT_MANAGER_FAILED;

        case LOGIN_USER_ALREADY_CONNECTED:
            PrintLoginUserAlreadyConnected();
            return CLIENT_MANAGER_FAILED;
    }

    PrintLoginUserLoginSuccess();

    return CLIENT_MANAGER_SUCCESS;
}

static void StartGroupMenu(Client_t *_client)
{
    int userInput = GROUP_MENU_OPTION_START_MENU;
    ClientManagerError_t status;

    while (1)
    {
        PrintGroupMenuGroup();
        UIChooseMenuOption(&userInput);

        switch(userInput)
        {
            case GROUP_MENU_OPTION_CREATE_GROUP:
                if (CLIENT_MANAGER_CRITICAL_ERROR == GroupCreate(_client))
                {
                    return FAILURE;
                }
                break;

            case GROUP_MENU_OPTION_JOIN_GROUP:
                if (CLIENT_MANAGER_CRITICAL_ERROR == JoinGroup(_client))
                {
                    return FAILURE;
                }
                break;

            case GROUP_MENU_OPTION_LEAVE_GROUP:
                if (CLIENT_MANAGER_CRITICAL_ERROR == LeaveGroup(_client))
                {
                    return FAILURE;
                }
                break;

            case GROUP_MENU_OPTION_LOGOUT:
                if (CLIENT_MANAGER_SUCCESS == ClientLogOut(_client))
                {
                    return;
                }

            default: 
                PrintUserChooseIllegalInput();
        }
    }
}

static ClientManagerError_t GroupCreate(Client_t *_client)
{
    CreateGroup_t createGroup;
    ResponseMessage_t responseMessage;
    byte groupName[MAX_LENGTH];
    byte buffer[MAX_LENGTH];
    size_t packSize, sentSize, receivedSize, unpackSize;

    PrintChooseGroupName();

    if (SUCCESS != UIinputNameOrPasswordOrGroup(&groupName))
    {
        return CLIENT_MANAGER_ILLEGAL_INPUT;
    }

    packSize = PackMessage(TAG_CREATE_GROUP, &createGroup, buffer);

    if (!packSize)
    {
        return CLIENT_MANAGER_PACK_FAILED;
    }

    sentSize = SendMessageToServer(_client->m_clientSocket, buffer, packSize);

    if (!IsCompleteMassage(buffer, sentSize)) 
    {
        return CLIENT_MANAGER_SEND_MESSAGE_FAILED;
    }

    receivedSize = ReceiveMessageFromServer(_client->m_clientSocket, buffer, sizeof(buffer));

    unpackSize = UnPackMessage(buffer, &responseMessage); 

    if (!unpackSize)
    {
        return CLIENT_MANAGER_UNPACK_FAILED;
    }

    if (!IsCompleteMassage(buffer, unpackSize))
    {
        return CLIENT_MANAGER_RECEIVED_FAILED;
    }

    switch (responseMessage.m_responeMessage)
    {
        case GROUP_CREATE_GROUP_ALREADY_EXIST:
            PrintCreateGroupGroupAlreadyExist();
            return CLIENT_MANAGER_FAILED;

        case GROUP_CREATE_CREATE_ERROR:
            PrintCreateGroupCreateError();
            return CLIENT_MANAGER_CRITICAL_ERROR;
    }

    PrintCreateGroupSuccess();

    return CLIENT_MANAGER_SUCCESS;
}

static ClientManagerError_t JoinGroup(Client_t *_client)
{
    GroupData_t groupData;
    JoinGroupResponse_t joinGroupResponse;
    byte userName[MAX_LENGTH];
    byte groupName[MAX_LENGTH];
    byte buffer[MAX_LENGTH];
    size_t packSize, sentSize, receivedSize, unpackSize;
    FILE *pidFile = NULL;
    ClientGroupsPID_t *newClientGroupPid = NULL;

    if(SUCCESS != ChooseUserAndGroupName(&groupData))
    {
        return CLIENT_MANAGER_ILLEGAL_INPUT;
    }

    packSize = PackMessage(TAG_USER_JOIN_GROUP, &groupData, buffer);

    if (!packSize)
    {
        return CLIENT_MANAGER_PACK_FAILED;
    }

    sentSize = SendMessageToServer(_client->m_clientSocket, buffer, packSize);

    if (!IsCompleteMassage(buffer, sentSize)) 
    {
        return CLIENT_MANAGER_SEND_MESSAGE_FAILED;
    }

    receivedSize = ReceiveMessageFromServer(_client->m_clientSocket, buffer, sizeof(buffer));

    unpackSize = UnPackMessage(buffer, &joinGroupResponse); 

    if (!unpackSize)
    {
        return CLIENT_MANAGER_UNPACK_FAILED;
    }

    if (!IsCompleteMassage(buffer, unpackSize))
    {
        return CLIENT_MANAGER_RECEIVED_FAILED;
    }

    switch (joinGroupResponse.m_responeMessage)
    {
        case JOIN_GROUP_GROUP_NOT_FOUND:
        PrintJoinGroupGroupNotFound();
        return CLIENT_MANAGER_FAILED;

        case JOIN_GROUP_JOIN_ERROR:
        PrintJoinGroupCreateError();
        return CLIENT_MANAGER_CRITICAL_ERROR;

        case JOIN_GROUP_USER_NOT_FOUND:
        PrintJoinGroupUserNotFound();
        return CLIENT_MANAGER_FAILED;

        case JOIN_GROUP_USER_IS_ALREADY_JOIN:
        PrintJoinUserIsAlreadyJoinGroup();
        return CLIENT_MANAGER_FAILED;
    }

    StartChat(joinGroupResponse.m_groupIPAddress, joinGroupResponse.m_groupPort, groupData.m_userName, groupData.m_groupName);

    newClientGroupPid = (ClientGroupsPID_t*)malloc(sizeof(ClientGroupsPID_t));
    if (!newClientGroupPid)
    {
        return CLIENT_MANAGER_CRITICAL_ERROR;
    }

    pidFile = fopen("senderPidFile", "w");
    if (!pidFile)
    {
        free(newClientGroupPid);
        return CLIENT_MANAGER_CRITICAL_ERROR;
    }

    fscanf(pidFile, "%d", newClientGroupPid->m_chatSenderPID);
    close(pidFile);

    pidFile = fopen("receiverPidFile", "w");
    if (!pidFile)
    {
        free(newClientGroupPid);
        return CLIENT_MANAGER_CRITICAL_ERROR;
    }

    fscanf(pidFile, "%d", newClientGroupPid->m_charReceiverPID);
    close(pidFile);

    strcpy(newClientGroupPid->m_groupName, groupData.m_groupName);

    if (DLIST_SUCCESS != ListPushTail(_client->m_clientPidsList , newClientGroupPid))
    {
        free(newClientGroupPid);
        return CLIENT_MANAGER_CRITICAL_ERROR;
    }

    PrintJoinGroupSuccess();

    return CLIENT_MANAGER_SUCCESS;
}

static int ChooseUserAndGroupName(GroupData_t *_groupData)
{
    byte userName[MAX_LENGTH];
    byte groupName[MAX_LENGTH];

    PrintChooseUserName();

    if (SUCCESS != UIinputNameOrPasswordOrGroup(userName))
    {
        return FAILURE;
    }

    PrintChooseGroupName();

    if (SUCCESS != UIinputNameOrPasswordOrGroup(groupName))
    {
        return FAILURE;
    }

    strcpy((char*)_groupData->m_userName, (char*)userName);
    strcpy((char*)_groupData->m_groupName, (char*)groupName);

    return SUCCESS;
}

static ClientManagerError_t LeaveGroup(Client_t *_client)
{
    GroupData_t groupData;
    ResponseMessage_t responseMessage;
    byte userName[MAX_LENGTH];
    byte groupName[MAX_LENGTH];
    byte buffer[MAX_LENGTH];
    size_t packSize, sentSize, receivedSize, unpackSize;

    if(SUCCESS != ChooseUserAndGroupName(&groupData))
    {
        return CLIENT_MANAGER_ILLEGAL_INPUT;
    }

    packSize = PackMessage(TAG_USER_LEAVE_GROUP, &groupData, buffer);

    if (!packSize)
    {
        return CLIENT_MANAGER_PACK_FAILED;
    }

    sentSize = SendMessageToServer(_client->m_clientSocket, buffer, packSize);

    if (!IsCompleteMassage(buffer, sentSize)) 
    {
        return CLIENT_MANAGER_SEND_MESSAGE_FAILED;
    }

    receivedSize = ReceiveMessageFromServer(_client->m_clientSocket, buffer, sizeof(buffer));

    unpackSize = UnPackMessage(buffer, &responseMessage); 

    if (!unpackSize)
    {
        return CLIENT_MANAGER_UNPACK_FAILED;
    }

    if (!IsCompleteMassage(buffer, unpackSize))
    {
        return CLIENT_MANAGER_RECEIVED_FAILED;
    }

    switch (responseMessage.m_responeMessage)
    {
        case LEAVE_GROUP_NOT_FOUND:
            PrintLeaveGroupNotFound();
            return CLIENT_MANAGER_FAILED;

        case LEAVE_GROUP_ERROR:
            PrintLeaveGroupError();
            return CLIENT_MANAGER_CRITICAL_ERROR;
    }

    if (SUCCESS != SearchAndFreeGroup(_client, groupData.m_groupName))
    {
        return CLIENT_MANAGER_CRITICAL_ERROR;
    }

    PrintLeaveGroupSuccess();

    return CLIENT_MANAGER_SUCCESS;
}

static Status_t SearchAndFreeGroup(Client_t *_client, byte *_groupName)
{   
    ListIter_t iterRunner = NULL;
    ListIter_t iterEnd = NULL;
    ClientGroupsPID_t *currGroup = NULL;

    iterRunner = ListIterBegin(_client->m_listOfGroups);
    iterEnd = ListIterEnd(_client->m_listOfGroups);

    while (!ListIterEqual(iterRunner, iterEnd))
    {
        currGroup = (ClientGroupsPID_t*)ListIterGet(iterRunner);

        if (!strcmp((char*)currGroup->m_groupName, (char*)_groupName))
        {
            ListIterRemove((ListIter_t)currGroup);
            KillPidsAndFree(currGroup);
            return SUCCESS;
        }
    
        iterRunner = ListIterNext(iterRunner);
    }

    return FAILURE;
}

static ClientManagerError_t ClientLogOut(Client_t *_client)
{
    byte userName[MAX_LENGTH];
    byte buffer[MAX_LENGTH];
    UserLogout_t userLogout;
    ResponseMessage_t responseMessage;
    size_t packSize, sendSize, receivedSize, unpackSize;

    PrintChooseUserName();

    if (SUCCESS != UIinputNameOrPasswordOrGroup(userName))
    {
        return CLIENT_MANAGER_ILLEGAL_INPUT;
    }

    strcpy((char*)userLogout.m_userName, (char*)userName);

    packSize = PackMessage(TAG_USER_LOGOUT, &userLogout, buffer);

    if (!packSize)
    {
        return CLIENT_MANAGER_PACK_FAILED;
    }

    sendSize = SendMessageToServer(_client->m_clientSocket, buffer, packSize);

    if (!IsCompleteMassage(buffer, sendSize)) 
    {
        return CLIENT_MANAGER_SEND_MESSAGE_FAILED;
    }

    receivedSize = ReceiveMessageFromServer(_client->m_clientSocket, buffer, sizeof(buffer));

    unpackSize = UnPackMessage(buffer, &responseMessage); 

    if (!unpackSize)
    {
        return CLIENT_MANAGER_UNPACK_FAILED;
    }

    if (!IsCompleteMassage(buffer, unpackSize))
    {
        return CLIENT_MANAGER_RECEIVED_FAILED;
    }

    switch (responseMessage.m_responeMessage)
    {
        case LEAVE_GROUP_NOT_FOUND:
            PrintLogOutNotFound();
            return CLIENT_MANAGER_FAILED;

        case LEAVE_GROUP_ERROR:
            PrintLogOutError();
            return CLIENT_MANAGER_CRITICAL_ERROR;
    }

    if (CLIENT_MANAGER_SUCCESS != CloseAllGroupChatWhenLogOut(_client, GroupData, userLogout.m_userName)
    {
        PrintLogOutError();
        return CLIENT_MANAGER_CRITICAL_ERROR;
    }

    PrintLogoutSuccess();

    return CLIENT_MANAGER_SUCCESS;
}

static Status_t CloseAllGroupChatWhenLogOut(Client_t *_client, byte *_userName)
{
    GroupData_t groupData;
    ResponseMessage_t responseMessage;
    byte userName[MAX_LENGTH];
    byte groupName[MAX_LENGTH];
    byte buffer[MAX_LENGTH];
    size_t packSize, sentSize, receivedSize, unpackSize;
    ListIter_t iterRunner = ListIterBegin(_client->m_listOfGroups);;
    ListIter_t iterEnd = ListIterEnd(_client->m_listOfGroups);
    ClientGroupsPID_t *currGroup = NULL;

    while (!ListIterEqual(iterRunner, iterEnd))
    {
        currGroup = (ClientGroupsPID_t*)ListIterGet(iterRunner);

        strcpy(groupData.m_groupName, currGroup->m_groupName);
        strcpy(groupData.m_userName, (char*)_userName);

        ListIterRemove((ListIter_t)currGroup);

        packSize = PackMessage(TAG_USER_LEAVE_GROUP, &groupData, buffer);

        if (!packSize)
        {
            return CLIENT_MANAGER_PACK_FAILED;
        }

        sentSize = SendMessageToServer(_client->m_clientSocket, buffer, packSize);

        if (!IsCompleteMassage(buffer, sentSize)) 
        {
            return CLIENT_MANAGER_SEND_MESSAGE_FAILED;
        }

        receivedSize = ReceiveMessageFromServer(_client->m_clientSocket, buffer, sizeof(buffer));

        unpackSize = UnPackMessage(buffer, &responseMessage); 

        if (!unpackSize)
        {
            return CLIENT_MANAGER_UNPACK_FAILED;
        }

        if (!IsCompleteMassage(buffer, unpackSize))
        {
            return CLIENT_MANAGER_RECEIVED_FAILED;
        }

        switch (responseMessage.m_responeMessage)
        {
            case LEAVE_GROUP_NOT_FOUND:
                PrintLeaveGroupNotFound();
                return CLIENT_MANAGER_FAILED;

            case LEAVE_GROUP_ERROR:
                PrintLeaveGroupError();
                return CLIENT_MANAGER_CRITICAL_ERROR;
        }

        KillPidsAndFree(currGroup);

        PrintLeaveGroupSuccess();

        iterRunner = ListIterNext(iterRunner);
    }

    return CLIENT_MANAGER_SUCCESS;
}

static void KillPidsAndFree(ClientGroupsPID_t *_currGroupPids)
{
    kill(_currGroupPids->m_chatSenderPID, 9);
    kill(_currGroupPids->m_charReceiverPID, 9);
    free(_currGroupPids);
}   

static void StartChat(char *_groupIp, char *_groupPort, char* _userName, char *_groupName)
{
    char senderCommandLineArguments[CMD_LENGTH];
    char receiverCommandLineArguments[CMD_LENGTH];

    sprintf(senderCommandLineArguments, "%s %d %s %s %s", "gnome-terminal --geometry 30x20+400+300 -- ./ChatSender.out", _groupPort, _groupIp, _userName, _groupName);
    sprintf(receiverCommandLineArguments, "%s %d %s %s", "gnome-terminal --geometry 30x20+900+300 -- ./ChatReceiver.out",_groupPort , _groupIp, _groupName);

    system(senderCommandLineArguments);
    system(receiverCommandLineArguments);
}