#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


class Matrix

{
    int rows;
    int cols;
    int** arr;
public:
    int get_rows()const
    {
        return rows;
    }
    int get_cols()const
    {
        return cols;
    }
    //Constructors

    Matrix(int rows = 2, int cols = 2)
    {
        this->rows = rows;
        this->cols = cols;
        this->arr = new int* [rows] {};
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols] {};
        }
        cout << "Constructor:\t" << this << endl;
    }
    Matrix(int n) :Matrix(1, n)
    {

    }
    Matrix(const Matrix& other) //:Matrix(other.rows, other.cols)
    {
        /*for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                this->arr[i][j] = other.arr[i][j];
            }
        }*/
        *this = other;
        cout << "CopyConstructor:\t" << this << endl;
    }
    Matrix(Matrix&& other)
    {
       /* *this = other;
        cout << "MoveConstructor:\t" << this << endl;
        arr = nullptr;
        rows = 0;
        cols = 0;*/
        *this = std::move(other);
    }
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[]arr[i];
        }
        delete[]arr;
        arr = nullptr;
        rows = 0;
        cols = 0;
        cout << "Destructor:\t" << this << endl;
    }

    //Operators

    Matrix& operator=(const Matrix& other)
    {
        if (this == &other)return *this;
        this->~Matrix();
        this->rows = other.rows;
        this->cols = other.cols;
        this->arr = new int* [rows] {};
        for (int i = 0; i < rows; i++)
        {
            this->arr[i] = new int[cols] {};
            memcpy(this->arr[i], other.arr[i], cols * sizeof(int));
        }
        cout << "CopyAssignment\t" << this << endl;
        return *this;
    }

    Matrix& operator=(Matrix&& other)
    {
        this->rows = other.rows;
        this->cols = other.cols;
        this->arr = other.arr;
        other.arr = nullptr;
        other.rows = 0;
        other.cols = 0;
        return *this;

    }

    const int* operator[](int i)const
    {
        return arr[i];
    }
    int* operator[](int i)
    {
        return arr[i];
    }

    //Methods

    void print()const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void fill()const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                arr[i][j] = rand() % 100;
            }
        }
    }

};

Matrix operator+(const Matrix& left, const Matrix& right)
{
    if ((left.get_cols() != right.get_cols()) || (left.get_rows() != right.get_rows()))
        return Matrix();
        //return cout<<"Matrix must have same number of cols and rows.";

    Matrix C(left.get_rows(), left.get_cols());

    for (int i = 0; i < left.get_rows(); i++)
    {
        for (int j = 0; j < left.get_cols(); j++)
        {
            C[i][j] = left[i][j] + right[i][j];
        }
    }
    return C;
}

void main()
{
    setlocale(LC_ALL, "Russian");
    Matrix A(3, 4);
    /*for (int i = 0; i < A.get_rows(); i++)
    {
        for (int j = 0; j < A.get_cols(); j++)
        {
            A[i][j] = rand() % 100;
        }
    }*/
    A.fill();
    A = A;
    A.print();

    Matrix B;
    B = A;
    B.print();
    Matrix C = A + B;
    C.print();

}