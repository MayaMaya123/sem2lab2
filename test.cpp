//
// Created by Майя Флейшер on 27.05.2021.
//
#include <iostream>
#include <cassert>
#include "dynamic_array.h"
#include "dynamic_array.cpp"
#include "linked_list.h"
#include "linked_list.cpp"
#include "array_sequence.h"
#include "linked_list_sequence.h"

// Dynamic Array
void TestConstructor1() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    DynamicArray<int> d(arr, 7);
    assert(d.GetLength() == 7);
    assert(d.Get(5) == 6);
    d.Resize(10);
    assert(d.GetLength() == 10);
    d.Set(4, 10);
    assert(d.Get(4) == 10);
    d.Resize(0);
    assert(d.GetLength() == 0);
}

void TestConstructor2() {
    DynamicArray<int> arr(10);
    assert(arr.GetLength() == 10);
    //assert(arr.Delete_DynamicArray());
}

void TestConstructor3() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    DynamicArray<int> d(arr, 6);
    DynamicArray<int> a(d);
    assert(a.GetLength() == 6);
    assert(a.Get(3) == 4);
    assert(a.Get(2) == 3);
    assert(a.Get(1) == 2);
    //d.Delete_DynamicArray();
    //a.Delete_DynamicArray();
}

void TestConstructor4() {
    DynamicArray<int> arr(0);
    assert(arr.GetLength() == 0);
}

void GetDynamicArray() {
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    assert(d.Get(4) == 5);
    assert(d.Get(3) == 4);
    assert(d.Get(2) == 3);
    assert(d.Get(1) == 2);
    assert(d.Get(0) == 1);
    //d.Delete_DynamicArray();
}


void GetSizeDynamicArray() {
    int arr[] = {1, 2, 3, 4, 5};
    DynamicArray<int> d(arr, 5);
    assert(d.GetLength() == 5);
    //d.Delete_DynamicArray();
}


//for LinkedList
void LL_TestConstructor1() {
    int arr[] = {1, 2, 3, 4, 5};
    LinkedList<int> LL(arr, 5);
    assert(LL.GetFirst() == 1);
    assert(LL.GetLast() == 5);
    assert(LL.Get(3) == 4);
    LinkedList<int> new_list = (LL.GetSubList(1, 3));
    assert(LL.Get(1) == 2);
    assert(LL.Get(2) == 3);
    assert(LL.Get(3) == 4);
    assert(LL.GetLength() == 5);
}

void LL_TestConstructor2() {
    int arr[] = {1, 2, 3, 4, 5};
    LinkedList<int> LL(arr, 5);
    LL.Append(6);
    assert(LL.GetLength() == 6);
    assert(LL.GetLast() == 6);
    LL.Prepend(0);
    assert(LL.GetLength() == 7);
    assert(LL.GetFirst() == 0);
    LL.InsertAt(10, 3);
    assert(LL.GetLength() == 8);
    assert(LL.Get(4) == 10);
    LinkedList<int> new_list2(arr, 3);
    LinkedList<int> new_list3 = (new_list2.Concat(LL));
}


void LL_void() {
    LinkedList<int> list;
    assert(list.GetLength() == 0);
}


void LL_copy() {
    LinkedList<int> list;
    LinkedList<int> new_list(list);
}


void ArraySequenceGetFirst() {
    int arr[] = {1, 2, 3, 4, 5};
    ArraySequence<int> d(arr, 5);
    d.GetFirst();
}


void ArraySequenceGetLast() {
    int arr[] = {1, 2, 3, 4, 5};
    ArraySequence<int> d(arr, 5);
    d.GetLast();
}


void ArraySequenceGet() {
    int arr[] = {1, 2, 3, 4, 5};
    ArraySequence<int> d_arr = ArraySequence<int>(arr, 4);
    assert(d_arr.Get(3) == 4);
}


void ArraySequenceSet() {
    int arr[] = {1, 2, 3, 4, 5};
    ArraySequence<int> d_arr = ArraySequence<int>(arr, 5);
    d_arr.Set(3, 10);
    assert(d_arr.Get(3) == 10);
}

void ArraySequenceGetSubsequence() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    ArraySequence<int> d_arr = ArraySequence<int>(arr, 7);
    d_arr.GetSubsequence(2, 4);
    assert(d_arr.Get(2) == 3);
    assert(d_arr.Get(3) == 4);
    assert(d_arr.Get(4) == 5);
}

void ArraySequenceAppend() {
    int arr[] = {1, 2, 3, 4, 5};
    ArraySequence<int> d_arr = ArraySequence<int>(arr, 5);
    d_arr.Append(6);
    assert(d_arr.Get(5) == 6);
    assert(d_arr.GetLength() == 6);
}


void ArraySequencePrepend() {
    int arr[] = {1, 2, 3, 4, 5};
    ArraySequence<int> d_arr(arr, 5);
    d_arr.Prepend(0);
    assert(d_arr.Get(0) == 0);
    assert(d_arr.GetLength() == 6);
}


void ArraySequenceInsertAt() {
    int arr[] = {1, 2, 3, 4, 5};
    ArraySequence<int> d_arr(arr, 5);
    d_arr.InsertAt(10, 3);
    assert(d_arr.Get(3) == 10);
    assert(d_arr.GetLength() == 6);
}

/*void ArraySequenceConcat(){
    int arr[] = {1,2,3,4,5};
    int arr2[] ={1,2,3};
    ArraySequence<int> d_arr(arr, 5);
    ArraySequence<int> d_arr2(arr2, 3);
    d_arr.Concat(d_arr2);
}
*/


void LL_SequenceGetFirst() {
    int arr[] = {1, 2, 3, 4, 5};
    LinkedListSequence<int> LL(arr, 5);
    LL.GetFirst();
}

void LL_SequenceGetLast() {
    int arr[] = {1, 2, 3, 4, 5};
    LinkedListSequence<int> LL(arr, 5);
    LL.GetLast();
}

void LL_SequenceGet() {
    int arr[] = {1, 2, 3, 4, 5};
    LinkedListSequence<int> LL = LinkedListSequence<int>(arr, 5);
    assert(LL.Get(3) == 4);
}


void LL_SequenceSet() {
    int arr[] = {1, 2, 3, 4, 5};
    LinkedListSequence<int> LL = LinkedListSequence<int>(arr, 5);
    LL.Set(10, 3);
    assert(LL.Get(3) == 10);
}


void LL_SequenceGetSubsequence() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    LinkedListSequence<int> LL = LinkedListSequence<int>(arr, 7);
    LL.GetSubsequence(2, 4);
    assert(LL.Get(2) == 3);
    assert(LL.Get(3) == 4);
    assert(LL.Get(4) == 5);
}

void LL_SequenceAppend() {
    int arr[] = {1, 2, 3, 4, 5};
    LinkedListSequence<int> LL = LinkedListSequence<int>(arr, 5);
    LL.Append(6);
    assert(LL.Get(5) == 6);
    assert(LL.GetLength() == 6);
}

void LL_SequencePrepend() {
    int arr[] = {1, 2, 3, 4, 5};
    LinkedListSequence<int> LL = LinkedListSequence<int>(arr, 5);
    LL.Prepend(0);
    assert(LL.Get(0) == 0);
    assert(LL.GetLength() == 6);
}


int main() {
    TestConstructor1();
    std::cout << "Constr 1 OK" << std::endl;
    TestConstructor2();
    std::cout << "Constr 2 OK" << std::endl;
    TestConstructor3();
    std::cout << "Constr 3 OK" << std::endl;
    TestConstructor4();
    std::cout << "Constr 4 OK" << std::endl;
    GetDynamicArray();
    std::cout << "Constr get OK" << std::endl;
    GetSizeDynamicArray();
    std::cout << "Constr getsize OK" << std::endl;
    LL_TestConstructor1();
    std::cout << "LL_TestConstructor1 OK" << std::endl;
    LL_TestConstructor2();
    std::cout << "LL_TestConstructor2 OK" << std::endl;
    LL_void();
    std::cout << "LL_void OK" << std::endl;
    LL_copy();
    std::cout << "LL_copy OK" << std::endl;
    ArraySequenceGetFirst();
    std::cout << "ArraySequenceGetFirst OK" << std::endl;
    ArraySequenceGetLast();
    std::cout << "ArraySequenceGetLast OK" << std::endl;
    ArraySequenceGet();
    std::cout << "ArraySequenceGet OK" << std::endl;
    ArraySequenceSet();
    std::cout << "ArraySequenceSet OK" << std::endl;
    ArraySequenceGetSubsequence();
    std::cout << "ArraySequenceGetSubsequence OK" << std::endl;
    ArraySequenceAppend();
    std::cout << "ArraySequenceAppend OK" << std::endl;
    ArraySequencePrepend();
    std::cout << "ArraySequencePrepend OK" << std::endl;
    ArraySequenceInsertAt();
    std::cout << "ArraySequenceInsertAt OK" << std::endl;
    LL_SequenceGetFirst();
    std::cout << "LL_SequenceGetFirst OK" << std::endl;
    LL_SequenceGetLast();
    std::cout << "LL_SequenceGetLast OK" << std::endl;
    LL_SequenceGet();
    std::cout << "LL_SequenceGet OK" << std::endl;
    LL_SequenceSet();
    std::cout << "LL_SequenceSet OK" << std::endl;
    LL_SequenceGetSubsequence();
    std::cout << "LL_SequenceGetSubsequence OK" << std::endl;
    LL_SequenceAppend();
    std::cout << "LL_SequenceAppend OK" << std::endl;
    LL_SequencePrepend();
    std::cout << "LL_SequencePrepend OK" << std::endl;
    return 0;
}