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
        ListNode* res = new ListNode();
        ListNode* ans = res;

        while(list1 && list2){
            ListNode* nxt1 = list1->next;
            ListNode* nxt2 = list2->next;

            if(list1->val <= list2->val){
                res->next = list1;
                list1 = nxt1;
            }

            else{
                res->next = list2;
                list2 = nxt2;
            }

            res = res->next;
            // if(!ans && res->val!=1000) ans = res;
        }

        if(list1) res->next = list1;
        else if(list2) res->next = list2;

        // if(!ans) return res->next;

        return ans->next;
    }
};
