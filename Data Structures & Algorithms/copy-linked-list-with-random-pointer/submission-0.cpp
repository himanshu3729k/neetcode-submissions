/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = new Node(0);
        Node* res = temp;
        unordered_map<Node*,Node*> mp;
        Node* curr = head;

        while(curr){    
            res->next = new Node(curr->val);
            res = res->next;
            mp[curr] = res;
            curr = curr->next;
        }

        res = temp->next;
        temp = res;

        while(head){
            temp->random = mp[head->random];
            temp = temp->next;
            head = head->next;
        }

        delete temp;
        return res;
    }
};
