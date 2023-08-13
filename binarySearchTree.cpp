// ********* BUILDING A BINARY SEARCH TREE WITH INSERTION AND TRAVERSAL *********
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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* & root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
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

void preOrderTraversal(Node* root) {
    // NLR
    if(root == NULL) {
        return;
    }

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
    // LNR
    if(root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    // LRN
    if(root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main() {
    
    Node* root = NULL;
    // 10 20 5 11 17 2 4 8 6 25 15 -1
    cout<<"Enter the data for Node "<<endl;
    takeInput(root);
    cout<<"Printing the tree: "<<endl;
    // levelOrderTraversal(root);
    cout<<"Printing Inorder: "<<endl;
    inOrderTraversal(root);
    cout<<endl;
    cout<<"Printing Preorder: "<<endl;
    preOrderTraversal(root);
    cout<<endl;
    cout<<"Printing Postorder: "<<endl;
    postOrderTraversal(root);
    cout<<endl;



    return 0;
}
*/


// ********** SEARCH IN BINARY SEARCH TREE ********
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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* & root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

// assuming there are only unique values in tree
bool findNodeInBST(Node* root, int target) {
    if(root == NULL) {
        return false;
    }

    if(root->data == target) {
        return true;
    }

    if(root->data > target) {
        // left sub tree me search karo
        return findNodeInBST(root->left, target);
    }
    else {
        // right sub tree me search karo
        return findNodeInBST(root->right, target);       
    }
}

int main() {
    
    Node* root = NULL;
    // 10 20 5 11 17 2 4 8 6 25 15 -1
    cout<<"Enter the data for Node "<<endl;
    takeInput(root);
    cout<<"Answer is: "<<findNodeInBST(root, 100);

    return 0;
}
*/


// ************ MINIMUM AND MAXIMUM VALUE IN BINAR SEARCH TREE *********
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

Node* insertIntoBST(Node*& root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

int minValue(Node* root) {
    Node* temp = root;
    if(temp == NULL) {
        return -1;
    }

    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp->data;
}

int maxValue(Node* root) {
    Node* temp = root;

    if(temp == NULL) {
        return -1;
    }

    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp->data;
}

int main() {
    
    Node* root = NULL;
    // 10 20 5 11 17 2 4 8 6 25 15 -1
    cout<<"Enter the data for Node "<<endl;
    takeInput(root);

    cout<<"Min value: "<<minValue(root)<<endl;
    cout<<"Max value: "<<maxValue(root)<<endl;

    return 0;
}
*/


// ********* DELETION IN BINARY SEARCH TREE ***********
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

Node* insertIntoBST(Node*& root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

// assuming there are only unique values in tree
Node* findNodeInBST(Node* root, int target) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data == target) {
        return root;
    }

    if(root->data > target) {
        // left sub tree me search karo
        return findNodeInBST(root->left, target);
    }
    else {
        // right sub tree me search karo
        return findNodeInBST(root->right, target);       
    }
}

int minValue(Node* root) {
    Node* temp = root;
    if(temp == NULL) {
        return -1;
    }

    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp->data;
}

int maxValue(Node* root) {
    Node* temp = root;

    if(temp == NULL) {
        return -1;
    }

    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp->data;
}

// *********** THIS IS THE WRONG CODE OF DELETION WITH A BUG **********
// Node* deleteNodeInBST(Node* root, int target) {
//     // base case
//     if(root == NULL) {
//         return root;
//     }

//     // step 1 - search root
//     // temp is to node to delete
//     Node* temp = findNodeInBST(root, target);

//     // I want to delete temp
//     if(temp->left == NULL && temp->right == NULL) {
//         // leaf node
//         delete temp;
//         return NULL;
//     }

//     else if(temp->left == NULL && temp->right != NULL) {
//         Node* child = temp->right;
//         delete temp;
//         return child;
//     }

//     else if(temp->left != NULL && temp->right == NULL) {
//         Node* child = temp->left;
//         delete temp;
//         return child;
//     }

//     else {
//         // dono child exist krte he
//         // inorder predecessor of left sub tree -> left subtree me max value
//         int inorderPre = maxValue(temp->left);
//         temp->data = inorderPre;

//         temp->left = deleteNodeInBST(temp->left, inorderPre);
//         return root;
//     }
// }
// ************ WRONG CODE OF DELETION ********* 

Node* deleteNodeInBST(Node* root, int target) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data == target) {
        // isse delete krna he

        // 4 cases to delete

        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL) {
            Node* child = root->right;
            delete root;
            return child;
        }
        else if(root->left != NULL && root->right == NULL) {
            Node* child = root->left;
            delete root;
            return child;
        }
        else {
            // both child
            // find in order predecessor in left sub tree
            int inorderPred = maxValue(root->left);
            // replace root->data with in order predecessor
            root->data = inorderPred;
            // delete in order predecessor from left subtree
            root->left = deleteNodeInBST(root->left, inorderPred);
            return root;
        }
    }
    else if(target > root->data) {
        // right jana he
        root->right = deleteNodeInBST(root->right, target);
    }
    else if(target < root->data) {
        // left jana he
        root->left = deleteNodeInBST(root->left, target);
    }
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
    // 100 50 150 40 60 175 110 -1
    cout<<"Enter the data for Node "<<endl;
    takeInput(root);

    root = deleteNodeInBST(root, 100);
    levelOrderTraversal(root);

    return 0;
}
*/


// ******* CHECK FOR VALID BINARY SERACH TREE ********
/*
#include <iostream>
#include <limits.h>
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

Node* insertIntoBST(Node*& root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

bool solve(Node* root, int lowerBound, int upperBound) {
    // base case
    if(root == NULL) {
        return true;
    }

    if(root->data > lowerBound && root->data < upperBound) {
        bool leftAns = solve(root->left, lowerBound, root->data);
        bool rightAns = solve(root->right, root->data, upperBound);

        return leftAns && rightAns;
    }
    else {
        return true;
    }
}

bool isValidBST(Node* root) {
    int lowerBound = INT_MIN;
    int upperBound = INT_MAX;
    bool ans = solve(root, lowerBound, upperBound);
    return ans;
}

int main() {
    
    Node* root = NULL;
    // 100 50 150 40 60 175 110 -1
    cout<<"Enter the data for Node "<<endl;
    takeInput(root);

    cout<<"Answer is: "<<isValidBST(root)<<endl;

    return 0;
}
*/


// ********** LOWEST COMMON ANCESTOR IN BINARY SEARCH TREE *********
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

Node* insertIntoBST(Node*& root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    // base case
    if(root == NULL) {
        return NULL:
    }

    // case 1
    if(p->data < root->data && q->data < root->data) {
        return lowestCommonAncestor(root->left, p, q);
    }

    // case 2
    else if(q->data > root->data && q->data > root->data) {
        return lowestCommonAncestor(root->right, p, q);
    }

    // case 3
    else {
        return root;
    }
}

int main() {


    return 0;
}
*/


// ********* KTH SMALLEST ELEMENT IN BINARY SEARCH TREE *********
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

Node* insertIntoBST(Node*& root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

void kthSamllest(Node* root, int& k, int& ans) {
    // base case
    if(root == NULL) {
        // -1 reflects base condition reached
        return;
    }

    // Inorder
    // left
    kthSamllest(root->left, k, ans);

    // N->root
    k--;
    if(k==0) {
        ans = root->data;
    }
    if(k < 0) {
        return;
    }

    // right
    kthSamllest(root->right, k, ans);
    return;    
}

int main() {

    
    Node* root = NULL;
    // 3 1 -1 -1 4 -1 2 -1 -1
    cout<<"Enter the data for Node "<<endl;
    takeInput(root);
    int ans = -1;
    int k = 1;
    kthSamllest(root, k, ans);
    cout<<"Answer is: "<<ans<<endl;
    


    return 0;
}
*/


// ********* CREATE A BINARY SEARCH TREE FROM GIVEN INORDER ARRAY ************
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

Node* insertIntoBST(Node*& root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

Node* BSTUsingInorder(int inorder[], int s, int e) {
    // base case
    if(s > e) {
        return NULL;
    }

    int mid = (s+e)/2;

    int element = inorder[mid];

    Node* root = new Node(element);

    root->left = BSTUsingInorder(inorder, s, mid-1);

    root->right = BSTUsingInorder(inorder, mid+1, e);

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
    
    int inorder[10] = {1,2,3,4,5,6,7,8,9};
    int s = 0;
    int e = 8;

    Node* root = BSTUsingInorder(inorder, s, e);

    levelOrderTraversal(root);

    return 0;
}
*/


// ******** FIND TWO NODES WHICH EQUALS A GIVEN SUM *********
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

Node* insertIntoBST(Node*& root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
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

void storeInorder(Node* root, vector<int>& inorder) {
    // base case
    if(root == NULL) {
        return;
    }

    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

bool findTarget(Node* root, int k) {
    vector<int> inorder;
    storeInorder(root, inorder);
    for(auto val: inorder) {
        cout<<val<<" ";
    }
    levelOrderTraversal(root);

    int s = 0;
    int e = inorder.size() - 1;

    while(s < e) {
        int sum = inorder[s] + inorder[e];

        if(sum == k) {
            return true;
        }

        else if(sum > k) {
            e--;
        }

        else {
            s++;
        }
    } 

    return false;
}

int main() {
    
    Node* root = NULL;
    // 100 50 20 70 200 300 250 350 400 -1
    cout<<"Enter the data for Node "<<endl;
    takeInput(root);
    int target = 320;
    cout<<"Answer is: "<<findTarget(root, target)<<endl;

    return 0;
}
*/


// ********* CONVERT THE BINARY SEARCH TREE INTO THE DOUBLY LINKED LIST ********
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

Node* insertIntoBST(Node*& root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
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

void convertIntoSortedDLL(Node* root, Node*& head) {
    if(root == NULL) {
        return;
    }

    // right subtree into LL
    convertIntoSortedDLL(root->right, head);
    
    // attach root node
    root->right = head;
    if(head != NULL) {
        head->left = root;
    }

    // update head
    head = root;

    // left subtree linked list
    convertIntoSortedDLL(root->left, head);
}

Node* BSTUsingInorder(int inorder[], int s, int e) {
    // base case
    if(s > e) {
        return NULL;
    }

    int mid = (s+e)/2;

    int element = inorder[mid];

    Node* root = new Node(element);

    root->left = BSTUsingInorder(inorder, s, mid-1);

    root->right = BSTUsingInorder(inorder, mid+1, e);

    return root;
}

void printLinkedList(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

int main() {
    
    int inorder[10] = {1,2,3,4,5,6,7,8,9};
    int s = 0;
    int e = 8;

    Node* root = BSTUsingInorder(inorder, s, e);

    // levelOrderTraversal(root);

    Node* head = NULL;
    convertIntoSortedDLL(root, head);
    printLinkedList(head);

    return 0;
}
*/


// ********** CONVERT THE SORTED LINKED LIST INTO BINARY SEARCH TREE ********
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

Node* insertIntoBST(Node*& root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
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

void convertIntoSortedDLL(Node* root, Node*& head) {
    if(root == NULL) {
        return;
    }

    // right subtree into LL
    convertIntoSortedDLL(root->right, head);
    
    // attach root node
    root->right = head;
    if(head != NULL) {
        head->left = root;
    }

    // update head
    head = root;

    // left subtree linked list
    convertIntoSortedDLL(root->left, head);
}

Node* BSTUsingInorder(int inorder[], int s, int e) {
    // base case
    if(s > e) {
        return NULL;
    }

    int mid = (s+e)/2;

    int element = inorder[mid];

    Node* root = new Node(element);

    root->left = BSTUsingInorder(inorder, s, mid-1);

    root->right = BSTUsingInorder(inorder, mid+1, e);

    return root;
}

void printLinkedList(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

Node* sortedLinkListIntoBST(Node*& head, int n) {
    // base case
    if(n <= 0 || head == NULL) {
        return NULL;
    }

    Node* leftSubTree = sortedLinkListIntoBST(head, n-1-(n/2));
    Node* root = head;
    root->left = leftSubTree;

    head = head->right;

    // right part solve karna he
    root->right =sortedLinkListIntoBST(head, n/2);
    return root;
}

int main() {
    
    int inorder[10] = {1,2,3,4,5,6,7,8,9};
    int s = 0;
    int e = 8;

    Node* root = BSTUsingInorder(inorder, s, e);

    Node* head = NULL;
    convertIntoSortedDLL(root, head);
    printLinkedList(head);

    Node* root1 = NULL;
    root1 = sortedLinkListIntoBST(head, 9);
    levelOrderTraversal(root1);

    return 0;
}
*/


// ********* FIND THE LARGEST BINARY SEARCH TREE IN A BINARY TREE ***********
/*
#include <iostream>
#include <queue>
#include <limits.h>
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

class NodeData {
    public:
    int size;
    int minVal;
    int maxVal;
    int validBST;

    NodeData() {
        
    }

    NodeData(int size, int max, int min, bool valid) {
        this->size = size;
        minVal = min;
        maxVal = max;
        validBST = valid;
    }
};

Node* insertIntoBST(Node*& root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
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

NodeData findLargestBST(Node* root, int& ans) {
    if(root == NULL) {
        NodeData temp(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    NodeData leftKaAns = findLargestBST(root->left, ans);
    NodeData rightKaAns = findLargestBST(root->right, ans);

    // checking starts here
    NodeData currNodeKaAns;

    currNodeKaAns.size = leftKaAns.size + rightKaAns.size + 1;
    currNodeKaAns.maxVal = max(root->data, rightKaAns.maxVal);
    currNodeKaAns.minVal = min(root->data, leftKaAns.minVal);

    if(leftKaAns.validBST && rightKaAns.validBST && (root->data > leftKaAns.maxVal && root->data < rightKaAns.minVal)) {
        currNodeKaAns.validBST = true;
    }
    else {
        currNodeKaAns.validBST = false;
    }

    if(currNodeKaAns.validBST) {
        ans = max(ans, currNodeKaAns.size);
    }
    return currNodeKaAns;
}

int main() {
    Node* root = new Node(50);
    Node* first = new Node(30);
    Node* second = new Node(60);
    Node* third = new Node(5);
    Node* fourth = new Node(20);
    Node* fifth = new Node(45);
    Node* sixth = new Node(70);
    Node* seventh = new Node(65);
    Node* eight = new Node(80);

    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;
    second->left = fifth;
    second->right = sixth;
    sixth->left = seventh;
    sixth->right = eight;


    cout<<"Printing the tree "<<endl;
    levelOrderTraversal(root);

    int ans = 0;
    NodeData final = findLargestBST(root, ans);
    cout<<"Largest BST ka size: "<<ans<<endl;

    return 0;
}
*/



// ******** FIND TE INORDER PREDECESSOR *********
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

Node* findPredecessor(Node* root, Node* p) {
    Node* pred = 0;
    Node* curr = root;

    while(curr) {
        if(curr->data < p->data) {
            pred = curr;
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }
    return pred;
}

int main() {
    


    return 0;
}
*/


// ******* FIND THE IN ORDER SUCCESSOR *********
/*
#include <iostream>
using namespace std;

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

Node* inOrderSuccessor(Node* root, Node* x) {
    Node* succ = 0;
    Node* curr = root;

    while(curr) {
        if(curr->data > x->data) {
            succ = curr;
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    return succ;
}

int main() {
    


    return 0;
}
*/


// ******** BUILD TREE FROM GIVEN PRE ORDER VECTOR *********
/*
#include <iostream>
#include <vector>
#include <limits.h>
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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* & root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

Node* build(int &i, int min, int max, vector<int>& preOrder) {
    if(i>=preOrder.size()) {
        return NULL;
    }

    Node* root = nullptr;

    if(preOrder[i] > min && preOrder[i] < max) {
        root = new Node(preOrder[i++]);
        root->left = build(i, min, root->data, preOrder);
        root->right = build(i, root->data, max, preOrder);
    }
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

Node* bstFromPreOrder(vector<int> preOrder) {
    int min = INT_MIN, max = INT_MAX;
    int i = 0;
    return build(i, min, max, preOrder);
}

int main() {
    
    vector<int> input = {8,5,1,7,10,12};
    Node* root = NULL;
    root = bstFromPreOrder(input);
    levelOrderTraversal(root);


    return 0;
}
*/


// ******** FIND THE SUM PAIR IN TWO BINARY SEARCH TREE **********
/*
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* & root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
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

int countPairs(Node* root1, Node* root2, int x) {
    int ans = 0;
    stack<Node*> s1, s2;

    Node* a = root1;
    Node* b = root2;

    while(1) {
        while(a) {
            s1.push(a);
            a = a->left;
        }

        while(b) {
            s2.push(b);
            b = b->right;
        }

        if(s1.empty() || s2.empty()) {
            break;
        }

        auto atop = s1.top();
        auto btop = s2.top();

        int sum = atop->data + btop->data;

        if(sum == x) {
            ++ans;
            s1.pop();
            s2.pop();
            a = atop->right;
            b = btop->left;
        }
        else if (sum < x) {
            s1.pop();
            a = atop->right;
        }
        else {
            s2.pop();
            b = btop->left;
        }
    }
    return ans;
}

int main() {
    
    Node* root1 = NULL;
    Node* root2 = NULL;

    takeInput(root1);
    takeInput(root2);

    cout<<"Answer is: "<<countPairs(root1, root2, 16)<<endl;


    return 0;
}
*/


// ********* BUILD A BALANCED BINARY SEARCH TREE WITH THE GIVEN TREE *********
/*
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* & root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
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

void inorder(Node* root, vector<int> &in) {
    if(!root) {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* buildTree(vector<int> &in, int start, int end) {
    if(start > end) {
        return NULL;
    }

    int mid = (start + end) >> 1;

    Node* root = new Node(in[mid]);

    root->left = buildTree(in, start, mid-1);
    root->right = buildTree(in, mid+1, end);
    return root;
}

Node* balanceBST(Node* root) {
    vector<int> in;

    inorder(root, in);

    // build balanced BST using inorder traversal
    return buildTree(in, 0, in.size()-1);
}

int main() {
    
    Node* root = new Node(1);
    Node* first = new Node(2);
    Node* second = new Node(3);
    Node* third = new Node(4);
    Node* fourth = new Node(5);

    root->right = first;
    first->right = second;
    second->right = third;
    third->right = fourth;

    levelOrderTraversal(root);

    Node* newRoot = balanceBST(root);
    levelOrderTraversal(newRoot);

    return 0;
}
*/


// ********** FIND THE DEAD END IN BST **********
/*
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* & root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
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

void fun(Node* root, unordered_map<int, bool>& visited, bool& ans) {
    if(root == 0) {
        return;
    }

    // visit the node
    visited[root->data] = 1;
    if(root->left == 0 && root->right == 0) {
        // leaf node
        int xp1 = root->data + 1;
        int xm1 = root->data - 1 == 0 ? root->data : root->data - 1;

        if(visited.find(xp1) != visited.end() && visited.find(xm1) != visited.end()) {
            ans = true;
        }
        return;
    }
    fun(root->left, visited, ans);
    fun(root->right, visited, ans);
}

bool isDeadEnd(Node* root) {
    bool ans = false; // tells if there was Dead end
    unordered_map<int, bool> visited;
    fun(root, visited, ans);
    return ans;
}

int main() {
    



    return 0;
}
*/


// ********* FIND THE SUM OF NODE IN BST WHICH HAS A VALUE UNDER THE GIVEN RANGE **********
/*
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* & root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
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

int rangeSumBST(Node* root, int low, int high) {
    if(!root) return 0;
    int ans = 0;

    bool wasInRange = false;
    if(root->data >= low && root->data > high) {
        wasInRange = true;
        ans += root->data;
    }

    if(wasInRange) {
        ans += rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
    else if(root->data < low) {
        ans += rangeSumBST(root->right, low, high);
    }
    else if(root->data > high) {
        ans += rangeSumBST(root->left, low, high);
    }

    return ans;
}

int main() {
    


    return 0;
}
*/


// ********* FLATTERN THE BST INTO THE LINKED LIST *******
/*
#include <iostream>
using namespace std;

struct node {
    int key;
    struct node* left, * right;
};

// A utility function to create a new BST node
struct node* newNode(int item) {
    struct node* temp = new struct node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key) {
    // I the tree is empty, return a new node
    if(node== NULL) {
        return newNode(key);
    }

    if(key<node->key) {
        node->left = insert(node->left, key);
    }
    else if(key > node->key) {
        node->right = insert(node->right, key);
    }

    // return the (unchanged) node pointer
    return node;
}

struct node* search(struct node* root, int key) {
    // base case: root is null or key is present at root
    if(root == NULL || root->key == key) {
        return root;
    }

    // key is greater than root's key
    if(root->key < key) {
        return search(root->right, key);
    }
    // key is smaller than root's key
    return search(root->left, key);
}

void printLL(node* head) {
    while(head) {
        cout<<head->key<<" ";
        head = head->right;
    }
}

// inorder traversal
void in(node* root, node*& prev) {
    if(!root) return;
    in(root->left, prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    in(root->right, prev);
}

node* flattern(node* root) {
    node* dummy = newNode(-1);
    node* prev = dummy;

    in(root, prev);
    prev->left = prev->right = NULL;
    root = dummy->right;
    return root;
}

// driver code
int main() {
    
    struct node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);
    root = flattern(root);
    printLL(root);

    return 0;
}
*/


// ********* REPLACE EVERY ELEMENT WITH THE LEAST GREATER ELEMENT TO ITS RIGHT *******
/*
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* & root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
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

Node* insert(Node* root, int val, int& succ) {
    if(!root) {
        return new Node(val);
    }

    if(val>root->data) {
        root->right = insert(root->right, val, succ);
    }
    else {
        succ = root->data;
        root->left = insert(root->left, val, succ);
    }
    return root;
}

vector<int> findLeastGreater(vector<int>& arr, int n) {
    vector<int> ans(arr.size(), -1);

    Node* root = 0;
    for(int i=arr.size()-1; i>=0; --i) {
        int succ = -1;
        root = insert(root, arr[i], succ);

        ans[i] = succ;
    }

    return ans;
}

int main() {

    vector<int> input{8,58,71,18,31,32,63,92,43,3,91,93,25,80,28};

    vector<int> ans = findLeastGreater(input, input.size());

    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;
    


    return 0;
}
*/


// ********** VALID BST FROM PREORDER ********
/*
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <limits.h>
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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* & root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
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

void build(int& i, int min, int max, vector<int>& A) {
    if(i>=A.size()) {
        return;
    }

    if(A[i]>min && A[i]<max) {
        //faking a new node creation
        int rootData = A[i];
        build(i, min, rootData, A);
        build(i, rootData, max, A);
    }
}

int main() {
    vector<int> A{7,7,10,10,9,5,2,8};
    int min = INT_MIN, max = INT_MAX;
    int i = 0;
    build(i, min, max, A);
    bool ans = i==A.size();
    cout<<"Answer is: "<<ans;


    return 0;
}
*/


// ******* MEARGE TWO BINARY SEARCH TREES *********
/*
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <limits.h>
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

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not a first node
    if(root->data > data) {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else {
        // insert in right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* & root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
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

vector<int> merge(Node* root1, Node* root2) {
    vector<int> ans; // stores sorted element of both the trees;
    stack<Node*> sa, sb;

    Node* a = root1, *b = root2;

    while(a || b || !sa.empty() || !sb.empty()) {
        while(a) {
            sa.push(a);
            a = a->left;
        }

        while(b) {
            sb.push(b);
            b = b->left;
        }

        if(sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)) {
            auto atop = sa.top();
            ans.push_back(atop->data);
            sa.pop();
            a = atop->right;
        }
        else {
            auto btop = sb.top();
            ans.push_back(btop->data);
            sb.pop();
            b = btop->right;
        }
    }

    return ans;
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    takeInput(root1);
    takeInput(root2);

    vector<int> ans = merge(root1, root2);

    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/