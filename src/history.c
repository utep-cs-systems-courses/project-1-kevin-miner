#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Start root node with default values */
List *init_history() {
  List *list = (List *)malloc(sizeof(List));
  Item *item = (Item *)malloc(sizeof(Item));
  list->root = item;

  item->id = 0;
  item->str = "--Root--\n";
  item->next = NULL;
  return list;
}

/* Add a new node to the list */
void add_history(List *list, char *str) {
 
  Item *curr = list->root;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  int i = curr->id;
  curr->next = (Item *) malloc(sizeof(Item));
  curr->next->id = i+1;
  curr->next->str = str;
  curr->next->next = NULL;
}

/* Retrieve a specific item on the list */
char *get_history(List *list, int id) {
  if (list == 0)
    return NULL;
  
  Item *p = list->root;
  while (p->id != id) {
    p = p->next;
  }
  printf("%s", p->str);
  return p->str;
}

/* Print list */
void print_history(List *list) {
  Item *p = list->root;
  while (p != NULL) {
    printf("%s", p->str);
    p = p->next;
  }
}

/* Free memory for list */
void free_history(List *list) {
  Item *p = list->root;
  Item *curr;
  while (p != NULL) {
    curr = p;        //Temporal holder so not to loose position
    free(p);
    p = p->next;      
  }
  free(list);
}

