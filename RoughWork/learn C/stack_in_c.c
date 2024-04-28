#include<stdio.h>
#include<conio.h>

typedef struct{
    void **ptr;
    int top;
    int maxsize;
}stack; 

stack* createStack(){
    stack* stk = (stack*)malloc(sizeof(stack));
    stk->top=-1;
    stk->ptr=(void**)malloc(sizeof(void*)*100);
    stk->maxsize = 100;
}
void push(stack*stk,int val){
   if(stk->top==stk->maxsize-1){
      stk->ptr = realloc(stk->ptr,stk->maxsize+stk->maxsize/2);
   }
   stk->top++;
   *((stk->ptr)+stk->top) = malloc(sizeof(2));
}
int main(){
    
    return 0 ;
}