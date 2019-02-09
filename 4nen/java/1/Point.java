public class Point
{
    int x, y;

    Point(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    double getDistance(Point p)
    {
        return Math.sqrt(Math.pow(x - p.x, 2) + Math.pow(y - p.y, 2));
    }
    double getDistance(int x, int y)
    {
        return Math.sqrt(Math.pow(this.x - x, 2) + Math.pow(this.y - y, 2));
    }
}
