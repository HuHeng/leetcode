#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) {
            return intervals;
        }

        std::sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        vector<vector<int>> res;
        //vector<int> r{intervals[0][0]};
        int left = intervals[0][0];
        int instance = intervals[0][1];
        int len = intervals.size();
        for(int i = 1; i < len; ++i) {
            if(intervals[i][0] <= instance) {
                instance = std::max(instance, intervals[i][1]);  
            } else {
                res.push_back(std::vector<int>{left, instance});
                left = intervals[i][0];
                instance = intervals[i][1];
            }
        }
        res.push_back(std::vector<int>{left, instance});
        return res;

    }
};

void printv(std::vector<std::vector<int>> xx) {
    for(auto& x : xx) {
        std::cout << "[" << x[0] << ", " << x[1] << "]" << "  ";
    }
    std::cout << std::endl;
}

int main()
{
    Solution s;
    
    std::vector<std::vector<int>> a {
        {15,18}, {2,6}, {1,3}, {8,10}
    };

    std::vector<std::vector<int>> b {
        {4,5}, {1,4}
    };

    auto as = s.merge(a);
    printv(as);

    auto bs = s.merge(b);
    printv(bs);

    return 0;
}
