//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    bool isAnagram(vector<int> v1,vector<int> v2){
        if(v1.size()!=v2.size()) return false;
        else{
            map<int,int> m;
            for(int i=0;i<v1.size();i++){
                m[v1[i]]++;
                m[v2[i]]--;
            }
            for(pair<int,int> p:m){
            if(p.second!=0) return false;
        }
         return true;
        }
        
       
    }
    bool areAnagrams(Node *root1, Node *root2)
    {
       queue<Node*> q1,q2;
       q1.push(root1);
       q2.push(root2);
       while(q1.empty()==false and q2.empty()==false){
           int c1 = q1.size();
           int c2 = q2.size();
        
           vector<int> v1;
           vector<int> v2;
          
           while(c1>0 and c2>0){
               c1--;
               c2--;
                  Node* f1 = q1.front();
                  Node* f2 = q2.front();
                   q1.pop();
                   q2.pop();
                   v1.push_back(f1->data);
                   v2.push_back(f2->data);
                    
                   if(f1->left!=NULL) q1.push(f1->left);
                   if(f1->right!=NULL) q1.push(f1->right);
                   if(f2->left!=NULL) q2.push(f2->left);
                   if(f2->right!=NULL) q2.push(f2->right);
                 
                   
           }
            if(!isAnagram(v1,v2)) return false;
       }
      return true; 
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends