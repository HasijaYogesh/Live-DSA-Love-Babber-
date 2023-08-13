// ******** CHECK IF NUMBER IS ODD OR EVEN ********
/*
#include <iostream>
using namespace std;

int main() {
    int n = 50;
    if(n & 1) {
        cout<<"N is odd"<<endl;
    }
    else {
        cout<<"N is even"<<endl;
    }

    return 0;
}
*/


// ****** FIND ITH BIT ********
/*
#include <iostream>
using namespace std;

int getIthBit(int n, int i) {
    int mask = 1 << i;
    int ans = n & mask;
    if(ans == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int main() {
    
    int ans = getIthBit(10,3);
    cout<<"Answer is "<<ans<<endl;


    return 0;
}   
*/


// ********** SET ITH BIT **********
/*
#include <iostream>
using namespace std;

void setIthBit(int n, int i) {
    int mask = 1<<i;
    int ans = n | mask;
    cout<<"After setting: "<<ans<<endl;
}

int main() {
    
    setIthBit(10,2);

    return 0;
}
*/


// ******** CLEARINH ITH BIT **********
/*
#include <iostream>
using namespace std;

void clearIthbit(int n, int i) {
    int mask = ~(1<<i);
    int ans = n & mask;
    cout<<"After clearing: "<<ans<<endl;
}

int main() {
    
    clearIthbit(10, 1);


    return 0;
}
*/


// ********* CHANGE ITH BIT WITH RESPECT TO TARGET ********
/*
#include <iostream>
using namespace std;

void clearIthbit(int& n, int i) {
    int mask = ~(1<<i);
    n = n & mask;
    cout<<"After clearing: "<<n<<endl;
}

void updateIthBit(int& n, int i, int target) {
    clearIthbit(n,i);
    int mask = target<<i;
    n = n | mask;
    cout<<"Answer is "<<n<<endl;
}

int main() {

    int n = 10;
    updateIthBit(n,0,1);


    return 0;
}
*/


// ******** LEET CODE 136 - SINGLE NUMBER ********
/*
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;

    for(int i=0; i<nums.size(); i++) {
        ans = ans ^ nums[i];
    }

    return ans;
}

int main() {
    vector<int> nums{4,2,2,1,1};

    int ans = singleNumber(nums);
    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ******** CLEARING TILL THE GIVEN LAST DIGIT *******
/*
#include <iostream>
using namespace std;

void clearLastIBits(int n, int i) {
    int mask = (-1 << i);
    n = n & mask;
    cout<<"After clearing last i bits: "<<n<<endl;
}

int main() {
    int n = 7;
    clearLastIBits(n,2);

    return 0;
}
*/


// ******** CHECK IF THE NUMBER COMES IN POWER OF 2 *********
/*
#include <iostream>
using namespace std;

bool checkPowerOf2(int n) {
    if((n & (n-1)) == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    
    bool ans = checkPowerOf2(32);
    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/


// ********* COUNT NUMBER OF SET BITS *******
/*
#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while(n != 0) {
        int lastBit = n & 1;
        if(lastBit) {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int countSetBitFast(int n) {
    int count = 0;

    while(n != 0) {
        // remove last set bit
        n = (n & n-1);
        count++;
    }
    return count;
}

int main() {
    
    // int ans = countSetBits(15);
    // cout<<"Answer is "<<ans<<endl;

    int ans = countSetBitFast(4);
    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ********* CLEAR BIT IN GIVEN RANGE ********
/*
#include <iostream>
using namespace std;

void clearBitsInRange(int n, int i, int j) {
    int a = (-1 << (i+1));
    int b = (1 << j) - 1;
    int mask = a | b;
    n = n & mask;
    cout<<"Answer is "<<n<<endl;
}

int main() {
    
    clearBitsInRange(15,2,0);


    return 0;
}
*/


// ************ FIND THE SUBSEQUENCES OF GIVEN STRING **********
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getSubsequences(string str) {
    vector<string> ans;
    int n = str.length();

    for(int num=0; num<(1<<n); num++) {
        string temp = "";

        // we will create subsequnce string int this temp string
        for(int i=0; i<n; i++) {
            char ch = str[i];
            if(num & (1 << i)) {
                // non zero value k liye, include current character
                temp.push_back(ch);
            }
        }
        if(temp.length() >= 0) {
            // store in ans
            ans.push_back(temp);
        }
    }
    sort(ans.begin(), ans.end());
    cout<<"Count of subsequences: "<<ans.size()<<endl;
    cout<<"Printing the subsequences: "<<endl;
    for(auto a: ans) {
        cout<<a<<endl;
    }
}

int main() {
    
    string a = "abc";
    getSubsequences(a);

    return 0;
}
*/