import java.util.*;

import java.io.*;

public class Main {

	public static void main(String[] args) throws Exception
	{
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T = Integer.parseInt(st.nextToken());
		
		for(int tc = 1; tc <= T; tc++)
		{
			String str = br.readLine();
			int N = str.length();
			Queue<Character> chq = new LinkedList<>();
			for(int i = 0; i < N; i++)
			{
				chq.add(str.charAt(i));
			}
			
			int ans = turtle(chq, N);
			System.out.println(ans);
		}
		
	}
	
	static int turtle(Queue<Character> chq, int N)
	{
		int dx[] = { -1, 0, 0, 1 };
		int dy[] = { 0, -1, 1, 0 };
		int dir = 0;
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {N,N});

		int mx_idx_x = 0, mx_idx_y = 0;
		int mn_idx_x = 2100000000, mn_idx_y = 2100000000;

		while (!q.isEmpty())
		{
			int pos[] = q.poll();
			int x = pos[0];
			int y = pos[1];


			mx_idx_x = Math.max(mx_idx_x, x);
			mx_idx_y = Math.max(mx_idx_y, y);
			mn_idx_x = Math.min(mn_idx_x, x);
			mn_idx_y = Math.min(mn_idx_y, y);

			if (chq.isEmpty())
			{
				break;
			}

			char cmd = chq.poll();

			if (cmd == 'F')
			{
				x = x + dx[dir];
				y = y + dy[dir];
			}
			else if (cmd == 'B')
			{
				x = x - dx[dir];
				y = y - dy[dir];
			}
			else if(cmd == 'L')
			{
				if (dir == 0) dir = 1;
				else if (dir == 1) dir = 3;
				else if (dir == 2) dir = 0;
				else if (dir == 3) dir = 2;
			}
			else if (cmd == 'R')
			{
				if (dir == 0) dir = 2;
				else if (dir == 1) dir = 0;
				else if (dir == 2) dir = 3;
				else if (dir == 3) dir = 1;
			}
			q.add(new int[]{ x,y });
		}
		return (mx_idx_x - mn_idx_x) * (mx_idx_y - mn_idx_y);
	}
}
