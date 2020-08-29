#include "list.h"

List *add_node_end(List **list, char *str)
{
  List *new_node = NULL;
  char *new_str = NULL;

  if (!list || !str)
    return NULL;

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

  if (!(*list))
  {
    new_node->next = new_node;
    new_node->prev = new_node;
    *list = new_node;
  }
  else
  {
    new_node->next = *list;
    new_node->prev = (*list)->prev;
    (*list)->prev = new_node;
    new_node->prev->next = new_node;
  }

  return new_node;
}

List *add_node_begin(List **list, char *str)
{
  List *new_node = NULL;
  char *new_str = NULL;

  if (!list || !str)
    return NULL;

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

  if (!(*list))
  {
    new_node->next = new_node;
    new_node->prev = new_node;
  }
  else
  {
    new_node->next = *list;
    new_node->prev = (*list)->prev;
    (*list)->prev = new_node;
    new_node->prev->next = new_node;
  }

  *list = new_node;
  return new_node;
}
