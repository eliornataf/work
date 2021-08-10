/*****************************************************************************
* File Name: Singly Linked List
* Written by: Elior Nataf
* Date: 22/2/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__

/*------------------------------- Header Files ------------------------------*/

/*------------------------------- Enum & Define -----------------------------*/

#define STR_LENGTH 128

/*----------------------------- Struct & Typedef ----------------------------*/

typedef struct Person Person_t;

struct Person
{
	size_t m_id;
	char m_name[STR_LENGTH];
	size_t m_age;
	Person_t *m_next;
};

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that adds an element at the head of the singly linked list.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * head - pointer to head of the singly linked list.
 * person - pointer to node to be added.
 *
 * Output:
 * head - the pointer to person is not initialized, return pointer to the head node.
 * head - pointer to the new head node.
 *
 * Error: 
 * head - the pointer to person is not initialized, return pointer to the head node.
 */
Person_t *ListInsertHead(Person_t *head, Person_t *person);

/* Description:
 * A function that removes an element at the head of a singly linked list.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * head - pointer to head of the singly linked list.
 * outputData - pointer to node to be removed.
 *
 * Output:
 * head - the head is NULL - list is empty, return pointer to the head node.
 * head - the pointer to outputData is not initialized, return pointer to the head node.
 * head - pointer to the new head node.
 *
 * Error: 
 * head - the head is NULL - list is empty, return pointer to the head node.
 * head - the pointer to outputData is not initialized, return pointer to the head node.
 */
Person_t *ListRemoveHead(Person_t *head, Person_t **outputData);

/* Description:
 * A function that adds an element from a singly linked list by key (id number).
 * the singly linked list is ascending order (smallest id [key] to largest id [key]);
 *
 * Time Complexity: O(n).
 *
 * Input:
 * head - pointer to head of the singly linked list.
 * key - id number to sorted the singly linked list by.
 * person - pointer to node to be added.
 *
 * Output:
 * head - the pointer to person is not initialized, return pointer to the head node.
 * head - the pointer to person has the same key [id] to node of the singly 
 * linked list, return pointer to the head node.
 * head - pointer to the new head node.
 *
 * Error: 
 * head - the pointer to person is not initialized, return pointer to the head node.
 * head - the pointer to person has the same key [id] to node of the singly 
 * linked list, return pointer to the head node.
 */
Person_t *ListInsertByKey(Person_t *head, size_t key, Person_t *person);

/* Description:
 * A function that adds an element from a singly linked list by key (id number).
 * the singly linked list is ascending order (smallest id [key] to largest id [key]);
 *
 * Time Complexity: O(n). 
 *
 * Input:
 * head - pointer to head of the singly linked list.
 * key - id number to sorted the singly linked list by.
 * person - pointer to node to be added.
 *
 * Output:
 * head - the pointer to person is not initialized, return pointer to the head node.
 * head - the pointer to person has the same key [id] to node of the singly 
 * linked list, return pointer to the head node.
 * head - pointer to the new head node.
 *
 * Error: 
 * head - the pointer to person is not initialized, pointer to the head node.
 * head - the pointer to person has the same key [id] to node of the singly 
 * linked list, return pointer to the head node.
 */
Person_t *ListInsertByKeyRecu(Person_t *head, size_t key, Person_t *person);

/* Description:
 * A function that removes an element from a singly linked list by key (id number).
 *
 * Time Complexity: O(n).
 *
 * Input:
 * head - pointer to head of the singly linked list.
 * key - the id number to the node to remove from the singly linked list.
 * outputData - pointer to node to be removed.
 *
 * Output:
 * head - the head is NULL - list is empty, return pointer to the head node.
 * head - the pointer to outputData is not initialized, return pointer to the head node.
 * head - the pointer to person has the same key [id] to node of the singly 
 * linked list, return pointer to the head node.
 * head - pointer to the new head node.
 *
 * Error: 
 * head - the head is NULL - list is empty, return pointer to the head node.
 * head - the pointer to outputData is not initialized, return pointer to the head node.
 * head - the pointer to person has the same key [id] to node of the singly 
 * linked list, return pointer to the head node.
 */
Person_t *ListRemoveByKey(Person_t *head, size_t key, Person_t **outputData);

/* Description:
 * A function that removes an element from a singly linked list by key (id number).
 *
 * Time Complexity: O(n). 
 *
 * Input:
 * head - pointer to head of the singly linked list.
 * key - the id number to the node to remove from the singly linked list.
 * outputData - pointer to node to be removed.
 *
 * Output:
 * head - the head is NULL - list is empty, return pointer to the head node.
 * head - the pointer to outputData is not initialized, return pointer to the head node.
 * head - the pointer to person has the same key [id] to node of the singly 
 * linked list, return pointer to the head node.
 * head - pointer to the new head node.
 *
 * Error: 
 * head - the head is NULL - list is empty, return pointer to the head node.
 * head - the pointer to outputData is not initialized, return pointer to the head node.
 * head - the pointer to person has the same key [id] to node of the singly 
 * linked list, return pointer to the head node.
 */
Person_t *ListRemoveByKeyRecu(Person_t *head, size_t key, Person_t **outputData);

/* Description:
 * A function that prints a specified singly linked list. 
 *
 * Time Complexity: O(n).
 *
 * Input:
 * head - pointer to head of the singly linked list.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - print failed.
 */
void PrintList(Person_t *head);

#endif /* __QUEUE_H__ */
