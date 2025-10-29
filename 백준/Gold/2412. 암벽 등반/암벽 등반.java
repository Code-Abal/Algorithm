import java.util.*;

public class Main {
	static int N, T, cnt = -1;
	static List<Integer>[] xList;
	
	public static void main(String[] args) throws Exception {
		N = read(); // 홈의 수
		T = read(); // 암벽의 정상
		
		// 리스트 초기화
		xList = new ArrayList[T+1];
		for(int i=0; i<=T; i++) {
			xList[i] = new ArrayList<>();
		}
		
		// 입력
		for(int i=0; i < N; i++) {
			int x = read();
			int y = read();
			
			xList[y].add(x);
		}
		bfs();
		System.out.println(cnt);
	}
	
	static void bfs() {
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {0, 0, 0});
		
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			
			if (cur[1] == T) {cnt = cur[2]; return;}
			
			for(int ny=cur[1]-2; ny<=cur[1]+2; ny++) {
				if (ny < 0 || ny > T) continue;
				
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
	
	private static int read() throws Exception {
	    int c;
	    while ((c = System.in.read()) <= 32) {
	        if (c == -1) return -1; // EOF
	    }

	    int n = c & 15;
	    while ((c = System.in.read()) > 32) {
	        n = (n << 3) + (n << 1) + (c & 15);
	    }
	    return n;
	}

}