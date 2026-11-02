#include<iostream>
#include<cctype>
#include<string>
using namespace std;


void mostrar_reglas(){
    cout<<R"reglas(Reglas del juego UNO.
Objetivo:

Quedarte sin cartas en la mano antes que los demás. Quien lo logra gana la ronda. Se pueden jugar varias rondas, y el ganador definitivo es el jugador que gane más rondas.

Jugadores

De 2 a 4 jugadores.

Las cartas (108 en total)
Cartas de número: cuatro colores (azul, verde, rojo y amarillo). Cada color tiene un 0 y dos cartas de cada número del 1 al 9.
Cartas de acción: cada color tiene 2 Salta, 2 Reversa y 2 Roba +2.
Cartas comodín: 4 Comodín y 4 Comodín Roba +4.
Inicio de la ronda
Se barajan las cartas y se reparten 7 a cada jugador.
Las cartas que sobran forman el mazo para robar, boca abajo.
Se pone una carta boca arriba para iniciar la pila de descarte. Esa es la carta activa.
Cómo se juega
Los jugadores juegan por turnos, uno después del otro.
En tu turno debes jugar una carta que coincida con la carta activa en color, número o símbolo. También puedes jugar un comodín en cualquier momento.
Si no tienes ninguna carta que puedas jugar, robas una carta del mazo.
Si la carta que robaste se puede jugar, puedes jugarla de inmediato. Si no, la guardas y el turno pasa al siguiente jugador.
Si el mazo para robar se acaba, se vuelven a usar las cartas de la pila de descarte, menos la carta activa.
Cartas de acción
Salta: el siguiente jugador pierde su turno.
Reversa: cambia el sentido del juego.
Roba +2: el siguiente jugador roba 2 cartas y pierde su turno.
Comodín: eliges el color con el que se va a seguir jugando.
Comodín Roba +4: eliges el color, y el siguiente jugador roba 4 cartas y pierde su turno.
Ganar
Quien se queda sin cartas primero gana la ronda y suma una victoria.
Se pueden jugar tantas rondas como quieran.
Cuando termina el juego, gana quien tenga más rondas ganadas.)reglas"<<endl;

}


int menu (){
    int respuesta;
    cout<<"Bienvenido al juego UNO"<< endl;
    cout<<"oprime 1 para jugar"<<endl;
    cout<<"oprime 2 para salir"<<endl;
    cout<<"oprime 3 para conocer las reglas del juego"<<endl;

    cin>> respuesta;

    return respuesta;

}


struct carta{
    int numero;
    string color;
    string tipo;
};

carta mazo[5][25]={
 {{0, "azul","normal"}, {1, "azul","normal"},{2, "azul","normal"}, {3, "azul","normal"},{4, "azul","normal"}, {5, "azul","normal"}, {6, "azul","normal"}, {7, "azul","normal"}, {8, "azul","normal"},
 {9, "azul","normal"}, {1, "azul","normal"},{2, "azul","normal"}, {3, "azul","normal"},{4, "azul","normal"}, {5, "azul","normal"}, {6, "azul","normal"}, {7, "azul","normal"}, {8, "azul","normal"},{9, "azul","normal"},
  {10, "azul","+2"}, {10, "azul","+2"},{10, "azul","salta"}, {10, "azul","reversa"},{10, "azul","salta"}, {10, "azul","reversa"}},

 {{0, "rojo","normal"}, {1, "rojo","normal"},{2, "rojo","normal"}, {3, "rojo","normal"},{4, "rojo","normal"}, {5, "rojo","normal"}, {6, "rojo","normal"}, {7, "rojo","normal"}, {8, "rojo","normal"},
 {9, "rojo","normal"}, {1, "rojo","normal"},{2, "rojo","normal"}, {3, "rojo","normal"},{4, "rojo","normal"}, {5, "rojo","normal"}, {6, "rojo","normal"}, {7, "rojo","normal"}, {8, "rojo","normal"},{9, "rojo","normal"},
  {10, "rojo","+2"}, {10, "rojo","+2"},{10, "rojo","salta"}, {10, "rojo","reversa"},{10, "rojo","salta"}, {10, "rojo","reversa"}},

 {{0, "verde","normal"}, {1, "verde","normal"},{2, "verde","normal"}, {3, "verde","normal"},{4, "verde","normal"}, {5, "verde","normal"}, {6, "verde","normal"}, {7, "verde","normal"}, {8, "verde","normal"},
 {9, "verde","normal"}, {1, "verde","normal"},{2, "verde","normal"}, {3, "verde","normal"},{4, "verde","normal"}, {5, "verde","normal"}, {6, "verde","normal"}, {7, "verde","normal"}, {8, "verde","normal"},{9, "verde","normal"},
  {10, "verde","+2"}, {10, "verde","+2"},{10, "verde","salta"}, {10, "verde","reversa"},{10, "verde","salta"}, {10, "verde","reversa"}},

 {{0, "amarillo","normal"}, {1, "amarillo","normal"},{2, "amarillo","normal"}, {3, "amarillo","normal"},{4, "amarillo","normal"}, {5, "amarillo","normal"}, {6, "amarillo","normal"}, {7, "amarillo","normal"}, {8, "amarillo","normal"},
 {9, "amarillo","normal"}, {1, "amarillo","normal"},{2, "amarillo","normal"}, {3, "amarillo","normal"},{4, "amarillo","normal"}, {5, "amarillo","normal"}, {6, "amarillo","normal"}, {7, "amarillo","normal"}, {8, "amarillo","normal"},{9, "amarillo","normal"},
  {10, "amarillo","+2"}, {10, "amarillo","+2"},{10, "amarillo","salta"}, {10, "amarillo","reversa"},{10, "amarillo","salta"}, {10, "amarillo","reversa"}},

 {{11, "negro", "+4"},{11, "negro", "+4"},{11, "negro", "+4"},{11, "negro", "+4"}, {11, "negro", "cambio color"},{11, "negro", "cambio color"},{11, "negro", "cambio color"},{11, "negro", "cambio color"}}
};


int main(){

    int opcion;
    do{
        opcion = menu();
        if(opcion==3){
            mostrar_reglas();
        }
    }while(opcion != 2);

return 0;

}
