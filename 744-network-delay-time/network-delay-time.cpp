class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto nodes:times){
            int u=nodes[0];
            int v=nodes[1];
            int w=nodes[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[k]=0;
        pq.push({0,k}); //{time,node}

        while(!pq.empty()){
            auto [currtime,node]=pq.top();
            pq.pop();
            for(auto [nbr,t]:adj[node]){
                if(currtime+t<dist[nbr]){
                    dist[nbr]=currtime+t;
                    pq.push({dist[nbr],nbr});
                }
            }
        }
        int maxTime = 0;
        for(int i = 1; i <= n; ++i){
            if(dist[i] == INT_MAX) return -1; // some node unreachable
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};