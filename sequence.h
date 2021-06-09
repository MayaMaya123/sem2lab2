#include <__bit_reference>
//
// Created by Майя Флейшер on 27.05.2021.
//
#include <cstdlib>

#ifndef SEM2LAB2_SEQUENCE_H
#define SEM2LAB2_SEQUENCE_H

// sequence - последовательность
template<class T>
class sequence {
public:
    virtual T GetFirst() = 0;  //получить значение первого элемента
    virtual T GetLast() = 0;  // Получить значение второго элемента
    virtual T &Get(int index) = 0;  // получить какой-либо элемент имассива по индексу
    virtual sequence<T> *GetSubsequence(int start_index,
                                        int end_index) = 0;  //Subsequence - подпоследовательность;  получить подпоследовательность
    virtual int GetLength() = 0;//получить длину
    virtual void Set(int index, T value) = 0;

    virtual void Append(T item) = 0;  // добавить элемент в конец
    virtual void Prepend(T item) = 0;

    virtual void InsertAt(T item, int index) = 0;  //вставляет элемент по индексу
    virtual sequence<T> *Concat(sequence<T> *list) = 0;

};

#endif //SEM2LAB2_SEQUENCE_H
