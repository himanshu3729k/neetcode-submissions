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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        
        int n=0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            n++;
        }

        if(n<k) return head;

        n/=k;

        curr=head;
        ListNode* temp1;
        ListNode* temp2 = new ListNode();
        ListNode* ans = temp2;

        for(int i=0;i<n;i++){
            // ListNode* use = (i%2==0)? temp1:temp2;
            if(i%2==0) temp1 = curr;
            else temp2 = curr;

            ListNode* prev;
            ListNode* nxt;

            for(int j=0;j<k;j++){
                nxt = curr->next;
                if(j>0) curr->next = prev;

                prev = curr;
                curr = nxt;
            }

            if(i%2==0) temp2->next = prev;
            else temp1->next = prev;
        }

        if(n%2) temp1->next = curr;
        else temp2->next = curr;

        curr=ans;
        ans = ans->next;

        delete curr;
        return ans;
    }
};
