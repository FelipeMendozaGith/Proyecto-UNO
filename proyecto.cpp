#include<iostream>
#include<cctype>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Se documentan las reglas del juego.
void mostrar_reglas(){
    cout<<R"reglas(Reglas del juego UNO.
Objetivo:

Quedarte sin cartas en la mano antes que los demas. 
Quien lo logra gana la ronda. 
Se pueden jugar varias rondas, y el ganador definitivo es el jugador que gane mas rondas.

Jugadores: De 2 a 4 jugadores.

Las cartas: 108 en total
Cartas de numero: cuatro colores (azul, verde, rojo y amarillo). Cada color tiene un 0 y dos cartas de cada numero del 1 al 9.
Cartas de accion: cada color tiene 2 Salta, 2 Reversa y 2 Roba +2.
Cartas comodin: 4 Comodin y 4 Roba +4.

Inicio de la ronda:
Se barajan las cartas y se reparten 7 a cada jugador.
Las cartas que sobran forman el mazo para robar, boca abajo.
Se pone una carta boca arriba para iniciar la pila de descarte. Esa es la carta activa.

Como se juega:
Los jugadores juegan por turnos, uno despues del otro.
En tu turno debes jugar una carta que coincida con la carta activa en color, numero o simbolo. 
Tambien puedes jugar un comodin en cualquier momento.
Si no tienes ninguna carta que puedas jugar, robas una carta del mazo.
Si la carta que robaste se puede jugar, puedes jugarla de inmediato. Si no, la guardas y el turno pasa al siguiente jugador.
Si el mazo para robar se acaba, se vuelven a usar las cartas de la pila de descarte, menos la carta activa.

Cartas de accion:
Salta: el siguiente jugador pierde su turno.
Reversa: cambia el sentido del juego.
Roba +2: el siguiente jugador roba 2 cartas y pierde su turno.
Comodin: eliges el color con el que se va a seguir jugando.
Roba +4: eliges el color, y el siguiente jugador roba 4 cartas y pierde su turno.

Ganar:
Quien se queda sin cartas primero gana la ronda y suma una victoria.
Se pueden jugar tantas rondas como quieran.
Cuando termina el juego, gana quien tenga mas rondas ganadas.)reglas"<<endl<<endl;
}

// Funcion menu principal devuelve la opcion elegida por el usuario.
int menu (){
    int respuesta;
    cout<<"Bienvenido al juego UNO"<< endl;
    cout<<"oprime 1 para jugar"<<endl;
    cout<<"oprime 2 para salir"<<endl;
    cout<<"oprime 3 para conocer las reglas del juego"<<endl;

    cin>> respuesta;

    return respuesta;

}

// Definicion de la estructura con la informacion de cada carta
struct carta{
    int numero;
    string color;
    string tipo;
    bool estatus;
};

// Matriz con todas las cartas que conforman el juego, cada carta inicia disponible para jugar.

carta mazo[5][25]={
 {{0, "azul","normal", true}, {1, "azul","normal",true},{2, "azul","normal",true}, {3, "azul","normal",true},{4, "azul","normal",true}, {5, "azul","normal",true}, {6, "azul","normal",true}, {7, "azul","normal",true}, {8, "azul","normal",true},
 {9, "azul","normal",true}, {1, "azul","normal",true},{2, "azul","normal",true}, {3, "azul","normal",true},{4, "azul","normal",true}, {5, "azul","normal",true}, {6, "azul","normal",true}, {7, "azul","normal",true}, {8, "azul","normal",true},{9, "azul","normal",true},
  {10, "azul","+2",true}, {10, "azul","+2",true},{10, "azul","salta",true}, {10, "azul","reversa",true},{10, "azul","salta",true}, {10, "azul","reversa",true}},

 {{0, "rojo","normal",true}, {1, "rojo","normal",true},{2, "rojo","normal",true}, {3, "rojo","normal",true},{4, "rojo","normal",true}, {5, "rojo","normal",true}, {6, "rojo","normal",true}, {7, "rojo","normal",true}, {8, "rojo","normal",true},
 {9, "rojo","normal",true}, {1, "rojo","normal",true},{2, "rojo","normal",true}, {3, "rojo","normal",true},{4, "rojo","normal",true}, {5, "rojo","normal",true}, {6, "rojo","normal",true}, {7, "rojo","normal",true}, {8, "rojo","normal",true},{9, "rojo","normal",true},
  {10, "rojo","+2",true}, {10, "rojo","+2",true},{10, "rojo","salta",true}, {10, "rojo","reversa",true},{10, "rojo","salta",true}, {10, "rojo","reversa",true}},

 {{0, "verde","normal",true}, {1, "verde","normal",true},{2, "verde","normal",true}, {3, "verde","normal",true},{4, "verde","normal",true}, {5, "verde","normal",true}, {6, "verde","normal",true}, {7, "verde","normal",true}, {8, "verde","normal",true},
 {9, "verde","normal",true}, {1, "verde","normal",true},{2, "verde","normal",true}, {3, "verde","normal",true},{4, "verde","normal",true}, {5, "verde","normal",true}, {6, "verde","normal",true}, {7, "verde","normal",true}, {8, "verde","normal",true},{9, "verde","normal",true},
  {10, "verde","+2",true}, {10, "verde","+2",true},{10, "verde","salta",true}, {10, "verde","reversa",true},{10, "verde","salta",true}, {10, "verde","reversa",true}},

 {{0, "amarillo","normal",true}, {1, "amarillo","normal",true},{2, "amarillo","normal",true}, {3, "amarillo","normal",true},{4, "amarillo","normal",true}, {5, "amarillo","normal",true}, {6, "amarillo","normal",true}, {7, "amarillo","normal",true}, {8, "amarillo","normal",true},
 {9, "amarillo","normal",true}, {1, "amarillo","normal",true},{2, "amarillo","normal",true}, {3, "amarillo","normal",true},{4, "amarillo","normal",true}, {5, "amarillo","normal",true}, {6, "amarillo","normal",true}, {7, "amarillo","normal",true}, {8, "amarillo","normal",true},{9, "amarillo","normal",true},
  {10, "amarillo","+2",true}, {10, "amarillo","+2",true},{10, "amarillo","salta",true}, {10, "amarillo","reversa",true},{10, "amarillo","salta",true}, {10, "amarillo","reversa",true}},

 {{11, "+ 4", "+4",true},{11, "+4", "+4",true},{11, "+4", "+4",true},{11, "+4", "+4",true}, {11, "cambio color", "cambio color",true},{11, "cambio color", "cambio color",true},{11, "cambio color", "cambio color",true},{11, "cambio color", "cambio color",true}}
};

struct registro{

    string nombre;
    int victorias = 0;

};

carta jugadores[4][100]={};
void repartir_cartas(carta mazo[5][25], int njugadores){
    for(int i=0; i<njugadores; i++){
        for(int o=0; o<7; o++){
            
                int fila = rand() % 5;
                if(fila == 4){
                    int col = rand() % 8;
                    jugadores[i][o]=mazo[fila][col];
                    

                }else{
                    int col = rand() % 25;
                    jugadores[i][o]=mazo[fila][col];
                    
                }
        }
    }

   
}

void mostrar_barajas(carta jugadores[4][100]){

    for(int i =0; i<2; i++){
        for(int z=0;z<7;z++){
            cout<<jugadores[i][z].numero<<" ";
            cout<<jugadores[i][z].color<<", ";
        }
        cout<<endl;
    }

};

int main(){
    std::srand(std::time(nullptr));
    int njugadores;
    int opcion;
    do{

        // Se llama la funcion menu 
        opcion = menu();

        // Se elige la opcion jugar
        if (opcion == 1){
  
            do{
                
                cout<<"¿cuantos jugadores quieren jugar?  "<<endl;
                cin>> njugadores;

            }while(njugadores<2 || njugadores>4 );

            registro usuarios [njugadores];

            for(int i=0; i<njugadores; i++){

                cout<<"ingrese nombre del jugador   "<< i+1 <<endl;
                cin>> usuarios[i].nombre;

            }
            repartir_cartas(mazo, njugadores);
             mostrar_barajas(jugadores);
            
        }
        
        // Se elige la opcion salir
        if(opcion == 2){
            break;
        }

        // Se elige la opcion reglas del juego
        if(opcion==3){
            mostrar_reglas();
        }


    }while(opcion != 2);

return 0;

}
