#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
          0        1        2        3
      --------   -----    -----    -----     ------     ------
    1     2    3   4   5    6   7    8    9    10   11    12    13

c1:            |----------------|

c2:       |-----------------|

c3:       |-------------|

c4:            |---------------------------------|

[x, y] means new interval

case 1: 
    first in odd n, second in odd m

    intervals < n, copy 
    add [x, y]
    intervals > m, copy 



case 2:
    first in even n, second in even m




  **/
class Solution {
public:
    int findIndex(vector<vector<int>>& intervals, int m, int n, int value)
    {
        int s = m; 
        int e = n;

        if(value < intervals[s][0])
            return (s+1)*2 - 1;
        if(value > intervals[e][1])
            return (e+1)*2 + 1;
        if(s == e) {
            return (s+1)*2;
        }

        if(s == e-1) {
            if(intervals[s][0] <= value && value <= intervals[s][1]) 
                return (s+1)*2;
            else if(intervals[s][1] < value && value < intervals[e][0])
                return (s+1)*2 +1;
            else 
                return (e+1) *2;
        }

        int x = (s+e) /2;

        if(value <= intervals[x][0])
            return findIndex(intervals, s, x, value);
        if(value >= intervals[x][1])
            return findIndex(intervals, x, e, value);
        return (x+1)*2;
    
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int >> r;
        int len = intervals.size();
        if(len == 0) {
            r.push_back(newInterval);
            return r;
        }

        int i1 = findIndex(intervals, 0, len-1, newInterval[0]);         
        int i2 = findIndex(intervals, 0, len-1, newInterval[1]);         
        if(i1 %2 ==0 && i2%2 ==0) {
            for(int i = 0; i < (i1+1)/2-1; ++i) {
                r.push_back(intervals[i]);
            }
            r.push_back(vector<int>{intervals[i1/2-1][0], intervals[i2/2-1][1]});
            for(int i = i2/2; i < len; i++){
                r.push_back(intervals[i]);
            }
        
        }else if(i1 % 2==1 && i2%2==1) {
            for(int i = 0; i < (i1+1)/2-1; ++i) {
                r.push_back(intervals[i]);
            }
            r.push_back(vector<int>{newInterval[0], newInterval[1]});
            for(int i = i2/2; i < len; i++){
                r.push_back(intervals[i]);
            }
            
        } else if(i1 %2 == 0 && i2 %2 ==1) {
            for(int i = 0; i < (i1+1)/2-1; ++i) {
                r.push_back(intervals[i]);
            }
            r.push_back(vector<int>{intervals[i1/2-1][0], newInterval[1]});
            for(int i = i2/2; i < len; i++){
                r.push_back(intervals[i]);
            }
        
        } else {
            for(int i = 0; i < (i1+1)/2-1; ++i) {
                r.push_back(intervals[i]);
            }
            r.push_back(vector<int>{newInterval[0], intervals[i2/2-1][1]});
            for(int i = i2/2; i < len; i++){
                r.push_back(intervals[i]);
            }
        
        }
        return r;

    }
};

int main()
{

    Solution s;

    vector<vector<int>> intervals{{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};

    //for(int i = 0; i < 20; ++i) {
    //    std::cout << i << ": " << s.findIndex(intervals, 0, 4, i) << std::endl;
    //}
    vector<int> newInterval{4,8};
    auto r = s.insert(intervals, newInterval);
    for(int i = 0; i < r.size(); ++i) {
        std::cout << "[" << r[i][0]  << "," << r[i][1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}
