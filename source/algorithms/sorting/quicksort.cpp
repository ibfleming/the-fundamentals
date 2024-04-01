/*
   This program will demonstrate the quick sort algorithm.
   
   Time Complexity: O(N log N)
   Auxiliary Space: ?
*/

#include <bits/stdc++.h>
#include <cstdio>

int partition(int arr[], int low, int high) {
   int pivot = arr[high];
   int i = low - 1;
   for( int j = low; j <= high; j++ ) {
      if( arr[j] < pivot ) {
         i++;
         std::swap(arr[i], arr[j]);
      }
   }
   std::swap(arr[i+1], arr[high]);
   return i + 1;
}

void quick_sort(int arr[], int low, int high) {
   if( low < high ) {
      int pi = partition(arr, low, high);
      quick_sort(arr, low, pi - 1);
      quick_sort(arr, pi + 1, high);
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

   printf("[Quick Sort] Unsorted array: ");
   print_array(arr, N);

   quick_sort(arr, 0, N-1);

   printf("\n[Quick Sort] Sorted array: ");
   print_array(arr, N);

   return 0;
}