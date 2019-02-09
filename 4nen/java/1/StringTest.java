public class StringTest
{
    public static void main(String[] args)
    {
        String s1 = "Hello, world";
        String s2 = "!!!";

        System.out.println("(1): " + s1.charAt(1));
        System.out.println("(2): " + s1.length());
        System.out.println("(3): " + s1.endsWith("world"));
        System.out.println("(4): " + s1.indexOf("o"));
        System.out.println("(5): " + s1.lastIndexOf("o"));
        System.out.println("(6): " + s1.substring(7, 11));
        System.out.println("(7): " + s1.toUpperCase());
        System.out.println("(8): " + s1.equals(s2));
        System.out.println("(9): " + s1.concat(s2));
    }
}
