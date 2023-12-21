//
// Created by Keny Chin Parra on 26/11/21
// Modified 15/12/2021 % cd Documents/Proyectos_CPP/nmlib/
//
#pragma once
//#include <assert.h>

#ifndef NMLIB_TENSOR_H
#define NMLIB_TENSOR_H

#include <memory>
//#include <string>

template<typename  T>
class tensor{
private:
    std::shared_ptr<T> m_data;
    size_t m_rows;
    size_t m_cols;
    size_t m_ranks;
    size_t m_size;

    tensor<T> sum(std::shared_ptr<T> a, std::shared_ptr<T> b);
    tensor<T> diff(std::shared_ptr<T> a, std::shared_ptr<T> b);
    tensor<T> mult(std::shared_ptr<T> a, std::shared_ptr<T> b);
    tensor<T> div(std::shared_ptr<T> a, std::shared_ptr<T> b);
public:
    tensor();
    tensor(std::shared_ptr<T> data, size_t ranks, size_t rows, size_t cols);
    tensor(const tensor &copy, const char * copying_mode);
    tensor(size_t ranks,size_t rows,size_t cols);
    tensor(size_t rows, size_t cols);
    ~tensor();

    std::shared_ptr<T> get_data();
    size_t get_ranks();
    size_t get_rows();
    size_t get_cols();
    size_t get_size();
    void print_data();
    void print_data(int data_init, int data_end);
    void print_ranks();
    void print_rows();
    void print_cols();
    void print_size();

    tensor<T> operator+(const tensor<T> &operand);
    tensor<T> operator-(const tensor<T> &operand);
    tensor<T> operator*(const tensor<T> &operand);
    tensor<T> operator/(const tensor<T> &operand);

    bool has_zero_entry();
};

/**
 * Constructores
 */

template<typename T>
tensor<T>::tensor(){
    m_ranks = m_rows = m_cols = m_size = 0;
}

template<typename T>
tensor<T>::tensor(std::shared_ptr<T> data, size_t ranks, size_t rows, size_t cols){
    m_ranks = ranks;
    m_rows = rows;
    m_cols = cols;
    m_size = ranks*rows*cols;
    m_data = std::shared_ptr<T>(new T [m_size]);
    for(size_t i=0;i<m_size;i++) m_data.get()[i] = data.get()[i];
}

template<typename T>
tensor<T>::tensor(const tensor &copy, const char * copying_mode){
    m_ranks = copy.m_ranks;
    m_rows = copy.m_rows;
    m_cols = copy.m_cols;
    m_size = copy.m_size;
    if(strcmp(copying_mode,"shallow")==0){
        m_data = copy.m_data; //shallow copy
    }
    else if(strcmp(copying_mode,"deep")==0){
        m_data = std::shared_ptr<T>(new T [m_size]);
        for(size_t i=0;i<m_size;i++) m_data.get()[i] = copy.m_data.get()[i];
    }
    else{
        std::cout << "Error: Invalid copying mode." << std::endl;
    }

}

template<typename T>
tensor<T>::tensor(size_t ranks, size_t rows, size_t cols){
    m_ranks = ranks;
    m_rows = rows;
    m_cols = cols;
    m_size = ranks*rows*cols;
    m_data = std::shared_ptr<T>(new T [m_size]);
}

template<typename T>
tensor<T>::tensor(size_t rows, size_t cols){
    m_ranks = 1;
    m_rows = rows;
    m_cols = cols;
    m_size = rows*cols;
    m_data = std::shared_ptr<T>(new T [m_size]);
}

/**
 * Funciones que devuelven los atributos de la clase.
 */

template<typename T>
size_t tensor<T>::get_ranks(){
    return m_ranks;
}

template<typename T>
size_t tensor<T>::get_rows(){
    return m_rows;
}

template<typename T>
size_t tensor<T>::get_cols(){
    return m_cols;
}

template<typename T>
size_t tensor<T>::get_size(){
    return m_size;
}

template<typename T>
std::shared_ptr<T> tensor<T>::get_data(){
    if(m_data == nullptr) std::cout << "Error: Null tensor: ";
    return m_data;
}

template<typename T>
void tensor<T>::print_data() {
    for(size_t i=0;i< m_size;i++){
        std::cout << m_data.get()[i] << ", " ;
    }
    std::cout << std::endl ;
}

template<typename T>
void tensor<T>::print_data(int data_init, int data_end) {
    if( (0 <= data_init)&&(data_end <= m_size) ){
        for(size_t i=data_init;i< data_end-1;i++){
            std::cout << m_data.get()[i] << ", " ;
        }
        if(data_init != data_end){
            std::cout << m_data.get()[data_end-1] ;
            std::cout << std::endl ;
        }
        else{
            std::cout << "empty" << std::endl ;
        }
    }
    else{
        std::cout << "Error: Valores fuera de rango. El rango es [0,size)." << std::endl;
    }

}

template<typename T>
void tensor<T>::print_ranks() {
    std::cout << m_ranks << std::endl;
}

template<typename T>
void tensor<T>::print_rows() {
    std::cout << m_rows << std::endl;
}

template<typename T>
void tensor<T>::print_cols() {
    std::cout << m_cols << std::endl;
}

template<typename T>
void tensor<T>::print_size() {
    std::cout << m_size << std::endl;
}

/**
 * Operaciones de Tensores.
 */

template<typename T>
tensor<T> tensor<T>::sum(std::shared_ptr<T> a, std::shared_ptr<T> b) {
    tensor<T> tensor(m_ranks,m_rows,m_cols);
    for(int i=0; i<m_size;i++) tensor.m_data.get()[i] = a.get()[i] + b.get()[i];
    return tensor;
}

template<typename T>
tensor<T> tensor<T>::diff(std::shared_ptr<T> a, std::shared_ptr<T> b) {
    tensor<T> tensor(m_ranks,m_rows,m_cols);
    for(int i=0; i<m_size;i++) tensor.m_data.get()[i] = a.get()[i] - b.get()[i];
    return tensor;
}

template<typename T>
tensor<T> tensor<T>::mult(std::shared_ptr<T> a, std::shared_ptr<T> b) {
    tensor<T> tensor(m_ranks,m_rows,m_cols);
    for(int i=0; i<m_size;i++) tensor.m_data.get()[i] = a.get()[i] * b.get()[i];
    return tensor;
}

template<typename T>
tensor<T> tensor<T>::div(std::shared_ptr<T> a, std::shared_ptr<T> b) {
    /** Verificar que b no tenga ningún denominador 0 */
    bool has_a_zero = false;
    for(size_t i=0;i<m_size;i++){
        if(m_data.get()[i] == 0){
            has_a_zero = true;
        }
    }
    assert(has_a_zero != true);
    /** */
    tensor<T> tensor(m_ranks,m_rows,m_cols);
    for(int i=0; i<m_size;i++) tensor.m_data.get()[i] = a.get()[i] / b.get()[i];
    return tensor;
}

template<typename  T>
tensor<T> tensor<T>::operator+(const tensor<T> &operand){
    auto a = sum(m_data,operand.m_data);
    return a;
}

template<typename  T>
tensor<T> tensor<T>::operator-(const tensor<T> &operand){
    auto a = diff(m_data,operand.m_data);
    return a;
}

template<typename  T>
tensor<T> tensor<T>::operator*(const tensor<T> &operand){
    auto a = mult(m_data,operand.m_data);
    return a;
}

template<typename  T>
tensor<T> tensor<T>::operator/(const tensor<T> &operand){
    auto a = div(m_data,operand.m_data);
    return a;
}

/**
 * Otras funciones
 */

template<typename T>
bool tensor<T>::has_zero_entry(){
    bool has_a_zero = false;
    for(size_t i=0;i<m_size;i++){
        if(m_data.get()[i] == 0){
            has_a_zero = true;
        }
    }
    return has_a_zero;
}

/**
 * Destructores
 */

template<typename T>
tensor<T>::~tensor(){}

#endif //NMLIB_TENSOR_H
