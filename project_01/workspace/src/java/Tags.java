import java.util.Objects;

public class Tags
{
	public static String[][] tags_padrao =
	{	
		// Assumindo que o gerador é o mesmo que o tomador
		{"TOMADOR_CIDADE", "tsMunTmd"},
		{"PRESTADOR_CIDADE", "tsMunPtd"},
		{"VALOR_SERVICO", "ValorServicos", "ns3:ValorServicos", "tsVlrSvc", "valorTotalServico"},
		{"VALOR_ISS", "ValorIss", "ns3:ValorIss", "tsVlrISSRet", "valorTotalISS"}

	};

	public static String[][] tags_encad_pai =
	{
		{"OrgaoGerador", "ns3:OrgaoGerador", "tomador", "Tomador"},
		{"PrestadorServico", "ns3:PrestadorServico", "prestador"}
	};
	
	public static String[][] tags_encad_filho =
	{
		{"CodigoMunicipio", "ns3:CodigoMunicipio", "descricaoMunicipio"}
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
