#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    char addchar(char a, char b, int& c) {
        int ans = a - '0' + b - '0' + c;
        if(ans < 2) {
            c = 0;
            return ans + '0';
        } else if (ans >=2) {
            c =1;
            return ans -2 + '0';
        }
        return '0';

    }

    string add(string a, string b) {
        int c = 0;
        int i = b.length()-1;
        int j = a.length()-1;
        for(; j >= 0; --i, --j) {
            if(i >= 0) {
                a[j] = addchar(a[j], b[i], c);
            } else if ( c != 0){
                a[j] = addchar(a[j], '0', c);
            
            } else {
                break;
            }
                
        }
        if(c != 0)
            a.insert(a.begin(), '1');
        return a;
    }
    string addBinary(string a, string b) {
        if(a.length() > b.length())
            return add(a, b);
        else 
            return add(b, a);

    }
};

int main(int argc, char** argv)
{

    Solution s;
    //string a = "1010";
    //string b = "1011";

    std::cout << s.addBinary(argv[1], argv[2]) << std::endl;;

    return 0;
}
