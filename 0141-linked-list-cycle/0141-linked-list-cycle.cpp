/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode *> s;
        ListNode * cur = head;
        while(cur){
            if(s.count(cur))return true;
            s.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};