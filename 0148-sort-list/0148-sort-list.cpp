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
    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeLL(ListNode* L1, ListNode* L2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(L1!=NULL && L2!=NULL){
            if(L1->val<L2->val){
                temp->next = L1;
                temp = L1;
                L1=L1->next;
            }
            else{
                temp->next = L2;
                temp = L2;
                L2 = L2->next;
            }
        }
        while(L1!=NULL){
           temp->next = L1;
            temp = L1;
            L1=L1->next; 
        }
        while(L2!=NULL){
            temp->next = L2;
            temp = L2;
            L2 = L2->next;
        }
        temp = temp->next;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
       if(head==NULL||head->next==NULL){
        return head;
       }
       ListNode* middle = findmid(head);
       ListNode* right = middle->next;
       middle->next = NULL;
       ListNode* left = head;

       left = sortList(left);
       right = sortList(right);
       return mergeLL(left,right);
    }
};