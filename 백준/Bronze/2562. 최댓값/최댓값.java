import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int arr[] = new int[9];
		
		int max = 0;
		int idx = 0;
		for(int i = 0; i < arr.length; i++)
		{
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			
			if(Math.max(max, a) == a)
			{
				max = a;
				idx = i + 1;
			}
		}
		System.out.println(max + "\n" + idx);
	}
}