import java.util.Objects;

public class Tags
{
	public static String[][] tags_padrao =
	{	
		{"TOMADOR_CIDADE"},
		{"PRESTADOR_CIDADE"},
		{"VALOR_SERVICO", "ValorServicos", "ns3:ValorServicos"},
		{"VALOR_ISS", "ValorIss", "ns3:ValorIss"}

	};

	public static String[][] tags_encad_pai =
	{
		{"OrgaoGerador", "ns3:OrgaoGerador"},
		{"PrestadorServico", "ns3:PrestadorServico"}
	};
	
	public static String[][] tags_encad_filho =
	{
		{"CodigoMunicipio", "ns3:CodigoMunicipio"},
		{"CodigoMunicipio", "ns3:CodigoMunicipio"}
	};

	public static int procuraString(String str, String[][] tags)
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
