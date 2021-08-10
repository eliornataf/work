#include <stdlib.h> /* malloc, free, abs */
#include <string.h> /* strcpy, strlen, strcat */
#include "ipManager.h" /* IP Manager Header */
#include "genericQueue.h" /* Generic queue header */

#define IP_LENGTH (12)
#define NUM_OF_IPS (100)
#define BUFFER_SIZE (4)
#define BASE (10)

/*****************************************************/

struct IPManager
{
    Queue_t *m_queue;
    size_t m_numOfIPS;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void FreeIPAddress(void *ipadderss);
static size_t CountDigit(int num);
static char *Itoa(int value, char *str, int base);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

IPManager_t *CreateIPManager(void)
{
    IPManager_t *ipManager = NULL;
    byte strToBuildWith[IP_LENGTH] = "224.0.0.";
    byte buffer[BUFFER_SIZE];
    byte *strToQueue = NULL;
    size_t i;

    ipManager = (IPManager_t*)malloc(sizeof(IPManager_t));
    if (!ipManager)
    {
        return NULL;
    }

    ipManager->m_queue = QueueCreate(NUM_OF_IPS);
    if (!ipManager->m_queue)
    {
        free(ipManager);
        return NULL;
    }

    for (i = 1;i < NUM_OF_IPS + 1;++i)
    {
        Itoa(i, (char*)buffer, BASE);

        strcat((char*)strToBuildWith, (char*)buffer);

        strToQueue = (byte*)malloc((strlen((char*)strToBuildWith) + 1) * sizeof(byte));
        if (!strToQueue)
        {
            DestroyIpManager(&ipManager);
            return NULL;
        }

        strcpy((char*)strToQueue, (char*)strToBuildWith);

        if (QUEUE_SUCCESS != QueueInsert(ipManager->m_queue, strToQueue))
        {
            free(strToQueue);
            DestroyIpManager(&ipManager);
            return NULL;
        }

        strcpy((char*)strToBuildWith, "224.0.0.");
    } 

    ipManager->m_numOfIPS = NUM_OF_IPS;

    return ipManager;
}

void DestroyIpManager(IPManager_t **_ipManager)
{
    if (!_ipManager || !*_ipManager)
    {
        return;
    }

    QueueDestroy(&(*_ipManager)->m_queue, FreeIPAddress);  

    free(*_ipManager);

    *_ipManager = NULL;
}

IpManagerError_t GetIpAddress(IPManager_t *_ipManager, byte *_ipAddress)
{
    void *getIPAddress = NULL;

    if (!_ipManager || !_ipAddress)
    {
        return IP_MANAGER_IS_NOT_INITIALIZE;
    }

    if (!_ipManager->m_numOfIPS)
    {
        return IP_MANAGER_NOT_AVAILABLE_IP;
    }

    if (QUEUE_SUCCESS != QueueRemove(_ipManager->m_queue, &getIPAddress))
    {
        return IP_MANAGER_GET_IP_FAILED;
    }

    strcpy((char*)_ipAddress, (char*)((byte*)getIPAddress));

    free(getIPAddress);

    --_ipManager->m_numOfIPS;

    return IP_MANAGER_SUCCESS;
}

IpManagerError_t AddIpAddress(IPManager_t *_ipManager, byte *_ipAddress)
{
    byte *ipToAdd = NULL;

    if (!_ipManager || !_ipAddress)
    {
        return IP_MANAGER_IS_NOT_INITIALIZE;
    }

    if (NUM_OF_IPS == _ipManager->m_numOfIPS)
    {
        return IP_MANAGER_FULL_AVAILABLE_IP;
    }

    ipToAdd = (byte*)malloc((strlen((char*)_ipAddress) + 1) * sizeof(byte));
    if (!ipToAdd)
    {
        return IP_MANAGER_ALLOCATION_FAILED;
    }

    strcpy((char*)ipToAdd, (char*)_ipAddress);

    if (QUEUE_SUCCESS != QueueInsert(_ipManager->m_queue, ipToAdd))
    {
        return IP_MANAGER_ADD_IP_FAILED;
    }

    ++_ipManager->m_numOfIPS;

    return IP_MANAGER_SUCCESS;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void FreeIPAddress(void *_ipadderss)
{
	free(_ipadderss);
}

static size_t CountDigit(int _num)
{
	int count = 0;
	
	while (_num != 0)
	{
		++count;
		_num /= 10;
	}
	
	return count;
}

static char *Itoa(int value, char *str, int base)
{
	size_t numOfDigits = CountDigit(value);
	char *strFirstLocation = str;
	size_t strStrlen = 0;
	int lastDig, i;
	
	if (value < 0)
	{
		str[0] = '-';
		++strStrlen;
	}
	
	strStrlen += numOfDigits;
	
	for (i = strStrlen - 1;value != 0;--i)
	{
		lastDig = abs(value % 10);
		str[i] = lastDig + '0';
		value /= 10;
	}
	
	str[strStrlen] = '\0';
	
	return strFirstLocation;
}