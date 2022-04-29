#include <stdio.h>
#include <stdlib.h>      
#include <time.h>
using namespace std;

#define MAX 13
#define MIN 1


int main(int argc, char *argv[]) {
    int ii=0;
    int random=0;
    srand(time(0));
    float apuesta=0, dinero=10000, ganancia=0;
    int cartaJA=0, cartaJB=0, cartaJC=0, suma_cartas_jugador=0; /* Cartas jugador */
    int cartaCA=0, suma_cartas_crupier=0; /* Cartas jugador */
    char continuar=0;
    int pedir_carta=0;
    do
    {
        suma_cartas_jugador=0; 
        ganancia=0;
        printf("\nUsted tiene %f pesos.\nIngrese su apuesta\n", dinero); /* Realizar apuesta*/
        scanf("%f", &apuesta);
        if (apuesta<=dinero&&apuesta!=0&&apuesta>0){ /* Apuesta valida */
            dinero-=apuesta;
            cartaJA = rand() % (MAX+1 - MIN); /* Carta 1 JUGADOR*/
            if (cartaJA>10){cartaJA=10;}
            if (cartaJA==0){cartaJA=1;}
            cartaJB = rand() % (MAX+1 - MIN); /* Carta 2 JUGADOR*/
            if (cartaJB>10){cartaJB=10;}
            if (cartaJB==0){cartaJB=1;}
            suma_cartas_jugador=cartaJA+cartaJB;
            if (cartaJA==10&&cartaJB==1||cartaJB==10&&cartaJA==1){ /* Situacion de blackjack */
                printf("\nTus cartas son\n %d y %d\nTienes blackjack\n", cartaJA, cartaJB);
                ganancia=apuesta*2.5;
                dinero+=ganancia;
                printf("Ganaste %f pesos\n", ganancia);
            }
            else if (suma_cartas_jugador<21){ /*Situacion suma menor a 21 */
                printf("\nTus cartas son\n %d y %d\nLa suma de tus cartas es %d\nDesea pedir otra carta?(Si-1 / No-0)\n", cartaJA, cartaJB, suma_cartas_jugador);
                scanf("%d", &pedir_carta);
                while (pedir_carta!=0){
                    cartaJC = rand() % (MAX+1 - MIN); /* Carta 3 JUGADOR*/
                    if (cartaJC>10){cartaJC=10;}
                    if (cartaJC==0){cartaJC=1;}
                    suma_cartas_jugador+=cartaJC;
                    if (suma_cartas_jugador<=21){ /*Situacion suma menor a 21 */
                        printf("\nTu nueva carta es\n%d\nLa suma de tus cartas es %d\nDesea pedir otra carta?(Si-1 / No-0)", cartaJC, suma_cartas_jugador);
                        scanf("%d", &pedir_carta);}
                    if (suma_cartas_jugador>21){ /*Situacion suma mayor a 21 */
                        printf("\nTus nueva carta es\n%d\nLa suma de tus cartas es %d\nHas perdido la ronda", cartaJC, suma_cartas_jugador);
                        pedir_carta=0;} 
                }    
                if (suma_cartas_jugador<=21){ /*Situacion suma menor a 21 */
                    printf("\nTurno del crupier");
                    suma_cartas_crupier=0;
                    cartaCA=0;
                    do{
                        cartaCA = rand() % (MAX+1 - MIN); /* Carta 3 JUGADOR*/
                        if (cartaCA>10){cartaCA=10;}
                        if (cartaCA==0){cartaCA=1;}
                        suma_cartas_crupier+=cartaCA;
                        printf("\nLa nueva carta del crupier es %d\nLa suma total del crupier es %d\n", cartaCA, suma_cartas_crupier);
                    } while (suma_cartas_crupier<17);
                    if (suma_cartas_crupier<=21&&suma_cartas_crupier>suma_cartas_jugador){
                        printf("El crupier gano la ronda, usted perdio %f", apuesta);
                    }
                    if (suma_cartas_crupier<=21&&suma_cartas_crupier==suma_cartas_jugador){
                        printf("Empato con el crupier, usted recupero su apuesta de %f", apuesta);
                        dinero+=apuesta;
                    }
                    if (suma_cartas_crupier<=21&&suma_cartas_crupier<suma_cartas_jugador){
                        do{
                        cartaCA = rand() % (MAX+1 - MIN); /* Carta 3 JUGADOR*/
                        if (cartaCA>10){cartaCA=10;}
                        if (cartaCA==0){cartaCA=1;}
                        suma_cartas_crupier+=cartaCA;
                        printf("\nLa nueva carta del crupier es %d\nLa suma total del crupier es %d\n", cartaCA, suma_cartas_crupier);
                    } while (suma_cartas_crupier<suma_cartas_jugador);
                    }
                    if (suma_cartas_crupier>21){
                        ganancia=apuesta*2;
                        printf("El crupier perdio, usted gano %f pesos\n", ganancia);
                        dinero+=ganancia;
                    } 
                }    
                if (suma_cartas_jugador>21){ /*Situacion suma mayor a 21 */
                    printf("\nTus nueva carta es\n%d\nLa suma de tus cartas es %d\nHas perdido la ronda", cartaJC, suma_cartas_jugador);
                    pedir_carta=0;} 
            }
            else if (suma_cartas_jugador>21){ /*Situacion suma mayor a 21 */
                printf("\nTus cartas son\n %d y %d\nLa suma de tus cartas es %d\nHas perdido la ronda", cartaJA, cartaJB, suma_cartas_jugador);
            }
        }
        else {printf ("Apuesta invalida, ingrese otro monto en la proxima ronda\n"); /* Apuesta invalida */
        printf("La ronda termino, para jugar otra ronda ingrese Y, para retirarse ingrese N\n"); /* Fin de ronda */
        scanf("%s", &continuar);}
    } while (continuar!='N');
    printf("Usted se retiro con %f pesos", dinero);
    
    return 0;
}