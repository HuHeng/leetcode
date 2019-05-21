#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void DFS(vector<vector<int>>& result, vector<int>& candidates, int i, vector<int>& out, int target, int pre) {
        int len = candidates.size();

        if(target == 0){
            result.push_back(out);
            return;
        }

        if(i >= len || target < 0) {
            return;
        }

            
        //DFS(result, candidates, i+1, out, target);
        //if(i+1 <len && candidates[i+1] != candidates[i]){
        //    out.push_back(candidates[i]);
        //    DFS(result, candidates, i+1, out, target-candidates[i]);
        //}
        //DFS(result, candidates, i+2, out, target);

        DFS(result, candidates, i+1, out, target, target);
        if(i>0 && candidates[i] == candidates[i-1] && pre == target) 
            return;

        out.push_back(candidates[i]);
        DFS(result, candidates, i+1, out, target - candidates[i], target);
        out.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> out;
        DFS(result, candidates, 0, out, target, 0);
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    auto ret = s.combinationSum2(candidates, target);
    for(auto& y : ret) {
        for(auto& x:y) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
