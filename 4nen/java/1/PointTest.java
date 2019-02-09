import java.util.*;

class PointTest
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.print("points count (0 < n <= 1000): ");

        Point[] points = new Point[Math.max(Math.min(input.nextInt(), 1000), 1)];
        Random random = new Random();
        int max;
        if(points.length > 10)
        {
            max = 50;
        }
        else
        {
            max = 20;
        }
        for(int i=0; i<points.length; i++)
        {
            points[i] = new Point(random.nextInt(max), random.nextInt(max));
        }

        Point px = new Point(0, 0);
        double sd = 0;
        for(int y=0; y<max; y++)
        {
            for(int x=0; x<max; x++)
            {
                double ts = 0;
                for(Point p : points)
                {
                    ts += p.getDistance(x, y);
                }
                if(sd == 0) sd = ts;
                if(ts < sd)
                {
                    px.x = x;
                    px.y = y;
                    sd = ts;
                }
            }
        }

        for(int y=0; y<max; y++)
        {
            for(int x=0; x<max; x++)
            {
                System.out.print(' ');
                if(x == px.x && y == px.y)
                {
                    System.out.print('X');
                }
                else
                {
                    int p;
                    for(p=0; p<points.length; p++)
                    {
                        if(points[p].x == x && points[p].y == y)
                        {
                            if(points.length > 10)
                            {
                                System.out.print('*');
                            }
                            else
                            {
                                System.out.print(p);
                            }
                            p = -1;
                            break;
                        }
                    }
                    if(p != -1)
                    {
                        System.out.print('.');
                    }
                }
            }
            System.out.println();
        }

        int target = -1;
        while(target < 0 || target >= points.length)
        {
            System.out.printf("%nどの点について調べますか?: ");
            target = input.nextInt();
        }
        int nearPoint = -1, farPoint = -1;
        for(int i=0; i<points.length; i++)
        {
            if(points[i] != points[target])
            {
                if(nearPoint == -1)
                {
                    nearPoint = i;
                    farPoint = i;
                }
                if(points[i].getDistance(points[target]) < points[nearPoint].getDistance(points[target]))
                {
                    nearPoint = i;
                }
                else if(points[i].getDistance(points[target]) > points[farPoint].getDistance(points[target]))
                {
                    farPoint = i;
                }
            }
        }

        System.out.printf("最も近い点は%d (距離は%.3f)%n", nearPoint, points[nearPoint].getDistance(points[target]));
        System.out.printf("最も遠い点は%d (距離は%.3f)%n", farPoint, points[farPoint].getDistance(points[target]));
    }
}
