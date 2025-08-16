import java.util.*;
import java.io.*;
public class Main 
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int dx[]  = {-1, 0, 1};
	static int dy[]  = {1, 1, 1};
	
	static boolean pipeLine(char arr[][], int R, int C, int startX, int startY)
	{
		int x = startX;
		int y = startY;
		arr[x][y] = 'x';
		
		if(y == C - 1) return true;
		
		for(int dir = 0; dir < 3; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if (nx >= 0 && ny >= 0 && nx < R && ny < C && arr[nx][ny] != 'x') 
			{
                // 연결이 가능하다면 재귀 호출
                if (pipeLine(arr, R, C, nx, ny)) 
                {
                    return true;
                }
            }
		}
		return false;
	}
	
	public static void main(String[] args) throws Exception 
	{
		st = new StringTokenizer(br.readLine());
		int R = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		
		char arr[][] = new char[R][C];
		Queue<int[]> start = new LinkedList<>();
		for(int i = 0; i < R; i++)
		{
			String temp = br.readLine();
			for(int j = 0; j < C; j++)
			{
				arr[i][j] = temp.charAt(j);
				if(j == 0)
				{
					start.add(new int[] {i, j});
				}
			}
		}
		int cnt = 0;
		while(!start.isEmpty())
		{
			int pos[] = start.poll();
			int x = pos[0];
			int y = pos[1];
			
			if(pipeLine(arr, R, C, x, y))
			{
				cnt++;
			}
		}
		System.out.println(cnt);
	}

}
