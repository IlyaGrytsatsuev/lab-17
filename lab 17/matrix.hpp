
 #include "point.hpp"
 #include <cstdio>
 #include <iostream>
 using namespace std;

 template <typename T>
 class Matrix
 {
 private:
     size_t row;
     size_t column;
     T **matrix;

 public:
    Matrix<T>(size_t row1, size_t column1)
     {
         row = row1;
         column = column1;

         matrix = new T*[row];
         for (size_t i = 0;  i < row; i++)
             matrix[i] = new T[column];
     }

     ~Matrix<T>()
     {
          for (size_t i = 0; i < row; i++)
             delete [] matrix[i];
     }

     Matrix<T>(const Matrix & b)
     {
         row = b.row;
         column = b.column;

         matrix = new T*[row];
         for (size_t i = 0; i < row; i++)
             matrix[i] = new T[column];

         for(size_t i = 0; i < row; i++)
             for(size_t j = 0; j < column; j++)
                 matrix[i][j] = b.matrix[i][j];
     }

     size_t rows(const Matrix<T>& a) const
     {
         return row;
     }
     
     size_t columns(const Matrix<T>& a) const
     {
         return column;
     }

     void set(size_t row1, size_t column1, T value)
     {
         if((row1 >= row)||(column1 >= column))
             throw "\nError!!!! You are out of rande!!!!\n";
         matrix[row1][column1] = value;
     }
     
     void fill_matrix()
     {
        for(int i = 0; i < row; i++)
            for (int j = 0; j < column; j++){
                cout<<"enter "<<"("<<i<<";"<<j<<") : ";
                cin >> matrix[i][j];
              }
     }

     T get(size_t row1, size_t column1) const
     {
         if((row1 >= row)||(column1 >= column))
             throw "\nError!!!! You are out of rande!!!!\n";
         return matrix[row1][column1];
     }

     Matrix<T> & operator = (const Matrix & b)
     {
         if (this != &b)
         {
             row = b.row;
             column = b.column;

             for (size_t i = 0; i < row; i++)
                 delete [] matrix[i];

             matrix = new T*[row];
             for (size_t i = 0;  i < row; i++)
                 matrix[i] = new T[column];

             for (size_t i = 0; i < row; i++)
                 for (size_t j = 0; j < column; j++)
                     matrix[i][j] = b.matrix[i][j];
         }
         return *this;
     }


     Matrix<T> sum(const Matrix &b)
     {
         Matrix <T>result(row,column);
         if ((row != b.row)||(column != b.column))
                 throw "\nError!!!You can sum only the same size matrix!!\n";

         for (size_t i = 0; i < row; i++)
             for(size_t j = 0; j < column; j++)
                 result.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
         return result;
     }

     
     void set_line(T value, size_t number)
     {
         if (number >= row)
             throw "\nError!!!! There is no such string\n";
         for(int i = 0; i < column; i++)
             matrix[number][i] = value;
     }

     void print() const
     {
         for (size_t i = 0; i < row; i++)
         {
             for (size_t j = 0; j < column; j++)
                 cout << matrix[i][j]<< " ";
             cout << endl;
         }
     }
     
     T* & operator [](const int &index) const  
     {
       return  matrix [index];
     }
     
 };
