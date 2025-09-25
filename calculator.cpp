#include <iostream>
using namespace std;

int main() {
    char operation;
    int stupid = 10;
    for (int stupid = 1; stupid > 0; stupid--) {
        long double num1 = 0;
        cout << "Hello friend i am calculator written by a complete noob in c++\nPlease enter a number\n";
        while (!(cin >> num1)){
            cout << "noooooo\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        long double num2 = 0;
        cout << "thank you for your submission, put another one in\n";
        while (!(cin >> num2)){
            cout << "noooooo\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "write the operator pls\n";
        while ((!(cin >> operation)) || (!(operation == '+' || operation == '-' || operation == '*' || operation == '/'))) {
            cout << "noooooo\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        switch (operation) {
            case '+':
              cout << "Thank you friend I will add the numbers.\nYour answer is " << num1 + num2 << ".\n";
            break;
            case '-':
              cout << "Thank you friend I will subtract the numbers.\nYour answer is " << num1 - num2 << ".\n";
            break;
            case '*':
              cout << "Thank you friend I will multiply the numbers.\nYour answer is " << num1 * num2 << ".\n";
            break;
            case '/':
              cout << "Thank you friend I will divide the numbers.\nYour answer is " << num1 / num2 << ".\n";
            break;
            default:
              cout << "I'm really sorry my friend, you entered something incorrect.\n";
        }
    } 
    return 0;
} 