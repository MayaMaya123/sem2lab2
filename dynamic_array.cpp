//
// Created by Майя Флейшер on 23.05.2021.
//

#include "dynamic_array.h"

template<class T>
void DynamicArray<T>::Delete() {
    if (items_of_array != nullptr && size != 0)
        delete[] items_of_array;
    items_of_array = nullptr;
    size = 0;
}


template<class T>
DynamicArray<T>::~DynamicArray<T>() {
    if (items_of_array != nullptr && size != 0)
        delete[] items_of_array;
    items_of_array = nullptr;
    size = 0;
}


//Копировать элементы из переданного массива
template<class T>
DynamicArray<T>::DynamicArray(T *array, int count) {   //описание функции из класса DynamicArray
    items_of_array = new T[count];  //выделение памяти для массива: новый тип количество
    size = count;
    for (int i = 0; i < count; i++) {
        items_of_array[i] = array[i];
    }
}


//Создать массив заданной длины
template<class T>
DynamicArray<T>::DynamicArray(int amount_of_elements) {
    items_of_array = new T[amount_of_elements];
    if (size < 0) {
        size = 0;
    }
    size = amount_of_elements;

}

//Копирующий конструктор
template<class T>
DynamicArray<T>::DynamicArray(DynamicArray<T> const &dynamicArray) {
    items_of_array = new T[dynamicArray.size];  //выделение памяти для массива: новый тип количество
    size = dynamicArray.size;
    for (int i = 0; i < size; i++) {
        items_of_array[i] = dynamicArray.items_of_array[i];
    }
}

//Получить элемент по индексу
template<class T>
T &DynamicArray<T>::Get(int index) {
    return items_of_array[index];
}


//Получить размер массива
template<class T>
int DynamicArray<T>::GetLength() {
    return size;
}


//Задать элемент по индексу
template<class T>
void DynamicArray<T>::Set(int index, T value) {
    items_of_array[index] = value;
}


//Изменить размер массива
template<class T>
void DynamicArray<T>::Resize(int newSize) {
    if (newSize == 0) {
        delete[] items_of_array;
        items_of_array = nullptr;
        size = 0;
        return;
    }

    if (newSize == size) {
        return;
    }
    if (newSize < size) {
        T *smaller_array = new T[newSize];
        for (int i = 0; i < newSize; i++) {
            smaller_array[i] = items_of_array[i];
        }
        delete[] items_of_array;
        size = newSize;
        items_of_array = smaller_array;
        return;
    }

    if (newSize > size) {
        T *larger_array = new T[newSize];
        for (int i = 0; i < size; i++) {
            larger_array[i] = items_of_array[i];
        }
        delete[] items_of_array;
        size = newSize;
        items_of_array = larger_array;
        return;
    }
}