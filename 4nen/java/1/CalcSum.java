import java.util.*;

class CalcSum
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        System.out.print("データ数は？: ");
        int sum = 0, n = input.nextInt();

        for(int i = 1; i <= n; i++)
        {
            System.out.print("No." + i + ": ");
            sum += input.nextInt();
        }

        System.out.println("Sum: " + sum);
        System.out.printf("Average: %5f\n", (double)sum/n);
    }
}
