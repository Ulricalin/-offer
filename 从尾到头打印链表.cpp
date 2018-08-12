/*
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> mystack;
        ListNode *p = head;
        while (p != NULL) {
            mystack.push(p->val);
            p = p->next;
        }
        vector<int> ans;
        while(!mystack.empty()) {
            ans.push_back(mystack.top());
            mystack.pop();
        }
        return ans;
    }
};