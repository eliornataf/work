#include <stdio.h> /* printf */
#include "singlyLinkedList.h" /* Singly Linked List Header */

Person_t *ListInsertHead(Person_t *_head, Person_t *_person)
{
	if (!_person)
	{
		return _head;
	}
	
	_person->m_next = _head;
	
	return _person;
}

Person_t *ListRemoveHead(Person_t *_head, Person_t **_outputData)
{
	if (!_head)
	{
		return _head;
	}
	
	*_outputData = _head;

	return _head->m_next;
}

Person_t *ListInsertByKey(Person_t *_head, size_t _key, Person_t *_person)
{
	Person_t *fastRunner = _head;
	Person_t *slowRunner = NULL;
	
	if (!_person)
	{
		return _head;
	}
	
	if (!_head || _key < _head->m_id)
	{
		return ListInsertHead(_head, _person);
	}
	
	while (fastRunner)
	{	
		if (_key == fastRunner->m_id)
		{
			break;
		}

		slowRunner = fastRunner;
		fastRunner = fastRunner->m_next;
		
		if (!fastRunner || _key < fastRunner->m_id)
		{
			slowRunner->m_next = _person;
			_person->m_next = fastRunner;
			break;
		}
	}
	
	return _head;
}

Person_t *ListInsertByKeyRecu(Person_t *_head, size_t _key, Person_t *_person)
{
	if (!_person)
	{
		return _head;
	}
	
	if (!_head || _key < _head->m_id)
	{
		return ListInsertHead(_head, _person);
	}
	
	if (_key == _head->m_id)
	{
		return _head;
	}
	
	_head->m_next = ListInsertByKeyRecu(_head->m_next, _key, _person);

	return _head;
}

Person_t *ListRemoveByKey(Person_t *_head, size_t _key, Person_t **_outputData)
{
	Person_t *fastRunner = _head;
	Person_t *slowRunner;

	if (!_head)
	{
		return _head;
	}
	
	if (_key == _head->m_id)
	{
		return ListRemoveHead(_head, _outputData);
	}
	
	while (fastRunner)
	{	
		slowRunner = fastRunner;
		fastRunner = fastRunner->m_next;
	
		if (fastRunner && _key == fastRunner->m_id)
		{
			*_outputData = fastRunner;
			slowRunner->m_next = fastRunner->m_next;
			fastRunner->m_next = NULL;
			break;
		}
	}
	
	return _head;
}

Person_t *ListRemoveByKeyRecu(Person_t *_head, size_t _key, Person_t **_outputData)
{
	if (!_head)
	{
		return _head;
	}
	
	if (_key == _head->m_id)
	{
		return ListRemoveHead(_head, _outputData);
	}
	
	_head->m_next = ListRemoveByKeyRecu(_head->m_next, _key, _outputData);
	
	return _head;
}

void PrintList(Person_t *_head)
{
	size_t i;

	if (!_head)
	{
		return;
	}

	for (i = 1;NULL != _head;_head = _head->m_next, ++i)
	{
		printf("\nNode number %ld:\n", i);
		printf("ID: %ld\n", _head->m_id);
		printf("Name: %s\n", _head->m_name);
		printf("Age: %ld\n", _head->m_age);	
	}
}
