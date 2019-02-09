import java.util.*;

class CardGame
{
    private static Player player;
    private static Player computer;

    public static void main(String args[])
    {
        player = new Player();
        computer = new Player();

        System.out.println("<<< カードゲーム >>>");
        for(int i=1; i<=Player.CARD_MAX; i++)
        {
            turn(i == Player.CARD_MAX);
        }

        if(player.getPoint() > computer.getPoint())
            System.out.println("Playerの勝利! Congratulations!");
        else if(player.getPoint() < computer.getPoint())
            System.out.println("Computerの勝利");
        else
            System.out.println("引き分け");
    }

    private static void turn(boolean isLastTurn)
    {
        System.out.println("Player:");
        player.showCards();
        System.out.println("Computer:");
        computer.showCards();

        Card playerCard, computerCard = computer.putCard();
        if(isLastTurn)
        {
            System.out.println("最後のカードを使います.");
            playerCard = player.putCard();
            System.out.println("Player:     " + playerCard);
            System.out.println("Computer:   " + computerCard);
        }
        else
        {
            Scanner input = new Scanner(System.in);
            while(true)
            {
                System.out.println("どのカードを使いますか？: ");
                playerCard = player.putCard(input.nextInt());

                if(playerCard != null) break;

                System.out.println("そのカードを使うことはできません.");
            }
            System.out.println("Player:     " + playerCard);
            System.out.println("Computerは" + computerCard + "を選択しました．");
        }


        if(playerCard.isSameAs(computerCard))
        {
            System.out.println("引き分け");
        }
        else if(playerCard.isStrongerThan(computerCard))
        {
            player.addPoint(1);
            System.out.println("Playerの" + playerCard + "の勝ち!");
        }
        else
        {
            computer.addPoint(1);
            System.out.println("Computerの" + computerCard + "の勝ち!");
        }


        System.out.println("--------------------");
        System.out.println("Player:     " + player.getPoint());
        System.out.println("Computer:   " + computer.getPoint());
        System.out.println("--------------------");
    }
}
