#ifndef dynamicArray_H
#define dynamicArray_H

class dynamicArray {
private:
    int length;
    int capacity;
    int* arrayUnderHood;

    void resize();

public:
    dynamicArray();
    ~dynamicArray();

    void printList();

    bool pushElement(int value);
    int popElement();

    int atIndex(int index);

    int getSize();
    int getCapacity();

    bool insertAt(int index, int value);
    bool deleteAt(int index);
};

#endif