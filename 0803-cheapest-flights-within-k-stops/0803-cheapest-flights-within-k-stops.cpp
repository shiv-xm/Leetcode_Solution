class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) 
            adj[f[0]].push_back({f[1], f[2]});

        // dist[node][stops] = min cost to reach node using stops
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        // {cost, node, stops}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int cost = top[0], node = top[1], stops = top[2];

            if (node == dst) return cost;
            if (stops > k) continue;

            for (auto &nxt : adj[node]) {
                int adjNode = nxt.first;
                int price = nxt.second;

                if (cost + price < dist[adjNode][stops + 1]) {
                    dist[adjNode][stops + 1] = cost + price;
                    pq.push({cost + price, adjNode, stops + 1});
                }
            }
        }
        return -1;
    }
};
