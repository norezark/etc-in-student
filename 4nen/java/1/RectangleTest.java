class RectangleTest
{
    public static void main(String[] args)
    {
        Rectangle rect = new Rectangle(10, 20);
        System.out.println("---unfill---");
        rect.draw(false);
        System.out.println("---fill---");
        rect.draw(true);
    }
}
