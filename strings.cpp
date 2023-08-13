// ****** BASIC STRING *******
/*
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string str;
    cout<<"Input - ";
    getline(cin, str);

    cout<<"Output - "<<str<<endl;

    return 0;
}
*/


// ******* REMOVAL OF DUPLICATE WITH LINEAR COMPLEXITY *******
/*
#include <iostream>
#include <string>
using namespace std;

string removeDuplicate(string s) {
    string ans = "";
    int i = 0;
    while(i < s.length()) {
        if(ans.length() > 0) {
            if(ans[ans.length()-1] == s[i]) {
                ans.pop_back();
            }
            else {
                ans.push_back(s[i]);
            }
        }
        else {
            ans.push_back(s[i]);
        }
        i++;
    }
    return ans;
}

int main() {
    string s = "abbaca";
    string ans = removeDuplicate(s);
    cout<<"Answer is - "<<ans<<endl;
    return 0;
}
*/


// ******* REMOVE ALL OCCURENCE OF SUNSTRING ********
/*
#include <iostream>
#include <string>
using namespace std;

string removeOccurence(string s, string part) {
    int pos = s.find(part);

    while(pos != string::npos) {
        s.erase(pos, part.length());
        pos = s.find(part);
    }
    return s;
}

int main() {
    string s = "daabcbaabcbs", part = "abc";
    string ans = removeOccurence(s, part);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ******* CHECK FOR VALID PALINDROME *******
/*
#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string s, int i, int j) {
    while(i<=j) {
        if(s[i]!=s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool validPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;

    while(i<=j) {
        if(s[i] != s[j]) {
            // ek baar i ko remove, ek baar j ko remove
            return checkPalindrome(s, i+1, j) || checkPalindrome(s, i, j-1);
        }
        else {
            // s[i] == s[j]
            i++;
            j--;
        }
    }
    return true;
}

int main() {
    string s = "abca";

    bool  ans = validPalindrome(s);
    cout<<"Answer is - "<<ans<<endl;


    return 0;
}
*/


// ******** IN THE ARRAY OF STRING WHERE TIME IS GIVEN IN 24 HOURS FORMAT, CALCULATE THE MINIMUM TIME 
//  DIFFRENCE BETWEEN THE GIVEN TIMES *******
/*
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int findMinDiffrence(vector<string>& timePoints){
    vector<int> minutesArr;
    // Step 1: Convert time string into minutes integer value 
    for(int i=0; i<timePoints.size(); i++) {
        string curr = timePoints[i];
        int hours = stoi(curr.substr(0,2));
        int minutes = stoi(curr.substr(3,2));
        int totalMinutes = hours * 60 + minutes;
        minutesArr.push_back(totalMinutes);
    }
    // Step 2: Sort the minutes array 
    sort(minutesArr.begin(), minutesArr.end());
    
    // Step 3: Get the diffrenece and calculate minimum diffrence
    int mini = INT16_MAX;
    int n = minutesArr.size();
    for(int i=0; i<n-1; i++) {
        int diff = minutesArr[i+1] - minutesArr[i];
        mini = min(mini, diff);
    }

    // Need to compare first time and last time like "23:59" & "00:00"
    int lastDiff1 = (minutesArr[0] + 1440) - minutesArr[n-1];
    int lastDiff2 = minutesARR[n-1] - minutesArr[0];
    int lastDiff = min(lastDiff1, lastDiff2);
    mini = min(mini, lastDiff);

    return mini;
}

int main() {
    vector<string> s{"00:00", "23:59"};

    int ans = findMinDiffrence(s);
    cout<<"Answer is - "<<ans<<endl;
 
    return 0;
}
*/


// ******** NUMBER OF PALINDROMIC SUBSTRING OF A STRING *********** 
/*
#include <iostream>
#include <string>
using namespace std;

int expandAroundIndex(string s, int i, int j) {
    int count=0;
    // Jab tak match karega, tab tak count increment kardo, i piche and j aage kardo
    while(i >= 0 && j<s.length() && s[i] == s[j]) {
        count++;
        i--;
        j++;
    }
    return count;
}

int countSunString(string s) {
    int count = 0;
    int n = s.length();

    for(int i=0; i<n; i++) {
        // Odd case
        int oddAns = expandAroundIndex(s, i, i);
        count = count + oddAns;

        // Even case
        int evenAns = expandAroundIndex(s, i, i+1);
        count = count + evenAns;
    }
    return count;
}

int main() {
    string s = "noon";

    int ans = countSunString(s);
    cout<<"Answer is - "<<ans<<endl;


    return 0;
}
*/


// ******* CUSTOM COMPARATER *******
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char first, char second) {
    return first > second;
}

bool compare(int a, int b) {
    return a > b;
}

int main() {
    string s = "babbar";
    sort(s.begin(), s.end(), cmp);

    cout<<s<<endl;

    vector<int> v{5,3,2,1,4};
    sort(v.begin(), v.end(), compare);

    for(auto val: v) {
        cout<<val<<" ";
    } cout<<endl;

    return 0;
}
*/


// ********* HASHMAPS *********
/*
#include <iostream>
#include <map>
using namespace std;

int main() {
    
    // create map
    map<int, char> meraMap;

    meraMap[0] = 'a';
    meraMap[1] = 'b';
    meraMap[25] = 'z';

    cout<<"Your answer is - "<<meraMap[0]<<endl;

    return 0;
}
*/


// ******** VALID ANAGRAM ********
/*
#include <iostream>
#include <string>
using namespace std;

bool isValidAnagram(string s, string t) {
    int freqTable[256] = {0};

    for(int i=0; i<s.size(); i++) {
        freqTable[s[i]]++;
    } 

    for(int i=0; i<t.size();i++) {
        freqTable[t[i]]--; 
    }

    for(int i=0; i<256; i++) {
        if(freqTable[i]!=0) {
            return false;
        }
    }
    return true;
 }

int main() {
    string s = "anagram";
    string t = "nagaram";

    cout<<"Answer is - "<<isValidAnagram(s, t)<<endl;

    return 0;
}
*/


// ******** CHECK FOR ISOMORPIC STRINGS *********
/*
#include <iostream>
#include <string>
using namespace std;

bool isIsomorpic(string s, string t) {
    int hash[256] = {0}; // mapping of each char of language 's' to language 't'
    bool isTCharsMapped[256] = {0}; // stores if t[i] char already mapped with s[i]

    for(int i=0; i<s.size(); i++) {
        if(hash[s[i]] ==0 && isTCharsMapped[t[i]] == 0) {
            hash[s[i]] = t[i];
            isTCharsMapped[t[i]] = true;
        }
    }

    for(int i=0; i<s.size(); i++) {
        if(char(hash[s[i]]) != t[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s = "egg";
    string t = "add";

    bool ans = isIsomorpic(s, t);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ****** REVERSE ONLY LETTERS *******
/*
#include <iostream>
#include <string>
using namespace std;

string reverseOnlyLetters(string s) {
    int i = 0;
    int j = s.size()-1;

    while(i<=j) {
        char one = s[i];
        char two = s[j];
        if(one >= 'A' && one <='Z') {
            one = one + 'a' - 'A';
        }
        if(two >= 'A' && two <='Z') {
            two = two + 'a' - 'A';
        }
        if(one >= 'a' && one <= 'z' && two >= 'a' && two <= 'z') {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        else if(one >= 'a' && one <= 'z') {
            j--;
        }
        else {
            i++;
        }
    }
    return s;
}

int main() {
    string s = "Test1ng-Leet=codeQ!";

    string ans = reverseOnlyLetters(s);

    cout<<"Reverse only letters string is - "<<ans<<endl;

    return 0;
}
*/


// ********* REVERSE ONLY ENGLISH LETTERS *******
/*
#include <iostream>
#include <string>
using namespace std;

string reverseOnlyLetters(string s) {
    int l = 0;
    int h = s.size() - 1;

    while(l<h) {
        if(isalpha(s[l]) && isalpha(s[h])) {
            swap(s[l], s[h]);
            l++, h--;
        }
        else if(!isalpha(s[l])) {
            l++;
        }
        else {}
            h--;
    }
    return s;
}

int main() {
    string s = "Test1ng-Leet=codeQ!";
    string ans = reverseOnlyLetters(s);
    cout<<"Reverse only letters string is - "<<ans<<endl;

    return 0;
}
*/


// ******** FIND THE LONGEST COMMON PRFIX IN ALL THE STRINGS OF GIVEN STRING ARRAY ********
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ans="";
    
    int i=0;

    while(true) {
        char curr_ch = 0;
        for(auto str: strs) {
            if(i>=str.size()) {
                // out of bound
                curr_ch = 0;
                break;
            }
            // just started
            if(curr_ch == 0) {
                curr_ch = str[i];
            }
            else if(str[i] != curr_ch) {
                curr_ch = 0;
                break;
            }
        }
        if(curr_ch == 0) {
            break;
        }
        else {
            ans.push_back(curr_ch);
            i++;
        }
    }

    return ans;
}

int main() {
    vector<string> strs{"flower", "flow", "floght"};

    string ans = longestCommonPrefix(strs);
    cout<<"Answer is ans - "<<ans<<endl;


    return 0;
}
*/


// ******** REVERSE VOWELS OF THE STRING *********
/*
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

string reverseVowels(string s) {
    int l = 0;
    int h = s.size() - 1;

    while(l < h) {
        if(isVowel(s[l]) && isVowel(s[h])) {
            swap(s[l], s[h]);
            l++, h--;
        } 
        else if(!isVowel(s[l])) {
            l++;
        }
        else {
            h--;
        }
    }
    return s;
}

int main() {
    string s = "leetcode";

    string ans = reverseVowels(s);
    cout<<"Answer is - "<<ans<<endl;


    return 0;
}
*/


// ******* CHECK FOR ISOMORPIC STRINGS ********
/*
#include <iostream>
#include <string>
using namespace std;

bool isIsomorpic(string s, string t) {
    int hash[256] = {0};
    bool isTCharsMapped[256] = {0};

    for(int i=0; i<s.size(); i++) {
        if(hash[s[i]] == 0 && isTCharsMapped[t[i]] == 0) {
            hash[s[i]] = t[i];
            isTCharsMapped[t[i]] == true;
        }
    }

    for(int i=0; i<s.size(); i++) {
        if((hash[s[i]]) != t[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s = "egg";
    string t = "add";

    bool ans = isIsomorpic(s, t);

    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ******* REORGANIZE STRING *********
/*
#include <iostream>
#include <string>
using namespace std;

string reorganizeString(string s) {
    int hash[26] = {0};

    for(int i=0; i<s.size(); i++) {
        hash[s[i] - 'a']++;
    } // TC - 0(n)

    // find the most frequent character
    char max_freq_char;
    int max_freq = INT8_MIN;
    for(int i=0; i<26; i++) {
        if(hash[i]>max_freq) {
            max_freq = hash[i];
            max_freq_char = i + 'a';
        }
    } // TC - 0(1)

    int index = 0;
    while(max_freq > 0 && index < s.size()) {
        s[index] = max_freq_char;
        max_freq--;
        index += 2;
    } // TC - 0(n)

    if(max_freq != 0) {
        return "";
    }
    hash[max_freq_char - 'a'] = 0;

    // lets place the rest of the character
    for(int i=0; i<26; i++) {
        while(hash[i] > 0) {
            index = index >= s.size() ? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    } // TC - 0(n)
    return s;
}

int main() {
    string s = "aab";

    string ans = reorganizeString(s);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ********* LONGEST PALINDROMIC SUBSTRING ******
/*
#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string& s) {
    int i = 0;
    int j = s.size() - 1;
    while(i<=j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string longestPalindromeSunstring(string s) {
    string ans = "";

    for(int i=0; i<s.size(); i++) {
        string str = "";
        for(int j=i; j<s.size(); j++) {
            str += s[j];
            if(checkPalindrome(str) && str.size() > ans.size()) {
                ans = str;
            }
        }
    }

    return ans;
}

int main() {
    string s = "babad";

    string ans = longestPalindromeSunstring(s);
    cout<<"Answer is "<<ans<<endl;

    cout<<s<<endl;

    return 0;
}
*/


// ******* IN TWO STRING, RETURN THE FIRST OCCURENCE OF SUBSTRING IN MAIN STRING ******
/*
#include <iostream>
#include <string>
using namespace std;

bool checkSubstring(string haystack, string needle, int start) {
    
    int h = start;
    int n = 0;

    while(n<needle.size()) {
        if(haystack[h] != needle[n]) {
            return false;
        }
        h++;
        n++;
    }
    return true;
}

int strStr(string haystack, string needle) {
    int i = 0;
    int j = needle.size();

    while(j<=haystack.size()) {
        if(checkSubstring(haystack, needle, i)) {
            return i;
        }
        i++;
        j++;
    }
    return -1;
}

int main() {
    string s = "a";
    string t = "a";

    int ans = strStr(s, t);
    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/


// ****** IN TWO STRING, RETURN THE FIRST OCCURENCE OF SUBSTRING IN MAIN STRING ******
/*
#include <iostream>
using namespace std;

int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    for(int i=0; i<=n-m; i++) {
        for(int j=0; j<m; j++) {
            if(needle[j] != haystack[i+j]) {
                break;
            }
            if(j == m-1) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    string s = "a";
    string t = "a";

    int ans = strStr(s, t);
    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ******* GROUP ANAGRAMS *******
/*
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool checkAnagram(string s, string t) {
    string first = s;
    string second = t;
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    if(first==second) {
        return true;
    }
    return false;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > finalAns;
        int n = strs.size();
        int i = 0;
        if(strs.size() == 1 && strs[0] == "") {
            finalAns.push_back(strs);
            return finalAns;
        }
        while(i<n) {
            vector<string> subStr;
            int first = 0;
            for(int j=i+1; j<n; j++) {
                if(checkAnagram(strs[i], strs[j]) && strs[j] != "0") {
                    if(first==0) {
                        subStr.push_back(strs[i]);
                        subStr.push_back(strs[j]);
                        strs[j] = "0";
                        first++;
                    }
                    else {
                        subStr.push_back(strs[j]);
                        strs[j] = "0";
                    }
                }
            }
            if(subStr.size()==0 && strs[i] != "0") {
                subStr.push_back(strs[i]);
            }
            if(subStr.size() >= 1) {
                finalAns.push_back(subStr);
            }
            i++;
        }
        return finalAns;
    }

int main() {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat","bat"};

    vector<vector<string>> finalAns = groupAnagrams(strs);

    for(int i=0; i<finalAns.size(); i++) {
        for(int j=0; j<finalAns[i].size(); j++) {
            cout<<finalAns[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}
*/


// ******* GROUP ANAGRAMS WITH MAP AND SORT *******
/*
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > ans;

    map<string, vector<string> > mp;

    for(auto str: strs) {
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }

    for(auto it = mp.begin(); it!=mp.end(); it++) {
        ans.push_back(it->second);
    }
    return ans;
}

int main() {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat","bat"};

    vector<vector<string>> finalAns = groupAnagrams(strs);

    for(int i=0; i<finalAns.size(); i++) {
        for(int j=0; j<finalAns[i].size(); j++) {
            cout<<finalAns[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}
*/


// ******* GROUP ANAGRAMS WITH HASH MAP AND VECTOR *******
/*
#include <iostream>
#include <vector>
#include <map>
using namespace std;

std::array<int,256> hashMap(string s) {
    std::array<int,256> hash = {0};
    for(int i=0; i<s.size(); i++) {
        hash[s[i]]++;
    }
    return hash;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<std::array<int, 256>, vector<string> >mp;

    for(auto str: strs) {
        mp[hashMap(str)].push_back(str);
    }

    vector<vector<string>>ans;
    for(auto it=mp.begin(); it!=mp.end(); it++) {
        ans.push_back(it->second);
    }
    return ans;
}

int main() {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat","bat"};

    vector<vector<string>> finalAns = groupAnagrams(strs);

    for(int i=0; i<finalAns.size(); i++) {
        for(int j=0; j<finalAns[i].size(); j++) {
            cout<<finalAns[i][j]<<" ";
        } cout<<endl;
    }


    return 0;
}
*/


// ******* MY ATOI - STRING TO INTEGER *******
/*
#include <iostream>
#include <string>
using namespace std;

int myAtoi(string s) {
    int num = 0;
    int i = 0;
    int sign = 1; // 1 is for positive

    while(s[i] == ' ') {
        i++;
    }

    if(i < s.size() && (s[i] == '-' || s[i] == '+')) {
        sign = s[i] == '+' ? 1 : -1;
        i++;
    }

    while(i<s.size() && isdigit(s[i])) {
        if(num > INT32_MAX / 10 || (num == INT32_MAX / 10 && s[i] > '7')) {
            return sign == -1 ? INT32_MIN : INT32_MAX;
        }
        num = num * 10 + (s[i] - '0');
        ++i;
    }

    return num * sign;
}

int main() {
    string s = "4193 with words";

    int ans = myAtoi(s);
    cout<<"Answer is = "<<ans<<endl;

    return 0;
}
*/


// ********* COMPRESS STRING *********
/*
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int compress(vector<char>& chars) {
    int index = 0;
    int count = 1;

    char prev = chars[0];

    for(int i=1; i<chars.size(); i++) {
        if(chars[i] == prev) {
            count++;
        }
        else {
            chars[index++] == prev;
            if(count > 1) {
                int start  = index;
                while(count) {
                    chars[index++] = count % 10 + '0';
                    count/=10;
                }
                reverse(chars.begin() + start, chars.begin() + index);
            }
            prev = chars[i];
            count = 1;
        }
    }
    chars[index++] = prev;
    if(count > 1) {
        int start  = index;
        while(count) {
            chars[index++] = count % 10 + '0';
            count/=10;
        }
        reverse(chars.begin() + start, chars.begin() + index);
    } 
    return index;
}

int main() {
    vector<char> ch = {'a','a','a','a','a','a','a','a','a','a','a','a'};

    int ans = compress(ch);
    
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ******* INTEGER TO ROMAN NUMBER *******
/*
#include <iostream>
#include <vector>
using namespace std;

string intToRoman(int num) {
    vector<string> romanSymbols = {"M", "CM", "D", "CD","C","XC","L","XL","X","IX","V","IV","I"};
    vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

    string ans = "";

    while(num != 0) {    
        cout<<num;
        for(int i=0; i<values.size(); i++) {
            if(num>=values[i]) {
                ans += romanSymbols[i];
                num = num - values[i];
                break;
            }
        }
    }

    return ans;
}

int main() {
    int num = 1994;

    string ans = intToRoman(num);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ******* ZIGZAG STRING IN GIVEN NO. OF ROWS *******
/*
#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1 ) {
        return s;
    }
    vector<string>zigzag(numRows);

    int i = 0;
    int row = 0;
    bool direction = 1; // 1 means top -> bottom

    while(true) {
        if(direction == 1) {
            while(row<numRows && i<s.size()) {
                zigzag[row++].push_back(s[i++]);
            }
            row = numRows - 2;
        }
        else {
            while(row>=0 && i<s.size()) {
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }
        if(i >= s.size()) {
            break;
        }
        direction = !direction;
    }
    string ans;
    for(int i=0; i<zigzag.size(); i++) {
        ans += zigzag[i];
    }
    return ans;
}

int main() {
    string s = "ABCDEFG";
    int numRows = 3;
    string ans = convert(s,numRows); 
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/


// ********* ARRANGE THE ARRAY OF NUMBER TO MAKE AN LARGEST NUMBER **********
/*
#include <iostream>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

static bool mycomp(string a, string b) {
    string t1 = a+b;
    string t2 = b+a;
    return  t1 > t2;
}

string largestNumber(vector<int> nums) {
    vector<string> snums;
    for(auto n:nums) {
        snums.push_back(to_string(n));
    }

    sort(snums.begin(),snums.end(), mycomp);

    string ans = "";
    for(auto str: snums) {
        ans += str;
    }
    cout<<ans<<endl;
    if(ans[0] == '0') {
        return "0";
    }
    return ans;
}

int main() {
    vector<int> nums = {0, 0};

    string ans = largestNumber(nums);
    cout<<"Answer is - "<<ans<<endl;

    return 0;
}
*/