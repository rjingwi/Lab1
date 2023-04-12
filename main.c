#include <stdio.h>
#include <stdbool.h>
#include "list.h"

int main() 
{
  
  list_t *mylist;
  mylist = list_alloc();

  printf("Initial length of my list is %d\n",list_length(mylist));
  list_add_to_back(mylist,15);
  list_add_to_back(mylist,4);
  list_add_to_back(mylist,7);
  printf("\nAfter appending some values to the end of the list the length is %d\n",list_length(mylist));
  printf("\nThe values are as follows:\n");
  list_print(mylist);
  printf("\nI will now append the number 50 at the front and 88 at index 2:\n");
  list_add_to_front(mylist,50);
  list_add_at_index(mylist,88,2);
  list_print(mylist);
  printf("\nOne number was removed from front of list: %d",list_remove_from_front(mylist));
  printf("\nOne number was removed from index 1 of list: %d",list_remove_at_index(mylist,1));
  printf("\nOne number was removed from back of list: %d\n",list_remove_from_back(mylist));
  printf("\nNew list is:\n");
  list_print(mylist);
  printf("\nTesting if number 15 is in list. Result is: %d",list_is_in(mylist,15));
  printf("\nTesting if number 64 is in list. Result is: %d\n",list_is_in(mylist,64));
  printf("\nTesting for the number at index 1: %d",list_get_elem_at(mylist,1));
  printf("\nVice versa the index of 4 is: %d\n",list_get_index_of(mylist,4));
  return 0;
}
