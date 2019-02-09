import java.util.InputMismatchException;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class SimonokuateQuizController {
	public static final int CHOICE_DEFAULT_LENGTH = 3;
	public static final int CHOICE_HARD_LENGTH = 10;

	private UtaList utaList;
	private int choiceLength;

	SimonokuateQuizController(UtaList utaList) {
		this.utaList = utaList;
		setChoiceLength(CHOICE_DEFAULT_LENGTH);
	}

	SimonokuateQuizController(UtaList utaList, int choiceLength) {
		this(utaList);
		setChoiceLength(choiceLength);
	}

	public void setChoiceLength(int choiceLength) {
		if (choiceLength < 2 || utaList.getSize() < choiceLength) return;

		this.choiceLength = choiceLength;
	}

	public void play() {
		Scanner input = new Scanner(System.in);

		System.out.print("出題回数は？: ");
		int countQuiz;
		while (true) {
			try {
				countQuiz = input.nextInt();
				if (1 <= countQuiz && countQuiz < utaList.getSize()) break;
				System.out.println("範囲外の数値です");
			} catch (InputMismatchException e) {
				System.out.println("整数値を入力してください");
			}
		}
		int correctCount = play(countQuiz, false);
		if(correctCount < 0) return;

		System.out.println("" + countQuiz + "問中" + correctCount + "問正解でした。");
		System.out.println("正答率は" + (int) (correctCount * 100.0 / countQuiz) + "%でした。");
	}

	public void playHard() {
		int tmp = choiceLength;
		setChoiceLength(CHOICE_HARD_LENGTH);
		play(utaList.getSize(), true);
		choiceLength = tmp;
	}

	private int play(int countQuiz, boolean doRemoveOnCorrect) {
		if(utaList.getSize() < choiceLength) {
			System.out.println("歌の数が少なすぎます");
			return -1;
		}

		Scanner input = new Scanner(System.in);
		Random random = new Random();

		List<Uta> answerList = utaList.exportRandomUta(countQuiz);
		int correctCount = 0;
		int i = 1;
		for (Uta answer : answerList) {
			System.out.println("第" + (i++) + "問");
			System.out.println(answer.getKami() + "...");
			List<Uta> sourceChoice = utaList.exportRandomUta(choiceLength);
			int answerIndex = sourceChoice.indexOf(answer);
			if (answerIndex == -1) {
				answerIndex = random.nextInt(choiceLength);
				sourceChoice.remove(0);
				sourceChoice.add(answerIndex, answer);
			}

			int j = 1;
			for (Uta choice : sourceChoice) {
				System.out.println("[" + (j++) + "] " + choice.getSimo());
			}

			System.out.print("答えは？: ");
			int inputAnswer;
			while (true) {
				try {
					inputAnswer = input.nextInt();
					if (1 <= inputAnswer && inputAnswer <= choiceLength) break;
					System.out.println("範囲外の数値です");
				} catch (InputMismatchException e) {
					System.out.println("整数値を入力してください");
					while(input.hasNext()) input.next();
				}
			}

			if (inputAnswer == answerIndex) {
				System.out.println("正解！");
				correctCount++;
				if(doRemoveOnCorrect) answerList.remove(answer);
			} else {
				System.out.println("不正解");
			}
		}

		return correctCount;
	}
}
