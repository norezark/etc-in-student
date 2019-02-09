import java.util.*;
import java.io.*;

class ToUpper
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String outFileName = "out.txt";

        try
        {
            FileWriter fw = new FileWriter(outFileName);

            System.out.println("テキストを入力してください。");
            while(true)
            {
                if(input.hasNextLine())
                {
                    fw.write(input.nextLine().toUpperCase());
                }
                else break;

                fw.write("\n");
            }
            fw.close();
        }
        catch(IOException e)
        {
            System.out.println(outFileName + "に書き込むことができません。終了します。");
        }
    }
}
