// ********* FIND FACTORIAL WITH RECURSION ********
/*
#include <iostream>
using namespace std;

int factorial(int n) {
    // Base case / base condition
    if(n==1) {
        return 1;
    }
    cout<<"Function is called for n: "<<n<<endl;
    int ans = n *  factorial(n-1);
    return ans;
}

int main() {
    int n;
    cout<<"Enter the value of n "<<endl;
    cin>>n;

    int ans = factorial(n);   

    cout<<"Answer is  - "<<ans<<endl;

    return 0;
}
*/


// ****** PRINT REVERSE COUNT USING RECURSION ********
/*
#include <iostream>
using namespace std;

void printCounting(int n) {
    // base condition
    if(n==0) {
        return;
    }

    // processing
    cout<<n<<" ";

    // recursive relation
    printCounting(n-1);
}

int main() {
    int n;
    cout<<"Enter the value of n "<<endl;
    cin>>n;

    printCounting(n);

    return 0;
}
*/


// ******* NTH TERM OF FIBONACCI SERIES USING RECURSION *********
/*
#include <iostream>
using namespace std;

int fib(int n) {
    // base case
    if(n==1) {
        // first term
        return 0;
    }
    if(n==2) {
        // second term
        return 1;
    }
    // RR -> f(n) = f(n-1) + f(n-2)
    int ans = fib(n-1) + fib(n-2);
    return ans;
}

int main() {
    int n;
    cout<<" Enter the term you want to see - "<<endl;
    cin>>n;

    int ans = fib(n);
    cout<<n<<"th term is: "<<ans<<endl;

    return 0;
}
*/


// ******* FACTORIAL BY RECURSION ********
/*
#include <iostream>
using namespace std;

int factorial(int n) {
    // Base condition
    if(n==1) {
        return 1;
    }
    // Recursive relation
    int ans = n * factorial(n-1);
    return ans;
}

int main() {
    int n;
    cout<<"Enter n - "<<endl;
    cin>>n;

    int ans = factorial(n);
    cout<<"Answer is  - "<<ans<<endl;

    return 0;
}
*/


// ********REVERSE COUNTING USING RESURSION **********
/*
#include <iostream>
using namespace std;

void printCounting(int n) {
    // Base condition
    if(n==0) {
        return;
    }
    printCounting(n-1);
    cout<<n<<" ";
}

int main() {
    int n;
    cout<<"Enter n - "<<endl;
    cin>>n;

    printCounting(n);

    return 0;
}
*/


// ****** FIBONACCI SERIES *******
/*
#include <iostream>
using namespace std;

int fib(int n) {
    // Base case
    if(n==1) {
        return 0;
    }
    if(n==2) {
        return 1;
    }

    // recursion relation
    int ans = fib(n-1) + fib(n-2);
    return ans;
}  

int main() {
    int n;
    cout<<"Enter the term for fibonacci series - "<<endl;
    cin>>n;

    int ans = fib(n);

    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ********* CLIMB STARIS PROBELM ******
/*
#include <iostream>
using namespace std;

int climbStairs(int n) {
    // Base case - stopping condition
    if(n==1 || n==0) {
        return 1;
    }
    int ans = climbStairs(n-1) + climbStairs(n-2);
    return ans;
}

int main() {
    int n;
    cout<<"Enter the value of n - "<<endl;
    cin>>n;

    int ans = climbStairs(n);
    cout<<"Answer is - "<<ans<<endl;


    return 0;
}
*/


// ********* PRINT ELEMENT OF AN ARRAY WITH RECURSION ********
/*
#include <iostream>
using namespace std;

void print(int arr[], int n, int i) {
    // base case
    if(i>=n) {
        return;
    }
    print(arr, n, i+1);
    cout<<arr[i]<<" ";
}

int main() {
    int arr[5] = {10,20,30,40,50};
    int n = 5;
    int i = 0;

    print(arr, n, i);


    return 0;
}
*/


// ******* FIND MAX ELEMENT IN AN ARRAY USING RECURSION *********
/*
#include <iostream>
#include<limits.h>
using namespace std;

void findMax(int arr[], int n, int i, int& maxi) {
    // base case
    if(i>=n) {
         // array argar khtam ho gaya, poora traverse hogya toh vapas aajao
        return ;
    }
    // 1 case solve krna he
    // current element ko check karo for max
    if(arr[i] > maxi) {
        maxi = arr[i];
    }

    // baki recursion sambhal lega
    findMax(arr, n, i+1, maxi);
}

int main() {
    int arr[] = {10,30,21,44,32,17,19,66};
    int n = 8;

    int maxi = INT_MIN;
    int i = 0;
    findMax(arr, n, i, maxi);
    cout<<"Maximum number is - "<<maxi<<endl;

    return 0;
}
*/


// ******** CLIMB STARIRS ********
/*
#include <iostream>
using namespace std;

int climbStairs(int n) {
    // Base case - stopping condition
    if(n==0 || n==1) {
        return 1;
    }
    int ans = climbStairs(n-1) + climbStairs(n-2);
    return ans;
}

int main() {
    int n;
    cout<<"Enter the value of n "<<endl;
    cin>>n;

    int ans = climbStairs(n);
    cout<<"Answer is: "<<ans<<endl;   

    return 0;
}
*/


// ********* PRINT ELEMENTS OF ARRAY USING RECURSION **********
/*
#include <iostream>
using namespace std;

void print(int arr[], int n, int i) {
    // Base case
    if(i >= n) {
        return;
    }
    
    // baaki recursion sambhal lega
    print(arr, n, i+1);
    // 1 case solve kr dia
    cout<<arr[i]<<" ";
}

int main() {
    int arr[5] = {10,20,30,40,50};
    int n = 5;
    int i = 0;
    print(arr, n, i);


    return 0;
}
*/


// ******** FIND MAXIMUM IN AN ARRAY USING RECURSION ********
/*
#include <iostream>
#include <limits.h>
using namespace std;

void findMax(int arr[], int n, int i, int& maxi) {
    if(i>=n) {
        return;
    }

    if(arr[i]>maxi) {
        maxi = arr[i];
    }
    findMax(arr, n, i+1, maxi);
}

int main() {
    int arr[10] = {15,18,19,36,25,87,14,69,16,75};
    int n = 10;
    int i = 0;
    int maxi = INT_MIN;

    findMax(arr, n, i, maxi);
    cout<<"Maximum element is: "<<maxi<<endl;

    return 0;
}
*/


// ********* FIND MINIMUM IN AN ARRAY USING RECURSION **********
/*
#include <iostream>
#include <limits.h>
using namespace std;

void findMin(int arr[], int n, int i, int& min) {
    if(i>=n) {
        return;
    }

    if(arr[i]<min) {
        min = arr[i];
    }

    findMin(arr, n, i+1, min);
}

int main() {
    int arr[] = {10,20,30,40,50};
    int n = 5;
    int i = 0;
    int min = INT_MAX;

    findMin(arr, n, i, min);
    cout<<"Minimum element is - "<<min<<endl;

    return 0;
}
*/


// ******** FIND AN ELEMENT IN STRING USING RECURSION *********
/*
#include <iostream>
#include <vector>
using namespace std;

void checkKey(string& str, int& i, int& n, char& key, vector<int>& ans) {
    // base case
    if(i >= n) {
        // key not found
        return;
    }

    if(str[i] == key) {
        ans.push_back(i);
    }

   checkKey(str, ++i, n, key, ans);
}

int main() {
    string str = "lovebabbar";
    int n = str.length();
    int i = 0;
    char key = 'b';

    vector<int> ans;
    checkKey(str, i, n, key, ans);

    for(auto val: ans) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/


// ********* COUNT THE ELEMENT IN AN STRING **********
/*
#include <iostream>
#include <vector>
using namespace std;

void checkKey(string& str, int& i, int& n, char& key, int& count) {
    // base case
    if(i >= n) {
        // key not found
        return;
    }

    if(str[i] == key) {
        count++;
    }

   checkKey(str, ++i, n, key, count);
}

int main() {
    string str = "lovebabbar";
    int n = str.length();
    int i = 0;
    char key = 'b';
    int count = 0;

    checkKey(str, i, n, key, count);

    cout<<"Count is - "<<count<<endl;

    return 0;
}
*/


// ******** PRINT EVERY DIGIT IN AN NUMEBR USING RECURSION *******
/*
#include <iostream>
#include <vector>
using namespace std;

void countDigits(int& num, vector<int>& ans) {
    if(num <= 0) {
        return;
    }

    int digit = num%10;
    num = num / 10;
    countDigits(num, ans);
    ans.push_back(digit);

}

int main() {
    int num = 692;
    vector<int> ans;

    countDigits(num, ans);

    for(auto val: ans) {
        cout<<val<<" ";
    }

    return 0;
}
*/


// ********** CHECK FOR SORTED ARRAY USING RECURSION *********
/*
#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int>& arr, int& n, int i) {
    // base case
    if(i == n-1) {
        return true;
    }
    // 1 case solve krna he, 
    if(arr[i+1] < arr[i]) {
        return false;
    }

    // baki recursion sambhal lega
    return checkSorted(arr, n, i+1);
}

int main() {
    vector<int> v{10,20,30,50,60};

    int n = v.size();
    int i = 0;
    bool isSorted = checkSorted(v, n, i);
    if(isSorted) {
        cout<<"Array is sorted"<<endl;
    }
    else {
        cout<<"Array is not sorted"<<endl;
    }


    return 0;
}
*/


// ********** BINARY SEARCH USING RESURSION *********
/*
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> v, int s, int e, int key) {
    // base case
    // case 1 -> key not found
    if(s>e) {
        return -1;
    }
    int mid = s+(e-s)/2;

    // case 2 -> key found
    if(v[mid] == key) {
        return mid;
    }

    // arr[mid] < key ----- right me search
    if(v[mid] < key) {
        return binarySearch(v, mid+1, e, key);
    }

    // arr[mid] > key ----- left me search
    else {
    return binarySearch(v, s, mid -1, key);
    }
}

int main() {
    vector<int> v{10,20,40,60,70,90,99};
    int target = 99;
    int s = 0;
    int e = v.size() - 1;
    int ans = binarySearch(v, s, e, target);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ******* SUBSEQUENCE OF A STRING USING RECURSION ********
/*
#include <iostream>
#include <vector>
using namespace std;

void printSubSequences(string str, string output, int i, vector<string>& ans) {
    // base case
    if(i>=str.length()) {
        ans.push_back(output);
        return;
    }

    // exclude ->
    printSubSequences(str, output, i+1, ans);

    // include ->
    // below line is reponsible for concatenation of output string ans i th character of str string
    output = output + str[i];

    printSubSequences(str, output,i+1, ans);
}

int main() {
    string str = "abc";
    string output = "";
    int i = 0;
    vector<string> ans;

    printSubSequences(str, output, i, ans);
    cout<<endl;
    cout<<"Printing all the sub sequences of string"<<endl;
    for(auto val: ans) {
        cout<<val<<endl;
    }

    return 0;
}
*/


// ****** GET MINIMUN LENGTH OF ARRAY WHICH CAN ADD UPTO A GIVEN KEY USING AN GIVEN ARRAY ******
/*
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(vector<int>& arr, int target) {
    // base case
    if(target == 0) {
        return 0;
    }
    if(target < 0) {
        return INT_MAX;
    }

    // let's solve one case
    int mini = INT_MAX;
    for(int i=0; i<arr.size(); i++) {
        int ans = solve(arr, target - arr[i]);
        if(ans != INT_MAX) {
        mini = min(mini, ans+1);
        }
    }
    return mini;
}

int main() {
    vector<int> arr{1,2};
    int target = 5;

    int ans = solve(arr, target);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ******* CUT INTO SEGMENT PROBLEM **********
/*
#include <iostream>
#include <limits.h>
using namespace std;

int solve(int n, int x, int y, int z) {
    // base case
    if(n==0) {
        return 0;
    }
    if(n<0) {
        return INT_MIN;
    }
    int a = solve(n-x, x, y, z) + 1;
    int b = solve(n-y, x, y, z) + 1;
    int c = solve(n-z, x, y, z) + 1;

    int ans = max(a, max(b,c));
    return ans;
}

int main() {
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    // Solve function -> It returns maximum numbers of segments
    int ans = solve(n,x,y,z);
    if(ans < 0) {
        ans = 0;
    }
    cout<<"Asnwer is - "<<ans<<endl;

    return 0;
}
*/


// ********* MAXIMUM SUM OF NON ADJACENT ELEMENTS ********
/*
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void solve(vector<int>& arr, int i,int sum, int& maxi) {
    // base case
    if(i>=arr.size()) {
        // maxi update
        maxi = max(sum, maxi);
        return;
    }

    //include
    solve(arr, i+2, sum+arr[i], maxi);

    //exclude
    solve(arr, i+1, sum, maxi);
}

int main() {    
    vector<int> arr{1,2,3,1,3,5,8,1,9};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;

    solve(arr, i,sum, maxi);
    cout<<"Answer is - "<<maxi<<endl;

    return 0;
}
*/


// ********* FIND LAST OCCURENCE OF A CHARACTER *********
/*
#include <iostream>
#include <string>
using namespace std;

void lastOcc(string& str, char& key, int i, int& charIndex) {
    if(i < 0) {
        return;
    }
    if(str[i] == key) {
        charIndex = i;
    }
    else {
    lastOcc(str, key, i-1, charIndex);
    }
}

int main() {
    string str = "abcddeg";
    char key = 'd';
    int i = str.length()-1;
    int charIndex = -1;

    lastOcc(str, key, i, charIndex);

    cout<<"Last index of key is - "<<charIndex<<endl;


    return 0;
}
*/


// ******** REVERSE A STRING USING RECURSION *******
/*
#include <iostream>
using namespace std;

void reverseStr(string& str, int s, int e) {
    if(s>e) {
        return;
    }
    swap(str[s], str[e]);
    reverseStr(str, s+1, e-1);
}

int main() {
    string str = "abcde";
    int s = 0;
    int e = str.length() - 1;

    reverseStr(str, s, e);

    cout<<"Reverse string is "<<str<<endl;

    return 0;
}
*/


// ******* ADD TWO STRINGS LIKE A INTEGER AND RETURN THE SUM OF THEM *********
/*
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

void addStringsUsingRecursion(string& nums1, int p1, string& nums2, int p2, int carry ,string& ans) {
    // base case
    if(p1<0 && p2<0) {
        if(carry != 0) {
            ans.push_back(carry + '0');
        }
        return;
    }

    // solve one case
    int n1 = (p1 >= 0 ? nums1[p1] : '0') - '0';   
    int n2 = (p2 >= 0 ? nums2[p2] : '0') - '0';
    int total = n1 + n2 + carry;
    int digit = total % 10;
    carry = total / 10;
    ans.push_back(digit + '0');

    // Recursion call
    addStringsUsingRecursion(nums1, p1-1, nums2, p2-1, carry, ans);
}

int main() {
    
    string s1 = "99";
    string s2 = "999";
    string ans = "";

    addStringsUsingRecursion(s1, s1.size()-1, s2, s2.size()-1, 0, ans);
    reverse(ans.begin(), ans.end());

    cout<<"Addition is - "<<ans<<endl;

    return 0;
}
*/


// ********** CHECK PALINDROM USING RECURSION *********
/*
#include <iostream>
using namespace std;

bool checkPalindrome(string& str, int n,int s, int e) {
    if(n >= str.size()) {
        return true;
    }

    if(str[s] != str[e]) {
        return false;
    }

    checkPalindrome(str, n+1, s+1, e-1);
}

int main() {
    string str = "abba";

    bool ans = checkPalindrome(str, 0, 0, str.size()-1);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ******** REMOVE ALL OCCURENCE OF SUBSTRING IN A STRING *******
/*
#include <iostream>
#include <string.h>
using namespace std;

void removeOccRe(string& s, string& part) {

    int found = s.find(part);
    if(found != string::npos) {
        // part in string has been located
        // Remove it from string
        string left_part = s.substr(0, found);
        string right_part = s.substr(found + part.size(), s.size());
        s = left_part + right_part;

        removeOccRe(s, part);
    }
    else {
        return;
    }
}

int main() {
    string s = "abcaeabcbcd";
    string part = "abc";

    removeOccRe(s, part);
    cout<<"Answer is - "<<s<<endl;


    return 0;
}
*/


// ******* PRINT ALL SUBSTRING OF A STRING *******
/*
#include <iostream>
using namespace std;

void printSubStringUtils(string& s, int i, int j) {
    if(j == s.size()) {
        return;
    }

    for(int start=i; start<=j; start++) {
        cout<<s[start]<<" ";
    }cout<<endl;

    printSubStringUtils(s, i, j+1);
}

void printSubString(string s) {
    for(int start=0; start<s.size(); start++) {
        int end = start;
        printSubStringUtils(s, start, end);
    }
}

int main() {
    string s = "12345";

    printSubString(s);

    return 0;
}
*/


// ******* BUY AND SELL STOCKS USING RECURSION ********
/*
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit) {
    // base case
    if(i >= prices.size()) {
        return;
    }

    // One solution
    if(prices[i]<minPrice) {
        minPrice = prices[i];
    }
    int todaysProfit = prices[i] - minPrice;
    if(todaysProfit > maxProfit) {
        maxProfit = todaysProfit;
    }

    // RE
    maxProfitFinder(prices, i+1, minPrice, maxProfit);    
}

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    maxProfitFinder(prices, 0, minPrice, maxProfit);
    return maxProfit;
}

int main() {
    vector<int> prices{7,1,5,3,6,4};

    int ans = maxProfit(prices);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ****** HOUSE ROBBERY PROBLEM ********
/*
#include <iostream>
#include <vector>
using namespace std;

int robHelper(vector<int>& nums, int i) {
    if(i >= nums.size()) {
        return 0;
    }
    // solve one case
    int robAmt1 = nums[i] + robHelper(nums, i + 2);
    int robAmt2 = 0 + robHelper(nums, i+1);

    return max(robAmt1, robAmt2);
}

int rob(vector<int>& nums) {
    return robHelper(nums, 0);
}

int main() {
    vector<int> nums{1,2,3,1};

    int ans = rob(nums);
    cout<<"Answer is - "<<ans<<endl;


    return 0;
}
*/


// ****** CONVERT INTEGER TO ENGLISH WORD ********
/*
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, string> > mp = {
    {1000000000, "Billion"},{1000000, "Million"},{1000, "Thousand"},{100, "Hundred"},{90, "Ninty"},{80, "Eighty"},{70, "Seventy"},{60, "Sixty"},{50, "Fifty"},{40, "Fourty"},{30, "Thirty"},{20, "Twenty"},{19, "Ninteen"},{18, "Eighteen"},{17, "Seventeen"},{16, "Sixteen"},{15, "Fifteen"},{14, "Fourteen"},{13, "Thirteen"},{12, "Twelve"},{11, "Eleven"},{10, "Ten"},{9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}
};

string numberToWord(int num) {
    if( num == 0) {
        return "Zero";
    }

    for(auto it: mp) {
        if(num >=it.first) {
            string a = "";
            if(num >= 100) {
                a = numberToWord(num/it.first);
            }

            string b = it.second;

            string c = "";
            if(num % it.first != 0) {
                c = numberToWord(num % it.first);
            }

            return a + " " + b + " " + c;
        }
    }
    return "";
}

int main() {

    string ans = numberToWord(1234567);

    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ******* WILD CARD MATCHING MATCHING *********
/*
#include <iostream>
using namespace std;

bool isMatchHelper(string s, int si, string p, int pi) {
    // base case
    if (si == s.size() && pi == p.size()) {
        return true;
    }

    // if s is out of bound and pi is not out of bound
    if(si == s.size() && pi < p.size()) {
        while(pi < p.size()) {
            if(p[pi] != '*') {
                return false;
            }
            pi++;
        }
        return true;
    }

    // single character matching 
    if(s[si] == p[pi] || '?' == p[pi]) {
        return isMatchHelper(s, si+1, p, pi+1);
    }

    if(p[pi] == '*') {
        // treat '*' as empty or null
        bool caseA = isMatchHelper(s, si, p, pi+1);

        // let '*' consume 1 character
        bool caseB = isMatchHelper(s, si+1, p, pi);

        return caseA || caseB;
    }

    // character doesn't match
    return false;
}

bool isMatch(string s, string p) {
    int si = 0; // pointer index for s string 
    int pi = 0; // pointer index for p string

    return isMatchHelper(s, si, p, pi);

}

int main() {
    string s = "abc";
    string p = "abc****";

    bool ans = isMatch(s, p);

    cout<<"Answer is - "<<ans<<endl;


    return 0;
}
*/


// ********** PERFECT SQUARES *********
/*
#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

int numSquareHelper(int n) {
    // base 
    if(n == 0) {
        return 1;
    }
    if(n < 0) {
        return 0;
    }

    // One case solution
    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);
    while(i <= end) {
        int perfectSqaure = i * i;
        int numberOfPerfectSqaures = 1 + numSquareHelper(n - perfectSqaure);
        if(numberOfPerfectSqaures < ans) {
            ans = numberOfPerfectSqaures;
        }
        i++;
    }

    return ans;
}

int numSquares(int n) {
    return numSquareHelper(n) - 1;
}

int main() {
    int num = 12;

    int ans = numSquares(12);

    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ********* FIND MINIMUM COST FOR TRAVELLING ***********
/*
#include <iostream>
#include <vector>
using namespace std;

int minCostTicketsHelper(vector<int>& days, vector<int>& costs, int i) {
    // base
    if(i >= days.size()) {
        return 0;
    }

    // Sol for one case
    // 1 day pass taken
    int cost1 = costs[0] + minCostTicketsHelper(days, costs, i+1);
    // 7 day pass taken
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while(j < days.size() && days[j] <= passEndDay) {
        j++;
    }
    int cost7 = costs[1] + minCostTicketsHelper(days, costs, j);
    // 30 day pass taken
    passEndDay = days[i] + 30 - 1;
    j = i;
    while(j < days.size() && days[j] <= passEndDay) {
        j++;
    }
    int cost30 = costs[2] + minCostTicketsHelper(days, costs, j);

    return min(cost1, min(cost7, cost30));
}

int minCostTickets(vector<int>& days, vector<int>& costs) {
    return minCostTicketsHelper(days, costs, 0);
}

int main() {
    vector<int> days{1,4,6,7,8,20};
    vector<int> costs{2,7,15};

    int ans = minCostTickets(days, costs);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ********* NUMBER OF DICE ROLL WITH TARGET SUM **********
/*
#include <iostream>
using namespace std;

int numRollsToTarget(int n, int k, int target) {
    // base case
    if(target < 0) return 0;
    if(n == 0 && target == 0) return 1;
    if(n == 0 && target != 0) return 0;
    if(n != 0 && target == 0) return 0;

    // one case solution
    int ans = 0;
    for(int i=1; i<=k; i++) {
        ans = ans  + numRollsToTarget(n-1, k, target-i);
    }
    return ans;
}

int main() {
    int ans = numRollsToTarget(3,2,6);
    cout<<"Answer is - "<<ans<<endl;


    return 0;
}
*/