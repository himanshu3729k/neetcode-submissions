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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        ListNode* prev = slow;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        prev = nullptr;

        while(slow){
            ListNode* cnext = slow->next;
            slow->next = prev;
            prev = slow;
            slow = cnext;
        }

        ListNode* tail = prev;
        ListNode* head1 = head;
        while(head1){
            ListNode* next1 = head1->next;
            ListNode* next2 = tail->next;
            prev = tail;

            head1->next = tail;
            tail->next = next1;

            head1 = next1;
            tail = next2;
        }

        if(tail) prev->next = tail;

    }
};
