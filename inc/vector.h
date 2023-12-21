//
// Created by Keny Geovany Chin Parra on 18/12/21.
//

#ifndef NMLIB_VECTOR_H
#define NMLIB_VECTOR_H

template<typename T>
class nm_vector{
private:
    std::shared_ptr<T> m_data;
    size_t m_rows;
    size_t m_cols;
    size_t m_ranks;
    size_t m_size;
public:
    nm_vector();

};

template<typename T>
nm_vector<T>::nm_vector(){
    m_rows = 9;
    std::cout << m_rows << std::endl;
}

#endif //NMLIB_VECTOR_H
