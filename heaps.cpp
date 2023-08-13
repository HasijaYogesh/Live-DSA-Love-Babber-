// ********** INSERTION, DELETION, HEAPIFY AND HEAP SORT IN THE HEAP *******
/*
#include <iostream>
using namespace std;

class Heap {
    public:
    int arr[101];
    int size;

    Heap() {
        size = 0;
    }

    void insert(int value) {
        // value insert karo end me
        size = size + 1;
        int index = size;
        arr[index] = value;

        // iss value ko place at correct position
        while(index > 1) {
            int parent = index/2;
            if(arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    int deleteRoot() {
        int ans = arr[1];
        // replace root node value with last node data
        arr[1] = arr[size];
        size--;

        // place root node ka data on its correct position
        int index = 1;
        while(index<size) {
            int left = 2*index;
            int right = (2*index) + 1;
            int largest = index;
            if(left<size && arr[largest] < arr[left]) {
                largest = left;
            }
            if(right<size && arr[largest] < arr[right]) {
                largest = right;
            }

            if(largest == index) {
                // value is at correct position
                break; 
            }
            else {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
        return ans;
    }
};

void heapify(int arr[], int n, int i) {
    int index = i;
    int leftIndex = 2*i;
    int rightIndex = (2*i)+1;
    int largest = index;
    if(leftIndex <= n && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    }
    if(rightIndex <= n && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
    }

    if(index != largest) {
        // left ya right child me se koi > hogya current node se
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
    else {
        return;
    }
}

void buildHeap(int arr[], int n) {
    for(int i = n/2; i>0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    int index = n;

    while(n != 1) {
        swap(arr[1], arr[index]);
        index--;
        n--;

        heapify(arr, n, 1);
    }
}

int main() {
    
    // Heap h;
    // h.arr[0] = -1;
    // h.arr[1] = 100;
    // h.arr[2] = 50;
    // h.arr[3] = 60;
    // h.arr[4] = 40;
    // h.arr[5] = 45;
    // h.size = 5;

    // cout<<"Printing the head"<<endl;
    // for(int i=0; i<=h.size; i++) {
    //     cout<<h.arr[i]<<" ";
    // } cout<<endl;

    // h.insert(110);

    // cout<<"Printing the head"<<endl;
    // for(int i=0; i<=h.size; i++) {
    //     cout<<h.arr[i]<<" ";
    // } cout<<endl;


    int arr[] = {-1,12,56,43,6,78,87,5,44,3,23,32};

    int n = 11;

    buildHeap(arr, n);

    cout<<"Printing the heap"<<endl;
    for(int i=0; i<=n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;

    heapSort(arr, n);

    cout<<"Printing the sorted heap"<<endl;
    for(int i=0; i<=n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;

    return 0;
}
*/


// ******** PRIORITY QUEUE STL / MAX HEAP STL*********
/*
#include <iostream>
#include <queue>
using namespace std;

int main() {
    
    priority_queue<int> pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout<<"Top element: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Size: "<<pq.size()<<endl;
    
    cout<<"Empty check: "<<pq.empty()<<endl;

    return 0;
}
*/


// ********* MIN HEAP STL - PRIORITY QUEUE **********
/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // min->heap
    priority_queue<int, vector<int>, greater<int> > pq;

    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout<<"Top element: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Size: "<<pq.size()<<endl;
    cout<<"Top element: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Empty check: "<<pq.empty()<<endl;

    return 0;
}
*/


// ********* FIND KTH SMALLEST AND GREATEST ELEMENT IN ARRAY *********
/*
#include <iostream>
#include <queue>
using namespace std;

int getKthGreatestElement(int arr[], int n, int k) {
    // create a min heap
    priority_queue<int, vector<int>, greater<int> > pq;

    // insert initial K element of array
    for(int i=0; i<k; i++) {
        pq.push(arr[i]);
    }

    // for remaining element push only if they are less than top
    for(int i=k; i<n; i++) {
        int element = arr[i];
        if(element > pq.top()) {
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();
    return ans;
}

int getKthSmallestElement(int arr[], int n, int k) {
    // create a max heap
    priority_queue<int> pq;

    // insert initial K element of array
    for(int i=0; i<k; i++) {
        pq.push(arr[i]);
    }

    // for remaining element push only if they are less than top
    for(int i=k; i<n; i++) {
        int element = arr[i];
        if(element < pq.top()) {
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();
    return ans;
}

int main() {
    int arr[] = {10,5,20,4,15};
    int n = 5;
    int k = 2;

    int ans = getKthSmallestElement(arr,n,k);
    int ans1 = getKthGreatestElement(arr, n, k);
    cout<<"Answer is "<<ans<<endl;
    cout<<"Answer 1 is "<<ans1<<endl;


    return 0;
}
*/


// ********* MERGE K SORTED ARRAY **********
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class info {
    public:
    int data;
    int row;
    int col;

    info(int val, int r, int c) {
        data = val;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(info* a, info* b) {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(int arr[][4], int k, int n) {
    priority_queue<info*, vector<info*>, compare> minHeap;

    // hr array ka first element insert karo
    for(int i=0; i<k; i++) {
        info* temp = new info(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;
    while(!minHeap.empty()) {
        info* temp = minHeap.top();
        int topElement = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();

        ans.push_back(topElement);

        if(topCol + 1 < n) {
            info* newInfo = new info(arr[topRow][topCol+1], topRow, topCol+1);
            minHeap.push(newInfo);
        }
    }

    return ans;
}

int main() {
    int arr[][4] = {{2,4,6,8}, {1,3,5,7}, {0,9,10,11}};
    int k = 3;
    int n = 4;

    vector<int> ans = mergeKSortedArrays(arr, k, n);

    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/


// ********* SMALLEST RANGE COVERING ELEMENTS FROM K LISTS *******
/*
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

class node {
    public:
    int data;
    int row;
    int col;

    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
    public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int> >& nums) {
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<node*, vector<node*>, compare> minHeap;
    int k = nums.size();
    for(int i=0; i<k; i++) {
        int element = nums[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new node(element, i, 0));
    }

    int ansStart = mini;
    int ansEnd = maxi;

    while(!minHeap.empty()) {
        node* top = minHeap.top();
        int topElement = top->data;
        int topRow = top->row;
        int topCol = top->col;
        minHeap.pop();

        // mini updated
        mini = topElement;

        // check for answer
        int currRange = maxi - mini;
        int ansRange = ansEnd - ansStart;
        if(currRange < ansRange) {
            ansStart = mini;
            ansEnd = maxi;
        }

        // check for new element in the same list
        if(topCol + 1 < nums[topRow].size()) {
            maxi = max(maxi, nums[topRow][topCol+1]);
            node* newNode = new node(nums[topRow][topCol+1], topRow, topCol+1);
            minHeap.push(newNode);
        }
        else {
            // there is no element in the same array or list
            break;
        }
    }

    vector<int> ans;
    ans.push_back(ansStart);
    ans.push_back(ansEnd);
    return ans;
}

int main() {
    
    vector<vector<int>> input{{4,10,15,24,26}, {0,9,12,20}, {5,18,22,3,2}};

    vector<int> ans = smallestRange(input);

    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/


// ******** LEET CODE NO. 1962 - REMOVE STONES TO MINIMIZE THE TOTAL **********
/*
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> maxHeap;

    for(int i=0; i<piles.size(); i++) {
        maxHeap.push(piles[i]);
    }

    while(k--) {
        int maxElement = maxHeap.top();
        maxHeap.pop();
        maxElement = maxElement - floor(maxElement/2);
        maxHeap.push(maxElement);
    }

    int sum = 0;
    while(!maxHeap.empty()) {
        int temp = maxHeap.top();
        maxHeap.pop();
        sum += temp;
    }

    return sum;
}

int main() {
    
    vector<int> input{5,4,9};
    int k = 2;

    cout<<"Answer is: "<<minStoneSum(input, k)<<endl;

    return 0;
}
*/


// ******** LEET CODE 767 - REORGANIZE STRING ********
/*
#include <iostream>
#include <queue>
using namespace std;

class node {
    public:
    char data;
    int count;

    node(char d, int c) {
        data = d;
        count = c;
    }
};

class compare {
    public:
    bool operator()(node a, node b) {
        return a.count < b.count;
    }
};

string reorganizeString(string s) {

    // create mapping
    int freq[26] = {0};

    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        freq[ch-'a']++;
    }

    priority_queue<node, vector<node>, compare> maxHeap;

    for(int i=0; i<26; i++) {
        if(freq[i] != 0) {
            node temp(i+'a', freq[i]);
            maxHeap.push(temp);
        }
    }

    string ans = "";

    while(maxHeap.size() > 1) {
        node first = maxHeap.top();
        maxHeap.pop();
        node second = maxHeap.top();
        maxHeap.pop();

        ans += first.data;
        ans += second.data;

        first.count--;
        second.count--;

        if(first.count != 0) {
            maxHeap.push(first);
        }
        if(second.count != 0) {
            maxHeap.push(second);
        }
    }

    if(maxHeap.size() == 1) {
        node temp = maxHeap.top();
        maxHeap.pop();
        if(temp.count == 1) {
            ans += temp.data;
        }
        else {
            return "";
        }
    }
    return ans;
}

int main() {
    
    string input = "aab";

    string ans = reorganizeString(input);

    cout<<"Answer is: "<<ans<<endl;


    return 0;
}
*/


// ******** LEET CODE 1405 - LONGEST HAPPY STRING *********
/* 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node {
    public:
    int data;
    int count;

    node(char d, int c) {
        data = d;
        count = c;
    }
};

class compare {
    public:
    bool operator()(node a, node b) {
        return a.count < b.count;
    }
};

string longestDiverseString(int a, int b, int c) {
    priority_queue<node, vector<node>, compare> maxHeap;

    if(a > 0) {
        node temp('a', a);
        maxHeap.push(temp);
    }
    if(b > 0) {
        node temp('b', b);
        maxHeap.push(temp);
    }
    if(c > 0) {
        node temp('c', c);
        maxHeap.push(temp);
    }

    string ans = "";

    while(maxHeap.size() > 1) {
        node first = maxHeap.top();
        maxHeap.pop();
        node second = maxHeap.top();
        maxHeap.pop();

        if(first.count >= 2) {
            ans += first.data;
            ans += first.data;
            first.count -= 2;
        }
        else {
            ans += first.data;
            first.count--;
        }

        if(second.count >= 2 && second.count >= first.count) {
            ans += second.data;
            ans += second.data;
            second.count -= 2;
        }
        else {
            ans += second.data;
            second.count--;
        }

        if(first.count > 0) {
            maxHeap.push(first);
        }

        if(second.count > 0) {
            maxHeap.push(second);
        }
    }

    if(maxHeap.size() == 1) {
        node temp = maxHeap.top();
        maxHeap.pop();

        if(temp.count >= 2) {
            ans += temp.data;
            ans += temp.data;
            temp.count -= 2;
        }
        else {
            ans += temp.data;
            temp.count--;
        }
    }

    return ans;
}

int main() {
    
    int a = 0, b = 8, c = 11;

    string ans = longestDiverseString(a,b,c);

    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ********** FIND MEDIAN IN THE GIVEN UNSORTED DATA STREAM ********
/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int signum(int a, int b) {
    if(a == b) {
        return 0;
    }

    if(a > b) {
        return 1;
    }

    if(a < b) {
        return -1;
    }
}

// This method is using if else statements
void callMedian(double &median, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int> >& minHeap, int element) {

    switch(signum(minHeap.size(), maxHeap.size())) {
        case 0:
             if(element > median) {
                minHeap.push(element);
                median = minHeap.top();
            }
            else {
                maxHeap.push(element);
                median = maxHeap.top();
            }
            break;

        case 1:
            if(element > median) {
                int minTop = minHeap.top();
                minHeap.pop();
                maxHeap.push(minTop);
                minHeap.push(element);
                median = (maxHeap.top() + minHeap.top())/2.0;
            }
            else {
                maxHeap.push(element);
                median = (maxHeap.top() + minHeap.top())/2.0;
            }
            break;

        case -1:
            if(element > median) {
                minHeap.push(element);
                median = (maxHeap.top() + minHeap.top())/2.0;
            }
            else {
                int maxTop = maxHeap.top();
                maxHeap.pop();
                minHeap.push(maxTop);
                maxHeap.push(element);
                median = (maxHeap.top() + minHeap.top())/2.0;
            }
            break;
    }
    
    // Below code is using normal if else condition and above code is using switch case statements
    // if(minHeap.size() == maxHeap.size()) {
    //     if(element > median) {
    //         minHeap.push(element);
    //         median = minHeap.top();
    //     }
    //     else {
    //         maxHeap.push(element);
    //         median = maxHeap.top();
    //     }
    // }

    // else if(maxHeap.size() > minHeap.size()) {
    //     if(element > median) {
    //         minHeap.push(element);
    //         median = (maxHeap.top() + minHeap.top())/2;
    //     }
    //     else {
    //         int maxTop = maxHeap.top();
    //         maxHeap.pop();
    //         minHeap.push(maxTop);
    //         maxHeap.push(element);
    //         median = (maxHeap.top() + minHeap.top())/2;
    //     }
    // }

    // // Else case is for - maxHeap.size() < minHeap.size();
    // else {
    //     if(element > median) {
    //         int minTop = minHeap.top();
    //         minHeap.pop();
    //         maxHeap.push(minTop);
    //         minHeap.push(element);
    //         median = (maxHeap.top() + minHeap.top())/2;
    //     }
    //     else {
    //         maxHeap.push(element);
    //         median = (maxHeap.top() + minHeap.top())/2;
    //     }
    // }
}
 
int main() {
    
    int arr[12] = {5,15,1,3,2,8,7,9,10,6,11,4};
    int n = 12;

    double median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for(int i=0; i<n; i++) {
        int element = arr[i];
        callMedian(median, maxHeap, minHeap, element);
        cout<<"arr[i] -> "<<median<<endl;
    }

    return 0;
}
*/


// ******** CHECK IF THE BST IS A MAX HEAP OR NOT *******
/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int nodeCount(struct Node* root) {
    if(!root) {
        return 0;
    }

    int l = nodeCount(root->left);
    int r = nodeCount(root->right);

    return 1 + l + r;
}

bool isCBT(struct Node* root, int i, int& n) {
    if(!root) {
        return true;
    }

    if(i > n) {
        return false;
    }
    return isCBT(root->left, 2*i, n) && isCBT(root->right, (2*i)+1, n);
}

bool isMaxOrder(struct Node* root) {
    if(!root) {
        return true;
    }

    int l = isMaxOrder(root->left);
    int r = isMaxOrder(root->right);

    int ans = false;

    if(!root->left && !root->right) {
        ans = true;
    }

    else if(root->left && !root->right) {
        ans = root->data > root->left->data;
    }
    else {
        ans = root->data > root->left->data && root->data > root->right->data;
    }

    return ans && l && r;
}

bool isHeap(struct Node* tree) {
    int n = nodeCount(tree);
    int i = 1;

    return isCBT(tree, i, n) && isMaxOrder(tree);
}

int main() {
    
    Node* root = new Node(30);
    Node* first = new Node(20);
    Node* second = new Node(10);

    root->left = first;
    root->right = second;

    cout<<"Answer is "<<isHeap(root);

    return 0;
}
*/


// ******* MERGE TWO MAX HEAP *********
/*
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v, int i, int n) {
    while(true) {
        int left = 2*i+1;
        int right = 2*i+2;

        int swapIndex = i;
        if(left < n && v[left] > v[i]) {
            swapIndex = left;
        }
        if(right < n && v[right] > v[swapIndex]) {
            swapIndex = right;
        }
        if(swapIndex == i) {
            break;
        }
        else {
            swap(v[i], v[swapIndex]);
        }
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // 1. Merge two heap vectors
    vector<int> c(a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());

    // 2. Lets heapify vector c
    for(int i=((c.size()/2)-1); i>=0; --i) {
        heapify(c, i, c.size());
    }

    return c;
}

int main() {

    vector<int> a{10,5,6,2};
    vector<int> b{12,7,9};
    int n = a.size(), m = b.size();

    vector<int> c = mergeHeaps(a, b, n, m);

    for(auto val: c) {
        cout<<val<<" ";
    }
    cout<<endl;


    return 0;
}
*/


// ********* K-CLOSEST POINTS TO ORIGIN ********
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class myComp {
    public:
    bool operator()(pair<int, int> &a, pair<int,int> &b) {
        int distA = a.first*a.first + a.second*a.second;
        int distB = b.first*b.first + b.second*b.second;

        return distA > distB;
    }
};

vector<vector<int>> KClosest(vector<vector<int>>& points, int k) {

    vector<vector<int>> ans;
    priority_queue<pair<int, int>, vector<pair<int,int>>, myComp> pq; // min heap based on giving higher priority to point closer to origin.

    for(auto p: points) {
        pq.push({p[0], p[1]});
    }
    while(!pq.empty() && k--) {
        auto& top = pq.top();
        ans.push_back({top.first, top.second});
        pq.pop();
    }

    return ans;
}

int main() {
    vector<vector<int>> points = {{1,3},{-2,2}};
    int k = 1;

    vector<vector<int>> ans = KClosest(points, k);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}
*/


// ********* FIND THE MAXIMUM ELEMENT IN SLIDING WINDOW ********
/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int,int>> pq; // pair<value,index>
    vector<int> ans;


    // consider first window
    for(int i=0; i<k; i++) {
        pq.push({nums[i], i});
    }

    // store max of first window
    ans.push_back(pq.top().first);

    // consider rest of the windows
    for(int i=k; i<nums.size(); i++) {
        pq.push({nums[i], i});

        // remove if max are from previous window
        while(pq.top().second <= i-k) {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }

    return ans;
}

int main() {
    
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/


// ********* LEET CODE 1878 - GET THE BIGGEST THREE RHOMBUS SUMS IN A GRID ******** 
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool checkBounds(vector<vector<int>>& grid, vector<pair<int,int>>& v) {
    int m = grid.size();
    int n = grid[0].size();

    for(auto pt:v) {
        if(pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n) {
            return false;
        }
    }

    return true;
}

bool getAllVertices(vector<vector<int>>& grid, vector<pair<int,int>>& v, pair<int,int> c, int& delta) {
    pair<int, int> A(c.first-delta, c.second);
    pair<int, int> B(c.first, c.second+delta);
    pair<int, int> C(c.first+delta, c.second);
    pair<int, int> D(c.first, c.second-delta);

    v[0] = A;
    v[1] = B;
    v[2] = C;
    v[3] = D;

    if(checkBounds(grid, v)) {
        return true;
    }
    else {
        return false;
    }
}

void getAllSum(vector<vector<int>>& grid, int& cx, int& cy, priority_queue<int>& pq) {
    // push rhombus sum of rhombus with area 0
    pq.push(grid[cx][cy]);

    int delta = 1;
    vector<pair<int,int>> v(4);

    while(getAllVertices(grid, v, {cx, cy}, delta)) {
        pair<int, int>& A = v[0];
        pair<int, int>& B = v[1];
        pair<int, int>& C = v[2];
        pair<int, int>& D = v[3];

        int cSum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];

        // all cells between AB
        for(int i=1; i<(B.first-A.first); i++) {
            cSum += grid[A.first+i][A.second+i];
        }
        // all cells between BC
        for(int i=1; i<(C.first-B.first); i++) {
            cSum += grid[B.first+i][B.second-i];
        }
        // all cells between CD
        for(int i=1; i<(C.first-D.first); i++) {
            cSum += grid[C.first-i][C.second-i];
        }
        // all cells between DA
        for(int i=1; i<(D.first-A.first); i++) {
            cSum += grid[D.first-i][D.second+i];
        }

        pq.push(cSum); // rhomus sum has been pushed
        delta++;
    }
}

bool canPush(vector<int>& ans, int& top) {
    for(auto val: ans) {
        if(val == top) {
            return false;
        }
    }
    return true;
}

vector<int> getBiggestThree(vector<vector<int>>& grid) {
    vector<int> ans;
    priority_queue<int> pq; // set can be used here as well
    int m = grid.size();
    int n = grid[0].size();

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            getAllSum(grid, i, j, pq);
        }
    }

    while (!pq.empty() && ans.size() < 3) {
        int top = pq.top();
        pq.pop();
        if(canPush(ans, top)) {
            ans.push_back(top);
        }
    }
    return ans;
}

int main() {

    vector<vector<int>> grid{{3,4,1,5,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};

    vector<int> ans = getBiggestThree(grid);  

    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;


    return 0;
}
*/


// ****** LEET CODE - 2163 ***********
/*
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

#define ll long long

long long minimumDifference(vector<int>& nums) {
    int n = nums.size()/3;
    
    vector<ll> prefix(nums.size(), -1), suffix(nums.size(), -1);
    // prefix[i] = sum of first n elements from left side
    // sufix[i] = sum of first n elements from right side

    ll sum = 0; // minimum n elements sum
    priority_queue<ll> pq; // max heap

    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];
        pq.push(nums[i]);

        // pop out maximum element
        if(pq.size() > n) {
            sum -= pq.top();
            pq.pop();
        }

        if(pq.size() == n) {
            prefix[i] = sum;
        }
    }

    sum = 0; // maximum n elements sum
    priority_queue<ll, vector<ll>, greater<ll> > pq2; // min heap 
    for(int i=nums.size()-1; i>=0; i--) {
        sum += nums[i];
        pq2.push(nums[i]);

        // pop out minimum element
        if(pq2.size() > n) {
            sum -= pq2.top();
            pq2.pop();
        }

        if(pq2.size() == n) {
            suffix[i] = sum;
        }
    }

    ll ans = LONG_LONG_MAX;
    for(int i=n-1; i<2*n; i++) {
        ans = min(ans, prefix[i] - suffix[i+1]);
    }

    return ans;
}

int main() {
    
    vector<int> input{7,9,5,8,1,3};

    ll ans = minimumDifference(input);

    cout<<"ANswer is "<<ans<<endl;


    return 0;
}
*/


// ******** LEET CODE 871 - MINIMUM NUBER OF REFUELING STOPS *********
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int stops = 0;
    int dist = 0;
    int i = 0;

    int fuel = startFuel;
    priority_queue<pair<int,int>> pq; //{fuel, position}

    while(true) {
        while(i < stations.size()) {
            // push stations with the reach with my current fuel levels from my current pos.
            if(stations[i][0] <= dist + fuel) {
                pq.push({stations[i][1], stations[i][0]});
            }
            else {
                break;
            }
            ++i;
        }

        // travel with full fuel level
        dist += fuel;
        fuel = 0;

        // reached
        if(dist >= target) {
            break;
        }

        // no fuel stations with reach
        if(pq.empty()) {
            stops = -1;
            break;
        }

        // refuel and re-adjust dist & fuel based on the distance travelled and fuel used till that station
        auto& top = pq.top();
        fuel = (dist - top.second) + top.first;
        dist = top.second;
        pq.pop();
        ++stops;
    }

    return stops;
}

int main() {

    


    return 0;
}
*/