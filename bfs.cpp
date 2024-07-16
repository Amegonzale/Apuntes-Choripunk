vector<int> dist(n, 1e9);
queue<int> q;

int start = 0;
dist[start] = 0;
q.push(start);

while(!q.empty())
{
    int u = q.front(); q.pop();
    for(int v : graph[u])
    {
        if(dist[u] + 1 < dist[v])
        {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}