import java.util.*;
import java.io.*;

public class Solution
{
	static int cnt = 0;
	static void hamburger(boolean visited[], ArrayList<Integer> food[], int idx, int N)
	{
		if(idx > 1)
		{
			for(int i = 0; i < idx; i++)
			{
				if(!visited[i]) continue;
				for(int f : food[i])
				{
					if(visited[i] && visited[f]) return;
				}
			}
		}
		
		if(idx == visited.length)
		{
			cnt++;
			return;
		}
		
		visited[idx] = true;
		hamburger(visited, food, idx + 1, N);
		visited[idx] = false;
		hamburger(visited, food, idx + 1, N);
	}
	
	public static void main(String[] args) throws Exception 
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());	
	    for(int tc = 1; tc <= T; ++tc)
	    {
	    	StringTokenizer st = new StringTokenizer(br.readLine());
	    	int N = Integer.parseInt(st.nextToken());
	    	int M = Integer.parseInt(st.nextToken());
	    	
	    	ArrayList<Integer> food[] = new ArrayList[N + 1];
	    	boolean visited[] = new boolean[N + 1];
	    	for(int i = 0; i < food.length; i++)
	    	{
	    		food[i] = new ArrayList<>();
	    	}
	    	for(int i = 0; i < M; i++)
	    	{
	    		st = new StringTokenizer(br.readLine());
	    		int a = Integer.parseInt(st.nextToken());
	    		int b = Integer.parseInt(st.nextToken());
	    		food[a].add(b);
	    		food[b].add(a);
	    	}
	    	cnt = 0;
	    	hamburger(visited, food, 1, N);
	    	sb.append("#").append(tc).append(" ").append(cnt).append("\n");
	    }
	    System.out.println(sb);
	}
}
