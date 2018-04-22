import java.util.Arrays;
import java.util.Objects;

public class Tags
{
	public static String[][] tags =
	{	
		{"TOMADOR_CIDADE"},
		{"PRESTADOR_CIDADE"},
		{"VALOR_SERVICO"},
		{"VALOR_ISS"}
	};

	public static int procuraString(String str)
	{
		int indice = -1;
		boolean encontrou = false;
		for(int i = 0; i < tags.length && !encontrou; i++)
		{
			for(int j = 0; j < tags[i].length && !encontrou; j++)
			{
				if(Objects.equals(tags[i][j], str))
				{
					 indice = i;
					 encontrou = true;
				}
			}
		}
		return indice;
	}
}
