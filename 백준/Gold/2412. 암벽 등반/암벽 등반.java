import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int N, T, cnt = 0;
	static List<Integer>[] xList;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); // 홈의 수
		T = Integer.parseInt(st.nextToken()); // 암벽의 정상
		
		// 리스트 초기화
		xList = new ArrayList[T+1];
		for(int i=0; i<=T; i++) {
			xList[i] = new ArrayList<>();
		}
		
		// 입력
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			xList[y].add(x);
		}
		
		bfs(0, 0);
		if(cnt == 0) cnt = -1;
		System.out.println(cnt);
	}
	
	static void bfs(int x, int y) {
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {y, x, 0});
		
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			
			if (cur[1] == T) {
				cnt = cur[2];
				return;
			}
			
			for(int ny=cur[1]-2; ny<=cur[1]+2; ny++) {
				if (ny < 0 || ny > T) {
					continue;
				}
				
				for(int i = 0; i<xList[ny].size(); i++) {
					int nx = xList[ny].get(i);
					
					if (Math.abs(cur[0]-nx) <= 2) {
						q.add(new int[] {nx, ny, cur[2]+1});
						xList[ny].remove(i); 	// 방문처리
						i--;
					}
				}
			}
		}
	}
}