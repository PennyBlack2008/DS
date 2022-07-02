#pragma once
#include "KeyLinkedList.h"
#include <string>
#include <stdexcept>

using namespace std;

template <typename T, typename V>
class HashMap
{
private:
	KeyLinkedList<T, V>* container[30];
	int hash(T key)
	{
		int hashValue = -1;
		int temp = 0;
		for (int i = 0; i < key; i++)
		{
			temp += i;
		}
		hashValue = temp % 30;
	}
	Node<T, V>* _findNodeByKey(T key, Node<T, V>* nowCursor)
	{
		Node<T, V>* cursor = nowCursor;
		while (cursor != nullptr)
		{
			if (cursor->key == key)
			{
				break;
			}
			cursor = cursor->next;
		}
		return cursor;
	}
public:
	HashMap()
	{
		for (int i = 0; i < 30; i++)
		{
			container[i] = new KeyLinkedList<T, V>();
		}
	}
	void put(T key, V value)
	{
		int hashcode = this->hash(key);

		Node<T, V>* cursor = this->container[hashcode]->head;
		cursor = _findNodeByKey(key, cursor);
		
		if (cursor != nullptr)
		{
			cursor->value = value;
		} else {
			this->container[hashcode]->add(key, value);
		}
	}
	V get(T key)
	{
		V value;
		int hashcode = this->hash(key);
	}
