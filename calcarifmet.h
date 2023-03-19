#include <string>

#ifndef CALCARIFMET_H
#define CALCARIFMET_H

using namespace std;

class calcArifmet
{
public:
    string justNum(string nums);
    string logicalNot(string nums);
    string logicalOr(string nums1, string nums2);
    string logicalAnd(string nums1, string nums2);
    string calcPlus(string num1, string nums2);
    string calcMinus(string num1, string nums2);
};

#endif // CALCARIFMET_H
