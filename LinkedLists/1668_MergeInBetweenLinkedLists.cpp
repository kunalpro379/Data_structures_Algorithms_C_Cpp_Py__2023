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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // ListNode* ptr=list1;
        // ListNode* ptr2=ptr->next;
        // for(int i=0;i<a-1;i++){ptr=ptr->next;}
        // for(int i=0;i<b-a+1;i++){ptr2=ptr2->next;}
        // ptr->next=list2;
        // while(list2->next)
        //     list2=list2->next;
        // list2->next=ptr2;

        // return list1;

      
        ListNode *currNode = list1;
        int index = 0;
        while(index < a-1){
            currNode = currNode->next;
            index++;
        }
        ListNode *front = currNode;
        while(index < b+1){
           currNode = currNode->next;
           index++;
        }
        ListNode *rear = currNode;
        ListNode *secondListTail = list2, *secondListHead = list2;
        while(secondListTail->next != NULL)secondListTail = secondListTail->next;
        front->next = secondListHead;
        secondListTail->next = rear;
        return list1;
    

    }
};