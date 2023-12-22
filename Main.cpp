
#include <iostream>
#include "Vector.h"
#include "Matrix.h"


int main()
{
    try {
        std::cout << "----------------------------------\n";
        std::cout << "testing of vectors`s method\n";
        Vector v1(5);
        Vector v2(5, 7);
        Vector v3(v2);
        std::cout << "constructing of vector v1=[" << v1 << "]\n";
        std::cout << "constructing of vector with values v2=[" << v2 << "]\n";
        std::cout << "constructing of vector with using of previous vector v3=[" << v3 << "]\n";
        v1 = v2;
        std::cout << "operation v1=v2  new value of v1 [" << v1 << "]\n";
        v1 += v2;
        std::cout << "operation v1+=v2  new value of v1 [" << v1 << "]\n";
        v1 -= v2;
        std::cout << "operation v1-=v2  new value of v1 [" << v1 << "]\n";
        v1++;
        std::cout << "operation v1++  new value of v1 [" << v1 << "]\n";
        v1--;
        std::cout << "operation v1--  new value of v1 [" << v1 << "]\n";
        v3 = v1 + v2;
        std::cout << "operation v3=v1+v2  new value of v3 [" << v3 << "]\n";
        v3 = v1 - v2;
        std::cout << "operation v3=v1-v2  new value of v3 [" << v3 << "]\n";
        std::cout << "v1 = " << v1 << "\n";
        v1 = v1 * 5;
        std::cout << "operation v1=v1*5  new value of v1 [" << v1 << "]\n";
        v1 = 3 * v1;
        std::cout << "operation v1=3*v1  new value of v1 [" << v1 << "]\n";
        double value = v1 * v2;
        std::cout << "operation value=v1*v2  value = " << value << "\n";
        v1[0] = 1;
        std::cout << "operation v1[0]=1  new value of v1 [" << v1 << "]\n";
        std::cout << "enter size of new vector\n";
        size_t s;
        std::cin >> s;
        Vector v4(s);
        std::cout << "operation >> with v4 enter numbers\n";
        std::cin >> v4;
        std::cout << "v4= [" << v4 << "]\n";
        std::cout << "len of v4 = " << v4.lenght() << "\n";
        std::cout << "capacity of v4 = " << v4.capacity() << "\n";
        std::cout << "----------------------------------\n";
    }
    catch (std::exception exception) {
        std::cout << "an exception was called \nits description:\n" << exception.what() << "\n";
    }
    try {
        std::cout << "testing of matrix method\n";
        double** matr = new double* [5];
        for (int i = 0; i < 5; ++i) {
            matr[i] = new double[5];
            for (int j = 0; j < 5; ++j) {
                matr[i][j] = 0;
            }
        }
        matr[0][1] = 3;
        matr[2][2] = 5;
        matr[4][3] = 2;
        matr[4][4] = 1;


        CSRMatrix m1(matr, 5);
        std::cout << "constrcuitng of CSRMatrix m1\n";
        std::cout << m1;

        CSRMatrix m2(m1);
        std::cout << "\ncopy constrcuitng of CSRMatrix m2\n";
        std::cout << m2;

        CSRMatrix m3 = m2;
        std::cout << "\noperation = with matrix \n m3 = m2 \n m3:\n" << m3;

        m3 = m3 * 2;
        std::cout << "\noperation = with matrix and number \n m3 = m3*2 \n m3:\n" << m3;

        m3 = 3 * m3;
        std::cout << "\noperation = with number and matrix \n m3 = 3*m3 \n m3:\n" << m3;
        Vector v1(5, 3);
        std::cout << "\n\nv1=" << v1;
        std::cout << "\nm1:" << m1;
        Vector c = m1 * v1;
        std::cout << "\nm1*v1=" << c;


        std::cout << "\noperation >> with matrix\n std::cin >> m3 \n";
        std::cin >> m3;
        std::cout << "\nm3:" << m3;

        std::cout << "\nmethod get_amount_of_values with m3\n" << m3.get_amount_of_values();
        std::cout << "\nmethod get_amount_of_rows with m3\n" << m3.get_amount_of_rows();
        std::cout << "\nmethod get_capacity with m3\n" << m3.get_capacity();
        double c1 = 5, c2 = -0.5, c3 = 13;
        Vector v2(v1 * 5), v3(5, 2);
        auto res = -c1 * m1 * (v1 - c2 * v2) + v3 * c3;
        std::cout << "\ncomplex expressions\n" << "Vector res = - c1 * m1 * (v1 - c2 * v2) + v3 * c3\n";
        std::cout << "\nres = [ " << res << "]";
    }
    catch (std::exception exception) {
        std::cout << "an exception was called \nits description:\n" << exception.what() << "\n";
    }

    return 0;
}
