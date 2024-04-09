/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int lendiff(ListNode* head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL){return NULL;}
        ListNode* ListA=headA;
        ListNode* ListB=headB;
        int lenA=lendiff(ListA);
        int lenB=lendiff(ListB);
        while(lenA>lenB){
                ListA=ListA->next;
                lenA--;
        }
                while(lenA<lenB){
                ListB=ListB->next;
                lenB--;
        }
                while(ListA!=ListB){
                ListA=ListA->next;
                ListB=ListB->next;
               
        }
        return ListA;
    }
};