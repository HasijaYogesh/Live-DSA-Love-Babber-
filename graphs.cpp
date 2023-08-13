// ******** ADJECENCY MATRIX IMPLEMENTATION **********
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    vector<vector<int> >adj(n, vector<int>(n,0));

    int e;
    cout<<"Enter the number of edges: "<<endl;
    cin>>e;

    for(int i=0; i<e; i++) {
        int u,v;
        cout<<"Enter u and v"<<endl;
        cin>>u>>v;
        adj[u][v] = 1;
    }


    // printing 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
*/


// ********* ADJECENCY LIST WITHOUT WEIGHT *********
/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected edge
        // direction = 1 -> directed edge

        // create an edge from u to v
        adjList[u].push_back(v);

        if(direction == 0) {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjecencyList() {
        for(auto node: adjList) {
            cout<<node.first<<"-> ";
            for(auto neighbours: node.second) {
                cout<<neighbours<<", ";
            } cout<<endl;
        }
    }
};

int main() {
    // undirected graph
    // Graph g;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);

    // g.printAdjecencyList();

    // directed graph
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,1);
    g.printAdjecencyList();


    return 0;
}
*/


// ********* ADJECENCY LIST WITH WEIGHT *********
/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<pair<int,int> > > adjList;

    void addEdge(int u, int v, int weight, bool direction) {
        // direction = 0 -> undirected edge
        // direction = 1 -> directed edge

        // create an edge from u to v
        adjList[u].push_back({v, weight});

        if(direction == 0) {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back({u,weight});
        }
    }

    void printAdjecencyList() {
        for(auto node: adjList) {
            cout<<node.first<<"-> ";
            for(auto neighbours: node.second) {
                cout<<"("<<neighbours.first<<","<<neighbours.second<<"), ";
            } cout<<endl;
        }
    }
};

int main() {
    Graph g;
    //g.addEdge(sourseNode, destinationNode, weight, direction);
    g.addEdge(0,1,5,1);
    g.addEdge(1,2,8,1);
    g.addEdge(0,2,6,1);
    g.printAdjecencyList();


    return 0;
}
*/


// ********** GRAPH WITH DYNAMIC DATA TYPE STORAGE **********
/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
template<typename T>

class Graph {
    public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        // direction = 0 -> undirected edge
        // direction = 1 -> directed edge

        // create an edge from u to v
        adjList[u].push_back(v);

        if(direction == 0) {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjecencyList() {
        for(auto node: adjList) {
            cout<<node.first<<"-> ";
            for(auto neighbours: node.second) {
                cout<<neighbours<<", ";
            } cout<<endl;
        }
    }
};

int main() {
    
    Graph<char> g;
    g.addEdge('a','b', 0);   
    g.addEdge('b','c', 0);   
    g.addEdge('a','c', 0);   
    g.printAdjecencyList();

    return 0;
}
*/


// ********** TARVERAL WAYS - BREATH FIRST SEARCH & DEPTH FIRST SEARCH ******* 
/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
template<typename T>

class Graph {
    public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        // direction = 0 -> undirected edge
        // direction = 1 -> directed edge

        // create an edge from u to v
        adjList[u].push_back(v);

        if(direction == 0) {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjecencyList() {
        for(auto node: adjList) {
            cout<<node.first<<"-> ";
            for(auto neighbours: node.second) {
                cout<<neighbours<<",";
            } cout<<endl;
        }
    }

    void bfs(T src, unordered_map<T, bool>& visited) {
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            T frontNode = q.front();
            q.pop();
            cout<<frontNode<<", ";

            // insert neighbours
            for(auto neighbour: adjList[frontNode]) {
                if(visited[neighbour] == false) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(T src, unordered_map<T, bool>& visited) {
        cout<<src<<", ";
        visited[src] = true;

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour]) {
                dfs(neighbour, visited);
            }
        }
    }
};

int main() {
    
    // Graph<int> g;
    // // n -> number of nodes in graph
    // int n = 8;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(1,3,0);
    // g.addEdge(3,5,0);
    // g.addEdge(3,7,0);
    // g.addEdge(7,4,0);
    // g.addEdge(7,6,0);

    Graph<int> g;
    // n -> number of nodes in graph
    int n = 5;
    g.addEdge(0,1,0);
    g.addEdge(1,3,0);
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);

    g.printAdjecencyList();
    cout<<endl;
    cout<<"Prinitng BFS Traversal: ";
    unordered_map<int, bool> visited1;
    for(int i=0; i<n; i++) {
        if(!visited1[i]) {
            g.bfs(i, visited1);
        }
    }
    cout<<endl;
    cout<<"Prinitng DFS Traversal: ";
    unordered_map<int, bool> visited2;
    for(int i=0; i<n; i++) {
        if(!visited2[i]) {
            g.dfs(i, visited2);
        }
    }

    return 0;
}
*/


// ********** CHECK IF THE GRAPH IS CYCLIC OR NOT IN UNDIRECTED GRAPH *********
/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
template<typename T>

class Graph {
    public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        // direction = 0 -> undirected edge
        // direction = 1 -> directed edge

        // create an edge from u to v
        adjList[u].push_back(v);

        if(direction == 0) {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjecencyList() {
        for(auto node: adjList) {
            cout<<node.first<<"-> ";
            for(auto neighbours: node.second) {
                cout<<neighbours<<",";
            } cout<<endl;
        }
    }

    void bfs(T src, unordered_map<T, bool>& visited) {
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            T frontNode = q.front();
            q.pop();
            cout<<frontNode<<", ";

            // insert neighbours
            for(auto neighbour: adjList[frontNode]) {
                if(visited[neighbour] == false) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(T src, unordered_map<T, bool>& visited) {
        cout<<src<<", ";
        visited[src] = true;

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour]) {
                dfs(neighbour, visited);
            }
        }
    }

    bool checkCyclicUsingBfs(T src, unordered_map<T, bool>& visited) {
        queue<T> q;
        unordered_map<int,int> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()) {
            T frontNode = q.front();
            q.pop();

            for(auto nbr: adjList[frontNode]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                if(visited[nbr] && nbr != parent[frontNode]) {
                    // cycle present
                    return true;
                }
            }
        }
        return false;
    }

    bool checkCyclicUsingDfs(T src, unordered_map<T, bool>& visited, int parent) {
        visited[src] = true;

        for(auto nbr: adjList[src]) {
            if(!visited[src]) {
                bool checkAageKaAns = checkCyclicUsingDfs(nbr, visited, src);
                if(checkAageKaAns == true) {
                    return true;
                }
            }
            if(visited[nbr] && nbr != parent) {
                // cycle present
                return true;
            }
        }
        return false;
    }
};

int main() {

    Graph<int> g;
    // n -> number of nodes in graph
    int n = 5;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(4,0,0);

    g.printAdjecencyList();
    cout<<endl;

    bool ans = false;
    unordered_map<int, bool> visited;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            ans = g.checkCyclicUsingBfs(i, visited);
            if(ans == true) {
                break;
            }
        }
    }
    if(ans == true) {
        cout<<"Cycle Present"<<endl;
    }
    else {
        cout<<"Cycle Absent"<<endl;
    }


    bool ansDfs = false;
    unordered_map<int, bool> visitedDfs;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            ansDfs = g.checkCyclicUsingDfs(i, visitedDfs, -1);
            if(ansDfs == true) {
                break;
            }
        }
    }
    if(ansDfs == true) {
        cout<<"Cycle Present"<<endl;
    }
    else {
        cout<<"Cycle Absent"<<endl;
    }

    return 0;
}
*/


// ********** CHECK IF THE GRAPH IS CYCLIC OR NOT IN DIRECTED GRAPH *********
/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
template<typename T>

class Graph {
    public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        // direction = 0 -> undirected edge
        // direction = 1 -> directed edge

        // create an edge from u to v
        adjList[u].push_back(v);

        if(direction == 0) {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjecencyList() {
        for(auto node: adjList) {
            cout<<node.first<<"-> ";
            for(auto neighbours: node.second) {
                cout<<neighbours<<",";
            } cout<<endl;
        }
    }

    void bfs(T src, unordered_map<T, bool>& visited) {
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            T frontNode = q.front();
            q.pop();
            cout<<frontNode<<", ";

            // insert neighbours
            for(auto neighbour: adjList[frontNode]) {
                if(visited[neighbour] == false) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(T src, unordered_map<T, bool>& visited) {
        cout<<src<<", ";
        visited[src] = true;

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour]) {
                dfs(neighbour, visited);
            }
        }
    }

    bool checkCyclicDirectedGraphUsingDfs(T src, unordered_map<int,bool>& visited, unordered_map<int,bool>& dfsVisited) {
        visited[src] = true;
        dfsVisited[src] = true;

        for(auto nbr: adjList[src]) {
            if(!visited[nbr]) {
                bool checkAagAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
                if(checkAagAnswer) {
                    return true;
                }
            }
            if(visited[nbr] == true && dfsVisited[nbr] == true) {
                return true;
            } 
        }
        // yahi galti hogi
        dfsVisited[src] = false;
        return false;
    }
};

int main() {

    Graph<int> g;
    // n -> number of nodes in graph
    int n = 5;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,0,1);

    g.printAdjecencyList();
    cout<<endl;


    bool ans = false;

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            ans = g.checkCyclicDirectedGraphUsingDfs(i, visited, dfsVisited);
            if(ans == true) {
                break;
            }
        }
    }

    if(ans) {
        cout<<"Cycle Present"<<endl;
    }
    else {
        cout<<"Cycle Absent"<<endl;
    }

    return 0;
}
*/


// ********* FIND THE TOPOLOGICAL SORT USING DFS & BFS ********
/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
using namespace std;
template<typename T>

class Graph {
    public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        // direction = 0 -> undirected edge
        // direction = 1 -> directed edge

        // create an edge from u to v
        adjList[u].push_back(v);

        if(direction == 0) {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjecencyList() {
        for(auto node: adjList) {
            cout<<node.first<<"-> ";
            for(auto neighbours: node.second) {
                cout<<neighbours<<",";
            } cout<<endl;
        }
    }

    void bfs(T src, unordered_map<T, bool>& visited) {
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            T frontNode = q.front();
            q.pop();
            cout<<frontNode<<", ";

            // insert neighbours
            for(auto neighbour: adjList[frontNode]) {
                if(visited[neighbour] == false) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(T src, unordered_map<T, bool>& visited) {
        cout<<src<<", ";
        visited[src] = true;

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour]) {
                dfs(neighbour, visited);
            }
        }
    }

    bool topologicalSortDfs(T src, unordered_map<int,bool>& visited, stack<int>& ans) {
        visited[src] = true;

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour]) {
                topologicalSortDfs(neighbour, visited, ans);
            }
        }
        // while returning, store the node in stack
        ans.push(src);
    }

    bool topologicalSortBfs(int n, vector<int>& ans) {
        queue<int> q;
        unordered_map<int,int> indegree;

        // indegree calculation
        for(auto i: adjList) {
            int src = i.first;
            for(auto nbr: i.second) {
                indegree[nbr]++;
            }
        }

        //put all nodes inside queue, which has indgree = 0
        for(int i=0; i<n; i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        // bfs logic
        while(!q.empty()) {
            int fNode= q.front();
            q.pop();
            ans.push_back(fNode);
            // or we can do count++ for valid or invalid topological order

            for(auto nbr: adjList[fNode]) {
                indegree[nbr]--;
                // check for 0 again
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }
};

int main() {
    
    Graph<int> g;
    // n -> number of nodes in graph
    // int n = 8;
    // g.addEdge(2,4,1);
    // g.addEdge(2,5,1);
    // g.addEdge(4,6,1);
    // g.addEdge(5,3,1);
    // g.addEdge(3,7,1);
    // g.addEdge(6,7,1);
    // g.addEdge(7,0,1);
    // g.addEdge(7,1,1);

    int n = 4;
    // graph for cycle check
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,1,1);

    g.printAdjecencyList();
    cout<<endl;

    // unordered_map<int, bool> visited;
    // stack<int> ans;

    // for(int i=0; i<n; i++) {
    //     if(!visited[i]) {
    //         g.topologicalSortDfs(i, visited, ans);
    //     }
    // }

    // cout<<"Topological Sort: ";
    // while(!ans.empty()) {
    //     cout<<ans.top()<<",";
    //     ans.pop();
    // }

    vector<int> ans;
    // No need of visited here, because we have travlled all node int the topological function
    g.topologicalSortBfs(n, ans);

    // cout<<"Printing topological sort using BFS: ";
    // for(auto i: ans) {
    //     cout<<i<<",";
    // } cout<<endl;

    if(ans.size() == n) {
        cout<<"Is is a valid topological sort"<<endl;
    }
    else {
        cout<<"Cycle present or invalid topological sort"<<endl;
    }

    return 0;
}
*/


// ********** SHORTEST DISTANCE IN GRAPH USING BFS WITH WEIGHT 1 AND DFS WITH WEIGHTED GRAPH ********
/*
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;

class graph {
    public: 
    unordered_map<int, list<pair<int,int>>> adjList;

    void addEdge(int u, int v, int wt, int direction) {
        // direction = 1 -> Undirected graph
        // direction = 0 -> Directed graph
        adjList[u].push_back({v,wt});

        if(direction == 1) {
            adjList[v].push_back({u,wt});
        }
    }

    void printAdjList() {
        for(auto i: adjList) {
            cout<<i.first<<"->";
            for(auto j: i.second) {
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<endl;
        }
    }

    void shortestPartBSF(int src, int dest) {
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        // initail steps for src
        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        while(!q.empty()) {
            int fNode = q.front();
            q.pop();

            for(auto nbr: adjList[fNode]) {
                if(!visited[nbr.first]) {
                    q.push(nbr.first);
                    visited[nbr.first] = 1;
                    parent[nbr.first] = fNode;
                }
            }
        }

        vector<int> ans;
        int node = dest;

        // store path in ans, after traversing in the parent array
        while(node != -1) {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(), ans.end());

        cout<<"Printing shortest path -> ";
        for(auto i: ans) {
            cout<<i<<", ";
        } cout<<endl;
    }


    void topologicalSortDfs(int  src, unordered_map<int,bool>& visited, stack<int>& ans) {
        visited[src] = true;

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour.first]) {
                topologicalSortDfs(neighbour.first, visited, ans);
            }
        }
        // while returning, store the node in stack
        ans.push(src);
    }

    void shortestPathDfs(int dest, stack<int> topoOrder, int n) {
        vector<int> dist(n, INT_MAX);

        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for(auto nbr: adjList[src]) {
            if((dist[src] + nbr.second) < dist[nbr.first]) {
                dist[nbr.first] = dist[src] + nbr.second;
            }
        }

        while(!topoOrder.empty()) {
            int topElement = topoOrder.top();
            topoOrder.pop();

            if(dist[topElement] != INT_MAX) {
                for(auto nbr: adjList[topElement]) {
                    if((dist[topElement] + nbr.second) < dist[nbr.first]) {
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }

        cout<<"Printing Ans: "<<endl;
        for(int i=0; i<n; i++) {
            cout<<i<<"-> "<<dist[i]<<endl;
        }
    }
};

int main() {
    
    // graph g;

    // g.addEdge(0,1,1,1);
    // g.addEdge(1,2,1,1);
    // g.addEdge(2,3,1,1);
    // g.addEdge(3,4,1,1);
    // g.addEdge(0,5,1,1);
    // g.addEdge(5,4,1,1);
    // g.addEdge(0,6,1,1);
    // g.addEdge(6,7,1,1);
    // g.addEdge(7,8,1,1);
    // g.addEdge(8,4,1,1);

    // g.printAdjList();

    // int src = 0;
    // int dest = 4;

    // g.shortestPartBSF(src, dest);


    graph g;

    g.addEdge(1,1,5,0);
    g.addEdge(0,2,3,0);
    g.addEdge(2,1,2,0);
    g.addEdge(1,3,3,0);
    g.addEdge(2,3,5,0);
    g.addEdge(2,4,6,0);
    g.addEdge(4,3,1,0);

    g.printAdjList();

    stack<int> topoOrder;
    unordered_map<int,bool> visited;
    // topological order
    int n = 5; // no. of nodes
    g.topologicalSortDfs(0, visited, topoOrder);

    cout<<"Printing topo order: "<<endl;

    g.shortestPathDfs(3, topoOrder, n);

    return 0;
}
*/


// *********** DIJKSTRA ALGORITHM TO FIND SHORTEST PATH IN WEIGHTED UNDIRECTED GRAPH *********
/*
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
#include <limits.h>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

class graph {
    public: 
    unordered_map<int, list<pair<int,int>>> adjList;

    void addEdge(int u, int v, int wt, int direction) {
        // direction = 1 -> Undirected graph
        // direction = 0 -> Directed graph
        adjList[u].push_back({v,wt});

        if(direction == 1) {
            adjList[v].push_back({u,wt});
        }
    }

    void printAdjList() {
        for(auto i: adjList) {
            cout<<i.first<<"->";
            for(auto j: i.second) {
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<endl;
        }
    }

    void shortestPartBSF(int src, int dest) {
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        // initail steps for src
        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        while(!q.empty()) {
            int fNode = q.front();
            q.pop();

            for(auto nbr: adjList[fNode]) {
                if(!visited[nbr.first]) {
                    q.push(nbr.first);
                    visited[nbr.first] = 1;
                    parent[nbr.first] = fNode;
                }
            }
        }

        vector<int> ans;
        int node = dest;

        // store path in ans, after traversing in the parent array
        while(node != -1) {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(), ans.end());

        cout<<"Printing shortest path -> ";
        for(auto i: ans) {
            cout<<i<<", ";
        } cout<<endl;
    }


    void topologicalSortDfs(int  src, unordered_map<int,bool>& visited, stack<int>& ans) {
        visited[src] = true;

        for(auto neighbour: adjList[src]) {
            if(!visited[neighbour.first]) {
                topologicalSortDfs(neighbour.first, visited, ans);
            }
        }
        // while returning, store the node in stack
        ans.push(src);
    }

    void shortestPathDfs(int dest, stack<int> topoOrder, int n) {
        vector<int> dist(n, INT_MAX);

        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for(auto nbr: adjList[src]) {
            if((dist[src] + nbr.second) < dist[nbr.first]) {
                dist[nbr.first] = dist[src] + nbr.second;
            }
        }

        while(!topoOrder.empty()) {
            int topElement = topoOrder.top();
            topoOrder.pop();

            if(dist[topElement] != INT_MAX) {
                for(auto nbr: adjList[topElement]) {
                    if((dist[topElement] + nbr.second) < dist[nbr.first]) {
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }

        cout<<"Printing Ans: "<<endl;
        for(int i=0; i<n; i++) {
            cout<<i<<"-> "<<dist[i]<<endl;
        }
    }

    void shortestDistDijkstra(int src, int n) {
        vector<int> dist(n, INT_MAX);
        set<pair<int,int>> st;

        dist[src] = 0;

        st.insert(make_pair(0,src));

        while(!st.empty()) {
            // fetch the smallest or first element from set
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // pop from set
            st.erase(st.begin());

            // neighbour traverse
            for(auto nbr: adjList[node]) {
                if((nbr.second + nodeDistance) < dist[nbr.first]) {
                    // mujhe distance update krna he
                    // finding entry in set
                    auto result = st.find(make_pair(dist[nbr.first], nbr.first));
                    // if found, then remove
                    if(result != st.end()) {
                        st.erase(result);
                    }
                    // updation in dist array and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }

        cout<<"Printing Ans: "<<endl;
        for(int i=0; i<n; i++) {
            cout<<dist[i]<<", ";
        } cout<<endl;
    }
};

int main() {
    
    graph g;
    g.addEdge(6,3,2,1);
    g.addEdge(6,1,14,1);
    g.addEdge(3,1,9,1);
    g.addEdge(3,2,10,1);
    g.addEdge(1,2,7,1);
    g.addEdge(2,4,15,1);
    g.addEdge(4,3,11,1);
    g.addEdge(6,5,9,1);
    g.addEdge(4,5,6,1);

    g.printAdjList();

    g.shortestDistDijkstra(6, 7);

    return 0;
}
*/


// ********** LEET CODE 547 - NUMBER OF PROVINCES ********
/*
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void dfs(unordered_map<int, bool>& vis, int src, vector<vector<int>>& isConnected) {
    vis[src] = true;

    // row -> src;
    // col -> we will write a loop
    int size = isConnected[src].size();
    for(int col=0; col<size; col++) {
        if(src-1 != col && isConnected[src][col] == 1) {
            // col is a nbr
            if(!vis[col]) {
                dfs(vis, col, isConnected);
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    unordered_map<int, bool> visited;
    int count = 0;
    int n = isConnected.size();
    // i represents node here
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(visited, i, isConnected);
            count++;
        }
    }
    return count;
}

int main() {
    vector<vector<int>> input{{1,1,0},{1,1,0},{0,0,1}};

    int ans = findCircleNum(input);
    cout<<"Asnwer is "<<ans<<endl;

    return 0;
}
*/


// ********** LEET CODE 200 - NUMBER OF ISLANDS **********
/*
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

void bfs(map<pair<int,int>,bool>& visited, vector<vector<char>>& grid ,int row, int col) {
    queue<pair<int,int>>q;

    // initial steps
    q.push({row,col});
    visited[{row,col}] = true;

    while(!q.empty()) {
        pair<int,int> fNode = q.front();
        q.pop();

        int x = fNode.first;
        int y = fNode.second;

        // I can move in 4 directions
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0; i<4; i++) {
            int newX = x+dx[i];
            int newY = y+dy[i];

            if(newX>=0 && newX<grid.size() && newY >=0 && newY<=grid[0].size() && !visited[{newX,newY}] && grid[newX][newY] == '1') {
                q.push({newX, newY});
                visited[{newX,newY}] = true;
            }
        }
    }
}

int numsIslands(vector<vector<char>>& grid) {
    map<pair<int,int>,bool> visited;

    int count = 0;
    for(int row=0; row<grid.size(); row++) {
        int n = grid[row].size();
        for(int col=0; col<n; col++) {
            if(!visited[{row,col}] && grid[row][col] == '1') {
                bfs(visited, grid,row, col);
                count++;
            }
        }
    }
    return count;
}

int main() {

    vector<vector<char>> input{{'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'},
                                {'0','0','0','1','1'}};

    int ans = numsIslands(input);
    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/


// ********* LEET CODE 733 - FLOOD FILL **********
/*
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

void dfs(int x, int y, int oldColor, int newColor, map<pair<int,int>,bool>& vis, vector<vector<int>>& arr) {
    vis[{x,y}] = true;
    arr[x][y] = newColor;
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};

    for(int i=0; i<4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if(newX>=0 && newX<arr.size() && newY>=0 && newY<arr[0].size() && !vis[{newX,newY}] && arr[newX][newY] == oldColor) {
            dfs(newX,newY, oldColor, newColor, vis, arr);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    
    int oldColor = image[sr][sc];
    map<pair<int,int>,bool> vis;

    vector<vector<int>> ans = image;
    dfs(sr,sc,oldColor,color,vis, ans);

    return ans;
}

int main() {    

    vector<vector<int>> input{{1,1,1},{1,1,0},{1,0,1}};

    vector<vector<int>> ans = floodFill(input, 1, 1, 2);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}
*/


// ********* LEET CODE 994 - ROTTING ORANGES ********
/*
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<pair<int,int>,int>> q;

    vector<vector<int>> arr = grid;
    int count = 0;
    int ansTime = 0;

    // inserting all rotten oranges in queue
    for(int row=0; row<grid.size(); row++) {
        for(int col=0; col<grid[row].size(); col++) {
            if(grid[row][col] == 2) {
                // rotten orange found
                pair<int,int> coordinates = make_pair(row,col);
                q.push({coordinates,0});
            }
        }
    }

    while(!q.empty()) {
        auto fNode = q.front();
        q.pop();

        int x = fNode.first.first;
        int y = fNode.first.second;
        int time = fNode.second;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i=0; i<4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX>=0 && newX<arr.size() && newY>=0 && newY<arr[0].size() && arr[newX][newY] == 1) {
                pair<int,int> newCoordinates = make_pair(newX,newY);
                ansTime = max(ansTime, time+1);
                q.push({newCoordinates, time+1});
                // mark rotten orange
                arr[newX][newY] = 2;
            }
        }
    }

    // check for fresh orange
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) {
            if(arr[i][j] == 1) {
                // fresh orange found
                return -1;
            }
        }
    }
    return ansTime;
}

int main() {
    vector<vector<int>> grid{{2,1,1},{1,1,0},{0,1,1}};

    int ans = orangesRotting(grid);
    cout<<"Answer is: "<<ans<<endl;

    return 0;
}
*/


// ******** LEET CODE 207 - COURSE SCHEDULE PART 1 - RETURN TRUE/FALSE *********
/*
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

bool topoSortBfs(int n, unordered_map<int,list<int>>& adjList) {
    queue<int> q;
    vector<int> ans;
    unordered_map<int,int> indegree;

    // indegree calculate
    for(auto i: adjList) {
        int src = i.first;
        for(auto nbr: i.second) {
            indegree[nbr]++;
        }
    }

    // put all node inside the queue, which has indegree
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // bfs logic
    while(!q.empty()) {
        int fNode = q.front();
        q.pop();

        ans.push_back(fNode);

        for(auto nbr: adjList[fNode]) {
            indegree[nbr]--;
            // check for zero again
            if(indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
    
    if(ans.size() == n) {
        // valid topo sort
        return true;
    }
    else {
        // invalid / cyclic topo sort
        return false;
    }
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int,list<int>> adjList;

    // build adjacency list
    for(auto task: prerequisites) {
        int u = task[0];
        int v = task[1];
        adjList[v].push_back(u);
    }

    bool ans = topoSortBfs(numCourses, adjList);

    return ans;
}

int main() {

    int nuCourses = 2;
    vector<vector<int>> prerequisites{{1,0},{0,1}};

    cout<<"Answer is "<<canFinish(nuCourses, prerequisites);

    return 0;
}
*/


// ******** LEET CODE 210 - COURSE SCHEDULE PART 2 - RETURN TOPOLOGICAL SORT *********
/*
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

vector<int> topoSortBfs(int n, unordered_map<int,list<int>>& adjList) {
    queue<int> q;
    vector<int> ans;
    unordered_map<int,int> indegree;

    // indegree calculate
    for(auto i: adjList) {
        int src = i.first;
        for(auto nbr: i.second) {
            indegree[nbr]++;
        }
    }

    // put all node inside the queue, which has indegree
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // bfs logic
    while(!q.empty()) {
        int fNode = q.front();
        q.pop();

        ans.push_back(fNode);

        for(auto nbr: adjList[fNode]) {
            indegree[nbr]--;
            // check for zero again
            if(indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
    
    if(ans.size() == n) {
        // valid topo sort
        return ans;
    }
    else {
        // invalid / cyclic topo sort
        return {};
    }
}

vector<int> canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int,list<int>> adjList;

    // build adjacency list
    for(auto task: prerequisites) {
        int u = task[0];
        int v = task[1];
        adjList[v].push_back(u);
    }

    vector<int> ans = topoSortBfs(numCourses, adjList);

    return ans;
}

int main() {

    int nuCourses = 2;
    vector<vector<int>> prerequisites{{1,0},{0,1}};

    vector<int> ans = canFinish(nuCourses, prerequisites);

    for(auto i: ans) {
        cout<<i<<" ";
    } cout<<endl;

    return 0;
}
*/


// ********* LEET CODE 127 - WORD LADDER ********
/*
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>> q;
    q.push({beginWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());

    // jo bhi word queue me insert karunga to usko set me se remove kr dunga
    st.erase(beginWord);

    while(!q.empty()) {
        pair<string,int> fNode = q.front();
        q.pop();

        string currString = fNode.first;
        int currCount = fNode.second;

        // check kahin destination tak to nhi pohoch gye
        if(currString == endWord) {
            return currCount;
        }

        for(int index=0; index<currString.length(); index++) {
            // hr index per jo value he usko me a-z se replace karunga
            char originalCharacter = currString[index];
            for(char ch='a'; ch<='z'; ch++) {
                currString[index] = ch;
                // check in word list
                if(st.find(currString) != st.end()) {
                    q.push({currString, currCount+1});
                    st.erase(currString);
                }
            }
            // bringing back the currString to its original state
            currString[index] = originalCharacter;
        }
    }
    return 0;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList{"hot","dog","dot","lot","log","cog"};

    int ans = ladderLength(beginWord, endWord, wordList);

    cout<<"Answer is "<<ans<<endl;


    return 0;
}
*/


// ******** LEET CODE 1631 - PATH WITH MINIMUM EFFORTS ***********
/*
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
    pq.push({0,{0,0}});
    dist[0][0] = 0;

    while(!pq.empty()) {
        auto fNode = pq.top();
        pq.pop();
        int frontNodeDifference = fNode.first;
        int x = fNode.second.first;
        int y = fNode.second.second;

        // check ans tak toh nhi pahuch gaye
        if(x == heights.size()-1 && y == heights[0].size()-1) {
            return dist[x][y];
        }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0; i<4; i++) {
            int newX = x+dx[i];
            int newY = y+dy[i];

            if(newX >= 0 && newX < heights.size() && newY < heights[0].size() && newY >= 0) {
                int currDiference = abs(heights[x][y] - heights[newX][newY]);
                int newMax = max(frontNodeDifference, currDiference);
                if(newMax < dist[newX][newY]) {
                    dist[newX][newY] = newMax;
                    pq.push({newMax, {newX, newY}});
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> input{{1,2,2},{3,8,2},{5,3,5}};

    int ans = minimumEffortPath(input);
    cout<<"Answer is "<<ans<<endl;

    return 0;
}
*/


// ********** BELLMAN FORD ALGORITHM FOR NEGATIVE CYCLE GRAPH SHORTEST DISTANCE *********
/*
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
#include <limits.h>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

class graph {
    public: 
    unordered_map<int, list<pair<int,int>>> adjList;

    void addEdge(int u, int v, int wt, int direction) {
        // direction = 1 -> Undirected graph
        // direction = 0 -> Directed graph
        adjList[u].push_back({v,wt});

        if(direction == 1) {
            adjList[v].push_back({u,wt});
        }
    }

    void printAdjList() {
        for(auto i: adjList) {
            cout<<i.first<<"->";
            for(auto j: i.second) {
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<endl;
        }
    }

    void bellmanFordAlgo(int n, int src) {
        // assuming directed weighted graph
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // n-1 relaxation step
        for(int i=0; i<n-1; i++) {
            // for all edges
            for(auto t: adjList) {
                for(auto nbr: t.second) {
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // To check for neagtive cycle
        bool negativeCycle = false;
        for(auto t: adjList) {
            for(auto nbr: t.second) {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    negativeCycle = true;
                    break;
                }
            }
        }

        if(negativeCycle == true) {
            cout<<"Negative cycle present";
        }
        else {
            cout<<"Negative cycle absent";
        }

        cout<<"Printing dist array: "<<endl;
        for(auto i: dist) {
            cout<<i<<" ";
        }
    }
};

int main() {
    
    graph g;
    g.addEdge(0,1,-1,0);
    g.addEdge(0,2,4,0);
    g.addEdge(1,2,3,0);
    g.addEdge(1,3,2,0);
    g.addEdge(1,4,2,0);
    g.addEdge(3,1,1,0);
    g.addEdge(3,2,5,0);
    g.addEdge(4,3,-3,0);

    g.bellmanFordAlgo(5, 0);

    return 0;
}
*/


// ********** FLOYD WARSHAL ALGORITHM FOR SHORTEST DISTANCE FROM ALL NODE STO ALL NODES *********
/*
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
#include <limits.h>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

class graph {
    public: 
    unordered_map<int, list<pair<int,int>>> adjList;

    void addEdge(int u, int v, int wt, int direction) {
        // direction = 1 -> Undirected graph
        // direction = 0 -> Directed graph
        adjList[u].push_back({v,wt});

        if(direction == 1) {
            adjList[v].push_back({u,wt});
        }
    }

    void printAdjList() {
        for(auto i: adjList) {
            cout<<i.first<<"->";
            for(auto j: i.second) {
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<endl;
        }
    }

    void floydWarshal(int n) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        // diagonal per zero mark krdo

        for(int i=0; i<n; i++) {
            dist[i][i] = 0;
        }

        // graph ke according distance insert krdia he
        for(auto t: adjList) {
            for(auto nbr: t.second) {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;
            }
        }

        for(int helper =0; helper<n; helper++) {
            for(int src=0; src<n; src++) {
                for(int dest=0; dest<n; dest++) {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper]+dist[helper][dest]);
                }
            }
        }

        cout<<"Printing diatnace array: "<<endl;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<dist[i][j]<<", ";
            }
            cout<<endl;
        }
    }
};

int main() {
    
    graph g;
    g.addEdge(0,1,3,0);
    g.addEdge(0,3,5,0);
    g.addEdge(1,0,2,0);
    g.addEdge(1,3,4,0);
    g.addEdge(2,1,1,0);
    g.addEdge(3,2,2,0);

    g.floydWarshal(4);

    return 0;
}
*/


// ******** KOSA RAJU ALGORITHM FOR STRONGLY CONNECTED COMPONENTS **********
/*
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
#include <limits.h>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

class graph {
    public: 
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, int direction) {
        // direction = 1 -> Undirected graph
        // direction = 0 -> Directed graph
        adjList[u].push_back(v);

        if(direction == 1) {
            adjList[v].push_back(u);
        }
    }

    void dfs1(int src, stack<int>& s, unordered_map<int,bool>& visited) {
        visited[src] = true;

        for(auto nbr: adjList[src]) {
            if(!visited[nbr]) {
                dfs1(nbr, s, visited);
            }
        }
        s.push(src);
    }

    void dfs2(int src, unordered_map<int,bool>& visited, unordered_map<int,list<int>>& adjNew) {
        visited[src] = true;
        cout<<src<<", ";

        for(auto nbr: adjNew[src]) {
            if(!visited[nbr]) {
                dfs2(nbr, visited, adjNew);
            }
        }
    }

    int countSCC(int n) {
        stack<int> s;

        unordered_map<int,bool> visited;
        // find the topological ordering
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs1(i,s,visited);
            }
        }

        // reverse all edges
        unordered_map<int,list<int>> adjNew;
        for(auto t: adjList) {
            for(auto nbr: t.second) {
                int u = t.first;
                int v = nbr;
                // v->u insert
                adjNew[v].push_back(u);
            }
        }

        // traverse using DFS
        int count = 0;
        unordered_map<int,bool> visited2;
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(!visited2[node]) {
                cout<<"Printing : "<<count+1<<"th SCC: ";
                dfs2(node,visited2, adjNew);
                cout<<endl;
                count++;
            }
        }   

        return count;   
    }
};

int main() {
    
    graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,0,0);
    g.addEdge(2,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,6,0);
    g.addEdge(6,4,0);
    g.addEdge(6,7,0);

    int ans = g.countSCC(8);
    cout<<"Number of SCC is : "<<ans<<endl;

    return 0;
}
*/


// ********* TARJAN'S ALGORITHM TO FIND IF BRIDGE EXISTS OR NOT IN GRAPH ***********
/*
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
#include <limits.h>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

class graph {
    public: 
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, int direction) {
        // direction = 1 -> Undirected graph
        // direction = 0 -> Directed graph
        adjList[u].push_back(v);

        if(direction == 1) {
            adjList[v].push_back(u);
        }
    }

    void findBridge(int src, int parent, int& timer, vector<int>& tin, vector<int>& low, unordered_map<int,bool>& vis) {
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(auto nbr: adjList[src]) {
            if(nbr == parent) {
                continue;
            }
            if(!vis[nbr]) {
                // dfs call
                findBridge(nbr, src, timer, tin, low, vis);
                // low update
                low[src] = min(low[src], low[nbr]);
                if(low[nbr] > low[src]) {
                    cout<<"Bridge at--> "<<nbr<<"--"<<src<<endl;
                }
            }
            else {
                // node is visited ans not parent
                // low update
                low[src] = min(low[src], low[nbr]);
            }
        }
    }
};

int main() {
    
    graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,0,1);
    g.addEdge(1,6,1);
    g.addEdge(1,3,1);
    g.addEdge(1,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,5,1);

    int n = 7;
    int timer = 0;
    vector<int> tin(n);
    vector<int> low(n);
    unordered_map<int,bool> vis;
    g.findBridge(0, -1, timer, tin, low, vis);

    return 0;
}
*/


// ********** LEET CODE 1192 - CRITICAL CONNECTIONS INS A NETWORKS *********
/*
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

void findBridge(int src, int parent, int& timer, vector<int>& tin, vector<int>& low, unordered_map<int,bool>& vis, unordered_map<int,list<int>>& adjList,vector<vector<int>>& ans) {
    vis[src] = true;
    tin[src] = timer;
    low[src] = timer;
    timer++;

    for(auto nbr: adjList[src]) {
        if(nbr == parent) {
            continue;
        }
        if(!vis[nbr]) {
            // dfs call
            findBridge(nbr, src, timer, tin, low, vis, adjList, ans);
            // low update
            low[src] = min(low[src], low[nbr]);
            // check for bridge
            if(low[nbr] > tin[src]) {
                vector<int> temp;
                temp.push_back(nbr);
                temp.push_back(src);
                // cout<<"Bridge at -: "<<src<<"----"<<nbr<<endl;
                ans.push_back(temp);
            }
        }
        else {
            // node is visited ans not parent
            // low update
            low[src] = min(low[src], low[nbr]);
        }
    }
}  

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conenctions) {
    unordered_map<int,list<int>> adjList;

    for(int i=0; i<conenctions.size(); i++) {
        int u = conenctions[i][0];
        int v = conenctions[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    int timer = 1;
    vector<int> tin(n);
    vector<int> low(n);
    unordered_map<int,bool> vis;
    findBridge(0,-1,timer,tin,low,vis,adjList,ans);

    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> connections{{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> ans = criticalConnections(n,connections);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<", ";
        }cout<<endl;
    }
    return 0;
}
*/