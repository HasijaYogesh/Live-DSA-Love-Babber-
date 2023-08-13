// ********* BASIC QUEUE **********
/*
#include <iostream>
#include <queue>
using namespace std;

int main() {
    
    // creation 
    queue<int> q;

    // insertion
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    // size
    cout<<"Size of queue: "<<q.size()<<endl;

    // removal
    q.pop();

    cout<<"Size of queue: "<<q.size()<<endl;

    if(q.empty()) {
        cout<<"Q is empty"<<endl;
    }
    else {
        cout<<"Q is not empty"<<endl;
    }

    cout<<"Front element is: "<<q.front()<<endl;

    return 0;
}
*/


// ********* CREATING OUR OWN QUEUE *********
/*
#include <iostream>
using namespace std;

class Queue {
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data) {
        if(rear == size) {
            cout<<"Queue is full"<<endl;
        }
        else {
            arr[rear] = data;
            rear++;
        }
    }

    void pop() {
        if(front == rear) {
            cout<<"Queue is empty"<<endl;
        }
        else {
            arr[front] = -1;
            front++;
            if(front == rear) {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront() {
        if(front == rear) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else {
            return arr[front];
        }
    }

    bool isEmpty() {
        if(front == rear) {
            return true;
        }
        else {
            return false;
        }
    }

    int getSize() {
        return rear - front;
    }
};

int main() {
    
    Queue q(10);
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    cout<<"Size of queue is : "<<q.getSize()<<endl;

    q.pop();

    cout<<"Size of queue is : "<<q.getSize()<<endl;

    cout<<"Front element is : "<<q.getFront()<<endl;

    if(q.isEmpty()) {
        cout<<"Queue is empty"<<endl;
    }
    else {
        cout<<"Queue is mot empty"<<endl;
    }


    return 0;
}
*/


// ********* CIRCULAR QUEUE *******
/*
#include <iostream>
using namespace std;

class CQueue {

    public:
    int size;
    int *arr;
    int front;
    int rear; 

    CQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push() {
        // queue full
        // single element case
        // circular nature
        // normal flow
        // TODO: add one more condition in the queue full if block
        if((front == 0 && rear == size-1)) {
            cout<<"Queue is full, cannot insert"<<endl;
        }
        else if(front == -1) {
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear = size-1 && front !=0) {
            rear = 0;
            arr[rear] = data;
        }
        else {
            rear++;
            arr[rear] = data;
        }
    }

    void pop() {
        // empty check
        // single element
        // circular nature
        // normal flow

        if(front == -1) {
            cout<<"Queue is empty, cannot pop"<<endl;
        }
        else if(front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(front == size-1) {
            front = 0;
        }
        else {
            front++;
        }
    }
};

int main() {
    




    return 0;
}
*/


// ***** DEQUE - DOUBLY ENDED QUEUE ********
/*
#include <iostream>
using namespace std;

class Deque {
    public:
    int size;
    int *arr;
    int front;
    int rear;

    Deque(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data) {
        // TODO: add one more condition in the queue full if block
        if(front == 0 && rear == size-1) {
            cout<<"Q is full, cannot insert"<<endl;
            return;
        }
        else if(front == -1) {
            front = rear = 0;
            
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = data;
    }

    void pushFront(int data) {
         // TODO: add one more condition in the queue full if block
        if(front == 0 && rear == size-1) {
            cout<<"Q is full, cannot insert"<<endl;
            return;
        }
        else if(front == -1) {
            front = rear = 0;   
        }
        else if(front == 0 && rear != size-1) {
            front = size-1;
        }
        else {
            front--;
        }
        arr[front] = data;
    }

    void popFront() {
        if(front == -1) {
            cout<<"Q is empty, cannot pop"<<endl;
            return;
        }
        else if(front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(front == size-1) {
            arr[front] = -1;
            front = 0;
        }
        else {
            arr[front] = -1;
            front++;
        }
    }

    void popRear() {
        if(rear == -1 && front -1) {
            cout<<"Q is empty, cannot pop"<<endl;
            return;
        }
        else if(front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(rear == 0) {
            arr[rear] = -1;
            rear = size-1;
        }
        else {
            arr[rear] = -1;
            rear--;
        }
    }

    void print() {
        for(int i=0; i<size; i++) {
            cout<<arr[i]<<" ";
        } cout<<endl;
    }
};

int main() {
    Deque dq(10);


    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushRear(30);
    dq.pushRear(40);
    dq.pushRear(50);
    dq.pushRear(60);
    dq.pushRear(70);
    dq.pushRear(80);


    dq.popRear();
    dq.popRear();
    dq.print();

    dq.popFront();
    dq.popFront();
    dq.popFront();
    dq.print();

    dq.pushFront(101);
    dq.pushFront(102);
    dq.pushFront(103);
    dq.pushFront(104);
    dq.pushFront(105);
    dq.print();

    dq.popFront();
    dq.print();

    return 0;
}
*/


// ******* DEQUE STL ********
/*
#include <iostream>
#include <deque>
using namespace std;

int main() {
    // creation
    deque<int> dq;

    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(30);

    cout<<"Size : "<<dq.size()<<endl;
    dq.pop_front();
    cout<<"Size : "<<dq.size()<<endl;
    dq.pop_back();
    cout<<"Size : "<<dq.size()<<endl;

    cout<<"Front: "<<dq.front()<<endl;
    cout<<"Back: "<<dq.back()<<endl;

    if(dq.empty()) {
        cout<<"DQ is empty"<<endl;
    }
    else {
        cout<<"DQ is not empty"<<endl;
    }

    return 0;
}
*/


// ****** REVERSE A QUEUE *******
/*
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Reverse using another stack
void reverseQueue(queue<int> &q) {

    stack<int> s;

    // step 1: put all elements of q into s
    while(!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    // step 2: put all element from stack to queue
    while(!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
}

// reverse using the recursion
void reverseQueueRecursion(queue<int>& q) {
    // base case
    if(q.empty()) {
        return;
    }

    // Step A
    int element = q.front();
    q.pop();

    // Step B
    reverseQueueRecursion(q);

    // Step C
    q.push(element);
     
}

int main() {
    
    queue<int> q;

    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    // reverseQueue(q);
    reverseQueueRecursion(q);

    // printing reverse queue
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;


    return 0;
}
*/


// ******* REVERSE FIRST K ELEMENT OF QUEUE ********
/*
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseK(queue<int> &q, int k) {
    int n = q.size();

    if(k <= 0 || k > n) {
        return;
    }

    // Step A : queue-> k elements -> stack
    stack<int> s;

    int count = 0;


    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if(count == k) {
            break;
        }
    }

    // Step B: stack -> q me wapas
    while(!s.empty()) {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    // Step C : push n-k element from q front to back
    count = 0;
    while(!q.empty() && n-k != 0) {
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count == n-k) {
            break;
        }
    }
}

int main() {
    
    queue<int> q;

    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    // reverseQueue(q);
    reverseK(q, 3);

    // printing reverse queue
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl; 


    return 0;
}
*/


// ********* INTERLEAVE FIRST AND SECOND HALF OF QUEUE *******
/*
#include <iostream>
#include <queue>
using namespace std;

void interLeaveQueue(queue<int> &q) {
    // step A: seprate both halves
    int n = q.size();
    if(q.empty()) {
        return;
    }
    int k = n/2;
    int count = 0;

    queue<int> q2;

    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;

        if(count == k) {
            break;
        }
    }

    // step B : start interleaving
    while(!q.empty() && !q2.empty()) {
        int first = q2.front();
        q2.pop();
        q.push(first);

        int second = q.front();
        q.pop();
        q.push(second);
    }

    // odd wala case
    if(n&1) {
        int element = q.front();
        q.pop();
        q.push(element);
    }
}

int main() {

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);

    interLeaveQueue(q);

    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}
*/


// ******** SLIDING WINDOW QUESTION, FFIND FIRST NEGATIVE INTEGER IN GIVEN K SIZE WINDOW **********
/*
#include <iostream>
#include <deque>
using namespace std;

void solve(int arr[], int size, int k) {
    deque<int> q;

    // process first window of size k
    for(int i=0; i<k; i++) {
        if(arr[i] < 0) {
            q.push_back(i);
        }
    }

    // process remaining window
    for(int i=k; i<size; i++) {
        // answer dedo purani window ka
        if(q.empty()) {
            cout<<0<<" ";
        }
        else {
            cout<<arr[q.front()]<<" ";
        }

        // out of window element ko remove krdo
        while((!q.empty()) && (i-q.front() >= k)) {
            q.pop_front();
        }

        // check current element for insertion
        if(arr[i] < 0) {
            q.push_back(i);
        }
    }

    // asnwer print karon last window ka
    if(q.empty()) {
        cout<<0<<" ";
    }
    else {
        cout<<arr[q.front()]<<" ";
    }
}

int main() {
    
    int arr[] = {12,-1,-7,8,-15,30,16,28};
    int size = 8;
    int k = 3;

    solve(arr, size, k);


    return 0;
}
*/


// ******** FIRST NON REPEATING CHARACTER IN A STREAM *******
/*
#include <iostream>
#include <queue>
using namespace std;

string solve(string str) {
    int freq[26] = {0};
    queue<char> q;

    string ans = "";

    for(int i=0; i<str.size(); i++) {
        char ch = str[i];

        // increment frequency
        freq[ch-'a']++;

        // q.push
        q.push(ch);

        while(!q.empty()) {
            if(freq[q.front() - 'a'] > 1) {
                q.pop();
            }
            else {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()) {
            ans.push_back('#');
        }
    }

    return ans;
}

int main() {
    
    string str = "zarcaazrd";

    cout<<"Answer: "<<solve(str)<<endl;

    return 0;
}
*/


// ********* CIRCULAR TOUR / GAS STATION *********
/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int deficit = 0; // kitna petrol kaam pad gaya
    int balance = 0; // kitna petrol bacha hua he
    int start = 0; // circuit kaha se start krre ho

    for(int i=0; i<gas.size(); i++) {
        balance = balance + gas[i] - cost[i];
        if(balance < 0) {
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }

    if(deficit + balance >= 0) {
        return start;
    }
    else {
        return -1;
    }

}


int main() {
    
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout<<"Answer: "<<canCompleteCircuit(gas, cost)<<endl;


    return 0;
}
*/


// ******** SLINDING WINDOW MAXIMUM *********
/*
#include <iostream>
#include <vector>
#include <deque>
#include <limits.h>
using namespace std;

vector<int> maxSlindingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> ans;

    // process first k element window
    for(int i=0; i<k; i++) {
        // chote element remove krdo
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        // inserting index so that we can check out of window element
        dq.push_back(i);
    }

    // store answer for first window
    ans.push_back(nums[dq.front()]);

    // remaining window ko process krna he
    for(int i=k; i<nums.size(); i++) {
        // out of window element ko remove krdia
        if(!dq.empty() && i-dq.front() >= k) {
             dq.pop_front();
        }

        // ab firse current element k liye chote element ko remove krna he
        // chote element remove krdo
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        // inserting index so that we can check out of window element
        dq.push_back(i);

        // current window ka answer store krna he
        ans.push_back(nums[dq.front()]);
    }

    return ans;

}

int main() {
    
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = maxSlindingWindow(nums, k);

    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/


// ********* QUEUE USING STACKS *******
/*
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    public:
    stack<int> s1, s2;

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        int pop = -1;
        if(!s2.empty()) {
            pop = s2.top();
        }
        else {
            while(!s1.empty) {
                s2.push(s1.top());
                s1.pop();
            }
            pop = s2.top();
        }
        s2.pop();
        return pop;
    }

    int peek() {
        int front = -1;
        if(!s2.empty()) {
            front = s2.top();
        }
        else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            front = s2.top();
        }
        return front;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    


    return 0;
}
*/


// ******* IMPLEMENT STACK USING QUEUE ********
/*
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    public:
    queue<int> q;
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size()-1; i++) {
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }

    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {





    return 0;
}
*/


// *********** FIND THE SUM OF MINIMUM AND MAXIMUM IN AN ARRAY ********
/*
#include <iostream>
#include <deque>
#include <stack>
#include <vector>
using namespace std;

int sumOfMinMaxOfAllWindowOfSizeK(vector<int> &nums, int k) {
    deque<int> dq, dq2;
    int ans = 0;

    // process first k element window
    for(int i=0; i<k; i++) {
        // chote element remove krdo
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        // bada element remove krdo
        while(!dq2.empty() && nums[i] <= nums[dq2.back()]) {
            dq2.pop_back();
        }

        // inserting index so that we can check out of window element
        dq.push_back(i);
        dq2.push_back(i);
    }

    // store answer for first window
    ans += nums[dq.front()] + nums[dq2.front()];

    // remaining window ko process krna he
    for(int i=k; i<nums.size(); i++) {
        // out of window element ko remove krdia
        if(!dq.empty() && i-dq.front() >= k) {
             dq.pop_front();
        }

        if(!dq2.empty() && i-dq2.front() <= k) {
             dq2.pop_front();
        }

        // ab firse current element k liye chote element ko remove krna he
        // chote element remove krdo
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        while(!dq2.empty() && nums[i] <= nums[dq2.back()]) {
            dq2.pop_back();
        }

        // inserting index so that we can check out of window element
        dq.push_back(i);
        dq2.push_back(i);

        // current window ka answer store krna he
        ans += nums[dq.front()] + nums[dq2.front()];
    }

    return ans;

}

int main() {
    
    vector<int> v{2,5,-1,7,-3,-1,-2};
    int k = 3;

    cout<<"Answer : "<<sumOfMinMaxOfAllWindowOfSizeK(v, k)<<endl;

    return 0;
}
*/


// ********* N QUEUES IN AN ARRAY ********
/*
#include <iostream>
using namespace std;

class KQueue {
    int n, k, freeSpot;
    int *arr, *front, *rear, *next;
    public:
    KQueue(int _n, int _k): n(_n), k(_k), freeSpot(0) {
        arr = new int [n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for(int i=0; i<k; i++) {
            front[i] = rear[i] = -1;
        }

        for(int i=0; i<n; i++) {
            next[i] = i+1;
        }
        next[n-1] = -1;
    }

    // push x into qith queue
    bool push(int x, int qi) {
        // over flow
        if(freeSpot == -1) {
            return false;
        }

        // find first free index
        int index = freeSpot;

        // update free spot
        freeSpot = next[index];

        // if first element in qi
        if(front[qi] == -1) {
            front[qi] = index;
        }
        else {
            // link new element to that Q's rearest element
            next[rear[qi]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    // pop element from qith queue
    int pop(int qi) {
        // underflow
        if(front[qi] == -1) {
            return -1;
        }

        // find index to pop
        int index = front[qi];

        // front update
        front[qi] = next[index];

        // update freespot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    ~KQueue() {
        delete []arr;
        delete []next;
        delete []front;
        delete []rear;
    }
};

int main() {
    KQueue kq(8,3);
    cout<<kq.push(1,0)<<endl;
    cout<<kq.push(2,0)<<endl;
    cout<<kq.push(5,1)<<endl;
    cout<<kq.push(3,0)<<endl;
    cout<<kq.pop(1)<<endl;
    cout<<kq.pop(1)<<endl;
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(0)<<endl;
    cout<<kq.pop(1)<<endl;

    return 0;
}
*/