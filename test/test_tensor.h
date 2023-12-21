//
// Created by Keny Geovany Chin Parra on 18/12/21.
//

#ifndef NMLIB_TEST_TENSOR_H
#define NMLIB_TEST_TENSOR_H

using namespace std;

void test_tensor(){
    /**
     * Maneras de inicializar un tensor.
     */

    size_t ranks = 30;
    size_t rows = 20;
    size_t cols = 18;

    auto t = std::shared_ptr<double>(new double [ranks*rows*cols]);
    for(size_t i=0;i<ranks*rows*cols;i++) t.get()[i] = (double)i;

    tensor<double> a;
    tensor<double> b(t,ranks,rows,cols);
    tensor<double> c1(ranks,rows,cols);
    tensor<double> c2(rows,cols);
    tensor<double> d1(b,"shallow");
    tensor<double> d2(b,"deep");

    cout << "Creamos un tensor pero sin inicializarlo, por lo que es el tensor nulo." << endl;
    cout << a.get_data().get() <<endl << endl;
    cout << "Inicializamos pasando los datos de otro vector y sus dimensiones." << endl;
    cout << b.get_data().get()[40]<< endl << endl;

    cout << "Shallow copy of an tensor." << endl;
    cout << "b[40]: " << b.get_data().get()[40] << endl;
    d1.get_data().get()[40] = 333;
    cout << "d1 <- b shallow" << endl;
    cout << "d1[40] <- 333" << endl;
    cout << "d1[40]: " << d1.get_data().get()[40] << endl;
    cout << "b[40]: " << b.get_data().get()[40] << endl << endl;

    /*Regresamos a la normalidad a b: */ b.get_data().get()[40]= 40;

    cout << "Deep copy of an tensor." << endl;
    cout << "b[40]: " << b.get_data().get()[40] << endl;
    cout << "d2[40]: " << d2.get_data().get()[40] << endl;
    d2.get_data().get()[40] = 333;
    cout << "d2 <- b deep" << endl;
    cout << "d2[40] <- 333" << endl;
    cout << "d2[40]: " << d2.get_data().get()[40] << endl;
    cout << "b[40]: " << b.get_data().get()[40] << endl << endl;

    cout << "Tensor inicializado con basura, usando 3 dimensiones." << endl;
    cout << "c1[40]: " << c1.get_data().get()[40] << endl << endl;

    cout << "Tensor inicializado con basura, usnado 2 dimensiones" << endl;
    cout << "c2[40]: " << c2.get_data().get()[40] << endl << endl;

    /**
     * Funciones que devuelven los atributos de una clase.
     */

    cout << "Obtenemos los atributos de b." << endl;
    cout << "b.get_ranks(): " << b.get_ranks() << endl;
    cout << "b.get_rows(): " << b.get_rows() << endl;
    cout << "b.get_cols(): " << b.get_cols() << endl;
    cout << "b.get_size(): " << b.get_size() << endl;
    cout << "b.get_data().get()[5]: " << b.get_data().get()[5] << endl ;
    b.print_ranks(); b.print_rows(); b.print_cols(); b.print_size();
    b.print_data(0,10);
    cout << endl;

    /**
     * Operaciones de Tensores.
     */

    cout << "Operamos b+b, b-b, b*b, b/b. Solo iprimimos los primeros 15 valores." << endl;
    //Tensor<double> suma_tens2 = b/b ;
    //suma_tens2.print_data(0,15);
    cout << "b+b = " ; (b+b).print_data(0,15);
    cout << "b-b = " ; (b-b).print_data(0,15);
    cout << "b*b = " ; (b*b).print_data(0,15);
    b.get_data().get()[0] = 5; /** Comentar esta linea para ver que hay error de división. */
    cout << "b/b = " ; (b/b).print_data(0,15);

    //b.get_data().get()[4] = 0;
    //cout << b.has_zero_entry() << endl;

    double * vector = NULL;
    vector = new double[7];
    for(int i=0;i<3;i++) cout << vector[i] << endl;
}

#endif //NMLIB_TEST_TENSOR_H
