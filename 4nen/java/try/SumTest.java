import java.util.Scanner;

class SumTest
{
    public static void main(String[] args)
    {
        int sum = 0, n = 3;
        Scanner in = new Scanner(System.in);
        for(int i = 0; i < n; i++)
        {
            System.out.print("Input Number: ");
            sum += in.nextInt();
        }
        System.out.println("sum: " + sum);
        System.out.println("average: " + sum / n);
    }
}
