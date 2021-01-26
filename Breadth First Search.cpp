#include<iostream>
#include <queue>
#include <list>
using namespace std;
class Graph{
public:
    int V;
    list<int> *adj;
    Graph(){
        V = 0;
        adj = new list<int>[V];
    }
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u,int v,int type){
        if (type==0){
            adj[v].push_back(u);
        }
        adj[u].push_back(v);
    }
    void BFS(){
        queue<int> q;
        bool *isVisited = new bool [V];
        for (int i = 0; i < V; ++i) {
            if (!isVisited[i]) {
                q.push(i);
                isVisited[i]= true;
                while (!q.empty()){
                    int top = q.front();
                    q.pop();
                    cout<<top<<" ";
                    for(auto it = adj[top].begin();it!=adj[top].end();it++){
                        if (!isVisited[*it]){
                            isVisited[*it] = true;
                            q.push(*it);
                        }
                    }
                }
            }
        }
    }
};

int main(){
    int V;
    cout<<"Enter Number of Nodes:\n";
    cin>>V;
    int E;
    cout<<"Enter Number of Edges:\n";
    cin>>E;
    Graph g(V);
    for (int i = 0; i < E; ++i) {
        int u,v;
        cout<<"Enter Edge  Number : "<<i+1<<"\n";
        cin>>u>>v;
        g.addEdge(u,v,1);
    }
    g.BFS();
}