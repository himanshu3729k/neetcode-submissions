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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];

        ListNode* res = lists[0];
        for(int i=1;i<lists.size();i++){
            ListNode* temp = new ListNode();
            ListNode* list1 = res;
            res = temp;
            ListNode* list2 = lists[i];

            while(list1 && list2){
                if(list1->val <= list2->val){
                    res->next = list1;
                    list1 = list1->next;
                }

                else{
                    res->next = list2;
                    list2 = list2->next;
                }

                res = res->next;
            }

            if(list1) res->next = list1;
            else res->next = list2;

            res = temp->next;
            delete temp;
        }
        
        return res;
    }
};
