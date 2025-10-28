#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    queue<vector<int>> q;
    vector<vector<bool>> visited (maps.size(), vector<bool>(maps[0].size(), false));
    vector<vector<int>> dist (maps.size(), vector<int>(maps[0].size(), 2100000000));
    q.push({0,0,1});
    visited[0][0] = true;
    
    while(!q.empty())
    {
        vector<int> info = q.front();
        int x = info[0];
        int y = info[1];
        int curDist = info[2];
        q.pop();
        
        if(x == maps.size() - 1 && y == maps[0].size() - 1) return dist[x][y];
        
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx >= 0 && ny >= 0 && nx < maps.size() && ny < maps[0].size() && maps[nx][ny] == 1)
            {
                if(curDist + 1 < dist[nx][ny]){dist[nx][ny] = curDist + 1; q.push({nx, ny, curDist + 1});}
            }
        }
    }
    return -1;
}