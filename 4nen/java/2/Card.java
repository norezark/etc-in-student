import java.util.*;

class Card
{
    public static final int TYPE_FIRE = 0;
    public static final int TYPE_WATER = 1;
    public static final int TYPE_GRASS = 2;

    private int type;
    private int number;

    Card()
    {
        Random random = new Random();
        type = random.nextInt(3);
        number = random.nextInt(9) + 1;
    }

    private int lim(int num, int min, int max)
    {
        return Math.min(max, Math.max(min, num));
    }

    Card(int t, int n)
    {
        type = lim(t, TYPE_FIRE, TYPE_GRASS);
        number = lim(n, 1, 9);
    }

    boolean isStrongerThan(Card c)
    {
        switch((type - c.type + 3) % 3)
        {
            case 1:
                return true;
            case 2:
                return false;
            case 0:
                return number > c.number;
        }

        return false;
    }

    boolean isSameAs(Card c)
    {
        return (number == c.number) && (type == c.type);
    }

    @Override
    public String toString()
    {
        String str = "";
        switch(type)
        {
            case TYPE_FIRE:
                str += "FIRE";
                break;
            case TYPE_WATER:
                str += "WATER";
                break;
            case TYPE_GRASS:
                str += "GRASS";
                break;
        }
        str += "[" + number + "]";

        return str;
    }
}
