void zigZagList(Node* head) 
{ 
    bool flag = true; 
  
    // Traverse linked list starting from head. 
    Node* current = head; 
    while (current->next != NULL) { 
        if (flag) /* "<" relation expected */
        { 
            if (current->data > current->next->data) 
                swap(current->data, current->next->data); 
        } 
        else /* ">" relation expected */
        { 
            if (current->data < current->next->data) 
                swap(current->data, current->next->data); 
        } 
  
        current = current->next; 
        flag = !flag; /* flip flag for reverse checking */
    } 
} 
