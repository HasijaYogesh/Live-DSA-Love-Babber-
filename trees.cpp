// ******* BINARY TREE BUILDING ********
/*
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

int main() {
    
    Node* root = NULL;

    root = buildTree();


    return 0;
}
*/


// ********* LEVEL ORDER TRAVERSAL ********
/*
#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    // initially
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        // Step A
        Node* temp = q.front();
        // Step B
        q.pop();
        if(temp == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            } 
        }
        else {
            // Step C
            cout<<temp->data<<" ";
            // Step D
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Node* root = NULL;

    root = buildTree();

    levelOrderTraversal(root);


    return 0;
}
*/


// ******* INORDER - LNR / PRE ORDER - NLR / POST ORDER - LRN *********
/*
#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

void inOrderTraversal(Node* root) {
    // base case
    if(root == NULL) {
        return;
    }

    // LNR - L means Left part
    inOrderTraversal(root->left);

    // N means current node print
    cout<<root->data<<" ";

    // R means right part
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    // base case
    if(root == NULL) {
        return;
    }

    // NLR

    // N means current node print
    cout<<root->data<<" ";

    // L means left part
    preOrderTraversal(root->left);

    // R means right part
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    // base case
    if(root == NULL) {
        return;
    }

    // LRN
    // L means left part
    postOrderTraversal(root->left);

    // R means right part
    postOrderTraversal(root->right);

    // N means current node print
    cout<<root->data<<" ";
}

int main() {
    


    return 0;
}
*/


// ********* HEIGHT / MAX DEPTH IN TREE *********
/*
#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int ans = max(leftHeight, rightHeight) + 1;

    return ans;
}

int main() {
    
    Node* root = NULL;

    root = buildTree();

    cout<<"Height of tree is "<<height(root)<<endl;

    return 0;
}
*/


// *********** DIAMETER OF TREE **********
/*
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int ans = max(leftHeight, rightHeight) + 1;

    return ans;
}

int diameterOfBinaryTree(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int op1 = diameterOfBinaryTree(root->left); 
    int op2 = diameterOfBinaryTree(root->right); 
    int op3 = height(root->left) + height(root->right);

    int ans = max(op1, max(op2, op3));

    return ans;
}

int main() {
    


    return 0;
}
*/


// ******** CHECK IF TREE BALANCED OR NOT ********
/*
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

int height(Node* root) {
    // base case
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int ans = 1 + max(leftHeight, rightHeight);

    return ans;
}

bool isBalanced(Node* root) {
    // Base case
    if(root == NULL) {
        return true;
    }

    // one case
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int diff = abs(leftHeight - rightHeight);

    bool ans1 = (diff <= 1);

    // recursion
    bool leftans = isBalanced(root->left);
    bool rightans = isBalanced(root->right);

    if(ans1 && leftans && rightans) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    



    return 0;
}
*/


// ****** LOWEST COMMON ANCESTER **********
/*
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {

    //base case
    if(root == NULL) {
        return NULL;
    }    

    // checkfor p and q
    if(root->data == p->data) {
        return p;
    }
    if(root->data == q->data) {
        return q;
    }

    Node* leftAns = lowestCommonAncestor(root->left, p, q);
    Node* rightAns = lowestCommonAncestor(root->right, p, q);

    if(leftAns == NULL && rightAns == NULL) {
        return NULL;
    }
    else if(leftAns != NULL && rightAns == NULL) {
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL) {
        return rightAns;
    }
    else {
        return root;
    }
}

int main() {
    


    return 0;
}
*/


// ********* FIND KTH ANCESTOR OF GIVEN P ********
/*
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

bool findKthAncestor(Node* root, int &k, int p, int& ans) {
    if(root == NULL) {
        return false;
    }

    if(root->data == p) {
        return true;
    }

    bool leftAns = findKthAncestor(root->left, k, p, ans);
    bool rightAns = findKthAncestor(root->right, k, p, ans);

    if(leftAns || rightAns) {
        k--;
    }
    if(k == 0 && ans == -1) {
        ans = root->data;
    }
    return leftAns || rightAns;
}

int main() {
    
    Node* root = NULL;

    root = buildTree();
    int k = 1;
    int p = 4;
    int ans = -1;

    findKthAncestor(root,k,p, ans);
    cout<<"Answer is "<<ans<<endl;
    cout<<"End"<<endl;
    // Sample tree
    // [1,2,4,-1,-1,5,-1,-1,3,-1,-1]


    return 0;
}
*/


// *********** FIND THE PATH IN TREE WITH TARGET SUM *******
/*
#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

void solve(Node* root, int targetSum, int& currSum, vector<int>& path, vector<vector<int>>& ans) {
    // base case
    if(root == NULL) {
        return;
    }

    // leaf node
    if(root->left == NULL && root->right == NULL) {
        // include current leaf node
        path.push_back(root->data);
        currSum += root->data;
        // check for target sum
        if(currSum == targetSum) {
            ans.push_back(path);
        }
        // exclude leaf node
        path.pop_back(root->data);
        currSum -= root->data;
        return;
    }

    // include curr node
    path.push_back(root->data);
    currSum += root->data;

    solve(root->left, targetSum, currSum, path, ans);
    solve(root->right, targetSum, currSum, path, ans);

    // exclude current node
    path.pop_back(root->data);
    currSum -= root->data;
}

vector<vector<int>> pathSum(Node* root, int targetSum) {
    vector<vector<int>> ans;

    int sum = 0;

    vector<int> temp;

    solve(root, targetSum, sum, temp, ans);

    return ans;
}

int main() {
    
    Node* root = NULL;

    root =buildTree();

    vector<vector<int>> ans = pathSum(root, 22);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    } cout<<endl;


    return 0;
}
*/


// ******** MAKE A TREE FROM INOREDER AND PRE ORDER GIVEN VECTORS *********
/*
#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int findPosition(int arr[], int n, int element) {
    for(int i=0; i<n; i++) {
        if(arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// build treee from inorder and preorder traversal
Node* buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, int& preIndex, int inorderStart, int inorderEnd) {
    // base case
    if(preIndex >= size || inorderStart > inorderEnd) {
        return NULL;
    }

    // step A
    int element = preorder[preIndex++];

    Node* root = new Node(element);

    int pos = findPosition(inorder, size, element);

    // step B
    root->left = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart,pos-1);

    // step C
    root->right = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos+1, inorderEnd);

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    // initially
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        // Step A
        Node* temp = q.front();
        // Step B
        q.pop();
        if(temp == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            } 
        }
        else {
            // Step C
            cout<<temp->data<<" ";
            // Step D
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    
    int inorder[] = {40,20,50,10,60,30,70};
    int preorder[] = {10,20,40,50,30,60,70};
    int size = 7;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size-1;

    Node* root = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, inorderEnd);

    cout<<"Printing level order traversal"<<endl;

    levelOrderTraversal(root);

    return 0;
}
*/


// ********* MAKE A TREE FROM INORDER AND POST ORDER GIVEN ARRAY **********
/*
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int findPosition(int arr[], int n, int element) {
    for(int i=0; i<n; i++) {
        if(arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// build treee from inorder and preorder traversal
Node* buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int& postIndex, int size, int inorderStart, int inorderEnd, unordered_map<int,int>& mapping) {
    // base case
    if(postIndex < 0 || inorderStart > inorderEnd) {
        return NULL;
    }

    // step A
    int element = postorder[postIndex];
    postIndex--;
    Node* root = new Node(element);

    // instead of this find position function we will use hash map
    // int pos = findPosition(inorder, size, element);
    int pos = mapping[element];

    // root->right solve first then left
    root->right = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, pos+1, inorderEnd, mapping);
    root->left = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, inorderStart, pos-1, mapping);

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    // initially
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        // Step A
        Node* temp = q.front();
        // Step B
        q.pop();
        if(temp == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            } 
        }
        else {
            // Step C
            cout<<temp->data<<" ";
            // Step D
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void createMapping(unordered_map<int,int>& mapping, int inorder[], int size) {
    for(int i=0; i<size; i++) {
        mapping[inorder[i]] = i;
    }
}

int main() {
    
    int inorder[] = {40,20,10,50,30,60};
    int postorder[] = {40,20,50,60,30,10};
    int size = 6;
    int postIndex = size-1;
    int inorderStart = 0;
    int inorderEnd = size-1;

    unordered_map<int, int> mapping;
    createMapping(mapping, inorder, size);

    cout<<"Building the tree"<<endl;
    Node* root = buildTreeFromPostOrderInOrder(inorder, postorder, size, postIndex, inorderStart, inorderEnd, mapping);
    cout<<"Building done"<<endl;

    // build tree code is correct but printing may have some issue
    cout<<"Printing level order traversal"<<endl;
    levelOrderTraversal(root);

    return 0;
}
*/


// ********** PRINT THE TOP VIEW OF TREE *********
/*
#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

int findPosition(int arr[], int n, int element) {
    for(int i=0; i<n; i++) {
        if(arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// build treee from inorder and preorder traversal
Node* buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int& postIndex, int size, int inorderStart, int inorderEnd, unordered_map<int,int>& mapping) {
    // base case
    if(postIndex < 0 || inorderStart > inorderEnd) {
        return NULL;
    }

    // step A
    int element = postorder[postIndex];
    postIndex--;
    Node* root = new Node(element);

    // instead of this find position function we will use hash map
    // int pos = findPosition(inorder, size, element);
    int pos = mapping[element];

    // root->right solve first then left
    root->right = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, pos+1, inorderEnd, mapping);
    root->left = buildTreeFromPostOrderInOrder(inorder, postorder, postIndex, size, inorderStart, pos-1, mapping);

    return root;
}

void printTopView(Node* root) {
    if(root == NULL) {
        return;
    }

    // create a map for storing horizontal distance -> Top node data
    map<int,int> topNode;

    // Level Order
    // we will store a pair consisting of node and horizontal distance
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // check if cuurrent horizontal distance is stored or not in map
        // this condition is for no value in map till end of map
        if(!topNode[hd]) {
            // create a entry
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    // an appka answer store hua hoga map me
    cout<<"Printing the answer: "<<endl;

    for(auto i: topNode) {
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}

int main() {

    Node* root = buildTree();

    printTopView(root);

    


    return 0;
}
*/


// ********** PRINT THE BOTTOM VIEW OF TREE *********
/*
#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

int findPosition(int arr[], int n, int element) {
    for(int i=0; i<n; i++) {
        if(arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void printBottomView(Node* root) {
    if(root == NULL) {
        return;
    }

    // create a map for storing horizontal distance -> Top node data
    map<int,int> topNode;

    // Level Order
    // we will store a pair consisting of node and horizontal distance
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    // an appka answer store hua hoga map me
    cout<<"Printing the answer: "<<endl;

    for(auto i: topNode) {
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}

int main() {

    Node* root = buildTree();

    printBottomView(root);    


    return 0;
}
*/


// ******** PRINT LEFT VIEW && RIGHT VIEW OF AN TREE ********
/*
#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

void printLeftView(Node* root, int level, vector<int>& ans) {
    if(root == NULL) {
        return;
    }

    if(level == ans.size()) {
        ans.push_back(root->data);
    }

    printLeftView(root->left, level+1, ans);
    printLeftView(root->right, level+1, ans);
}

void printRightView(Node* root, int level, vector<int>& ans) {
    if(root == NULL) {
        return;
    }

    if(level == ans.size()) {
        ans.push_back(root->data);
    }

    printRightView(root->right, level+1, ans);
    printRightView(root->left, level+1, ans);
}

int main() {
    
    Node* root = buildTree();
    // 10 20 30 -1 -1 50 60 -1 -1 70 -1 80 -1 -1 40 -1 90 -1 -1

    // vector<int> ans;
    // printLeftView(root, 0, ans);

    vector<int> ans;
    // 10 20 30 -1 -1 40 60 -1 -1 -1 80 50 -1 70 -1 -1 90 -1 -1
    printRightView(root, 0, ans);

    cout<<"Printing the ans: ";
    for(auto val: ans) {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
*/


// ********** PRINTING THE BOUNDARY OF A TREE *********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

void printLeftBoundary(Node* root) {
    // base case
    // if root is null, go back
    if(root == NULL) {
        return;
    }
    // if root is a leaf node, go back
    if(root->left == NULL && root->right == NULL) {
        return;
    }

    cout<<root->data<<" ";
    if(root->left) {
        printLeftBoundary(root->left);
    }
    else {
        printLeftBoundary(root->right);
    }
}

void printLeafNodes(Node* root) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        cout<<root->data<<" ";
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void printRightBoundary(Node* root) {
    if(root->right == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        return;
    }
    if(root->right) {
        printRightBoundary(root->right);
    }
    else {
        printRightBoundary(root->left);
    }
    cout<<root->data<<" ";
}

void boundaryTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    //step A
    printLeftBoundary(root->left);
    // step B
    printLeafNodes(root);
    // step C
    printRightBoundary(root->right);
}

int main() {
    
    Node* root = buildTree();
    // 10 20 30 -1 -1 40 60 -1 -1 -1 80 50 -1 70 -1 -1 90 -1 -1
    // 10 20 30 -1 -1 50 70 90 -1 -1 80 -1 -1 60 -1 -1 40 -1 100 -1 120 110 -1 -1 130 -1 -1
    boundaryTraversal(root);

    return 0;
}
*/


// ********* FASTEST WAY TO FIN DTHE DIAMETER - TIME COMPLEXITY 0(N) ********
/*
#include <iostream>
using namespace std;
// D is for diameter
int D = 0;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // curret diameter
    int currentD = leftHeight + rightHeight;

    // global diameter
    D = max(D, currentD);

    return max(leftHeight, rightHeight)  + 1;
}

int diameterOfBinaryTree(Node* root) {
    height(root);
    return D;
}

int main() {
    
    Node* root = buildTree();

    cout<<"Diameter is: "<<diameterOfBinaryTree(root)<<endl;

    return 0;
}
*/


// ********** CHECK FOR BALANCED TREE FAST WAY - 0(N) ********** 
/*
#include <iostream>
using namespace std;

bool isBalanced = true;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    // check of current node, is it balanced?
    if(isBalanced && abs(lh-rh) > 1) {
        isBalanced = false;
    }

    return max(lh, rh) + 1;
}

bool isBalancedTree(Node* root) {
    height(root);
    return isBalanced;
}

int main() {

    Node* root = buildTree();

    cout<<"ANswer is: "<<isBalancedTree(root)<<endl;

    return 0;
}
*/


// ********* CHECK IF TWO TREE ATE INDENTICAL / SAME TREE *********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

bool sameTree(Node* p, Node* q) {
    if(!p && !q) {
        return true;
    }

    if(p && q) {
        return (p->data == q->data) && sameTree(p->left, q->left) && sameTree(p->right, q->right);
    }

    return false;
}

int main() {
    
    Node* root1 = buildTree();
    Node* root2 = buildTree();

    // 1 2 -1 -1 3 -1 -1
    cout<<"Answer is: "<<sameTree(root1, root2);

    return 0;
}
*/


// ********** CHECK IF TREE IS SYMMETRIC / MIRROR **********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

bool isMirror(Node* p, Node* q) {
    if(!p && !q) {
        return true;
    }

    if(p && q) {
        return (p->data == q->data) && isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }

    return false;
}

bool isSymmetric(Node* root) {
    return isMirror(root->left, root->right);
}

int main() {
    
    Node* root = buildTree();

    // 1 2 3 -1 -1 4 -1 -1 2 4 -1 -1 3 -1 -1
    cout<<"Answer is: "<<isSymmetric(root);

    return 0;
}
*/


// ********* DIAGONAL TRAVERSAL USING MAP ********
/*
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

void printDiagonalTree(Node* root, unordered_map<int, vector<int>>& map, int level) {
    if(!root) {
        return;
    }

    map[level].push_back(root->data);

    printDiagonalTree(root->left, map, level+1);
    printDiagonalTree(root->right, map, level);
}

int main() {
    
    // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
    Node* root = buildTree();
    unordered_map<int, vector<int>> map;
    printDiagonalTree(root, map, 0);

    vector<int> level0 = map[0];
    vector<int> level1 = map[1];
    vector<int> level2 = map[2];

    for(auto val: level0) {
        cout<<val<<" ";
    } cout<<endl;
    for(auto val: level1) {
        cout<<val<<" ";
    } cout<<endl;
    for(auto val: level2) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/


// ********* DIAGONAL TRAVERSAL USING QUEUE ********
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

vector<int> diagonal(Node* root) {
    vector<int> ans;
    if(!root) {
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        while(temp) {
            ans.push_back(temp->data);
            if(temp->left) {
                // baad me dekhna he
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
}

int main() {
    
    // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
    Node* root = buildTree();
    
    vector<int> ans = diagonal(root);
    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/


// ******** PRINT THE TREEIN ZIG ZAG MANNER **********
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> ans;

    if(!root) {
        return ans;
    }

    bool LtoR = true;

    queue<Node*> q;
    q.push(root);

    if(!q.empty()) {
        int width = q.size();
        vector<int> onelevel(width);

        for(int i=0; i<width; i++) {
            Node* front = q.front();
            q.pop();
            int index = LtoR ? i : width - i - 1;
            onelevel[index] = front->data;
            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }
        // toggle the direction 
        LtoR = !LtoR;
        ans.push_back(onelevel);
    }
    return ans;
}

int main() {
    // 3 9 -1 -1 20 15 26 -1 -1 19 -1 -1 7 -1 -1
    Node* root = buildTree();

    vector<vector<int>> ans = zigzagLevelOrder(root);
    // Some issue in printing, logic is same
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }

    return 0;
}
*/


// ******** TRANSFORM TO SUM TREE **********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

int sum(Node* root) {
    if(!root) {
        return 0;
    }

    if(!root->left && !root->right) {
        int temp = root->data;
        root->data = 0;
        return temp;
    }

    int lsum = sum(root->left);
    int rsum = sum(root->right);

    int temp = root->data;
    root->data = lsum + rsum;
    return root->data + temp;
}

void toSumTree(Node* root) {
    sum(root);
}

int main() {
    
    Node* root = buildTree();
    // 10 -2 8 -1 -1 -4 -1 -1 6 7 -1 -1 5 -1 -1
    toSumTree(root);

    cout<<"Start root value: "<<root->data<<endl;

    return 0;
}
*/


// ********* VERTICAL ORDER TRAVERSAL OF BINARY TREE **********
/*
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

vector<vector<int>> verticalTraversal(Node* root) {
    vector<vector<int>> ans;
    queue<pair<Node*, pair<int,int>>> q; // Node, {row, col}

    q.push({root,{0,0}});
    map<int, map<int, multiset<int>>> mp; // col, -> {row, [x,y,z]}
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        Node*&node = front.first;
        auto&coordinate = front.second;

        int&row = coordinate.first;
        int&col = coordinate.second;

        mp[col][row].insert(node->data);

        if(node->left) {
            q.push({node->left,{row+1, col-1}});
        }
        if(node->right) {
            q.push({node->right,{row+1, col+1}});
        }
    }

    // store final vertical order into vector
    for(auto it: mp) {
        auto&colMap = it.second;
        vector<int> vLine;
        for(auto colMapIt: colMap) {
            auto&mset = colMapIt.second;
            vLine.insert(vLine.end(), mset.begin(), mset.end());
        }
        ans.push_back(vLine);
    }
    return ans;
}

int main() {
    
    Node* root = buildTree();
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    vector<vector<int>> ans = verticalTraversal(root);

    for(int i=0; i<ans.size(); i++) {
        vector<int> temp = ans[i];
        for(int j=0; j<temp.size(); j++) {
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    }


    return 0;
}
*/


// ********** FIND THE TARGET SUM PATH FROM ANY NODE OF THE TREE *********
/*
#include <iostream>
using namespace std;
// global variable for checking root sum
int ans = 0;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

void pathFromOneRoot(Node* root, long long sum) {
    if(!root) {
        return;
    }

    if(sum == root->data) {
        ans++;
    }

    pathFromOneRoot(root->left, sum-root->data);
    pathFromOneRoot(root->right, sum-root->data);
}

int pathSum(Node* root, long long targetSum) {
    if(root) {
        pathFromOneRoot(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right,targetSum);
    }
    return ans;
}

int main() {
    // 5 3 2 -1 -1 -1 2 -1 1 -1 -1
    Node* root = buildTree();
    cout<<"Answer is: "<<pathSum(root, 8)<<endl;


    return 0;
}
*/


// ********** MORRISE TRAVERSAL ********
/*
#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

vector<int> inorderTraversal(Node* root) {
    vector<int>ans;

    Node* curr = root;

    while(curr) {
        // left node is null, then visit it and go right;
        if(curr->left == nullptr) {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        // left node is not null
        else {
            // find the in order predecessor
            Node* pred = curr->left;
            while(pred->right != curr && pred->right) {
                pred = pred->right;
            }

            // if pred right node is null, then go left after establishing link from pred to curr
            if(pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            }
            else {
                // left is already visited, go right after visiting curr node, while removing the link
                pred->right = nullptr;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main() {
    
    Node* root = buildTree();
    vector<int> ans = inorderTraversal(root);
    for(auto val: ans) {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
*/


// ********* FLATTERN THE BINARY TREE INTO LINKED LIST ********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

void flattern(Node* root) {
    Node* curr = root;
    while(curr) {
        if(curr->left) {
            Node* pred = curr->left;
            while(pred->right) {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}

void print(Node* root) {
    while(root) {
        cout<<root->data<<" ";
        root = root->right;
    }
    cout<<endl;
}

int main() {

    // 1 2 3 -1 -1 4 5 -1 -1 -1 6 -1 -1
    Node* root = buildTree();
    flattern(root);
    print(root);


    return 0;
}
*/


// ********** MAXIMUM SUM OF NON ADJACENT NODES IN TREE ***********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

pair<int, int> getMaxSum_helper(Node* root) {
    if(!root) {
        return {0,0};
    }

    auto left = getMaxSum_helper(root->left);
    auto right = getMaxSum_helper(root->right);

    // sum including the node
    int a = root->data + left.second + right.second;

    // sum excluding the node
    int b = max(left.first, left.second) + max(right.first, right.second);

    return {a,b};
}

int getMaxSum(Node* root) {
    auto ans = getMaxSum_helper(root);
    return max(ans.first, ans.second);
}

int main() {
    // 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
    Node* root = buildTree();

    cout<<"Answer is: "<<getMaxSum(root)<<endl;


    return 0;
}
*/


// ******** SUM OF LONGEST BLOODLINE OF A TREE *********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

pair<int,int> height(Node* root) {
    if(!root) {
        return {0,0};
    }

    auto lh = height(root->left);
    auto rh = height(root->right);

    int sum = root->data;
    if(lh.first == rh.first) {
        sum += lh.second > rh.second ? lh.second : rh.second;
    }
    else if(lh.first > rh.first) {
        sum += lh.second;
    }
    else {
        sum += rh.second;
    }

    return {max(lh.first, rh.first) + 1, sum};
}

int sumOfLongRootToLeafPath(Node* root) {
    auto h = height(root);
    return h.second;
}

int main() {
    // 4 2 7 -1 -1 1 6 -1 -1 -1 5 2 -1 -1 3 -1 -1
    Node* root = buildTree();
    cout<<"Answer is: "<<sumOfLongRootToLeafPath(root)<<endl;

    return 0;
}
*/


// ******** MINIMUM TIME TO BURN TREE / BURNING TREE *********
/*
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

Node* makeNodeToParentMappingAndFindTargetNode(Node* root,  unordered_map<Node*, Node*>& parentMap, int target) {
    queue<Node*> q;
    Node* targetNode = 0;
    q.push(root);
    parentMap[root] = 0;
    while(!q.empty()) {
        Node* front = q.front(); 
        q.pop();

        if(front->data = target) {
            targetNode = front;
        }
        if(front->left) {
            q.push(front->left);
            parentMap[front->left] = front;
        }
        if( front->right) {
            q.push(front->right);
            parentMap[front->right] = front;
        }
        return targetNode;
    }
}

int burnTheTree(Node* targetNode,  unordered_map<Node*, Node*>& parentMap) {
    unordered_map<Node*, bool> isBurned;
    queue<Node*> q; // currently set on fire node

    int T = 0;
    q.push(targetNode);
    isBurned[targetNode] = 1;
    while(!q.empty()) {
        int size = q.size();
        bool isFireSpreaded = 0;

        for(int i=0; i<size; i++) {
            Node* front = q.front();
            q.pop();

            if(front->left && !isBurned[front->left]) {
                q.push(front->left);
                isBurned[front->left] = 1;
                isFireSpreaded = 1;
            }
            if(front->right && !isBurned[front->right]) {
                q.push(front->right);
                isBurned[front->right] = 1;
                isFireSpreaded = 1;
            }
            if(parentMap[front] && !isBurned[parentMap[front]]) {
                q.push(parentMap[front]);
                isBurned[parentMap[front]] = 1;
                isFireSpreaded = 1;
            }
            if(isFireSpreaded) {
                ++T;
            }
        }
    }
    return T;
}

int minTime(Node* root, int target) {
    unordered_map<Node*, Node*> parentMap; // node to it's parent pointer
    Node* targetNode = makeNodeToParentMappingAndFindTargetNode(root, parentMap, target);
    return burnTheTree(targetNode, parentMap);
}

int main() {
    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    Node* root = buildTree();

    cout<<"Answer is: "<<minTime(root, 8)<<endl;


    return 0;
}
*/


// ******** FIND /RETURN ALL THE DUPLICATE SUBTREE ********
/*
#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    // Step A, B and C

    Node* root = new Node(data);

    cout<<"Enter data for left part of "<<data<<" node "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<<data<<" node "<<endl;
    root->right = buildTree();

    return root;
}

vector<Node*> ans;
unordered_map<string, int> subTreeMap;

string preorder(Node* root) {
    if(!root) {
        return "N";
    }

    string curr = to_string(root->data);
    string left = preorder(root->left);
    string right = preorder(root->right);

    string s = curr + "," + left + "," + right;

    if(subTreeMap.find(s) != subTreeMap.end()) {
        if(subTreeMap[s] == 1) {
            ans.push_back(root);
        }
        subTreeMap[s]++;
    }
    else {
        subTreeMap[s] = 1;
    }
    return s;
}

vector<Node*> findDuplicateSubTree(Node* root) {
    cout<<preorder(root)<<endl;
    return ans;
}

int main() {
    // 1 2 4 -1 -1 -1 3 2 4 -1 -1 -1 4 -1 -1
    Node* root = buildTree();

    vector<Node*> duplicate = findDuplicateSubTree(root);

    for(auto val: duplicate) {
        cout<<val->data<<" ";
    } cout<<endl;

    return 0;
}
*/