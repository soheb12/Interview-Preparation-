#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int data;
    Node* next;
}*head = NULL,*temp = NULL;

Node* get_node(int x)
{
    Node* temp = (Node*)malloc( sizeof(Node) );
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void insert(int x)
{
    Node* temp2 = get_node(x);
    if(head == NULL)
    {head = temp2;temp = head;}
    else
    {
        temp->next = temp2;
        temp = temp2;
    }
}

void reverse(Node **head_ref)
{
    Node *cur = *head_ref;
    Node *prev = NULL,*next = NULL;
    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head_ref = prev;//Coz at the end prev will point at the end of the linked list
}

Node* middle_node(Node *head_ref)
{
    Node *fast_ptr = head_ref, *slow_ptr = head_ref, *prev_slow_ptr = head_ref;
    while(fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        prev_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr;//if nodes are even then SECOND middle node is in slow_ptr and FIRST middle node is in prev_slow_ptr
}

int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        insert(x);
    }
    temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    reverse(&head);//pass the reference so that changes are permanent
    temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    printf("%d\n",middle_node(head)->data);
}
