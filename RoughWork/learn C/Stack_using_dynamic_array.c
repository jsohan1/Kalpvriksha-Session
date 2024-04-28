#include <stdio.h>
#include <stdlib.h>


typedef struct{
   int *ptr;
   int top ;
   int maxsize;
}stack;

stack* createstack(){
   stack* stk = (stack*)malloc(sizeof(stack)*1);
   stk->ptr = (int*)malloc(sizeof(int)*100);
   stk->top=-1;
   stk->maxsize=100;
   return stk;
}

void push(stack*stk,int val){
   if(stk->top==stk->maxsize-1){
      stk->ptr = realloc(stk->ptr,stk->maxsize+stk->maxsize/2);
      if(stk->ptr==NULL){
         printf("Warning : Stack OVerflowed\n");
         return;
      }
   }
   stk->top++;
   *((stk->ptr)+stk->top) = val;
}

void pop(stack*stk){
   if(stk->top==-1){
      printf("Warning : Stack is already empty\n");
      return;
   }
   stk->top--;
}

int isEmtpy(stack*stk){
   return (stk->top==-1);
}
int size(stack*stk){
   return stk->top+1;
}
int peek(stack *stk){
   if(isEmtpy(stk)){
      printf("Waring : Stack is empty\n Unexpected value returned\n");
      return rand();
   }
   return *(stk->ptr+stk->top);
}
int main(){
   stack *stk = createstack() ;
   printf("pushed 78\n");
   push(stk,78);
   printf("pushed 90\n");
   push(stk,90);
   printf("popped\n");
   pop(stk);
   printf("peek element is : %d\n",peek(stk));
   printf("Size of Stack is : %d\n",size(stk));
   printf("is it empty or not : %d\n",isEmtpy(stk));
   return 0;
}  