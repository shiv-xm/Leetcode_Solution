class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        dist[0][0]=0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            auto t=pq.top(); pq.pop();
            int eff=t[0], x=t[1],y=t[2];
            if(x==n-1 && y==m-1)return eff;

            for(auto &d : dirs){
                int nx= x+d[0], ny = y+ d[1];
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int newEff = max(eff,abs(heights[nx][ny]-heights[x][y]));
                    if(newEff <dist[nx][ny]){
                        dist[nx][ny] = newEff;
                        pq.push({newEff,nx,ny});
                    }
                }
            }
        }
        return 0;
    }
};