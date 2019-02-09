import java.util.Random;
import java.util.Scanner;

public class RepeatDivide {
    static final int MAX = 1000;
    public static void main(String[] args) {

        Random rnd = new Random();
        int r = rnd.nextInt(MAX);
        Scanner in = new Scanner(System.in);
        int val = r;
        System.out.println(val);

        while(true){
            System.out.print("Input integer : ");
            String line = in.nextLine();
            try
            {
                val = val / Integer.parseInt(line);
            }
            catch (ArithmeticException e)
            {
                System.out.println("演算エラー");
                System.exit(1);
            }
            catch (NumberFormatException e)
            {
                System.out.println("不正入力");
                System.exit(1);
            }
            System.out.println(val);
        }
    }
}

