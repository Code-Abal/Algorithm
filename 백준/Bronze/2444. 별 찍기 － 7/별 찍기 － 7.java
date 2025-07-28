import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		for(int i = 1; i <= N - 1; i++)
		{
			for(int space = N - i; space >= 1; --space)
			{
				System.out.print(" ");
			}
			
			for(int j = 1; j <= (i * 2) - 1; ++j)
			{
				System.out.print("*");
			}
			System.out.println();
		}

		for(int i = N; i >= 1; --i)
		{			
			for(int space = 1; space <= N - i; ++space)
			{
				System.out.print(" ");
			}
			
			for(int j = 1; j <= (i * 2) - 1; j++)
			{
				System.out.print("*");
			}
			
			System.out.println();
		}
	}
}