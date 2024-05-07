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
ListNode* rev(ListNode* head)
{
    
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            
        }
        return prev;
}
    ListNode* doubleIt(ListNode* head) {
        head=rev(head);
        ListNode *temp=head;
        int c=0;
        ListNode* tail=NULL;
        while(temp)
        {
            int val=temp->val;
            if(((2*val)+c)>9)
            {
                temp->val=((2*val)+c)%10;
                c=1;
            }
            else
            {
                temp->val=(2*val)+c;
                c=0;
            }
            tail=temp;
            temp=temp->next;
        }
        if(c==1)
        {

            ListNode *newnode=new ListNode(c);
            tail->next=newnode;
        }
        head=rev(head);
        return head;
    }
};