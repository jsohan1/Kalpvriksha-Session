#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node node;

struct node{
    int data;
    node* next;
};

node* insertionAtHead(int val,node*head){
    node * newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = head;
    return newnode;
}
node* insertionAtTail(int val,node* head){
    if(head==NULL){
        head = insertionAtHead(val,head);
        return head;
    }
    node* rt = head;
    while(head->next!=NULL){
        head = head->next;
    }
    head->next = (node*)malloc(sizeof(node));
    head->next->data = val;
    head->next->next = NULL;
    return rt;
}
node* insertionAtPoint(int val,int position,node*head){
    if(position==1){
        head = insertionAtHead(val,head);
        return head;
    }
    int i = 1;
    node* rt = head;
    while(i!=position-1){
        i++;
        head = head->next;
    }
    node * newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    node * temp = head->next;
    head->next = newnode;
    newnode->next = temp;
    return head;
}
void printLinkedList(node* head){
    while(head){
        printf("%d ",head->data);
        head = head->next;
    }
}
node* deleteAtHead(node* head){
    if(!head){return NULL;}
    else{
        node * dl = head;
        head = head -> next;
        free(dl);
        return head;
    } 
}
node* deleteAtTail(node* head){
    node *rt = head;
   if(!head)return NULL;
   if(head->next==NULL){
        free(head);
        return NULL;
   }
   while(head->next->next){
        head = head -> next;
   }   
    node* del = head-> next;
    head->next = NULL;
    free(del);
    return rt;
}
node* deleteatposition(node*head,int position){
    if(position=1){
        return deleteAtHead(head);
    }
    node*rt = head;
    int i = 1;
    while(i!=position-1){
        i++;
        head = head->next;
    }
    node * del = head->next;
    head -> next = head -> next -> next;
    free(del);
    return rt;
}

typedef struct stack stack;
typedef struct stack{
    node* head;
    int top;
}; 

stack* createStack(){
    stack * stk = (stack*)malloc(sizeof(stack));
    stk->head = NULL;
    stk->top = -1;
}
void push(stack*stk,int val){
    stk->head = insertionAtHead(val,stk->head);
    stk->top++;
}
void pop(stack*stk){
    if(stk->top==-1){
        printf("warning : stack is already empty\n");
        return ;
    }
    stk->head = deleteAtHead(stk->head);
    stk->top--;
}
int peek(stack* stk){
    return stk->head->data;
}
int isEmpty(stack* stk){
    return stk->top==-1;
}
int size(stack* stk){
    return stk->top+1;
}
int main(){
    stack * stk = createStack();
    push(stk,1);
    push(stk,2);
    printf("%d\n",peek(stk));
    pop(stk);
    printf("%d\n",peek(stk));

}