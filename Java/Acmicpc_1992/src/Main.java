import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
Acmicpc
- 쿼드트리 (https://www.acmicpc.net/problem/1992)
 */
public class Main {
    private static int[][] paper;

    public static void main(String[] args) {
        try (
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))
        ) {
            int N = Integer.parseInt(br.readLine());
            paper = new int[N+1][N+1];
            for (int i = 1; i <= N; i++) {
                String line = br.readLine();
                for (int j = 1; j <= N ; j++) {
                    paper[j][i] = Integer.parseInt(String.valueOf(line.charAt(j-1)));
                }
            }
            bw.write(paperCounter(1, N, 1, N, N));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static String paperCounter(int start_x, int finish_x, int start_y, int finish_y, int width) {
        StringBuilder result = new StringBuilder();
        if((start_x > finish_x) || (start_y > finish_y)) {
            return "";
        }

        boolean paperIsWhite = (paper[start_x][start_y] == 0);
        int totalCell = width * width;
        int countCell = 0;

        for (int i = start_x; i <= finish_x ; i++) {
            for (int j = start_y; j <= finish_y ; j++) {

                if((paper[i][j] == 1) && (!paperIsWhite)) {
                    countCell++;
                } else if((paper[i][j] == 0) && (paperIsWhite)){
                    countCell++;
                } else {
                    break;
                }
            }
        }

        if (totalCell == countCell) {
            if(paperIsWhite) {
                result.append("0");
            } else {
                result.append("1");
            }
        } else {
            width /= 2;
            result.append("(");
            result.append(paperCounter(start_x, finish_x - width, start_y, finish_y - width, width));
            result.append(paperCounter(start_x + width, finish_x, start_y, finish_y - width, width));
            result.append(paperCounter(start_x, finish_x - width, start_y + width, finish_y, width));
            result.append(paperCounter(start_x + width, finish_x, start_y + width, finish_y, width));
            result.append(")");
        }

        return result.toString();
    }

}
