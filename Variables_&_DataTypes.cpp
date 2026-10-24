/*                     Q: How to write a variable and Data Types ?

Variable name letters, numbers, aur underscore _ se ban sakta hai.
• Variable name number se start nahi hota, jaise 2age ghalat hai.
• Space allowed nahi hai; student age ghalat hai.
• C++ keywords, jaise int, return, aur if, variable name nahi ban sakte.
• Variable name meaningful hona chahiye, jaise age, marks, ya price.
• C++ case-sensitive hai; Age aur age alag variables hain.
• int studentAge; — correct
• int 2age; — incorrect
• int student age; — incorrect
• int student_age; — correct  */

/*  

#include <iostream>
#include <string>     // String data type istemal karne ke liye zaroori hai
using namespace std;

int main() {
    // 1. int (Integer - Poore numbers ke liye)
    int age = 22;

    // 2. float (Floating-Point - Point wale chote numbers, end me 'f' lagta hai)
    float price = 450.75f;

    // 3. double (Bade aur zyada accurate point wale numbers)
    double pi = 3.1415926535;

    // 4. char (Character - Sirf ek single letter, single quotes '' me)
    char grade = 'A';

    // 5. bool (Boolean - Sirf true ya false, background me true=1 aur false=0 hota hai)
    bool isPassed = true;

    // 6. string (Text ya poora sentence store karne ke liye, double quotes "" me)
    string channelName = "Code with Me";

    // 7. long long (Bohat bade numbers ke liye jo simple 'int' me fit nahi aate)
    long long worldPopulation = 8000000000;

    // 8. unsigned int (Sirf positive numbers ke liye, minus values nahi aa sakti)
    unsigned int totalStudents = 150;

    // 9. short (Chote numbers ke liye taake computer ki RAM/memory kam use ho)
    short roomTemperature = 25;

    // 10. const int (Constant - Is variable ki value fix ho jati hai, badli nahi ja sakti)
    const int hoursInDay = 24;


    // --- Sab variables ki values ko screen par print karna ---
    cout << "1. Integer (int): " << age << endl;
    cout << "2. Float (float): " << price << endl;
    cout << "3. Double (double): " << pi << endl;
    cout << "4. Character (char): " << grade << endl;
    cout << "5. Boolean (bool): " << isPassed << " (1 ka matlab true hai)" << endl;
    cout << "6. String (string): " << channelName << endl;
    cout << "7. Long Long (long long): " << worldPopulation << endl;
    cout << "8. Unsigned Int: " << totalStudents << endl;
    cout << "9. Short: " << roomTemperature << endl;
    cout << "10. Constant Int (const): " << hoursInDay << endl;

    return 0;
}

