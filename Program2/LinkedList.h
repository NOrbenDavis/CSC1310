/**********************************************************************
	Title:        LinkedList.h
	Author:       Nicholas Davis
	Date Created: 3/4/2021
	Purpose:      Singly linked list
***********************************************************************/

#ifndef LinkedList_H
#define LinkedList_H


template <typename T>
class LinkedList
{
private:
    struct ListNode
    {
        T value;
        struct ListNode *next;
    };
    ListNode *head;
    ListNode *tail;
    int numNodes;
public:
    LinkedList();
    ~LinkedList();
    int getLength();
    T getNodeValue(int);
    void insertNode(T );
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
    numNodes = 0;
}


template <typename T>
LinkedList<T>::~LinkedList()
{
    ListNode *nodePtr;
    ListNode *nextNode;
    nodePtr = head;
    while(nodePtr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

template <typename T>
int LinkedList<T>::getLength()
{
    return numNodes;
}

template <typename T>
T LinkedList<T>::getNodeValue(int position)
{
    ListNode *nodePtr;
    nodePtr = head;
    for (int i = 0; i < position; i++)
    {
        nodePtr = nodePtr->next;
    }
    return nodePtr->value; 
}

template <typename T>
void LinkedList<T>::insertNode(T givenDestination)
{
    int headVal = 0;
    int tailVal = 0;
    int newVal = 0;
    ListNode *nodePtr;
    ListNode *prevNode;
    ListNode *newNode;
    newNode = new ListNode;
    newNode->value = givenDestination;
    newNode->next = NULL;

    //If no nodes
    if(!head)
    {
        head = newNode;
        tail = newNode;
        ++numNodes;
    }
    //Head case
    else if (*(newNode->value) < *(head->value))
    {
        newNode->next = head;
        head = newNode;
        ++numNodes;
    }

    //Tail case
    else if (*(tail->value) < *(newNode->value))
    {
        tail->next = newNode;
        tail = newNode;
        ++numNodes;
    }
    //Traverse case
    else
    {
        nodePtr = head;
    
        while(*(nodePtr->value) < *(newNode->value))
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        newNode->next = nodePtr;
        prevNode->next = newNode;
        ++numNodes;
    }
}

#endif