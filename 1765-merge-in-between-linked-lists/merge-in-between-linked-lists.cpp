class Solution {
public:
    ListNode* mergeInBetween(ListNode* head1, int a, int b, ListNode* head2) {
        ListNode* temp1=head1;
        ListNode* a1=NULL;
        ListNode* a2=NULL;
        ListNode* b1=NULL;
        a--;
        b++;
        while(1)
        {
            if(a==0)
            {
                a1=temp1;
            }
            if(b==1)
            {
                a2=temp1;
            }
            if(b==0)
            {
                b1=temp1;
                break;
            }
            temp1=temp1->next;
            a--;
            b--;
        }
        a1->next=NULL;
        a1->next=head2;
        a2->next=NULL;
        ListNode* temp2=head2;
        while(temp2)
        {
            if(temp2->next==NULL)
            {
                break;
            }
            temp2=temp2->next;
        }
        temp2->next=b1;
        return head1;
    }
};