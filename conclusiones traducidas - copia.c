/*=========================================================================================
===============================================Mariangela&Ángel============================
=====================CONCLUSIONES==========================================================*/

void mostrarConclusionFinal(Character *Equipo1, Character *Equipo2, int turnos, char *escenario) 
{
	int vivosG1 = 0;
	int vivosG2 = 0;

	for (int i = 0; i < 5; i++) 
	{
		if (Equipo1[i].Hp > 0)
		{
			vivosG1++;
		}
		if (Equipo2[i].Hp > 0) 
		{
			vivosG2++;
		}
	}

	if (Lenguaje == 0) 
	{
		printf("\n\n##########################################################\n");
		printf("                 *** REGISTRO DE BATALLA *** \n");
		printf("##########################################################\n");

		printf("\n[DATOS DEL ENCUENTRO EN: %s]\n", escenario);
		printf("- Ciclos de combate: %d\n", turnos);
		printf("- Supervivientes Grupo 1 (HEROES): %d / 5\n", vivosG1);    
		printf("- Supervivientes Grupo 2 (ENEMIGOS): %d / 5\n", vivosG2);  

		if (vivosG1 > 0) 
		{
			printf("\n>>> RESULTADO: VICTORIA ABSOLUTA DEL GRUPO 1 <<<\n");
			
			if (strcmp(escenario, "Reencuentro en la Niebla") == 0 || strcmp(escenario, "Reunion in the Mist") == 0)
			{
				printf("Los Cristalizados fueron destruidos\n");
			} 
			else if (strcmp(escenario, "La Gran Biblioteca") == 0 || strcmp(escenario, "The Grand Library") == 0)
			{
				printf("Los Cazadores Hostiles han sido derrotados\n");
			} 
			else if (strcmp(escenario, "El Epicentro en la Catedral") == 0 || strcmp(escenario, "The Epicenter in the Cathedral") == 0)
			{
				printf("CONCLUSIÓN FINAL: La Bruma Escarlata ha sido derrotada. La niebla se disipa en toda la ciudad.\n");
			}
		} 
		else if (vivosG2 > 0) 
		{
			printf("\n>>> RESULTADO: VICTORIA ABSOLUTA DEL GRUPO 2 <<<\n");

			int faccionGanador = 0;

			if (strcmp(Equipo2[0].Group, "Los Cristalizados") == 0 || strcmp(Equipo2[0].Group, "The Crystallized") == 0)
			{
				faccionGanador = 1;
			}
			else if (strcmp(Equipo2[0].Group, "Cazadores Hostiles") == 0 || strcmp(Equipo2[0].Group, "Hostile Hunters") == 0)
			{
				faccionGanador = 2;
			}
			else if (strcmp(Equipo2[0].Group, "La Bruma Escarlata") == 0 || strcmp(Equipo2[0].Group, "The Scarlet Mist") == 0)
			{
				faccionGanador = 3;
			}
			
			switch (faccionGanador) 
			{ 
				case 1: 
					printf("Los Cristalizados han convertido a sus rivales en estatuas de cuarzo.\n");
					break;
				
				case 2: 
					printf("Los Cazadores Hostiles han ganado el encuentro.\n");
					break;
				
				case 3: 
					printf("DUELO FINAL FALLIDO: La Bruma Escarlata ha devorado las almas de sus oponentes.\n");
					break;

				default:
					printf("Las fuerzas enemigas han prevalecido.\n");
					break;
			}
		} 
		else 
		{
			printf("\n>>> RESULTADO: EMPATE <<<\n");
			printf("En %s no hubo vencedores \n", escenario);
		}

		printf("\n[ESTADO FINAL DE LOS CAMPEONES:]\n");
		printf("%-22s | %-10s | %-10s\n", "PERSONAJE", "HP FINAL", "ESTADO");
		printf("----------------------------------------------------------\n");

		for (int i = 0; i < 5; i++) 
		{
			if (Equipo1[i].Hp > 0)
			{
				printf("%-22s | %10.1f | VIVO\n",Equipo1[i].Name, Equipo1[i].Hp);

			}
			else
			{
               printf("%-22s | %10.1f | CAÍDO\n",Equipo1[i].Name, 0.0);

			}
		}

		printf("------------------------------------------------------------\n");

		for (int i = 0; i < 5; i++) 
		{
			if (Equipo2[i].Hp > 0)
			{
				printf("%-22s | %10.1f | VIVO\n",Equipo2[i].Name, Equipo2[i].Hp);

			}
			else
			{
               printf("%-22s | %10.1f | CAÍDO\n",Equipo2[i].Name, 0.0);

			}
		}

		printf("\n##########################################################\n");
		printf("Simulación finalizada\n");
		printf("Presione una tecla para volver al menu principal...\n");
	}
	else 
	{
		printf("\n\n##########################################################\n");
		printf("                 *** BATTLE RECORD *** \n");
		printf("##########################################################\n");

		printf("\n[ENCOUNTER DATA IN: %s]\n", escenario);
		printf("- Combat cycles: %d\n", turnos);
		printf("- Survivors Group 1 (HEROES): %d / 5\n", vivosG1);    
		printf("- Survivors Group 2 (ENEMIES): %d / 5\n", vivosG2);  

		if (vivosG1 > 0) 
		{
			printf("\n>>> RESULT: ABSOLUTE VICTORY FOR GROUP 1 <<<\n");
			
			if (strcmp(escenario, "Reencuentro en la Niebla") == 0 || strcmp(escenario, "Reunion in the Mist") == 0) 
			{
				printf("The Crystallized were destroyed\n");
			} 
			else if (strcmp(escenario, "La Gran Biblioteca") == 0 || strcmp(escenario, "The Grand Library") == 0) 
			{
				printf("The Hostile Hunters have been defeated\n");
			} 
			else if (strcmp(escenario, "El Epicentro en la Catedral") == 0 || strcmp(escenario, "The Epicenter in the Cathedral") == 0)
			{
				printf("FINAL CONCLUSION: The Scarlet Mist has been defeated. The mist dissipates throughout the city.\n");
			}
		} 
		else if (vivosG2 > 0) 
		{
			printf("\n>>> RESULT: ABSOLUTE VICTORY FOR GROUP 2 <<<\n");

			int faccionGanador = 0;

			if (strcmp(Equipo2[0].Group, "Los Cristalizados") == 0 || strcmp(Equipo2[0].Group, "The Crystallized") == 0)
			{
				faccionGanador = 1;
			}
			else if (strcmp(Equipo2[0].Group, "Cazadores Hostiles") == 0 || strcmp(Equipo2[0].Group, "Hostile Hunters") == 0)
			{
				faccionGanador = 2;
			}
			else if (strcmp(Equipo2[0].Group, "La Bruma Escarlata") == 0 || strcmp(Equipo2[0].Group, "The Scarlet Mist") == 0)
			{
				faccionGanador = 3;
			}
			
			switch (faccionGanador) 
			{ 
				case 1: 
					printf("The Crystallized have turned their rivals into quartz statues.\n");
					break;
				
				case 2: 
					printf("The Hostile Hunters have won the encounter.");
					break;
				
				case 3: 
					printf("FAILED FINAL DUEL: The Scarlet Mist has devoured the souls of their opponents.\n\n");
					break;

				default:
					printf("The opposing forces have prevailed.\n");
					break;
			}
		} 
		else 
		{
			printf("\n>>> RESULT: TIE <<<\n");
			printf("In %s there were no victors\n", escenario);
		}

		printf("\n[FINAL STATUS OF THE CHAMPIONS:]\n");
		printf("%-22s | %-10s | %-10s\n", "CHARACTER", "FINAL HP", "STATUS");
		printf("----------------------------------------------------------\n");

		for (int i = 0; i < 5; i++) 
		{
			if (Equipo1[i].Hp > 0)
			{
				printf("%-22s | %10.1f | ALIVE\n",Equipo1[i].Name, Equipo1[i].Hp);

			}
			else
			{
               printf("%-22s | %10.1f | FALLEN\n",Equipo1[i].Name, 0.0);

			}
		}

		printf("------------------------------------------------------------\n");

		for (int i = 0; i < 5; i++) 
		{
			if (Equipo2[i].Hp > 0)
			{
				printf("%-22s | %10.1f | ALIVE\n",Equipo2[i].Name, Equipo2[i].Hp);

			}
			else
			{
               printf("%-22s | %10.1f | FALLEN\n",Equipo2[i].Name, 0.0);

			}
		}

		printf("\n##########################################################\n");
		printf("Simulation finished\n");
		printf("Press any key to return to the main menu...\n");
	}
	
	while (getchar() != '\n');
	getchar();
}