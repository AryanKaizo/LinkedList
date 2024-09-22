#include <stdio.h>
#include "linked_list.h"

int main(int argc, char const *argv[])
{
    list_head *list=new_list();

    for(int i=0;i<10;++i) {
        list_append(list, i);
    }

    print_list(list);
    
    return 0;
}
