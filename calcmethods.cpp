#include "calcmethods.h"
#include <stdexcept>

const int BIN = 2;
const int OCT = 8;
const int DEC = 10;
const int HEX = 16;
const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string calcMethods::toDec(string nums, int inNumSystem) {
    string numsBefore = nums;
    string numsAfter = "";
    bool dot = false;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == ',' or nums[i] == '.')
        {
            numsBefore = nums.substr(0, i);
            numsAfter = nums.substr(i+1, nums.size());
            dot = true;
        }
    }

    unsigned long long int result = 0;
    int power = 1;
    for (int i = numsBefore.size() - 1; i >= 0; --i)
    {
        int digit = digits.find(numsBefore[i]);
        if (digit >= inNumSystem)
            throw invalid_argument("Invalid input");
        result += digit * power;
        power *= inNumSystem;
    }

    double resultDot = 0;
    if (dot)
    {
        double powerDot = 1;
        for (int i = 0; i < numsAfter.size(); ++i)
        {
            powerDot *= inNumSystem;
            int digit = digits.find(numsAfter[i]);
            if (digit >= inNumSystem)
                throw invalid_argument("Invalid input");
            resultDot += 1 / powerDot * digit;
        }
    }

    return (dot) ? to_string(result + resultDot) : to_string(result);
}

string calcMethods::toBin(string nums, int inNumSystem) {
    unsigned long long num = stoi(toDec(nums, inNumSystem));
    string result = "";
    bool status = true;

    while(status){
        status = false;
        if (num != 0) {
            result += to_string(num % BIN);
            num /= BIN;
            status = true;
        }
    }

    reverse(result.begin(),result.end());
    return result;
}

string calcMethods::toOct(string nums, int inNumSystem) {
    unsigned long long num = stoi(toDec(nums, inNumSystem));
    string result = "";
    bool status = true;

    while(status){
        status = false;
        if (num != 0) {
            result += to_string((num % OCT));
            num /= OCT;
            status = true;
        }
    }

    reverse(result.begin(),result.end());
    return result;
}

string calcMethods::toHex(string nums, int inNumSystem) {
    map <int, char> st = {{10,'A'},
                            {11, 'B'},
                            {12, 'C'},
                            {13, 'D'},
                            {14, 'E'},
                            {15, 'F'},
                            };
    unsigned long long num = stoi(toDec(nums, inNumSystem));
    string result = "";
    bool status = true;

    while(status){
        status = false;
        if (num != 0) {
            if (num % HEX >= 10)
                result += st[num % HEX];
            else
                result += to_string((num % HEX));
            num /= HEX;
            status = true;
        }
    }

    reverse(result.begin(),result.end());
    return result;
}
