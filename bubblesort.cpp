#include <iostream>
using namespace std;



void swap(int* num1, int* num2) {
  int buffer = *num1;
  *num1 = *num2;
  *num2 = buffer;
}

void sort(int* input, int size) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < size -1 ; i++) {
            if (input[i] > input[i+1]) {
                swap(input[i], input[i+1]);
                swapped = true;
            }

        }
    } 
}



int main() {
  int array[] = {
    74, 19, 92, 36, 87, 23, 50, 14, 65, 41,
    7, 61, 27, 98, 3, 33, 79, 46, 72, 84,
    11, 95, 5, 29, 62, 9, 68, 38, 58, 21,
    76, 17, 43, 88, 31, 97, 6, 100, 25, 83,
    12, 37, 60, 2, 94, 15, 10, 59, 73, 44
  };
  int size = sizeof(array) / sizeof(array[0]);
  sort(array, size);
  for (int j = 0; j <= size - 1; j++) {
    cout << array[j] << ", ";
  }
  cout << endl;
  return 0;
} 