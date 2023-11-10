/*-- DoublyLinkedList.h ---------------------------------------------------

  This header file defines the template class DoublyLinkedList for managing
  a doubly linked list of elements.
  Basic operations include:
	 Constructor
	 insertAtPosition: Insert an element at a specific position
	 insertFront: Insert an element at the front of the list
	 insertEnd: Insert an element at the end of the list
	 remove: Remove a specified element from the list
	 isEmpty: Check if the list is empty
	 getSize: Get the number of elements in the list
	 search: Search for a specific element in the list
	 display: Output the list
	 <<: Overloaded output operator for displaying the list elements

-------------------------------------------------------------------------*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>

using namespace std;

template <typename ElementType>
class DoublyLinkedList
{

private:
	class DNode
	{

	public:
		ElementType elementData;
		DNode *next;
		DNode *prev;

		DNode(const ElementType &element);
	};
	typedef DNode *DNodePtr;

public:
	DoublyLinkedList();

	DoublyLinkedList(const DoublyLinkedList &original);

	~DoublyLinkedList();

	bool insertAtPosition(const ElementType &element, int pos);
	void insertAtFirst(const ElementType &element);
	void insertAtEnd(const ElementType &element);

	bool deleteElement(const ElementType &element);
	bool deleteAtPosition(int pos);
	bool deleteAtFirst();
	bool deleteAtEnd();

	/***************************************************
	 * @brief Check if the list is empty.
	 * @return A boolean according if the list is empty or not.
	 * @pre None.
	 * @post The state of the list remains unchanged.
	 */
	bool isEmpty() const;

	/***************************************************
	 * @brief Gets the size of the list.
	 * @return The number of elements in the list.
	 * @pre None.
	 * @post The state of the list remains unchanged.
	 */
	int getSize() const;

	int search(const ElementType &element);
	// ElementType &getDataAtPosition(int pos)const;

	ElementType* getDataAtPos(int pos);

	void display(ostream &os) const;

private:
	DNodePtr myFirst;
	int mySize;
};

// End of header file
/*-------------------------------------------------------------------------*/

template <typename ElementType>
DoublyLinkedList<ElementType>::DNode::DNode(const ElementType &element)
	: elementData(element), next(nullptr), prev(nullptr) {}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList()
	: myFirst(nullptr), mySize(0) {}

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(const DoublyLinkedList &original)
{
	myFirst = nullptr;

	if (!original.isEmpty())
	{
		myFirst = new DNode(original.myFirst->elementData);
		DNodePtr tempPtr = myFirst->next;
		DNodePtr ogPtr = original.myFirst->next;
		while (ogPtr != nullptr)
		{
			tempPtr = new DNode(ogPtr->elementData);
			tempPtr->prev = ogPtr->prev;
			tempPtr = tempPtr->next;
			ogPtr = ogPtr->next;
		}
	}
	mySize = original.mySize;
}

template <typename ElementType>
DoublyLinkedList<ElementType>::~DoublyLinkedList()
{
	DNodePtr tempPtr = myFirst;
	while (tempPtr != nullptr)
	{
		DNodePtr temp = tempPtr;
		tempPtr = tempPtr->next;
		delete temp;
	}

	mySize = 0;
}

template <typename ElementType>
inline int DoublyLinkedList<ElementType>::getSize() const
{
	return mySize;
}

template <typename ElementType>
inline bool DoublyLinkedList<ElementType>::isEmpty() const
{
	return myFirst == nullptr;
}

template <typename ElementType>
void DoublyLinkedList<ElementType>::insertAtFirst(const ElementType &element)
{
	DNodePtr newPtr = new DNode(element);
	if (isEmpty())
		myFirst = newPtr;
	else
	{
		newPtr->next = myFirst;
		myFirst->prev = newPtr;
		myFirst = newPtr;
	}
	mySize++;
}

template <typename ElementType>
void DoublyLinkedList<ElementType>::insertAtEnd(const ElementType &element)
{
	DNodePtr newPtr = new DNode(element);

	if (isEmpty())
		myFirst = newPtr;

	else
	{
		DNodePtr tempPtr = myFirst;
		while (tempPtr->next != nullptr)
		{
			tempPtr = tempPtr->next;
		}
		newPtr->prev = tempPtr;
		tempPtr->next = newPtr;
	}
	mySize++;
}

template <typename ElementType>
bool DoublyLinkedList<ElementType>::insertAtPosition(const ElementType &element,
													 int pos)
{
	if (pos < 0 || pos > mySize || pos > 0 && isEmpty())
		return false;

	DNodePtr newPtr = new DNode(element);

	// insertAtFirst
	if (isEmpty() && pos == 0)
		myFirst = newPtr;

	else if (pos == 0)
	{
		newPtr->next = myFirst;
		myFirst->prev = newPtr;
		myFirst = newPtr;
	}

	else
	{
		DNodePtr tempPtr = myFirst;
		for (int i = 0; i < pos - 1; i++)
		{
			tempPtr = tempPtr->next;
		}

		// insertAtEnd
		if (pos == mySize)
		{
			newPtr->prev = tempPtr;
			tempPtr->next = newPtr;
		}

		// insert not at first nor at the end
		else
		{
			newPtr->next = tempPtr->next;
			newPtr->prev = tempPtr;
			tempPtr->next->prev = newPtr;
			tempPtr->next = newPtr;
		}
	}
	mySize++;
	return true;
}

template <typename ElementType>
bool DoublyLinkedList<ElementType>::deleteAtFirst()
{
	if (isEmpty())
		return false;

	// else
	DNodePtr tempPtr = myFirst->next;
	delete myFirst;
	myFirst = tempPtr;
	mySize--;
	return true;
}

template <typename ElementType>
bool DoublyLinkedList<ElementType>::deleteAtEnd()
{
	if (isEmpty())
		return false;

	// else
	DNodePtr tempPtr = myFirst;
	while (tempPtr != nullptr)
	{
		tempPtr = tempPtr->next;
	}
	delete tempPtr;
	mySize--;
	return true;
}

template <typename ElementType>
bool DoublyLinkedList<ElementType>::deleteElement(const ElementType &element)
{
	int pos = search(element);
	return deleteAtPosition(pos);
}

template <typename ElementType>
bool DoublyLinkedList<ElementType>::deleteAtPosition(int pos)
{
	if (pos < 0 || pos >= mySize)
		return false;

	DNodePtr tempPtr = myFirst;
	for (int i = 0; i < pos; i++)
	{
		tempPtr = tempPtr->next;
	}

	if (tempPtr == nullptr)
		return false;

	if (tempPtr == myFirst)
	{
		deleteAtFirst();
	}
	else if (tempPtr->next == nullptr)
	{
		deleteAtEnd();
	}
	else
	{
		tempPtr->next->prev = tempPtr->prev;
		tempPtr->prev->next = tempPtr->next;
		delete tempPtr;
	}
	return true;
}

template <typename ElementType>
int DoublyLinkedList<ElementType>::search(const ElementType &element)
{
	DNodePtr tempPtr = myFirst;
	int count = 0;
	while (tempPtr != nullptr)
	{
		if (tempPtr->elementData == element)
			break;
		else
		{
			tempPtr = tempPtr->next;
			count++;
		}
	}

	if (count == mySize)
		return -1;
	// else
	return count;
}


template <typename ElementType>
ElementType* DoublyLinkedList<ElementType>::getDataAtPos(int pos)
{
	if (pos >= 0 && pos < mySize)
	{
		DNodePtr tempPtr = myFirst;
		for (int i = 0; i < pos; i++)
		{
			tempPtr = tempPtr->next;
		}
		return &(tempPtr->elementData);
	}

	return nullptr;
}

template <typename ElementType>
void DoublyLinkedList<ElementType>::display(ostream &os) const
{
	if (isEmpty())
		os << "List is empty.\n";
	else
	{
		DNodePtr tempPtr = myFirst;
		while (tempPtr != nullptr)
		{
			os << tempPtr->elementData << "\n";
			tempPtr = tempPtr->next;
		}
	}
}

template <typename ElementType>
ostream &operator<<(ostream &os, const DoublyLinkedList<ElementType> &list)
{
	list.display(os);
	return os;
}

template <typename ElementType>
istream &operator>>(istream &is, DoublyLinkedList<ElementType> &list)
{
	ElementType element;
	while (is >> element)
	{
		list.insertAtEnd(element);
	}
	return is;
}

#endif