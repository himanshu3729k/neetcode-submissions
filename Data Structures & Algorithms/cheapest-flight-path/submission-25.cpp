class Solution {
public:
    const int M = 1e9;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n,vector<pair<int,int>>());

        for(auto& f:flights){
            g[f[0]].emplace_back(f[1],f[2]);
        }

        vector<vector<int>> dist(n,vector<int>(k+10, M));
        dist[src][0]=0;

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.emplace(0,src,-1);

        while(!pq.empty()){
            auto [cw,cn,cs]=pq.top();
            pq.pop();
            if (cw > dist[cn][cs]) continue;
            if(cs==k+1) continue;

            for(auto& [nn,nw]:g[cn]){
                if(dist[nn][cs+1] > cw+nw){
                    dist[nn][cs+1] = cw+nw;
                    pq.emplace(dist[nn][cs+1], nn, cs+1);
                }
            }
        }

        int ans=M;
        for(int i=0;i<=k;i++){
            ans = min(ans, dist[dst][i]);
        }

        return (ans==M) ? -1 : ans;
    }
};
