// ****** LEET CODE 239 - SLIDING WINDOW MAXIMUM *********
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;

    // process first k size window
    for(int i=0; i<k; i++) {
        while(!dq.empty() && nums[i]>=nums[dq.back()]) {
            dq.pop_back();
        }
        // insert element
        dq.push_back(i);
    }

    // ans store karlo for 1st window
    ans.push_back(nums[dq.front()]);

    // reamining windows
    for(int i=k; i<nums.size(); i++) {
        // removal
        if(!dq.empty() && i-k >= dq.front()) {
            dq.pop_front();
        }

        // addition
        while(!dq.empty() && nums[i]>=nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);

        // ans store
        ans.push_back(nums[dq.front()]);
    }

    return ans;
}

int main() {

    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for(auto i: ans) {
        cout<<i<<" ";
    } cout<<endl;


    return 0;
}
*/


// ********* LEET CODE 1 - TWO SUM **********
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int,int>> data;
    vector<int> ans;
    for(int i=0; i<nums.size(); i++) {
        int val = nums[i];
        int index = i;
        data.push_back({val, index});
    }

    sort(data.begin(), data.end(), cmp);

    int start = 0;
    int end = data.size()-1;

    while(start < end) {
        if(data[start].first + data[end].first == target) {
            ans.push_back(data[start].second);
            ans.push_back(data[end].second);
            break;
        }
        else if(data[start].first + data[end].first > target) {
            end--;
        }
        else {
            start++;
        }
    }

    return ans;
}

int main() {
    vector<int> nums {2,7,11,15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);
    for(auto i: ans) {
        cout<<i<<" ";
    } cout<<endl;

    return 0;
}
*/


// ********** LEET CODE 209 - MINIMUM SIZE SUBARRAY SUM ***********
/*
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int i = 0;
    int j = 0;
    int sum = 0;
    int len = INT_MAX;

    while(j<nums.size()) {
        // include current number
        sum = sum+nums[j];

        // mere pass ek window ka sum ready h
        while(sum >= target) {
            // minimise -> sum me se decrease karo, len bhi update krlena, i/start ko aage badhana padega

            len = min(len, j-i+1);
            sum = sum - nums[i];
            i++;
        }
        j++;
    }

    if(len == INT_MAX) {
        return 0;
    }
    else {
        return len;
    }
}

int main() {
    
    int target = 7;
    vector<int> nums{2,3,1,2,4,3};

    int ans = minSubArrayLen(target, nums);
    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/


// ********** SMALLEST WINDOW IN A STRING CONTAINING ALL THE CHARACTERS OF ANOTHER STRING *********
/*
#include <iostream>
#include <limits.h>
#include <unordered_map>
using namespace std;

string smallestWindow(string s, string p) {
    int len1 = s.length();
    int len2 = p.length();
    int start = 0;
    int ansIndex = -1;
    int ansLen = INT_MAX;

    if(len1 < len2) {
        return "-1";
    }

    unordered_map<char,int> strMap;
    unordered_map<char,int> patMap;
    
    // to keep track of all characters of P string
    for(int i=0; i<p.length(); i++) {
        char ch = p[i];
        patMap[ch]++;
    }

    int count = 0;
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        strMap[ch]++;

        // valid character
        if(strMap[ch] <= patMap[ch]) {
            count++;
        }
        if(count == len2) {
            // window is ready
            // minimise the window -> freq decrement, ans update, i/start ko aage badhana he
            while(strMap[s[start]] > patMap[s[start]] || patMap[s[start]] == 0) {
                if(strMap[s[start]] > patMap[s[start]]) {
                    strMap[s[start]]--;
                }
                start++;
            }   

            // ans update
            int lengthOfWindow = i-start+1;
            if(lengthOfWindow < ansLen) {
                ansLen = lengthOfWindow;
                ansIndex = start;
            }
        }
    }

    if(ansIndex == -1) {
        return "-1";
    }
    else {
        return s.substr(ansIndex, ansLen);
    }
}

int main() {
    string s = "timetopractice";
    string p = "toc";

    string ans = smallestWindow(s,p);
    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/