/*
   This program will demonstrate the insertion sort algorithm.

   Time Complexity: O(N2)
   Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>
#include <cstdio>

void insertion_sort(int arr[], int n) {
   int i, j, key;
   for( i = 1; i < n; i++) {
      key = arr[i];
      j = i - 1;

      while(j >= 0 && arr[j] > key) {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = key;
   }
}

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

   printf("[Insertion Sort] Unsorted array: ");
   print_array(arr, N);

   insertion_sort(arr, N);

   printf("\n[Insertion Sort] Sorted array: ");
   print_array(arr, N);

   return 0;
}