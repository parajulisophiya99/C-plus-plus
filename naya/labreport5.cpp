#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Macro version - simple text substitution done by the preprocessor
#define IS_EVEN_MACRO(x) ((x) % 2 == 0)

// Inline function - a "request" to the compiler to substitute the function
// body directly at the call site, avoiding function-call overhead
inline bool isEven(int n) {
    return n % 2 == 0;
}

// Non-inline (regular) function - involves actual function call overhead
// (pushing arguments/return address on stack, jumping, returning, etc.)
bool isEvenRegular(int n) {
    return n % 2 == 0;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Using the inline function
    if (isEven(num))
        cout << num << " is Even (checked using inline function)." << endl;
    else
        cout << num << " is Odd (checked using inline function)." << endl;

    // ---------------------------------------------------------
    // Performance comparison: macro vs inline function vs regular function
    // over 1 million iterations
    // ---------------------------------------------------------
    const int ITERATIONS = 1000000;
    volatile bool result; // volatile to prevent compiler from optimizing the loop away

    // 1. Macro timing
    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < ITERATIONS; i++) {
        result = IS_EVEN_MACRO(i);
    }
    auto end1 = high_resolution_clock::now();
    auto macroDuration = duration_cast<microseconds>(end1 - start1).count();

    // 2. Inline function timing
    auto start2 = high_resolution_clock::now();
    for (int i = 0; i < ITERATIONS; i++) {
        result = isEven(i);
    }
    auto end2 = high_resolution_clock::now();
    auto inlineDuration = duration_cast<microseconds>(end2 - start2).count();

    // 3. Regular (non-inline) function timing
    auto start3 = high_resolution_clock::now();
    for (int i = 0; i < ITERATIONS; i++) {
        result = isEvenRegular(i);
    }
    auto end3 = high_resolution_clock::now();
    auto regularDuration = duration_cast<microseconds>(end3 - start3).count();

    cout << "\n--- Performance over " << ITERATIONS << " iterations ---\n";
    cout << "Macro version:           " << macroDuration << " microseconds\n";
    cout << "Inline function version: " << inlineDuration << " microseconds\n";
    cout << "Regular function version:" << regularDuration << " microseconds\n";

    return 0;
}