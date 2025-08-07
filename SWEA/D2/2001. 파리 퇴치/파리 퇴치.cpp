import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String[] args) throws Exception, Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; ++tc)
		{
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			
			int arr[][] = new int[N][N];
			
			for(int i = 0; i < N; i++)
			{
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < N; j++)
				{
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			int maxFly = 0;
			for(int i = 0; i <= N - M; i++)
			{
				for(int j = 0; j <= N - M; j++)
				{
					int Fly = 0;
					for(int k = i; k < i + M; k++)
					{
						for(int p = j; p < j + M; p++)
						{
							Fly += arr[k][p];
						}
					}
					maxFly = Math.max(maxFly, Fly);
				}
			}
			sb.append("#").append(tc).append(" ").append(maxFly).append("\n");
		}
		System.out.println(sb);
	}

}
