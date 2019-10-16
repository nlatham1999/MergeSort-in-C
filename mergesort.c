//Nicholas Latham
//mergsort with linked lists
//9/9/2019


#include<stdlib.h> 
#include<stdio.h>

//struct for our node
struct node{
	int data;
	struct node * next;
};

//inserts an item into a list
struct node * insertItem(struct node * list,int elem){
	if(list == NULL){
		list  = (struct node*) malloc(sizeof(struct node));
		list->data = elem;
		list->next = NULL;
	}else{
		list->next = insertItem(list->next, elem);
	}
	return list;
}

//prints out the list
void showList(struct node * list){
	if(list == NULL){
		printf("oops");
	}else{
		while(list != NULL){
			printf("%d\n", list->data);
			list = list->next;
		}
	}
}

//takes two lists and merges them
struct node* merge(struct node * head1, struct node * head2){
	struct node *newNode = NULL;
	if(head1 != NULL && head2 != NULL){
		newNode = (struct node*) malloc(sizeof(struct node));
		if(head1->data < head2->data){
			newNode->data = head1->data;
			newNode->next = merge(head1->next, head2);
		}else{
			newNode->data = head2->data;
			newNode->next = merge(head1, head2->next);
		}
	}else{
		if(head1 != NULL){
			newNode = head1;
		}else{
			newNode = head2;
		}
	}
	return newNode;
}

//gets the length of the list
int length(struct node * list){
	if(list == NULL){
		return 0;
	}else{
		return 1 + length(list->next);
	}
}

//breaks up the list and then merges it
struct node* mergesort(struct node* head, int size){
	if(size <= 1){
		return head;
	}
	
	struct node * second = NULL;
	struct node * temp = head;
	
	for(int i = 0; i < (size-1)/2; i++){
		temp = temp->next;
	}
	second = temp->next;
	temp->next=NULL;
	
	head = mergesort(head, length(head));
	second = mergesort(second, length(second));
	
	return merge(head, second);
}
	
		

int main(){

	//create our list
	struct node *list = NULL;
	list = insertItem(list, 1);
	list = insertItem(list, 8);
	list = insertItem(list, 4);
	list = insertItem(list, 0);
	list = insertItem(list, 10);
	list = insertItem(list, 9);
	list = insertItem(list, 2);
	
	//print off unsorted list
	printf("\n unsorted \n");
	showList(list);

	//sort the list
	list = mergesort(list, length(list));
	
	//print off sorted list
	printf("\n sorted \n");
	showList(list);
}
