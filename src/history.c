#include "history.h"
#include <stdlib.h>
#include <stdio.h>

List* init_history()
{
  List *newHistory = malloc(sizeof(void *));
  return newHistory;
}

/* Add an item to the end of the LL 
   List* list - the LL
   char* str - string to store. */
void add_history(List *list, char *str)
{
  Item *newItem = malloc(sizeof(void *));
  newItem->str = str;

  if(list->root){
    Item *currentNode = list->root;
    int newID = 2;
    while(currentNode->next){
      currentNode = currentNode->next;
      newID++;
    }
    currentNode->next = newItem;
    newItem->id = newID;
  } else {
    list->root = newItem;
    newItem->id = 1;
  }
}

/* Retrieve string stored in the node with the given id.
   List* list - the LL
   int id - the ID of the string to find. */
char *get_history(List *list, int id)
{
  Item *currentNode;
  if(list->root){
    currentNode = list->root;
  } else {
    return "no root node!";
  }
  while(currentNode){
    if(currentNode->id == id){
      return currentNode->str;
    }
    currentNode = currentNode->next;
  }
  return "no match found!";
}

/* Print the full content of the list */
void print_history(List *list)
{
  Item *currentNode = list->root;
  while(currentNode){
    printf("%d. %s\n", currentNode->id, currentNode->str);
    currentNode = currentNode->next;
  }
}

/* frees items from a linked list */
void free_item(Item *item)
{
  if(item->next){
    free_item(item->next);
  }
  free(item->str);
  free(item);
}

/* Free the history list and the strings it references. */
void free_history(List *list)
{
  if(list->root){
    free_item(list->root);
  }
  free(list);
}
