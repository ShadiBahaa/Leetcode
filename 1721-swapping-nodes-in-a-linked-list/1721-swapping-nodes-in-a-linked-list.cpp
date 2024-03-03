/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *tmp = head;
        int cnt = 0;
        while (tmp){
            cnt++;
            tmp = tmp->next;
        }
        int i = 1;
        ListNode * first = head;
        ListNode * second = head;
        while (true){
            if (i == k){
                break;
            }
            first = first->next;
            i++;
        }
        i = 1;
        while (true){
            if (i == cnt-k+1){
                break;
            }
            second = second->next;
            i++;
        }
        int val = first->val;
        first->val = second->val;
        second->val = val;
        return head;
    }
};