// iostream: cin, cout, getline jese input/output tools ke liye
#include <iostream>

// string: std::string class use karne ke liye
#include <string>

// unordered_map: key-value pairs store karne ke liye (fast lookup)
#include <unordered_map>

// functional: std::function use karne ke liye
#include <functional>

// algorithm: std::transform function ke liye
#include <algorithm>

// cctype: tolower() function ke liye
#include <cctype>

// std namespace ke saare names direct use karne ki permission
// e.g. cout, cin, string, unordered_map likh sakte hain
using namespace std;

// Monday ka routine return karne wala function
string monday_routine() {
    // Monday ka message return karo
    return "Monday: Back to work! Set weekly goals.";
}

// Friday ka routine return karne wala function
string friday_routine() {
    // Friday ka message return karo
    return "Friday: Weekend is almost here!";
}

// Weekend ka routine return karne wala function
string weekend_routine() {
    // Saturday/Sunday ka message return karo
    return "Weekend: Relax and recharge.";
}

// Normal weekday ka routine return karne wala function
string default_weekday_routine() {
    // Tuesday, Wednesday, Thursday ka message return karo
    return "Weekday: Focus on your tasks.";
}

// Invalid day ke liye message return karne wala function
string invalid_day_action() {
    // Galat day enter hone par ye message return hoga
    return "Invalid day! Please enter a valid day.";
}

// String ko lowercase me convert karne wala function
string clean_string(string str) {
    // transform: string ke har character par lambda apply karega
    transform(str.begin(), str.end(), str.begin(),
        // Lambda function: ek character receive karta hai
        [](unsigned char ch) {
            // Character ko lowercase karke wapas char me cast karo
            return static_cast<char>(tolower(ch));
        }
    );
    // Lowercase string return karo
    return str;
}

// Day ka naam receive karke uska schedule return karne wala function
string get_daily_schedule(string day_name) {
    // Action ka alias: ye ek function type hai jo string return karta hai
    using Action = function<string()>;

    // Routes map: har day ka naam -> uska routine function
    const unordered_map<string, Action> routes = {
        // Monday apna special routine use karega
        {"monday", monday_routine},
        // Tuesday normal weekday routine use karega
        {"tuesday", default_weekday_routine},
        // Wednesday normal weekday routine use karega
        {"wednesday", default_weekday_routine},
        // Thursday normal weekday routine use karega
        {"thursday", default_weekday_routine},
        // Friday apna special routine use karega
        {"friday", friday_routine},
        // Saturday weekend routine use karega
        {"saturday", weekend_routine},
        // Sunday weekend routine use karega
        {"sunday", weekend_routine}
    };

    // User ka day lowercase karke map me search karo
    // it = iterator; agar mila to us entry par point karega
    const auto it = routes.find(clean_string(day_name));

    // Agar iterator end ke barabar nahi hai, matlab day valid hai
    // Bina if ke validity check
    const bool valid = (it != routes.end());

    // Actions array: index 0 = invalid message, index 1 = valid message
    const Action actions[] = {
        // Index 0: invalid day ka function
        invalid_day_action,
        // Index 1: lambda jo "Valid day!" return karta hai
        []() { return string("Valid day!"); }
    };

    // valid = true -> index 1 -> "Valid day!"
    // valid = false -> index 0 -> "Invalid day!..."
    // Array indexing se if/ternary avoid kiya gaya hai
    cout << actions[valid]() << '\n';

    // Dispatch map: true/false ke hisaab se kaunsa function chalana hai
    const unordered_map<bool, Action> dispatch = {
        // false case: invalid day function
        {false, invalid_day_action},
        // true case: lambda jo map se mila hua routine call karega
        {true, [it, end = routes.end()]() {
            // it->second = map me stored function
            // us function ko call karke uska message return karo
            return it->second();
        }}
    };

    // valid ke hisaab se sahi function call karo aur result return karo
    return dispatch.at(valid)();
}

// Program ka entry point
int main() {
    // User ka input store karne ke liye string variable
    string day;

    // User se day mangna
    cout << "Enter a day: ";

    // Poori line input lena (spaces bhi support karta hai)
    getline(cin, day);

    // Function call karke result print karna
    cout << get_daily_schedule(day) << '\n';

    // Program successfully end
    return 0;
}
