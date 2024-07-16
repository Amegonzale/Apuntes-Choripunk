
vector<ll> dist(n, 1e9);
priority_queue<pii, vector<pii>, greater<pii> > q;

ll start = 0;
dist[start] = 0;
q.push(pii(0,start));

while(!q.empty())
{
    pii p = q.top(); q.pop();
    int d = p.first, u = p.second;

    if(d != dist[u]) continue;

    for(pii a : graph[u])
    {
        int v = a.first, w = a.second;
        if(dist[u] + w < dist[v])
        {
            dist[v] = dist[u] + w;
            q.push(pii(dist[v],v));
        }
    }
}
