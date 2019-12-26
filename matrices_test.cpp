#include <iostream>
#include <cstdlib>
#include <ctime>

#include "matrices.h"

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

    
    tab = random_2d_array(4,2);
    Matrix<int> B = Matrix<int>(4,2,tab);
    delete [] tab;

    std::cout << "A=\n" << A.str_repr() << std::endl;
    std::cout << "B=\n" << B.str_repr() << std::endl;
    try{
        std::cout << "A*B=\n" << (A*B).str_repr() << std::endl;
    }catch(char const* err_str)
    {
        std::cerr << err_str << std::endl;
    }
    

    delete [] tab;    
    std::cout << "Test finished." << std::endl;
    return 0;
}