#include <iostream>
#include <chrono>
using namespace std;

double recursivefactorial(int num) {
    if (num > 1) {
        return num * recursivefactorial(num-1);
    } else {
        return max(num, 1);
    }
}

long int iterativefactorial(int num) {
    long long int output = 1;
    for (int i = 1; i <= num; i++) {
        output *= i;
    }
    return output;
}

int main(){

    auto factlambda = [](int num) {
        int output = 1;
        for (int i = 1; i <= num; i++) {
            output *= i;
        }
        return output;
    };

    for (int i = 0; i < 50; i++) {
        cout << i << ' ' << factlambda(i) << endl;
    }
    for (int i = 0; i < 50; i++) {
        cout << i << ' ' << iterativefactorial(i) << endl;
    }
    for (int i = 0; i < 1000; i++) {
        cout << i << ' ' << recursivefactorial(i) << endl;
    }
    return 0;
}