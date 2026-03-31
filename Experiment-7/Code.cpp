class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        queue<pair<int,pair<int,int>>> q;

        vector<int> dist(n,1e9);
        
        dist[src]=0;

        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        // stops,node,distance.
        q.push({0,{src,0}});

        while(!q.empty()){

            auto a=q.front();
            q.pop();

            int stops=a.first;
            int node=a.second.first;
            int cost=a.second.second;

            if(stops>k){
                continue;
            }
            for(auto iter:adj[node]){
                int ngh=iter.first;
                int eW=iter.second;

                if(cost+eW < dist[ngh] && stops<=k){
                    dist[ngh]=cost+eW;
                    q.push({stops+1,{ngh,dist[ngh]}});
                }
            }
        }

        if(dist[dst]==1e9) return -1;
        else{
            return dist[dst];
        }
        
    }
};