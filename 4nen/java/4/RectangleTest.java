import static org.hamcrest.CoreMatchers.*;
import static org.junit.Assert.*;

import org.junit.*;


public class RectangleTest {
    private Rectangle rectangle;

    public static void main(String[] args)
    {
        org.junit.runner.JUnitCore.main(RectangleTest.class.getName());
    }
    @Before
    public void setUp()
    {
        rectangle = new Rectangle();
    }
    @Test
    public void checkOverlapにR(0を与えるとREALを返す()
    {
        assertThat(quadEquation.getSolution(1, 3, 1), is(QuadEquation.SolutionType.REAL));
    }
}
