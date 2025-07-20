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
			int b = Integer.parseInt(st.nextToken());
			
			char c = a > b ? 'A' : 'B';
			
			StringBuilder sb = new StringBuilder();
			
			//sb.append("#").append(tc).append(" ").append(sum).append("\n");
			sb.append(c).append("\n");
			System.out.print(sb);
		}
	}
}
