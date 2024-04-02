/*
   This program will demonstrate the Z algorithm for pattern searching.

   Average Time Complexity: O(n + m)
*/

#include <bits/stdc++.h>

void get_z_array(std::string str, int Z[]);

void z_search(std::string text, std::string pattern) {
   std::string concat = pattern + "$" + text;
   int l = concat.length();

   int Z[l];
   get_z_array(concat, Z);

   for (int i = 0; i < l; ++i)
   {
      if (Z[i] == pattern.length())
         std::cout << "Pattern found at index " << i - pattern.length() - 1 << std::endl;
   }
}

void get_z_array(std::string str, int Z[]) {
   int n = str.length();
   int L, R, k;

   L = R = 0;
   for( int i = 1; i < n; ++i) {
      if( i > R ) {
         L = R = i;

         while( R < n && str[R - L] == str[R] )
            R++;
         Z[i] = R - L;
         R--;
      } else {
         k = i - L;

         if( Z[k] < R - i + 1 )
            Z[i] = Z[k];
         else {
            L = i;
            while( R < n && str[R - L] == str[R] )
               R++;
            Z[i] = R - L;
            R--;
         }
      }
   }
}

int main() {
   std::string text = "GEEKS FOR GEEKS";
   std::string pattern = "GEEK";
   z_search(text, pattern);
   return 0;
}



