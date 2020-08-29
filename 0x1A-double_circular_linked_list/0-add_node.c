#include "list.h"

List *add_node_end(List **list, char *str)
{
  printf("Inside add end\n");
  List *new = malloc(sizeof(List));
  char *new_str = strdup(str);

  if (!list || !(*list) || !str || !new || !new_str)
  {
    printf("uh oh\n");
    return NULL;
  }

  new->str = new_str;
  new->next = *list;
  new->prev = (*list)->prev;
  (*list)->prev = new;
  new->prev->next = new;

  return new;
}

List *add_node_begin(List **list, char *str)
{
  printf("inside node begin\n");
  List *new = malloc(sizeof(List));
  char *new_str = strdup(str);

  if (!list || !(*list) || !str || !new || !new_str)
  {
    printf("uh oh\n");
    return NULL;
  }

  new->str = new_str;
  new->next = *list;
  new->prev = (*list)->prev;
  (*list)->prev = new;
  new->prev->next = new;

  *list = new;
  return new;
}
