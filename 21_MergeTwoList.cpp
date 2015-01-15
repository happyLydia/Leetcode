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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        bool up = true,already=false;
        ListNode * ptr1 = l1, *ptr2=l2, *head=NULL,* curptr=NULL;
       
        while(ptr1->next)
        {
            if(ptr1->next->val > ptr1->val){
                up = true;
                already=true;
                break;
            }
            else if (ptr1->next->val < ptr1->val){
                up=false;
                already=true;
                break;
            }
            ptr1 = ptr1->next; 
        }
        
        while(!already && ptr2->next)
        {
            if(ptr2->next->val > ptr2->val){
                up = true;
                already=true;
                break;
            }
            else if (ptr2->next->val < ptr2->val){
                up=false;
                already=true;
                break;
            }
            ptr2 = ptr2->next; 
        }
        
        ptr1 = l1;
        ptr2 = l2;
        
        if((ptr1->val < ptr2->val && up) || (ptr1->val > ptr2->val && !up)){
            head = ptr1;
            curptr = ptr1;
            ptr1 = ptr1->next;
        }else{
            head = ptr2;
            curptr=ptr2;
            ptr2 = ptr2->next;
        }
        while(ptr1 && ptr2)
        {
            if((ptr1->val < ptr2->val && up) || (ptr1->val > ptr2->val && !up)){
                curptr->next = ptr1;
                curptr = curptr->next;
                ptr1 = ptr1->next;
            }else {
                curptr->next = ptr2;
                curptr = curptr->next;
                ptr2 = ptr2->next;
            }
        }

        if(ptr1)
        {
            curptr->next = ptr1;
        }else if(ptr2)
        {
            curptr->next = ptr2;
        }
        
        return head;
    }
};