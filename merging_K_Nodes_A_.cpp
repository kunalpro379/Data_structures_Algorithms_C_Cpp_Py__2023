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

 //
 //time complexity O(k^2 * n),
 //
class Solution {
public:
ListNode* mergeTwo(ListNode* list1, ListNode* list2){
  if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        ListNode* ans=0;
        if(list1->val<list2->val){
            ans=list1;
            list1->next=mergeTwo(list1->next,list2);

        }
        else{
            ans=list2;
            list2->next=mergeTwo(list1,list2->next);
        }
        return ans;

}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      while(lists.size()>1){
        ListNode* a=lists.back();
        lists.pop_back();
        ListNode* b=lists.back();
        lists.pop_back();
        ListNode* merged=mergeTwo(a,b);
        lists.push_back(merged);
      }
        if(lists.empty()){
          return NULL;
        }
        else{
          return lists[0];
        }
    }
};
