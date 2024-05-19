#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define File	
#define null NULL

/*if you have doubt why are we using malloc
instead of just declaring node n; n.data = data; n.next = h; return &n;
because local variable will get deleted and hence that address(&n)
is of no use*/

// 😬😬😬 ONE thing remaining is to reverse a list in place
typedef struct _node
{
	int data;
	struct _node *next;
} node;

typedef node *Header;

node *create_node() {
	node *p;
	p = (node *)malloc(sizeof(node));
	return p;
}

int Traverse(Header h) {
	int n = 0;
	if(h==null) return 0;
	while (h) {
		printf("%d, ", h->data );
		h = h->next;
		n++;
	}
	printf("\n");
	return n;
}


node *To_empty(){
	Header p = null;
	// p = create_node();
	return p;
}


node *Insert_begin(Header h, int data) {
	Header p = create_node();
	p->data = data;
	p->next = h;
	return p;
}


node *Insert_end(Header h, int data) {
	Header p = create_node();
	p->data = data;
	p->next = NULL;
	if(h == NULL) return p;
	Header temp = h;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = p;
	return h;
}


node *Insert_sorted(Header h,int data){
	Header p,q;
	p = create_node();
	p->data = data;
	p->next = NULL;
	q = h;	
	if(!h) return p;
	if(data<= h->data){
		p->next = h;
		return p;
	}
	while((q->next!=null) && (q->next)->data < data){
		q = q->next;
	}
	if(q->next == NULL){
		q->next = p;
		return h;
	}
	Header temp;
	temp = q->next;
	q->next = p;
	p->next = temp;
	return h;
}

// Great example of recursion
void Reverse(Header h){
	if(h == null) return;
	Reverse(h->next);
	printf("%d, ",h->data);
}

node *Delete(Header h,int data){
	Header q = h;
	if(h == null) return null;
	if(data == h->data){
		h = h->next;
		free(q);
		return h;
	}
	while(q->next!=null && data!=q->next->data){
		q = q->next;
	}
	if(q->next == null) return h;
	Header temp = q->next;
	q->next = q->next->next;
	free(temp);
	return h;
}


// split the odd ones and even ones in different links
void Split(Header h, Header *r_odd, Header *r_even){
	Header temp_odd = NULL, temp_even = NULL;
	if(h == null){
		*r_odd = *r_even = null;
		return;
	}
	Header o,e;
	while(h){
		if((h->data)%2){
			if(temp_odd==null)
				temp_odd = o = h;
			else{
				o->next = h;
				o = o->next;
			}
		}
		else{
			if(temp_even==null)
				temp_even = e = h;
			else{ 
				e->next = h;
				e = e->next;
			}
		}
		h= h->next;
	}
	if(o) o->next = NULL;
	if(e) e->next = NULL;
	*r_odd = temp_odd;
	*r_even = temp_even;
	return;

}

node *Join(Header h1, Header h2){
	Header h,t;
	if(h1 == null && h2 == null) return null;
	if(h1 == null) return h2;
	if(h2 == null) return h1;
	if(h1->data <= h2->data){
		h = t = h1;
		h1 = h1->next;
	}
	else{
		h = t =h2;
		h2 = h2->next;
	}
	while(h1 || h2){
		if(h1 == null){
			t->next = h2;
			break;
		}
		if(h2 == null){
			t->next = h1;
			break;
		}
		if(h1->data <= h2->data){
			t->next = h1;
			t = t->next;
			h1 = h1->next;
		}
		else{
			t->next =h2;
			t = t->next;
			h2 = h2->next;
		}
	}
	return h;
}

int main() {
	srand(time(0));

#ifdef File
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


//Testing

	Header h = NULL;
	int size;
	printf("size = %d\n",Traverse(h));


	/*node s1 = {3};
	node s2 = {4};
	h = &s1;
	size = Traverse(h);
	s1.next = &s2;
	size = Traverse(h);
	h = Insert_begin(h, 34);
	size = Traverse(h);
	h = Insert_end(h, 34);
	size = Traverse(h);
	h = To_empty();
	size = Traverse(h);
	h = Insert_end(h,10);
	size = Traverse(h);
	h = To_empty();
	h = Insert_begin(h, 9);
	size = Traverse(h);
	h = To_empty();*/


	for (int i = 0; i < 10; ++i)
	{
		int temp = rand()%100 + 1;
		h = Insert_sorted(h,temp);
		// Traverse(h);
	}
	size = Traverse(h);
	h = Insert_sorted(h,50);
	size = Traverse(h);
	// Reverse(h);
	printf("size = %d\n", size);
	h = Delete(h,50);
	printf("size = %d\n", Traverse(h));
	printf("\n");


	Header odd = NULL,even = NULL;
	Split(h,&odd,&even);

	//now see that the original h is changed it now depends on whether the first element is odd or even
	// printf("size = %d\n", Traverse(h));
	printf("size_odd = %d\n", Traverse(odd));
	printf("size_even = %d\n", Traverse(even));

	h = Join(odd,even);
	printf("size = %d\n", Traverse(h));
	// printf("size_odd = %d\n", Traverse(odd));
	// printf("size_even = %d\n", Traverse(even));
	return 0;
}