import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for (int tc = 1; tc <= T; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			
			int cnt = 0;
			
			while(true)
			{
				if((A > N || B > N))
				{
					break;
				}
				
				if(A > B)
				{
					B += A;
				}
				else
				{
					A += B;
				}
				cnt++;
			}
			
			StringBuilder sb = new StringBuilder();
			
			//sb.append("#").append(tc).append(" ").append(sum).append("\n");
			sb.append(cnt).append("\n");
			System.out.print(sb);
		}
	}
}
