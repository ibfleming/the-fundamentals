/*
   This program will demonstrate the bubble sort algorithm.

   Time Complexity: O(N2)
   Auxiliary Space: O(1)

*/

#include <bits/stdc++.h>
#include <cstdio>

// ----------------------------------------------------------------------------
// Bubble sort algorithm

void bubble_sort(int arr[], int n) {
   int i, j;
   bool swap;
   for(i = 0; i < n - 1; i++) {
      swap = false;
      for(j = 0; j < n - i - 1; j++) {
         if(arr[j] > arr[j + 1]) {
            std::swap(arr[j], arr[j + 1]);
            swap = true;
         }
      }
      if(!swap) {
         break;
      }
   }
}

// ----------------------------------------------------------------------------

void print_array(int arr[], int size) {
   int i;
   for(i = 0; i < size; i++) {
      printf(" %d", arr[i]);
   }
   printf("\n");
}

int main() {

   int arr[] = {64, 34, 25, 12, 22, 11, 90, 1, 0, 100, 43};
   int N = sizeof(arr) / sizeof(arr[0]);

   printf("Unsorted array: ");
   print_array(arr, N);

   bubble_sort(arr, N);

   printf("\nSorted array: ");
   print_array(arr, N);

   return 0;
}
