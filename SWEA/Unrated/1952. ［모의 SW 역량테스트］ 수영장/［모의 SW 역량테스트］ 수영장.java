import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int pay = 3001;
	static void cal(int MonthDay[], int Price[], boolean Visited[], int Month, int Withdraw)
	{
		if (Month >= 13)
		{
			pay = Math.min(Withdraw, pay);
			return;
		}

		if (Withdraw > pay) return;

		// 1일 이용권
		Visited[Month] = true;
		cal(MonthDay, Price, Visited, Month + 1, Withdraw + (Price[0] * MonthDay[Month]));
		
		// 1달 이용권
		cal(MonthDay, Price, Visited, Month + 1, Withdraw + Price[1]);;
		Visited[Month] = false;

		// 3달 이용권
		for (int i = 0; i < 3; i++)
		{
			if (Month + i > 12) continue;
			Visited[Month + i] = true;
		}
		cal(MonthDay, Price, Visited, Month + 3, Withdraw + Price[2]);
		for (int i = 0; i < 3; i++)
		{
			if (Month + i > 12) continue;
			Visited[Month + i] = false;
		}
		return;
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringBuilder sb = new StringBuilder();
	    int T = Integer.parseInt(br.readLine());		

		for (int tc = 1; tc <= T; tc++)
		{
			int price[] = new int[4];
			int monthDay[] = new int[13];
			boolean visited[] = new boolean[13];
			
		    StringTokenizer st = new StringTokenizer(br.readLine());
			// 1일 1달 3달 1년
			for (int i = 0; i < 4; i++)
			{
				price[i] = Integer.parseInt(st.nextToken());
			}

			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= 12; i++)
			{
				monthDay[i] = Integer.parseInt(st.nextToken());
			}
			pay = 3001;
			cal(monthDay, price, visited, 1, 0);
			sb.append("#").append(tc).append(" ").append(Math.min(pay, price[3])).append("\n");
		}
		System.out.println(sb);
	}
}