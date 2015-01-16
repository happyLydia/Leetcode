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
    void reorderList(ListNode *head) {
        
        if(!head)
            return;
        
        ListNode * sptr=head, *fptr=head;
        
        while(fptr && fptr->next)
        {
            sptr = sptr->next;
            fptr = fptr->next->next;
        }
  
        ListNode * newhead = NULL;
        ListNode * tpnode = NULL;
		tpnode = sptr;
        sptr = sptr->next;
		tpnode->next=NULL;
        
        while(sptr)
        {
            tpnode = sptr->next;
            sptr->next = newhead;
            newhead = sptr;
            sptr = tpnode;
        }
        
        sptr = head;
        
        ListNode* tpnode2=NULL;
        while(newhead)
        {
            tpnode = sptr->next;
			tpnode2 = newhead->next;

            sptr->next = newhead; 
            newhead->next = tpnode;

			newhead = tpnode2;

			sptr = sptr->next->next;
        }
        
        return;
        
    }
};