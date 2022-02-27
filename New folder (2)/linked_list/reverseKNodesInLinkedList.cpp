#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
void list_traversal(node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
        i++;
    }
    cout << endl;
}
void add_starting(node **ptr, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *ptr;
    *ptr = new_node;
}
void add_end(node *ptr, int data)
{
    node *ptr1 = (node *)malloc(sizeof(int));
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr1->data = data;
    ptr1->next = ptr->next;
    ptr->next = ptr1;
}
void add_after(int data, int index, node *head)
{
    int i = 0;
    while (i != index - 1)
    {
        head = head->next;
        i++;
    }
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head->next;
    head->next = ptr;
}
void insert_after(int data, node *ptr)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = ptr->next;
    ptr->next = p;
}

void reverse(node *&head, node *curr, node *prev)
{
    if (curr == NULL)
        return;
    node *frwd = curr->next;
    curr->next = prev;
    prev = curr;
    curr = frwd;
    head = prev;
    reverse(head, curr, prev);
}
// this is when u there are less than k nodes and u want to reverse them also
node *reverseKnodes(node *head, int k)
{
    node *prev = NULL;
    node *nxt = NULL;
    node *curr = head;
    int cnt = k;
    while (curr != NULL && cnt--)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    if (nxt)
        head->next = reverseKnodes(nxt, k);
    return prev;
}
// this is when u there are less than k nodes and u dont want to reverse them also
/*
    // reverse krne ka new way
    /*  only and only if u have head and tail ptr
        step 1: make a prev node pointing to tail;
        step 2:make a temp copy of head->next
        step3: head->next = prev;
        step4:prev = head;
        step5: head = temp;
        
        when we have to stop
            i.e when we reach the tail ptr 
            i.e head ==tail;
    
     ListNode* reverse(ListNode* first,ListNode*last)
     {
         ListNode*prev = last;
         while(first!=last)
         {
             ListNode*temp = first->next;
             first->next = prev;
             prev = first;
             first = temp;
         }
         return prev;
     }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)return NULL;
        // here we find the first and last node after k nodes
        // if there are less number of nodes then return head
        ListNode *node = head;
        for(int i=0;i<k;i++)
        {
            if(!node)return head;
            node = node->next;
        }
        auto newHead = reverse(head,node);
        head->next = reverseKGroup(node,k);
       return newHead;
    }
*/
int main()
{

    node *head;
    node *second;
    node *third;
    node *fourth;
    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
    head->data = 50;
    head->next = second;
    second->data = 39;
    second->next = third;
    third->data = 5;
    third->next = fourth;
    fourth->data = 78;
    fourth->next = NULL;
    add_starting(&head, 69);
    add_starting(&head, 99);
    add_end(head, 12);
    add_after(7, 2, head);
    insert_after(7, second);
    list_traversal(head);
    // reverse(head, head, NULL);
    head = reverseKnodes(head, 2);
    list_traversal(head);
    return 0;
}