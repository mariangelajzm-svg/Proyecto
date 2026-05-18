IDEA: Juego con 12 personajes y 4 grupos (3 por grupo)  5 VS5 .
                   REGLAS A SEGUIR:
1. Comentarios: Usar para aclarar el propósito de variables y funciones.
2. Nomenclatura: Usar PascalCase para variables ( NombreDeVariable).
   (Primera letra de cada palabra en mayúscula, sin espacios ni guiones).
3. Llaves {}: Abrirlas en una línea nueva para separar mejor los bloques.
4. Indentación: Respetar el sangrado reglamentario para mantener el orden.
5. Idioma: El profesor mencionó que la creación de variables debía ser en inglés... aunque mas adelante las traducire*/
// Librerias usadas
#include <stdio.h>   // necesaria para imprimir y obtener datos del usuario
#include <stdbool.h> // para poder usar valores verdaderos o falsos
#include <stdlib.h>  // funciones como rand y srand para numeros "aleatorios"
#include <time.h>    // necesaria para que la funcion srand tome el reloj interno del computador como "semilla"
#include <math.h>
#include <string.h>
// Necesaria para operaciones matematicas un poco mas avanzadas
// ===================ESTRUCTURAS GLOBLALES=============
//<<<<<grupos de cartas  hechos por PAola>>
typedef struct 
{
	
	int CharacterID;// Identificacion del personaje
    char Group[30];// Grupo al que pertenece el Personaje
    char Type[30]; // Tipo de personaje (Guerrero, Distancia, Tanque)
    char Name[30]; // Nombre del Personaje
    float Hp; // Vida Máxima del Personaje
    float Def; // Defensa del Personaje
    float Atk; // Ataque del Personaje
    int Energy; // Energía del Personaje 
} Character;
// ==================VARIABLES GLOBALEs====================
Character Roster[12]; // Todos los Personajes que son parte del Juego.

int Lenguaje=0; // 0 es espaniol y 1 ingles
bool JuegoEncendido =true;//por ahora solo la que conrtola el apagado del juego
bool Play1Star = true; // si es TRUE el jugador 1 inicia, si es False inicia el jugador 2 y el que inicia elije la carta ambiente 
//===============ARREGLOS GLOBALES===============


/* ==============INDICE DE PROTOTIPOS(FUNCIONES) ===========
se iran mencionando aca para que el programa sepa que en
algun momento conseguira una funcion con ese nombre*/
char ShowPrincipalMenu();
void PrincipalLoop();
void MenuJump();
void CreateRoster();//crea a los personajes (Paola)
void ShowRoster();//muestra a los personajes en catalogo
/*añadir funcion para SeleccionDePersonaje
 y recordar hacer una funcion aleatrorio para el dado*/
void Dice();// el dado que decide si inicia el grupo 1 o 2 y el que gana tambien elije la carta ambiente 
void SelectLanguage();// espaniol opcion 1, ingles opcion 2
//===========INT MAIN donde inicializamos algunas funciones ========
int main()
{   
	srand(time(NULL));// necesario para el dado 
	SelectLanguage();
	CreateRoster();
	PrincipalLoop();
	return 0;
}
/*===================================================================================
==============================================By: Paola&Jimmelis================
======================FUNCIONES MENU================================================*/
void MenuJump()
{
	printf("\n>>>>>>>>>>>>>>>>>>>>O<<<<<<<<<<<<<<<<<<<<\n");
	printf("\n");
	printf("\n>>>>>>>>>>>>>>>>>>>>O<<<<<<<<<<<<<<<<<<<<\n");
}
/* aca se elije el idioma del juego*/
void SelectLanguage()
{
	char Option;
	printf("Selecciona un Idioma // Select a language \n");
	printf("=========================================\n");
	printf("1- ESPANIOL       //      1-SPANISH   \n");
	printf("2- INGLES         //      2-ENGLISH   \n");
	printf("Su Seleccion      // Your selection: -> ");
	scanf(" %c", &Option); 
	if(Option == '2') 
	{
		Lenguaje = 1; 
		printf("=========================================\n");
		printf("Starting the game in **ENGLISH**\n");
	}
	else if(Option == '1')
	{
		Lenguaje = 0; 
		printf("=========================================\n");
		printf("Inicializando el juego en **ESPANIOL**\n");
	}
	else 
	{
		// Si escriben otra cosa, forzamos espaniol
		Lenguaje = 0; 
		printf("=========================================\n");
		printf("Opcion invalida. Inicializando por defecto en **ESPANIOL**\n");
	}
	
	MenuJump();
}
/*funcion encargada del menu principa, use char ya que un numero es igual un caracter y asi nos
 salvamos de un bucle infinito si sin querer escribian una letra u otro simbolo salvamos de u
 n bucle infinito si sin querer escribian una letra u otro simbolo*/
 	
char ShowPrincipalMenu()
{
	char SeleccionUsuario;
	if (Lenguaje == 0) // Si es 0, mostramos todo en ESPANIOL
	{
		printf ("\n ==== Ecos de Traicion y Horror en C ====\n\n");
		printf (" POR FAVOR SELECCIONE UNA OPCION\n");
		printf ("\n 1-- Ver lista de personajes \n");
		printf ("\n 2-- Formar Equipos \n");
		printf ("\n 3-- Iniciar Batalla \n");
		printf ("\n 4-- Mostrar Resultados \n");
		printf ("\n 5-- SALIR DEL JUEGO!\n");
		printf ("\n SU SELECCION   ");
	}
	else // Si es 1 (o cualquier otra cosa), mostramos todo en INGLES
	{
		printf ("\n ==== Echoes of Treason and Horror in C ====\n\n");
		printf (" PLEASE SELECT AN OPTION\n");
		printf ("\n 1-- View character list \n");
		printf ("\n 2-- Form Teams \n");
		printf ("\n 3-- Start Battle \n");
		printf ("\n 4-- Show Results \n");
		printf ("\n 5-- EXIT GAME!\n");
		printf ("\n YOUR SELECTION   ");
	}
	scanf(" %c", &SeleccionUsuario);
	MenuJump();
	return SeleccionUsuario;
}
// es el bucle principal donde se inicia el juego
void PrincipalLoop()
{
	char OpcionDeInicio;
	while (JuegoEncendido == true)
	{
		OpcionDeInicio = ShowPrincipalMenu();
		switch (OpcionDeInicio) 
		{	
			case '1':
				if (Lenguaje == 0) 
				{ 
					printf("\n   LISTA DE PERSONAJES\n"); 
				}
				else 
				{ 
					printf("\n   CHARACTER LIST\n"); 
				}
				ShowRoster(); // Llamamos al catalogo
			break;
			case '2':
				if (Lenguaje == 0)
				{
				  printf("\n CREACION DE EQUIPOS\n"); 
				}
				else
				{
				  printf("\n TEAM CREATION\n");
				}
			break;
			case '3':
				if (Lenguaje == 0)
				{
					printf("\n INICIAR BATALLA\n");
					Dice(); 
				}
				else
				{
					printf("\n START BATTLE \n");
					Dice();
				}
			break;
			case '4':
				if (Lenguaje == 0)
				{
				  printf("\nREGISTRO DE VENCEDORES EN IRONHAVEN\n"); 
				}
				else
				{
				  printf("\nRECORD OF VICTORS IN IRONHAVEN\n");
				}	
			break;
			case '5':
				if (Lenguaje == 0)
				{
				  printf("\n*** =SALIENDO DEL JUEGO GRACIAS POR JUGAR! ***\n"); 
				}
				else
				{
				  printf("\n*** EXITING GAME THANKS FOR PLAYING! ***\n");
				}
				JuegoEncendido = false;				
			break;
			default:
				if (Lenguaje == 0)
				{
				  printf("\n==Opcion no valida! Intente de nuevo Por favor===\n"); 
				}
				else
				{
				  printf("\n==Invalid option! Please try again===\n");
				}			
			break;
		}	
		MenuJump();
	}	
}
/*===================================================================================
=====================================================================================
===CREACION DE PERSONAJES,CARTAS DE AMBIENTE   y CATALOGO===============================*/
void CreateRoster() // paola
{
    // Si el lenguaje es ESPANIOL (0)
    if (Lenguaje == 0) 
    {
        Character creatingES[12] = 
        {
            // Nobles de Ironhaven
            { 1,"Nobles de Ironhaven","Guerrero","Alaric", 150, 150, 150, 150}, 
            { 2,"Nobles de Ironhaven","Distancia","Elara", 100, 50, 200, 250}, 
            { 3,"Nobles de Ironhaven","Tanque","Gareth, el Leal", 250, 200, 100, 50}, 
            // Los Cristalizados
            { 4,"Los Cristalizados","Tanque","Espectro de Obsidiana", 250, 200, 100, 50}, 
            { 5,"Los Cristalizados","Guerrero" ,"Jaspe, el Baron Rojo", 150, 150, 150, 150}, 
            { 6,"Los Cristalizados","Distancia","Selene, Demonio de Plata", 100, 50, 200, 250}, 
            // Cazadores Hostiles
            { 7,"Cazadores Hostiles","Tanque","Gehrman, el Verdugo", 250, 200, 100, 50}, 
            { 8,"Cazadores Hostiles","Distancia" ,"Kira, Asesino de Monstruos", 100, 50, 200, 250}, 
            { 9,"Cazadores Hostiles","Guerrero","Orion, Cazador Celestial", 150, 150, 150, 150}, 
            // La Bruma Escarlata
            {10,"La Bruma Escarlata","Guerrero","El Arcano", 300, 50, 0, 250}, 
            {11,"La Bruma Escarlata","Tanque","Rey Cedric", 250, 200, 100, 50}, 
            {12,"La Bruma Escarlata","Distancia","Principe Arthur", 150, 150, 150, 150}
        };
        for (int i = 0; i < 12; i++) Roster[i] = creatingES[i];
    }
    // Si el lenguaje es INGLES
    else 
    {
        Character creatingEN[12] = 
        {
            // Ironhaven Nobles
            { 1,"Ironhaven Nobles","Warrior","Alaric", 150, 150, 150, 150}, 
            { 2,"Ironhaven Nobles","Ranged","Elara", 100, 50, 200, 250}, 
            { 3,"Ironhaven Nobles","Tank","Gareth, the Loyal", 250, 200, 100, 50}, 
            // The Crystallized
            { 4,"The Crystallized","Tank","Obsidian Wraith", 250, 200, 100, 50}, 
            { 5,"The Crystallized","Warrior" ,"Jasper, the Red Baron", 150, 150, 150, 150}, 
            { 6,"The Crystallized","Ranged","Selene, Silver Demon", 100, 50, 200, 250}, 
            // Hostile Hunters
            { 7,"Hostile Hunters","Tank","Gehrman, the Executioner", 250, 200, 100, 50}, 
            { 8,"Hostile Hunters","Ranged" ,"Kira, Monster Hunter", 100, 50, 200, 250}, 
            { 9,"Hostile Hunters","Warrior","Orion, Celestial Hunter", 150, 150, 150, 150}, 
            // The Scarlet Mist
            {10,"The Scarlet Mist","Warrior","The Arcane", 300, 50, 0, 250}, 
            {11,"The Scarlet Mist","Tank","King Cedric", 250, 200, 100, 50}, 
            {12,"The Scarlet Mist","Ranged","Prince Arthur", 150, 150, 150, 150}
        };
        for (int i = 0; i < 12; i++) Roster[i] = creatingEN[i];
    }
}

void ShowRoster() //CATALOGO DE PERSONAJES
{
	if (Lenguaje == 0) 
	{
	 	printf("****       CATALOGO DE PERSONAJES DE IRONHAVEN        ****\n");
    	for (int i = 0; i < 12; i++) 
    	{
			printf("\n ====================================================================");
        	printf("\nID:    %d   |Grupo: %s\n", Roster[i].CharacterID,Roster[i].Group );
        	printf(" Nombre: %s   |Tipo: %s\n",Roster[i].Name , Roster[i].Type);
        	printf("       ESTADISTICAS\n HP: %.2f  |DEF: %.2f \n ATK: %.2f | ENERGIA: %d\n",Roster[i].Hp, Roster[i].Def, Roster[i].Atk, Roster[i].Energy);       
    	}
	}
	else 
	{
		printf("****       IRONHAVEN CHARACTER CATALOG       ****\n");
    	for (int i = 0; i < 12; i++) 
    	{
			printf("\n ====================================================================");
        	printf("\nID:    %d   |Group:: %s\n", Roster[i].CharacterID,Roster[i].Group );
        	printf(" Name: %s   |Type: %s\n",Roster[i].Name , Roster[i].Type);
        	printf("       STATISTICS\n HP: %.2f  |DEF: %.2f \n ATK: %.2f | ENERGY: %d\n",Roster[i].Hp, Roster[i].Def, Roster[i].Atk, Roster[i].Energy);       
    	}
	}
    	
}
/*===================================================================================
=====================================================================================
=====================SELECCION DE PERSONAJES POR CATALOGO===============================*/





/*===================================================================================
============================================================Arturo===================
================================DADO DE INICIO =====================================*/
void Dice()
{
 	int resultado = (rand() % 6) + 1;
    printf("El dado decidira el destino ...y es ..:\n \t=====%d=====\n", resultado);
    printf("------------------------\n");
    if(resultado % 2 != 0) 
	{
        printf(" Es IMPAR! Comienza el *Grupo 1 (Lazos de Vapor)\n");
        Play1Star = true;  // El grupo 1 inicia
    } 
	else 
	{
        printf("Es PAR! Comienza el *Grupo 2*(Alianza Escarlata ) \n");
        Play1Star = false; // El grupo 2 inicia
    }  
}


/*===================================================================================
===============================================Mariangela==========Ángel============================
=====================CONCLUSIONES==========================*/
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

    
    printf("\n\n##########################################################\n");
    printf("                 *** REGISTRO DE BATALLA *** \n");
    printf("##########################################################\n");

    
    printf("\n[DATOS DEL ENCUENTRO EN: %s]\n", escenario);
    printf("- Ciclos de combate: %d\n", turnos);
    printf("- Supervivientes Grupo 1 (HEROES): %d / 5\n", vivosG1);    
    printf("- Supervivientes Grupo 2 (ENEMIGOS): %d / 5\n", vivosG2);  

    
    if (vivosG1 > 0) 
    {
        printf("\n>>> RESULTADO: VICTORIA ABSOLUTA DE LOS NOBLES DE IRONHAVEN <<<\n");
        
        if (strcmp(escenario, "Reencuentro en la Niebla") == 0) 
        {
            printf("Los Cristalizados fueron destruidos\n");
        } 
        else if (strcmp(escenario, "La Gran Biblioteca") == 0) 
        {
            printf("Los Cazadores Hostiles han sido derrotados\n");
        } 
        else if (strcmp(escenario, "El Epicentro en la Catedral") == 0)
        {
            printf("CONCLUSIÓN FINAL: La Bruma Escarlata ha sido derrotada. La niebla se disipa en toda la ciudad.\n");
        }
    } 
    else if (vivosG2 > 0) 
    {
        printf("\n>>> RESULTADO: DERROTA <<<\n");

        
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
            case 1: // Los cristalizados
                printf("Los Cristalizados han convertido a los Nobles de Ironhaven en estatuas de cuarzo.\n");
                break;
            
            case 2: // Cazadores Hostiles
                printf("Los Cazadores Hostiles han ganado.\nLos Nobles de Ironhaven han sido derrotados\n");
                break;
            
            case 3: // La Bruma Escarlata
                printf("DUELO FINAL FALLIDO: La Bruma Escarlata ha devorado las almas de los nobles de Ironhaven.\n");
                break;

            default:
                printf("Las fuerzas oscuras han prevalecido.\n");
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

    // Equipo 1
    for (int i = 0; i < 5; i++) 
    {
        printf("%-22s | %10.1f | %s\n", 
                Equipo1[i].Name, 
                (Equipo1[i].Hp < 0 ? 0 : Equipo1[i].Hp),
                (Equipo1[i].Hp > 0 ? "VIVO" : "CAÍDO"));
    }

    printf("------------------------------------------------------------\n");

    // Equipo 2
    for (int i = 0; i < 5; i++) 
    {
        printf("%-22s | %10.1f | %s\n", 
                Equipo2[i].Name, 
                (Equipo2[i].Hp < 0 ? 0 : Equipo2[i].Hp), 
                (Equipo2[i].Hp > 0 ? "VIVO" : "CAÍDO"));
    }

    printf("\n##########################################################\n");
    printf("Simulación finalizada\n");
    printf("Presione una tecla para volver al menu principal...\n");

    
    while (getchar() != '\n');
    getchar();
}