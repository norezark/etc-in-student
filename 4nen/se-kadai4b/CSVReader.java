import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CSVReader {
	private String dataFileName;

	public CSVReader(String dataFileName) {
		this.dataFileName = dataFileName;
	}

	public List<String[]> parseToStrings() throws FileNotFoundException, IOException {
		File file = new File(dataFileName);
		FileReader fileReader = new FileReader(file);
		BufferedReader reader = new BufferedReader(fileReader);
		List<String[]> list = new ArrayList<String[]>();
		String line;
		while ((line = reader.readLine()) != null) {
			list.add(line.split(",", 0));
		}
		reader.close();

		return list;
	}
}
