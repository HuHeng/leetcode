#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> generatehash(string& str) {
        vector<int> hh(26, 0);
        for(size_t i = 0; i < str.length(); ++i) {
            hh[str[i]-'a']++;
        }
        return hh;
    }

    bool checkthesamegroup(vector<int>& hash_map, vector<int>& hh) {
        //copy
        for(size_t i = 0; i < hh.size(); ++i) {
            if(hash_map[i] != hh[i]) 
                return false;
        }
        return true;

    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<vector<int>> char_hash;
        for(auto& str : strs) {
            bool find = false;
            auto hh = generatehash(str);
            for(size_t i = 0; i < ans.size(); ++i) {
                if(checkthesamegroup(char_hash[i], hh)) {
                    ans[i].push_back(str);
                    find = true;
                    break;
                }
            }
            if(!find) {
                //new group
                vector<string> v;
                v.push_back(str);
                ans.push_back(v);
                //set hash
                char_hash.push_back(hh);
            }
        }

        return ans;
    }
};

int main()
{

    vector<string> ss {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    auto vv = s.groupAnagrams(ss);
    for(auto& v: vv) {
        for(auto& str : v) {
            std::cout << str << "  ";
        }
        std::cout << std::endl;
    }

    return 0;
}
