#include <iostream>

#include "matrices.h"

int main(int argc, char *argv[])
{
    std::cout << "Test started." << std::endl;
    int** array_A = new int[2];
    {4,-1, 2};
    {-2,0,7};
    Matrix<int> A = Matrix<int>(2, 3, array_A);
    int** array_B = new int[3];
    {2,3,-1,5};
    {11,0,0,-3};
    {9,3,7,2};
    Matrix<int> B = Matrix<int>(3, 4, array_B);
    int** array_C = new int[3];
    {1,2,3,4};
    {0,1,0,1};
    {-4,-3,-2,-1};
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