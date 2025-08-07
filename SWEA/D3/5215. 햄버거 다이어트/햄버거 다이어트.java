import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int maxTaste = 0;
	static int T[];
	static int K[];
	static int N,L;
	static void dfs(int depth, int sum, int cal) 
	{
		if (depth == N) 
		{
			if (cal <= L && sum > maxTaste) 
			{
				maxTaste = sum;
			}
			return;
		}
		// 재료를 선택하지 않는 경우
		dfs(depth + 1, sum, cal);

		// 현재 재료를 선택하는 경우
		dfs(depth + 1, sum + T[depth], cal + K[depth]);
	}

	public static void main(String[] args) throws Exception 
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		int Tc = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= Tc; tc++) 
		{
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());

			T = new int[N];
			K = new int[N];

			for (int i = 0; i < N; i++) 
			{
				st = new StringTokenizer(br.readLine());
				T[i] = Integer.parseInt(st.nextToken());
				K[i] = Integer.parseInt(st.nextToken());
			}

			maxTaste = 0;
			dfs(0, 0, 0);

			sb.append("#").append(tc).append(" ").append(maxTaste).append("\n");		
		}
		System.out.println(sb);
	}

}
