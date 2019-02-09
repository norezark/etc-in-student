import org.junit.*;
import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;

public class NengoUtilTest
{
    private NengoUtil nengoUtil;

    public static void main(String[] args)
    {
        org.junit.runner.JUnitCore.main(NengoUtilTest.class.getName());
    }
    @Before
    public void setUp()
    {
        nengoUtil = new NengoUtil();
    }
    @Test
    public void getYearFromNengoにS0を与えるとマイナス1を返す()
    {
        assertThat(nengoUtil.getYearFromNengo('S', 0), is(-1));
    }
    @Test
    public void getYearFromNengoにH0を与えるとマイナス1を返す()
    {
        assertThat(nengoUtil.getYearFromNengo('H', 0), is(-1));
    }
    @Test
    public void getYearFromNengoにSマイナス1を与えるとマイナス1を返す()
    {
        assertThat(nengoUtil.getYearFromNengo('S', -1), is(-1));
    }
    @Test
    public void getYearFromNengoにHマイナス1を与えるとマイナス1を返す()
    {
        assertThat(nengoUtil.getYearFromNengo('H', -1), is(-1));
    }
    @Test
    public void getYearFromNengoにS65を与えるとマイナス1を返す()
    {
        assertThat(nengoUtil.getYearFromNengo('S', 65), is(-1));
    }
    @Test
    public void getYearFromNengoにH32を与えるとマイナス1を返す()
    {
        assertThat(nengoUtil.getYearFromNengo('H', 32), is(-1));
    }
    @Test
    public void getYearFromNengoにS1を与えると1926を返す()
    {
        assertThat(nengoUtil.getYearFromNengo('S', 1), is(1926));
    }
    @Test
    public void getYearFromNengoにS32を与えると1957を返す()
    {
        assertThat(nengoUtil.getYearFromNengo('S', 32), is(1957));
    }
    @Test
    public void getYearFromNengoにS64を与えると1989を返す()
    {
        assertThat(nengoUtil.getYearFromNengo('S', 64), is(1989));
    }
    @Test
    public void getYearFromNengoにH1を与えると1989を返す()
    {
        assertThat(nengoUtil.getYearFromNengo('H', 1), is(1989));
    }
    @Test
    public void getYearFromNengoにH16を与えると2004を返す()
    {
        assertThat(nengoUtil.getYearFromNengo('H', 16), is(2004));
    }
    @Test
    public void getYearFromNengoにH31を与えると2019を返す()
    {
        assertThat(nengoUtil.getYearFromNengo('H', 31), is(2019));
    }
}
