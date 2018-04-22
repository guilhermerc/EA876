import java.util.Scanner;
import java.util.Stack;

public class Main
{
	public static void main(String[] args)
	{
		String[] saida = new String[4];

		Stack pilha = new Stack();
		Scanner stdin = new Scanner(System.in);

		String leitura = "";
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
						leitura = stdin.nextLine();
						pilha.push(leitura);
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
						leitura = stdin.nextLine();
						if(achou == true)
							saida[indice] = leitura;
						achou = false;
						break;
					}
				case 2:
					{
						pilha.pop();
					}
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
