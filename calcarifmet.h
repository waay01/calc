#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#ifndef CALCARIFMET_H
#define CALCARIFMET_H

using namespace std;

class calcArifmet
{
public:
    vector<int> strToVector(string num1);
    string toShowQt(vector<int> num);

    string justNum(string nums);
    string logicalNot(string nums);
    string logicalOr(string nums1, string nums2);
    string logicalAnd(string nums1, string nums2);
    string calcPlus(string num1, string nums2);
    string calcMinus(string num1, string nums2);
};

#endif // CALCARIFMET_H
