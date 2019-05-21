#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> findmin(vector<int>& heights, int s, int e)
        {
            //int len = heights.size();
            int min_index = s;
            vector<int> ret;
            ret.push_back(s);
            for(int i =s+1; i<=e; ++i){
                if(heights[i] < heights[min_index]) {
                    min_index = i;
                    ret.clear();
                    ret.push_back(i);
                }else if(heights[i] == heights[min_index]){
                    ret.push_back(i);
                }

            }
            return ret;

        }

        int max3(int a, int b, int c){

            return std::max(std::max(a,b),c);
        }

        int largestRectangleArea(vector<int>& heights, int s, int e) {
            if(s > e)
                return 0;
            if(s == e)
                return heights[s];
            auto min_indexs = findmin(heights, s, e);

            //
            int max_area = (e-s+1) * heights[min_indexs[0]];

            for(size_t i = 0; i<=min_indexs.size(); ++i){
                int area = 0;
                if(i == 0){
                    area = largestRectangleArea(heights, s, min_indexs[i] -1 );

                }else if(i == min_indexs.size()){
                    area = largestRectangleArea(heights, min_indexs[i-1]+1, e);

                }else {
                    area = largestRectangleArea(heights, min_indexs[i-1]+1, min_indexs[i]-1);
                }
                max_area = std::max(area, max_area);
            }
            return max_area;

        }

        int largestRectangleArea(vector<int>& heights) {
            int len = heights.size();
            if(len == 0)
                return 0;
            return largestRectangleArea(heights, 0, len-1);   
        }
};

int main()
{
    Solution s;
    //vector<int> h{2, 1, 5,6,2, 3};
    vector<int> h{0,0};
    int r = s.largestRectangleArea(h);
    std::cout << r << std::endl;
    return 0;
}
