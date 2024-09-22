#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

list_head * new_list(void) {
    /*
        returns a list_head struct
        conatins the starting of node and the length of list;
    */
    list_head *list=(list_head *)malloc(sizeof(list_head));
    list->node_ptr=NULL;
    list->length=0;
    return list;
} 

list_node * new_node( int val) {
    /*
        allocate space for node
        node contains value val and has next and prev to NULL by default
        in case prev is null then it is the first node after head

    */
    list_node *node=(list_node*) malloc(sizeof(list_node));
    node->next=NULL;
    node->prev=NULL;
    node->value=val;
    return node;

}

int list_append(list_head *head, int num) {
    /*
        Append the item in the linked list at last!

    */ 
    list_node *n=new_node(num); // a new node with num assigned
    if(head->length==0) {
        head->node_ptr=n;
        head->length+=1;
        return 1; // 1 for true
    }
    list_node *l=head->node_ptr;
    while(l->next!=NULL) {
        l=l->next;
    }

    n->prev=l;
    l->next=n;
    head->length+=1;
    return 1;    
}
list_node *list_get(list_head *head, unsigned int index) {
    /*
        returns a pointer to the node at index of head
    */

    if(index>=head->length) return 0;   //return 0 if out of index;



    list_node *n=head->node_ptr;

    for(int i=0;i<index;++i)
        n=n->next;
    
    return n;
    
}

void print_list(list_head *head) {
    /*
        Prints the linked list in order
        Utilises the list_get() function
    */
    for(int i=0;i<head->length;i++)
        printf("%d  ", list_get(head, i)->value);
    printf("\n");
}



void free_list(list_head *head) {
    list_node *n=head->node_ptr;
    list_node *l;
    free(head);
    while(n!=NULL) {
        l=n->next;
        free_node(n);
        n=l;
    }
}