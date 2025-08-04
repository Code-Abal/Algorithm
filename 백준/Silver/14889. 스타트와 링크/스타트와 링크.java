import java.util.*;
import java.io.*;

public class Main {
	
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception
	{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		
		int team[][] = new int[N + 1][N + 1];

		for (int i = 1; i <= N; i++) 
		{	
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) 
			{
				team[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		//조합 추출
		Deque<ArrayList<Integer>> dq = new LinkedList<>();
		ArrayList<Integer> arr = new ArrayList<>();
		BackTrack(arr, dq, 1, N, N / 2);
		
		//큐 앞뒤에서 접근
		int minpower = Integer.MAX_VALUE;
		while(!dq.isEmpty())
		{
			ArrayList<Integer> start = new ArrayList<>(dq.pollFirst());
			ArrayList<Integer> link = new ArrayList<>(dq.pollLast());
			
			int startpower = 0;
			int linkpower = 0;
			for(int i = 0; i < start.size() - 1; i++)
			{
				for(int j = i + 1; j < start.size(); j++)
				{
					startpower += team[start.get(i)][start.get(j)] + team[start.get(j)][start.get(i)];
					linkpower += team[link.get(i)][link.get(j)] + team[link.get(j)][link.get(i)];
				}
			}
			int power = Math.abs(startpower - linkpower);
			minpower = Math.min(minpower, power);
		}
		
		System.out.println(minpower);
	}
	static void BackTrack(ArrayList<Integer> arr, Deque<ArrayList<Integer>> dq, int idx, int N, int M)
	{
		if(arr.size() == M)
		{
			dq.add(arr);
			return;
		}
		
		for(int i = idx; i <= N; i++)
		{
			ArrayList<Integer> copyarr = new ArrayList<>(arr);
			copyarr.add(i);
			BackTrack(copyarr, dq, i + 1, N, M);
		}
	}
}
