// ******* BASIC STACKS *******
/*
#include <iostream>
#include <stack>
using namespace std;

int main() {
    // creation
    stack<int> st;

    // insertion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // remove
    st.pop();

    // check element
    cout<<"Element on top - "<<st.top()<<endl;

    // size
    cout<<"Size of stack - "<<st.size()<<endl;

    // empty
    if(st.empty()) {
        cout<<"Stack is empty"<<endl;
    }
    else {
        cout<<"Stack is not empty"<<endl;
    }


    return 0;
}
*/


// ******** PRINTING THE STACK *********
/*
#include <iostream>
#include <stack>
using namespace std;

int main() {
    
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<endl;
    cout<<"Stack is empty - "<<s.empty()<<endl;

    return 0;
}
*/


// ********* MAKING OUR OWN STACK THROUGH CLASS ***********
/*
#include <iostream>
using namespace std;

class Stack {
    private:
    int* arr;
    int top;
    int size;

    public:
    Stack(int size) {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    // functions
    void push(int data) {
        if(size - top > 1) {
            // space available
            // insert
            top++;
            arr[top] = data;
        }
        else {
            // space not available
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop() {
        if(top == -1) {
            // stack is empty
            cout<<"Stack underflow, cant delete element"<<endl;
        }
        else {
            // stack is not empty
            top--;
        }
    }

    int getTop() {
        if(top == -1) {
            cout<<"SThere is no element in stack"<<endl;
        }
        else {
            return arr[top];
        }
    }

    // number of valid element in stack
    int getSize() {
        return top+1;
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    
    Stack s(5);

    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while(!s.isEmpty()) {
        cout<<s.getTop()<<" ";
        s.pop();
    } cout<<endl;

    cout<<"Size of stack - "<<s.getSize()<<endl;

    s.pop();

    return 0;
}
*/


// ******* TWO STACK IN A SINGLE ARRAY *********
/*
#include <iostream>
using namespace std;

class Stack {
    public:
    int* arr;
    int size;
    int top1;
    int top2;

    Stack(int size) {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    // functions 
    void push1(int data) {
        if(top2-top1 == 1) {
            // space not available
            cout<<"Stack 1 overflow!"<<endl;
        }
        else {
            // space available
            top1++;
            arr[top1] = data;
        }
    }

    void pop1() {
        // stack empty
        if(top1 == -1) {
            cout<<"Stack 1 underflow!"<<endl;
        }
        // stack not empty
        else {
            arr[top1] = 0;
            top1--;
        }
    }

    void push2(int data) {
        if(top2-top1 == 1) {
            // space not available
            cout<<"Stack 2 overflow"<<endl;
        }
        else {
            // space available
            top2--;
            arr[top2] = data;
        }
    }

    void pop2() {
        if(top2 == size) {
            // stack 2 is empty
            cout<<"Stack 2 underflow!"<<endl;
        }
        else {
            // stack 2 not empty
            arr[top2] = 0;
            top2++;
        }
    }

    void print() {
        cout<<endl;
        cout<<"Top1 - "<<top1<<endl;       
        cout<<"Top2 - "<<top2<<endl;       
        for(int i=0; i<size; i++) {
            cout<<arr[i]<<" ";
        } cout<<endl;
    }
};

int main() {

    Stack s(10);

    s.push1(10);
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();
    s.push1(40);
    s.print();
    s.push1(50);
    s.print();


    s.push2(100);
    s.print();
    s.push2(110);
    s.print();
    s.push2(120);
    s.print();
    s.push2(130);
    s.print();
    s.push2(140);
    s.print();
    s.push2(150);
    s.print();

    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();

    s.push2(1000);
    s.print();
    s.push2(1111);
    s.print();

    s.pop1();
    s.print();


    return 0;
}
*/


// ******* REVERSE STRING USING STACK ********
/*
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str = "babbar";

    stack<char> s;

    for(int i=0; i<str.length(); i++) {
        s.push(str[i]);
    }

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    } cout<<endl;

    return 0;
}
*/


// ********** FIND MID IN A STACK *******
/*
#include <iostream>
#include <stack>
using namespace std;

void printMiddle(stack<int> s, int& totalSize) {
    // stack is empty
    if(s.size() == 0) {
        cout<<"No element in stack!"<<endl;
        return;
    }
    // base case
    if(s.size() == (totalSize/2)+1) {
        cout<<"Middle element is - "<<s.top()<<endl;
    }

    int temp = s.top();
    s.pop();

    printMiddle(s, totalSize);

    s.push(temp);
}

int main() {
    
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int size = s.size();
    printMiddle(s, size);


    return 0;
}
*/


// ********** INSERT TOPMOST ELEMENT TO BOTTOM **********
/*
#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int &target) {
    if(s.empty()) {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    solve(s, target);

    s.push(topElement);
}

void insertAtBottom(stack<int> &s) {
    if(s.empty()) {
        cout<<"Stack is empty, cant insert at bottom"<<endl;
        return;
    }
    int target = s.top();
    s.pop();
    solve(s, target);
}

int main() {
    
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    insertAtBottom(s);

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    } cout<<endl;

    return 0;
}
*/


// ********** REVERSE THE STACK ***********
/*
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int &target) {
    if(s.empty()) {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    insertAtBottom(s, target);

    s.push(topElement);
}

void reverseStack(stack<int> &s) {
    // base case
    if(s.empty()) {
        return;
    }

    int target = s.top();
    s.pop();

    reverseStack(s);

    // insert at bottom target to

    insertAtBottom(s, target);
}

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverseStack(s);

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    } cout<<endl;


    return 0;
}
*/


// ******** CHECK FOR VALID PARANTHESES *********
/*
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(int i=0; i<s.length(); i++) {
        char ch = s[i];

        // opening bracket
        if( ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // closing bracket
        else {
            if(!st.empty()) {
                char topCh = st.top();
                if(ch == ')' && topCh == '(') {
                    // matching brackets
                    st.pop();
                }
                else if(ch == ']' && topCh == '[') {
                    // matching brackets
                    st.pop();
                }
                else if(ch == '}' && topCh == '{') {
                    // matching brackets
                    st.pop();
                }
                else {
                    // brackets not matching
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    if(st.empty()) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string s = "({[]})";

    bool ans = isValid(s);

    if(ans) cout<<"Valid"<<endl;
    else cout<<"Not valid!"<<endl;


    return 0;
}
*/


// ******* SORT A STACK *********
/*
#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int>& s, int target) {
    // base case
    if(s.empty()) {
        s.push(target);
        return;
    }
    if(s.top() > target) {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    insertSorted(s, target);

    // back track
    s.push(topElement);
}

void sortStack(stack<int> &s) {
    // base case
    if(s.empty()) {
        return;
    }

    int topElement = s.top();
    s.pop();

    sortStack(s);

    insertSorted(s, topElement);
}

int main() {
    
    stack<int> s;

    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    sortStack(s);

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
*/


// ******** REMOVE UNWANTED PARANTHESES **********
/*
#include <iostream>
#include <stack>
using namespace std;

bool solve(char ch, stack<char>& st) {
    while(!st.empty()) {
        if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
            while(st.top() != '(') {
                st.pop();
            }
            st.pop();
            return true;
        }
        if(st.top() == '(') {
            return false;
        } 
    } 
    return false;
}

bool checkForUnwantedBrackets(string s) {
    stack<char> st;

    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            st.push(s[i]);
        }
        if(s[i] == ')') {
            bool ans = solve(s[i], st);
            if(!ans) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string s = "(((a+b) + d))";

    int ans = checkForUnwantedBrackets(s);
    if(ans) {
        cout<<"No unwanted parantheses.."<<endl;
    }
    else {
        cout<<"Unwanted parantheses exists!"<<endl;
    }

    return 0;
}
*/


// ********* CREATE A STACK WITH PUSH, POP, TOP, GET MIN FUNCTION IN O(1) COMPLEXITY ********
/*
#include <iostream>
#include <vector>
using namespace std;

class MinStack {
    public:
    vector<pair<int,int> >st;

    MinStack() {

    }

    void push(int val) {
        if(st.empty()) {
            pair<int,int> p = make_pair(val, val);
            st.push_back(p);
        }
        else {
            pair<int,int> p;
            p.first = val;
            p.second = min(val, st.back().second);
            st.push_back(p);
        }
    }

    void pop() {
        if(st.empty()) {
            cout<<"Stack underflow"<<endl;
        }
        else {
            st.pop_back();
        }
    }

    int top() {
        if(st.empty()) {
            return -1;
        }
        return st.back().first;
    }

    int getMin() {
        if(st.empty()) {
            return -1;
        }
        return st.back().second;
    }
};

int main() {
    MinStack sk;

    sk.push(2);
    sk.push(1);
    sk.push(6);
    sk.push(5);

    cout<<sk.top()<<endl;
    sk.pop();
    cout<<sk.top()<<endl;

    cout<<sk.getMin()<<endl;


    return 0;
}
*/


// ********** LONGEST VALID PARENTHESES **********
/*
#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int maxLen = 0;
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        if(ch == '(') {
            st.push(i);
        }
        else {
            st.pop();
            if(st.empty()) {
                st.push(i);
            }
            else {
                int len = i - st.top();
                maxLen = max(len, maxLen);
            }
        }
    }
    return maxLen;
}

int main() {
    
    string s = "(()()";

    cout<<"Length of valid parentheses - "<<longestValidParentheses(s)<<endl;

    return 0;
}
*/


// ******* NEXT SMALLER ELEMENT IN AN ARRAY *******
/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    
    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);

    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    for(int i=input.size()-1; i>=0; i--) {
        int curr = input[i];
        // appka answer stack me
        while(s.top()>=curr) {
            s.pop();
        }
        // choota element mil chuka he
        ans[i] = s.top();
        s.push(curr);
    }
    cout<<"Printing ans : ";
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    } cout<<endl;
    return 0;
}
*/


// ******* PREVIOUS SMALLER ELEMENT IN AN ARRAY *******
/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> previousSmallestElement(vector<int> input) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    for(int i=0; i<input.size(); i++) {
        int curr = input[i];
        while(s.top()>=curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

void printVector(vector<int> arr) {
    cout<<"Printing vector : ";
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int main() {
    
    vector<int> input{2,1,4,3};

    vector<int> ans = previousSmallestElement(input);
    printVector(ans);
    return 0;
}
*/


// *********** MAXIMUN AREA IN THE HISTOGRAM ************
/*
#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

vector<int> previousSmallestElement(vector<int> &input) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    for(int i=0; i<input.size(); i++) {
        int curr = input[i];
        while(s.top() != -1 && input[s.top()]>=curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> nextSmallestElement(vector<int> &input) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    for(int i=input.size()-1; i>=0; i--) {
        int curr = input[i];
        // appka answer stack me
        while(s.top() != -1 && input[s.top()]>=curr) {
            s.pop();
        }
        // choota element mil chuka he
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int getRectangularAreaHistogram(vector<int> &height) {

    // step 1 : prev smaller output
    vector<int> prev = previousSmallestElement(height);

    // step 2 : next smaller output
    vector<int> next = nextSmallestElement(height);

    int maxArea = INT_MIN;

    for(int i=0; i<height.size(); i++) {
        int length = height[i];
        int prevSmall = prev[i];
        int nextSmall = next[i] != -1 ? next[i] : height.size();
        int width = nextSmall - prevSmall - 1;

        int area = length * width;

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<int> input{2,1,5,6,2,3};

    cout<<"Max area - "<<getRectangularAreaHistogram(input)<<endl;


    return 0;
}
*/


// ****** REMOVE ALL ADJACENT STRING *******
/*
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;

    for(auto ch : s) {
        if(!st.empty() && st.top() == ch) {
            // [pair up]
            st.pop();
        }
        else {
            st.push(ch);
        }
    }

    string ans;
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s = "azxxzy";

    string ans = removeDuplicates(s);
    cout<<"Answer : "<<ans<<endl;

    return 0;
}
*/


// ******* MINIMUM BRACKETS REVERSALS // COUNT THE REVERSALS ***********
/*
#include <iostream>
#include <stack>
using namespace std;

int countRev(string s) {
    // is odd size string then impossible to make pair
    if(s.size() & 1) {
        return -1;
    }

    int ans = 0;

    stack<char> st;

    for(char ch: s) {
        if(ch == '{') {
            st.push(ch);
        }
        else {
            if(!st.empty() && st.top() == '{') {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
    }

    // if stack is still not empty, lets count reversals

    while(!st.empty()) {
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();

        if(a == b) {
            ans += 1;
        }
        else {
            ans += 2;
        }
    }
    return ans;
}

int main() {
    string s = "}{{}}{{{";

    cout<<"Answer is - "<<countRev(s)<<endl;


    return 0;
}
*/


// ********* NEXT GREATER NODE IN LINKED LIST *********
/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextLargerNode(vector<int> ll) {
    stack<int> st;
    vector<int> ans(ll.size()); // initialization with 0

    for(int i=0; i<ll.size(); i++) {

        while(!st.empty() && ll[i] > ll[st.top()]) {
            // means Ith element is the next greater of the element index present in stack
            int kids = st.top();
            st.pop();
            ans[kids] = ll[i];
        }
        st.push(i);
    }

    return ans;
} 

int main() {
    // Assuming we have created a vector from a linked list
    vector<int> v{2,1,7,4,3,5};

    vector<int> ans = nextLargerNode(v);

    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;



    return 0;
}
*/


// ********* FIND THE CELEBRITY PRESENT IN THE PARTY OR NOT *******
/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int> > &M, int n) {
    stack<int> st;

    // step 1 : push all person into stack
    for(int i=0; i<n; i++) {
        st.push(i);
    }

    // step 2 : search for the celebrity by top two person in stack *** RUN DISCARD METHOD TO GET A MIGH BE CELEBRITY ******
    while(st.size() != 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        
        // if a knows b?
        if(M[a][b]) {
            // a is not a celebrity, b might be
            st.push(b);
        }
        else {
            // b is not a celebrity, a might be
            st.push(a);
        }
    }

    // step 3 : check that the remaining person is actaul a celebrity or not
    int mightBeCelebrity = st.top();
    st.top();

    // celebrity should not know anyone
    for(int i=0; i<n; i++) {
        if(M[mightBeCelebrity][i] != 0) {
            return -1;
        }
    }

    // other everyone should know celebrity
    for(int i=0; i<n; i++) {
        if(M[i][mightBeCelebrity] == 0 && i != mightBeCelebrity) {
            return -1;
        }
    }

    // the remaining person is actaully a celebrity
    return mightBeCelebrity;
}

int main() {

    vector<vector<int> > v{{0,1,0}, {0,0,0}, {0,1,0}};
    int n = 3;
    cout<<"Celebrity : "<<celebrity(v, n)<<endl;


    return 0;
}
*/


// ********** IMPORTANT **********
// ********* N STACKS IN AN ARRAY *********
/*
#include <iostream>
using namespace std;

class NStack {
    int *a, *top, *next;
    int n; // number of stack
    int size; // size of main array
    int freeSpot; // tells free space in main array

    public:
    NStack(int _n, int _s): n(_n), size(_s) {
        freeSpot = 0;
        a = new int[size];
        top = new int [n];
        next = new int [size];

        for(int i=0; i<n; i++) {
            top[i] = -1;
        }

        for(int i=0; i<size; i++) {
            next[i] = i+1;
        }
        next[size-1] = -1;
    }

    // push x into mth stack
    bool push(int x, int m) {
        if(freeSpot == -1) {
            cout<<"Stack overflow"<<endl;
            return false;
        }

        // step 1 : find index
        int index = freeSpot;

        // step 2 : update freespot
        freeSpot = next[index];

        // step 3 : insert into main array
        a[index] = x;

        // step 4 : update next
        next[index] = top[m-1];

        // step 5 : update top
        top[m-1] = index;

        // push success
        return true;
    }

    // pop from mth stack
    int pop(int m) {
        if(top[m-1] == -1) {
            cout<<"Stack underflow"<<endl;
            return -1;
        }

        // steps of pop function will be reverse of push function
        int index = top[m-1];

        top[m-1] = next[index];

        int poppedElement = a[index];

        next[index] = freeSpot;

        freeSpot = index;

        return poppedElement;
    }

    ~NStack() {
        delete []a;
        delete []top;
        delete []next;
    }
};

int main() {
    
    NStack s(3, 6);

    cout<<s.push(10,1)<<endl;
    cout<<s.push(11,1)<<endl;
    cout<<s.push(12,1)<<endl;
    cout<<s.push(14,2)<<endl;
    cout<<s.push(15,3)<<endl;
    cout<<s.pop(1)<<endl;
    cout<<s.pop(2)<<endl;

    return 0;
}
*/


// ******** ONLINE STOCK SPAN *********
/*
#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
    public:
    stack<pair<int, int>> st;
    StockSpanner() {

    }

    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main() {
    
    StockSpanner a;

    cout<<a.next(100)<<" ";
    cout<<a.next(80)<<" ";
    cout<<a.next(60)<<" ";
    cout<<a.next(70)<<" ";
    cout<<a.next(60)<<" ";
    cout<<a.next(75)<<" ";
    cout<<a.next(85)<<" ";

    return 0;
}
*/


// ********** SIMPLIFY PATH ********
/*
#include <iostream>
#include <stack>
using namespace std;

void buildAns(stack<string>&s, string &ans) {
    if(s.empty()) {
        return;
    }

    string minPath = s.top();
    s.pop();
    buildAns(s, ans);

    ans += minPath;
}

string simplifyPath(string path) {
    stack <string> s;

    int i = 0;
    while(i<path.size()) {
        int start = i;
        int end = i+1;

        while(end < path.size() && path[end] != '/') {
            end++;
        }
        string minPath = path.substr(start, end - start);
        i = end;
        if(minPath == "/" || minPath == "/.") {
            continue;
        }
        if(minPath != "/..") {
            s.push(minPath);
        }
        else if(!s.empty()) {
            s.pop();
        }
    }

    string ans = s.empty() ? "/" : "";

    buildAns(s, ans);
    return ans;
}

int main() {
    
    string st = "/a/./b/../../c/";

    string ans = simplifyPath(st);
    cout<<"Asnwer is - "<<ans<<endl;

    return 0;
}
*/


// ******** LC-1003 - CHECK IF WORD IS VALID FROM SUBSTITUTIONS (NOT THE OPTIMISED APPROACH BECAUSE THE TIME COMPLEXITY IS O(N2)) ***********
/*
#include <iostream>
using namespace std;

bool isValid(string s) {
    if(s.size() == 0) {
        return true;
    }

    int fnd = s.find("abc");

    if(fnd != string::npos) {
        // found
        string tleft = s.substr(0, fnd);
        string tright = s.substr(fnd + 3, s.size());
        return isValid(tleft + tright);
    }

    return false;
}

int main() {
    
    string s = "abcababcc";

    cout<<"Answer is - "isValid(s)<<endl;

    return 0;
}
*/


// ******** LC-1003 - CHECK IF WORD IS VALID FROM SUBSTITUTIONS (WITH OPTIMISED CODE AND USING STACK) ***********
/*
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    if( s[0] != 'a') {
        return false;
    }

    stack<char> st;

    for(char ch:s) {
        if(ch == 'a') {
            st.push(ch);
        }
        else if(ch == 'b') {
            if(!st.empty() && st.top() == 'a') {
                st.push(ch);
            }
            else {
                return false;                
            }
        }
        else {
            // ch == 'c'
            if(!st.empty() && st.top() == 'b') {
                st.pop();
                if(!st.empty() && st.top() == 'a') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    return st.empty() ? true : false;
}

int main() {
    string s = "abcababccababcc";

    cout<<"Answer is - "<<isValid(s)<<endl;

    return 0;
}
*/


// ********** DECODE THE STRING *********
/*
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <stack>
using namespace std;

string decodeString(string s) {
    stack<string>st;

    for(auto ch : s) {
        if(ch == ']') {
            string stringToRepeat = "";
            while(!st.empty() && !isdigit(st.top()[0])) {
                string top = st.top();
                stringToRepeat += top;
                st.pop();
            }

            string numeric = "";
            while(!st.empty() && isdigit(st.top()[0])) {
                numeric += st.top();
                st.pop();
            }
            reverse(numeric.begin(), numeric.end());

            int n = stoi(numeric);

            // final decoding
            string currentDecode = "";

            while(n--) {
                currentDecode += stringToRepeat;
            }
            st.push(currentDecode);
        }
        else if(ch != '[') {
            string temp(1, ch);
            st.push(temp);
        }
    }
    string ans = "";

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s = "3[abc]3[a2[c]]";

    cout<<"Answer is - "<<decodeString(s)<<endl;

    return 0;
}
*/


// *********** CAR FLEET - 1 ***********
/*
#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Car {
    public:
    int pos, speed;

    Car(int p, int s): pos(p), speed(s) {};
};

static bool myComp(Car&a, Car&b) {
    return a.pos < b.pos;
}

int carFleet(int target, vector<int>& position, vector<int>& speed) {

    vector<Car> cars;

    for(int i=0; i<position.size(); i++) {
        Car car(position[i], speed[i]);
        cars.push_back(car);
    }

    sort(cars.begin(), cars.end(), myComp);

    stack<float> st;

    for(auto car: cars) {
        float time = (target - car.pos) / ((float) car.speed);
        while(!st.empty() && time >= st.top()) {
            st.pop();
        }
        st.push(time);
    }

    return st.size();
}

int main() {

    int target = 12;
    vector<int> pos{10,8,0,5,3};
    vector<int> speed{2,4,1,1,3};

    cout<<"Answer is : "<<carFleet(target, pos, speed);


    return 0;
}
*/


// *********** CAR FLEET - 2 ***********    
/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<double> getCollisionTimes(vector<vector<int>>& cars) {
    vector<double> answer(cars.size(), -1); // collision time of Ith car with the next car
    stack<int> st;

    for(int i=cars.size()-1; i>=0; i--) {
        // check if car ahead of current car is faster?

        while(!st.empty() && cars[st.top()][1] >= cars[i][1]) {
            st.pop();
        }

        while(!st.empty()) {
            double colTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
            if(answer[st.top()] == -1 || colTime <= answer[st.top()]) {
                answer[i] = colTime;
                break;
            }
            st.pop();
        }
        st.push(i);
    }

    return answer;
}

int main() {

    vector<vector<int>> cars{{1,2}, {2,1}, {4,3}, {7,2}};

    vector<double> ans = getCollisionTimes(cars);

    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/