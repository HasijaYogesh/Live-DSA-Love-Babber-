/*
#include <iostream>
using namespace std;

int main() {
    char name[100];
    cout<<"Enter your name!"<<endl;
    cin>>name;

    // cout<<"Your name is "<<name<<endl;
    for(int i=0; i<7; i++) {
        cout<<"index "<<i<<" value "<<name[i]<<endl;
    }

    int value = (int) name[6];
    cout<<"Null char is "<<value<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char name[100];
    cout<<"Name - ";

    cin.getline(name, 50);

    cout<<name;

    return 0;
}
*/


/*
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int getLength(char name[]) {
    int length  = 0;
    int i = 0;
    while(name[i]!='\0') {
        length++;
        i++;
    }
    return length;
}

void reverseCharArray(char name[]) {
    int i=0;
    int n = getLength(name);
    int j=n-1;

    while(i<=j) {
        swap(name[i],name[j]);
        i++;
        j--;
    }
}

int main() {
    char name[100];
    cin>>name;
    cout<<"Name is "<<name<<endl;
    cout<<"length is "<<getLength(name)<<endl;
    reverseCharArray(name);
    cout<<"Reverse is "<<name<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

void replaceSpaces(char sentence[]) {
    int i=0;
    int n = strlen(sentence);
    for(int i=0;i<n;i++) {
        if(sentence[i]==' ') {
            sentence[i] = '@';
        }
    }
}

int main() {
    char sentence[100];
    cin.getline(sentence, 100);
    replaceSpaces(sentence);
    cout<<"After replacing spaces "<<sentence<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

bool checkPalindrome(char word[]) {
    int i=0;
    int n = strlen(word);
    int j=n-1;
    while(i<=j) {
        if(word[i]!=word[j]) {
            return false;
        }
        else {
            i++;
            j--;
        }
    }
    return true;
}

int main() {
    
    char word[100] = "yogesh";
    cout<<"Palindrome check: "<<checkPalindrome(word);

    return 0;
}
*/


/*
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

void convertIntoUpperCase(char arr[]) {
    int n = strlen(arr);

    for(int i=0; i<n; i++) {
        arr[i] = arr[i] - 'a' + 'A';
    }
}

int main() {
    
    char arr[100] = "babbar";
    convertIntoUpperCase(arr);
    cout<<arr<<endl;

    return 0;
}
*/


/*
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string removeDuplicates(string s) {
    string ans="";
    int i=0;

    while(i<s.length()) {
        if(ans.length()>0) {
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

    cout<<removeDuplicates(s);

    return 0;
}
*/


/*
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string removeOccurences(string &s, string part) {
    int pos = s.find(part);
    while(pos != string::npos) {
        s.erase(pos, part.length());
        pos = s.find(part);
    }
}

int main() {
    string s = "axxxyyyb";
    string p = "xy";
    removeOccurences(s, p);
    cout<<s;

    return 0;
}
*/


/*
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
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
    int i=0;
    int j=s.length()-1;

    while(i<=j) {
        if(s[i]!=s[j]) {
            return checkPalindrome(s, i+1, j) || checkPalindrome(s, i, j-1);
        }
        else {
            i++;
            j--;
        }
    }
    return true;
}

int main() {
    string s = "abbaa";
    cout<<validPalindrome(s);


    return 0;
}
*/


/*
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
using namespace std;

int findMinDiffrence(vector<string>& timePoints) {
    //step 1 - convert time string into minutes
    vector<int> minutes;

    for(int i=0; i<timePoints.size(); i++) {
        string curr = timePoints[i];

        int hours = stoi(curr.substr(0,2));
        int minute = stoi(curr.substr(3,2));
        int totalMinutes = hours*60+minute;
        minutes.push_back(totalMinutes);
    }
    // step 2 - sorting
    sort(minutes.begin(),minutes.end());

    //step 3 - minimum diffrence between times
    int mini = INT8_MAX;
    int n = minutes.size()-1;
    for(int i=0;i<n;i++) {
        int diff = minutes[i+1] - minutes[i];
        mini = min(mini, diff);
    }

    //something missing here - This is very important game of this question
    int lastDiff = (minutes[0] +1440) - minutes[n-1];
    int lastDiff2 = minutes[n-1] - minutes[0];
    mini = min(mini, lastDiff);
    mini = min(mini, lastDiff2);

    return mini;
}

int main() {
    vector<string> v{"00:00","23:59"};
    cout<<findMinDiffrence(v)<<endl;

    return 0;
}
*/


/*count substring palindrome*/
/*
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
using namespace std;

int expandAroundIndex(string s, int left, int right) {
    int count = 0;
    // jab tak match karega, tak tak count increment lardo, i piche aur j aaje kardo
    while(left>=0 && right<s.length() && s[left]==s[right]) {
        count++;
        left--;
        right++;
    }
    return count;
}

int countSubstrings(string s) {
    int count=0;
    int n = s.length();
    for(int center=0; center<n; center++) {
        //odd
        int oddAns = expandAroundIndex(s, center, center);
        count = count + oddAns;

        //even
        int evenAns = expandAroundIndex(s, center, center+1);
        count = count + evenAns;
    }
    return count;
}

int main() {
    


    return 0;
}
*/


// ******** BASIC INPUT OF CHAR ARRAY *******
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
    char ch[100];
    cout<<"Enter your name - "<<endl;
    cin.getline(ch, 100);

    cout<<"Your name - "<<ch<<endl;

    return 0;
}
*/


// ********* LENGTH OF ARRAY ********
/*
#include <iostream>
#include <cstring>
using namespace std;

int getLength(char name[]) {
    int length = 0;
    int i = 0;
    while(name[i] != '\0') {
        length++;
        i++;
    }
    return length;
}

int main() {
    char name[100] = "Yogesh";
    
    // cout<<"Enter your name - "<<endl;
    // cin.getline(name, 100);

    cout<<"Length is - "<<getLength(name)<<endl;
    cout<<"Length is - "<<strlen(name)<<endl;


    return 0;
}
*/


// ****** REVERSE A CHAR ARRAY *******
/*
#include <iostream>
#include <cstring>
using namespace std;

void reverse(char name[]) {
    int i = 0;
    int j = strlen(name)-1;
    while(i <= j) {
        swap(name[i], name[j]);
        i++;
        j--;
    }
}

int main() {
    char name[100] = "Yogesh";
    cout<<name<<endl;
    reverse(name);

    cout<<"Reverse name is - "<<name<<endl;

    return 0;
}
*/


// ******* CHECK PALINDROME ********
/*
#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char name[]) {
    int i=0;
    int j = strlen(name) - 1;
    while(i<=j) {
        if(name[i] != name[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    char name[100] = "nitin";
    if(checkPalindrome(name)) {
        cout<<"Palindrome"<<endl;
    }
    else {
        cout<<"Not a Palindrome"<<endl;
    }
    return 0;
}
*/