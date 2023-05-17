#pragma once
#include<iostream>
#ifndef ARRAYDYNAMIC_H_
#define ARRAYDYNAMIC_H_
using namespace std;

template <class T>
class ArrayDynamic
{
private:
    T* data;
    int size;
    void copiarData(T*& aux)
    {
        aux = new T[size];
        for (int i = 0; i < size; i++)
        {
            aux[i] = data[i];
        }
    }
public:
    ArrayDynamic()
    {
        data = new T[0];
        size = 0;
    };
    ArrayDynamic(T* arr, const int tamanio)
    {
        data = new T[tamanio];
        for (int i = 0; i < tamanio; ++i)
        {
            data[i] = arr[i];
        }
    }
    ArrayDynamic(const ArrayDynamic& lista)
    {
        data = new T[lista.getSize()];
        size = lista.getSize();
        for (int i = 0; i < size; i++)
        {
            data[i] = lista.data[i];
        }

    }
    ~ArrayDynamic()
    {
        delete[] data;
    }
    int getSize() { 
        return size; 
    }
    void pushBack(T value)
    {
        T* aux;
        copiarData(aux);
        delete[] data;
        size++;
        data = new T[size];
        for (int i = 0; i < size - 1; i++)
        {
            data[i] = aux[i];
        }
        data[size - 1] = value;
        delete[] aux;
    }
    void insert(T value, int pos)
    {
        T* aux;
        copiarData(aux);
        delete[] data;
        size++;
        data = new T[size];
        for (int i = 0; i < size ; i++)
        {
            if (i == pos)
            {
                data[i] = value;
            }
            else if (i > pos)
            {
                data[i] = aux[i-1];
            }
            else
                data[i] = aux[i];
        }
        delete[] aux;
    }
    void remove(int pos)
    {
        T* aux;
        copiarData(aux);
        delete[] data;
        size--;
        data = new T[size];
        for (int i = 0; i < size; i++)
        {
            if (i >= pos)
            {
                data[i] = aux[i + 1];
            }
            else
            {
                data[i] = aux[i];
            }
        }
        delete[] aux;
    }
    void print()
    {
        cout << "\t ACTUALIZADO "<< endl;
        for (int i = 0; i < size; i++)
        {
            cout <<"\t" << *(data + i) << endl;
        }
    }
};

#endif