#include <stdlib.h> /* malloc, free*/
#include <string.h> /* strlen, memcpy */
#include "protocol.h" /* Protocol Header */

/******************************************************/

#define NULL_CHAR_SIZE (1)
#define TOTAL_LENGTH_SIZE (1)
#define METADATA_SIZE (1)
#define TAG_SIZE (1)
#define ENUM_SIZE (1)

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void PackMessageUserData(UserData_t *message, byte *buffer);
static void PackResponseMessage(ResponseMessage_t *message, byte *buffer);
static void UnPackMessageUserData(UserData_t *userData, byte *message);
static void UnPackResponseMessage(ResponseMessage_t *responeMessage, byte *message);
static void PackCreateGroup(CreateGroup_t *message, byte *buffer);
static void UnPackCreateGroup(CreateGroup_t *createGroup, byte *message);
static void PackDataGroup(GroupData_t *message, byte *buffer);
static void UnPackDataGroup(GroupData_t *groupData, byte *message); 
static void PackJoinGroupResponse(JoinGroupResponse_t *message, byte *buffer);
static void UnPackJoinGroupResponse(JoinGroupResponse_t *joinGroupResponse, byte *message);
static void PackUserLogOut(UserLogout_t *message, byte *buffer);
static void UnPackUserLogOut(UserLogout_t *userLogout, byte *message);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

size_t PackMessage(TagMessage_t _messageTag, void *_objectToPackMessageFrom, byte *_buffer)
{
    if (_messageTag < 0 || !_objectToPackMessageFrom)
    {
        return FUNCTION_ERROR;
    }

    *_buffer = (byte)_messageTag;
    ++_buffer;

    switch(_messageTag)
    {
        case TAG_USER_REGISTER:
        case TAG_USER_LOGIN:
            PackMessageUserData((UserData_t*)_objectToPackMessageFrom, _buffer);
            break;

        case TAG_RESPONSE_MESSAGE:
            PackResponseMessage((ResponseMessage_t*)_objectToPackMessageFrom, _buffer);
            break;

        case TAG_CREATE_GROUP:
            PackCreateGroup((CreateGroup_t*)_objectToPackMessageFrom, _buffer);
            break;

        case TAG_USER_JOIN_GROUP:
        case TAG_USER_LEAVE_GROUP:
            PackDataGroup((GroupData_t*)_objectToPackMessageFrom, _buffer);
            break;

        case TAG_USER_JOIN_GROUP_RESPONSE:
            PackJoinGroupResponse((JoinGroupResponse_t*)_objectToPackMessageFrom, _buffer);
            break;
        
        case TAG_USER_LOGOUT:
            PackUserLogOut((UserLogout_t*)_objectToPackMessageFrom, _buffer);
            break; 
    }

    return _buffer[1];
}

size_t UnPackMessage(byte *_buffer, void *_objectToUnPackMessage)
{
    if (!_objectToUnPackMessage || !_buffer)
    {
        return FUNCTION_ERROR;
    }

    switch(*_buffer)
    {
        case TAG_USER_REGISTER:
        case TAG_USER_LOGIN:
            UnPackMessageUserData((UserData_t*)_objectToUnPackMessage, _buffer);
            break;

        case TAG_RESPONSE_MESSAGE:
            UnPackResponseMessage((ResponseMessage_t*)_objectToUnPackMessage, _buffer);
            break;

        case TAG_CREATE_GROUP:
            UnPackCreateGroup((CreateGroup_t*)_objectToUnPackMessage, _buffer);
            break;

        case TAG_USER_JOIN_GROUP:
        case TAG_USER_LEAVE_GROUP:
            UnPackDataGroup((GroupData_t*)_objectToUnPackMessage, _buffer);
            break;

        case TAG_USER_JOIN_GROUP_RESPONSE:
            UnPackJoinGroupResponse((JoinGroupResponse_t*)_objectToUnPackMessage, _buffer);
            break;

        case TAG_USER_LOGOUT:
            UnPackUserLogOut((UserLogout_t*)_objectToUnPackMessage, _buffer);
            break; 
    }

    return _buffer[1];
}

TagMessage_t GetMessageTag(byte *_message)
{
    if (!_message)
    {
        return FUNCTION_ERROR;
    }

    return (TagMessage_t)*_message;
}

int IsCompleteMassage(byte *_message, size_t _givenMessageLength)
{
    if (!_message || !_givenMessageLength)
    {
        return FUNCTION_ERROR;
    }

    return ((size_t)(*(++_message)) == _givenMessageLength);
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

/********************** UserData **********************/

static void PackMessageUserData(UserData_t *_message, byte *_buffer)
{
    size_t userNameLength = strlen((char*)_message->m_userName) + NULL_CHAR_SIZE;
    size_t userPasswordLength = strlen((char*)_message->m_userPassword) + NULL_CHAR_SIZE;

    *_buffer = (byte)(userNameLength + userPasswordLength + METADATA_SIZE * 2 + TAG_SIZE + TOTAL_LENGTH_SIZE);
    ++_buffer;

    *_buffer = (byte)(userNameLength);
    ++_buffer;

    memcpy(_buffer, _message->m_userName, userNameLength);
    _buffer += userNameLength;

    *_buffer = (byte)(userPasswordLength);
    ++_buffer;

    memcpy(_buffer, _message->m_userPassword, userPasswordLength);
    _buffer += userPasswordLength;
}

static void UnPackMessageUserData(UserData_t *_userData, byte *_message)
{
    size_t userNameLength, userPasswordLength;

    _message += TAG_SIZE + TOTAL_LENGTH_SIZE;

    userNameLength = (size_t)(*_message);
    ++_message;

    memcpy(_userData->m_userName, (byte*)_message, userNameLength);
    _message += userNameLength;

    userPasswordLength = (size_t)(*_message);
    ++_message;

    memcpy(_userData->m_userPassword, (byte*)_message, userPasswordLength);
    _message += userPasswordLength;
}

/********************** ResponseMessage **********************/

static void PackResponseMessage(ResponseMessage_t *_message, byte *_buffer)
{
    *_buffer = (byte)(ENUM_SIZE + METADATA_SIZE + TAG_SIZE + TOTAL_LENGTH_SIZE);
    ++_buffer;

    *_buffer = (byte)(ENUM_SIZE);
    ++_buffer;

    *_buffer = (byte)(_message->m_responeMessage);
}

static void UnPackResponseMessage(ResponseMessage_t *_responeMessage, byte *_message)
{
    _message += TAG_SIZE + TOTAL_LENGTH_SIZE + METADATA_SIZE;

    _responeMessage->m_responeMessage = (Reponse_t)*_message;
}

/********************** CreateGroup **********************/

static void PackCreateGroup(CreateGroup_t *_message, byte *_buffer)
{
    size_t groupIPAddressLength = strlen((char*)_message->m_groupIPAddress) + NULL_CHAR_SIZE;
    size_t groupPortLength = strlen((char*)_message->m_groupPort) + NULL_CHAR_SIZE;

    *_buffer = (byte)(groupIPAddressLength + groupPortLength + METADATA_SIZE * 2 + TAG_SIZE + TOTAL_LENGTH_SIZE);
    ++_buffer;

    *_buffer = (byte)(groupIPAddressLength);
    ++_buffer;

    memcpy(_buffer, _message->m_groupIPAddress, groupIPAddressLength);
    _buffer += groupIPAddressLength;

    *_buffer = (byte)(groupPortLength);
    ++_buffer;

    memcpy(_buffer, _message->m_groupPort, groupPortLength);
    _buffer += groupPortLength;
}

static void UnPackCreateGroup(CreateGroup_t *_createGroup, byte *_message)
{
    size_t groupIPAddressLength, groupPortLength;

    _message += TAG_SIZE + TOTAL_LENGTH_SIZE;

    groupIPAddressLength = (size_t)(*_message);
    ++_message;

    memcpy(_createGroup->m_groupIPAddress, (byte*)_message, groupIPAddressLength);
    _message += groupIPAddressLength;

    groupPortLength = (size_t)(*_message);
    ++_message;

    memcpy(_createGroup->m_groupPort, (byte*)_message, groupPortLength);
    _message += groupPortLength;
}

/********************** GroupData **********************/

static void PackDataGroup(GroupData_t *_message, byte *_buffer)
{
    size_t userNameLength = strlen((char*)_message->m_userName) + NULL_CHAR_SIZE;
    size_t groupNameLength = strlen((char*)_message->m_groupName) + NULL_CHAR_SIZE;

    *_buffer = (byte)(userNameLength + groupNameLength + METADATA_SIZE * 2 + TAG_SIZE + TOTAL_LENGTH_SIZE);
    ++_buffer;

    *_buffer = (byte)(userNameLength);
    ++_buffer;

    memcpy(_buffer, _message->m_userName, userNameLength);
    _buffer += userNameLength;

    *_buffer = (byte)(groupNameLength);
    ++_buffer;

    memcpy(_buffer, _message->m_groupName, groupNameLength);
    _buffer += groupNameLength;
}

static void UnPackDataGroup(GroupData_t *_groupData, byte *_message)
{
    size_t userNameLength, groupNameLength;

    _message += TAG_SIZE + TOTAL_LENGTH_SIZE;

    userNameLength = (size_t)(*_message);
    ++_message;

    memcpy(_groupData->m_userName, (byte*)_message, userNameLength);
    _message += userNameLength;

    groupNameLength = (size_t)(*_message);
    ++_message;

    memcpy(_groupData->m_groupName, (byte*)_message, groupNameLength);
    _message += groupNameLength;
}

/********************** JoinGroupResponse **********************/

static void PackJoinGroupResponse(JoinGroupResponse_t *_message, byte *_buffer)
{
    size_t groupIPAddressLength = strlen((char*)_message->m_groupIPAddress) + NULL_CHAR_SIZE;
    size_t groupPortLength = strlen((char*)_message->m_groupPort) + NULL_CHAR_SIZE;

    *_buffer = (byte)(groupIPAddressLength + groupPortLength + METADATA_SIZE * 3 + TAG_SIZE + TOTAL_LENGTH_SIZE + ENUM_SIZE);
    ++_buffer;

    *_buffer = (byte)(groupIPAddressLength);
    ++_buffer;

    memcpy(_buffer, _message->m_groupIPAddress, groupIPAddressLength);
    _buffer += groupIPAddressLength;

    *_buffer = (byte)(groupPortLength);
    ++_buffer;

    memcpy(_buffer, _message->m_groupPort, groupPortLength);
    _buffer += groupPortLength;

    *_buffer = (byte)(ENUM_SIZE);
    ++_buffer;

    *_buffer = (byte)(_message->m_responeMessage);
}

static void UnPackJoinGroupResponse(JoinGroupResponse_t *_joinGroupResponse, byte *_message)
{
    size_t groupIPAddressLength, groupPortLength;

    _message += TAG_SIZE + TOTAL_LENGTH_SIZE;

    groupIPAddressLength = (size_t)(*_message);
    ++_message;

    memcpy(_joinGroupResponse->m_groupIPAddress, (byte*)_message, groupIPAddressLength);
    _message += groupIPAddressLength;

    groupPortLength = (size_t)(*_message);
    ++_message;

    memcpy(_joinGroupResponse->m_groupPort, (byte*)_message, groupPortLength);
    _message += groupPortLength;

    ++_message;
     _responeMessage->m_responeMessage = (Reponse_t)*_message;
}

/********************** UserLogout **********************/

static void PackUserLogOut(UserLogout_t *_message, byte *_buffer)
{
    size_t userNameLength = strlen((char*)_message->m_userName) + NULL_CHAR_SIZE;

    *_buffer = (byte)(userNameLength + METADATA_SIZE + TAG_SIZE + TOTAL_LENGTH_SIZE);
    ++_buffer;

    *_buffer = (byte)(userNameLength);
    ++_buffer;

    memcpy(_buffer, _message->m_userName, userNameLength);
    _buffer += userNameLength;
}

static void UnPackUserLogOut(UserLogout_t *_userLogout, byte *_message)
{
    size_t userNameLength;

    _message += TAG_SIZE + TOTAL_LENGTH_SIZE;

    userNameLength = (size_t)(*_message);
    ++_message;

    memcpy(_userLogout->m_userName, (byte*)_message, userNameLength);
    _message += userNameLength;
}

/*****************************************************/