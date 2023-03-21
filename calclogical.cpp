#include "calclogical.h"

const string digits = "01";
const int sizeA = 4;

string calcLogical::logicalNot(string nums) {
    string st;
    for (int i = 0; i < sizeA; ++i) {
        int digit = digits.find(nums[i]);
        if (digit != 0 && digit != 1)
            throw invalid_argument("Invalid input");
        (digit) ? st.append(to_string(0)) : st.append(to_string(1));
    }
    return st;
}

string calcLogical::logical(int param) {
    return (param) ? "1111" : "0000";
}

string calcLogical::justNum(string nums) {
    return nums;
}

string calcLogical::logicalOr(string nums1, string nums2) {
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

string calcLogical::logicalAnd(string nums1, string nums2) {
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

string calcLogical::logicalXor(string nums1, string nums2) {
    string st;
    for (int i = 0; i < sizeA; ++i) {
        int digit1 = digits.find(nums1[i]);
        int digit2 = digits.find(nums2[i]);
        if ((digit1 != 0 && digit1 != 1) || (digit2 != 0 && digit2 != 1))
            throw invalid_argument("Invalid input");
        st.append(to_string(digit1 ^ digit2));
    }
    return st;
}
