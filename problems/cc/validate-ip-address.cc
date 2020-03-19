// https://leetcode-cn.com/problems/validate-ip-address/

#include <iostream>
#include <regex>

using namespace std;

class Solution
{
public:
    string validIPAddress(string IP)
    {
        regex ipv4_r("^(((([0-9]{1}){1})|(([1-9]{1}[0-9]{1}){1})|((1{1}[0-9]{2}){1})|((2{1}[0-4]{1}[0-9]{1}){1})|((2{1}5{1}[0-5]{1}){1})){1}\\.){3}(((([0-9]{1}){1})|(([1-9]{1}[0-9]{1}){1})|((1{1}[0-9]{2}){1})|((2{1}[0-4]{1}[0-9]{1}){1})|((2{1}5{1}[0-5]{1}){1})){1})$");
        regex ipv6_r("^(((([0-9]|[a-f]|[A-F]){1,4}){1}:{1}){7})((([0-9]|[a-f]|[A-F]){1,4}){1})$");
        return regex_match(IP, ipv4_r) ? "IPv4" : regex_match(IP, ipv6_r) ? "IPv6" : "Neither";
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
