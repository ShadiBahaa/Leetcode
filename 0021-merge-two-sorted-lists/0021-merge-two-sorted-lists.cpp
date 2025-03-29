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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * ptr1 = list1;
        ListNode * ptr2 = list2;
        ListNode * ret = new ListNode(-1);
        ListNode * head = ret;
        bool first = true;
        while(ptr1 && ptr2){
            if(ptr1->val <= ptr2->val){ 
            ret->next = new ListNode(ptr1->val);
            if(first){
                head = ret;
                first = false;
            }
            ptr1 = ptr1->next;
        }else {
            ret->next = new ListNode(ptr2->val);
            if(first){
                head = ret;
                first = false;
            }
            ptr2 = ptr2->next;
        }
        ret = ret->next;
    }
    while(ptr1){
        ret->next = new ListNode(ptr1->val);
            ptr1 = ptr1->next;
            ret = ret->next;
    }
    while(ptr2){
        ret->next= new ListNode(ptr2->val);
            ptr2 = ptr2->next;
            ret = ret->next;
    }
    return head->next;
    }
};