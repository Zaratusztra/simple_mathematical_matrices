#include <iostream>
#include <cstdlib>
#include <ctime>

#include "matrices.h"

using zrts::Matrix;

int ** random_2d_array(int M, int N)
{
    int ** tab = new int*[M];
    for(int i = 0; i < M; i++)
    {
        tab[i] = new int[N];
        for(int j = 0; j < N; j++)
        {
            tab[i][j] = rand() % 10;
        }
    }
    return tab;
}

void read_array(int M, int N, int** arr)
{
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
            std::cout << arr[i][j] << ' ' << std::flush;
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::cout << "Test started." << std::endl;

    srand(time(NULL));

    int** tab = random_2d_array(2,3);
    Matrix<int> A = Matrix<int>(2,3,tab);
    delete [] tab; tab = nullptr;

    
    tab = random_2d_array(3,5);
    Matrix<int> B = Matrix<int>(3,5,tab);
    delete [] tab;

    Matrix<int> I = Matrix<int>(3,3,0);
    for(int i = 0; i < 3; i++)
        I.set_val(i,2-i,1);

    try{
        
        std::cout << "I=\n" << I.str_repr() << std::endl;
        std::cout << "A=\n" << A.str_repr() << std::endl;
        std::cout << "B=\n" << B.str_repr() << std::endl;

        std::cout << "A*B=\n" << (A*B).str_repr() << std::endl;
        
    }catch(char const* err_str)
    {
        std::cerr << err_str << std::endl;
    }
    

    delete [] tab;
    std::cout << "Test finished." << std::endl;
    return 0;
}