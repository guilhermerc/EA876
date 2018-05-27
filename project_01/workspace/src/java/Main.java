import java.util.Objects;
import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		String[] saida = new String[4];

		Scanner stdin = new Scanner(System.in);

		String leitura = "";
		String leitura_atual = "";
		boolean achou = false;
		boolean achou_pai = false;
		int indice_pai = -1;
		int indice = -1;

		while(stdin.hasNext())
		{
			int numero = stdin.nextInt(); stdin.nextLine();
			switch(numero)
			{
				case 0:
					{
						leitura = "";
						leitura_atual = "";
						while(true)
						{
							leitura_atual = stdin.nextLine();
							if(!Objects.equals(leitura_atual, "0!"))
								leitura += leitura_atual;
							else
								break;
						}
						// se não achou um pai na última
						// execução
						if(!achou_pai)
						{
							indice = Tags.procuraString(leitura, Tags.tags_padrao);
							if(indice != -1)	
								achou = true;
							else
							{
								indice = Tags.procuraString(leitura, Tags.tags_encad_pai);
								if(indice != -1)
								{
									achou_pai = true;
									indice_pai = indice;
								}
							}
						}
						// se achou um pai na última
						// execução
						else
						{
							indice = Tags.procuraString(leitura, Tags.tags_encad_filho);
							if(indice != -1)
							{
								indice = indice_pai; 
								achou_pai = false;
								achou = true;
							}
								
						}
						break;
					}
				case 1:
					{
						leitura = "";
						leitura_atual = "";
						while(true)
						{
							leitura_atual = stdin.nextLine();
							if(!Objects.equals(leitura_atual, "1!"))
								leitura += leitura_atual;
							else
								break;
						}
						if(achou == true)
							saida[indice] = leitura;
						achou = false;
						break;
					}
				default:	
			}
		}

		for(int i = 0; i < saida.length; i++)
		{
			System.out.print(saida[i]);
			if(i != saida.length - 1)
				System.out.print("-");

		}
		System.out.print("\n");
	}	
}
