#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
int n, e;
int Partition[MAX], visit[MAX];
vector< int > G[MAX];
bool is_bipartite(int x)
{
    visit[x]=1;
    Partition[x]=1;
    queue<int>q;
    q.push(x);
    while(!q.empty())
    {
        int y=q.front();
        q.pop();
        for(int i=0; i<G[y].size(); i++)
        {
            int r=G[y][i];
            if(Partition[y]==Partition[r]) return false;
            if(visit[r]==0)
            {
                visit[r]=1;
                Partition[r]=3-Partition[y];
                q.push(r);
            }
        }
    }
    return true;
}

int main()
{
    int i, u, v;
    scanf("%d %d", &n, &e);
    for(i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if(is_bipartite(1)) printf("Yes\n");
    else printf("No\n");
    for(i=1;i<=n;i++){
        cout<<Partition[i]<<" ";
    }
    return 0;
}
