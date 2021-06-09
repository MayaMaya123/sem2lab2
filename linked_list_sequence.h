//
// Created by Майя Флейшер on 27.05.2021.
//

#ifndef SEM2LAB2_LINKED_LIST_SEQUENCE_H
#define SEM2LAB2_LINKED_LIST_SEQUENCE_H
#include "linked_list.h"
#include "sequence.h"
#include "ThorowOutOfRange.h"
template <class T>
class LinkedListSequence : public sequence<T> {
private:
    LinkedList<T> linkedList;

public:
    //Создание объекта
    LinkedListSequence (T* items, int count){  //Копировать элементы из переданного массива
        linkedList =  LinkedList<T>(items, count);
    }
    LinkedListSequence (){  //Создать пустой список
        linkedList = LinkedList<T>();
    }
    explicit LinkedListSequence (LinkedList<T> const &list){
        linkedList = LinkedList<T> (list);
    }// Копирующий конструктор
    T GetFirst(){  //Получить первый элемент в списке
        if (linkedList.GetLength() == 0) {
            throw IndexOutOfRange();
        }
        return linkedList.GetFirst();
    }
    T GetLast(){  //Получить последний элемент в списке
        if (linkedList.GetLength() == 0) {
            throw IndexOutOfRange();
        }
        return linkedList.GetLast();
    }
    T& Get(int index){  //Получить элемент по индексу
        if (index < 0 || index >= linkedList.GetLength()){
            throw IndexOutOfRange();
        }
        return linkedList.Get(index);
    }

    void Set(T value, int index){  //устновить значение по индексу
        linkedList.Set(index, value);
    }

    sequence<T>* GetSubsequence(int startIndex, int endIndex){  //Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.
        auto *res = new LinkedListSequence<T>(linkedList.GetSubList(startIndex, endIndex));
        return res;
    }
    int GetLength(){
        return linkedList.GetLength();
    }	//Получить длину списка
    void Append(T item){
        return linkedList.Append(item);
    }//Добавляет элемент в конец списка
    void Prepend(T item){
        return linkedList.Prepend(item);
    }  //Добавляет элемент в начало списка
    void InsertAt(T item, int index){
        if (index < 0 || index >= linkedList.GetLength()){
            throw IndexOutOfRange();
        }
        return linkedList.InsertAt(item, index);
    } //Вставляет элемент в заданную позицию
    sequence <T>* Concat(sequence <T> *list){  //Сцепляет два списка
        LinkedListSequence<T> *new_list = new LinkedListSequence<T>();
        for (int i =0; i<list->GetLength(); i++) {
            new_list->Append(list->Get(i));
        }
        return new_list;
    }
};

#endif //SEM2LAB2_LINKED_LIST_SEQUENCE_H
