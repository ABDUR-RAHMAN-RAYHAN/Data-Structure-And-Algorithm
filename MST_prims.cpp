#include<iostream>
#include<vector>
using namespace std;
class Graph
{
    int n;//number of vertices
    vector<vector<int>> mat;//adjacency matrix
    bool directed;//directed---> true,,,undirected-->false
    vector<int> q,key,par;
public:
    Graph(int n,bool dir): n(n),directed(dir)
    {
        mat=vector<vector<int>>(n,vector<int> (n,0));
        q=vector<int> (n);
        key=vector<int> (n);
        par=vector<int>(n);

    }
    void addedge(int u,int v, int w)
    {
        mat[u][v]=w;
        if(!directed)
        {
            mat[v][u]=w;
        }

    }
    bool isedge(int u,int v)
    {
        if (mat[u][v]!=0)
        {
            return true;
        }
        else return false;
    }
    int extractMin()
    {
        int m=INT_MAX;
        int indx=-1;
        for(int i=0; i<n; i++)
        {
            if(key[i]<m && q[i]==1)
            {
                m=key[i];
                indx=i;
            }
        }
        return indx;
    }

    void MST_prims(int r)
    {
        for(int i=0; i<n; i++)
        {
            q[i]=1;
            key[i]=INT_MAX;
            par[i]=-1;
        }
        key[r]=0;
        for(int i=1; i<=n; i++)
        {
            int u=extractMin();
            q[u]=0;
            if(u==-1){
                    cout<<"This graph is disconnected"<<endl;
                break;
            }
            for(int v=0;v<n;v++){
                if(isedge(u,v)){
                    if(q[v]==1 && key[v]>mat[u][v]){
                        key[v]=mat[u][v];
                        par[v]=u;
                    }
                }
            }
        }
        int cost=0;
        cout<< "Chosen edges for MST:"<<endl;
        for(int i=0;i<n;i++){
            if(i!=r){
                cout<<"( "<<i<<" , "<<par[i]<<" , "<<key[i]<<" )"<<endl;
                cost+=key[i];
            }
        }
        cout<<"Chosen MST cost :"<<cost<<endl;
    }
};
int main()
{
    Graph g(5,false);
    g.addedge(0,1,4);
    g.addedge(0,2,5);
    g.addedge(1,3,3);
    g.addedge(1,4,1);
    g.addedge(2,3,6);
    g.addedge(3,4,2);
    g.MST_prims(2);
}
