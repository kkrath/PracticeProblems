#include<iostream>
#include<list>
#include<queue>
using namespace std;


class Graph{
    int v;
    list<int> *adj;

    public:
        Graph(int v){
            this->v = v;
            adj = new list<int>[v];
        }

        void addEdge(int v, int u){
            adj[v].push_back(u);
        }

        void BFS(int s){
            bool *visited  = new bool[v];
            for(int i = 0; i < v; i++)
                visited[v] = false;
            queue<int> queue;
            visited[s] = true;
            queue.push(s);
            list<int>::iterator i;

            while(!queue.empty()){
                s = queue.front();
                cout << s << " ";
                queue.pop();

                for(i = adj[s].begin(); i!= adj[s].end(); ++i){
                    if(!visited[*i]){
                        visited[*i] = true;
                        queue.push(*i);
                    }
                }
            }
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
  
    return 0; 
}