class StringChar
{
    public static void main(String[] args)
    {
        int at = 0;
        if(args.length < 2)
        {
            System.out.println("Too few arguments.");
            System.exit(1);
        }
        else
        {
            try
            {
                at = Integer.parseInt(args[1]);
            }
            catch (Exception e)
            {
                System.out.println("Invalid input.");
                System.exit(1);
            }

            if(args[0].length() <= at || at < 0)
            {
                System.out.println("Invalid input.");
                System.exit(1);
            }
        }

        System.out.println(args[0].charAt(at));
    }
}
