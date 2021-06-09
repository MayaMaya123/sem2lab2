//
// Created by Майя Флейшер on 31.05.2021.
//
#ifndef SEM2LAB2_VECTOR_H
#define SEM2LAB2_VECTOR_H

#include <cmath>
#include <ostream>

template<class T>
class Vector {
private:
    ArraySequence<T> vector;
public:

    int GetLength() {
        return vector.GetLength();
    }

    //создание вектор с непроинициализированными координатами
    Vector(int dimension) {
        ArraySequence<T> temp(dimension);
        vector = temp;
    }

    //создание обьекта = создание пустого вектора
    Vector() {
        ArraySequence<T> new_vector;
        vector = new_vector;
    }

    // создание вектора по массиву
    Vector(T *coords, int size) {
        ArraySequence<T> new_vector(coords, size);
        vector = new_vector;
    }

    // копирующий конструктор
    explicit Vector(ArraySequence<T> &n_vector) {
        vector = n_vector;
    }

    //получить значение координаты по индексу
    T &GetCoordinate(int index) {
        return vector.Get(index);
    }

    //получить длинну вектора dimension - размерность массива
    int GetDimension() {
        return vector.GetLength();
    }

    Vector<T> &SumVectors(Vector<T> second_vector) {
        auto *result = new Vector<T>(vector.GetLength());
        for (int i = 0; i < vector.GetLength(); i++) {
            result->vector.Set(i, vector.Get(i) + second_vector.GetCoordinate(i));
        }
        return *result;
    }

    //умножение на скаляр
    Vector<T> &ScalarMultiVector(T scalar_number) {
        auto *result = new Vector<T>(vector.GetLength());
        for (int i = 0; i < vector.GetLength(); i++) {
            result->vector.Set(i, vector.Get(i) * scalar_number);
        }
        return *result;
    }

    //вычисление нормы = длина
    float NormaVector() {
        float t = 0;
        for (int i = 0; i < vector.GetLength(); i++) {
            t += vector.Get(i) * vector.Get(i);
        }
        return sqrt(t);
    }

    //скалярное произведение
    T ScalarMultiplicationVectors(Vector<T> second_vector) {
        T t = 0;
        for (int i = 0; i < vector.GetLength(); i++) {
            t += vector.Get(i) * second_vector.GetCoordinate(i);
        }
        return t;
    }

    friend std::ostream &operator<<(std::ostream &file_cout, Vector<T> &v) {
        file_cout << '{';
        for (int i = 0; i < v.GetLength(); i++) {
            file_cout << v.GetCoordinate(i);
            if (i != v.GetLength() - 1) {
                file_cout << ", ";
            }
        }
        file_cout << '}';
        return file_cout;
    }
};

#endif //SEM2LAB2_VECTOR_H
