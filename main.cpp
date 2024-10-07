#include <iostream>
#include "stringdata.h"
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int linear_search(const vector<string>& container, const string& element) {
    for (size_t i = 0; i < container.size(); ++i) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}

// Binary search function
int binary_search(const vector<string>& container, const string& element) {
    int minIndex = 0;
    int maxIndex = container.size() - 1;

    while (minIndex <= maxIndex) {
        int midIndex = minIndex + ((maxIndex - minIndex) / 2);

        if (container[midIndex] == element) {
            return midIndex;
        }
        if (element > container[midIndex]) {
            minIndex = midIndex + 1;
        } else {
            maxIndex = midIndex - 1;
        }
    }
    return -1;
}

// Main function to perform the searches
int main() {
    vector<string> string_data = getStringData();
    cout << "Welcome to my analyzer!" << endl;
    cout << "Now using: Linear Search" << endl << endl;

    // Linear Search Tests
    long long start = systemTimeNanoseconds();
    cout << "Searching for: not_here" << endl;
    cout << linear_search(string_data, "not_here") << endl;
    cout << "Time: " << (systemTimeNanoseconds() - start) << " milliseconds" << endl;

    start = systemTimeNanoseconds();
    cout << endl << "Searching for: mzzzz" << endl;
    cout << linear_search(string_data, "mzzzz") << endl;
    cout << "Time: " << (systemTimeNanoseconds() - start) << " milliseconds" << endl;

    start = systemTimeNanoseconds();
    cout << endl << "Searching for: aaaaa" << endl;
    cout << linear_search(string_data, "aaaaa") << endl;
    cout << "Time: " << (systemTimeNanoseconds() - start) << " milliseconds" << endl;

    cout << endl;
    cout << "Now using: Binary Search" << endl;

    // Binary Search Tests
    start = systemTimeNanoseconds();
    cout << "Searching for: not_here" << endl;
    cout << binary_search(string_data, "not_here") << endl;
    cout << "Time: " << (systemTimeNanoseconds() - start) << " milliseconds" << endl;

    start = systemTimeNanoseconds();
    cout << endl << "Searching for: mzzzz" << endl;
    cout << binary_search(string_data, "mzzzz") << endl;
    cout << "Time: " << (systemTimeNanoseconds() - start) << " milliseconds" << endl;

    start = systemTimeNanoseconds();
    cout << endl << "Searching for: aaaaa" << endl;
    cout << binary_search(string_data, "aaaaa") << endl;
    cout << "Time: " << (systemTimeNanoseconds() - start) << " milliseconds" << endl;

    return 0;
}
