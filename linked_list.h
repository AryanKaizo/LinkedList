#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct list_node {
    /*  
        A list node which can be refrenced by a list_head or a list_node 
        Contains the value of node
     */
    int value;          // the integral value of node
    // double linked list function
    struct list_node *next;    // null if no next
    struct list_node *prev;    // null if previous is list_head
    // if prev is NULL it implies this node is the first node
} list_node;

typedef struct list_head {
    /* The head keeps track of pointer and length of list */
    unsigned int length;
    list_node *node_ptr; // pointer to first node;

} list_head;


list_head * new_list(void); // a new list func returns list_head
list_node * new_node( int); // new_node function returns a new list_node
                            //initializes the node next and prev as null and values as specified

list_node *list_get(list_head *, unsigned int);  //get the list at given index if exist
//return 0 at failure;

int list_append(list_head *, int);  //append to a list
void print_list(list_head *);   //print the list


#endif  // LINKED_LIST_H_