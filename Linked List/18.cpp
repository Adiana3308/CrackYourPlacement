Node *segregateEvenOdd(Node *head) {

    // Starting node of list having even values.
    Node *evenStart = nullptr;
    Node *evenEnd = nullptr;

    // Same for the odd list.
    Node *oddStart = nullptr;
    Node *oddEnd = nullptr;

    // Node to traverse the list.
    Node *currNode = head;

    while (currNode != nullptr) {
        int val = currNode->data;

        // If current value is even, add it to the
        // even values list.
        if (val % 2 == 0) {
            if (evenStart == nullptr) {
                evenStart = currNode;
                evenEnd = evenStart;
            }
            else {
                evenEnd->next = currNode;
                evenEnd = evenEnd->next;
            }
        }
        else {
          
            // If current value is odd, add it to 
              // the odd values list.
            if (oddStart == nullptr) {
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else {
                oddEnd->next = currNode;
                oddEnd = oddEnd->next;
            }
        }

        // Move to the next node.
        currNode = currNode->next;
    }

    // If either odd list or even list is empty, 
      // return the head as is.
    if (oddStart == nullptr || evenStart == nullptr)
        return evenStart;

    // Add odd list after even list.
    evenEnd->next = oddStart;
    oddEnd->next = nullptr;

    // Return the head of the modified list.
    return evenStart;
}

void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}
