
#ifndef LLISTWITHDUMMYNODE_H
#define LLISTWITHDUMMYNODE_H
#include <iostream>
using namespace std;

template <typename ElementType>
class LListWithDummyNode
{
private:
    class Node
    {
    public:
        ElementType data;
        Node *next;
        Node(const ElementType &newElement);
    };

    typedef Node *nodePtr;
    nodePtr myFirst;
    int mySize;

public:
    LListWithDummyNode();
    LListWithDummyNode(const LListWithDummyNode &original);
    ~LListWithDummyNode();

    inline bool isEmpty() const;
    int getSize() const;

    void addAtBeg(const ElementType &newElement);
    void addAtEnd(const ElementType &newElement);
    bool addAtPosition(const ElementType &newElement, unsigned position);

    bool deleteElementAtBeg();
    bool deleteElementAtEnd();
    bool deleteElementAtPos(unsigned position);
    bool deleteElement(const ElementType &element);

    // ElementType& getDataAtPosition(int pos);

    ElementType* getDataAtPos(int pos);

    int search(const ElementType &element);
    void displayList(ostream &os) const;
};

// END OF HEADER FILE

template <typename ElementType>
LListWithDummyNode<ElementType>::Node::Node(const ElementType &newElement)
    : data(newElement), next(nullptr)
{
}

template <typename ElementType>
LListWithDummyNode<ElementType>::LListWithDummyNode()
    : mySize(0)
{
    ElementType garbage;
    nodePtr dummy = new Node(garbage);
    myFirst = dummy;
}

template <typename ElementType>
LListWithDummyNode<ElementType>::
    LListWithDummyNode(const LListWithDummyNode &original)
{
    mySize = original.mySize;
    ElementType garbage;
    myFirst = new Node(garbage);

    nodePtr tempPtr = myFirst;
    nodePtr ogPtr = original.myFirst->next;

    while (ogPtr != nullptr)
    {
        tempPtr->next = new Node(ogPtr->data);
        tempPtr = tempPtr->next;
        ogPtr = ogPtr->next;
    }
}

template <typename ElementType>
LListWithDummyNode<ElementType>::~LListWithDummyNode()
{
    nodePtr tempPtr = myFirst->next;
    while (tempPtr != nullptr)
    {
        nodePtr nodeToDelete = tempPtr;
        tempPtr = tempPtr->next;
        delete nodeToDelete;
        mySize--;
    }
}

template <typename ElemntType>
bool LListWithDummyNode<ElemntType>::isEmpty() const
{
    return mySize == 0;
}

template <typename ElementType>
int LListWithDummyNode<ElementType>::getSize() const
{
    return mySize;
}
template <typename ElementType>
void LListWithDummyNode<ElementType>::addAtBeg(const ElementType &newElement)
{
    nodePtr newNode = new Node(newElement);
    if (isEmpty())
    {
        myFirst->next = newNode;
        mySize++;
    }
    else
    {
        newNode->next = myFirst->next;
        myFirst->next = newNode;
        mySize++;
    }
}

template <typename ElementType>
void LListWithDummyNode<ElementType>::addAtEnd(const ElementType &newElement)
{
    nodePtr newNode = new Node(newElement);
    if (isEmpty())
    {
        myFirst->next = newNode;
        mySize++;
    }
    else
    {
        nodePtr tempPtr = myFirst->next;
        while (tempPtr->next != nullptr)
        {
            tempPtr = tempPtr->next;
        }
        tempPtr->next = newNode;
        mySize++;
    }
}
template <typename ElementType>
bool LListWithDummyNode<ElementType>::
    addAtPosition(const ElementType &newElement, unsigned position)
{
    if (position < 0 || position < mySize)
    {
        return false;
    }
    nodePtr newNode = new Node(newElement);
    if (isEmpty() && position != 0)
    {
        return false;
    }
    else if (isEmpty() && position == 0)
    {
        myFirst->next = newNode;
        mySize++;
        return true;
    }
    else if (!isEmpty() && position == 0)
    {
        newNode->next = myFirst->next;
        myFirst->next = newNode;
        mySize++;
        return true;
    }
    else
    {
        nodePtr tempPtr = myFirst;
        for (int i = 0; i < position - 1; i++)
        {
            tempPtr = tempPtr->next;
        }
        newNode->next = tempPtr->next;
        tempPtr->next = newNode;
        mySize++;
        return true;
    }
}

template <typename ElementType>
bool LListWithDummyNode<ElementType>::deleteElementAtBeg()
{
    if (isEmpty())
    {
        return false;
    }
    nodePtr nodeTodelete = myFirst->next;
    myFirst->next = nodeTodelete->next;
    delete nodeTodelete;
    mySize--;

    return true;
}
template <typename ElementType>
bool LListWithDummyNode<ElementType>::deleteElementAtEnd()
{
    if (isEmpty())
    {
        return false;
    }

    nodePtr tempPtr = myFirst->next;
    while (tempPtr->next != nullptr && tempPtr->next->next != nullptr)
    {
        tempPtr = tempPtr->next;
    }

    delete tempPtr->next;
    tempPtr->next = nullptr;
    mySize--;

    return true;
}

template <typename ElementType>
bool LListWithDummyNode<ElementType>::deleteElementAtPos(unsigned int position)
{
    if (position < 0 || position >= mySize)
    {
        return false;
    }
    if (isEmpty())
    {
        return false;
    }
    if (position == 0)
    {
        nodePtr nodeTodelete = myFirst->next;
        myFirst->next = nodeTodelete->next;
        delete nodeTodelete;
        mySize--;

        return true;
    }
    nodePtr tempPtr = myFirst->next;

    for (int i = 1; i < position - 1; i++)
    {
        tempPtr = tempPtr->next;
    }
    nodePtr nodeTodelete = tempPtr->next;

    tempPtr->next = nodeTodelete->next;
    delete nodeTodelete;
    mySize--;
    return true;
}

template <typename ElementType>
int LListWithDummyNode<ElementType>::search(const ElementType &element)
{
    int index = 0;
    nodePtr tempPtr = myFirst->next;
    while (tempPtr != nullptr)
    {

        if (tempPtr->data == element)
        {
            return index;
        }
        else
        {
            tempPtr = tempPtr->next;
            index++;
        }
    }
    return -1;
}

template <typename ElementType>
bool LListWithDummyNode<ElementType>::deleteElement(const ElementType &element)
{
    int indexOfTheElement = search(element);
    if (indexOfTheElement == -1)
    {
        return false;
    }
    else if (indexOfTheElement == 0)
    {
        nodePtr nodeTodelete = myFirst->next;
        myFirst->next = nodeTodelete->next;
        delete nodeTodelete;
        mySize--;
        return true;
    }
    else if (indexOfTheElement == mySize - 1)
    {
        nodePtr tempPtr = myFirst;
        while (tempPtr->next->next != nullptr)
        {
            tempPtr = tempPtr->next;
        }
        nodePtr nodeToDelete = tempPtr->next;
        tempPtr->next = nullptr;
        delete nodeToDelete;
        mySize--;

        return true;
    }
    else
    {
        nodePtr tempPtr = myFirst;

        for (int i = 0; i < indexOfTheElement; i++)
        {
            tempPtr = tempPtr->next;
        }
        nodePtr nodeToDelete = tempPtr->next;
        tempPtr->next = nodeToDelete->next;
        delete nodeToDelete;

        mySize--;
        return true;
    }
}

//template <typename ElementType>
//ElementType& LListWithDummyNode<ElementType>::getDataAtPosition(int pos) {
//    try {
//        if (pos >= 0 && pos < mySize)
//        {
//            nodePtr tempPtr = myFirst->next;
//            for (int i = 0; i < pos; i++)
//            {
//                tempPtr = tempPtr->next;
//            }
//            return tempPtr->data;
//        }
//        else
//        {
//            throw out_of_range("Error:");
//        }
//    }
//    catch (const out_of_range& e) {
//        std::cerr << " Position is invalid" << std::endl;
//    }
//}

// testing 
template <typename ElementType>
ElementType* LListWithDummyNode<ElementType>::getDataAtPos(int pos) {
    
        if (pos >= 0 && pos < mySize)
        {
            nodePtr tempPtr = myFirst->next;
            for (int i = 0; i < pos; i++)
            {
                tempPtr = tempPtr->next;
            }
            return &(tempPtr->data);
        }

        return nullptr;
}

template <typename ElementType>
void LListWithDummyNode<ElementType>::displayList(ostream &os) const
{
    if (isEmpty())
    {
        cout << "The list is empty";
    }
    else
    {
        nodePtr tempPtr = myFirst->next;
        while (tempPtr != nullptr)
        {
            os << tempPtr->data << " ";
            tempPtr = tempPtr->next;
        }
    }
}
template <typename ElementType>
ostream &operator<<(ostream &os, LListWithDummyNode<ElementType> &list)
{
    list.displayList(os);
    return os;
}
template <typename ElementType>
istream &operator>>(istream &is, LListWithDummyNode<ElementType> &list)
{
    ElementType element;
    while (is >> element)
    {
        list.addAtEnd(element);
    }
    return is;
}

#endif