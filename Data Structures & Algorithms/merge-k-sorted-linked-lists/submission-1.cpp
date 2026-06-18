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
        vector<int> list1;

        for(int i=0;i<lists.size();i++){
            ListNode* list2 = lists[i];
            while(list2){
                list1.push_back(list2->val);
                list2 = list2->next;
            }
        }
        
        sort(list1.begin(), list1.end());

        ListNode* temp = new ListNode();
        ListNode* res = temp;

        for(int x:list1){
            res->next = new ListNode(x);
            res = res->next;
        }

        res = temp->next;
        delete temp;

        list1.clear();

        return res;
    }
};