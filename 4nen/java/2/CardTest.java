class CardTest
{
    public static void main(String[] args)
    {
        Card cards[] =
        {
            new Card(Card.TYPE_WATER, 5),
            new Card(Card.TYPE_FIRE, 8),
            new Card(Card.TYPE_GRASS, 2),
            new Card()
        };

        for(Card card1 : cards)
        {
            for(Card card2 : cards)
            {
                judge(card1, card2);
                System.out.println();
            }
        }
    }

    private static void judge(Card c1, Card c2)
    {
        System.out.println(c1 + " vs " + c2);
        if(c1.isSameAs(c2))
            System.out.println("引き分け");
        else if(c1.isStrongerThan(c2))
            System.out.println(c1 + "の勝ち");
        else
            System.out.println(c2 + "の勝ち");
    }
}
