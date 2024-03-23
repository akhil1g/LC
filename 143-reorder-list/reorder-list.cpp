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
        ListNode* temp=head;
        ListNode* pre=NULL;
        while(temp!=NULL)
        {
            ListNode* next=temp->next;
            temp->next=pre;
            pre=temp;
            temp=next;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        if(head==NULL)
        return;
        if(head->next==NULL)
        return;
        ListNode* temp=head;
        ListNode* mid=head;
        int i=0;
        while(temp!=NULL)
        {
            if(i&1)
            mid=mid->next;
            i++;
            temp=temp->next;
        }
        ListNode* head1=mid->next;
        mid->next=NULL;
        head1=rev(head1);
        temp=head;
        while(temp!=NULL&&head1!=NULL)
        {
            ListNode* next=temp->next;
            ListNode* hnext=head1->next;
            head1->next=temp->next;
            temp->next=head1;
            temp=next;
            head1=hnext;
        }
    }
};