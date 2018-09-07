#include <iostream>
#include <map>
/*
 * Converts roman numeral to integer number
 */

using namespace std;
int main() {
    map<char, int> romanMap;
    romanMap['I'] = 1;
    romanMap['V'] = 5;
    romanMap['X'] = 10;
    romanMap['L'] = 50;
    romanMap['C'] = 100;
    romanMap['D'] = 500;
    romanMap['M'] = 1000;

    romanMap['i'] = 1;
    romanMap['v'] = 5;
    romanMap['x'] = 10;
    romanMap['l'] = 50;
    romanMap['c'] = 100;
    romanMap['d'] = 500;
    romanMap['m'] = 1000;

    int prevVal = 0;
    int total = 0;
    string romanInput;
    cout << "Enter a Roman Numeral: ";
    while(cin >> romanInput) {
        for( auto it = romanInput.rbegin(); it != romanInput.rend(); it++) {
            int curVal = romanMap[*it];
            if(curVal >= prevVal)
                total += curVal;
            else
                total -= curVal;
            prevVal = curVal;
        }
        cout << "Value is " << total << endl;
        cout << "Enter a roman numeral: ";
    }
    return 0;
}