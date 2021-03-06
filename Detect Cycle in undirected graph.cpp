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
    void addEdge(int u,int v,int type) const{
        if (type==0){
            adj[v].push_back(u);
        }
        adj[u].push_back(v);
    }
    bool DFSUtil(int v,bool *isVisited,int parent){

        isVisited[v] = true;
        for(int & i : adj[v]) {
            if (!isVisited[i]){
                if (DFSUtil(i,isVisited,v)){
                    return true;
                }
            } else if (i!=parent){
                return true;
            }
        }
        return false;
    }
    bool DFS(){
        bool *isVisited = new bool[V];
        memset(isVisited,false,V);
        for (int i = 0; i < V; ++i) {
            if (!isVisited[i]){
                if (DFSUtil(i,isVisited,-1)){
                    return true;
                }
            }
        }
        return false;
    }
    void checkCycle(){
        if(DFS()){
            cout<<"Cyclic"<<"\n";
        } else{
            cout<<"Acyclic\n";
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
    g.checkCycle();
}