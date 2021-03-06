#include <iostream>
#include <list>
#include <memory.h>

using namespace std;

class Graph{
public:
    int V;
    list<int> *adj;
    Graph(){
        V = 0;
        adj = new list<int>[V];
    }
    explicit Graph(int v){
        V = v;
        adj = new list<int>[V];
    }
    void addEdge(int u,int v) const{
        adj[u].push_back(v);
    }
    void DFSUtil(int v,bool *isVisited){

        isVisited[v] = true;
        cout<<v<<" ";

        for (int & i : adj[v]) {
            if (!isVisited[i]){
                DFSUtil(i,isVisited);
            }
        }
    }
    void DFS(){
        bool *isVisited = new bool[V];
        memset(isVisited,false,V);
        for (int i = 0; i < V; ++i) {
            if (!isVisited[i]){
                DFSUtil(i,isVisited);
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
        g.addEdge(u,v);
    }
    g.DFS();
}