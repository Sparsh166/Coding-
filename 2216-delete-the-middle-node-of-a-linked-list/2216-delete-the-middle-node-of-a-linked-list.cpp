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
    ListNode* mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* target = mid(head);
        while(temp!=NULL){
            if(head==NULL||head->next==NULL){
                return NULL;
            }
            if(temp==target){
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp=temp->next;
        }
        return head;
    }
};