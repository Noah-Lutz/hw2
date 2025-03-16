#ifndef ARRAY_H
#define ARRAY_H

#include <string>

template <class DataType>
class Array
{
public:
    Array(int size);
    DataType & operator[](int index);
    void changeSize(int newSize);
    int length() const;
    std::string err() const;
private:
    DataType *elements;
    int capacity;
    DataType dud;
    int errorCode;
};

#endif //ARRAY_H
