#include <iostream>

#include "method.h"

using namespace std;

int main(int argc, char const* argv[]) {
  int arr[10];
  void choose_sort(int* arr);
  init_arr(arr, 1);
  print_arr(arr, 10);

  choose_sort(arr);
  print_arr(arr, 10);
  return 0;
}

void choose_sort(int* arr) {
  int temp, max, max_index = 0;

  for (int i = 10; i > 0; i--) {
    max = arr[0];
    max_index = 0;
    for (int j = 0; j < i; j++) {
      if (arr[j] > max) {
        max = arr[j];
        max_index = j;
      }
    }
    temp = arr[i - 1];
    arr[i - 1] = arr[max_index];
    arr[max_index] = temp;
  }
}