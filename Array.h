#ifndef ARRAY_H
#define ARRAY_H

#include <string>

template <class DataType>
class Array
{
public:
    Array(int size);
    DataType& operator[](int index);
    void changeSize(int newSize);
    int length() const;
    std::string err() const;

private:
    DataType* elements;
    int capacity;
    DataType dud;
    int errorCode;
};

// Method Definitions

template<class DataType>
Array<DataType>::Array(int size) {
    if (size < 1) {
        capacity = 1;
        errorCode = 1;
    } else {
        capacity = size;
        errorCode = 0;
    }
    elements = new DataType[capacity];
}

template<class DataType>
DataType& Array<DataType>::operator[](int index) {
#ifdef DEBUG_ARRAY
    if (index < 0 || index >= capacity) {
        errorCode |= 2;
        return dud;
    }
#endif
    return elements[index];
}

template<class DataType>
void Array<DataType>::changeSize(int newSize) {
    if (newSize < 1) {
        errorCode |= 4;
        return;
    }

    DataType* newArray = new DataType[newSize];
    int limit = (newSize > capacity) ? capacity : newSize;

    for (int i = 0; i < limit; i++) {
        newArray[i] = elements[i];
    }

    delete[] elements;
    elements = newArray;
    capacity = newSize;
}

template<class DataType>
int Array<DataType>::length() const {
    return capacity;
}

template<class DataType>
std::string Array<DataType>::err() const {
    if (errorCode == 0) return "No error.\n";
    std::string errorMessage = "";

    if (errorCode & 1) {
        errorMessage += "Nonpositive size passed into constructor, so\n";
        errorMessage += "the capacity was set to 1 by default\n";
    }

    if (errorCode & 2) {
        errorMessage += "Index out of range.\n";
    }

    if (errorCode & 4) {
        errorMessage += "Nonpositive size passed into changeSize, so\n";
        errorMessage += "the size of the array was not changed.";
    }

    return errorMessage;
}

#endif // ARRAY_H