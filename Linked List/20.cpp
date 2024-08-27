    Node* subtract(Node* l1, Node* l2) {
        // Remove leading zeros
        l1 = removeLeadingZeros(l1);
        l2 = removeLeadingZeros(l2);

        // Reverse both linked lists
        l1 = reverse(l1);
        l2 = reverse(l2);

        // Determine which linked list represents the larger number
        Node* larger = getLarger(l1, l2);

        Node* result = nullptr;
        Node* prev = nullptr;
        int borrow = 0;

        // Traverse both linked lists simultaneously and subtract
        while (l1 != nullptr || l2 != nullptr) {
            int val1 = (l1 != nullptr) ? l1->data : 0;
            int val2 = (l2 != nullptr) ? l2->data : 0;

            int diff = val1 - val2 - borrow;

            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }

            // Create a new node for the result
            Node* newNode = new Node(diff);

            if (result == nullptr) {
                result = newNode;
            }
            else {
                prev->next = newNode;
            }
            prev = newNode;

            // Move to the next nodes
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        // Reverse the result linked list
        result = reverse(result);

        return result;
    }
