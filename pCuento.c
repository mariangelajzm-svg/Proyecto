#include <stdio.h>
#include <stdlib.h>

int main() {
    int seleccionModo, seleccionMetodo;

printf("\n============================================\n");
    printf("     ECOS DE TRAICIÓN Y HORROR EN C \n");
    printf("============================================\n");

    
   printf("¿De qué modo desea jugar?\n");
    printf("1 -- persona vs persona\n");
    printf("2 -- persona vs máquina\n");
    printf("3 -- solo espectador(máquina vs máquina).\n\n");
    printf("Su selección: ");
    scanf("%d", &seleccionModo);

   
    printf("\n Elija el método de selección de personajes\n");
    printf("--1 Al azar\n");
    printf("-2 Manual\n\n");
    printf("Su selección: ");
    scanf("%d", &seleccionMetodo);

   printf("\n============================================\n");
    printf("   CATEGORÍAS DE PERSONAJES DISPONIBLES \n");
    printf("============================================\n");

   
    printf("1. LOS NOBLES DE IRONHAVEN\n");
    
    printf("   - Alaric\n");
    printf("   - Elara\n\n");

   
    printf("2. LOS CRISTALIZADOS\n");
    
    printf("   - Espectro de Obsidiana\n");
    printf("   - Jaspe, el barón rojo\n");
    printf("   - Selene, demonio de plata\n\n");

   
  printf("3. CAZADORES HOSTILES\n");
    
    printf("   - Gehrman, el Verdugo\n");
    printf("   - Kira, asesino de monstruos\n");
    printf("   - Orión, cazador celestial \n\n");

    
    printf("4. LA BRUMA ESCARLATA\n");
    
    printf("   - El Arcano\n");
    printf("   - Rey Cedric\n");
    printf("   - Príncipe Arthur\n");
    
    
   // Pausa final
    printf("\n Presione ENTER para continuar...");
   
    return 0;
}