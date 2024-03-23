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

 ListNode* Rev(ListNode* head){
    ListNode* prev=NULL;
    while(head!=NULL){
            ListNode* nextNode=head->next;
            head->next=prev;
            prev=head;
            head=nextNode;
    }
    return prev;
 }
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        // while(tail!=NULL){tail=tail->next;}
        // while(head==tail){

        // }
        if(head==NULL||head->next==NULL){
            return;
        }
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*  secondHalf=Rev(slow->next);
        slow->next=NULL;
        ListNode* current =head;
//merging first half and second half
        while(secondHalf!=NULL){
            ListNode* temp1=current->next;
            ListNode* temp2=secondHalf->next;
            current->next=secondHalf;
            secondHalf->next=temp1;
            current=temp1;
            secondHalf=temp2;
        }
        

    }
};