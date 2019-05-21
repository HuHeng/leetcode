#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using node_pair = std::pair<ListNode*, int>;
        auto cmp = [](node_pair l, node_pair r){return l.first->val > r.first->val;};
        std::priority_queue<node_pair, std::vector<node_pair>, decltype(cmp)> q(cmp);

        ListNode* current = NULL;
        ListNode** phead = &current;
        ListNode** p = phead;

        int len = lists.size();

        for(int i = 0; i < len; ++i) {
            if(lists[i] != NULL){
                q.push({lists[i], i});
                lists[i] = lists[i]->next;
            }
        }

        while(!q.empty()) {
            auto t = q.top();
            *p = new ListNode(t.first->val);
            p = &((*p)->next);
            int index = t.second;
            q.pop();
            if(lists[index] != NULL){
                q.push({lists[index], index});
                lists[index] = lists[index]->next;
            }
        }
        return *phead;
    }
};

int main()
{
    Solution s;
    auto p1_1 = new ListNode(1);
    auto p1_2 = p1_1->next = new ListNode(4);
    auto p1_3 = p1_2->next = new ListNode(5);

    auto p2_1 = new ListNode(1);
    auto p2_2 = p2_1->next = new ListNode(3);
    auto p2_3 = p2_2->next = new ListNode(4);

    auto p3_1 = new ListNode(2);
    auto p3_2 = p3_1->next = new ListNode(6);

    std::vector<ListNode*> lists{p1_1, p2_1, p3_1};

    auto xx = s.mergeKLists(lists);
    for(; xx; xx=xx->next){
        std::cout << xx->val << " ";
    }
    std::cout << endl;
    return 0;
}
