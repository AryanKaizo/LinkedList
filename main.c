/*
    A file to test the linked list functions

*/

#include <stdio.h>
#include <string.h>

#include "linked_list.h"

int main(int argc, char const *argv[])
{
    list_head *list=new_list();
    int p;

    for(int i=0;i<1000;++i) {
        list_append(list, i);
    }

    print_list(list);
    free_list(list);    
    return 0;
}
