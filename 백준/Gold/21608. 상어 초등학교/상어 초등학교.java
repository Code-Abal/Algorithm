import java.io.*;
import java.util.*;

public class Main {
    static final int MAX_N = 20;
    static final int[] dx = {0, 0, 1, -1};
    static final int[] dy = {1, -1, 0, 0};
    static int N;

    static class StudentInfo {
        int studentNum;
        int[] loveLine = new int[4];

        StudentInfo() {
            studentNum = -1;
        }

        StudentInfo(int _studentNum, int _n1, int _n2, int _n3, int _n4) {
            studentNum = _studentNum;
            loveLine[0] = _n1;
            loveLine[1] = _n2;
            loveLine[2] = _n3;
            loveLine[3] = _n4;
        }
    }

    static StudentInfo[] studentInfo = new StudentInfo[MAX_N * MAX_N + 1];
    static int[][] seat = new int[MAX_N + 1][MAX_N + 1];
    static int[] inputOrder = new int[MAX_N * MAX_N + 1];

    public static void main(String[] args) throws IOException {
        init();
        setSeat();
        loveSurvey();
    }

    static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N * N; i++) {
            st = new StringTokenizer(br.readLine());
            int studentNum = Integer.parseInt(st.nextToken());
            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());
            int n3 = Integer.parseInt(st.nextToken());
            int n4 = Integer.parseInt(st.nextToken());

            studentInfo[studentNum] = new StudentInfo(studentNum, n1, n2, n3, n4);
            inputOrder[i + 1] = studentNum;
        }
    }

    static void setSeat() {
        seat[2][2] = inputOrder[1]; // 첫 번째 학생 초기화
        for (int i = 2; i <= N * N; i++) searchSeat(inputOrder[i]);
    }

    static void searchSeat(int studentNum) {
        int loverow = 401, lovecol = 401;
        int maxLoveSeat = 0;
        int loveEmptycol = 401, loveEmptyrow = 401, maxLove_EmptySeat = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (seat[i][j] != 0) continue; // 앉아있으면 패스

                int curEmptySeat = 0, curLoveSeat = 0;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if (nx >= 1 && ny >= 1 && nx <= N && ny <= N) {
                        if (seat[nx][ny] == 0) curEmptySeat++;
                        else {
                            for (int line = 0; line < 4; line++)
                                if (seat[nx][ny] == studentInfo[studentNum].loveLine[line]) curLoveSeat++;
                        }
                    }
                }

                if (curLoveSeat > maxLoveSeat) {
                    maxLoveSeat = curLoveSeat;
                    maxLove_EmptySeat = curEmptySeat;
                    loveEmptycol = i;
                    loveEmptyrow = j;
                } else if (curLoveSeat == maxLoveSeat) {
                    if (maxLove_EmptySeat < curEmptySeat) {
                        maxLove_EmptySeat = curEmptySeat;
                        loveEmptycol = i;
                        loveEmptyrow = j;
                    } else if (maxLove_EmptySeat == curEmptySeat) {
                        if (loveEmptycol > i) {
                            loveEmptycol = i;
                            loveEmptyrow = j;
                        } else if (loveEmptycol == i) {
                            loveEmptyrow = Math.min(loveEmptyrow, j);
                        }
                    }
                }
                lovecol = loveEmptycol;
                loverow = loveEmptyrow;
            }
        }
        seat[lovecol][loverow] = studentNum;
    }

    static void loveSurvey() {
        int score = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int cnt = loveStudentCnt(seat[i][j], i, j);
                if (cnt == 1) score += 1;
                else if (cnt == 2) score += 10;
                else if (cnt == 3) score += 100;
                else if (cnt == 4) score += 1000;
            }
        }
        System.out.println(score);
    }

    static int loveStudentCnt(int studentNum, int i, int j) {
        int studentLoveCnt = 0;
        for (int dir = 0; dir < 4; dir++) {
            int nx = i + dx[dir];
            int ny = j + dy[dir];

            if (nx >= 1 && ny >= 1 && nx <= N && ny <= N) {
                for (int line = 0; line < 4; line++) {
                    if (seat[nx][ny] == studentInfo[studentNum].loveLine[line]) studentLoveCnt++;
                }
            }
        }
        return studentLoveCnt;
    }
}
