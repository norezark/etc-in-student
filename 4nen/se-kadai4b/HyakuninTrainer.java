import java.util.Scanner;

class HyakuninTrainer {
	public enum HyakuninTrainerMode {
		CHECK(1, "歌の確認"), QUIZ(2, "下の句当てクイズ"), QUIZHARD(3, "下の句当てクイズ（ハードモード）"), EXIT(0, "終了");

		private final int index;
		private final String description;

		private HyakuninTrainerMode(final int index, final String description) {
			this.index = index;
			this.description = description;
		}

		public int getIndex() {
			return this.index;
		}

		public String getDescription() {
			return this.description;
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("百人一首トレーナーへようこそ！");

		UtaList utaList = new UtaList();
		utaList.importDataFromCSV("hyakunin.csv");
		SimonokuateQuizController simonokuateQuizController = new SimonokuateQuizController(utaList);

		boolean doExit = false;
		while (!doExit) {
			for (HyakuninTrainerMode mode : HyakuninTrainerMode.values()) {
				System.out.println("[" + mode + "] " + mode.getDescription());
			}
			System.out.print("どれを実行しますか？ : ");
			String inputMode = input.next().toUpperCase();
			System.out.println(inputMode + "を開始します。");
			try {
				switch (HyakuninTrainerMode.valueOf(inputMode)) {
					case CHECK:
						utaList.printList();
						break;
					case QUIZ:
						simonokuateQuizController.play();
						break;
					case QUIZHARD:
						simonokuateQuizController.playHard();
						break;
					case EXIT:
						doExit = true;
						break;
					default:
						break;
				}
				System.out.println(inputMode + "を終了しました。");
			} catch (IllegalArgumentException e) {
				System.out.println("間違った入力です。");
			}
		}

	}

}
