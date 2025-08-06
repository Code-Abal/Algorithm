import java.util.*;
import java.io.*;

class Solution
{
	public static void main(String[] args) throws Exception
	{
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		for(int tc = 1; tc <= 10; tc++)
		{
			int T = Integer.parseInt(br.readLine());
			int arr[][] = new int[100][100];
			boolean visited[][] = new boolean[100][100];
			
			int startX = 0, startY = 0;
			for(int i = 0; i < 100; i++)
			{
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < 100; j++)
				{
					arr[i][j] = Integer.parseInt(st.nextToken());
					if(arr[i][j] == 2)
					{
						startX = i;
						startY = j;
					}
				}
			}
			int ans = BFS(arr, visited, startX, startY);
			System.out.println("#" + T + " " + ans);
		}
	}
	static int BFS(int arr[][], boolean visited[][], int startX, int startY)
	{
        //{좌 우 상}, 순서로 탐색 -> 좌우가 0일 때 상 탐색.
		int dx[] = {0,0,-1};
		int dy[] = {-1,1,0};
		
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {startX,startY});
		visited[startX][startY] = true;
		while(!q.isEmpty())
		{
			int pos[] = q.poll();
			int x = pos[0];
			int y = pos[1];
			if(x == 0) return y;
			for(int i = 0; i < 3; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx >= 0 && ny >= 0 && nx < 100 && ny < 100 && !visited[nx][ny])
				{
					if(arr[nx][ny] == 1)
					{
						q.add(new int[] {nx,ny});
						visited[nx][ny] = true;
						break;						
					}
				}
			}
		}
		return 0;
	}
}