#include <vector>
#include <string>

#ifndef CALCLOGICAL_H
#define CALCLOGICAL_H

using namespace std;

class calcLogical
{
public:
    string justNum(string nums);
    string logical(int param);
    string logicalNot(string nums);
    string logicalOr(string nums1, string nums2);
    string logicalAnd(string nums1, string nums2);
    string logicalXor(string nums1, string nums2);
};

#endif // CALCLOGICAL_H
