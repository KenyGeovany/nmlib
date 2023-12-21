//
// Created by Keny Geovany Chin Parra on 17/12/21.
// Modified 24/12/2021
//

#pragma once
//#include <assert.h>

#ifndef NMLIB_MATRIX_H
#define NMLIB_MATRIX_H

//#include <memory>
//#include <string>

template<typename T>
class nm_matrix{
private:
    std::shared_ptr<T> nm_data;
    size_t nm_rows;
    size_t nm_cols;
    size_t nm_size;

    nm_matrix<T> sum(std::shared_ptr<T> a, std::shared_ptr<T> b);
    nm_matrix<T> diff(std::shared_ptr<T> a, std::shared_ptr<T> b);
    nm_matrix<T> mult(std::shared_ptr<T> a, std::shared_ptr<T> b);
    nm_matrix<T> div(std::shared_ptr<T> a, std::shared_ptr<T> b);
public:
    nm_matrix();
    nm_matrix(size_t rows,size_t cols);
    nm_matrix(std::shared_ptr<T> data, size_t rows, size_t cols);
    nm_matrix(const nm_matrix &copy, const char * copying_mode);
    ~nm_matrix();

    std::shared_ptr<T> get_data();
    int get_rows();
    int get_cols();
    int get_size();

    void print_rows();
    void print_cols();
    void print_size();
    void print_data();
    void print_data(int from_row, int to_row, int from_col, int to_col);

    nm_matrix<T> operator+(const nm_matrix<T> &operand);
    nm_matrix<T> operator-(const nm_matrix<T> &operand);
    nm_matrix<T> operator*(const nm_matrix<T> &operand);
    nm_matrix<T> operator/(const nm_matrix<T> &operand);
};

/**
 * Constructors
 */

template<typename T>
nm_matrix<T>::nm_matrix(){
    nm_rows = nm_cols = nm_size = 0;
    nm_data = nullptr;
}

template<typename T>
nm_matrix<T>::nm_matrix(size_t rows, size_t cols){
    /*0 < rows,cols*/
    nm_rows = rows;
    nm_cols = cols;
    nm_size = rows * cols;
    nm_data = std::shared_ptr<T>(new T [nm_size]);
    for(int i=0;i<nm_size;i++) nm_data.get()[i] = 0;

}

template<typename T>
nm_matrix<T>::nm_matrix(std::shared_ptr<T> data, size_t rows, size_t cols){
    nm_rows = rows;
    nm_cols = cols;
    nm_size = rows * cols;
    nm_data = std::shared_ptr<T>(new T [nm_size]);
    for(int i=0; i < nm_size; i++) nm_data.get()[i] = data.get()[i];
}

template<typename T>
nm_matrix<T>::nm_matrix(const nm_matrix &copy, const char * copying_mode){
    nm_rows = copy.nm_rows;
    nm_cols = copy.nm_cols;
    nm_size = copy.nm_size;
    if(strcmp(copying_mode,"shallow")==0){
        nm_data = copy.nm_data; //shallow copy
    }
    else if(strcmp(copying_mode,"deep")==0){
        nm_data = std::shared_ptr<T>(new T [nm_size]);
        for(int i=0; i < nm_size; i++) nm_data.get()[i] = copy.nm_data.get()[i];
    }
    else{
        std::cout << "Error: Invalid copying mode." << std::endl;
    }

}

template<typename T>
nm_matrix<T>::~nm_matrix() = default; /*??*/

/**
 * Functions that get the class attributes.
 */

template<typename T>
int nm_matrix<T>::get_rows(){
    return nm_rows;
}

template<typename T>
int nm_matrix<T>::get_cols(){
    return nm_cols;
}

template<typename T>
int nm_matrix<T>::get_size(){
    return nm_size;
}

template<typename T>
std::shared_ptr<T> nm_matrix<T>::get_data(){
    if(nm_data == nullptr) std::cout << "Null matrix" << std::endl;
    return nm_data;
}

/**
 * Functions that print the class attributes.
 */

template<typename T>
void nm_matrix<T>::print_rows() {
    std::cout << nm_rows << std::endl;
}

template<typename T>
void nm_matrix<T>::print_cols() {
    std::cout << nm_cols << std::endl;
}

template<typename T>
void nm_matrix<T>::print_size() {
    std::cout << nm_size << std::endl;
}

template<typename T>
void nm_matrix<T>::print_data(){
    if(nm_data != nullptr){
        std::cout << std::endl;
        for (int i = 0; i < nm_rows; i++) {
            for (int j = 0; j < nm_cols - 1; j++) {
                std::cout << nm_data.get()[nm_cols * i + j] << ", ";
            }
            std::cout << nm_data.get()[nm_cols * (i + 1) - 1] << std::endl;
        }
    }
    else{
        std::cout << "NULL matrix" << std::endl; /*Warning: Null matrix*/
    }
}

template<typename T>
void nm_matrix<T>::print_data(int from_row, int to_row, int from_col, int to_col) {
    if((nm_data == nullptr)||(nm_rows <= 0)||(nm_cols <=0)||(nm_size <=0)){
        std::cout << "NULL matrix" << std::endl; /*Warning: Null matrix*/
    }
    else if( (1<=from_row)&&(from_row<=to_row)&&(to_row<=nm_rows)&&(1<=from_col)&&(from_col<=to_col)&&(to_col<=nm_cols) ){
        std::cout << std::endl;
        for(int i= (from_row-1);i<= (to_row-1);i++){
            for(int j = (from_col-1); j <= (to_col-2); j++){
                std::cout << nm_data.get()[nm_cols*i+j] << ", " ;
            }
            std::cout << nm_data.get()[nm_cols*(i+1)-(nm_cols-to_col+1)] << std::endl;
        }
    }
    else{
        //std::cout << "Warning: Values out of range." << std::endl; /*Warning: values out of range*/
        bool values_out_of_range = false; assert(values_out_of_range!=false); /*Error: values out of range*/
    }

}

/**
 * Matrix operations.
 */

template<typename T>
nm_matrix<T> nm_matrix<T>::sum(std::shared_ptr<T> a, std::shared_ptr<T> b) {
    nm_matrix<T> nm_matrix(nm_rows,nm_cols);
    for(int i=0; i<nm_size;i++) nm_matrix.nm_data.get()[i] = a.get()[i] + b.get()[i];
    return nm_matrix;
}

template<typename T>
nm_matrix<T> nm_matrix<T>::diff(std::shared_ptr<T> a, std::shared_ptr<T> b) {
    nm_matrix<T> nm_matrix(nm_rows,nm_cols);
    for(int i=0; i<nm_size;i++) nm_matrix.nm_data.get()[i] = a.get()[i] - b.get()[i];
    return nm_matrix;
}

template<typename T>
nm_matrix<T> nm_matrix<T>::mult(std::shared_ptr<T> a, std::shared_ptr<T> b) {
    nm_matrix<T> nm_matrix(nm_rows,nm_cols);
    for(int i=0; i<nm_size;i++) nm_matrix.nm_data.get()[i] = a.get()[i] * b.get()[i];
    return nm_matrix;
}

template<typename T>
nm_matrix<T> nm_matrix<T>::div(std::shared_ptr<T> a, std::shared_ptr<T> b) {
    /** Verify that b doesn't have any component 0 */
    bool has_a_zero = false;
    for(int i=0;i<nm_size;i++){
        if(nm_data.get()[i] == 0){
            has_a_zero = true;
        }
    }
    assert(has_a_zero == false);
    /** */
    nm_matrix<T> nm_matrix(nm_rows,nm_cols);
    for(int i=0; i<nm_size;i++) nm_matrix.nm_data.get()[i] = a.get()[i] / b.get()[i];
    return nm_matrix;
}

template<typename  T>
nm_matrix<T> nm_matrix<T>::operator+(const nm_matrix<T> &operand){
    /*Error: size incompatibility*/
    if((nm_rows != operand.nm_rows)||(nm_cols != operand.nm_cols)||(nm_size != operand.nm_size)) {
        bool size_incompatibility = false; assert(size_incompatibility != false);
    }
    if (nm_data == nullptr) { nm_matrix<T> M; return M; } /*Warning: Null matrix*/
    /** */
    auto a=sum(nm_data, operand.nm_data);
    return a;
}

template<typename  T>
nm_matrix<T> nm_matrix<T>::operator-(const nm_matrix<T> &operand){
    /*Error: size incompatibility*/
    if((nm_rows != operand.nm_rows)||(nm_cols != operand.nm_cols)||(nm_size != operand.nm_size)) {
        bool size_incompatibility = false; assert(size_incompatibility != false);
    }
    if (nm_data == nullptr) { nm_matrix<T> M; return M; } /*Warning: Null matrix*/
    /** */
    auto a = diff(nm_data,operand.nm_data);
    return a;
}

template<typename  T>
nm_matrix<T> nm_matrix<T>::operator*(const nm_matrix<T> &operand){
    /*Error: size incompatibility*/
    if((nm_rows != operand.nm_rows)||(nm_cols != operand.nm_cols)||(nm_size != operand.nm_size)) {
        bool size_incompatibility = false; assert(size_incompatibility != false);
    }
    if (nm_data == nullptr) { nm_matrix<T> M; return M; } /*Warning: Null matrix*/
    /** */
    auto a = mult(nm_data,operand.nm_data);
    return a;
}

template<typename  T>
nm_matrix<T> nm_matrix<T>::operator/(const nm_matrix<T> &operand){
    /*Error: size incompatibility*/
    if((nm_rows != operand.nm_rows)||(nm_cols != operand.nm_cols)||(nm_size != operand.nm_size)) {
        bool size_incompatibility = false; assert(size_incompatibility != false);
    }
    if (nm_data == nullptr) { nm_matrix<T> M; return M; } /*Warning: Null matrix*/
    /** */
    auto a = div(nm_data,operand.nm_data);
    return a;
}

#endif //NMLIB_MATRIX_H
