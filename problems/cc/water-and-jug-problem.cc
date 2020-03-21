// https://leetcode-cn.com/problems/water-and-jug-problem/
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canMeasureWater(int x, int y, int z)
    {
        // return (z == x + y || z == x || z == y) ? true : (z > x + y || x == 0 || y == 0) ? false : (z % gcd(x, y)) == 0; // 也可一行
        if (z == x + y || z == x || z == y)
            return true;
        if (z > x + y || x == 0 || y == 0)
            return false;
        return (z % gcd(x, y)) == 0;
    }

    int gcd(int a, int b)
    {
        // return a == 0 || b == 0 ? abs(a - b) : a > b ? gcd(b, a) : gcd(a, b % a); // 也可一行
        if (a == 0)
            return b;
        else if (b == 0)
            return a;
        else if (a > b)
            return gcd(b, a);
        else
            return gcd(a, b % a);
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
