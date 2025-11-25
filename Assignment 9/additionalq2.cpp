#include <iostream>
#define INF 1000000
using namespace std;

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INF, min_index = -1;
    for(int v=0; v<V; v++)
        if(!sptSet[v] && dist[v]<=min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

int main() {
    int m, n;
    cin >> m >> n;
    int grid[20][20];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> grid[i][j];
    int V = m*n;
    int graph[400][400] = {0};
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) {
            int u = i*n + j;
            if(i>0) graph[u][(i-1)*n+j] = grid[i-1][j];
            if(i<m-1) graph[u][(i+1)*n+j] = grid[i+1][j];
            if(j>0) graph[u][i*n+j-1] = grid[i][j-1];
            if(j<n-1) graph[u][i*n+j+1] = grid[i][j+1];
        }
    int dist[400];
    bool sptSet[400];
    for(int i=0;i<V;i++) {
        dist[i]=INF;
        sptSet[i]=0;
    }
    dist[0]=grid[0][0];
    for(int count=0; count<V-1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u]=true;
        for(int v=0;v<V;v++)
            if(!sptSet[v] && graph[u][v] && dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
    }
    cout << dist[V-1] << endl;
    return 0;
}
