/*
   This program will demonstrate how to do matrix multiplication.
*/

#include <bits/stdc++.h>
#include <cmath>
#define N_ROWS_COLS 2
#define vi std::vector<int>
#define vii std::vector<vi>

// Naive Method, O(N^3)
void naive_matrix_mult(int A[][N_ROWS_COLS], int B[][N_ROWS_COLS], int C[][N_ROWS_COLS]) {
   for( int i = 0; i < N_ROWS_COLS; i++ ) {
      for( int j = 0; j < N_ROWS_COLS; j++ ) {
         C[i][j] = 0;
         for( int k = 0; k < N_ROWS_COLS; k++ ) {
            C[i][j] += A[i][k] * B[k][j];
         }
      }
   }
}

// Divide and Conquer Method, O(N^3)

int next_power_of_2(int n) {
   return pow(2, int(ceil(log2(n))));
}

void display_matrix(vii matrix, int m, int n) {
   for(int i = 0; i < m; i++) {
      std::cout << "|"
                << " ";
      for(int j = 0; j < n; j++) {
         std::cout << matrix[i][j] << " ";
      }
      std::cout << "|" << std::endl;
   }
}

void add_matrices(vii &A, vii &B, vii &C, int size) {
   for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
         C[i][j] = A[i][j] + B[i][j];
      }
   }
}

void subtract_matrices(vii &A, vii &B, vii &C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// ---------------------------------------------------------------------

void strassen_algorithm(vii &A, vii &B, vii&C, int size) {
   if(size == 1) {
      C[0][0] = A[0][0] * B[0][0];
      return;
   }
   else {

      int new_size = size / 2;
      vi z(new_size);
      vii a(new_size, z), b(new_size, z), c(new_size, z), d(new_size, z),
          e(new_size, z), f(new_size, z), g(new_size, z), h(new_size, z),
          c11(new_size, z), c12(new_size, z), c21(new_size, z), c22(new_size, z),
          p1(new_size, z), p2(new_size, z), p3(new_size, z), p4(new_size, z),
          p5(new_size, z), p6(new_size, z), p7(new_size, z), fResult(new_size, z),
          sResult(new_size, z);
      size_t i, j;
      
      for( i = 0; i < new_size; i++ ) {
         for( j = 0; j < new_size; j++ ) {
            a[i][j] = A[i][j];
            b[i][j] = A[i][j + new_size];
            c[i][j] = A[i + new_size][j];
            d[i][j] = A[i + new_size][j + new_size];

            e[i][j] = B[i][j];
            f[i][j] = B[i][j + new_size];
            g[i][j] = B[i + new_size][j];
            h[i][j] = B[i + new_size][j + new_size];            
         }
      }

      /*
            A         B           C
         [a b]  *  [e f]  =  [c11 c12]
         [c d]     [g h]     [c21 c22]
         p1,p2,p3,p4 = AHED for this: A:Row(+) and B:Column(-)
         p5 = Diagonal :both +ve
         p6 = Last CR  :A:Row(-) B:Column(+)
         p7 = First CR :A:Row(-) B:Column(+)
      */

      // Calculating all Strassen formulas
      // p1 = (f - h) * a
      subtract_matrices(f, h, sResult, new_size);
      strassen_algorithm(a, sResult, p1, new_size);

      // p2 = (a + b) * h
      add_matrices(a, b, fResult, new_size);
      strassen_algorithm(fResult, h, p2, new_size);

      // p3 = (c + d) * e
      add_matrices(c, d, fResult, new_size);
      strassen_algorithm(fResult, e, p3, new_size);

      // p4 = (g - e) * d
      subtract_matrices(g, e, sResult, new_size);
      strassen_algorithm(d, sResult, p4, new_size);

      // p5 = (a + d) * (e + h)
      add_matrices(a, d, fResult, new_size);
      add_matrices(e, h, sResult, new_size);
      strassen_algorithm(fResult, sResult, p5, new_size);

      // p6 = (b - d) * (g + h)
      subtract_matrices(b, d, fResult, new_size);
      add_matrices(g, h, sResult, new_size);
      strassen_algorithm(fResult, sResult, p6, new_size);

      // p7 = (a - c) * (e + f)
      subtract_matrices(a, c, fResult, new_size);
      add_matrices(e, f, sResult, new_size);
      strassen_algorithm(fResult, sResult, p7, new_size);
        
      /* 
      Calculating all elements of C by p1,p2,p3:
      c11 = p4 + p5 + p6 - p2
      c12 = p1 + p2
      c21 = p3 + p4
      c22 = p1 - p3 + p5- p7
      */

      add_matrices(p1, p2, c12, new_size);
      add_matrices(p3, p4, c21, new_size);

      add_matrices(p4, p5, fResult, new_size);
      add_matrices(fResult, p6, sResult, new_size);
      subtract_matrices(sResult, p2, c11, new_size);

      subtract_matrices(p1, p3, fResult, new_size);
      add_matrices(fResult, p5, sResult, new_size);
      subtract_matrices(sResult, p7, c22, new_size);

      // Group the results obtained in a single matrix
      for( i = 0; i < new_size; i++ ) {
         for( j = 0; j < new_size; j++ ) {
            C[i][j] = c11[i][j];
            C[i][j + new_size] = c12[i][j];
            C[i + new_size][j] = c21[i][j];
            C[i + new_size][j + new_size] = c22[i][j];
         }
      }
   }
}

// For converting matrix to square matrix
void convert_to_square_matrix(vii &A, vii &B, int r1, int c1, int r2, int c2) {
   int max_size = std::max({r1, c1, r2, c2});
   int size = next_power_of_2(max_size);

   vi z(size);
   vii Aa(size, z), Bb(size, z), Cc(size, z);

   for (size_t i = 0; i < r1; i++)
   {
      for (size_t j = 0; j < c1; j++)
      {
         Aa[i][j] = A[i][j];
      }
   }
   for (size_t i = 0; i < r2; i++)
   {
      for (size_t j = 0; j < c2; j++)
      {
         Bb[i][j] = B[i][j];
      }
   }

   strassen_algorithm(Aa, Bb, Cc, size);
   vi temp1(c2);
   vii C(r1, temp1);
   for (size_t i = 0; i < r1; i++) {
      for (size_t j = 0; j < c2; j++) {
         C[i][j] = Cc[i][j];
      }
   }
   display_matrix(C, r1, c2);
}

int main(void) {
   vii a = {
      {1, 2, 3},
      {1, 2, 3},
      {0, 0, 2}
   };
   vii b = {
      {1, 0, 0},
      {0, 1, 0},
      {0, 0, 1}
   };
   convert_to_square_matrix(a, b, 3, 3, 3, 3);
   return 0;
}