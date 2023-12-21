//
// Created by Keny Geovany Chin Parra on 18/12/21.
// Modified 22/12/21, 24/12/21
//

#ifndef NMLIB_TEST_MATRIX_H
#define NMLIB_TEST_MATRIX_H

void test_matrix(){
    /**
     * Parameters
     */
    size_t rows = 3;
    size_t cols = 4;
    size_t size = rows*cols;
    auto t = std::shared_ptr<double>(new double [size]);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            t.get()[cols*i+j] = i+j; /*Casting (double)*/
        }
    }

    int a,b,c; std::shared_ptr<double> d;
    /**
     * Ways to initialize a matrix.
     */
    cout << "-------------------------------------------------------" << endl;
    cout << "Test constructors" << endl << endl;

    cout << "TEST: nm_matrix()" << endl;
    nm_matrix<double> M1; /*Null matrix: data = NULL, rows = 0, cols = 0 */
    cout << endl;

    cout << "TEST: nm_matrix(rows,cols)" << endl;
    nm_matrix<double> M2(rows,cols); /*Zero matrix: data = (0,..,0)*/
    cout << endl;

    cout << "TEST: nm_matrix(t,rows,cols)" << endl;
    nm_matrix<double> M3(t,rows,cols); /*Initialized matrix*/
    cout << endl;

    cout << "TEST: nm_matrix(M,Deep)" << endl;
    nm_matrix<double> M3_copy_D(M3,"deep"); /*Deep copy*/
    cout << "Before: " << M3.get_data().get()[cols*1+2] << ", ";
    cout << M3_copy_D.get_data().get()[cols*1+2] << ". ";
    M3_copy_D.get_data().get()[cols*1+2] = 7;
    cout << "After: " << M3.get_data().get()[cols*1+2] << ", ";
    cout << M3_copy_D.get_data().get()[cols*1+2] << endl << endl;

    cout << "TEST: nm_matrix(M,Shallow)" << endl;
    nm_matrix<double> M3_copy_S(M3,"shallow"); /*Shallow copy*/
    cout << "Before: " << M3.get_data().get()[cols*1+2] << ", ";
    cout << M3_copy_S.get_data().get()[cols*1+2] << ". ";
    M3_copy_S.get_data().get()[cols*1+2] = 7;
    cout << "After: " << M3.get_data().get()[cols*1+2] << ", ";
    cout << M3_copy_S.get_data().get()[cols*1+2] << endl <<  endl;

    /**
     * Get class attributes
     */
    cout << "-------------------------------------------------------" << endl;
    cout << "Test get class attributes" << endl << endl;
    cout << "TEST: M1.get_rows(), M1.get_cols(), M1.get_size(), M1.get_data()" << endl;
    a = M1.get_rows(); b =M1.get_cols(); c = M1.get_size(); d = M1.get_data();
    cout << "rows: " << a << ", cols: " << b << ", size: " << c << ", data = [ " ;
    for(int i=0;i<c;i++) cout << d.get()[i] << ", " ; cout << "]" << endl << endl;

    cout << "TEST: M1.get_rows(), M1.get_cols(), M1.get_size(), M1.get_data()" << endl;
    a = M2.get_rows(); b =M2.get_cols(); c = M2.get_size(); d = M2.get_data();
    cout << "rows: " << a << ", cols: " << b << ", size: " << c << ", data = [ " ;
    for(int i=0;i<c;i++) cout << d.get()[i] << " " ; cout << "]" << endl << endl;

    cout << "TEST: M1.get_rows(), M1.get_cols(), M1.get_size(), M1.get_data()" << endl;
    a = M3.get_rows(); b =M3.get_cols(); c = M3.get_size(); d = M3.get_data();
    cout << "rows: " << a << ", cols: " << b << ", size: " << c << ", data = [ " ;
    for(int i=0;i<c;i++) cout << d.get()[i] << " " ; cout << "]" << endl << endl;

    /**
     * Print class attributes
     */
    cout << "-------------------------------------------------------" << endl;
    cout << "Test print class attributes" << endl << endl;

    cout << "TEST: M1.print_rows(), M1.print_cols(), M1.print_size()" << endl;
    M1.print_rows(); M1.print_cols(); M1.print_size();

    cout << "TEST: M1.print_data()" << endl;
    M1.print_data();
    cout << "TEST: M1.print_data(2,3,2,3)" << endl;
    M1.print_data(2,3,2,3);
    cout << endl;

    cout << "TEST: M2.print_rows(), M2.print_cols(), M2.print_size()" << endl;
    M2.print_rows(); M2.print_cols(); M2.print_size();

    cout << "TEST: M2.print_data()" ;
    M2.print_data();
    cout << "TEST: M2.print_data(2,3,2,3)" ;
    M2.print_data(2,3,2,3);
    cout << endl;

    cout << "TEST: M3.print_rows(), M3.print_cols(), M3.print_size()" << endl;
    M3.print_rows(); M3.print_cols(); M3.print_size();

    cout << "TEST: M3.print_data()" ;
    M3.print_data();
    cout << "TEST: M3.print_data(2,3,2,3)" ;
    M3.print_data(2,3,2,3);
    cout << endl;

    cout << "TEST: assertions and warnings" << endl;
    M1.print_data(2,3,2,-7); /*Warning: Null matrix*/
    //M3.print_data(2,3,2,-7); /*Uncomment to see error: values out of range*/
    cout << endl;

    /**
     * Overloading of basic operations
     */
    cout << "-------------------------------------------------------" << endl;
    cout << "Test matrix operations" << endl << endl;

    cout << "Operate M1+M1, M1-M1, M1*M1, M1/M1." << endl;
    cout << "M1+M1 = " ; (M1+M1).print_data();
    cout << "M1-M1 = " ; (M1-M1).print_data();
    cout << "M1*M1 = " ; (M1*M1).print_data();
    cout << "M1/M1 = " ; (M1/M1).print_data(); /** Uncomment this line to see a division error. */
    cout << endl;

    cout << "Operate M2+M2, M2-M2, M2*M2, M2/M2." << endl;
    cout << "M2+M2 = " ; (M2+M2).print_data();
    cout << "M2-M2 = " ; (M2-M2).print_data();
    cout << "M2*M2 = " ; (M2*M2).print_data();
    //cout << "M2/M2 = " ; (M2/M2).print_data(); /** Uncomment this line to see a division error. */
    cout << endl;

    cout << "Operate M3+M3, M3-M3, M3*M3, M3/M3." << endl;
    cout << "M3+M3 = " ; (M3+M3).print_data();
    cout << "M3-M3 = " ; (M3-M3).print_data();
    cout << "M3*M3 = " ; (M3*M3).print_data();
    M3.get_data().get()[0] = 5; /** Comment this line to see a division error. */
    cout << "M3/M3 = " ; (M3/M3).print_data();
    cout << endl;

    cout << "TEST: assertions and warnings" << endl;
    nm_matrix<double> M_size_null;
    nm_matrix<double> M_size_4x5(4,5);
    nm_matrix<double> M_size_4x3(4,3);
    //(M_size_4x5+M_size_4x3).print_data(); /** Uncomment this line to see a size incompatibility. */
    //(M_size_null + M_size_4x3).print_data(); /** Uncomment this line to see a size incompatibility. */
    cout << endl;

}

#endif //NMLIB_TEST_MATRIX_H
