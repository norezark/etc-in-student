import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class UtaList {
	private List<Uta> list;

	UtaList() {
		list = new ArrayList<Uta>();
	}

	public void importDataFromList(List<Uta> data) {
		list.addAll(data);
	}

	public void importDataFromCSV(String dataFileName) {
		List<String[]> lineList = null;
		try {
			CSVReader reader = new CSVReader(dataFileName);
			lineList = reader.parseToStrings();
		} catch (FileNotFoundException e) {
			System.out.println("ファイルが存在しません");
			return;
		} catch (IOException e) {
			System.out.println("ファイルのアクセスに失敗しました");
			return;
		}

		for(String[] cell : lineList) {
			if(cell.length != 8) continue;

			list.add(new Uta(Integer.parseInt(cell[0]),
						cell[1], cell[2], cell[3], cell[4], cell[5], cell[6],
						Uta.UtaAuthorType.values()[Integer.parseInt(cell[7])]));
		}
	}

	public void printList() {
		for (Uta uta : list) {
			System.out.println(uta);
		}
	}

	public List<Uta> exportRandomUta(int count) {
		List<Uta> clone = new ArrayList<Uta>(list);
		Collections.shuffle(clone);

		return clone.subList(0, count);
	}

	public int getSize() {
		return list.size();
	}
}
