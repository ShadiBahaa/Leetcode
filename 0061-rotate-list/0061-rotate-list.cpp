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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)return nullptr;
        if (head->next == nullptr)return head;
        ListNode* tail = head;
        int sz = 1;
        while (tail->next != nullptr){
            tail = tail->next;
            sz++;
        }
        k %= sz;
        k = sz - k - 1;
        tail->next = head;
        ListNode* current = head;
        while (k--){
            current = current->next;
        }
        head = current->next;
        current->next = nullptr;
        return head;
    }
};