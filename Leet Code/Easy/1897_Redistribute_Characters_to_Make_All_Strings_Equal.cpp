// 1897. Redistribute Characters to Make All Strings Equal
#include<iostream>
using namespace std;

class Solution {
public:
    bool makeEqual(std::vector<std::string>& words) {
        if (words.size() == 1) {
            return true;
        }

        int count = 0;
        for (const std::string& s : words) {
            count += s.length();
        }

        if (count % words.size() != 0) {
            return false;
        }

        std::vector<int> m(26, 0);
        for (const std::string& s : words) {
            for (char c : s) {
                m[c - 'a']++;
            }
        }

        for (int count : m) {
            if (count % words.size() != 0) {
                return false;
            }
        }

        return true;
    }
};


int main()
{
    
    return 0;
}