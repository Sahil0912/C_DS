#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define File
#define null NULL

typedef struct _node
{
	int data;
	struct _node *next;
	
}node;


typedef struct {
	node *front;
	node *back;
}queue;



//This is new way to returning a struct
queue Init(){
	return (queue){null,null};
}


queue enqueue(queue q,int data){
	node *p = (node *)malloc(sizeof(node));
	p->data = data;
	p->next = NULL;
	if(q.back == NULL) return (queue){p,p};
	else{
		q.back->next = p;
		return (queue){q.front,p};
	}
}

queue dequeue(queue q){
	if(q.front == NULL) return (queue){NULL,NULL};
	else{
		node *p = q.front;
		q.front = q.front->next;
		free(p);
		return (queue)q;
	}
}
int Front(queue q){
	if(q.front == NULL){
		printf("Queue is empty (returning -1)\n");
		return -1;
	}
	else return q.front->data;
}


int Back(queue q){
	if(q.front == NULL){
		printf("Queue is empty (returning -1)\n");
		return -1;
	}
	else return q.back->data;
}


int main(){
#ifdef File
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    queue q;
    q = Init();
    q = enqueue(q,31);
    q = enqueue(q,139014);
    q = enqueue(q,8342);
    printf("%d\n", Front(q));
    printf("%d \n",Back(q));
    q = dequeue(q);
    printf("%d\n", Front(q));
    printf("%d \n",Back(q));
    q = dequeue(q);
    printf("%d\n", Front(q));
    printf("%d \n",Back(q));
    q = dequeue(q);
    printf("%d\n", Front(q));
    printf("%d \n",Back(q));   
    return 0;
}