#ifndef singlyLinkedList_H
#define singlyLinkedList_H

class Node {
public:
    int value;
    Node* next;

    Node(int value);
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    int getLength();
    void printList();

    Node* getNodeByIndex(int index);
    bool setNodeValue(int index, int value);

    bool appendNode(int value);
    bool deleteLastNode();

    bool prependNode(int value);
    bool deleteFirstNode();

    bool insertNodeAt(int index, int value);
    bool deleteNodeAt(int index);

    bool reverseList();
};

#endif