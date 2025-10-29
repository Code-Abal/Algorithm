import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int N, T, cnt = Integer.MAX_VALUE;
	static int maxLenX = 0, maxLenY = 0;
	static List<Integer>[] xList;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); // 홈의 수
		T = Integer.parseInt(st.nextToken()); // 암벽의 정상
		
		// 리스트 초기화
		xList = new ArrayList[T+1];
		for(int i=0; i<= T; i++) {
			xList[i] = new ArrayList<>();
		}
		
		// 입력
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int y = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			maxLenX = Math.max(maxLenX, x);
			maxLenY = Math.max(maxLenY, y);
			xList[x].add(y);
		}
		
		bfs(0, 0);
        if(cnt == Integer.MAX_VALUE) cnt = -1;
		System.out.println(cnt);
	}
	
	static void bfs(int x, int y) {
		Queue<int[]> q = new LinkedList<>();
		boolean visited[][] = new boolean[maxLenX + 1][maxLenY + 1];
		q.add(new int[] {x, y, 0});
		
		// cur[0] = 세로, cur[1] = 가로
		
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			
			if (cur[0] == T) {
				cnt = Math.min(cnt, cur[2]);
				return;
			}
			
			for(int nx=cur[0]-2; nx<=cur[0]+2; nx++) {
				
				if (nx < 0 || nx > T) {
					continue;
				}
		
				for(int i = 0; i < xList[nx].size(); i++) {
					int ny = xList[nx].get(i);
					
					if (Math.abs(cur[1] - ny) <= 2) {
						if(!visited[nx][ny])
						{
							q.add(new int[] {nx, ny, cur[2]+1});
							visited[nx][ny] = true;
						}
					}
				}
			}
		}
	}
}