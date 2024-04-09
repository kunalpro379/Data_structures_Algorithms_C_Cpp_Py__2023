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
            ListNode* curr=head;
            ListNode* next=NULL;
            ListNode* prev=NULL;
            int count=0;
            ListNode* temp=head;
            for (int i =0;i<k;i++) {//cheak if at least k nodes left int the list
                if(!temp){return head;}//less than k
                temp=temp->next;
            }  
            while(curr!=NULL&&count<k){//rev first k nodes
                next=curr->next;//store next node of current node
                curr->next=prev;
                prev=curr;
                curr =next;
                ++count;
            }
            if(next!=NULL){
                head->next=reverseKGroup(next,k);
            }
            return prev;
    }
};