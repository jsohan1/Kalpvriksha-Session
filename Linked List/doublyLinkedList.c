#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node node;
struct node{
    int data;
    node* next,*prev;
};

node* createNode(int val){
    node* rt = (node*)malloc(sizeof(node));
    rt->next = NULL;
    rt->prev = NULL;
    rt->data=val;
    return rt;
}
node* insertAtHead(node*head,int val){
    node* nd = createNode(val);
    if(head==NULL){
        head = nd;
        return head;
    }
    nd->next = head;
    head->prev = nd;
    head = nd;
    return head;
}
node* insertAtTail(node* head,int val){
    node* nd = createNode(val);
    node* rt = head;
    if(rt == NULL){
        return insertAtHead(head,val);
    }
    while(head->next){
        head = head->next;
    }
    head -> next = nd;
    nd->prev = head;
    return rt;
}
node* insertAtPosition(node* head,int val, int position){
    if(position==1){
        return insertAtHead(head,val);
    }
    node * rt  = head;
    node * nd = createNode(val);
    int i = 1 ;
    while(i!=position-1){
        i++;
        head = head -> next;
    }
    nd->next = head->next;
    head->next->prev = nd;
    head ->next = nd;
    nd->prev = head;
    return rt;
}
node* deleteAtHead(node* head){
    if(head==NULL){
        return NULL;
    }
    node * dl = head;
    head = head ->  next ;
    if(head){head -> prev = NULL;}
    free(dl);
    return head;
}
node* deleteAtTail(node* head){
    if(!head)return NULL;
    if(!(head->next)){
        free(head);
        head = NULL;
        return head;
    }
    node* rt = head;
    while(head->next->next){
        head = head->next;
    }
    node* dl = head -> next;
    head->next = NULL;
    free(dl);
    return rt;
}
node* deleteAtPosition(node* head,int position){
    if(position==1){
        return deleteAtHead(head);
    }
    node* rt = head;
    int i = 1; 
    while(i!=position-1){
        head = head -> next;
        i++;
    }
    node* dl = head->next;
    head->next = head->next->next;
    head->next->prev = head;
    free(dl);
    return rt;
}

void printList(node* head){
    while(head){
        printf("%d ",head->data);
        head = head->next;
    }
}
void printReverseList(node*head){
    if(!head){
        return ;
    }
    while(head->next){
        head = head->next;
    }
    while(head){
        printf("%d ",head->data);
        head = head->prev;
    }
}
void deleteEntireList(node* head){
    while(head){
        node* temp = head;
        head = head->next;
        free(temp);
    }
}
int main(){
   node* head = NULL;
   head = insertAtTail(head,34);
   head = insertAtHead(head,23);
   head = insertAtPosition(head,100,1);
   printList(head);
   printf("\n");
   printReverseList(head);
   head = deleteAtPosition(head,3);
   printf("\n");
   printList(head);
   deleteEntireList(head);
   return 0; 
}