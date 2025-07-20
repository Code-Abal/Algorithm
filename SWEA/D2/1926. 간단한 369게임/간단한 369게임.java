import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//int T = Integer.parseInt(br.readLine());
		
		for (int tc = 1; tc <= 1; tc++) {
			StringBuilder sb = new StringBuilder();
			
			int N = Integer.parseInt(br.readLine());
			
			for (int i = 1; i <= N; i++) {
				String str = Integer.toString(i);
				
				int cnt = 0;
				for (char c : str.toCharArray()) {
					int clab = c - '0';
					
					if(clab == 3 || clab == 6 || clab == 9)
					{
						cnt++;
					}
				}
				
				if(cnt > 0)
				{
					for (int j = 0; j < cnt; j++) {
						sb.append("-");
					}				
				}
				else
				{
					sb.append(i);
				}
				sb.append(" ");
			}
			System.out.print(sb);
		}
	}
}
