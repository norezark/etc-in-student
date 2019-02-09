class MyPointTest
{
    public static void main(String[] args)
    {
        MyPoint p = new MyPoint(2, 3);

        System.out.println( "getX: " + p.getX() +
                            "\ngetY: " + p.getY() +
                            "\ngetR: " + p.getR() +
                            "\nisOrigin: " + p.isOrigin());
    }
}
