#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node* next;
}node;

typedef struct{
    node * head;
    int top;
}stack;

stack* createstack(){
    stack* stk = (stack*)malloc(sizeof(stack));
    stk->head = NULL;
    stk->top=-1;
    return stk;
}
void push(stack*stk,int val){
    node* temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->next = stk->head;
    stk->head = temp;
    stk->top++;
}
void pop(stack*stk){
    if(!stk->head){
        printf("WARNING : Stakc already empty\n");
        return;
    }
    stk->top--;
    node* fr = stk->head;
    stk->head = stk->head->next;
    free(fr);
}
int isEmpty(stack* stk){
    return stk->top == -1;
}
int peek(stack *stk){
   if(isEmpty(stk)){
      printf("Waring : Stack is empty\n Unexpected value returned\n");
      return rand();
   }
   return stk->head->val;
}
int size(stack*stk){
    return stk->top+1;
}
int main(){
    stack *stk = createstack();
    printf("pop\n");
    pop(stk);
    printf("Push 20\n");
    push(stk,20);
    printf("Push 25\n");
    push(stk,25);
    printf("Push 90\n");
    push(stk,90);
    printf("Pop\n");    
    pop(stk);
    printf("Peek : %d\n",peek(stk));
    printf("Isempty : %d\n",isEmpty(stk));
    printf("size : %d",size(stk));

    return 0 ;
}