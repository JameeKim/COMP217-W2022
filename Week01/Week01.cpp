/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Class Week #1 (Wed. Jan. 12, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <string>
#include <iostream>

#include "Utilities.h"

using namespace std;

// Declaring a function
// Names of the parameters are not necessary
int factorial(int n);

// The main function containing the logic to be run
int main() {
    // Defining variables with various types in C++
    int x = 5;
    double d = 2.05;
    float f = 4.598;
    bool b = true;

    // `string` is NOT a predefined type
    // We need `#include <string>` at the top of the file
    string msg = "The sum is equal to: ";

    // Operators
    double sum = d + f;

    // Print on console
    cout << msg << sum << endl;

    // Branching
    float temp = 12.5;
    if (temp > 10) {
        cout << "It's hot!" << endl;
    } else if (temp < 10) {
        cout << "It's cold!" << endl;
    } else {
        cout << "It's 10 degrees" << endl;
    }

    // Loop
    cout << "Counting from 1 to 10: ";
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << " ";
    }
    cout << endl;

    // Using a user-defined function
    int sixFac = factorial(6);
    cout << "6! = " << sixFac << endl;

    // Calling things defined in another header file
    int ph = getPlayerHealth();
    cout << "Player Health: " << ph << "/" << playerDefaultHealth << endl;

    // Calling functions in namespaces
    cout << "Is the player attacking? " << player::isAttacking() << endl;
    cout << "Is the enemy attacking? " << enemy::isAttacking() << endl;

    // Finished without errors
    return 0;
}

// Defining a function
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
