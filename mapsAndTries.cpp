// *********** BASICS OF HASH MAPS ***********
/*
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    
    // creation
    unordered_map<string, int> m;

    // insertion
    pair<string, int> p = make_pair("Scorpio", 9);
    m.insert(p);

    pair<string, int> p2("alto", 2);
    m.insert(p2);

    m["fortuner"] = 10;

    // accessing
    cout<<m.at("alto")<<endl;
    cout<<m.at("Scorpio")<<endl;

    cout<<m["fortuner"]<<endl;


    // search
    cout<<m.count("Scorpio")<<endl;

    if(m.find("fortuner") != m.end()) {
        cout<<"Fortuner found"<<endl;
    }
    else {
        cout<<"Fortuner not found"<<endl;
    }


    cout<<"Size - "<<m.size()<<endl;

    cout<<m["hummer"]<<endl;
    cout<<"Size - "<<m.size()<<endl;

    cout<<"Printing all entries in map: "<<endl;

    for(auto i: m) {
        cout<<i.first<<" -> "<<i.second<<endl;
    }

    return 0;
}
*/


// ********** COUNT NUMBER OF CHARACTER IN A STRING *********
/*
#include <iostream>
#include <unordered_map>
using namespace std;

// CHeck for circular linked list
// bool checkCircular(Node* head) {
//     unordered_map<Node*, bool> vis;
//     Node* temp = head;

//     while(temp != NULL) {
//         if(vis.find(temp) != vis.end()) {
//             vis[temp] = true;
//         }
//         else {
//             return true;
//         }
//         temp = temp->next;
//     }

//     return false;
// }

int main() {
    string str = "thiruvananthapuram";

    unordered_map<char, int> freq;

    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        freq[ch]++;
    }

    for(auto i: freq) {
        cout<<i.first<<" -> "<<i.second<<endl;
    }


    return 0;
}
*/


// ********* TRIES INSERTION AND SEARCHING *********
/*
#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d) {
        this->data = d;
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word) {
    // base case
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode* child;

    // present
    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    // not present
    else {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursion sambhal lega
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
    if(word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    // present
    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        return false;
    }
    // recursion call
    return searchWord(child, word.substr(1));
}

int main() {

    TrieNode* root = new TrieNode('-');

    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babbar");
    insertWord(root, "babu");

    if(searchWord(root, "coding")) {
        cout<<"Present"<<endl;
    }
    else {
        cout<<"Absent"<<endl;
    }

    return 0;
}
*/


// ********** CHECK FOR LONGEST PREFIX IN ARRAY OF STRINGS **********
/*
#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ans = "";

    // loop on first string
    for(int i=0; i<strs[0].length(); i++) {
        char ch = strs[0][i];
        bool match = true;

        // compare this character with all
        // the remaining strings at the same index
        for(int j=1; j<strs.size(); j++) {
            // compare
            if(strs[j].size() < i || ch != strs[j][i]) {
                match = false;
                break;
            }
        }
        if(match) {
            ans.push_back(ch);
        }
        else {
            break;
        }
    }

    return ans;
}

int main() {
    
    vector<string> v{"flower", "flow", "flight"};

    string ans = longestCommonPrefix(v);

    cout<<"Answer is "<<ans<<endl;
    
    return 0;
}
*/


// ******** LONGEST PREFIX IN STRING ARRAY USINF TRIES *********
/*
#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char d) {
        this->data = d;
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word) {
    // base case
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode* child;

    // present
    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    // not present
    else {
        child = new TrieNode(ch);
        root->childCount++;
        root->children[index] = child;
    }

    // recursion sambhal lega
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
    if(word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    // present
    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        return false;
    }
    // recursion call
    return searchWord(child, word.substr(1));
}

void findLCP(string first, string& ans, TrieNode* root) {

    if(root->isTerminal) {
        return;
    }

    for(int i=0; i<first.length(); i++) {
        char ch = first[i];

        if(root->childCount == 1) {
            ans.push_back(ch);
            int index = ch - 'a';
            root = root->children[index];
        }
        else {
            break;
        }
        if(root->isTerminal) {
            break;
        }
    }
}

string longestCommonPrefix(vector<string>& strs) {
    TrieNode* root = new TrieNode('-');

    // insert strings
    for(int i=0; i<strs.size(); i++) {
        insertWord(root, strs[i]);
    }

    string ans = "";
    string first = strs[0];
    findLCP(first, ans, root);

    return ans;

}

int main() {

    vector<string> v{"flower", "flow", "flight"};

    string ans = longestCommonPrefix(v);

    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ********** GET SUGGESTIONS FOR GIVEN STRINGS ********
/*
#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d) {
        this->data = d;
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word) {
    // base case
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode* child;

    // present
    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    // not present
    else {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursion sambhal lega
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
    if(word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    // present
    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        return false;
    }
    // recursion call
    return searchWord(child, word.substr(1));
}

void storeSuggestions(TrieNode* curr, vector<string>& temp, string& prefix) {
    if(curr->isTerminal) {
        temp.push_back(prefix);
    }

    // a to z tak choices dedo
    for(char ch='a'; ch <= 'z'; ch++) {
        int index = ch-'a';

        TrieNode* next = curr->children[index];

        if(next != NULL) {
            // if child exists
            prefix.push_back(ch);
            storeSuggestions(next, temp, prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> getSuggestions(TrieNode* root, string input) {

    TrieNode* prev = root;
    vector<vector<string> > output;
    string prefix = "";

    for(int i=0; i<input.length(); i++) {
        char lastch = input[i];

        int index = lastch - 'a';

        TrieNode* curr = prev->children[index];

        if(curr == NULL) {
            break;
        }
        else {
            // iske ander me sare suggestion store krke launga
            vector<string> temp;
            prefix.push_back(lastch);
            storeSuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
}

int main() {

    vector<string> v;
    v.push_back("love");
    v.push_back("lover");
    v.push_back("loving");
    v.push_back("last");
    v.push_back("lost");
    v.push_back("lane");
    v.push_back("lord");

    string input = "lovi";

    TrieNode* root = new TrieNode('-');

    for(int i=0; i<v.size(); i++) {
        insertWord(root, v[i]);
    }

    vector<vector<string>> ans = getSuggestions(root, input);

    cout<<"Printing the answer: "<<endl;

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<", ";
        }
        cout<<endl;
    }

    return 0;
}
*/


// ******* ARRAY SUBSET OF ANOTHER ARRAY ******
/*
#include <iostream>
#include <unordered_map>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> map;
    string ans = "Yes";

    // map hasing using a1
    for(int i=0; i<n; i++) {
        map[a1[i]]++;
    }

    // check wheather all elements of a2 present in a1
    for(int i=0; i<m; i++) {
        if(map.find(a2[i]) == map.end()) {
            ans = "No";
            break;
        }
        else {
            // check if present ans count greater than 1
            if(map[a2[i]] > 0) {
                map[a2[i]]--;
            }
            else {
                ans = "No";
                break;
            }
        }
    }

    return ans;
}

int main() {
    
    int a1[] = {1,2,3,4,5,1,1,1};
    int a2[] = {1,2,3,1};
    int n = 8;
    int m = 4;

    string ans = isSubset(a1, a2, n, m);

    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ******* UNION OF TWO LINKED LIST ********
/*
#include <iostream>
#include <map>
using namespace std;

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    map<int, Node*> map;
    Node* curr = head1;

    // L1 hashed
    while(curr) {
        map[curr->data] = curr;
        curr = curr->next;
    }

    curr = head2;

    // L2 hashed
    while(curr) {
        map[curr->data] = curr;
        curr = curr->next;
    }

    Node* UL = NULL;
    curr = 0;

    // iterate map & make final union list
    for(auto it = map.begin(); it!=map.end(); it++) {
        if(!UL) {
            UL = it->second;
            curr = UL;
        }
        else {
            curr->next = it->second;
            curr = curr->next;
        }
    }

    curr->next = NULL;

    return UL;
}

int main() {
    


    return 0;
}
*/


// ******* GET THE INTERSECTION OF THE LINKED LIST, ORDER SHOULD BE ACCORDING TO FIRST LINKED LIST ********
/*
#include <iostream>
#include <unordered_map>
using namespace std;

Node* findIntersection(Node* head1, Node* head2) {
    unordered_map<int, int> map;

    Node* curr = head2;
    // hash list 2 items
    while(curr) {
        map[curr->data]++;
        curr = curr->next;
    }

    Node* IL = NULL;
    Node* it = 0;
    curr = head1;

    while(curr) {
        if(map.find(curr->data) != map.end()) {
            // node value present in L2
            if(!IL) {
                IL = curr;
                it = IL;
            }
            else {
                if(map[curr->data] > 0) {
                    it->next = curr;
                    it = it->next;
                    map[curr->data]--;
                }
            }
        }
        curr = curr->next;
    }
    it->next = NULL;
    return IL;
} 

int main() {
    


    return 0;
}
*/


// ****** FIND TWO PAIRS IN AN ARRAY, THAT SHARES SAME SUM I.E A+B=C+D *********
/*
#include <iostream>
#include <unordered_map>
using namespace std;

int findPairs(long long a[], long long n) {
    unordered_map<int,bool> map;
    // pairs
    for(int i=0; i<n; i++) {
        for(int j=0; j=i+1; j++) {
            int sum = a[i] + a[j];
            if(map.find(sum) != map.end()) {
                return true;
            }
            else {
                map[sum] = true;
            }
        }
    }
    return false;
}

int main() {

    long long a[] = {3,4,7,1,2,9,8};
    long long n = 7;

    bool ans = findPairs(a, n);

    cout<<"Answer is "<<ans<<endl;
    


    return 0;
}
*/


// ******* LONGEST SUBARRAY WITH SUM 0 ********
/*
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxLen(vector<int>& A, int n) {
    unordered_map<int, int> map;
    int csum = 0;
    int ans = 0; // max  length of sunarray with 0 sum;

    for(int i=0; i<n; i++) {
        csum += A[i];
        if(csum == 0) {
            ans = max(ans, i+1);
        }
        
        else if(map.find(csum) == map.end()) {
            map[csum] = i;
        }

        else {
            // map  has csum already.
            ans = max(ans, i - map[csum]);
        }
    }
    return ans;
}

int main() {
    
    vector<int> A{15,-2,2,-8,1,7,10,23};
    int N = A.size();

    int ans = maxLen(A, N);

    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ********* LONGEST SUBARRAY OF 0'S AND 1'S ********
/*
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxLen(vector<int>& A, int n) {
    unordered_map<int, int> map;
    int csum = 0;
    int ans = 0; // max  length of sunarray with 0 sum;

    for(int i=0; i<n; i++) {
        int val = A[i] == 0 ? -1 : 1;
        csum += val;
        if(csum == 0) {
            ans = max(ans, i+1);
        }
        
        else if(map.find(csum) == map.end()) {
            map[csum] = i;
        }

        else {
            // map  has csum already.
            ans = max(ans, i - map[csum]);
        }
    }
    return ans;
}

int main() {
    
    vector<int> A{0,1,0,1};
    int N = A.size();

    int ans = maxLen(A, N);

    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/