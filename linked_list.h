//
// Created by Майя Флейшер on 23.05.2021.
//
#ifndef SEM2LAB2_LINKED_LIST_H
#define SEM2LAB2_LINKED_LIST_H

template<class T>
class LinkedList {
// структура элемента
//ptr=pointer
private:
    struct element {
        T value;  // значение которое хранится в одном элементе
        struct element *ptr_to_next;
    };
    struct element *ptr_to_first;
    struct element *ptr_to_last;
    int length; // длина листа

public:
    //Создание объекта
    LinkedList(T *items, int count);  //создаем из статического массива список
    LinkedList();  //Создать пустой список
    LinkedList(LinkedList<T> const &list);    //Копирующий конструктор
    //Декомпозиция
    T GetFirst();   //Получить первый элемент в списке
    T GetLast();  //Получить последний элемент в списке
    T Get(int index);  //Получить элемент по индексу
    void Set(int index, T value);  //Задать элемент по индексу
    LinkedList<T> GetSubList(int startIndex, int endIndex);  //Получить список из всех элементов,
    // начиная с начального заданного индекса и заканчивая конечным заданным индексом
    int GetLength();  //Получить длину списка
    //Операции
    void Append(T item);    //Добавляет элемент в конец списка
    void Prepend(T item);    //Добавляет элемент в начало списка
    void InsertAt(T item, int index);   //Вставляет элемент в заданную позицию
    LinkedList<T> Concat(LinkedList<T> list);    //Сцепляет два списка

};

#endif //SEM2LAB2_LINKED_LIST_H
