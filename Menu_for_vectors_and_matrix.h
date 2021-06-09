//
// Created by Майя Флейшер on 01.06.2021.
#include "square_matrix.h"
#include "vector.h"
#include <iostream>

using namespace std;

int *enter_int(int dimension) {
    int *coords = new int[dimension];
    int temp;
    for (int i = 0; i < dimension; i++) {
        cin >> temp;
        coords[i] = temp;
    }
    return coords;
}

float *enter_float(int dimension) {
    auto *coords = new float[dimension];
    float temp;
    for (int i = 0; i < dimension; i++) {
        cin >> temp;
        coords[i] = temp;
    }
    return coords;
}

ArraySequence<ArraySequence<int>> &enter_int_matrix(int dimension) {
    int temp;
    auto *matrix = new ArraySequence<ArraySequence<int>>;
    for (int i = 0; i < dimension; i++) {
        auto *column = new ArraySequence<int>;
        for (int j = 0; j < dimension; j++) {
            cin >> temp;
            column->Append(temp);
        }
        matrix->Append(*column);
    }
    return *matrix;
}

ArraySequence<ArraySequence<float>> &enter_float_matrix(int dimension) {
    int temp;
    auto *matrix = new ArraySequence<ArraySequence<float>>;
    for (int i = 0; i < dimension; i++) {
        auto *column = new ArraySequence<float>;
        for (int j = 0; j < dimension; j++) {
            cin >> temp;
            column->Append(temp);
        }
        matrix->Append(*column);
    }
    return *matrix;
}