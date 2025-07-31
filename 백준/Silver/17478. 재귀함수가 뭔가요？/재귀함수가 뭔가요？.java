import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N = 0;
    public static void main(String[] args) throws IOException {BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    
    String front = "";
    
    System.out.println("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n"
    		+ "\"재귀함수가 뭔가요?\"\n"
    		+ "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n"
    		+ "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n"
    		+ "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
    recursion(front, 1);
    System.out.println("라고 답변하였지.\n");
    }
    
    static void recursion(String front, int cnt)
    {
    	front += "____";
    	
    	if(cnt == N)
    	{
    		System.out.println(front + "\"재귀함수가 뭔가요?\"\n"
            		+ front + "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n"
            		+ front + "라고 답변하였지.");
    		return;
    	}
    	
    	System.out.println(front + "\"재귀함수가 뭔가요?\"\n"
        		+ front + "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n"
        		+ front + "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n"
        		+ front + "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
        
    	recursion(front, cnt + 1);
        
        System.out.println(front + "라고 답변하였지.");
        
    }
}

