#include <iostream>

#include "matrices.h"

int main(int argc, char *argv[])
{
    std::cout << "Test started." << std::endl;
    Matrix<int> A = Matrix<int>(2,3,0);
    A.set_val(1,1,5);
    A.set_val(1,2,1);
    A.set_val(0,2,-1);
    Matrix<int> B = Matrix<int>(3,4,1);
    B.set_val(1,2,0);
    Matrix<int> C = Matrix<int>(3,4,-3);
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
    
    std::cout << "Test finished." << std::endl;
    return 0;
}