//
// Created by Майя Флейшер on 01.06.2021.
//
#include "array_sequence.h"

#ifndef SEM2LAB2_SQUARE_MATRIX_H
#define SEM2LAB2_SQUARE_MATRIX_H


template<class T>
class Matrix {
private:
    ArraySequence<ArraySequence<T>> matrix{};
    int size = 0;
public:
    //создание обьекта
    Matrix() = default;

    //копирующий конструктор = создание матрицы
    explicit Matrix(ArraySequence<ArraySequence<T>> &new_matrix) {
        int count = new_matrix.GetLength();
        for (int i = 0; i < count; i++) {
            ArraySequence<T> column;
            for (int j = 0; j < count; j++) {
                column.Append(new_matrix.Get(i).Get(j));
            }
            matrix.Append(column);
            size = count;
        }
    }

    explicit Matrix(int size)
            : size(size) {
        for (int i = 0; i < size; i++) {
            ArraySequence<T> column;
            matrix.Append(column);
        }
    }

    //line - строчка, column - столбец
    T &Get(int line, int column) {
        return matrix.Get(line).Get(column);
    }

    int GetSize() {
        return size;
    }

    //Сложение
    Matrix<T> SumMatrix(Matrix<T> &second_matrix) {
        Matrix<T> result;
        for (int i = 0; i < size; i++) {
            ArraySequence<T> column;
            for (int j = 0; j < size; j++) {
                column.Append(matrix.Get(i).Get(j) + second_matrix.Get(i, j));
            }
            result.matrix.Append(column);
        }
        result.size = size;
        return result;
    }

    void Set(int index, ArraySequence<T> value) {
        matrix.Set(index, value);
    }

    //умножение на скаляр
    Matrix<T> ScalarMultiMatrix(T scalar_number) {
        auto *result = new Matrix<T>(size);
        for (int i = 0; i < size; i++) {
            ArraySequence<T> column;
            for (int j = 0; j < size; j++) {
                matrix.Get(i).multiplicate_for_by_number(scalar_number);
                result->Set(i, matrix.Get(i));
            }
        }
        return *result;
    }

    //элементарные преобразования строк
    Matrix<T> &ElementaryLineConv(int line1, int line2, T scalar_number) {
        auto *result = new Matrix<T>();
        for (int i = 0; i < size; i++) {
            ArraySequence<T> line;
            for (int j = 0; j < size; j++) {
                if (j == line1) {
                    line.Append(matrix.Get(i).Get(line2) * scalar_number + matrix.Get(i).Get(line1));
                } else {
                    line.Append(matrix.Get(i).Get(j));
                }
            }
            result->matrix.Append(line);

        }
        result->size = size;
        matrix = result->matrix;
        return *this;
    }

    //перегрузка оператора
    Matrix<T> &operator=(Matrix<T> result) {
        matrix = result.matrix;
        size = result.size;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &file_cout, Matrix<T> &m) {
        for (int i = 0; i < m.GetSize(); i++) {
            for (int j = 0; j < m.GetSize(); j++) {
                file_cout << m.Get(i, j) << " ";
            }
            file_cout << std::endl;
        }
        file_cout << std::endl;
        return file_cout;
    }
};


#endif //SEM2LAB2_SQUARE_MATRIX_H
