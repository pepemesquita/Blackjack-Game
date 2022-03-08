#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "locale.h"
#include "time.h"
#include "lib.h"

int somaJogador = 0;

celula *cria(void)
{
	celula *start;
	start = (celula *)malloc(sizeof(celula));
	start->prox = NULL;
	return start;
}

void insere(int x, celula *p)
{
	celula *nova;

	nova = (celula *)malloc(sizeof(celula));
	nova->conteudo = x;
	nova->prox = p->prox;
	p->prox = nova;
}

void imprime(celula *ini)
{
	celula *p;
	for (p = ini->prox; p != NULL; p = p->prox)
		printf("%d\n", p->conteudo);
}

void menu(void)
{
	printf("\n");
	printf("1 - Comecar a jogar\n");
	printf("2 - Regras do jogo\n");
	printf("3 - Exibir pontos (RAM)\n");
	printf("4 - Exibir pontos (SSD ou HD)\n");
	printf("5 - Gravar da RAM para o HD/SSD\n");
	printf("6 - Zerar pontuação no HD/SSD\n");
	printf("7 - Zerar pontuação na RAM\n");
	printf("8 - Sair do jogo\n");
	printf("\nDigite: ");
}

void zerarSSD(void)
{
	FILE *arquivo;
	arquivo = fopen("score.txt", "w");
	fprintf(arquivo, "");
	fclose(arquivo);
}

void gravar(celula *ini)
{
	FILE *arquivo;
	arquivo = fopen("score.txt", "a");
	celula *p;
	for (p = ini->prox; p != NULL; p = p->prox)
	{
		fprintf(arquivo, "%d\n", p->conteudo);
	}
	fclose(arquivo);
}

void score(void)
{
	FILE *arquivo;
	arquivo = fopen("score.txt", "r");
	char c;
	c = fgetc(arquivo);
	while (!feof(arquivo))
	{
		putchar(c);
		c = fgetc(arquivo);
	}
	fclose(arquivo);
}

void ajuda(void)
{
	FILE *arquivo;
	arquivo = fopen("help.txt", "r");
	char c;
	c = fgetc(arquivo);
	while (!feof(arquivo))
	{
		putchar(c);
		c = fgetc(arquivo);
	}
	fclose(arquivo);
}

void misturar(int cartas[])
{
	int t;
	int i;
	int baralho[52];
	for (i = 0; i < 52; i++)
		baralho[i] = (i / 13 + 3) * 100 + i % 13 + 1;
	srand(time(NULL));
	for (i = 0; i < 52; i++)
	{
		do
		{
			t = rand() % 52;
		} while (baralho[t] == 0);
		cartas[i] = baralho[t];
		baralho[t] = 0;
	}
}

void draw(int num)
{
	char fl;
	int po_num, naipe;
	fl = num / 100;
	po_num = num % 100;

  naipe=fl;
  if (naipe == 3) { naipe = 'O'; }
  if (naipe == 4) { naipe = 'C'; }
  if (naipe == 5) { naipe = 'P'; }
  if (naipe == 6) { naipe = 'E'; }

	switch (po_num)
	{
	case 1:
		printf("*******\n");
		printf("*     *\n");
		printf("*%c    *\n", naipe);
		printf("*   A *\n");
		printf("*     *\n");
		printf("*******\n");
		break;
	case 10:
		printf("*******\n");
		printf("*     *\n");
		printf("*%c    *\n", naipe); 
		printf("*  %2d *\n", po_num);
		printf("*     *\n");
		printf("*******\n");
		break;
		break;
	case 11:
		printf("*******\n");
		printf("*     *\n");
		printf("*%c    *\n", naipe);
		printf("*   J *\n");
		printf("*     *\n");
		printf("*******\n");
		break;

	case 12:
		printf("*******\n");
		printf("*     *\n");
		printf("*%c    *\n", naipe);
		printf("*   Q *\n");
		printf("*     *\n");
		printf("*******\n");
		break;
	case 13:
		printf("*******\n");
		printf("*     *\n");
		printf("*%c    *\n", naipe);
		printf("*   K *\n");
		printf("*     *\n");
		printf("*******\n");
		break;
	default:
		printf("*******\n");
		printf("*     *\n");
		printf("*%c    *\n", naipe);
		printf("*  %2d *\n", po_num);
		printf("*     *\n");
		printf("*******\n");
		break;
	}
}

int play(void)
{
	somaJogador = 0;
	int i, somaCasa = 0, cartasJogador[5] = {0}, cartasCasa[5] = {0}, cartas[52];
	float auxSoma1 = 0, auxSoma2 = 0;
	char go_on, d;
	do
	{
		go_on = getchar();
	} while (go_on != '\n');
	printf("\n");
	misturar(cartas);
	cartasJogador[0] = cartas[0];
	cartasJogador[1] = cartas[1];
	cartasCasa[0] = cartas[2];
	cartasCasa[1] = cartas[3];
	printf("Uma das cartas da casa:\n");
	draw(cartasCasa[0]);
	printf("\n");
	draw(cartasJogador[0]);
	printf("\n");
	draw(cartasJogador[1]);
	printf("\n");
	i = 0;
	for (i = 0; i < 2; i++)
	{
		if (cartasJogador[i] % 100 == 1)
		{
			printf("Escolha o valor da carta As %d, digite 's' para 11 ou 'n' para 1 :\n", i + 1);
			do
			{
				d = getchar();
			} while (d != 's' && d != 'n');
			if (d == 's')
			{
				printf("Voce escolheu o valor 11 para a carta As.\n");
				somaJogador = somaJogador + 11;
			}
			else
			{
				if (d == 'n')
				{
					printf("Voce escolheu o valor 1 para a carta As.\n");
					somaJogador = somaJogador + 1;
				}
			}
		}
		else
		{
			if (ReiRainhaValete(cartasJogador[i]) % 100 == 10)
			{
				somaJogador = somaJogador + 11;
			}
			else
			{
				somaJogador = somaJogador + cartasJogador[i] % 100;
			}
		}
		if (somaJogador > 21)
		{
			printf("Soma das cartas do jogador no momento:%d\n\n", somaJogador);
			printf("Computador venceu!\n\n");
			return 1;
		}
		else
		{
			if (somaJogador == 21)
			{
				printf("Soma das cartas do jogador no momento:%d\n\n", somaJogador);
				printf("Voce venceu!\n\n");
				return 0;
			}
		}
	}
	printf("Soma das cartas do jogador agora:%d\n\n", somaJogador);
	i = 0;
	for (i = 0; i < 3; i++)
	{
		char j = 'n';
		printf("Quer mais cartas? S/N\n");
		printf("Digite: ");
		do
		{
			j = getchar();
		} while (j != 's' && j != 'n');
		if (j == 's' || j == 'S')
		{
			printf("Voce tem outra carta agora\n");
			cartasJogador[i + 2] = cartas[i + 4];
			printf("e sua carta %d e:\n", i + 3);
			draw(cartasJogador[i + 2]);
			if (cartasJogador[i + 2] % 100 == 1)
			{
				printf("Escolha o valor da carta As %d, tecle 's' para 11 ou 'n' para 1:\n", i + 3);
				do
				{
					d = getchar();
				} while (d != 's' && d != 'n');
				if (d == 's')
				{
					printf("Voce escolheu o valor 11 para a carta As.\n\n");
					somaJogador = somaJogador + 11;
				}
				else
				{
					if (d == 'n')
					{
						printf("Voce escolheu o valor 1 para a carta As.\n\n");
						somaJogador = somaJogador + 1;
					}
				}
			}
			else
			{
				if (ReiRainhaValete(cartasJogador[i + 2]) % 100 == 10)
				{
					somaJogador = somaJogador + 10;
				}
				else
				{
					somaJogador = somaJogador + cartasJogador[i + 2] % 100;
				}
			}
			if (somaJogador > 21)
			{
				printf("Soma das cartas do jogador no momento:%d\n\n", somaJogador);
				printf("Computador ganhou!\n\n");
				insere(somaJogador, ini);
				return 1;
			}
			else if (somaJogador == 21)
			{
				printf("Soma das cartas do jogador no momento:%d\n\n", somaJogador);
				printf("Voce ganhou!\n\n");
				insere(somaJogador, ini);
				return 0;
			}
			else
				printf("Soma das cartas do jogador no momento:%d\n\n", somaJogador);
		}
		else
		{
			printf("Soma das cartas do jogador no momento:%d\n\n", somaJogador);
			break;
		}
	}
	if (i == 3)
	{
		printf("Voce ganhou! Porque a soma das suas 5 cartas nao e maior que 21!\n\n");
		insere(somaJogador, ini);
		return 0;
	}
	printf("Cartas do computador:\n");
	draw(cartasCasa[0]);
	draw(cartasCasa[1]);
	if (cartasCasa[0] % 100 + cartasCasa[1] % 100 == 2)
	{
		somaCasa = 12; // Duas cartas Às
		printf("Soma das cartas do computador no momento:%d\n\n", somaCasa);
	}
	else
	{
		auxSoma1 = ReiRainhaValete(cartasCasa[0]) % 100;
		auxSoma2 = ReiRainhaValete(cartasCasa[1]) % 100;
		if (auxSoma1 + auxSoma2 == 1.00)
		{
			auxSoma1 = (float)0;
			auxSoma2 = (float)0;
			somaCasa = 21;
			printf("Soma das cartas do computador agora:%d\n\n", somaCasa);
			printf("Computador ganhou!\n\n");
			insere(somaJogador, ini);
			return 1;
		}
		else
		{
			if (cartasCasa[0] % 100 == 1 || cartasCasa[1] % 100 == 1)
			{
				somaCasa = (cartasCasa[0] + cartasCasa[1]) % 100 + (rand() % 2) * 10;
				printf("Soma das cartas do computador no momento:%d\n\n", somaCasa);
			}
			else
			{
				somaCasa = (ReiRainhaValete(cartasCasa[0])) % 100 + (ReiRainhaValete(cartasCasa[1])) % 100;
				printf("Soma das cartas do computador no momento:%d\n\n", somaCasa);
			}
		}
	}
	// se a casa recebe mais cartas até somaCasa>16
	for (i = 0; i < 3 && somaCasa < 17; i++)
	{
		cartasCasa[i + 2] = cartas[i + 7];
		printf("A carta do computador %d e:\n", i + 3);
		draw(cartasCasa[i + 2]);
		if (cartasCasa[i + 2] % 100 == 1)
		{
			if (somaCasa + 11 <= 21)
			{
				printf("O computador escolheu a carta As como 11\n\n");
				somaCasa = somaCasa + 11;
				printf("Soma das cartas do computador no momento:%d\n\n", somaCasa);
			}
			else
			{
				printf("O computador escolheu a carta As como 1\n");
				somaCasa = somaCasa + 1;
				printf("Soma das cartas do computador no momento:%d\n\n", somaCasa);
			}
		}
		else
		{
			somaCasa = somaCasa + ReiRainhaValete(cartasCasa[i + 2]) % 100;
			printf("Soma das cartas do computador no momento:%d\n\n", somaCasa);
		}
	}
	if (i == 3)
	{
		printf("Vitoria do computador! Porque a soma de suas 5 cartas não é maior que 21!\n\n");
		insere(somaJogador, ini);
		return 1;
	}
	// reta final
	if (somaCasa > 21 || somaJogador > somaCasa)
	{
		printf("Voce ganhou!\n\n");
		insere(somaJogador, ini);
		return 0;
	}
	else
	{
		if (somaJogador == somaCasa)
		{
			printf("Que legal! Voce e o computador pontuaram igualmente!\n\n");
			insere(somaJogador, ini);
			return 3;
		}
		else
		{
			if (somaJogador < somaCasa)
			{
				printf("Computador ganhou!\n\n");
				insere(somaJogador, ini);
				return 1;
			}
		}
	}
	return 3;
}

int ReiRainhaValete(int a)
{
	if ((a % 100 == 11) || (a % 100 == 12) || (a % 100 == 13))
	{
		return (a / 100) * 100 + 10;
	}
	else
	{
		return a;
	}
}