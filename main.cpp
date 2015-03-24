
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <vector>          // std::list
using namespace std;

int infinito = 9999;

//Dado: un grafo con 5 nodos implementado en una tabla (arreglo bidimensional)
//Dado: las columnas de la tabla representan el inicio y las filas el destino
//Dado: las columnas y las filas se representan en el arreglo de la siguiente manera: [columnas][filas]
//Dado: las aristas tienen un valor de 0 si apuntan a ellas, infinito si no esta conectada y de lo contrario significa que sí hay una conexion entre los nodos

//Devuelve la distancia (o peso) de una arista dado sus dos nodos (inicio y destino)
//Nota: se sugiere NO usar recursion


//explicacion del ejercicio
//dado el inicio y el destino del nodo retorno la distancia de las arista del inicio hasta el destino
int obtenerDistanciaAristaDirecta(int grafo[5][5], int inicio, int destino)
{
    return grafo[inicio][destino];   ///devuelve la cantidad de aristas desde el inicio hasta el fin
}

vector<int> obtenerListaDeAristas(int grafo[5][5], int inicio)
{
    vector<int> respuesta;
    return respuesta;
}

//Devuelve verdadero si existe al menos un camino para llegar desde el nodo inicio hasta el nodo destino dada una profundidad maxima de recorrido
//Nota: se sugiere usar recursion

//la funcion recibe 3 variables el inicio y el destino con la profundidad 
bool existeCamino(int grafo[5][5], int inicio, int destino,int profundidad)
{
       if (profundidad<0 &&inicio<5)    ///comparo si la profundidad es menor a 0 y el valor dado es menor al tamano del grafo retorno falso
    return false;                         ///no existe un  camino y sigo a la siguiente condicion. este es mi caso base

    if (inicio==destino)            //   ..mi cuerpo: sii el valor dado es igual al destino entonces si existe un camino debido a que mi inicio llego a mi destino

    return true;                    

    for(int i=0;i<5;i++)          ///para recorer el grafo es necesario un bucle en este caso es for en donde
    {                           /// se a generar dependiendo del tamno de mi grafo

    if (grafo[inicio][i]==infinito)              ///una vez que entramos comparamos de nuevo para cubrir todas las posibilidades
    {                                    ///si mi grafo en la posicion dada con una iteracion es igual al valor a evaluar entoces 
    continue;                              ///le doy un filtro para que continue mi siguiente condicion anidada
    }
    if (existeCamino(grafo,i,destino,profundidad-1))    //utilizo la recursion para moverme entre mis nodos./// es importante mencionar que se debe de reducir el nivel de la profunidad para que este se mueva al sieguiente nivel de lo contrario no funcionara
                                                         //como parametros en la recursion recibimos un grafo cmo lo demanda el ejercicio, el numero de iteracion, el destino y una profundidad menor que indica que la siguiente recuersion pasara a otro nivel del grafo
    return true;                        ///si durante la recuersion encuentra el valor de nodo destino entonces retorna verdadero
    
    }
return false;             ///si no lo encuentra entonces retorna falso



}

int main ()
{
    evaluar();

    return 1;
}
