/*
 * This is highly unprofessional implementation of mathematical matrix.
 * Work In Progress.
 *                  ~Ziemowit Wójcicki.
 */

#ifndef _zst_MATRICES_
#define _zst_MATRICES_

#include <string>

namespace zst{

template <typename DataType>
class Matrix
{
private:
    DataType** values;

    void create_values_array();
    void delete_values_array();
    void fill_values_array_with(DataType val);
public:
    const unsigned int size_m;
    const unsigned int size_n;
    Matrix();
    Matrix(unsigned int m, unsigned int n);
    Matrix(unsigned int m, unsigned int n, DataType v);
    Matrix(unsigned int m, unsigned int n, DataType **array);
    Matrix(const Matrix<DataType> &M); // A copy constructor
    ~Matrix();
    DataType get_val(unsigned int i, unsigned int j) const;
    void set_val(unsigned int i, unsigned int j, DataType new_val);
    std::string str_repr() const; // This is really stupid, I know. Only for learning purpouses :P
    DataType det();

    Matrix<DataType>& operator=(const Matrix<DataType>& M);
    template <typename Type>
    friend Matrix<DataType>& operator+(const Matrix<DataType>& A, const Matrix<DataType>& B);
    template <typename Type>
    friend Matrix<DataType> operator*(const Matrix<DataType>& A, const Matrix<DataType>& B);
};

template <typename DataType>
void Matrix<DataType>::create_values_array()
{
    values = new DataType* [size_m];
    for (unsigned i = 0; i < size_m; i++)
    {
        values[i]=new DataType[size_n];
    }
}

template <typename DataType>
void Matrix<DataType>::fill_values_array_with(DataType val)
{
    
    if(values != nullptr)
    {
        for (unsigned i = 0; i < size_m; i++)
            for(unsigned j = 0; j < size_n; j++)
            {
                values[i][j]=val;
            }
    }
}

template <typename DataType>
DataType Matrix<DataType>::get_val(unsigned int i, unsigned int j) const
{
    if(i < size_m && j < size_n)
    {
        return values[i][j];
    }
    else
    {
        throw "Matrix index out of scope!";
    }
}

template <typename DataType>
void Matrix<DataType>::set_val(unsigned int i, unsigned int j, DataType new_val)
{
    if(i < size_m && j < size_n)
    {
        values[i][j] = new_val;
    }
    else
    {
        throw "Matrix index out of scope!";
    }
}

template <typename DataType>
Matrix<DataType>::Matrix()
{
    size_m = 2;
    size_n = 2;
    create_values_array();
    fill_values_array_with(DataType(0));
}

template <typename DataType>
Matrix<DataType>::Matrix(unsigned int m, unsigned int n) : size_m(m), size_n(n)
{
    create_values_array();
    fill_values_array_with(DataType(0));
}

template <typename DataType>
Matrix<DataType>::Matrix(unsigned int m, unsigned int n, DataType v) : size_m(m), size_n(n)
{
    create_values_array();
    fill_values_array_with(v);
}

template <typename DataType>
Matrix<DataType>::Matrix(unsigned int m, unsigned int n, DataType **array) : size_m(m), size_n(n)
{
    create_values_array();
    for(unsigned int i = 0; i < size_m; i++)
        for(unsigned int j = 0; j < size_n; j++)
            values[i][j]=array[i][j];
}

template <typename DataType>
Matrix<DataType>::Matrix(const Matrix<DataType>& M) : size_m(M.size_m), size_n(M.size_n)
{
    create_values_array();
    for(unsigned int i = 0; i < size_m; i++)
        for(unsigned int j = 0; j < size_n; j++)
            values[i][j]=M.get_val(i,j);
}

template <typename DataType>
void Matrix<DataType>::delete_values_array()
{
    if(values != nullptr)
    {
        for (unsigned i = 0; i < size_m; i++)
        {
            delete [] values[i];
        }
        delete [] values;
    }

    //  if(values!=nullptr)
    //      delete [] values;
}

template <typename DataType>
Matrix<DataType>::~Matrix()
{
    delete_values_array();
}

template <typename DataType>
std::string Matrix<DataType>::str_repr() const
{
    if(values != nullptr)
    {
        std::string repr;
        for (unsigned i = 0; i < size_m; i++)
        {
            for(unsigned j = 0; j < size_n; j++)
            {
                std::string app = std::to_string(values[i][j]);
                repr.append(app);
                repr.append(" ");
            }
            repr.append("\n");
        }
        return repr;
    }
    else
    {
        throw "Error, matrix values array points to null.";
    }
}

template <typename DataType>
Matrix<DataType>& Matrix<DataType>::operator=(const Matrix<DataType>& M)
{
    for (unsigned i = 0; i < size_m; i++)
        for(unsigned j = 0; j < size_n; j++)
        {
            values[i][j]=M.get_val(i,j);
        }
    return *this;
}

template <typename Type>
Matrix<Type>& operator+(const Matrix<Type>& A, const Matrix<Type>& B)
{
    if(A.size_m != B.size_m || A.size_n != B.size_n )
    {
        throw "Incompatibile sizes of given matrices.";
    }
    else
    {
        Matrix<Type> *sum_matrix = new Matrix<Type>(A.size_m, A.size_n, 0);
        Type sum;
        for(unsigned int i = 0; i < A.size_m; i++)
        {
            for(unsigned int j = 0; j < A.size_n; j++)
            {
                sum = A.get_val(i,j)+B.get_val(i,j);
                sum_matrix->set_val(i,j,sum);
            }
        }
        return *sum_matrix;
    }
}

template <typename Type>
Matrix<Type>& operator*(Matrix<Type>& A, Matrix<Type>& B)
{
    /* 
    *  I will probably try to implement Volker Strassen's algorithm at some point. This will be fun... :P
    */
    if(A.size_n != B.size_m)
    {
        throw "Incompatibile sizes of given matrices.";
    }
    else
    {
        Matrix<Type>* result_matrix = new Matrix<Type>(A.size_m, B.size_n, 0);
        for(unsigned int row = 0; row < A.size_m; row++)
        {
            for(unsigned int column = 0; column < B.size_n; column++)
            {
                Type val = Type(0);
                for(unsigned int i = 0; i < A.size_n; i++)
                {
                    val += A.get_val(row, i)*B.get_val(i, column);
                }
                result_matrix->set_val(row, column, val);
            }
        }
        return *result_matrix;
    }
}

template <typename DataType>
DataType Matrix<DataType>::det()
{
    /* 
    *  Realistically I should implement some better algorithm here, but I will not.
    */
   throw "Function not implemented yet!";
   return DataType(-1);
}

} // zst

#endif