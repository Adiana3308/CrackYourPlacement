void reverselist(Node** head)
{
    Node *prev = NULL, *curr = *head, *next;
 
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void rearrange(Node** head, Node* last)
{
    if (!last)
        return;
    rearrange(head, last->next);
    if (!(*head)->next)
        return;

    if ((*head) != last && (*head)->next != last) {
        Node* tmp = (*head)->next;
        (*head)->next = last;
        last->next = tmp;
        *head = tmp;
    }
    else {
        if ((*head) != last)
            *head = (*head)->next;
        (*head)->next = NULL;
    }
}
