// ******* BASIC SINGLY LINKED LIST **********
/*
#include <iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout<<"Printing the Linked List"<<endl;
    print(first);

    return 0;
}
*/


// ********* INSERT AT HEAD AND TAIL OF NODE AND PRINT THE LINKED LIST ********
/*
#include <iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// I want to insert a node right at the head/start of Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {

    // check for empty Linked List
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;  

        return; 
    }

    // step 1 -> create node
    Node* newNode = new Node(data);

    // step 2 -> attach new node next with head
    newNode->next = head;

    // step 3 -> make head is starting point
    head = newNode;
}

// I want to insert a node right at the end of Linked List
void insertAtTail(Node* &head, Node* tail, int data) {

    // check for empty Linked List
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;  

        return; 
    }

    // step 1 -> create new node
    Node* newNode = new Node(data);

    // step 2 -> connect with tail node
    tail->next = newNode;
 
    // step -> tail will be equal to newNode / update the tail
    tail = newNode;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    
    // Insert at head
    Node* head = NULL;
    // Insert at tail
    Node* tail = NULL;
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 50);

    cout<<"Printing the Node - "<<endl;
    print(head);

    return 0;
}
*/


// ****** INSERT AND DELETE NODE AT SPECIFIC POSITION IN LINKED LIST ********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~Node() {
        cout<<"Node with value: "<<this->data<<" deleted!"<<endl;
    }
};

// I want to insert a node right at the head/start of Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {

    // check for empty Linked List
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;  

        return; 
    }

    // step 1 -> create node
    Node* newNode = new Node(data);

    // step 2 -> attach new node next with head
    newNode->next = head;

    // step 3 -> make head is starting point
    head = newNode;
}

// I want to insert a node right at the end of Linked List
void insertAtTail(Node* &head, Node*& tail, int data) {

    // check for empty Linked List
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;  

        return; 
    }

    // step 1 -> create new node
    Node* newNode = new Node(data);

    // step 2 -> connect with tail node
    tail->next = newNode;
 
    // step -> tail will be equal to newNode / update the tail
    tail = newNode;
}

int findLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(int position, Node*& head, Node*& tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if( position == 0) {
        // Node* newNode = new Node(data);
        // newNode->next = head;
        // head = newNode;
        // return;
        // ***** ALTERNATE *****
        insertAtHead(head, tail, data);
        return;
    }

    // length of linked list
    int len = findLength(head);
    cout<<"length: "<<len<<endl;
    if(position >= len) {
        insertAtTail(head, tail, data);
        return;
    }
    // step 1 - find the position : previous and current position
    int i = 1;
    Node* prev = head;
    while(i<position) {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    // step 2 - create a node
    Node* newNode = new Node(data);

    // step 3 - new node = current
    newNode->next = curr;

    // step 4 - prev next = curr;
    prev->next = newNode;
}

void deleteNode(int position, Node*& head, Node*& tail) {
    if(head == NULL) {
        cout<<"Cannot delete, Linked list is empty";
        return;
    }

    // deleting first node
    if(position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // deleting last node
    int len = findLength(head);

    if(position >= len) {
        // step 1 - find previous
        int i = 1;
        Node* prev = head;
        while( i < len - 1) {
            prev = prev->next;
            i++;
        }
        // step 2 - previous -> next == NULL
        prev->next = NULL;
        // step 3 - node* temp = tail
        Node* temp = tail;
        // step 4 - tail = prev
        tail = prev;
        // step 5 - delete temp
        delete temp;
        return;
    }

    // find previous and current
    int i = 1;
    Node* prev = head;
    while(i < position-1) {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    // prev -> next = curr -> next
    prev->next = curr->next;

    // curr -> next = null
    curr->next = NULL;

    // delete curr
    delete curr;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);
    insertAtTail(head, tail, 77);

    print(head);
    // cout<<"Head 1: "<<head->data<<endl;
    // cout<<"Tail 1: "<<tail->data<<endl;

    // insertAtPosition(4, head, tail, 101);
    // print(head);
    // cout<<"Head 2: "<<head->data<<endl;
    // cout<<"Tail 3: "<<tail->data<<endl;
    // print(head);

    deleteNode(10, head, tail);
    print(head);

    return 0;
}
*/


// ******** DOUBLY LINKED LIST ********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node() {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        cout<<"Node with value: "<<this->data<<" deleted"<<endl;
    }
};

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

int getLength(Node* &head) {
    int len = 0;
    Node* temp = head;

    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node*& head, Node*& tail, int data) {
    if(head == NULL) {
        // LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }   

    // step 1 - create a node
    Node* newNode = new Node(data);
    // step 2 - new node link to head
    newNode->next = head;
    // step 3 - head prev = newnode
    head->prev = newNode;
    // step 4 - head = new node
    head = newNode;
    return;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        // LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // LL is not empty
    // step 1 - new node create
    Node* newNode = new Node(data);
    // step 2 - tail ka next = new node
    tail->next = newNode;
    // step 3 - new node la prev = tail
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int data,int position) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // LL is not empty
    // insertion at start
    if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    // insertion at end
    int len = getLength(head);

    if(position > len) {
        insertAtTail(head, tail, data);
        return;
    }

    // insertion at middle
    // step 1 - find prev ans curr
    int i = 1;
    Node* prevNode = head;
    while(i < position-1) {
        prevNode = prevNode->next;
        i++;
    }
    Node* currNode = prevNode->next;

    // step 2
    Node* newNode = new Node(data);

    // step 3
    prevNode->next = newNode;

    // step 4
    newNode->prev = prevNode;

    // step 5
    currNode->prev = newNode;

    // step 6
    newNode->next = currNode;
}

void deleteFromPos(Node*& head, Node* & tail, int position) {
    if(head == NULL) {
        cout<<"Linked list is empty"<<endl;
    }

    if(head->next == NULL) {
        // single node
        Node* temp = NULL;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);
    if(position > len) {
        cout<<"Please enter a valid position"<<endl;
        return;
    }

    if(position == 1) {
        // want to delete the first node
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    if(position == len) {
        // delete last node
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }
    
    // delete from middle
    // step 1 - find left, curr and right
    int i = 1;
    Node* left = head;
    while(i<position-1) {
        left = left->next;
        i++;
    }
    Node* curr = left->next;
    Node* right = curr->next;

    // step 2
    left->next = right;
    // step 3
    right->prev = left;
    // step 4
    curr->prev = NULL;
    // step 5
    curr->next = NULL;
    // step 6
    delete curr;
    return;
}

int main() {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    // print(first);

    Node* head = first;
    Node* tail = third;
    insertAtHead(head, tail, 101);
    // print(head);
    insertAtTail(head, tail, 501);
    // print(head);
    insertAtPosition(head, tail, 401, 3);
    print(head);

    deleteFromPos(head, tail, 10);
    print(head);

    return 0;
}
*/


// ******* REVERSE A LINKED LIST *******
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~Node() {
        cout<<"Node with value: "<<this->data<<" deleted!"<<endl;
    }
};

// I want to insert a node right at the head/start of Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {

    // check for empty Linked List
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;  

        return; 
    }

    // step 1 -> create node
    Node* newNode = new Node(data);

    // step 2 -> attach new node next with head
    newNode->next = head;

    // step 3 -> make head is starting point
    head = newNode;
}

// I want to insert a node right at the end of Linked List
void insertAtTail(Node* &head, Node*& tail, int data) {

    // check for empty Linked List
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;  

        return; 
    }

    // step 1 -> create new node
    Node* newNode = new Node(data);

    // step 2 -> connect with tail node
    tail->next = newNode;
 
    // step -> tail will be equal to newNode / update the tail
    tail = newNode;
}

int findLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(int position, Node*& head, Node*& tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if( position == 0) {
        // Node* newNode = new Node(data);
        // newNode->next = head;
        // head = newNode;
        // return;
        // ***** ALTERNATE *****
        insertAtHead(head, tail, data);
        return;
    }

    // length of linked list
    int len = findLength(head);
    cout<<"length: "<<len<<endl;
    if(position >= len) {
        insertAtTail(head, tail, data);
        return;
    }
    // step 1 - find the position : previous and current position
    int i = 1;
    Node* prev = head;
    while(i<position) {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    // step 2 - create a node
    Node* newNode = new Node(data);

    // step 3 - new node = current
    newNode->next = curr;

    // step 4 - prev next = curr;
    prev->next = newNode;
}

void deleteNode(int position, Node*& head, Node*& tail) {
    if(head == NULL) {
        cout<<"Cannot delete, Linked list is empty";
        return;
    }

    // deleting first node
    if(position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // deleting last node
    int len = findLength(head);

    if(position >= len) {
        // step 1 - find previous
        int i = 1;
        Node* prev = head;
        while( i < len - 1) {
            prev = prev->next;
            i++;
        }
        // step 2 - previous -> next == NULL
        prev->next = NULL;
        // step 3 - node* temp = tail
        Node* temp = tail;
        // step 4 - tail = prev
        tail = prev;
        // step 5 - delete temp
        delete temp;
        return;
    }

    // find previous and current
    int i = 1;
    Node* prev = head;
    while(i < position-1) {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    // prev -> next = curr -> next
    prev->next = curr->next;

    // curr -> next = null
    curr->next = NULL;

    // delete curr
    delete curr;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Reverse thorugh recursion
Node* reverse(Node*& prev, Node*& curr) {
    // base case
    if(curr == NULL) {
        // LL is reversed
        return prev;
    }    

    // 1 case solve then recursive call
    Node* forward = curr->next;
    curr->next = prev;

    reverse(curr, forward);
}

// Reverse thorugh loop
Node* reverseThroughLoop(Node*& head) {
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main() {
    
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);
    insertAtTail(head, tail, 77);

    print(head);
    // cout<<"Head 1: "<<head->data<<endl;
    // cout<<"Tail 1: "<<tail->data<<endl;

    // insertAtPosition(4, head, tail, 101);
    // print(head);
    // cout<<"Head 2: "<<head->data<<endl;
    // cout<<"Tail 3: "<<tail->data<<endl;
    // print(head);

    // deleteNode(10, head, tail);
    // print(head);

    Node* prev = NULL;
    Node* curr = head;
    // head = reverse(prev, curr);
    head = reverseThroughLoop(head);
    print(head);

    return 0;
}
*/


// ******* FIND THE MIDDLE ELEMENT OF LINKED LIST **********
/*
#include <iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

Node* getMiddle(Node*& head) {
    if(head == NULL) {
        cout<<"LL is empty";
        return head;
    }

    if(head->next == NULL) {
        // only 1 node
        return head;
    }

    // LL having more than 1 node
    Node* slow = head;
    Node* fast = head->next;

    while(slow != NULL && fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

int main() {
    
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    print(head);

    Node* middle = getMiddle(head);
    cout<<"Middle element is - "<<middle->data<<endl;

    return 0;
}
*/


// ******** REVERSE THE LINKED LIST WITH RESPECT TO GIVEN KTH GROUP ********* 
/*
#include <iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

int getLength(Node*& head) {
    int len = 0;

    Node* temp = head;
    while(temp != NULL) {
        temp= temp->next;
        len++;
    }
    return len;
}

Node* reverseKNodes(Node*& head, int k) {
    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return NULL;
    }
    int len = getLength(head);
    if(k > len) {
        return head;
    }

    // it means number of nodes in LL is greater than K
    // Step A - Reverse first K nodes of LL

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int count = 0;

    while(count<k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Step B - Recursion call
    if(forward != NULL) {
        // we still have nodes left to reverse
        head->next = reverseKNodes(curr, k);
    }

    // Step C - returnhead of the modified LL
    return prev;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    print(head);
    head = reverseKNodes(head, 3);
    print(head);

    return 0;
}
*/


// ******** REVERSE THE LINKED LIST WITH RESPECT TO GIVEN KTH GROUP ********* ***** CODED AGAIN ****** 
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head) {
    int len = 0;
    Node* temp = head;

    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

Node* reverseKNodes(Node*& head, int k) {
    if(head == NULL) {
        cout<<"Linked list is empty"<<endl;
        return head;
    }
    int len = getLength(head);
    if(k > len) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;

    int i = 0;
    while(i<k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;
    }
    if(forward != NULL) {
        head->next = reverseKNodes(forward, k);
    }
    return prev;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    print(head);
    int k = 5;
    head = reverseKNodes(head, 3);
    print(head);

    return 0;
}
*/


// ******** CHECK IS LINKED LIST HAS A LOOP OR NOT ********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head) {
    int len = 0;
    Node* temp = head;

    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

bool checkForLoop(Node* &head) {
    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast) {
            // loop present
            return true;
        }
    }
    return false;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);
    Node* tenth = new Node(100);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    tenth->next = fifth;

    // print(head);
    cout<<"Loop is present or not - "<<checkForLoop(head)<<endl;

    return 0;
}
*/


// ********* FIND THE STARTING POINT OF LOOP LINKED LIST **********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head) {
    int len = 0;
    Node* temp = head;

    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

Node* startingPointLoop(Node* &head) {
    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast) {
            slow = head;
            break;
        }
    }
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    // slow = fast
    return slow;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = fifth;

    // print(head);
    cout<<"Starting point of loop - "<<startingPointLoop(head)->data<<endl;

    return 0;
}
*/


// ******* REMOVE LOOP FROM LINKED LIST ********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head) {
    int len = 0;
    Node* temp = head;

    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

Node* startingPointLoop(Node* &head) {
    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast) {
            slow = head;
            break;
        }
    }
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    // slow = fast
    return slow;
}

Node* removeLoop(Node* head) {
    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return NULL;
    }
    
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        fast = fast->next;
        if(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast) {
            slow = head;
            break;
        }
    }
    Node* prev = fast;
    while(slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;
    return slow;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = fourth;

    Node* start = removeLoop(head);
    cout<<"Loop start at - "<<start->data<<endl;
    print(head);

    return 0;
}
*/


// ********* CHECK FOR THE PALINDROME IN LINKED LIST **********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
 
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
 
bool checkPalindrome(Node* &head) {
    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return true;
    }

    if(head->next == NULL) {
        // only 1 node
        cout<<"Only 1 node present"<<endl;
        return true;
    }

    // Node is greater than 1

    // Step A : find the middle node
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    // slow pointer is pointing to middle node

    // Step B : Reverse the linked list after middle node

    Node* reverseLLKaHead = reverse(slow->next);
    // Join the reverse LL into the left part
    slow->next = reverseLLKaHead;

    // Step C : Start comparision
    print(head);
    Node* temp1 = head;
    Node* temp2 = reverseLLKaHead;

    while(temp2 != NULL) {
        if(temp1->data != temp2->data) {
            // not a palindrome
            return false;
        }
        else {
            // if data is equal, then aage badh jao
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(3);
    Node* fifth = new Node(2);
    Node* sixth = new Node(1);

    head->next = second;    
    second->next = third;
    third->next = fourth;    
    fourth->next = fifth;
    fifth->next = sixth;

    bool isPalindrome = checkPalindrome(head);
    cout<<"Answer is - "<<isPalindrome<<endl;
    if(isPalindrome) {
        cout<<"LL is a valid palindrome"<<endl;
    }
    else {
        cout<<"LL is not a palindrome"<<endl;
    }

    return 0;
}
*/



// ********** REMOVE DUPLICATE IN SORTED AND UNSORTED LINKED LINK **************
/*
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public: 
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void removeDuplicateFromSortedLL(Node* head) {
    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return;
    }
    if(head->next == NULL) {
        cout<<"Single node is Linked list"<<endl;
        return;
    }

    // Greater than 1 node
    Node* curr = head;

    while(curr != NULL) {
        if((curr->next != NULL) && (curr->data == curr->next->data)) {
            // equal 
            Node* temp = curr->next;
            curr->next = curr->next->next;

            // delete duplicate node
            temp->next = NULL;
            delete temp;
        }
        else {
            // not equal
            curr = curr->next;
        }
    }
    return;
}

void removeDuplicateFromUnsortedLL(Node* &head) {
    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return;
    }
    if(head->next == NULL) {
        cout<<"Single node is Linked list"<<endl;
        return;
    }

    // Greater than 1 node

    //  1 4 8 4 7 8 1
    unordered_map<int, bool> map;
    Node* curr = head->next;
    Node* prev = head;
    int prevData = prev->data;
    map[prevData] = true;

    while(curr != NULL) {
        int currData = curr->data;
        if(map[currData] == true) {
            // equal
            Node* temp = curr;
            prev->next = curr->next;
            curr = curr->next;

            // delete duplicate node
            temp->next = NULL;
            delete temp;
        }
        else {
            // not equal
            curr = curr->next;
            prev = prev->next;
            map[currData] = true;
        }
    }
    return;
}

int main() {
    
    Node* head = new Node(1);
    Node* second = new Node(4);
    Node* third = new Node(8);
    Node* fourth = new Node(4);
    Node* fifth = new Node(7);
    Node* sixth = new Node(8);
    Node* seventh = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    cout<<"Input linked list - "<<endl;
    print(head);

    removeDuplicateFromUnsortedLL(head);

    cout<<"Output linked list - "<<endl;
    print(head);

    return 0;
}
*/


// ********** SORT ZERO, ONE AND TWO IN LINKED LIST BUT THIS SOLUTION IS WITH DATA REPLACEMENT **********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void sortZeroOneAndTwo(Node* &head) {
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == 0) {
            zeroCount++;
        }
        else if(temp->data == 1) {
            oneCount++;
        }
        else if(temp->data == 2) {
            twoCount++;
        }
        temp = temp->next;
    }
    
    temp = head;

    while(temp != NULL) {
        if (zeroCount > 0) {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount > 0) {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount > 0) {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
}

int main() {
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(1);
    Node* fifth = new Node(0);
    Node* sixth = new Node(2);
    Node* seventh = new Node(0);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    cout<<"Input linked list - "<<endl;
    print(head);

    sortZeroOneAndTwo(head);
    cout<<"Output linked list - "<<endl;
    print(head);

    return 0;
}
*/


// ******** SORT ZERO, ONE AND TWO IN LINKED LIST WITHOUT DATA REPLACEMENT *********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* sortZeroOneTwo(Node* &head) {

    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return NULL;
    }

    if(head->next == NULL) {
        // single node in LL
        return head;
    }

    // Create dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;


    // Traverse the original linked list
    Node* curr = head;
    while(curr != NULL) {
        if(curr->data == 0) {
            // take out the zero wali node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            
            // append the zero node in zerohead LL
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if(curr->data == 1) {
            // take out the one wali node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            
            // append the one node in zerohead LL
            oneTail->next = temp;
            oneTail = temp;
        }
        else if(curr->data == 2) {
            // take out the two wali node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            
            // append the two node in zerohead LL
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // ab yha per, zero, one, two, teeno LL ready h    

    // remove dummy

    // modify onr wali list
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    // modify two wali list
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    // join list
    if(oneHead != NULL) {
        zeroTail->next = oneHead;
        if(twoHead != NULL) {
            oneTail->next = twoHead;
        }
    }
    else {
        // one wali list is empty
        if(twoHead != NULL) {
            zeroTail->next = twoHead;
        }
    }

    // remove zero head dummy node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    // return head of the modified linked list
    return zeroHead;
}

int main() {
    
    Node* head = new Node(2);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(0);
    Node* fifth = new Node(1);
    Node* sixth = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    cout<<"Input linked list - ";
    print(head);

    head = sortZeroOneTwo(head);
    cout<<"Output linked list - ";
    print(head);

    return 0;
}
*/


// ******** FIND THE SUM OF TWO LINKED LIST **********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* solve(Node* head1, Node* head2) {
    if(head1 == NULL) {
        return head2;
    }
    if(head2 == NULL) {
        return head1;
    }

    // step 1: Reverse both linked list
    head1 = reverse(head1);
    head2 = reverse(head2);

    // step 2: add both linked list
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;
    while((head1 != NULL) && (head2 != NULL)) {
        // calculate sum
        int sum = carry + head1->data + head2->data;
        // find the digit to create node
        int digit = sum % 10;
        // calulate carry
        carry = sum / 10;

        // create a new node for the digit
        Node* newNode = new Node(digit);
        // attach the new node into the answer wali linked list
        if(ansHead == NULL) {
            // first node insert kr rhe ho
            ansHead = newNode;
            ansTail = newNode;
        }
        else {
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // jb head1 list ki length head2 list se jada hogi
    while(head1 != NULL) {
        int sum = carry + head1->data;
        int digit  = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(digit);

        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }

    // jb head2 list ki length head1 list se jada hogi
    while(head2 != NULL) {
        int sum = carry + head2->data;
        int digit  = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(digit);

        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;
    }

    // handle carry ko alag se krna padega
    while(carry != 0) {
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    // step 3: reverse the ans linked list
    ansHead = reverse(ansHead);
    return ansHead;
}

int main() {
    
    Node* head1 = new Node(2);
    Node* second1 = new Node(4);
    head1->next = second1;

    Node* head2 = new Node(2);
    Node* second2 = new Node(3);
    Node* third2 = new Node(4);

    head2->next = second2;
    second2->next = third2;

    Node* ans = solve(head1, head2);
    cout<<"Answer is - ";
    print(ans);

    return 0;
}
*/


// ********** FIND THE GIVEN Kth NODE FROM THE END OF THE LINKED LIST **********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

int getLength(Node* &head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int search(Node* &head, int position) {
    int length = getLength(head) - 1;
    int positionFromEnd = length - position;
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        if(count == positionFromEnd) {
            return temp->data;
        }
        count++;
        temp = temp->next;
    }
    return -1;
}

void fun(Node* head, int &positionFromTail, int &ans) {
    if(head == 0) {
        return;
    }
    fun(head->next, positionFromTail, ans);
    if(positionFromTail == 0) {
        ans = head->data;
    }
    positionFromTail--;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    // print(head);
    // ******* THIS IS MY SOLUTION ********
    // int ans = search(head, 3);
    // cout<<"Answer is - "<<ans<<endl;

    // ********* LAKHSHAY'S SOLUTION THROUGH RECURSION **********
    int ans = -1;
    int positionFromTail = 3;
    fun(head, positionFromTail, ans);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ******** INTERSECTION OF TWO LINKED LISTS *********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

Node* getIntersectionNode(Node* headA, Node* headB) {
    Node* a = headA;
    Node* b = headB;

    while( a->next && b->next) {
        if(a == b) {
            return a;
        }
        a = a->next;
        b = b->next;
    }

    if(a->next == 0 && b->next == 0 && a !=b ) {
        return 0;
    }

    if(a->next == 0) {
        // Bth link list is bigger or equal
        // we need to find out how much bigger it is
        int blen = 0;
        while(b->next) {
            blen++;
            b = b->next;
        }

        while(blen--) {
            headB = headB->next;
        }
    }
    else {
        // Ath link list is bigger
        // we need to find out how much bigger it is
        int alen = 0;
        while(a->next) {
            alen++;
            a = a->next;
        }

        while(alen--) {
            headA = headA->next;
        }
    }

    while(headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node* head1 = new Node(1);
    Node* second1 = new Node(2);
    Node* third1 = new Node(3);

    head1->next = second1;
    second1->next = third1;
    third1->next = third;

    Node* ans = getIntersectionNode(head, head1);
    cout<<"Answer is - "<<ans->data<<endl;

    return 0;
}
*/


// ********* MERGE TWO SORTED LINK LISTS ********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

Node* mergeTwoLists(Node* left, Node* right) {
    if(left == 0) {
        return right;
    }
    if(right == 0) {
        return left;
    }

    Node* ans = new Node(-1);
    Node* mptr = ans;

    while(left && right) {
        if(left->data <= right->data) {
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else {
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }

    if(left) {
        mptr->next = left;
    }
    if(right) {
        mptr->next = right;
    }
    
    Node* temp = ans;
    ans = ans->next;

    temp->next = NULL;
    delete temp;

    return ans;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(3);
    Node* third = new Node(5);
    Node* fourth = new Node(7);
    Node* fifth = new Node(8);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node* head1 = new Node(2);
    Node* second1 = new Node(4);
    Node* third1 = new Node(6);

    head1->next = second1;
    second1->next = third1;

    cout<<"First Linked list - ";
    print(head);
    cout<<"Second Linked list - ";
    print(head1);
    Node* ans = mergeTwoLists(head, head1);
    cout<<"Merged linked list - ";
    print(ans);

    return 0;
}
*/


// ********** SORT LIST USING MERGE SORT **********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    if(left == 0) {
        return right;
    }
    if(right == 0) {
        return left;
    }

    Node* ans = new Node(-1);
    Node* mptr = ans;

    while(left && right) {
        if(left->data <= right->data) {
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else {
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }

    if(left) {
        mptr->next = left;
    }
    if(right) {
        mptr->next = right;
    }

    Node* temp = ans;
    ans = ans->next;

    temp->next = NULL;
    delete temp;

    return ans;
}

Node* sortList(Node* head) {
    if(head == 0 || head->next == 0) {
        return head;
    }

    // Break LL into two half using mid node
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = 0;

    // sort recursive call
    left = sortList(left);
    right = sortList(right);

    // merge both left and right LL
    Node* mergeLL = merge(left, right);
    return mergeLL;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(4);
    Node* third = new Node(3);
    Node* fourth = new Node(5);
    Node* fifth = new Node(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout<<"Input Linked list - ";
    print(head);
    cout<<"Output Linked list - ";
    head = sortList(head);
    print(head);

    return 0;
}
*/


// ************ FLATTERN LINKED LIST **********
/*
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* bottom;

    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->bottom;
    } cout<<endl;
}

Node* merge(Node* a, Node* b) {
    if(!a) return b;
    if(!b) return a;

    Node* ans = 0;

    if(a->data < b->data) {
        ans = a;
        a->bottom = merge(a->bottom, b);
    }
    else {
        ans = b;
        b->bottom = merge(a, b->bottom);
    }
    return ans;
}

Node* flatten(Node* root) {
    if(!root) return 0;

    Node* mergedLL = merge(root, flatten(root->next));
    return mergedLL;
}

int main() {
    Node* head = new Node(5);
    Node* head2 = new Node(28);
    head->next = head2;

    Node* first = new Node(7);
    Node* second = new Node(8);
    Node* third = new Node(30);
    head->bottom = first;
    first->bottom = second;
    second->bottom = third;

    Node* fourth = new Node(35);
    Node* fifth = new Node(40);
    Node* sixth = new Node(45);
    head2->bottom = fourth;
    fourth->bottom = fifth;
    fifth->bottom = sixth;
    Node* ans = flatten(head);
    print(ans);

    return 0;
}
*/


// ******** COPY LIST WITH RANDOM POINTERS WITH SPACE COMPLEXITY 0(N)*********
/*
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* randam;

    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
        this->randam = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

Node* helper(Node* head, unordered_map<Node*, Node*> &mp) {
    if(head == 0) {
        return 0;
    }

    Node* newHead = new Node(head->data);
    mp[head] = newHead;

    newHead->next = helper(head->next, mp);

    if(head->randam) {
        newHead->randam = mp[head->randam];
    }

    return newHead;
} 

Node* copyRandomLis(Node* head) {
    unordered_map<Node*, Node*> mp; // old node -> new node mapping
    return helper(head, mp);
}

int main() {
    Node* head = new Node(7);
    Node* second = new Node(13);
    Node* third = new Node(11);
    Node* fourth = new Node(10);
    Node* fifth = new Node(1);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->randam = head;
    fourth->randam = third;
    third->randam = fifth;
    second->randam = head;
    head->randam = NULL;

    Node* ans = copyRandomLis(head);

    print(ans);

    return 0;
}
*/


// ******** COPY LIST WITH RANDOM POINTERS WITHOUT MAKING MAP - SPACE COMPLEXITY - 0(1)*********
/*
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* randam;

    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
        this->randam = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

Node* copyRandomList(Node* head) {
    if(!head) return NULL;

    // step 1 - clone A -> A'
    Node* it = head; // itearte over old head;
    while(it) {
        Node* clonedNode = new Node(it->data);
        clonedNode->next = it->next;
        it->next = clonedNode;
        it = it->next->next;
    }

    // step  2 - assign random links of A' with the help of old node A
    it = head;
    while(it) {
        Node* clonedNode = it->next;
        clonedNode->randam = it->randam ? it->randam->next : nullptr;
        it = it->next->next;
    }

    // step 3 - detach A' from A
    it = head;
    Node* clonedHead = it->next;
    while(it) {
        Node* clonedNode = it->next;
        it->next = it->next->next;
        if(clonedNode->next) {
            clonedNode->next = clonedNode->next->next;
        }
        it = it->next;
    }

    return clonedHead;
}

int main() {
    Node* head = new Node(7);
    Node* second = new Node(13);
    Node* third = new Node(11);
    Node* fourth = new Node(10);
    Node* fifth = new Node(1);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->randam = head;
    fourth->randam = third;
    third->randam = fifth;
    second->randam = head;
    head->randam = NULL;

    cout<<"Original link list - ";
    print(head);

    Node* ans = copyRandomList(head);
    cout<<"Cloned link list - ";
    print(ans);

    return 0;
}
*/


// ********* ROTATE LINK LIST BY K PLACES *********
/*
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

int getLength(Node* head) {
    int count = 0;

    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* rotateLL(Node* head, int k) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    int len = getLength(head);
    int actualRotateK = k % len;
    if(actualRotateK == 0) {
        return head;
    }

    int newLastNodePos = len - actualRotateK - 1;

    Node* newLastNode = head;

    for(int i=0; i<newLastNodePos; i++) {
        newLastNode = newLastNode->next;
    }
    Node* newHead = newLastNode->next;

    newLastNode->next = 0;

    Node* it = newHead;
    while(it->next) {
        it = it->next;
    } 
    it->next = head;
    return newHead;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout<<"Original link list - ";
    print(head);
    cout<<"Rotated link list - ";
    int k = 10;
    Node* ans = rotateLL(head, k);
    print(ans);

    return 0;
}
*/


// ********** DELETE N NODES AFTER M NODES ***********
/*
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

int getLength(Node* head) {
    int count = 0;

    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

void linkDelete(Node* head, int M, int N) {
    if(head == NULL || head->next == NULL) {
        return;
    }

    Node* it = head;

    for(int i=0; i< M-1; i++) {
        // if M nodes are not avaliable
        if(!it) return;
        it = it->next;
    }
    // it -> would be Mth node
    if(!it) return;

    Node* MthNode = it;
    it = MthNode->next;

    for(int i=0; i<N; i++) {
        if(!it) break;
        Node* temp = it->next;
        delete it;
        it = temp;
    }

    MthNode->next = it;
    linkDelete(it, M, N);
}

int main() {
    Node* head = new Node(9);
    Node* second = new Node(1);
    Node* third = new Node(3);
    Node* fourth = new Node(5);
    Node* fifth = new Node(9);
    Node* sixth = new Node(4);
    Node* seventh = new Node(10);
    Node* eight = new Node(1);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;

    cout<<"Original link list - ";
    print(head);
    linkDelete(head, 2, 2);
    cout<<"After deletion - ";
    print(head);

    return 0;
}
*/


// ************ FIND MIN / MAX NUMBER BETWEEN CRITICAL POINTS (LEET CODE - 2058) **********
/*
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

int getLength(Node* head) {
    int count = 0;

    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

vector<int> nodesBetweenCriticalPoints(Node* head) {
    vector<int> ans = {-1, -1}; // min distance and max distance

    Node* prev = head;
    if(!prev) return ans;

    Node* curr = head->next;
    if(!curr) return ans;

    Node* nxt = curr->next;
    if(!nxt) return ans;

    int firstCP = -1;
    int lastCP = -1;
    int minDist = INT_MAX;
    int i = 1;

    while(nxt) {
        bool isCP = (curr->data > prev->data && curr->data > nxt->data) || (curr->data < prev->data && curr->data < nxt->data) ? true : false;

        if(isCP && firstCP == -1) {
            firstCP = i;
            lastCP = i;
        }
        else if(isCP) {
            minDist = min(minDist, i-lastCP);
            lastCP = i;
        }
        ++i;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }

    if(lastCP == firstCP) {
        // only 1 CP was found
        return ans;
    }
    else {
        ans[0] = minDist;
        ans[1] = lastCP - firstCP;
    }
    return ans;
}

int main() {
    Node* head = new Node(5);
    Node* second = new Node(3);
    Node* third = new Node(1);
    Node* fourth = new Node(2);
    Node* fifth = new Node(5);
    Node* sixth = new Node(1);
    Node* seventh = new Node(2);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    cout<<"Original link list - ";
    print(head);

    vector<int> ans = nodesBetweenCriticalPoints(head);
    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;
    
    return 0;
}
*/


// ******** MERGE NODES BETWEEN ZEROS **********
/*
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}

int getLength(Node* head) {
    int count = 0;

    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* mergeNodesBetweenZeros(Node* head) {
    if(!head) return 0;

    Node* slow = head;
    Node* fast = head->next;
    Node* newLastNode = nullptr;

    int sum = 0;

    while(fast) {
        if(fast->data != 0) {
            sum+=fast->data;
        }
        else {
            // fast ki value == 0
            slow->data = sum;
            newLastNode = slow;
            slow = slow->next;
            sum = 0;
        }
        fast = fast->next;
    }

    Node* temp = newLastNode->next;

    // just formed new list
    newLastNode->next = NULL;

    // deleting old list
    while(temp) {
        Node* nxt = temp->next;
        temp->next = NULL;
        delete temp;
        temp = nxt;
    }

    return head;
}

int main() {
    Node* head = new Node(0);
    Node* second = new Node(3);
    Node* third = new Node(1);
    Node* fourth = new Node(0);
    Node* fifth = new Node(4);
    Node* sixth = new Node(5);
    Node* seventh = new Node(2);
    Node* eight = new Node(0);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;

    cout<<"Original link list - ";
    print(head);
    Node* ans = mergeNodesBetweenZeros(head);
    cout<<"After merge link list - ";
    print(ans);

    return 0;
}
*/
