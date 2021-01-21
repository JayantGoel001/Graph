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
    explicit Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u,int v,int type) const{
        if (type==0){
            adj[v].push_back(u);
        }
        adj[u].push_back(v);
    }
    void DFSUtil(int v,bool *isVisited){
        isVisited[v] = true;
        cout<<v<<" ";
        for(int & it : adj[v]){
            if (!isVisited[it]) {
                DFSUtil(it, isVisited);
            }
        }
    }
    void DFS(){
        bool *isVisited = new bool[V];
        memset(isVisited,false,V);

        for (int i = 0; i < V; ++i) {
            if (!isVisited[i]) {
                DFSUtil(i, isVisited);
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
        g.addEdge(u,v,0);
    }
    int startNode = 0;
    cout<<"Enter Starting Node : "<<"\n";
    cin>>startNode;
    g.DFS();
}