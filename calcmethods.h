#include <string>
#include <algorithm>
#include <map>

#ifndef CALCMETHODS_H
#define CALCMETHODS_H

using namespace std;

class calcMethods
{
public:
    string toDec(string nums, int inNumSystem);
    string toBin(string nums, int inNumSystem);
    string toOct(string nums, int inNumSystem);
    string toHex(string nums, int inNumSystem);
};

#endif // CALCMETHODS_H
