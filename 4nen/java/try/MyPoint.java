public class MyPoint
{
    int x, y;

    MyPoint(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    double getR()
    {
        return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
    }

    boolean isOrigin()
    {
        return x == 0 && y == 0;
    }

    double getDinstance(MyPoint p)
    {
        return Math.sqrt(Math.pow(p.x - x, 2) + Math.pow(p.y - y, 2));
    }
}
