public class Rectangle
{
    int height;
    int width;

    Rectangle(int height, int width)
    {
        this.height = height;
        this.width = width;
    }

    int getArea()
    {
        return height * width;
    }

    void draw(boolean fills)
    {
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                if(i == 0 || i == height-1 || j == 0 || j == width-1 || fills)
                {
                    System.out.print('*');
                }
                else
                {
                    System.out.print(' ');
                }
            }
            System.out.print('\n');
        }

        //for(int i=0; i<height; i++) System.out.println("*" + new String(new char[width-2]).replace("\0", (i == 0 || i == height-1 || fills)?"*":" ") + "*");
    }
}
