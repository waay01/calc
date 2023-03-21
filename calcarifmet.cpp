#include "calcarifmet.h"

using namespace std;

const string digits = "01";
const int sizeA = 4;

vector<int> num1, num2;

vector<int> calcArifmet::strToVector(string nums) {
    vector<int> num;
    for(int i = 0; i < num.size(); ++i)
        num.emplace_back(digits.find(num1[i]));

    return num;
}

string calcArifmet::toShowQt(vector<int> num) {
    string result = "";
    for (int i = 0; i < num.size(); ++i)
        result += to_string(num[i]);
    return result;
}

int strToInt(string numStr) {
    int numInt = 0, i = 0, sing = 1;
    if(numStr[0] == '-')
    {
        sing = -sing;
        i++;
    }

    for (; i != numStr.size(); ++i)
    {
        int digit = digits.find(numStr[i]);
        numInt = numInt * 10 + digit;
    }
    return numInt * sing;
}

int toDec(string nums, int inNumSystem) {
    string numsBefore = nums;

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

    return result;
}

int toDecVector(vector<int> nums, int inNumSystem) {
    unsigned long long result = 0;
    int power = 1;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        if (nums[i] >= inNumSystem)
            throw invalid_argument("Invalid input");
        result += nums[i] * power;
        power *= inNumSystem;
    }

    return result;
}

string toBin(string nums) {
    int num = strToInt(nums);
//    string result = "";
//    bool status = true;

//    while(status){
//        status = false;
//        if (num != 0) {
//            result += to_string(num % 2);
//            num /= 2;
//            status = true;
//        }
//    }

//    reverse(result.begin(),result.end());
//    return result;
    return to_string(num);
}

string calcArifmet::justNum(string nums) {
    return nums;
}

string calcArifmet::logicalNot(string nums) {
    string st;
    for (int i = 0; i < sizeA; ++i) {
        int digit = digits.find(nums[i]);
        if (digit != 0 && digit != 1)
            throw invalid_argument("Invalid input");
        (digit) ? st.append(to_string(0)) : st.append(to_string(1));
    }
    return st;
}

string calcArifmet::logicalOr(string nums1, string nums2) {
    string st;
    for (int i = 0; i < sizeA; ++i) {
        int digit1 = digits.find(nums1[i]);
        int digit2 = digits.find(nums2[i]);
        if ((digit1 != 0 && digit1 != 1) || (digit2 != 0 && digit2 != 1))
            throw invalid_argument("Invalid input");
        st.append(to_string(digit1 | digit2));
    }
    return st;
}

string calcArifmet::logicalAnd(string nums1, string nums2) {
    string st;
    for (int i = 0; i < sizeA; ++i) {
        int digit1 = digits.find(nums1[i]);
        int digit2 = digits.find(nums2[i]);
        if ((digit1 != 0 && digit1 != 1) || (digit2 != 0 && digit2 != 1))
            throw invalid_argument("Invalid input");
        st.append(to_string(digit1 & digit2));
    }
    return st;
}

string calcArifmet::calcPlus(string nums1, string nums2) {
    int st = toDec(nums1, 2) + toDec(nums2, 2);
    return toBin(to_string(st));
}
