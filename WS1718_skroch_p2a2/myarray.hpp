/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   myarray.hpp
 * Author: max
 *
 * Created on 23. Oktober 2017, 16:33
 */

#ifndef MYARRAY_HPP
#define MYARRAY_HPP

#include <initializer_list>
#include <stdexcept>
#include <iostream>

template<class T, int N> class myArray {
public:
    myArray();
    explicit myArray(T);
    myArray(const myArray&);
    myArray(std::initializer_list<T>);
    ~myArray();
    myArray& operator=(const myArray&);
    T& operator[](int);
    const T& operator[](int) const;
    T& at(int);
    const T& at(int) const;
    T* dataPtr(int);
    int size() const;
    void fill(myArray<T, N>&, const T&);
    void printAll() const;
private:
    T elem[N];
};

template<class T, int N>
myArray<T, N>::myArray() { //Standardkonstruktor

}

template<class T, int N>
myArray<T, N>::myArray(T t) {
    for (size_t i{}; i < N; ++i) {
        elem[i] = t;
    }
}

template<class T, int N>
myArray<T, N>::myArray(const myArray& x) {
    *this = x;
}

template<class T, int N>
myArray<T, N>::myArray(std::initializer_list<T> in) {
    std::copy(in.begin(), in.end(), elem);
}

template<class T, int N>
myArray<T, N>::~myArray() {

}

template<class T, int N>
myArray<T, N>& myArray<T, N>::operator=(const myArray<T, N>& x) {
    for (size_t i{}; i < N; ++i) {
        elem[i] = x.elem[i];
        return *this;
    }
}

template<class T, int N>
T& myArray<T, N>::operator [](int n){
    return elem[n];
}

template<class T, int N>
const T& myArray<T, N>::operator [](int n) const{
    return elem[n];
}

template<class T, int N>
T& myArray<T, N>::at(int n) {
    if (n < 0 || N <= n) {
        throw std::out_of_range{"bad index"};
    }
    return elem[n];
}

template<class T, int N>
const T& myArray<T, N>::at(int n) const {
    if (n < 0 || N <= n) {
        throw std::out_of_range{"bad index"};
    }
    return elem[n];
}

template<class T, int N>
T* myArray<T, N>::dataPtr(int n) {
    return &(elem[n]);
}

template<class T, int N>
int myArray<T, N>::size() const {
    return N;
}

template<class T, int N>
void myArray<T, N>::fill(myArray<T, N>& r, const T& val) {
    for (size_t i{}; i < N; ++i) {
        r[i] = val;
    }
}

template<class T, int N>
void myArray<T, N>::printAll() const {
    for (size_t i{}; i < N; ++i) {
        std::cout << elem[i] << std::endl;
    }
}
#endif /* MYARRAY_HPP */

