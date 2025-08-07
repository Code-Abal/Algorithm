import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Solution 
{
	static class Food
	{
		int taste;
		int calory;
		Food(int t, int c)
		{
			this.taste = t;
			this.calory = c;
		}
	}
	
	static int JMT = 0;
	
	public static void main(String[] args) throws Exception 
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; ++tc)
		{
			//이전 테스트케이스에 영향을 줄 수 있으므로, 초기화.
			JMT = 0;
			
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int L = Integer.parseInt(st.nextToken());

			Food foods[] = new Food[N];
			boolean visited[] = new boolean[N];
			for(int i = 0; i < N; i++)
			{
				st = new StringTokenizer(br.readLine());
				int taste = Integer.parseInt(st.nextToken());
				int calory = Integer.parseInt(st.nextToken());
				foods[i] = new Food(taste, calory);
			}
			
			BackTrack(foods, visited, L, 0, 0, 0);
			
			sb.append("#").append(tc).append(" ").append(JMT).append("\n");
		}
		System.out.println(sb);
	}
	static void BackTrack(Food foods[], boolean visited[], int L, int calory, int taste, int idx)
	{
		if(calory > L)return;

		JMT = Math.max(JMT, taste);
		
		for(int i = idx; i < foods.length; i++)
		{
			if(!visited[i])
			{
				visited[i] = true;
				BackTrack(foods, visited, L, calory + foods[i].calory, taste + foods[i].taste, i + 1);
				visited[i] = false;
			}
		}
	}
}