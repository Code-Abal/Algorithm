import java.io.*;
import java.util.*;

public class Main {

	static int dx[] = {0, 1, 0, -1};
	static int dy[] = {1, 0, -1, 0};
	
	public static void main(String[] args) throws Exception 
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int M = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			
			int arr[][] = new int[N][M];
			boolean visited[][] = new boolean[N][M];
			int cnt = 0;
			for(int i = 0; i < K; i++)
			{
				st = new StringTokenizer(br.readLine());
				int y = Integer.parseInt(st.nextToken());
				int x = Integer.parseInt(st.nextToken());
				arr[x][y] = 1;
			}
			for(int i = 0; i < N; i++)
			{
				for(int j = 0; j < M; j++)
				{
					if(!visited[i][j] && arr[i][j] == 1)
					{
						BFS(arr, visited, i, j, N, M);
						cnt++;
					}
				}
			}
			System.out.println(cnt);
		}
	}
	
	static void BFS(int arr[][], boolean visited[][], int x, int y, int N, int M)
	{
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {x, y});
		visited[x][y] = true;
		
		while(!q.isEmpty())
		{
			int pos[] = q.poll();
			int posX = pos[0];
			int posY = pos[1];
			
			for(int dir = 0; dir < 4; dir++)
			{
				int nx = posX + dx[dir];
				int ny = posY + dy[dir];
				
				if(nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny])
				{
					if(arr[nx][ny] == 1)
					{
						q.add(new int[] {nx,ny});
						visited[nx][ny] = true;
					}
				}
			}
		}
	}
}
