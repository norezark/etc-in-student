public class Triple
{
    int num1, num2, num3;

    void set(int num1, int num2, int num3)
    {
        this.num1 = num1;
        this.num2 = num2;
        this.num3 = num3;
    }

    void show()
    {
        System.out.println(num1 + " " + num2 + " " + num3);
    }

    int max()
    {
        return Math.max(num1, Math.max(num2, num3));
    }

    boolean hasPair()
    {
        return (num1 == num2) || (num2 == num3) || (num3 == num1);
    }

    boolean isAllSame()
    {
        return (num1 == num2) && (num2 == num3) && (num3 == num1);
    }

    void add(Triple t)
    {
        num1 += t.num1;
        num2 += t.num2;
        num3 += t.num3;
    }
}
