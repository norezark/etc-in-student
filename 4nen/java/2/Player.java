import java.util.*;

class Player
{
    public static final int CARD_MAX = 3;
    private ArrayList<Card> cards;
    private int point = 0;

    Player()
    {
        cards = new ArrayList<Card>(CARD_MAX);
        for(int i=0; i<CARD_MAX; i++)
        {
            cards.add(new Card());
        }
    }

    void showCards()
    {
        for(int i=0; i<cards.size(); i++)
        {
            System.out.println("No." + (i+1) + ":" + cards.get(i));
        }
    }

    int addPoint(int p)
    {
        point += p;
        return point;
    }

    int getPoint()
    {
        return point;
    }

    Card putCard()
    {
        if(cards.size() == 0) return null;

        Random random = new Random();
        int index = random.nextInt(cards.size())+1;
        return putCard(index);
    }

    Card putCard(int index)
    {
        index--;
        if(index < 0 || index >= cards.size())
        {
            return null;
        }
        return cards.remove(index);
    }
}
