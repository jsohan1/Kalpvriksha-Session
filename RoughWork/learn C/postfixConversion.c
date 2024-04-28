#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char val;
    struct node *next;
} node;

typedef struct
{
    node *head;
    int top;
} stack;

stack *createstack()
{
    stack *stk = (stack *)malloc(sizeof(stack));
    stk->head = NULL;
    stk->top = -1;
    return stk;
}
void push(stack *stk, char val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->val = val;
    temp->next = stk->head;
    stk->head = temp;
    stk->top++;
}
void pop(stack *stk)
{
    if (!stk->head)
    {
        printf("WARNING : Stakc already empty\n");
        return;
    }
    stk->top--;
    node *fr = stk->head;
    stk->head = stk->head->next;
    free(fr);
}
int isEmpty(stack *stk)
{
    if (stk->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char peek(stack *stk)
{
    if (isEmpty(stk))
    {
        printf("Waring : Stack is empty\n Unexpected value returned\n");
        return rand();
    }
    return stk->head->val;
}
char size(stack *stk)
{
    return stk->top + 1;
}

char *postConversion(char *infix)
{
    stack *stk = createstack();
    int ind = 0;
    char *postfix = (char *)calloc(sizeof(char), 100);
    for (int a = 0; a < 100 && infix[a] != '\0'; a++)
    {
        // printf("at : %d",a);
        if (infix[a] >= '0' && infix[a] <= '9')
        {
            postfix[ind] = infix[a];
            ind++;
        }
        else
        {
            if (infix[a] == '(')
            {
                push(stk, infix[a]);
            }
            else
            {
                if (infix[a] == ')')
                {
                    while( !isEmpty(stk)&&peek(stk) != '(')
                    {
                        postfix[ind] = peek(stk);
                        // printf("add and pop the %c\n",peek(stk));
                        pop(stk);
                        if(peek(stk)=='('){
                            // printf("next is (");
                        }
                        ind++;
                    }
                    pop(stk); 
                }
                else
                {
                    int val;
                    if (infix[a] == '+' || infix[a] == '-')
                    {
                        // printf("out operrtor at %d\n", a);
                        while (!isEmpty(stk)&&peek(stk)!='(')
                        {
                            postfix[ind] = peek(stk);
                            // printf("operrtor\n");
                            pop(stk);
                            ind++;
                        }
                        push(stk, infix[a]);
                    }
                    else
                    {
                        while (!isEmpty(stk) && (peek(stk) == '*' || peek(stk) == '/')&&peek(stk)!='(')
                        {
                            postfix[ind] = peek(stk);
                            pop(stk);
                            ind++;
                        }
                        push(stk, infix[a]);
                    }
                }
            }
        }
    }
    while (!isEmpty(stk))
    {
        postfix[ind] = peek(stk);
        pop(stk);
        ind++;
    }
    postfix[ind] = '\0';
    return postfix;
}
int main()
{
    char *infix = (char *)malloc(sizeof(char) * 100);
    scanf("%s", infix);
    char *postfix = postConversion(infix);
    printf("\n%s\n", postfix);
    // printf("%d",strlen(postfix));
    // for(int a = 0 ; a < strlen(postfix); a++){

    //     printf("%c ",postfix[a]);
    // }
    return 0;
}