void mostrarConclusionFinal(personaje *equipo1, personaje *equipo2, int turnos, char *escenario) {
    int vivosG1 = 0, vivosG2 = 0;
    

    for(int i = 0; i < 5; i++) {
        if(equipo1[i].hp > 0) vivosG1++;
        if(equipo2[i].hp > 0) vivosG2++;
    }


    printf("\n\n"
           "##########################################################\n"
           
           "                 *** REGISTRO DE BATALLA ***           \n"
           
           "##########################################################\n");



    printf("\n[DATOS DEL ENCUENTRO EN: %s]\n", escenario);
    printf("- Ciclos de combate: %d\n", turnos);
    printf("- Supervivientes Grupo 1 (HEROES): %d / 5\n", vivosG1);    
    printf("\n- Supervivientes Grupo 2 (ENEMIGOS): %d / 5\n", vivosG2);  


    if(vivosG1 > 0) {
        printf("\n>>> RESULTADO: VICTORIA ABSOLUTA DE LOS NOBLES DE IRONHAVEN <<<\n");
        
        if(strcmp(escenario, "Reencuentro en la Niebla") == 0) {
            printf("Los Cristalizados fueron destruidos\n");
        } 
        
        else if(strcmp(escenario, "La Gran Biblioteca") == 0) {
            printf("Los Cazadores Hostiles han sido derrotados\n");
                   
        }
        
        else if(strcmp(escenario, "El Corazon de la Bruma") == 0) {
            printf("CONCLUSIÓN FINAL:La Bruma Escarlata ha sido derrotada. La niebla se disipa en toda la ciudad.\n");
        }
        

    }

    else if(vivosG2 > 0) {
        printf("\n>>> RESULTADO: DERROTA <<<\n");
        
        faccionGanador = equipo2[0].grupo;
        switch(ganador) {
            
            case CRISTALIZADOS:
                printf("Los Cristalizados han convertido a los Nobles de Ironhaven en estatuas de cuarzo.\n");
                break;
            
            case CAZADORES HOSTILES:
                printf("Los Cazadores Hostiles han ganado.\n"
                       "Los Nobles de Ironhaven han sido derrotados\n");
                break;
            
                case BRUMA ESCARLATA:
                printf("DUELO FINAL FALLIDO: La Bruma Escarlata ha devorado las almas de los nobles de Ironhaven.\n");
                break;
            
        }
    } 
    else {
        printf("\n>>> RESULTADO: EMPATE <<<\n");
        printf("En %s no hubo vencedores \n", escenario);
    }


    printf("\n[ESTADO FINAL DE LOS CAMPEONES:]\n");
    printf("%-20s | %-10s | %-10s\n", "PERSONAJE", "HP FINAL", "ESTADO");
    printf("----------------------------------------------------------\n");

    for(int i = 0; i < 5; i++) {
        printf(" - %-20s | HP: %6.1f | Estado: %s\n", 
                equipo1[i].nombre, (equipo1[i].hp < 0 ? 0 : equipo1[i].hp),
                (equipo1[i].hp > 0 ? "VIVO" : "CAÍDO"));
    }

    for(int i = 0; i < 5; i++) {
        printf(" - %-20s | HP: %6.1f | Estado: %s\n", 
                equipo2[i].nombre, (equipo2[i].hp < 0 ? 0 : equipo2[i].hp), 
                (equipo2[i].hp > 0 ? "VIVO" : "CAÍDO"));
    }

    printf("\n##########################################################\n");
    
    printf("Simulación finalizada\n");

    printf("Presione una tecla para volver al menu principal...\n")

    while(getchar() != '\n');
    getchar();

}