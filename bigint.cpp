#include <iostream>
#include <string>
using namespace std;

class BigInt {

    private:

        string number;

    public: 

        BigInt(string n) {

            number = n;
        }

        BigInt add(BigInt& otherNum) {

            int carry = 0;
            int thisLen = number.length() - 1;
            int otherLen = otherNum.number.length() - 1;
            string sum = "";

            while ((thisLen >= 0) || (otherLen >= 0)) {

                int digitsSum = carry;

                if (thisLen >= 0) {

                    digitsSum += number[thisLen] - '0';
                    thisLen--;
                }

                if (otherLen >= 0) {

                    digitsSum += otherNum.number[otherLen] - '0';
                    otherLen--;
                }

                carry = digitsSum / 10;
                digitsSum = digitsSum % 10;
                sum = to_string(digitsSum) + sum;
            }

            if (carry != 0) {

                sum = to_string(carry) + sum;
            }

            return sum;
        }

        string display() {

            return number;
        }
};

int main() {

    BigInt n1("123543534634236324325234231231");
    BigInt n2("324325326532423532632632432532");

    BigInt n3 = n1.add(n2);

    cout << n3.display() << endl;

    return 0;
}