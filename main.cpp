#include <iostream>
#include "Menu_for_vectors_and_matrix.h"


void action_with_vectors_for_int(Vector<int> vector) {
    int menu;

    cout << "Choose action with vector" << endl;
    cout << "1 - sum of vectors" << endl;
    cout << "2 - multiplication by number" << endl;
    cout << "3 - calculate length" << endl;
    cout << "4 - scalar multiplication" << endl;
    cout << "5 - exit" << endl;
    cin >> menu;
    if (menu == 1) {
        cout << "enter coordinates of second vector" << endl;
        Vector<int> vector2 = Vector<int>(enter_int(vector.GetLength()), vector.GetLength());
        Vector<int> result = vector.SumVectors(vector2);
        cout << result << endl;
    } else if (menu == 2) {
        cout << "enter a number" << endl;
        int number;
        cin >> number;
        Vector<int> result = vector.ScalarMultiVector(number);
        cout << result << endl;
    } else if (menu == 3) {
        float result = vector.NormaVector();
        cout << result << endl;
    } else if (menu == 4) {
        cout << "enter coordinates of second vector" << endl;
        Vector<int> vector2 = Vector<int>(enter_int(vector.GetLength()), vector.GetLength());
        int result = vector.ScalarMultiplicationVectors(vector2);
        cout << result << endl;
    } else if (menu == 5) {
        exit(0);
    }
}


void action_with_vectors_for_float(Vector<float> vector) {
    int menu;
    cout << "Choose action with vector" << endl;
    cout << "1 - sum of vectors" << endl;
    cout << "2 - multiplication by number" << endl;
    cout << "3 - calculate length" << endl;
    cout << "4 - scalar multiplication" << endl;
    cout << "5 - exit" << endl;
    cin >> menu;
    if (menu == 1) {
        cout << "enter coordinates of second vector" << endl;
        Vector<float> vector2 = Vector<float>(enter_float(vector.GetLength()), vector.GetLength());
        Vector<float> result = vector.SumVectors(vector2);
        cout << result << endl;
    }
    if (menu == 2) {
        cout << "enter a number" << endl;
        float number;
        cin >> number;
        Vector<float> result = vector.ScalarMultiVector(number);
        cout << result << endl;
    }
    if (menu == 3) {
        float result = vector.NormaVector();
        cout << result << endl;
    }
    if (menu == 4) {
        cout << "enter coordinates of second vector" << endl;
        Vector<float> vector2 = Vector<float>(enter_float(vector.GetLength()), vector.GetLength());
        float result = vector.ScalarMultiplicationVectors(vector2);
        cout << result << endl;
    }
    if (menu == 5) {
        exit(0);
    }
}


void action_with_int_matrix(Matrix<int> matrix) {
    int menu;
    cout << "Choose action with matrix" << endl;
    cout << "1 - sum of matrix" << endl;
    cout << "2 - multiplication by number" << endl;
    cout << "3 - elementary convert " << endl;
    cout << "5 - exit" << endl;
    cin >> menu;
    if (menu == 1) {
        cout << "Enter elements of second matrix" << endl;
        Matrix<int> matrix2 = Matrix<int>(enter_int_matrix(matrix.GetSize()));
        Matrix<int> result = matrix.SumMatrix(matrix2);
        cout << result << endl;
    }
    if (menu == 2) {
        cout << "enter a number" << endl;
        int number;
        cin >> number;
        Matrix<int> result = matrix.ScalarMultiMatrix(number);
        cout << result << endl;
    }
    if (menu == 3) {
        int line1;
        int line2;
        int number;
        cout << "Enter line1" << endl;
        cin >> line1;
        cout << "Enter line2" << endl;
        cin >> line2;
        cout << "Enter a number" << endl;
        cin >> number;
        Matrix<int> result = matrix.ElementaryLineConv(line1, line2, number);
        cout << result << endl;
    }
    if (menu == 4) {
        exit(0);
    }
}


void action_with_float_matrix(Matrix<float> matrix) {
    int menu;
    cout << "Choose action with matrix" << endl;
    cout << "1 - sum of matrix" << endl;
    cout << "2 - multiplication by number" << endl;
    cout << "3 - elementary convert " << endl;
    cout << "5 - exit" << endl;
    cin >> menu;
    if (menu == 1) {
        cout << "Enter elements of second matrix" << endl;
        Matrix<float> matrix2 = Matrix<float>(enter_float_matrix(matrix.GetSize()));
        Matrix<float> result = matrix.SumMatrix(matrix2);
        cout << result << endl;
    }
    if (menu == 2) {
        cout << "enter a number" << endl;
        float number;
        cin >> number;
        Matrix<float> result = matrix.ScalarMultiMatrix(number);
        cout << result << endl;
    }
    if (menu == 3) {
        int line1;
        int line2;
        float number;
        cout << "Enter line1" << endl;
        cin >> line1;
        cout << "Enter line2" << endl;
        cin >> line2;
        cout << "Enter a number" << endl;
        cin >> number;
        Matrix<float> result = matrix.ElementaryLineConv(line1, line2, number);
        cout << result << endl;
    }
    if (menu == 4) {
        exit(0);
    }
}


int main() {
    int menu;
    int dimension;
    int type_selection;
    cout << "What type of data do you want?" << endl;
    cout << "1-vectors" << endl;
    cout << "2-matrix" << endl;
    cin >> menu;
    if (menu == 1) {
        cout << "Enter dimension of vector" << endl;
        cin >> dimension;
        while (true) {
            cout << "Choose type of vector" << endl;
            cout << "1 - integer" << endl;
            cout << "2 - float" << endl;
            cin >> type_selection;

            switch (type_selection) {
                case 1: {
                    cout << "Enter a vector's coordinates" << endl;
                    Vector<int> intVector = Vector<int>(enter_int(dimension), dimension);
                    action_with_vectors_for_int(intVector);
                    break;
                }
                case 2: {
                    cout << "Enter a vector's coordinates" << endl;
                    Vector<float> floatVector = Vector<float>(enter_float(dimension), dimension);
                    action_with_vectors_for_float(floatVector);
                    break;
                }
            }
        }
    }
    if (menu == 2) {
        cout << "Enter dimension of matrix" << endl;
        cin >> dimension;
        while (true) {
            cout << "1-integer" << endl;
            cout << "2-float" << endl;
            cin >> type_selection;
            switch (type_selection) {
                case 1: {
                    cout << "Enter elements of matrix" << endl;
                    Matrix<int> floatMatrix = Matrix<int>(enter_int_matrix(dimension));
                    action_with_int_matrix(floatMatrix);
                    break;
                }
                case 2: {
                    cout << "Enter a matrix's coordinates" << endl;
                    Matrix<float> floatMatrix = Matrix<float>(enter_float_matrix(dimension));
                    action_with_float_matrix(floatMatrix);
                    break;
                }
            }
        }
    }
    return 0;
}
