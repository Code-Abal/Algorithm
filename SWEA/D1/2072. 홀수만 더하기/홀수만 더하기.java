import java.util.*;
import java.io.*;

public class Solution {
   public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= T; tc++) {
            int[] arr = new int [10];

            String str = br.readLine();
            String[] temp = str.split(" ");
            int ans = 0;
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(temp[i]);
                if(arr[i] % 2 == 1)
                {
                    ans += arr[i];
                }
            }
            StringBuilder sb = new StringBuilder();
            sb.append("#").append(tc).append(" ").append(ans);
            System.out.println(sb.toString());
        }
        br.close();
    }
}