class Solution {
public:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>>& heights){
        int n=heights.size();
        int m=heights[0].size();

        vis[row][col]=1;

        queue<pair<int,int>> q;
        q.push({row,col});

        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m &&
                heights[nr][nc]>=heights[r][c] && vis[nr][nc]==0){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> visP(n,vector<int>(m,0));
        vector<vector<int>> visA(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            bfs(i,0,visP,heights);
            bfs(i,m-1,visA,heights);
        }
        for(int i=0;i<m;i++){
            bfs(0,i,visP,heights);
            bfs(n-1,i,visA,heights);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visP[i][j]==1 && visA[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};