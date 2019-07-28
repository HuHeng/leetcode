#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) 
            return head;
        vector<ListNode*> v;
        ListNode* c = head;
        for(; c!=NULL; c = c->next) {
            v.push_back(c);
        }
        int index = v.size() - k % v.size();
        if(index == v.size())
            return head;
        //ListNode* ans = v[index];
        v[index-1]->next = NULL;
        v[v.size()-1]->next = head;
        return v[index];
    }
};


int main()
{

    Solution s;
    //vector<ListNode> list_node{1,2,3,4,5};
    vector<ListNode> list_node{1};
    for(size_t i = 0; i < list_node.size(); ++i) {
        if(i != list_node.size()-1) {
            list_node[i].next = &list_node[i+1];
        } else {
            list_node[i].next = NULL;
        }
    }
    ListNode* c = s.rotateRight(&list_node[0], 0);
    for(; c != NULL; c = c->next) {
        std::cout << c->val << " ";
    }
    std::cout << std::endl;
    return 0;
}
