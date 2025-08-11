import java.io.*;
import java.util.*;

public class Main
{
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());

        List<Integer>[] numList = new ArrayList[N + 1];

        for (int i = 0; i <= N; i++) // 초기화
            numList[i] = new ArrayList<>();

        for (int i = 0; i < M; i++)
        {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            numList[s].add(e);
        }

        int[] distanceArr = new int[N + 1];
        Arrays.fill(distanceArr, -1); // 초기화
        distanceArr[X] = 0; // 방문~

        bfs(numList, distanceArr, X); // 탐색

        boolean isFind = false; // 찾았는가
        
        for (int i = 1; i <= N; i++)
        {
            if (distanceArr[i] == K)
            {
                sb.append(i).append("\n");
                isFind = true;
            }
        }

        if (!isFind)
            System.out.println(-1);
        else
            System.out.print(sb);
    }

    private static void bfs(List<Integer>[] numList, int[] distanceArr, int x)
    {
        Queue<Integer> bfsQ = new LinkedList<>();

        bfsQ.offer(x);

        while (!bfsQ.isEmpty())
        {
            int now = bfsQ.poll();

            for(int next : numList[now])
            {
            	if (distanceArr[next] == -1)
                {
                    distanceArr[next] = distanceArr[now] + 1;
                    bfsQ.offer(next);
                }
            }
        }
    }
}
