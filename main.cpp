#include <iostream>
#include <locale.h>
#include <bitset>
#include <thread>
#include <chrono>

//Pendências próximas:
// Função para gerar número aleatório
// Função para escalar a intensidade da calha vibratória (alimenta função de geração de número aleatório)
// Função para selecionar pesagem a ser descarregada ou série de pesagens a ser descarregada
// Função para reabastecer caçapa descarregada através de número aleatório
// Estruturar menus de parametrização e operação da balança
// Menus para estatística da balança
// Função para Registro de pesagens realizadas em arquivo (futuramente: banco de dados)
// Função para Registro de parâmetros salvos em arquivo para utilização futura
// Organizar declarações e implementações de funções em arquivo separado


void leArrayPesos(double pesos_cacapas[], double* max_peso, double* min_peso, double* soma_pesos);


int main()
{
	setlocale(LC_ALL, "portuguese");

	//Array que simula um instante com os pesos de cada caçapa para serem selecionados.
	double Pesos[14]{ 174.6, 460.9, 57.2, 200.4, 227.2, 172.7, 228.0, 87.4, 232.8, 318.3, 316.3, 232.3, 146.0, 63.0 };


	auto begin = std::chrono::high_resolution_clock::now();
	//Valor máximo e mínimo de pesagem
	double soma = 0, max = 730, min = 690;

	leArrayPesos(Pesos, &max, &min, &soma);

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
	return 0;
}
void leArrayPesos(double pesos_cacapas[], double* max_peso, double* min_peso, double* soma_pesos)
/*
 Função que tem a finalidade de computar as combinações de caçapas. 
 Através de uma varredura, esta função realiza a comparação entre 14 
 máscaras de bits, através de uma opeeração "OR", e a após cada comparação, 
 move a máscara de bits de modo que todas as combinações possíveis são realizadas. 
 A varredura no array de pesos se dá primeiramente com todas as 
 combinações de duas a duas caçapas, então três a três, e assim 
 sucessivamente até que todas as combinções de caçapas são verificadas. 
*/
{

	const int size = 14;
	int somaNr = 0;

	int xa = 2, xb = 1, xc = 0, xd = 0;
	std::bitset<size> comb1(xa);
	std::bitset<size> comb2(xb);
	std::bitset<size> comb3(xc);
	std::bitset<size> comb4(xd);
	std::bitset<size> comb5(xc);
	std::bitset<size> comb6(xd);
	std::bitset<size> comb7(xc);
	std::bitset<size> comb8(xd);
	std::bitset<size> comb9(xc);
	std::bitset<size> comb10(xd);
	std::bitset<size> comb11(xc);
	std::bitset<size> comb12(xd);
	std::bitset<size> comb13(xc);
	std::bitset<size> comb14(xd);
	std::bitset<size> moving(xd);

	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
	int x = 13;
	int linha = 0;
	
	for (m = 0; m < x - n; m++)
	{
		for (l = 0; l < x - m - n; l++)
		{
			for (k = 0; k < x - l - m - n; k++)
			{
				for (j = 0; j < x - k - l - m - n; j++)
				{
					for (i = 0; i < x - j - k - l - m - n; i++)
					{
						for (h = 0; h < x - i - j - k - l - m - n; h++)
						{
							for (g = 0; g < x - h - i - j - k - l - m - n; g++)
							{
								for (f = 0; f < x - g - h - i - j - k - l - m - n; f++)
								{
									for (e = 0; e < x - e - f - g - h - i - j - k - l - m - n; e++)
									{
										for (d = 0; d < x - e - f - g - h - i - j - k - l - m - n; d++)
										{
											for (c = 0; c < (x - d - e - f - g - h - i - j - k - l - m - n); c++)
											{
												for (b = 0; b < (x - c - d - e - f - g - h - i - j - k - l - m - n); b++)
												{
													for (a = 0; a < (x - b - c - d - e - f - g - h - i - j - k - l - m - n); a++)
													{
														//Soma as máscaras de bits para formar um bitset único, e filtrar o array de pesos
														moving = (comb1 | comb2 | comb3 | comb4 | comb5 | comb6 | comb7 | comb8 | comb9 | comb10 | comb11 | comb12 | comb13);
														linha++;
														for (int z = 0; z < 14; z++)
														{
															//Checa se um bit está 1 na máscara, e busca o valor na posição equivalente do array de pesos
															if (moving[z] == 1)
															{
																//Soma o peso da posição do array com o peso da próxima posição testada
																*soma_pesos += pesos_cacapas[z];

															}

														}
														//Checa se o valor de soma atende os critérios de peso máximo e mínimo
														if (*soma_pesos <= *max_peso && *soma_pesos >= *min_peso)
														{
															somaNr++;
															std::cout << "Soma Nro.: " << somaNr << " - Linha: " << linha << " - Bitset: " << moving << " - Soma:" << *soma_pesos << "\n";
														}
														comb1 <<= 1;
														*soma_pesos = 0;
														//std::this_thread::sleep_for(std::chrono::milliseconds(70));
													}

													comb2 <<= 1;
													comb1 = comb2 << 1;
														
												}
												comb3 <<= 1;
												comb2 = comb3 << 1;
												comb1 = comb2 << 1;

												if (comb3 == 0)
												{
													comb3 = 1;
													comb2 = comb3 << 1;
													comb1 = comb2 << 1;
												}

													
											}
											comb4 <<= 1;
											comb3 = comb4 << 1;
											comb2 = comb3 << 1;
											comb1 = comb2 << 1;

											if (comb4 == 0)
											{
												comb4 = 1;
												comb3 = comb4 << 1;
												comb2 = comb3 << 1;
												comb1 = comb2 << 1;
											}
											if (comb5 == 0) x = 12;
												
										}
										comb5 <<= 1;
										comb4 = comb5 << 1;
										comb3 = comb4 << 1;
										comb2 = comb3 << 1;
										comb1 = comb2 << 1;

										if (comb5 == 0)
										{
											comb5 = 1;
											comb4 = comb5 << 1;
											comb3 = comb4 << 1;
											comb2 = comb3 << 1;
											comb1 = comb2 << 1;
										}
										if (comb6 == 0) x = 11;
											
									}
									comb6 <<= 1;
									comb5 = comb6 << 1;
									comb4 = comb5 << 1;
									comb3 = comb4 << 1;
									comb2 = comb3 << 1;
									comb1 = comb2 << 1;

									if (comb6 == 0)
									{
										comb6 = 1;
										comb5 = comb6 << 1;
										comb4 = comb5 << 1;
										comb3 = comb4 << 1;
										comb2 = comb3 << 1;
										comb1 = comb2 << 1;
									}
									if (comb7 == 0) x = 10;
										
								}
								comb7 <<= 1;
								comb6 = comb7 << 1;
								comb5 = comb6 << 1;
								comb4 = comb5 << 1;
								comb3 = comb4 << 1;
								comb2 = comb3 << 1;
								comb1 = comb2 << 1;

								if (comb7 == 0)
								{
									comb7 = 1;
									comb6 = comb7 << 1;
									comb5 = comb6 << 1;
									comb4 = comb5 << 1;
									comb3 = comb4 << 1;
									comb2 = comb3 << 1;
									comb1 = comb2 << 1;
								}
								if (comb8 == 0) x = 9;
									
							}
							comb8 <<= 1;
							comb7 = comb8 << 1;
							comb6 = comb7 << 1;
							comb5 = comb6 << 1;
							comb4 = comb5 << 1;
							comb3 = comb4 << 1;
							comb2 = comb3 << 1;
							comb1 = comb2 << 1;

							if (comb8 == 0)
							{
								comb8 = 1;
								comb7 = comb8 << 1;
								comb6 = comb7 << 1;
								comb5 = comb6 << 1;
								comb4 = comb5 << 1;
								comb3 = comb4 << 1;
								comb2 = comb3 << 1;
								comb1 = comb2 << 1;
							}
							if (comb9 == 0) x = 8;
							
						}
						comb9 <<= 1;
						comb8 = comb9 << 1;
						comb7 = comb8 << 1;
						comb6 = comb7 << 1;
						comb5 = comb6 << 1;
						comb4 = comb5 << 1;
						comb3 = comb4 << 1;
						comb2 = comb3 << 1;
						comb1 = comb2 << 1;

						if (comb9 == 0)
						{
							comb9 = 1;
							comb8 = comb9 << 1;
							comb7 = comb8 << 1;
							comb6 = comb7 << 1;
							comb5 = comb6 << 1;
							comb4 = comb5 << 1;
							comb3 = comb4 << 1;
							comb2 = comb3 << 1;
							comb1 = comb2 << 1;
						}
						if (comb10 == 0)x = 7;
							
					}
					comb10 <<= 1;
					comb9 = comb10 << 1;
					comb8 = comb9 << 1;
					comb7 = comb8 << 1;
					comb6 = comb7 << 1;
					comb5 = comb6 << 1;
					comb4 = comb5 << 1;
					comb3 = comb4 << 1;
					comb2 = comb3 << 1;
					comb1 = comb2 << 1;

					if (comb10 == 0)
					{
						comb10 = 1;
						comb9 = comb10 << 1;
						comb8 = comb9 << 1;
						comb7 = comb8 << 1;
						comb6 = comb7 << 1;
						comb5 = comb6 << 1;
						comb4 = comb5 << 1;
						comb3 = comb4 << 1;
						comb2 = comb3 << 1;
						comb1 = comb2 << 1;
					}
					if (comb11 == 0)x = 6;
						
				}
				comb11 <<= 1;
				comb10 = comb11 << 1;
				comb9 = comb10 << 1;
				comb8 = comb9 << 1;
				comb7 = comb8 << 1;
				comb6 = comb7 << 1;
				comb5 = comb6 << 1;
				comb4 = comb5 << 1;
				comb3 = comb4 << 1;
				comb2 = comb3 << 1;
				comb1 = comb2 << 1;

				if (comb11 == 0)
				{
					comb11 = 1;
					comb10 = comb11 << 1;
					comb9 = comb10 << 1;
					comb8 = comb9 << 1;
					comb7 = comb8 << 1;
					comb6 = comb7 << 1;
					comb5 = comb6 << 1;
					comb4 = comb5 << 1;
					comb3 = comb4 << 1;
					comb2 = comb3 << 1;
					comb1 = comb2 << 1;
				}
				if (comb12 == 0)x = 5;
					
			}
			comb12 <<= 1;
			comb11 = comb12 << 1;
			comb10 = comb11 << 1;
			comb9 = comb10 << 1;
			comb8 = comb9 << 1;
			comb7 = comb8 << 1;
			comb6 = comb7 << 1;
			comb5 = comb6 << 1;
			comb4 = comb5 << 1;
			comb3 = comb4 << 1;
			comb2 = comb3 << 1;
			comb1 = comb2 << 1;

			if (comb12 == 0)
			{
				comb12 = 1;
				comb11 = comb12 << 1;
				comb10 = comb11 << 1;
				comb9 = comb10 << 1;
				comb8 = comb9 << 1;
				comb7 = comb8 << 1;
				comb6 = comb7 << 1;
				comb5 = comb6 << 1;
				comb4 = comb5 << 1;
				comb3 = comb4 << 1;
				comb2 = comb3 << 1;
				comb1 = comb2 << 1;
			}
			if (comb13 == 0)x = 4;
				
		}
		comb13 <<= 1;
		comb12 = comb13 << 1;
		comb11 = comb12 << 1;
		comb10 = comb11 << 1;
		comb9 = comb10 << 1;
		comb8 = comb9 << 1;
		comb7 = comb8 << 1;
		comb6 = comb7 << 1;
		comb5 = comb6 << 1;
		comb4 = comb5 << 1;
		comb3 = comb4 << 1;
		comb2 = comb3 << 1;
		comb1 = comb2 << 1;
		if (comb13 == 0)
		{
			comb13 = 1;
			comb12 = comb13 << 1;
			comb11 = comb12 << 1;
			comb10 = comb11 << 1;
			comb9 = comb10 << 1;
			comb8 = comb9 << 1;
			comb7 = comb8 << 1;
			comb6 = comb7 << 1;
			comb5 = comb6 << 1;
			comb4 = comb5 << 1;
			comb3 = comb4 << 1;
			comb2 = comb3 << 1;
			comb1 = comb2 << 1;
		}
		x = 3;

	}
	
}
