/*
   This program will demonstrate the selection sort algorithm.

   
*/

#include <bits/stdc++.h>
#include <cstdio>

void selection_sort(int arr[], int n) {
   int i, j, min_idx;
   for(i = 0; i < n - 1; i++) {
      min_idx = i;
      for(j = i + 1; j < n; j++) {
         if(arr[j] < arr[min_idx]) {
            min_idx = j;
         }
      }
      if(min_idx != i) {
         std::swap(arr[min_idx], arr[i]);
      }
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

   printf("[Selection Sort] Unsorted array: ");
   print_array(arr, N);

   selection_sort(arr, N);

   printf("\n[Selection Sort] Sorted array: ");
   print_array(arr, N);

   return 0;
}