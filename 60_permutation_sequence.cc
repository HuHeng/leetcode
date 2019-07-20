#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if(n <= 0) {
            return "";
        }
        vector<int> p(n+1, 1);

        vector<char> s(n+1, '0');
        for(int i = 1; i <= n; ++i) {
            s[i] = i + '0';
            p[i] = p[i-1] * i;
        }

        std::string r(n,'1');

        k--;
        for(int i = 0; i < n; ++i) {
            int index = k / p[n-1-i];
            r[i] = s[index + 1]; 

            //
            k = k % p[n-1-i];
            s.erase(s.begin() + index + 1);
        }

        return r;
    }
};



int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    Solution s;
    std::cout << s.getPermutation(n, k) << std::endl;
}
