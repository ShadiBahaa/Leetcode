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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode * cur = head;
        int sz = 0;
        while (cur){
            sz++;
            cur = cur->next;
        }
        if (n == sz){
            ListNode *tmp = head;
            head = head->next;
            //free(tmp);
            tmp = nullptr;
        }else {
            ListNode* current = head;
            ListNode* previous = nullptr;
            int cnt = sz;
            while (current){
                if (cnt == n){
                    break;
                }else {
                    previous = current;
                    current = current->next;
                }
                cnt--;
            }
            previous->next = current->next;
            //free(current);
            //current = nullptr;
        }
        return head;
    }
};