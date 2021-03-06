/**
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

    示例：

    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
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
        ListNode* l3=new ListNode;ListNode *p;
        p=l3;int carry=0;
        int tem=l1->val+l2->val;
        p->val=tem%10+carry;
        if(tem>=10) carry=1;
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL||l2!=NULL)
        {
            int n1=0,n2=0;
            if(l1) 
            {
                n1=l1->val;
                l1=l1->next;
            }
            if(l2) {
                n2=l2->val;
                l2=l2->next;
            }
            int tem=n1+n2+carry;
            ListNode *a=new ListNode(tem%10);
            p->next=a;
            p=a;
            carry=tem/10;
        }
        if(carry==1)
        {
            ListNode *a=new ListNode(1,nullptr);
            p->next=a;
            p=a;
        }
        p->next=NULL;
        return l3;
    }
};