listint_t *find_listint_loop(listint_t *head) {
  listint_t *fast = NULL;
  listint_t *slow = NULL;

  if (!head) return (NULL);

  fast = head;
  slow = head;

  while (fast->next->next && slow->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      slow = head;

      while (fast != slow) {
        fast = fast->next;
        slow = slow->next;

        if (fast == slow) return (slow);
      }
    }
  }

  return (NULL);
}
