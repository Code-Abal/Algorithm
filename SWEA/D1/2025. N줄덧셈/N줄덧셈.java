import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//int T = Integer.parseInt(br.readLine());
		
		for (int tc = 1; tc <= 1; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			
			int sum = 0;
			for (int i = 1; i <= a; i++) {
				sum += i;
			}
			
			StringBuilder sb = new StringBuilder();
			
			//sb.append("#").append(tc).append(" ").append(sum).append("\n");
			sb.append(sum).append("\n");
			System.out.print(sb);
		}
	}
}
