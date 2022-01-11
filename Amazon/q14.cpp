//link to the question: https://practice.geeksforgeeks.org/problems/burning-tree/1/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void parent(Node *root,unordered_map<Node*,Node*>&mp)
 {
     if(!root)
     return;
     queue<Node*>q;
     q.push(root);
     while(!q.empty())
     {
         Node *t=q.front();
         q.pop();
         if(t==root)
         mp[t]=NULL;
         if(t->left)
         {
             q.push(t->left);
             mp[t->left]=t;
         }
         if(t->right)
         {
             q.push(t->right);
             mp[t->right]=t;
         }
     }
 }
  void findnode(Node *root,int target,Node *&res)
  {
      if(!root)
      return;
      if(root->data==target)
      res=root;
      findnode(root->left,target,res);
      findnode(root->right,target,res);
  }
   int minTime(Node* root, int target) 
   {
      if(!root)
      return 0;
      unordered_map<Node*,Node*>mp;
      parent(root,mp);
      Node *res=NULL;
      findnode(root,target,res);
      queue<Node*>q;
      q.push(res);
      int dist=0;
      set<Node*>s;
      while(!q.empty())
      {
          int n=q.size();
          while(n--)
          {
             Node *t=q.front();
             q.pop();
             if(t->left&&s.find(t->left)==s.end())
             {
                 q.push(t->left);
                 s.insert(t->left);
             }
             if(t->right&&s.find(t->right)==s.end())
             {
                 q.push(t->right);
                 s.insert(t->right);
             }
             if(mp[t]&&s.find(mp[t])==s.end())
             {
                 q.push(mp[t]);
                 s.insert(mp[t]);
             }
          }
          dist++;
      }
      return dist-1;
   }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends