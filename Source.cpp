//Jonah Bees 03/29/24
#include <iostream>
#include <string>
using namespace std;

int convertRomanToInt(char r);

int main() {
    int total = 0;
    string romanNumeral;

    while (true) {
        cout << "Enter a Roman numeral or 'Q' to quit: ";
        getline(cin, romanNumeral);

        if (romanNumeral == "Q" || romanNumeral == "q") {
            break;
        }

        int prevValue = 0;

        for (int i = romanNumeral.length() - 1; i >= 0; i--) {
            int value = convertRomanToInt(romanNumeral[i]);

            if (value == 0) {
                total = 0;
                break;
            }

            if (value < prevValue) {
                total -= value;
            }
            else {
                total += value;
            }

            prevValue = value;
        }

        if (total != 0) {
            cout << romanNumeral << " = " << total << endl;
        }

        total = 0;
    }

    return 0;
}
int convertRomanToInt(char r) {
    switch (r) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default:
        cout << "Invalid Roman numeral character: " << r << endl;
        return 0;
    }
}