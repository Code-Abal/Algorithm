import java.io.*;
import java.util.*;

public class Main {

    static final int MAX_N = 100000;
    static final int MAX_INT = Integer.MAX_VALUE;
    static final int MIN_INT = Integer.MIN_VALUE;

    static class Node {
        long minNode, maxNode;

        Node() {
            this.minNode = Long.MAX_VALUE; // 빈 노드는 최댓값으로 초기화
            this.maxNode = Long.MIN_VALUE; // 빈 노드는 최솟값으로 초기화
        }

        Node(long val) {
            this.minNode = val;
            this.maxNode = val;
        }

        Node(long minNode, long maxNode) {
            this.minNode = minNode;
            this.maxNode = maxNode;
        }
    }

    static long[] arr = new long[MAX_N];
    static Node[] tree = new Node[MAX_N * 4];

    static void init(int node, int start, int end) {
        if (start == end) {
            tree[node] = new Node(arr[start]);
            return;
        }

        int mid = (start + end) / 2;
        init(node * 2, start, mid);
        init(node * 2 + 1, mid + 1, end);

        long minVal = Math.min(tree[node * 2].minNode, tree[node * 2 + 1].minNode);
        long maxVal = Math.max(tree[node * 2].maxNode, tree[node * 2 + 1].maxNode);
        tree[node] = new Node(minVal, maxVal);
    }

    static Node findMinMax(int node, int start, int end, int left, int right) {
        if (right < start || end < left) {
            return new Node();
        }

        if (left <= start && end <= right) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        Node LNode = findMinMax(node * 2, start, mid, left, right);
        Node RNode = findMinMax(node * 2 + 1, mid + 1, end, left, right);

        long minVal = Math.min(LNode.minNode, RNode.minNode);
        long maxVal = Math.max(LNode.maxNode, RNode.maxNode);

        return new Node(minVal, maxVal);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        // 각 줄마다 하나씩 수를 입력받음
        for (int i = 0; i < N; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }

        // tree 배열 초기화
        for (int i = 0; i < tree.length; i++) {
            tree[i] = new Node();
        }

        init(1, 0, N - 1);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            Node ans = findMinMax(1, 0, N - 1, a - 1, b - 1);
            sb.append(ans.minNode).append(" ").append(ans.maxNode).append("\n");
        }

        System.out.print(sb);
    }
}
