/*
   This program will demonstrate the heap sort algorithm.

   Time Complexity: O(N log N)
   Auxiliary Space: O(log n)
*/

#include <bits/stdc++.h>
#include <cstdio>

void heapify(int arr[], int N, int i) {
   int largest = i;
   int left = 2 * i + 1;
   int right = 2 * i + 2;

   if(left < N && arr[left] > arr[largest]) {
      largest = left;
   }

   if(right < N && arr[right] > arr[largest]) {
      largest = right;
   }

   if(largest != i) {
      std::swap(arr[i], arr[largest]);
      heapify(arr, N, largest);
   }
}

void heap_sort(int arr[], int N) {
   for(int i = N / 2 - 1; i >= 0; i--) {
      heapify(arr, N, i);
   }

   for(int i = N - 1; i > 0; i--) {
      std::swap(arr[0], arr[i]);
      heapify(arr, i, 0);
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

   printf("[Heap Sort] Unsorted array: ");
   print_array(arr, N);

   heap_sort(arr, N);

   printf("\n[Heap Sort] Sorted array: ");
   print_array(arr, N);

   return 0;
}