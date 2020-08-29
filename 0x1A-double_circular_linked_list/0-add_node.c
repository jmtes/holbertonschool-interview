#include "list.h"

List *add_node_end(List **list, char *str)
{
  printf("Inside add end\n");
  List *new_node = NULL;
  char *new_str = NULL;

  if (!list || !(*list) || !str)
  {
    printf("uh oh\n");
    return NULL;
  }

  new_node = malloc(sizeof(List));
  if (!new_node)
    return NULL;

  new_str = strdup(str);
  if (!new_str)
  {
    free(new_node);
    return NULL;
  }

  new_node->str = new_str;
  new_node->next = *list;
  new_node->prev = (*list)->prev;
  (*list)->prev = new_node;
  new_node->prev->next = new_node;

  return new_node;
}

List *add_node_begin(List **list, char *str)
{
  printf("inside node begin\n");
  List *new_node = NULL;
  char *new_str = NULL;

  if (!list || !(*list) || !str)
  {
    printf("uh oh\n");
    return NULL;
  }

  new_node = malloc(sizeof(List));
  if (!new_node)
    return NULL;

  new_str = strdup(str);
  if (!new_str)
  {
    free(new_node);
    return NULL;
  }

  new_node->str = new_str;
  new_node->next = *list;
  new_node->prev = (*list)->prev;
  (*list)->prev = new_node;
  new_node->prev->next = new_node;

  *list = new_node;
  return new_node;
}
