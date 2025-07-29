/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// double b;
// char g;
// String var;
// long AB;
// a = sc.nextInt();                           // int 변수 1개 입력받는 예제
// b = sc.nextDouble();                        // double 변수 1개 입력받는 예제
// g = sc.nextByte();                          // char 변수 1개 입력받는 예제
// var = sc.next();                            // 문자열 1개 입력받는 예제
// AB = sc.nextLong();                         // long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// double b = 1.0;               
// char g = 'b';
// String var = "ABCDEFG";
// long AB = 12345678901234567L;
//System.out.println(a);                       // int 변수 1개 출력하는 예제
//System.out.println(b); 		       						 // double 변수 1개 출력하는 예제
//System.out.println(g);		       						 // char 변수 1개 출력하는 예제
//System.out.println(var);		       				   // 문자열 1개 출력하는 예제
//System.out.println(AB);		       				     // long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
	static int dx[] = {0, 1, 0, -1};
	static int dy[] = {1, 0, -1, 0};
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++)
		{
			int N = Integer.parseInt(br.readLine());
			
			int arr[][] = new int[N][N];
			boolean visited[][] = new boolean[N][N];
			Queue<int[]> q = new LinkedList<>();
			
			q.add(new int[] {0,0});

			int dir = 0;
			int num = 1;
			
			while(!q.isEmpty())
			{
				int pos[] = q.poll();
				int x = pos[0];
				int y = pos[1];
				
				arr[x][y] = num++; 
				visited[x][y] = true;
				
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				if(nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny])
				{
					dir = (dir + 1) % 4;
					int tx = x + dx[dir];
					int ty = y + dy[dir];
					
					if(tx >= 0 && ty >= 0 && tx < N && ty < N && !visited[tx][ty])
					{
						q.add(new int[] {tx, ty});
					}
					continue;
				}
				q.add(new int[] {nx, ny});
			}
			
			StringBuilder sb = new StringBuilder();
			sb.append("#").append(tc).append("\n");
			
			for(int i = 0; i < N; i++)
			{
				for(int j = 0; j < N; j++)
				{
					sb.append(arr[i][j]).append(" ");
				}
				sb.append("\n");
			}
			System.out.print(sb);
		}
	}
}