import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {

	static double hakjumScore[] = {4.0, 3.0, 2.0, 1.0};
	static String grade[] = { "A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F", "P"};
	static double gradeScore[] = {4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0};
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		double totalHakjum = 0;
		double totalSubjectGrade = 0;
		//전공평점은 전공과목별 (학점 × 과목평점)의 합을 학점의 총합으로 나눈 값이다.
		for(int i = 0; i < 20; i++)
		{
			st = new StringTokenizer(in.readLine());
			String tempSubject = st.nextToken();
			double tempHakjum = Double.parseDouble(st.nextToken());
			String tempGrade = st.nextToken();
			
			if(tempGrade.equals("P")) continue;
			
			totalHakjum += tempHakjum;
			
			for(int g = 0; g < grade.length; g++)
			{
				if(tempGrade.equals(grade[g]))
				{
					totalSubjectGrade += tempHakjum * gradeScore[g];
					break;
				}
			}
		}
		System.out.printf("%f", totalSubjectGrade / totalHakjum);
	}
}