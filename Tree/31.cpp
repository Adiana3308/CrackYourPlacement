//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    unordered_set<int>s;
    void check(Node*root,int &ans)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            // if 1 is present and 2 is also present in the tree then it is a deadend
            if(root->data==1 && s.find(2)!=s.end())
            {
                ans=25;  //just a random number
                return ;
            }
            // if both the previous value to the number and the next value present
            else if(s.find(root->data-1)!=s.end() && s.find(root->data+1)!=s.end())
            {
                ans=25;
                return ;
            }
        }
        s.insert(root->data);
        
        check(root->left,ans);
        check(root->right,ans);
        
    }
    
    bool isDeadEnd(Node *root)
    {
        int ans=0;
        check(root,ans);
        if(ans==25)
        {
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends
