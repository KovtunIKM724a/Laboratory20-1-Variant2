#include <iostream>
#include <vector>
using namespace std;

int main() {

    srand(time(nullptr));

    vector<double> vec(15);

    for (int i = 0; i < 15; i++)
    {
        double first_N = rand() % 201 - 100;
        double second_N = (double)(rand() % 2000 - 1000) / 1000;

        vec[i] = first_N + second_N;
        cout << vec[i] << " ";
    }
    cout << "\n";

    bool foundNegative = false;
    double maxNegative = vec[0];

    for (double num : vec) {
        if (num < 0) {
            if (!foundNegative || num > maxNegative) {
                maxNegative = num;
                foundNegative = true;
            }
        }
    }

    if (foundNegative) {
        int rounded = round(maxNegative);
        cout << "Largest negative number: " << maxNegative << "\n";
        cout << "Rounded: " << rounded << "\n";
    }
    else {
        cout << "There are no negative numbers in the vector.\n";
    }


    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < 15; ++i) {
        if (vec[i] < vec[minIndex]) minIndex = i;
        if (vec[i] > vec[maxIndex]) maxIndex = i;
    }

    int from = min(minIndex, maxIndex) + 1;
    int to = max(minIndex, maxIndex);

    if (to - from <= 0) {
        cout << "There are no elements between the minimum and maximum element.\n";
    }
    else {
        double product = 1.0;
        for (int i = from; i < to; ++i) {
            product *= vec[i];
        }
        cout << "The yield of elements between the minimum and maximum: " << product << "\n";
    }
}