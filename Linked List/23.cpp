//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node* root) {
    Node* temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head->next==NULL)return head;
        vector<int> v;
        Node* a = head;
        while(a!=NULL)
        {
            v.push_back(a->data);
            a=a->next;
        }
        vector<int> st;
        for(int i=0;i<v.size();i++)
        {
            bool flag=false;
            for(int j=i+1;j<v.size();j++)
            {
                if(v[j]>v[i])
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                st.push_back(v[i]);
            }
        }
        
        Node* ans = new Node(st[0]);
        Node* b = ans;
        for(int i=1;i<st.size();i++)
        {
            b->next  = new Node(st[i]);
            b=b->next;
        }
        return ans;
        // your code goes here
    }
    
};




//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }
        Solution ob;
        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Node* result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node* root) {
    Node* temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head->next==NULL)return head;
        vector<int> v;
        Node* a = head;
        while(a!=NULL)
        {
            v.push_back(a->data);
            a=a->next;
        }
        vector<int> st;
        for(int i=0;i<v.size();i++)
        {
            bool flag=false;
            for(int j=i+1;j<v.size();j++)
            {
                if(v[j]>v[i])
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                st.push_back(v[i]);
            }
        }
        
        Node* ans = new Node(st[0]);
        Node* b = ans;
        for(int i=1;i<st.size();i++)
        {
            b->next  = new Node(st[i]);
            b=b->next;
        }
        return ans;
        // your code goes here
    }
    
};




//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }
        Solution ob;
        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Node* result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends
