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

    ListNode* middleNode(ListNode* head) {
        //int len=getlen(head);
        if(!head||!head->next){
            return head;
        }
        ListNode* fast=head;
        ListNode* solow=head;
        while(
            fast&& fast->next
        ){
            solow=solow->next;
            fast =fast ->next->next;
        }
       
                return solow;

    }
};