import java.util.ArrayList;

public class Tags 
{
	public ArrayList<String> tags;

	public Tags()
	{
		this.tags = new ArrayList<String>();
	}

	public String toString()
	{
		String saida = "Saida:\n";
		for(int i = 0; i < this.tags.size(); i++)
			saida += tags.get(i) + "\n";
		return saida;
	}
}
