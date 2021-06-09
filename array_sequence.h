//
// Created by Майя Флейшер on 28.05.2021.
//
#include "sequence.h"
#include "dynamic_array.h"
#include "dynamic_array.cpp"

#ifndef SEM2LAB2_ARRAY_SEQUENCE_H
#define SEM2LAB2_ARRAY_SEQUENCE_H

#include "ThorowOutOfRange.h"

template<class T>
class ArraySequence : public sequence<T> {
private:
    DynamicArray<T> dynamicArray{};
public:
    /*class IndexOutOfRange{
    private:
        int size;
        int index;
    public:
        //IndexOutOfRange(int size, int index) : size(size), index(index){}

    };*/

    /*void DeleteArraySequence(){
        dynamicArray.Delete();
    }*/
//создание массива с непроинициализированными элементами
    explicit ArraySequence(int size) {
        dynamicArray = DynamicArray<T>(size);
    }

    ArraySequence() : dynamicArray() {
    }

    ArraySequence(T *items, int count) {
        dynamicArray = DynamicArray<T>(items, count);

    } //Копировать элементы из переданного массива


    explicit ArraySequence<T>(const sequence<T> &list)
            : dynamicArray(list) {
    }  //Копирующий конструктор


    T GetFirst() {
        if (dynamicArray.GetLength() == 0) {
            throw IndexOutOfRange();
        }
        return dynamicArray.Get(0);
    } //Получить первый элемент в списке


    T GetLast() {
        if (dynamicArray.GetLength() == 0) {
            throw IndexOutOfRange();
        }
        return dynamicArray.Get(dynamicArray.GetLength() - 1);
    }


    T &Get(int index) {
        if (index < 0 || index >= dynamicArray.GetLength()) {
            throw IndexOutOfRange();
        }
        return dynamicArray.Get(index);
    }


    void Set(int index, T value) {  //устновить значение по индексу
        dynamicArray.Set(index, value);
    }


    int GetLength() {  //Получить длину списка
        return dynamicArray.GetLength();
    }


    sequence<T> *GetSubsequence(int start_index, int end_index) {
        auto new_array = new ArraySequence<T>;
        for (int i = start_index; i <= end_index; i++) {
            new_array->Append(dynamicArray[i]);
        }
        return new_array;

    }


    void Append(T item) {
        dynamicArray.Resize(dynamicArray.GetLength() + 1);
        dynamicArray.Set(dynamicArray.GetLength() - 1, item);
    }


    void Prepend(T item) {
        dynamicArray.Resize(dynamicArray.GetLength() + 1);
        for (int i = dynamicArray.GetLength() - 2; i >= 0; i--) {
            dynamicArray[i + 1] = dynamicArray[i];
        }
        dynamicArray.Set(0, item);
    }


    void InsertAt(T item, int index) {
        if (index < 0 || index >= dynamicArray.GetLength()) {
            throw IndexOutOfRange();
        }
        dynamicArray.Resize(dynamicArray.GetLength() + 1);
        for (int i = dynamicArray.GetLength() - 2; i >= index; i--) {
            dynamicArray[i + 1] = dynamicArray[i];
        }
        dynamicArray[index] = item;
    }  //Вставляет элемент в заданную позицию

    void multiplicate_for_by_number(T number) {
        for (int i = 0; i < dynamicArray.GetLength(); i++) {
            dynamicArray[i] = dynamicArray[i] * number;
        }
    }


    sequence<T> *Concat(sequence<T> *list) {
        auto *new_array_sequence = new ArraySequence<T>;
        for (int i = 0; i < dynamicArray.GetLength(); i++) {
            new_array_sequence->Append(dynamicArray.Get(i));
        }
        for (int i = 0; i < list->GetLength(); i++) {
            new_array_sequence->Append(list->Get(i));
        }
        return new_array_sequence;
    }   //Сцепляет два списка


    T &operator[](int i) {
        return dynamicArray[i];
    }

    ArraySequence<T> &operator=(const ArraySequence<T> &arraySequence) {
        dynamicArray = arraySequence.dynamicArray;
        return *this;
    }
};

#endif
