import java.util.*;
import java.io.*;

public class Main 
{
	static final int MAX_N = 501;
	static ArrayList<Integer> graph[] = new ArrayList[MAX_N];
	static boolean[] visited= new boolean[MAX_N];
	public static void main(String[] args) throws IOException 
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < MAX_N; i++)graph[i] = new ArrayList<>();
		
		for(int i = 0; i < M; i++)
		{
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			graph[from].add(to);
			graph[to].add(from);
		}
		System.out.println(wedding());
		
	}
	static int wedding()
	{
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[]{1,0});
		int friend = 0;
		while(!q.isEmpty())
		{
			int info[] = q.poll();
			int node = info[0];
			int cnt = info[1];
			
			visited[node] = true;
			
			if(cnt == 2) continue;
			for(int next : graph[node])
			{
				if(!visited[next])
				{
					q.add(new int[] {next, cnt + 1});
					visited[next] = true;
					friend++;
				}
			}
		}
		return friend;
	}
}
