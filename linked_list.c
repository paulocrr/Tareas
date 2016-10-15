#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
struct node *head;
struct node *head2;
struct node *create_list(struct node *head,int arr[],int n){
    struct node *next;
    struct node *cur,*prev;
    head = malloc(sizeof(struct node));
    next = malloc(sizeof(struct node));
    head -> val = arr[0];
    prev = head;
    int i = 1;
    for(; i<n;++i){
        cur = malloc(sizeof(struct node));
        cur -> val = arr[i];
        prev -> next = cur;
        prev = cur;
    }
    prev->next = NULL;
    return head;
}
void print_list(struct node *head){
    struct node *t;
    t = head;
    while(t != NULL){
        printf("%d\n",t->val);
        t = t->next;
    }
}
int count_list(struct node *head){
    struct node *t;
    t = head;
    int i = 0;
    while(t != NULL){
        ++i;
        t=t->next;
    }
    return i;
}
void delete_node(int key){
    struct node *prev,*cur;
    prev = head;
    cur = head ->next;
    while(cur!=NULL){
        if(cur->val == key){
            prev->next=cur ->next;
            free(cur);
            break;
        }
        prev = cur;
        cur = cur->next;

    }
}
void insert_begin(int v){
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    new_node->val=v;
    new_node->next=head;
    head = new_node;

}
void insert_middle(int v,struct node *head){
    struct node *new_node;
    struct node *t,*t2;
    t=head;
    new_node = malloc(sizeof(struct node));
    int len = count_list(head);
    new_node ->val=v;
    int j = 0;
    for(;j<(len/2);++j){
        t=t->next;
    }
    t2=t->next;
    t->next = new_node;
    new_node->next=t2;


}
void sort_list(struct node *head){
   struct node *cur, *next;
	int size = count_list(head);
	int i, j, value;

	for(i = 0; i < count_list(head); i++, size-- ){
		cur = head ;
		next = head -> next ;

		for(j = 1; j < size; j++ ){

			if(cur -> val > next -> val){
				value = cur -> val ;
				cur -> val = next -> val;
				next -> val = value ;
			}

			cur = cur -> next;
			next = next -> next;

		}
	}
}
void concatenate_list(struct node *head, struct node *head2){
    int len = count_list(head);
    int i = 0;
    while(i<len-1){
        //printf("hola\n");
        head = head->next;
        ++i;
    }
    head->next = head2;
}
main(){
    int arreglo [5] = {4,2,3,5,1};
    int arreglo2[4]={7,6,8,9};
    head = create_list(head,arreglo,5);
    head2=create_list(head2,arreglo2,4);
   // delete_node(2);
   // insert_begin(33);
   // insert_middle(44,head);
   // sort_list(head);
    concatenate_list(head,head2);
    print_list(head);
    //print_list(head2);


}
