#include "list.h"

/**
 * add_node_end - Add node to end of circular doubly linked list
 * @list: Pointer to address of list head
 * @str: String to put in new node
 * 
 * Return: Pointer to new node on success, NULL on failure
 */
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

/**
 * add_node_begin - Add node to beginning of circular doubly linked list
 * @list: Pointer to address of list head
 * @str: String to put in new node
 * 
 * Return: Pointer to new node on success, NULL on failure
 */
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
