import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for (int tc = 1; tc <= T; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			int mok = a / b;
			int nmg = a % b;
			
			StringBuilder sb = new StringBuilder();
			
			
			sb.append("#").append(tc).append(" ").append(mok).append(" ").append(nmg).append("\n");
			System.out.print(sb);
		}
	}
}
