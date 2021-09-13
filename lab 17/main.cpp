#include "matrix.hpp"
#include "point.hpp"
#include <cstdio>
#include <iostream>
using namespace std;

int main()
 {
     int n;
     cout<<"enter the size of matrix: ";
     cin>>n;
    
     try {
         Matrix<int> a (n,n);
         Matrix<int> b (n,n);
         Matrix<int> c (n,n);
         cout<<a.columns(a)<<"\n";
         cout<<a.rows(a)<<"\n";
         a.fill_matrix(a);
         cout<<"\nMatrix a:\n";
         a.print();
         b.fill_matrix(b);
         cout<<"\nMatrix b:\n";
         b.print();
         c = a.sum(b);
         cout<<"\nSum matrix is:\n";
         c.print();
         Point d(1,1,1);
         Point v(2,2,2);
         Matrix <Point> e(n,n);
         Matrix <Point> f(n,n);
         Matrix <Point> k(n,n);
         e.set_line(d,0);
         e.set_line(d,1);
         e.set_line(d,2);
         cout<<"\nMatrix e:\n";
         e.print();
         f.set_line(v,0);
         f.set_line(v,1);
         f.set_line(v,2);
         cout<<"\nMatrix f:\n";
         f.print();
         k = e.sum(f);
         cout<<"\nSum matrix is:\n";
         k.print();
     }
     catch (const char *str ) {
         cout<<str;
     }
     return 0;
 }
