//
// Created by Майя Флейшер on 23.05.2021.
//
#include <cstdlib>

#ifndef SEM2LAB2_DYNAMIC_ARRAY_H
#define SEM2LAB2_DYNAMIC_ARRAY_H

template<class T> // шаблон
class DynamicArray {    //объявление класс
private: //приватные переменные
    T *items_of_array{nullptr};  //сам массив
    size_t size{0};  //количество элементов массива
public:
    DynamicArray() = default; //создать пустой массив
    void Delete();

    ~DynamicArray();  //деструктор
    //Создание объекта
    DynamicArray(T *array, int count); //Копировать элементы из переданного массива
    explicit DynamicArray(int amount_of_elements);//Создать массив заданной длины
    DynamicArray(DynamicArray<T> const &dynamicArray);//Копирующий конструктор
    //Декомпозиция
    T &Get(int index); //Получить элемент по индексу
    int GetLength(); //Получить размер массива
    //Операции
    //GetSubsequence(int first_index, int last_index);
    void Set(int index, T value);  //Задать элемент по индексу
    void Resize(int newSize);  //Изменить размер массива
    T &operator[](int i) {   //перегружаем опреатор
        return items_of_array[i];
    }

    //перегружаем оператор
    DynamicArray<T> &operator=(const DynamicArray<T> &dynamicArray) {
        this->Resize(dynamicArray.size);
        for (int i = 0; i < size; i++) {
            items_of_array[i] = dynamicArray.items_of_array[i];
        }
        return *this;
    }
};


#endif //SEM2LAB2_DYNAMIC_ARRAY_H

