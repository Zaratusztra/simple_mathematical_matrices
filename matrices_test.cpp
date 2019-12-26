#include <iostream>
#include <cstdlib>
#include <ctime>

#include "matrices.h"

void set_column_with_random_integers(int M, int N; int** array)
{
    for(int i = 0; i < M; i++)
    {
        array[i] = new new int[N];
        for (int j = 0; j < N; j++)
            array[i][j]=rand % 100;
    }
}

int main(int argc, char *argv[])
{
    std::cout << "Test started." << std::endl;

    srand(time(NULL));
    int** array_A = new int[2];
    set_column_with_random_integers(2,3,array_A);
    int** array_B = new int[3];
    set_column_with_random_integers(3,4,array_B);
    int** array_C = new int[3];
    set_column_with_random_integers(3,4,array_C);
    

    Matrix<int> A = Matrix<int>(2, 3, array_A);
    Matrix<int> B = Matrix<int>(3, 4, array_B);
    Matrix<int> C = Matrix<int>(3, 4, array_C);
    try{
        std::cout << A.str_repr() << std::endl;
        std::cout << std::endl;
        std::cout << B.str_repr() << std::endl;
        std::cout << std::endl;
        std::cout << (B+C).str_repr() << std::endl;
        std::cout << std::endl;
        std::cout << (A*B).str_repr() << std::endl;
    }catch(char* errstr){
        std::cerr << errstr << std::endl;
    }
    
    delete [] array_A;
    delete [] array_B;
    delete [] array_C;
    std::cout << "Test finished." << std::endl;
    return 0;
}