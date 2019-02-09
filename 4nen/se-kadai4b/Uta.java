
public class Uta {
	public static enum UtaAuthorType {
		BOUZU, TONO, HIME,
	}

	private int id;
	private String kami;
	private String simo;
	private String kamiYomi;
	private String simoYomi;
	private String author;
	private String authorYomi;
	private UtaAuthorType authorType;

	Uta(int id, String kami, String simo, String kamiYomi, String simoYomi, String author, String authorYomi,
			UtaAuthorType authorType) {
		this.id = id;
		this.kami = kami;
		this.simo = simo;
		this.kamiYomi = kamiYomi;
		this.simoYomi = simoYomi;
		this.author = author;
		this.authorYomi = authorYomi;
		this.authorType = authorType;
	}

	public int getId() {
		return id;
	}

	public String getKami() {
		return kami;
	}

	public String getSimo() {
		return simo;
	}

	public String getKamiYomi() {
		return kamiYomi;
	}

	public String getSimoYomi() {
		return simoYomi;
	}

	public String getAuthor() {
		return author;
	}

	public String getAuthorYomi() {
		return authorYomi;
	}

	public UtaAuthorType getAuthorType() {
		return authorType;
	}

	@Override
	public String toString() {
		return "[" + id + "] " + kami + " " + simo + ", " + author;
	}
}
