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
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next =  prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* getKNode(ListNode* temp, int k){
        k-=1;
        while(temp!=NULL&&k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* KthNode = getKNode(temp,k);
            if(KthNode ==NULL){
                if(prev)prev->next = temp;
                break;
            }
            ListNode* newNode = KthNode->next;
            KthNode->next = NULL;
            reverse(temp);
            if(temp==head){
                 head = KthNode;
            }
            else{
                prev->next = KthNode;
            }
            prev = temp;
            temp = newNode;
        }
        return head;
    }
};