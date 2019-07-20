#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Solution {
public:
    void generate(vector<vector<int>>& v, int x, int y, int n, int start) {
        if(n <= 0) {
            return;
        }

        for(int i = x; i < x+n; ++i) {
            v[y][i] = start++;
        }
        for(int j = y+1; j < y+n; ++j) {
            v[j][x+n-1] = start++;
        }

        for(int i = x+n-2; i >= x; --i) {
            v[y+n-1][i] = start++;
        }
        for(int i = y+n-2; i >= y+1; --i) {
            v[i][x] = start++;
        }

        return generate(v, x+1, y+1, n-2, start);

    }


    vector<vector<int>> generateMatrix(int n) {
        if(n <=0) {
            return vector<vector<int>>();
        }
        vector<vector<int>> v(n, vector<int>(n, 0));
        
        generate(v, 0, 0, n, 1);
        return v;
    }

};

int main(int argc, char** argv)
{
    int n = atoi(argv[1]);

    Solution s;
    auto v = s.generateMatrix(n);
    std::cout << v.size() << std::endl;
    std::cout << v[0].size() << std::endl;
    for(auto& vv : v) {
        for(auto x : vv) {
            std::cout << setw(5) << x;
        }
        std::cout << std::endl;
    }
    return 0;
}
