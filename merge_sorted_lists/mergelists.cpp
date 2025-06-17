#include <iostream>
#include <math.h>

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 






class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        //sets a dummy header node that points to null 
        ListNode dummy(0); //dummy node to start the head
        //creates a pointer call tail that points to the dummy head
        //we'll use this tail to assign each new node
        ListNode* tail = &dummy;
        //while the lists are not pointing at null keep traversing 
        while(list1 != nullptr || list2 != nullptr){
            
            //check the lists individuually and assign the values to variables
            //if the list is null then set value to max so the other one is picked
            int val1 = (list1 != nullptr) ? list1->val : INT_MAX;
            int val2 = (list2 != nullptr) ? list2->val : INT_MAX;
            
            //if value one is less than value 2 
            //then the tail points to value 1
            if(val1 < val2){
                tail->next = list1;
                list1 = list1->next;
            //else the tail points to value 2
            }else{
                tail->next = list2;
                list2 = list2->next;
            }
            //need this to set tail to be the next node so we can continue
            tail = tail->next;
        }
        return dummy.next;
    }
};