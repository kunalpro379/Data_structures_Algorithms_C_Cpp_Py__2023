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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Fhead=l1;
        ListNode*  Shead=l2;
        ListNode* dumbAss=new ListNode();
        ListNode* curr=dumbAss;
        int Cary=0;
    while(Fhead!=NULL|| Shead!=NULL||Cary){
                int sum=(Fhead?Fhead->val:0)+(Shead?Shead->val:0)+(Cary);
                Cary=sum/10;
                curr->next=new ListNode(sum%10);
                curr=curr->next;
                if(Fhead) Fhead=Fhead->next;
                if(Shead) Shead=Shead->next;

    }
    return dumbAss->next;

    }
};