#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define File
#define null NULL




/*




typedef struct Stack
{
    int data;
    struct Stack *next;
}stack1;
typedef stack1 *node1;


stack1 *create_new(){
    stack1 *p = (stack1 *)malloc(sizeof(stack1));
    return p;
}

stack1 *Push(node1 h, int data){
    node1 n = create_new();
    n->data = data;
    n->next = NULL;
    h->next = n;
    return n;
}

int Top_element(node1 h){
    return h->data;
}

// stack1 *Pop(node h){
    // will be inefficient
// }




*/


typedef struct Stack2
{
    int data;
    struct Stack2 *next;
}stack2;


typedef stack2 *node2;

stack2 *Push2(node2 top, int data){
    node2 p = (stack2 *)malloc(sizeof(stack2));
    p->data = data;
    p->next = top;
    return p;
}

void Pop(node2 *top){
    if(*top == null){
        printf("Stack is Empty!\n");
        return;
    }
    int popped_element = (*top)->data;
    node2 temp = *top;
    if((*top)->next == NULL){
        *top = NULL;
        printf("popped_element = %d\n", popped_element);
        return;
    }
    (*top) = (*top)->next;
    free(temp);
    printf("popped_element = %d\n", popped_element);
    return;
}

void Top_element(node2 top){
    if(top == NULL){
        printf("Empty Stack\n");
        return;
    }
    printf("%d\n", top->data);
}


int main(){
#ifdef File
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
/*
    node1 Head, Tail;
    Tail  = Head;
    Tail = Push(Tail,12);
    int top = Top_element(Tail);
    printf("%d\n", top);
*/



    // see for stack1 pop will be inefficient because we have top set to the end element
    // we will have to traverse the complete list in order to set top to the previous element




    // now coming to stack2 implementation using linked list only




    node2 Top = NULL;
    Top = Push2(Top,2);
    Top_element(Top);
    Top = Push2(Top,3);
    Top = Push2(Top,414);

    Pop(&Top);
    Top_element(Top);

    Pop(&Top);
    Top_element(Top);

    Pop(&Top);
    Top_element(Top);


    Pop(&Top);
    Top_element(Top);
    return 0;
}