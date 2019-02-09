import static org.hamcrest.CoreMatchers.*;
import static org.junit.Assert.*;

import org.junit.*;


public class QuadEquationTest {
    private QuadEquation quadEquation;

    public static void main(String[] args)
    {
        org.junit.runner.JUnitCore.main(QuadEquationTest.class.getName());
    }
    @Before
    public void setUp()
    {
        quadEquation = new QuadEquation();
    }
    @Test
    public void getSolutionに1_3_1を与えるとREALを返す()
    {
        assertThat(quadEquation.getSolution(1, 3, 1), is(QuadEquation.SolutionType.REAL));
    }
    @Test
    public void getSolutionに1_マイナス3_1を与えるとREALを返す()
    {
        assertThat(quadEquation.getSolution(1, -3, 1), is(QuadEquation.SolutionType.REAL));
    }
    @Test
    public void getSolutionに1_1_2を与えるとCOMPLEXを返す()
    {
        assertThat(quadEquation.getSolution(1, 1, 2), is(QuadEquation.SolutionType.COMPLEX));
    }
    @Test
    public void getSolutionに1_2_1を与えるとDOUBLEを返す()
    {
        assertThat(quadEquation.getSolution(1, 2, 1), is(QuadEquation.SolutionType.DOUBLE));
    }
    @Test
    public void getSolutionに1_1_0を与えるとREALを返す()
    {
        assertThat(quadEquation.getSolution(1, 1, 0), is(QuadEquation.SolutionType.REAL));
    }
    @Test
    public void getSolutionに0_1_1を与えるとLINEARを返す()
    {
        assertThat(quadEquation.getSolution(0, 1, 1), is(QuadEquation.SolutionType.LINEAR));
    }
    @Test
    public void getSolutionに0_0_1を与えるとNONEを返す()
    {
        assertThat(quadEquation.getSolution(0, 0, 1), is(QuadEquation.SolutionType.NONE));
    }
    @Test
    public void getSolutionに0_0_0を与えるとINDEFを返す()
    {
        assertThat(quadEquation.getSolution(0, 0, 0), is(QuadEquation.SolutionType.INDEF));
    }
}

