import java.util.Scanner;

class CountCharType
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Input String: ");
        String input = in.next();
        int alphabet = 0, number = 0;
        for(int i = 0; i < input.length(); i++)
        {
            if(Character.isLetter(input.charAt(i))) alphabet++;
            if(Character.isDigit(input.charAt(i))) number++;
        }
        System.out.println("Alphabet: " + alphabet);
        System.out.println("Number: " + number);
    }
}
