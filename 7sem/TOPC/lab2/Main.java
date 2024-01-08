import java.io.FileReader;
import java.util.Scanner;

public class Main {

    private static int[][] matrix;
    private static Scanner scanner;
    private static boolean flag = false;
    private static int temp_ch;

    public static void main(String[] args) {
        try{
            int i, n;
            FileReader fr = new FileReader("data.txt");
            matrix = readMatrix(matrix); // управляющая таблица
            i=0; // номер состояния КА
            n=0; // число правильных слов
            String word = new String();
            int ch; // текущая литера
            ch = fr.read();
            while (ch != -1) {
                    if (Character.isLetter(ch)){
                        
                        switch(ch) {
                            case 'W':
                                i = matrix[0][i];
                                word += (char) ch;
                                break;
                            case 'A':
                                i = matrix[1][i];
                                word += (char) ch;
                                break;
                            case 'I':
                                i = matrix[2][i];
                                word += (char) ch;
                                break;
                            case 'T':
                                i = matrix[3][i];
                                word += (char) ch;
                                break;
                            case 'S':
                                i = matrix[4][i];
                                word += (char) ch;
                                break;
                            case 'G':
                                i = matrix[5][i];
                                word += (char) ch;
                                break;
                            case 'N':
                                i = matrix[6][i];
                                word += (char) ch;
                                break;
                            case 'L':
                                i = matrix[7][i];
                                word += (char) ch;
                                break;
                            default:
                                i = matrix[8][i];
                                break;
                        }
                    }

                    else if (Character.isDigit(ch)) {
                                i = matrix[9][i];
                    }
                    else {
                        switch (ch) {
                            case '(':
                                i = matrix[11][i];
                                word += (char) ch;
                                break;
                            case ')':
                                i = matrix[12][i];
                                word += (char) ch;
                                break;
                            case '>':
                                i = matrix[13][i];
                                word += (char) ch;
                                break;
                            case '=':
                                i = matrix[14][i];
                                word += (char) ch;
                                break;
                            case '+':
                                i = matrix[15][i];
                                word += (char) ch;
                                break;
                            case '%':
                                i = matrix[16][i];
                                word += (char) ch;
                                break;
                            case '.':
                                i = matrix[17][i];
                                word += (char) ch;
                                break;
                            case '<':
                                i = matrix[18][i];
                                word += (char) ch;
                                break;
                            default:
                                i = matrix[19][i];
                                word += (char) ch;
                                break;
                        }
                    }
                if ((i > 99)&&(i < 500)) {
                    /* Анализ кода состояния */
                    switch(i){
                        case 100:
                            System.out.println("Служебное слово 'WAIT'. Cостояние = "+i);
                            break;
                        case 200:
                            System.out.println("Служебное слово 'SIGNAL'. Cостояние = "+i);
                            break;
                        case 300:
                            System.out.println("Завершился идентификатор. Cостояние = "+i);
                            break;
                        case 400:
                            System.out.println("Завершилась константа. Cостояние = "+i);
                            break;
                    }
                    i=0;
                    if (ch == '<' || ch == '=' || ch == '>') flag = true;
                }
                else if (i > 500 && i < 800) {
                    switch(i) {
                        case 501:
                            System.out.println("Разделитель '('. Cостояние = " + i);
                            break;
                        case 502:
                            System.out.println("Разделитель ')'. Cостояние = " + i);
                            break;
                        case 503:
                            System.out.println("Разделитель '>'. Cостояние = " + i);
                            break;
                        case 504:
                            System.out.println("Разделитель '='. Cостояние = " + i);
                            break;
                        case 505:
                            System.out.println("Разделитель '+'. Cостояние = " + i);
                            break;
                        case 506:
                            System.out.println("Разделитель '%'. Cостояние = " + i);
                            break;
                        case 507:
                            System.out.println("Разделитель '>='. Cостояние = " + i);
                            break;
                        case 508:
                            System.out.println("Разделитель '<='. Cостояние = " + i);
                            break;
                        default:
                            System.out.println("Ошибка "+i);
                    }
                    i=0;
                }
                else if (i > 800) {
                    switch(i) {
                        case 801:
                            System.out.println("Неправильное начало");
                            break;
                        case 802:
                            System.out.println("Ошибка в служебном слове");
                            break;
                        case 803:
                            System.out.println("Ошибка в написании имени переменной");
                        case 804:
                            System.out.println("Ошибочная константа");
                        case 805:
                            System.out.println("Ошибка");
                        default:
                            System.out.println("Неизвестная входная литера");
                    }
                    i=0;
                    ch = fr.read();
                }
                if (!flag){
                    ch = fr.read();

                }else{
                    flag = false;
                }
            }
        }
            catch (Exception e){
            e.printStackTrace();
        }
    }

    public static int[][] readMatrix(int mas[][]) {
        try{
            scanner = new Scanner(new FileReader("matrix.txt"));
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            if (scanner.hasNextInt()){
                mas = new int [n][m];
                for (int i=0; i<n; i++) {
                    for (int j = 0; j < m; j++ ) {
                        mas[i][j] = scanner.nextInt();
                    }
                }
            }
        } catch (Exception e){
            e.printStackTrace();
        }

        return mas;
    }

    public static void Print(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j] + "  ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
