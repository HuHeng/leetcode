#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            if(matrix.size() <= 0)
                return vector<int>{};

            int m = matrix.size();
            int n = matrix[0].size();
            int x = 0, y = 0;

            vector<int> xx; 
            while(m >0 && n > 0){ 
                //collect right n
                for(int i = 0; i < n; ++i, ++x){
                    xx.push_back(matrix[y][x]);
                }
                if(--m == 0)
                    break;
                ++y;
                --x;

                //collect down m-1
                for(int i = 0; i < m; ++i, ++y){
                    xx.push_back(matrix[y][x]);
                }
                if(--n == 0)
                    break;
                --x;
                --y;

                //collect left n-1
                for(int i = 0; i < n; ++i, --x){
                    xx.push_back(matrix[y][x]);
                }
                if(--m == 0)
                    break;
                --y;
                ++x;

                //collect up m-2
                for(int i = 0; i < m; ++i, --y){
                    xx.push_back(matrix[y][x]);
                }
                --n;
                ++x;
                ++y;

            }
            return xx;
        }

};
        int main()
        {
            vector<vector<int>> a{{1,2,3},{4,5,6}, {7,8,9}};
            Solution s;
            vector<int> ret = s.spiralOrder(a);
            for(auto i : ret)
                std::cout << i << " ";
            std::cout << std::endl;
            return 0;

        }
