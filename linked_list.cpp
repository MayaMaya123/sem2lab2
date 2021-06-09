//
// Created by Майя Флейшер on 23.05.2021.
// когда список создается ему должна ему присваиваться какая то длина и каждй раз когда размер списка изменяется нужно его соотвествено
// увеличивать
#include "ThorowOutOfRange.h"
#include "linked_list.h"

// добавляет элемент в конец списка; item - некоторая информация которую собираемся хранить в списке
template<class T>
void LinkedList<T>::Append(T item) {
    auto *new_ptr = new struct element;  // выделяем память под новый элемент
    new_ptr->value = item;  // добавляем в конец списка новый элемент
    new_ptr->ptr_to_next = nullptr;
    if (ptr_to_last != nullptr)
        ptr_to_last->ptr_to_next = new_ptr;
    ptr_to_last = new_ptr;
    if (ptr_to_first == nullptr) {  // проверяем на пустоту
        ptr_to_first = ptr_to_last;
    }
    length++;
}


//Добавляет элемент в начало списка
template<class T>
void LinkedList<T>::Prepend(T item) {
    auto *new_ptr = new struct element;
    new_ptr->ptr_to_next = ptr_to_first;
    ptr_to_first = new_ptr;
    if (ptr_to_last == nullptr) {
        ptr_to_last = ptr_to_first;
    }
    length++;
}


//Вставляет элемент в заданную позицию
template<class T>
void LinkedList<T>::InsertAt(T item, int index) {
    if (index == 0) {
        Prepend(item);
        return;
    }
    if (index == length - 1) {
        Append(item);
        return;
    }
    auto *new_cell = new struct element;
    struct element *curr_ptr = ptr_to_first;
    new_cell->value = item;
    for (int i = 0; i < index; i++) {
        curr_ptr = curr_ptr->ptr_to_next;
    }
    new_cell->ptr_to_next = curr_ptr->ptr_to_next;
    curr_ptr->ptr_to_next = new_cell;
    length++;
}


//Сцепляет два списка
template<class T>
LinkedList<T> LinkedList<T>::Concat(LinkedList<T> list) {
    LinkedList<T> new_list = LinkedList<T>(list);
    struct element *curr_ptr = ptr_to_first;
    for (int i = 0; i < length; i++) {
        new_list.Append(curr_ptr->value);
        curr_ptr = curr_ptr->ptr_to_next;
    }
    return new_list;
}


//создаем из статического массива список
template<class T>
LinkedList<T>::LinkedList(T *items, int count) {
    length = 0;
    ptr_to_last = nullptr;
    ptr_to_first = nullptr;
    for (int i = 0; i < count; i++) {
        Append(items[i]);//добавляем элементы листа в конец

    }
}

//Создать пустой список
template<class T>
LinkedList<T>::LinkedList() {
    length = 0;
    ptr_to_first = nullptr;
    ptr_to_last = nullptr;
}


//Копирующий конструктор - копируем список
template<class T>
LinkedList<T>::LinkedList(
        LinkedList<T> const &list) {  //LinkedList - это и есть список номер один &list-ссылка на список который нужно скопировать
    length = 0;
    ptr_to_first = nullptr;
    ptr_to_last = nullptr;
    struct element *curr = list.ptr_to_first;  // curr=current -текущий указатель на текущий элемент
    while (curr != nullptr) {
        Append(curr->value);
        curr = curr->ptr_to_next;
    }
}


//Получить первый элемент в списке
template<class T>
T LinkedList<T>::GetFirst() {
    if (ptr_to_first == nullptr) {
        if (length == 0) {
            throw IndexOutOfRange();
        }
    }
    return ptr_to_first->value;
}


//Получить последний элемент в списке
template<class T>
T LinkedList<T>::GetLast() {
    if (ptr_to_last == nullptr) {
        if (length == 0) {
            throw IndexOutOfRange();
        }
    }
    return ptr_to_last->value;

}


//Получить элемент по индексу
template<class T>
T LinkedList<T>::Get(int index) {
    if (index < 0 || index >= length) {
        throw IndexOutOfRange();
    }
    struct element *cell = ptr_to_first; //cell-ячейка
    for (int i = 0; i < index; i++) {
        cell = cell->ptr_to_next;
    }
    return cell->value;
}

template<class T>
void LinkedList<T>::Set(int index, T value) {  //Задать элемент по индексу
    if (index < 0 || index >= length) {
        throw IndexOutOfRange();
    }
    element *element = ptr_to_first;
    for (int i = 0; i < index; i++, element = element->ptr_to_next);
    element->value = value;
}

//Получить список из всех элементов, начиная с начального заданного индекса(startIndex) и заканчивая конечным заданным индексом (endIndex)
template<class T>
LinkedList<T> LinkedList<T>::GetSubList(int startIndex, int endIndex) {
    LinkedList<T> result = LinkedList<T>();
    struct element *cell = ptr_to_first;
    for (int i = 0; i < startIndex; i++) {
        cell = cell->ptr_to_next;
    }
    for (int i = startIndex; i <= endIndex; i++) {
        cell = cell->ptr_to_next;
        result.Append(cell->value);
    }
    return result;
};


//Получить длину списка
template<class T>
int LinkedList<T>::GetLength() {
    /* struct element *curr=ptr_to_last;
     int counter = 0;
     while (curr !=nullptr){
         curr = curr->ptr_to_next;
         counter++;
     }
     return counter;
     */
    return length;
}