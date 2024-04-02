/*
   This program will demonstrate how to perform a binary search on an array.

   Average Case: O(log N)
   Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>

int binary_search(int arr[], int l, int r, int x) {
   while( l <= r ) {
      int m = l + (r - 1) / 2;

      if( arr[m] == x ) {
         return m;
      }

      if( arr[m] < x ) {
         l = m + 1;
      }
      else {
         r = m - 1;
      }
   }
   return -1;
}

int main(void) {
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   int x = 7;
   int N = sizeof(arr) / sizeof(arr[0]);
   int result = binary_search(arr, 0, N - 1, x);
   (result == -1)
      ? std::cout << "Element is not present in array."
      : std::cout << "Element is present at index " << result << "." << std::endl;
   return 0;
}