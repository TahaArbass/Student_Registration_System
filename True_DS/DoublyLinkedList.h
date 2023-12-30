/******************************************************************************
 * Implementation of doubly linked list
 *
 * DoublyLinkedList: defualt constructor.
 * DoublyLinkedList: copy constructor.
 * ~DoublyLinkedList: distructor.
 * insertAtPosition: inserts a new element at a given position.
 * insertAtFirst: inserts a new element at the first of
 * the doubly linked list.
 * insertAtEnd: inserts a new element at the end of the doubly  linked list.
 * deleteElement: deletes a given element from the doubly linked list.
 * deleteAtPosition: deletes the element at a given position.
 * deleteAtFirst: deletes the element at the first of the doubly linked list.
 * deleteAtEnd: deleted the element at the end of the doubly linked list.
 * isEmpty: checks if the doubly linked list is empty.
 * getSize: getter for the size of the doubly linked list.
 * search: search for the element in the doubly linked list.
 * getDataAtPosition: getter for the data at a given position.
 * display: display the doubly linked list.
 * operator<<: display the doubly linked list object.
 * operator>>: uses cin to get input related to the doubly linked list.
 *
 * ****************************************************************************
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>

using namespace std;

/***** DNode Class Template *****/
template <typename ElementType>
class DoublyLinkedList
{

private:
	class DNode
	{

	public:
		ElementType elementData; // elementdata stored in the node.
		DNode* next;			 // Pointer to the next node of the list.
		DNode* prev;			 // Pointer to the previous node of the list.

		DNode(const ElementType& element);
		/*----------------------------------------------------------------
   DNode Constructor

   Precondition:  The 'element' is a valid element.
   Postcondition: A new DNode object is created with the specified data,
		  and pointers to the previous and next nodes are set to nullptr.
 ------------------------------------------------------------------------*/
	};
	typedef DNode* DNodePtr;

public:
	/***** Default Constructor *****/
	DoublyLinkedList();
	/*-------------------------------------------------------------------------
  Construct an empty Doubly Linked List.

  Precondition:  None.
  Postcondition: An empty Doubly Linked List is created.
----------------------------------------------------------------------------*/

/***** Copy Constructor *****/
	DoublyLinkedList(const DoublyLinkedList& original);
	/*-------------------------------------------------------------------------
  Construct a new Doubly Linked List by copying an existing one.

  Precondition:  The 'original' parameter is a valid Doubly Linked List.
  Postcondition: A new Doubly Linked List is created as a copy of the
  'original'list, preserving the order of elements.
----------------------------------------------------------------------------*/

/***** Destructor *****/
	~DoublyLinkedList();
	/*-------------------------------------------------------------------------
  Destroy the Doubly Linked List and deallocate its memory.

  Precondition:  None.
  Postcondition: The Doubly Linked List is destroyed, and its memory is
																deallocated.
----------------------------------------------------------------------------*/

/***** Insert Element at Given Position *****/
	bool insertAtPosition(const ElementType& element, int pos);
	/*-------------------------------------------------------------------------
	Insert an element at the specified position within the Doubly Linked List.



	  Precondition:  The 'element' is a valid element. The 'pos' is a
	  non-negative integer that represents a valid position within the list.
	  Postcondition: If successful, the 'element' is inserted at the specified
	   'pos'in the list. Returns true if the insertion is successful,
					 false otherwise.
	-------------------------------------------------------------------------*/

	/***** Insert Element at the Beginning *****/
	void insertAtFirst(const ElementType& element);
	/*-------------------------------------------------------------------------
	  Insert an element at the beginning of the Doubly Linked List.

	 Precondition:  The 'element' is a valid element.
	 Postcondition: The 'element' is inserted at the beginning of the list.
	-------------------------------------------------------------------------*/

	/***** Insert Element at the End *****/
	void insertAtEnd(const ElementType& element);
	/*-------------------------------------------------------------------------
  Insert an element at the end of the Doubly Linked List.

  Precondition:  The 'element' is a valid element.
  Postcondition: The 'element' is inserted at the end of the list.
----------------------------------------------------------------------------*/

/***** Delete Element *****/
	bool deleteElement(const ElementType& element);
	/*-------------------------------------------------------------------------
  Delete the first occurrence of a specific element from
													the Doubly Linked List.

  Precondition:  The 'element' is a valid element.
  Postcondition: If the 'element' is found in the list,
				 the first occurrence of it is removed,
				  and the list is modified. Returns true if the element
				 was found and deleted, false otherwise.
----------------------------------------------------------------------------*/

/***** Delete Element at Given Position *****/
	bool deleteAtPosition(int pos);
	/*-------------------------------------------------------------------------
  Delete an element at the specified position within the Doubly Linked List.


  Precondition:  The 'pos' is a non-negative integer representing a
   valid position within the list.
  Postcondition: If the 'pos' is valid and within the list's bounds,
   the element at that position is deleted, and the list is modified.
	Returns true if the deletion is successful, false otherwise.
----------------------------------------------------------------------------*/

/***** Delete Element at the Beginning *****/
	bool deleteAtFirst();
	/*-------------------------------------------------------------------------
  Delete the element at the beginning of the Doubly Linked List.

  Precondition:  None.
  Postcondition: If the list is not empty,
  the element at the beginning is deleted,
  and the list is modified. Returns true if the deletion is successful,
				 false otherwise.
----------------------------------------------------------------------------*/

/***** Delete Element at the End *****/
	bool deleteAtEnd();
	/*-------------------------------------------------------------------------
  Delete the element at the end of the Doubly Linked List.

  Precondition:  None.
  Postcondition: If the list is not empty, the element at the end is deleted,
				 and the list is modified.
				  Returns true if the deletion is successful,false otherwise.
----------------------------------------------------------------------------*/

/***** Check if the List is Empty *****/
	bool isEmpty() const;
	/*-------------------------------------------------------------------------
	  Check if the Doubly Linked List is empty.

	  Precondition:  None.
	  Postcondition: Returns true if the list is empty, false otherwise.
	-------------------------------------------------------------------------*/

	/***** Get the Size of the List *****/
	int getSize() const;
	/*-------------------------------------------------------------------------
  Get the size (number of elements) in the Doubly Linked List.

  Precondition:  None.
  Postcondition: Returns the number of elements in the list as an integer.
----------------------------------------------------------------------------*/

/***** Search for an Element *****/
	int search(const ElementType& element);
	/*-------------------------------------------------------------------------
  Search for a specific element in the Doubly Linked List and return
														its position.

  Precondition:  The 'element' is a valid element.
  Postcondition: If the 'element' is found in the list,
   its position is returned as an integer. If the element is not found,
															 -1 is returned.
----------------------------------------------------------------------------*/

/***** Get Data at a Specific Position *****/
	ElementType* getDataAtPos(int pos);
	/*-------------------------------------------------------------------------
	  Retrieve the data at a specified position in the Doubly Linked List.

	  Precondition:  The 'pos' is a non-negative integer representing
	  a valid position within the list.
	  Postcondition: If the 'pos' is valid and within the list's bounds,
	   a pointer to the data at that position is returned.
	   If 'pos' is invalid, nullptr is returned.
	-------------------------------------------------------------------------*/
	/***** Display the List *****/
	void display(ostream& os) const;
	/*-------------------------------------------------------------------------
  Display the elements of the Doubly Linked List.

  Precondition:  The 'os' parameter is a valid output stream.
  Postcondition: The elements of the list are displayed on the output stream.
----------------------------------------------------------------------------*/

private:
	DNodePtr myFirst; // pointer to the first node
	int mySize;		  // size of the element in the doubly linked list
};

// End of header file
/*-------------------------------------------------------------------------*/

// DNode constructor implmentation
template <typename ElementType>
DoublyLinkedList<ElementType>::DNode::DNode(const ElementType& element)
	: elementData(element), next(nullptr), prev(nullptr) {}

// Doubly linked list constructor implementation
template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList()
	: myFirst(nullptr), mySize(0) {}

// Doubly linked list Copy Constructor

template <typename ElementType>
DoublyLinkedList<ElementType>::
DoublyLinkedList(const DoublyLinkedList& original)
{
	myFirst = nullptr; // myFirst points to null.

	// Checking if orginal list is not Empty to proceed.

	if (!original.isEmpty())
	{
		// Create the first node in the new list.
		myFirst = new DNode(original.myFirst->elementData);

		// Pointers to traverse the new list and the original list.
		DNodePtr tempPtr = myFirst->next;
		DNodePtr ogPtr = original.myFirst->next;

		// Loop through the original list .
		while (ogPtr != nullptr)
		{
			// duplicating the elements.
			tempPtr = new DNode(ogPtr->elementData);

			// Set the previous pointer of the new node.
			tempPtr->prev = ogPtr->prev;

			// Move to the next node in both the new and original lists.
			tempPtr = tempPtr->next;
			ogPtr = ogPtr->next;
		}
	}

	// Set the size of the new list to be the same as the original list.
	mySize = original.mySize;
}

// destructor of the doubly linked list
template <typename ElementType>
DoublyLinkedList<ElementType>::~DoublyLinkedList()
{
	// tempPtr points to what myFirst is pointing to.
	DNodePtr tempPtr = myFirst;

	// traversing tempPtr.
	while (tempPtr != nullptr)
	{
		// temp points to tempPtr.
		DNodePtr temp = tempPtr;
		tempPtr = tempPtr->next;
		delete temp; // deleting temp.
	}

	mySize = 0; // size set to 0 after destruction.
}

// returns the size of the list.
template <typename ElementType>
inline int DoublyLinkedList<ElementType>::getSize() const
{
	return mySize;
}

// checks if the list is empty.
template <typename ElementType>
inline bool DoublyLinkedList<ElementType>::isEmpty() const
{
	return myFirst == nullptr;
}

// inserts a new element at the begining of the list.
template <typename ElementType>
void DoublyLinkedList<ElementType>::insertAtFirst(const ElementType& element)
{
	// Creating new Node.
	DNodePtr newPtr = new DNode(element);

	// checking if the list is empty.
	if (isEmpty())
		myFirst = newPtr;
	else
	{
		// Otherwise update the pointers to fit the opeation.
		newPtr->next = myFirst;
		myFirst->prev = newPtr;
		myFirst = newPtr;
	}
	mySize++; // incrementing the size of the list.
}

// inserts a new element at the end of the list.
template <typename ElementType>
void DoublyLinkedList<ElementType>::insertAtEnd(const ElementType& element)
{
	// Creating new Node.
	DNodePtr newPtr = new DNode(element);

	// Checking if the list is empty.
	if (isEmpty())
		myFirst = newPtr;

	else
	{
		// Otherwise update the pointers to fit the operation.

		DNodePtr tempPtr = myFirst;

		// traversing
		while (tempPtr->next != nullptr)
		{
			tempPtr = tempPtr->next;
		}
		newPtr->prev = tempPtr;
		tempPtr->next = newPtr;
	}
	mySize++; // incrementing the size of the list.
}

// inserts a new element at a given position.
template <typename ElementType>
bool DoublyLinkedList<ElementType>::insertAtPosition(const ElementType
	& element,
	int pos)
{

	// Checking if the position is valid.
	if (pos < 0 || pos > mySize || pos > 0 && isEmpty())
		return false;

	// creating a new Node.
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
	// The list is not empty and the position is not 0
	else
	{
		DNodePtr tempPtr = myFirst;

		// traversing
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
			// updating pointer to fit the operation.
			newPtr->next = tempPtr->next;
			newPtr->prev = tempPtr;
			tempPtr->next->prev = newPtr;
			tempPtr->next = newPtr;
		}
	}
	mySize++;	 // incrementing the size of the list.
	return true; // true is returned after the insertion.
}

// deletes an element at the begining of the list.
template <typename ElementType>
bool DoublyLinkedList<ElementType>::deleteAtFirst()
{
	// checking if the list is empty.
	if (isEmpty())
		return false;

	// else updating the pointers to fit the operation.
	DNodePtr tempPtr = myFirst->next;
	delete myFirst;
	myFirst = tempPtr;
	mySize--;	 // decrementing the size of the list.
	return true; // true is returned after the deletion.
}

// deletes an element at the end of the list.
template <typename ElementType>
bool DoublyLinkedList<ElementType>::deleteAtEnd()
{
	// checking if the list is empty.
	if (isEmpty())
		return false;

	// else
	DNodePtr tempPtr = myFirst;

	// traversing.
	while (tempPtr != nullptr)
	{
		tempPtr = tempPtr->next;
	}
	delete tempPtr; // deletes tempPtr which points to the last node.
	mySize--;		// decrementing the size of the list.
	return true;	// true returned after the deletion.
}

// deletes an element from the list.
template <typename ElementType>
bool DoublyLinkedList<ElementType>::deleteElement(const ElementType& element)
{

	// Calling the method search to get the index of the element.
	int pos = search(element);

	// Calling the method deleteAtPosition to delete the element at its index.
	return deleteAtPosition(pos);
}

// deltes an element from a given position.
template <typename ElementType>
bool DoublyLinkedList<ElementType>::deleteAtPosition(int pos)
{
	// Checking if the position is valid.
	if (pos < 0 || pos >= mySize)
		return false;

	// Creating temp pointer
	DNodePtr tempPtr = myFirst;

	// traversing
	for (int i = 0; i < pos; i++)
	{
		tempPtr = tempPtr->next;
	}
	// if the list is empty.
	if (tempPtr == nullptr)
		return false;
	// if the list is not empty and the position is at first.
	if (tempPtr == myFirst)
	{
		deleteAtFirst();
	}
	// the position is at end.
	else if (tempPtr->next == nullptr)
	{
		deleteAtEnd();
	}
	// the position neither at first nor at end.
	else
	{
		tempPtr->next->prev = tempPtr->prev;
		tempPtr->prev->next = tempPtr->next;
		delete tempPtr;
	}
	return true; // true is returned after the deletion.
}

// searches for the element in the list.
template <typename ElementType>
int DoublyLinkedList<ElementType>::search(const ElementType& element)
{
	// Creating a temp pointer
	DNodePtr tempPtr = myFirst;
	int count = 0; // initializing  counter to get the index.

	// traversing.
	while (tempPtr != nullptr)
	{
		// breaking the loop after finding the element
		if (tempPtr->elementData == element)
			break;
		else
		{
			// updating the position of the temp pointer.
			tempPtr = tempPtr->next;
			count++; // incrementing the counter.
		}
	}

	if (count == mySize)
		return -1;
	// else
	return count;
}

// returns a pointer of the data at a specific position.
template <typename ElementType>
ElementType* DoublyLinkedList<ElementType>::getDataAtPos(int pos)
{
	// Checking if the position is valid.
	if (pos >= 0 && pos < mySize)
	{

		// Creating temp pointer.
		DNodePtr tempPtr = myFirst;

		// traversing
		for (int i = 0; i < pos; i++)
		{
			tempPtr = tempPtr->next;
		}
		// returning an adress to the data at the giving position.
		return &(tempPtr->elementData);
	}

	return nullptr; // Other wise a null pointer is returned.
}

// displays the content of the list.
template <typename ElementType>
void DoublyLinkedList<ElementType>::display(ostream& os) const
{
	// checking if the list is empty.
	if (isEmpty())
		os << "List is empty.\n";
	else
	{
		// traversing using a temp pointer to display each data.
		DNodePtr tempPtr = myFirst;
		while (tempPtr != nullptr)
		{
			os << tempPtr->elementData << "\n";
			tempPtr = tempPtr->next;
		}
	}
}

// overloaded display operator.
template <typename ElementType>
ostream& operator<<(ostream& os, const DoublyLinkedList<ElementType>& list)
{
	list.display(os);
	return os;
}

// overloaded insertion operator.
template <typename ElementType>
istream& operator>>(istream& is, DoublyLinkedList<ElementType>& list)
{

	ElementType element;
	while (is >> element)
	{
		list.insertAtEnd(element);
	}
	return is;
}

template <typename ElementType>
bool operator==(const DoublyLinkedList<ElementType>& l1, const DoublyLinkedList<ElementType>& l2)
{
	if (l1.getSize != l2.getSize())
	{
		return false;
	}

	typename DoublyLinkedList<ElementType>::DNodePtr pointer1 = l1.myFirst;
	typename DoublyLinkedList<ElementType>::DNodePtr pointer2 = l2.myFirst;

	while (pointer1 != nullptr)
	{
		if (pointer1->elementData != pointer2->elementData)
		{
			return false;
		}
		pointer1 = pointer1->next;
		pointer2 = pointer2->next;
	}
	return true;
}

#endif