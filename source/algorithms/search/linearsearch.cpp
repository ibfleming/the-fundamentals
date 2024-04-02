/*
   This program demonstrates how to perform a linear search on an array. 

   Average Case: O(N)
   Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>

int linear_search(int arr[], int N, int x) {
   for(int i = 0; i < N; i++) {
      if( arr[i] == x ) {
         return i;
      }
   }
   return -1;
}

int main(void) {
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   int x = 4;
   int N = sizeof(arr) / sizeof(arr[0]);

   int result = linear_search(arr, N, x);
   (result == -1)
      ? std::cout << "Element is not present in array."
      : std::cout << "Element is present at index " << result << "." << std::endl;
   return 0;
}