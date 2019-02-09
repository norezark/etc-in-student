import java.util.Scanner;

class CountWord
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        while(true)
        {
            System.out.print("Input String: ");
            String words = input.nextLine().trim();
            if(words.isEmpty()) break;
            int count = 0;
            if(!isDelimiter(words.charAt(0))) count++;
            for(int i=1; i<words.length(); i++)
            {
                if(isDelimiter(words.charAt(i-1)) && !isDelimiter(words.charAt(i))) count++;
            }
            System.out.println(count + " words");
        }
    }

    private static boolean isDelimiter(char c)
    {
        char[] delimiters = new char[]{' ', ',', '.', '!', '?', ':', ';', '-'};
        for(char d : delimiters)
        {
            if(c == d) return true;
        }
        return false;
    }
}
