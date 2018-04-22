import java.util.Scanner;
import java.util.ArrayList;

public class Main
{
	public static void main(String[] args)
	{
		String[] saida = new String[4];

		Scanner stdin = new Scanner(System.in);

		Tags municipio_gerador = new Tags();
		Tags municipio_prestador = new Tags();
		Tags valor_do_servico = new Tags();
		Tags iss_retido = new Tags();

		municipio_gerador.tags.add("TOMADOR_CIDADE");
		municipio_prestador.tags.add("PRESTADOR_CIDADE");
		valor_do_servico.tags.add("VALOR_SERVICO");
		iss_retido.tags.add("VALOR_ISS");
		
		while(stdin.hasNext())
		{
			String leitura = stdin.nextLine();

			if(municipio_gerador.tags.contains(leitura))
			{
				saida[0] = stdin.nextLine();
			}		
			else if(municipio_prestador.tags.contains(leitura))
			{
				saida[1] = stdin.nextLine();
			}
			else if(valor_do_servico.tags.contains(leitura))
			{
				saida[2] = stdin.nextLine();
			}
			else if(iss_retido.tags.contains(leitura))
			{
				saida[3] = stdin.nextLine();
			}
		}

		for(int i = 0; i < saida.length; i++)
		{
			System.out.print(saida[i]);
			if(i != saida.length - 1)
				System.out.print(", ");

		}
		System.out.print("\n");
	}
}
