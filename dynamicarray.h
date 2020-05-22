#pragma once
#include <iostream>
#define defaultsize 5
using namespace std;

template <typename Data>
class DynamicArray
{
private:
    unsigned int capacity;
    Data * data;
public:
    DynamicArray()
    {
        capacity = defaultsize;
        data = new Data[capacity];
        for(unsigned int i = 0; i< capacity; ++i)
            data[i] = 0;
    }
    DynamicArray(unsigned int const sizearray)
    {
        capacity = sizearray;
        data = new Data[capacity];
        for(unsigned int i = 0; i< capacity; ++i)
            data[i] = 0;
    }
    DynamicArray(DynamicArray const &dynamicArray)
    {
        capacity = dynamicArray.capacity;
        data = new Data[capacity];
        for(unsigned int i = 0; i < capacity; ++i)
            data[i]= dynamicArray.data[i];
    }
    Data& operator [] (unsigned int const index)
    {
        if(index >= capacity)
        {
            Data *tmpdata = new Data[1+index];
            for(unsigned int i = 0; i < index +1; ++i)
            {
                if(i < capacity)
                {
                    tmpdata[i]= data[i];
                }else{
                    tmpdata[i]= 0;
                }
            }
            delete[] data;
            data = tmpdata;
            capacity = index +1;
        }
        return data[index];
    }
    bool const isContains(Data const inputData) const
    {
        for(unsigned int i = 0; i < capacity; ++i)
            if(data[i] == inputData)
                return true;
        return false;
    }
    bool const isEmpty() const
    {
        if(capacity == 0)
            return true;
        return false;
    }
    bool const clear()
    {
        if(capacity == 0)
            return  false;
        delete[] data;
        capacity = 0;
        return true;
    }
    unsigned int const size()
    {
        return capacity;
    }
    bool const resize(unsigned int const newSize)
    {
        Data *tmpdata = new Data[newSize];
        if(tmpdata == nullptr)
            return false;
        for(unsigned int i = 0; i < newSize; ++i)
        {
            if(i < capacity)
            {
                tmpdata[i]= data[i];
            }else{
                tmpdata[i]= 0;
            }
        }
        delete[] data;
        data = tmpdata;
        capacity = newSize;
        return true;
    }
    void print() const
    {
        cout<<endl;
        if(capacity == 0)
        {
            cout<<"Array is empty"<<endl;
        }else{
            for(unsigned int i = 0; i < capacity; ++i)
                cout<<i<<" element = "<<data[i]<<endl;
        }
    }
    DynamicArray& operator =(DynamicArray const &dynamicArray)
    {
        delete[] data;
        capacity = dynamicArray.capacity;
        data = new Data[capacity];
        for(unsigned int i = 0; i < capacity; ++i)
            data[i] = dynamicArray[i];
        return *this;
    }
    ~DynamicArray()
    {
        capacity = 0;
        delete[] data;
    }
};
