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
    ListNode* reverseLL(ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    ListNode* newhead = reverseLL(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}
     ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Reverse the list
        ListNode* rHead = reverseLL(head);
        ListNode* temp = rHead;
        ListNode* prev = NULL;
        int cnt=0;
        if(n==1){
            rHead = rHead->next;
            delete temp;
            return reverseLL(rHead);
        }
        while(temp!=NULL){
            cnt++;
            if(cnt==n){
                prev->next = prev->next->next;
                delete temp;
                break;
            }
            prev = temp;
            temp=temp->next;
        }
        return reverseLL(rHead);
    }
};