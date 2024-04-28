#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node*next,*prev;
}node;
node* insertAtHead(node* head,int val){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data=val;
    if(head == NULL){
        newnode->next = newnode->prev = NULL;
        return newnode;
    }
    newnode->next = head;
    newnode->prev = NULL;
    head -> prev = newnode;
    head = newnode;
    return head;
}
node *insertAtTail(node* head,int val){
    if(head==NULL){
        return insertAtHead(head,val);
    }
    node* rt = head;
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data=val;
    while(head->next){
        head=head->next;
    }
    head -> next = newnode;
    newnode->prev = head;
    newnode->next = NULL;
    return rt;
}
node* insertAtPosition(node*head,int position,int val){
    if(position==1){
        return insertAtHead(head,val);
    }
    node*rt = head;
    int i = 1;
    while(i!=position-1){
        head = head->next;
        i++;
    }
    if(head->next==NULL){
        return insertAtTail(rt,val);
    }
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->prev = head;
    newnode->next = head->next;
    head->next->prev = newnode;
    head ->next = newnode;
    return rt;
}
void printLinkedList(node* head){
    // printf("printing head\n");
    while(head){
        printf("%d ",head->data);
        head = head->next;
    }
}
node *deleteAtHead(node* head){
    if(!head){
        return NULL;
    }
    node* dl = head;
    head = head->next;
    head->prev=NULL;
    free(dl);
    return head;
}
node* deleteAtTail(node*head){
    if(!head)return NULL;

    if(!(head->next)){
        free(head);
        return NULL;
    }
    node* rt = head;
    while(head->next->next){
        head = head->next;
    }
    node* dl = head->next;
    head->next = NULL;
    free(dl);
    return rt;
}
node* deleteAtPosition(node*head,int position){
    if(position==1){
        return deleteAtHead(head);
    }
    int i = 1;
    node* rt = head;
    while(i!=position-1){
        head = head->next;
        i++;
    }
    if(head->next->next==NULL){
        return deleteAtTail(rt);
    }
    node* dl = head->next;
    // printf("deleting %d",head->next->next->data);
    head->next = head->next->next;
    dl->next->prev = head;
    free(dl);
    // printf("returing\n");
    return rt;
}

int main(){
    node * head = NULL;
    head = insertAtHead(head,4);
    head = insertAtTail(head,78);
    head = insertAtHead(head,74);
    head = insertAtPosition(head,3,100);
    printLinkedList(head);
    // printf("deleting\n");
    // head = deleteAtHead(head);   
    // printLinkedList(head);
    // head = deleteAtTail(head);   
    // printf("\n");
    // printLinkedList(head);
        head = deleteAtPosition(head,1);   
    printf("\n");
    printLinkedList(head);
    return 0;
}