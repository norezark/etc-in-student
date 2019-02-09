class TripleTest
{
    public static void main(String[] args)
    {
        Triple t1 = new Triple();
        t1.set(5, 8, 5);
        t1.show();
        System.out.println("最大値: " + t1.max());

        Triple t2 = new Triple();
        t2.set(1, 1, 1);
        t1.add(t2);
        t1.show();

        System.out.println("t1.max() : " + t1.max());
        System.out.println("t1.hasPair() : " + t1.hasPair());
        System.out.println("t2.isAllSame() : " + t2.isAllSame());
    }
}
