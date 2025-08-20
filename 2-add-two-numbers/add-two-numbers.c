/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    int a1,a2,d1=0,d2=0;
    struct ListNode *temp1=l1,*temp2=l2;
    int a,at1=0,at2=0,ao;
    int flag1=0,flag2=0;
    while(temp1!=0)
    {
       d1++;
       temp1=temp1->next;
    }
     while(temp2!=0)
    {
       d2++;
       temp2=temp2->next;
    }
    temp1=l1,temp2=l2;
    if(d1>=d2)
    {
    while(temp1!=0||temp2!=0)
    {
        if(temp1==0)
        a1=0;
        else 
        a1=temp1->val;
        if(temp2==0)
        a2=0;
        else
        a2=temp2->val;
        a=a1+a2+at1;
        ao=a%10;
        at2=a/10;
        temp1->val=ao;
        at1=at2;
        if(temp1!=0)
        temp1=temp1->next;
        if(temp2!=0)
        temp2=temp2->next;
    }
    if(at1!=0)
    {
    temp1=l1;
    while(temp1!=0)
    {
        if(temp1->next==0)
        break;
        temp1=temp1->next;
    }
    temp1->next=l2;
    temp2=l2;
    temp2->val=at1;
    temp2->next=NULL;
    }
    return l1;
    }
    else 
    {
        while(temp1!=0||temp2!=0)
    {
        if(temp1==0)
        a1=0;
        else 
        a1=temp1->val;
        if(temp2==0)
        a2=0;
        else
        a2=temp2->val;
        a=a1+a2+at1;
        ao=a%10;
        at2=a/10;
        temp2->val=ao;
        at1=at2;
        if(temp1!=0)
        temp1=temp1->next;
        if(temp2!=0)
        temp2=temp2->next;
    }
    if(at1!=0)
    {
    temp2=l2;
    while(temp2!=0)
    {
        if(temp2->next==0)
        break;
        temp2=temp2->next;
    }
    temp2->next=l1;
    temp1=l1;
    temp1->val=at1;
    temp1->next=NULL;
    }
    return l2;
    }
}