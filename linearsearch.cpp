#include <iostream>

using namespace std;

int linearsearch(int* array, int size, int item) {
    for (int i = 0; i < size; i++) {
        if (array[i] == item) {
            return i;
        }
    }
    return -1;
}
int main() {
    int array[] = {
    74, 19, 92, 36, 87, 23, 50, 14, 65, 41,
    7, 61, 27, 98, 3, 33, 79, 46, 72, 84,
    11, 95, 5, 29, 62, 9, 68, 38, 58, 21,
    76, 17, 43, 88, 31, 97, 6, 100, 25, 83,
    12, 37, 60, 2, 94, 15, 10, 59, 73, 44
    };
    int item;
    cin >> item;
    int index;
    int size = sizeof(array) / sizeof(array[0]);
    index = linearsearch(array, size, item);
    cout << index;
    return 0;
}

