import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//int T = Integer.parseInt(br.readLine());
		
		for (int tc = 1; tc <= 1; tc++) {
			//StringTokenizer st = new StringTokenizer(br.readLine());
			
			//String str = br.readLine();
			
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if(i == j)
					{
						sb.append("#");
					}
					else
					{
						sb.append("+");
					}
				}
				sb.append("\n");
			}
			
			//sb.append("#").append(tc).append(" ").append(sum).append("\n");
			System.out.print(sb);
		}
	}
}
