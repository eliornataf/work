#include <stdlib.h> /* malloc, free */
#include <string.h>
#include "serverManager.h" /* Server Manager Header */
#include "groupManager.h" /* Group Manager Header */
#include "tcpGenericServer.h" /* TCP Generic Server Header */
#include "userManager.h" /* User Manager Header */
#include "protocol.h" /* Protocol Header */

#define SERVER_PORT (1025)
#define QUEUE_LENGTH (1024)
#define MAX_CONNECT_CLIENTS (1020)

#define SUCCESS (0)
#define FAILURE (1)
#define BUFFER_SIZE (4096)

#define MAX_LENGTH (256)

#define IS_NOT_RESPONSE_MESSAGE (0)
#define IS_RESPONSE_MESSAGE (1)

/******************************************************/

struct ServerManager
{
    UserManager_t *m_userManager;
    GroupManager_t *m_groupManager;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void ClientMessageFunc(TCPServer_t *tcpServer, int clientID, void *message, void *appContext);
static Status_t ClientMessageRegister(byte *message, ServerManager_t *serverManager, TCPServer_t *tcpServer, int clientID);

static Status_t ClientMessageLogin(byte *message, ServerManager_t *serverManager, TCPServer_t *tcpServer, int clientID);
static Status_t ClientMessageCreateGroup(byte *message, ServerManager_t *serverManager, TCPServer_t *tcpServer, int clientID);
static Status_t ClientMessageJoinGroup(byte *message, ServerManager_t *serverManager, TCPServer_t *tcpServer, int clientID);
static Status_t ClientMessageLeaveGroup(byte *message, ServerManager_t *serverManager, TCPServer_t *tcpServer, int clientID);
static Status_t ClientMessageLogout(byte *message, ServerManager_t *serverManager, TCPServer_t *tcpServer, int clientID);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Status_t RunServerManager(void)
{
    TCPServer_t *tcpServer = NULL;
    ServerManager_t *serverManager = NULL;
    GroupManager_t *groupManager = NULL;

    serverManager = (ServerManager_t*)malloc(sizeof(ServerManager_t));
    if (!serverManager)
    {
        return FAILURE;
    }

    serverManager->m_userManager = CreateUserManager();
    if (!serverManager->m_userManager)
    {
        free(serverManager);
        return FAILURE;
    }

    serverManager->m_groupManager = CreateGroupManager();
    if (!serverManager->m_groupManager)
    {
        DestroyUserManager(&serverManager->m_userManager);
        free(serverManager);
        return FAILURE;
    }

    tcpServer = CreateServer("127.0.0.1", SERVER_PORT, QUEUE_LENGTH, MAX_CONNECT_CLIENTS, NULL, NULL, ClientMessageFunc, NULL, serverManager);
    if (!tcpServer)
    {
        DestroyUserManager(&serverManager->m_userManager);
        DestroyGroupManager(&serverManager->m_groupManager);
        free(serverManager);
        return FAILURE;
    }

    RunServer(tcpServer);

    DestroyServer(&tcpServer);
    DestroyUserManager(&serverManager->m_userManager);
    DestroyGroupManager(&serverManager->m_groupManager);
    free(serverManager);

    return SUCCESS;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

/****************** ClientMessage ******************/

static void ClientMessageFunc(TCPServer_t *_tcpServer, int _clientID, void *_message, void *_appContext)
{
    switch(GetMessageTag((byte*)_message))
    {
        case TAG_USER_REGISTER:
            ClientMessageRegister((byte*)_message, (ServerManager_t*)_appContext, _tcpServer, _clientID);
            break;

        case TAG_USER_LOGIN:
            ClientMessageLogin((byte*)_message, (ServerManager_t*)_appContext, _tcpServer, _clientID);
            break;

        case TAG_CREATE_GROUP:
            ClientMessageCreateGroup((byte*)_message, (ServerManager_t*)_appContext, _tcpServer, _clientID);

        case TAG_USER_JOIN_GROUP:
            ClientMessageJoinGroup((byte*)_message, (ServerManager_t*)_appContext, _tcpServer, _clientID);
            break;

        case TAG_USER_LEAVE_GROUP:
            ClientMessageLeaveGroup((byte*)_message, (ServerManager_t*)_appContext, _tcpServer, _clientID);
            break;

        case TAG_USER_LOGOUT:
            ClientMessageLogout((byte*)_message, (ServerManager_t*)_appContext, _tcpServer, _clientID);
            break;
    }
}

static Status_t ClientMessageRegister(byte *_message, ServerManager_t *_serverManager, TCPServer_t *_tcpServer, int _clientID)
{
    UserData_t userData;
    ResponseMessage_t responseMessage;
    byte buffer[BUFFER_SIZE];
    size_t packSize, serverMessageSize;
    UserManagerError_t status;

    UnPackMessage(_message, &userData);

    status = UserRegister(_serverManager->m_userManager, userData.m_userName, userData.m_userPassword);

    switch (status)
    {
        case USER_MANAGER_USER_ALREADY_EXIST:
            responseMessage.m_responeMessage = REGISTER_USER_ALREADY_EXIST;
            break;

        case USER_MANAGER_SUCCESS:
            responseMessage.m_responeMessage = REGISTER_USER_SUCCESS;
            break;
        
        default: responseMessage.m_responeMessage = REGISTER_USER_CREATE_ERROR;
    }

    packSize = PackMessage(TAG_RESPONSE_MESSAGE, &responseMessage, buffer);

    if (!packSize)
    {
        return FAILURE;
    }

    serverMessageSize = ServerSendMessage(_tcpServer, _clientID, buffer, packSize);

    if (!IsCompleteMassage((byte*)responseMessage, serverMessageSize))
    {
        return FAILURE;
    }

    return SUCCESS;
}

static Status_t ClientMessageLogin(byte *_message, ServerManager_t *_serverManager, TCPServer_t *_tcpServer, int _clientID)
{
    UserData_t userData;
    ResponseMessage_t responseMessage;
    UserManagerError_t status;
    byte buffer[BUFFER_SIZE];
    size_t packSize, serverMessageSize;

    UnPackMessage(_message, &userData);

    status = UserLogin(_serverManager->m_userManager, userData.m_userName, userData.m_userPassword);

    switch (status)
    {
        case USER_MANAGER_USER_NOT_FOUND:
            responseMessage.m_responeMessage = LOGIN_USER_NOT_FOUND;
            break;

        case USER_MANAGER_INCORRECT_PASSWORD:
            responseMessage.m_responeMessage = LOGIN_USER_INCORRECT_PASSWORD;
            break;

        case USER_MANAGER_USER_IS_ALREADY_CONNECTED:
            responseMessage.m_responeMessage = LOGIN_USER_ALREADY_CONNECTED;
            break;

        case USER_MANAGER_SUCCESS:
            responseMessage.m_responeMessage = LOGIN_USER_SUCCESS;
            break;
    }

    packSize = PackMessage(TAG_RESPONSE_MESSAGE, &responseMessage, buffer);

    if (!packSize)
    {
        return FAILURE;
    }

    serverMessageSize = ServerSendMessage(_tcpServer, _clientID, buffer, packSize);

    if (!IsCompleteMassage((byte*)responseMessage, serverMessageSize))
    {
        return FAILURE;
    }

    return SUCCESS;
}

static Status_t ClientMessageCreateGroup(byte *_message, ServerManager_t *_serverManager, TCPServer_t *_tcpServer, int _clientID)
{
    CreateGroup_t createGroup;
    ResponseMessage_t responseMessage;
    byte buffer[BUFFER_SIZE];
    groupManagerError_t status;

    size_t packSize, serverMessageSize;

    UnPackMessage(_message, &createGroup);

    status = CreateNewGroup(_serverManager->m_groupManager, createGroup.m_groupIPAddress);

    switch (status)
    {
        case GROUP_MANAGER_GROUP_IS_ALREADY_EXIST:
            responseMessage.m_responeMessage = GROUP_CREATE_GROUP_ALREADY_EXIST;
            break;

        case GROUP_MANAGER_SUCCESS:
            responseMessage.m_responeMessage = GROUP_CREATE_SUCCESS;
            break;

        default:
            responseMessage.m_responeMessage = GROUP_CREATE_CREATE_ERROR;
    }

    packSize = PackMessage(TAG_RESPONSE_MESSAGE, &responseMessage, buffer);

    if (!packSize)
    {
        return FAILURE;
    }

    serverMessageSize = ServerSendMessage(_tcpServer, _clientID, buffer, packSize);

    if (!IsCompleteMassage((byte*)responseMessage, serverMessageSize))
    {
        return FAILURE;
    }

    return SUCCESS;
}

static Status_t ClientMessageJoinGroup(byte *_message, ServerManager_t *_serverManager, TCPServer_t *_tcpServer, int _clientID)
{
    GroupData_t groupData;
    JoinGroupResponse_t joinGroupResponse;
    byte buffer[BUFFER_SIZE];
    byte groupIpAddress[MAX_LENGTH];
    groupManagerError_t groupManagerStatus;
    UserManagerError_t userManagerStatus;
    size_t packSize, serverMessageSize;

    UnPackMessage(_message, &groupData);

    userManagerStatus = AddGroupToUser(_serverManager->m_userManager, groupData->m_userName, groupData->m_groupName);

    switch (userManagerStatus)
    {
        case USER_MANAGER_USER_NOT_FOUND:
        joinGroupResponse.m_responeMessage = JOIN_GROUP_USER_NOT_FOUND;
        break;

        case USER_MANAGER_USER_IS_ALREADY_JOIN_GROUP:
        joinGroupResponse.m_responeMessage = JOIN_GROUP_USER_IS_ALREADY_JOIN;
        break;

        case USER_MANAGER_SUCCESS:
        groupManagerStatus = JoinGroup(_serverManager->m_groupManager, groupData.m_groupName, groupData.groupIpAddress);

        switch (groupManagerStatus)
        {
            case GROUP_MANAGER_GROUP_NOT_FOUND:
            joinGroupResponse.m_responeMessage = JOIN_GROUP_GROUP_NOT_FOUND;
            break;

            case GROUP_MANAGER_IS_NOT_INITIALIZE:
            joinGroupResponse.m_responeMessage = JOIN_GROUP_JOIN_ERROR;
            break;

            case GROUP_MANAGER_SUCCESS:
            groupManagerStatus = IncreaseGroupCounter(_serverManager->m_groupManager, groupData.m_groupName);

            switch (groupManagerStatus)
            {
                case GROUP_MANAGER_GROUP_NOT_FOUND:
                joinGroupResponse.m_responeMessage = JOIN_GROUP_GROUP_NOT_FOUND;
                break;

                case GROUP_MANAGER_IS_NOT_INITIALIZE:
                joinGroupResponse.m_responeMessage = JOIN_GROUP_JOIN_ERROR;
                break;

                case GROUP_MANAGER_SUCCESS:
                strcpy((char*)joinGroupResponse.m_groupIPAddress, (char*)groupIpAddress);
                strcpy((char*)joinGroupResponse.m_groupPort, "9999");
                joinGroupResponse.m_responeMessage = JOIN_GROUP_SUCCESS;
                break;
            }

            default:
            joinGroupResponse.m_responeMessage = JOIN_GROUP_JOIN_ERROR;
        }
    }

    packSize = PackMessage(TAG_USER_JOIN_GROUP_RESPONSE, &joinGroupResponse, buffer);

    if (!packSize)
    {
        return FAILURE;
    }

    serverMessageSize = ServerSendMessage(_tcpServer, _clientID, buffer, packSize);

    if (!IsCompleteMassage((byte*)joinGroupResponse, serverMessageSize))
    {
        return FAILURE;
    }

    return SUCCESS;
}

static Status_t ClientMessageLeaveGroup(byte *_message, ServerManager_t *_serverManager, TCPServer_t *_tcpServer, int _clientID)
{
    GroupData_t groupData;
    ResponseMessage_t responseMessage;
    byte buffer[BUFFER_SIZE];
    groupManagerError_t groupManagerStatus;
    UserManagerError_t userManagerStatus;
    size_t packSize, serverMessageSize;

    UnPackMessage(_message, &groupData);

    userManagerStatus = RemoveGroupFromUser(_serverManager->m_userManager, groupData.m_userName, groupData.m_groupName);

    switch (userManagerStatus)
    {
        case USER_MANAGER_USER_NOT_FOUND:
            responseMessage.m_responeMessage = LEAVE_GROUP_NOT_FOUND;
            break;

        case USER_MANAGER_IS_NOT_INITIALIZE:
            responseMessage.m_responeMessage = LEAVE_GROUP_ERROR;
            break;

        case USER_MANAGER_SUCCESS:
            groupManagerStatus = DecreaseGroupCounter(_serverManager->m_groupManager, groupData.m_groupName);

            switch (groupManagerStatus)
            {
                case GROUP_MANAGER_GROUP_NOT_FOUND:
                    responseMessage.m_responeMessage = LEAVE_GROUP_NOT_FOUND;
                    break;

                case GROUP_MANAGER_IS_NOT_INITIALIZE:
                    responseMessage.m_responeMessage = LEAVE_GROUP_ERROR;
                    break;

                case GROUP_MANAGER_SUCCESS:
                    responseMessage.m_responeMessage = LEAVE_GROUP_SUCCESS;
                    break;
            }
    }

    packSize = PackMessage(TAG_RESPONSE_MESSAGE, &responseMessage, buffer);

    if (!packSize)
    {
        return FAILURE;
    }

    serverMessageSize = ServerSendMessage(_tcpServer, _clientID, buffer, packSize);

    if (!IsCompleteMassage((byte*)responseMessage, serverMessageSize))
    {
        return FAILURE;
    }

    return SUCCESS;
}

static Status_t ClientMessageLogout(byte *_message, ServerManager_t *_serverManager, TCPServer_t *_tcpServer, int _clientID)
{
    UserLogout_t *userLogout = NULL;
    ResponseMessage_t *responseMessage = NULL;
    byte buffer[BUFFER_SIZE];
    UserManagerError_t userManagerStatus;
    size_t packSize, serverMessageSize;

    userLogout = (UserLogout_t*)malloc(sizeof(UserLogout_t));
    if (!userLogout)
    {
        return FAILURE;
    }

    UnPackMessage(_message, userLogout);

    responseMessage = (ResponseMessage_t*)malloc(sizeof(ResponseMessage_t));
    if (!responseMessage)
    {
        free(userLogout);
        return FAILURE;
    }

    userManagerStatus = LogoutUser(_serverManager->m_userManager, userLogout->m_userName);

    switch (userManagerStatus)
    {
        case USER_MANAGER_SUCCESS:
            responseMessage->m_responeMessage = LOGOUT_SUCCESS;
            break;

        default:
            responseMessage->m_responeMessage = LOGOUT_FAILED;
            break;
    }

    packSize = PackMessage(TAG_RESPONSE_MESSAGE, responseMessage, buffer);

    if (!packSize)
    {
        free(userLogout);
        free(responseMessage);
        return FAILURE;
    }

    serverMessageSize = ServerSendMessage(_tcpServer, _clientID, buffer, packSize);

    if (!IsCompleteMassage((byte*)responseMessage, serverMessageSize))
    {
        free(userLogout);
        free(responseMessage);
        return FAILURE;
    }

    free(userLogout);
    free(responseMessage);

    return SUCCESS;
}