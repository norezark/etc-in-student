class ExceptionTest
{
    public static void main(String[] args)
    {
        if(args.length < 1)
        {
            System.exit(0);
        }

        int x = Integer.parseInt(args[0]);

        switch(x)
        {
            case 0:
                System.out.println("ArithmaticExceptionを発生させます。");
                System.out.println(1 / 0);
                break;
            case 1:
                System.out.println("ArrayIndexOutOfBoundsExceptionを発生させます。");
                System.out.println(args[-1]);
                break;
            case 2:
                System.out.println("NumberFormatExceptionを発生させます。");
                System.out.println(Integer.parseInt("!"));
                break;
            case 3:
                System.out.println("NullPointerExceptionを発生させます。");
                args = null;
                System.out.println(args.length);
                break;
        }
    }
}
