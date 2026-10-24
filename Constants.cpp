#include <iostream>
using namespace std;

int main() {
    // Defining a constant variable
    const double PI = 3.14159;
    const int MINUTES_IN_HOUR = 60;

    cout << "Value of PI: " << PI << endl;
    cout << "Minutes in an hour: " << MINUTES_IN_HOUR << endl;

    // ⚠️ Trying to change a constant value will cause an error:
    // PI = 3.14; // ERROR: assignment of read-only variable 'PI'

    return 0;
}
