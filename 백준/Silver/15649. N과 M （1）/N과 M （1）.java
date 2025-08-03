import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws Exception
	{
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		ArrayList<Integer> arr = new ArrayList<>();
		boolean visited[] = new boolean[N + 1];		
		BackTrack(arr, visited, N, M);
	}
	
	static void BackTrack(ArrayList<Integer> arr, boolean[] visited, int N, int M)
	{
		if(arr.size() == M)
		{
			for (int a : arr)
			{
				System.out.print(a + " ");
			}
			System.out.println();
			return;
		}
		
		for(int i = 1; i <= N; i++)
		{
			// 문제점 발견
			ArrayList<Integer> copyarr = new ArrayList<>(arr);
			if(!visited[i])
			{
				copyarr.add(i);
				visited[i] = true;
				BackTrack(copyarr,visited, N, M);
				visited[i] = false;
			}
		}
		return;
	}
}