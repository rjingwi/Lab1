// list/list.c
//
// Implementation for linked list.
//
// Ryan Jingwi

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <string.h>

node_t* node_alloc(elem val){
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
  new_node->value = val;
  new_node->next = NULL;
  return new_node;
}

void free_node(node_t* n){
  free(n);
}

list_t* list_alloc(){
  list_t* new_list = (list_t*) malloc(sizeof(list_t));
  new_list->head = NULL;
  return new_list;
}

void list_free(list_t* l){
  free(l);
}

void list_print(list_t *l){
  node_t* current_node = l->head;
  while(current_node != NULL){
    printf("%d\n",current_node->value);
    current_node = current_node->next;
  }
}

int list_length(list_t *l){
  int length = 0;
  node_t* current_node = l->head;
  while(current_node != NULL){
    length++;
    current_node = current_node->next;
  }
  return length;
}

void list_add_to_back(list_t *l, elem value){
  if(list_length(l) == 0){
    l->head = node_alloc(value);
  }
  else{
    node_t* current_node = l->head;
    while(current_node->next != NULL){
      current_node = current_node->next;
    }
    current_node->next = node_alloc(value);
  }
}

void list_add_to_front(list_t *l, elem value){
  node_t* old_head = l->head;
  l->head = node_alloc(value);
  l->head->next = old_head;
}

void list_add_at_index(list_t *l, elem value, int index){
  if(index>list_length(l)+1){
    list_add_to_back(l,value);
  }
  else if(index == 0){
    list_add_to_front(l,value);
  }
  else{
    node_t* addition = node_alloc(value);
    int current_index = 0;
    node_t* current_node = l->head;
    while(current_index != index-1){
    current_node = current_node->next;
    current_index ++;
    }
    addition->next = current_node->next;
    current_node->next = addition;
  }
}

elem list_remove_from_back(list_t *l){
  if (list_length(l) == 0){
    return -1;
  }
  node_t* current_node = l->head;
  int current_index = 0;
  while(current_node->next->next!= NULL){
    current_node = current_node->next;
    current_index ++;
  }
  elem popped_value = current_node->next->value;
  current_node->next = NULL;
  return popped_value;
}

elem list_remove_from_front(list_t *l){
  if (list_length(l) == 0){
    return -1;
  }
  elem popped_value = l->head->value;
  l->head = l->head->next;
  return popped_value;
}

elem list_remove_at_index(list_t *l, int index){
  if (list_length(l) == 0){
    return -1;
  }
  else if(index == 0){
    return list_remove_from_front(l);
  }
  else{
    node_t* current_node = l->head;
    int current_index = 0;
    while(current_index != index-1){
    current_node = current_node->next;
    current_index ++;
    }
    node_t* new_next = current_node->next->next;
    elem popped_value = current_node->next->value;
    current_node->next = NULL;
    current_node->next = new_next;
    return popped_value;
  }

}

bool list_is_in(list_t *l, elem value){
  node_t* current_node = l->head;
  while(current_node->next!= NULL){
    if(current_node->value == value){
      return true;
    }
    current_node = current_node->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index){
  if(index>list_length(l)-1){
    return -1;
  }
  int current_index = 0;
  node_t* current_node = l->head;
  while(current_index != index){
    current_node = current_node->next;
    current_index++;
  }
  return current_node->value;
}

int list_get_index_of(list_t *l, elem value){
  int current_index = 0;
  node_t* current_node = l->head;
  while(current_node != NULL){
    if (current_node->value == value){
      return current_index;
    }
    current_node = current_node->next;
    current_index++;
  }
  return -1;
}