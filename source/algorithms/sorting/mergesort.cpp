/*
   This program will demonstrate the merge sort algorithm.
   Average Case: O(N log N)
   Space Complexity: O(N)
*/


#include <bits/stdc++.h>
using namespace std;

void merge(int array[], const int left, const int mid, int const right) {

   const int sub_array_one = mid - left + 1;
   const int sub_array_two = right - mid;

   auto *left_array  = new int[sub_array_one], 
        *right_array = new int[sub_array_two];

   for(auto i = 0; i < sub_array_one; i++)
      left_array[i] = array[left + i];
   for(auto j = 0; j < sub_array_two; j++)
      right_array[j] = array[mid + 1 + j];

   auto idx_sub_one = 0, 
        idx_sub_two = 0;
   int idx_merged = left;

   while( idx_sub_one < sub_array_one && idx_sub_two < sub_array_two ) {
      if( left_array[idx_sub_one] <= right_array[idx_sub_two] ) {
         array[idx_merged] = left_array[idx_sub_one];
         idx_sub_one++;
      }
      else {
         array[idx_merged] = right_array[idx_sub_two];
         idx_sub_two++;
      }
      idx_merged++;
   }


   while( idx_sub_one < sub_array_one ) {
      array[idx_merged] = left_array[idx_sub_one];
      idx_sub_one++;
      idx_merged++;
   }

   while( idx_sub_two < sub_array_two ) {
      array[idx_merged] = right_array[idx_sub_two];
      idx_sub_two++;
      idx_merged++;
   }
   delete[] left_array;
   delete[] right_array;
}

void merge_sort(int array[], const int begin, const int end) {
   if( begin >= end )
      return;

   const int mid = begin + (end - begin) / 2;
   merge_sort(array, begin, mid);
   merge_sort(array, mid + 1, end);
   merge(array, begin, mid, end);
}

void print_array(int array[], int size) {
   for(auto i = 0; i < size; i++)
      cout << array[i] << " ";
   cout << endl;
}

int main() {
   int arr[] = {12, 11, 13, 5, 6, 7};
   int arr_size = sizeof(arr) / sizeof(arr[0]);

   cout << "Given array is: " << endl;
   print_array(arr, arr_size);

   merge_sort(arr, 0, arr_size - 1);

   cout << "Sorted array is: " << endl;
   print_array(arr, arr_size);
   return 0;
}