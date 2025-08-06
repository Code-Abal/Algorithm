import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
	static int win = 0;
	static int lose = 0;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int tc = Integer.parseInt(br.readLine());
		
		for (int T = 1; T <= tc; T++) {
			win = 0; lose = 0;
			int kyu[] = new int[9];
			int in[] = new int[9];
			boolean[] visited= new boolean [19];
			
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < 9; i++)
			{
				kyu[i] = Integer.parseInt(st.nextToken());
				visited[kyu[i]] = true;
			}
			
			int idx = 0;
			for(int i = 1; i <= 18; i++)
			{
				if(!visited[i])
				{
					in[idx++] = i;
					visited[i] = true;
				}
			}
			visited = new boolean[9];
			int permu[] = new int[9];
			recursion(in, kyu, visited, permu, 0);
			
			StringBuilder sb = new StringBuilder();
			sb.append("#").append(T).append(" ").append(win).append(" ").append(lose);
			System.out.println(sb);
		}
	}
	static void recursion(int[] in, int[] kyu, boolean[] visited, int[] permu, int idx)
	{
		if(idx == 9)
		{
			battle(permu, kyu);
			return;
		}
		
		for(int i = 0; i < 9; i++)
		{
			if(!visited[i])
			{
				permu[idx] = in[i];
				visited[i] = true;
				recursion(in, kyu, visited, permu, idx + 1);
				visited[i] = false;
			}
		}
	}
	
	static void battle(int[] inyung, int[] kyu)
	{
		int scoreK = 0, scoreI = 0;
		for(int i = 0; i < 9; i++)
		{
			int score = kyu[i] + inyung[i];
			if(kyu[i] > inyung[i]) scoreK += score;
			else if(kyu[i] < inyung[i]) scoreI += score;
		}
		if(scoreK > scoreI) win++;
		else lose++;
	}
}