#include <iostream>
using namespace std;


int sumOfDigits(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    int maxNumber = 0;
    int maxSum = 0;
    int currentNumber;


    while (true) {
        cout << "enter a natural number (0 if done): ";
        cin >> currentNumber;


        if (currentNumber == 0) {
            break;
        }


        int currentSum = sumOfDigits(currentNumber);


        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxNumber = currentNumber;
        }
    }

    if (maxNumber != 0) {
        cout << "Max sum of digits was " << maxSum << " for " << maxNumber << endl;
    } else {
        cout << "No numbers were entered." << endl;
    }

    return 0;
}