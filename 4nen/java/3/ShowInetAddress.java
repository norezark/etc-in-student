import java.net.*;
import java.util.*;

class ShowInetAddress
{
    public static void main(String[] args)
    {
        if(args.length < 1)
        {
            System.out.println("引数を指定してください。");
            System.exit(1);
        }

        try
        {
            InetAddress[] host = InetAddress.getAllByName(args[0]);
            for(InetAddress ip : host)
            {
                System.out.println(ip.getHostAddress());
            }
        }
        catch(UnknownHostException e)
        {
            System.out.println("ホスト名を解決できませんでした。");
        }
    }
}
