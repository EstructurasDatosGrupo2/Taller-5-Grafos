#include "Graph.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

queue<int> uploadStellarMap(string fileName);
void saveConstellationsHAMILTONTack(std::vector<std::vector<int>> constelaciones);
void saveConstellationsEULERTack(std::vector<std::vector<int>> constelaciones);
void saveConstellationsHAMILTONTackMINIMA(std::vector<std::vector<int>> constelaciones);
void saveConstellationsEULERTackMINIMA(std::vector<std::vector<int>> constelaciones);
void crearMatrizAdjacencia(std::vector<std::vector<int>> constelaciones);

int main(){

    Graph<int, int> myGraph(2);
    queue<int> queueStellarMap;
    int matrixAdj[29][29];


    cout<<"Hello the Stellar Traker program"<<endl;
    //Cargando Mapa estelar
    queueStellarMap = uploadStellarMap("stellarMap.txt");

    //Creando matriz de adya
    for(int filas = 0; filas < 29; filas++){

        for (int columnas = 0; columnas < 29; columnas++){
            matrixAdj[filas][columnas] = queueStellarMap.front();
            cout << queueStellarMap.front() << "  ";
            queueStellarMap.pop();
            
        }
        cout << endl;
    }


    //Creando grafo
    
    for(int filas = 0; filas < 29; filas++){
        for (int columnas = 0; columnas < 29; columnas++){
            int cost = matrixAdj[filas][columnas];
            if(cost != 0){
                myGraph.agregarArista(filas, columnas, cost, 0);
            } 
        }
                
    }
    cout << "Grafo creado" << endl;
    
    cout << myGraph.printGraph();
    cout << "Cantidad de nodos: " << myGraph.getCantNodos() << endl;
    cout << "Cantidad de aristas: " << myGraph.cantidadAristas() << endl;
    cout << "Cantidad de vertices: " << myGraph.cantidadVertices() << endl;
    cout << "Dirigido: " << myGraph.getDirigido() << endl;
    cout << "Datos del Vetice 0;" << endl;
    cout << "Arista puente: " << myGraph.aristaPuente(0, 1, 0) << endl;
    cout << "Grado salida: " << myGraph.gradoSalida(0) << endl;
    cout << "Grado entrada: " << myGraph.gradoEntrada(0) << endl;
    cout << "Grado: " << myGraph.grado(0) << endl;
    cout << "Descendientes: ";
    myGraph.descendientes(0);
    cout<< endl;
    cout << "Ascendientes: ";
    myGraph.ascendientes(0);
    cout << endl;
    cout << "Grafo conectado: " << myGraph.grafoConectado() << endl;
    cout << "Cantidad de campos conectados: " << myGraph.cantidadCamposConectados() << endl;
    cout << "Recorrido DFS: " << myGraph.printDFS(0) << endl;
    cout << "Recorrido BFS: " << myGraph.printBFS(0) << endl;
    
    
    cout << endl;
    cout << endl;

    //Constelaciones Euler 20
    cout << "Constelaciones Euler"<<endl;
    vector<vector<int>> constelacionesEuler = myGraph.constelacionesEuler();
    for (vector<vector<int>>::iterator it = constelacionesEuler.begin(); it != constelacionesEuler.end(); ++it){
        for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2){
            cout << *it2 << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    //camino hamiltoniano
    cout << "Camino hamiltoniano"<<endl;
    vector< vector<int> > caminoHamiltoniano = myGraph.caminoHamiltoniano();
    for (vector<vector<int>>::iterator it = caminoHamiltoniano.begin(); it != caminoHamiltoniano.end(); ++it){
        for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2){
            cout << *it2 << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;


    saveConstellationsEULERTack(constelacionesEuler);
    saveConstellationsHAMILTONTack(caminoHamiltoniano);
    crearMatrizAdjacencia(constelacionesEuler);
    


    //costelaciones en su minima expresion
    cout << "Constelaciones EULER en su minima expresion"<<endl;
    vector<vector<int>> constelacionesEulerMINIMA = myGraph.constelacionesMinima(constelacionesEuler);
    for (vector<vector<int>>::iterator it = constelacionesEulerMINIMA.begin(); it != constelacionesEulerMINIMA.end(); ++it){
        for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2){
            cout << *it2 << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    cout << "Constelaciones Hamilton en su minima expresion"<<endl;
    vector<vector<int>> constelacionesHamiltonMINIMA = myGraph.constelacionesMinima(caminoHamiltoniano);
    for (vector<vector<int>>::iterator it = constelacionesHamiltonMINIMA.begin(); it != constelacionesHamiltonMINIMA.end(); ++it){
        for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2){
            cout << *it2 << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    saveConstellationsHAMILTONTackMINIMA(constelacionesHamiltonMINIMA);
    saveConstellationsEULERTackMINIMA(constelacionesEulerMINIMA);


   
}
//Guardando constelaciones
void saveConstellationsEULERTack(std::vector<std::vector<int>> constelaciones){
    ofstream myFile;
    int counter = 0;
    myFile.open("constellationsEULER<20.txt");
    myFile << "Constelcion Euler de costos menores a 20" << endl;
    myFile << "Datos para crear matriz de Adjacencia" << endl;

    for (vector<vector<int>>::iterator it = constelaciones.begin(); it != constelaciones.end(); ++it){
        myFile << "Nodos-conectados: ";
        for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2){
            myFile << " " << *it2;
            counter++;
        }
         
        myFile << endl;
    }
    
    myFile << "Cantidad de vertices: " << constelaciones.size() << endl;
    myFile << "Cantidad de aristas: " << constelaciones.size()*(constelaciones.size()-1)/2 << endl;
    myFile << "Cantidad de conecciones: " << counter << endl;

    myFile << "EU-" << constelaciones.size() << " "<<constelaciones.size()*(constelaciones.size()-1)/2<<" 2022" << endl;
    myFile.close();
    

}

void saveConstellationsHAMILTONTack(std::vector<std::vector<int>> constelaciones){
    ofstream myFile;
    int counter = 0;
    myFile.open("constellationsHAMILTON<20.txt");
    myFile << "Constelcion Euler de costos menores a 20" << endl;
    myFile << "Datos para crear matriz de Adjacencia" << endl;

    for (vector<vector<int>>::iterator it = constelaciones.begin(); it != constelaciones.end(); ++it){
        myFile << "Nodos-conectados: ";
        for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2){
            myFile << " " << *it2;
            counter++;
        }
         
        myFile << endl;
    }
    myFile << "Cantidad de vertices: " << constelaciones.size() << endl;
    myFile << "Cantidad de aristas: " << constelaciones.size()*(constelaciones.size()-1)/2 << endl;
    myFile << "Cantidad de conecciones: " << counter << endl;

    myFile << "HA-" << constelaciones.size() << " "<< constelaciones.size()*(constelaciones.size()-1)/2<<" 2022" << endl;
    myFile.close();
    

}

queue<int> uploadStellarMap(string fileName){
    
    queue<int> queueStellarMap;
    char *ch = new char[1040];
    char * pch;
	ifstream file;
    
	//open file
	file.open(fileName,ios::in);
	if(!file)
	{
		cout<<"Error in opening file!!!"<<endl;
	}
	
	//read and print file content
	while (!file.eof()) 
	{
		file.getline(ch,1040,',');	//reading from file
		//cout << ch << " ";	//printing
        int cost = atoi(ch);
        queueStellarMap.push(cost);
     
        
	}
	//close the file
	file.close();
   

    return queueStellarMap;
}
// Crear matriz de Adjacencia de acuerdo a la constelacion
void crearMatrizAdjacencia(std::vector<std::vector<int>> constelaciones){
    ofstream myFile;
    
    myFile.open("matrizAdjacencia.txt");
    myFile << "Matriz de Adjacencia" << endl;
    myFile << "Datos para crear matriz de Adjacencia" << endl;
    myFile << "Cantidad de vertices: " << constelaciones.size() << endl;
    myFile << "Cantidad de aristas: " << constelaciones.size()*(constelaciones.size()-1)/2 << endl;
    myFile << "Cantidad de campos conectados: " << constelaciones.size() << endl;

    myFile << "Matriz de Adjacencia" << endl;
    

   

    myFile.close();
    

    


}

void saveConstellationsHAMILTONTackMINIMA(std::vector<std::vector<int>> constelaciones){
    ofstream myFile;
    int counter = 0;
    myFile.open("constellationsHAMILTONminima<20.txt");
    myFile << "Constelcion Euler de costos menores a 20" << endl;
    

    for (vector<vector<int>>::iterator it = constelaciones.begin(); it != constelaciones.end(); ++it){
        myFile << "Nodos-conectados: ";
        for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2){
            myFile << " " << *it2;
            counter++;
        }
         
        myFile << endl;
    }
    myFile << "Cantidad de vertices: " << constelaciones.size() << endl;
    myFile << "Cantidad de aristas: " << constelaciones.size()*(constelaciones.size()-1)/2 << endl;
    myFile << "Cantidad de conecciones: " << counter << endl;

    myFile << "KA-" << constelaciones.size() << " "<< constelaciones.size()*(constelaciones.size()-1)/2<<" 2022" << endl;
    myFile.close();
}
void saveConstellationsEULERTackMINIMA(std::vector<std::vector<int>> constelaciones){
    ofstream myFile;
    int counter = 0;
    myFile.open("constellationsEULERminima<20.txt");
    myFile << "Constelcion Euler de costos menores a 20" << endl;
    myFile << "Datos para crear matriz de Adjacencia" << endl;

    for (vector<vector<int>>::iterator it = constelaciones.begin(); it != constelaciones.end(); ++it){
        myFile << "Nodos-conectados: ";
        for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2){
            myFile << " " << *it2;
            counter++;
        }
         
        myFile << endl;
    }
    myFile << "Cantidad de vertices: " << constelaciones.size() << endl;
    myFile << "Cantidad de aristas: " << constelaciones.size()*(constelaciones.size()-1)/2 << endl;
    myFile << "Cantidad de conecciones: " << counter << endl;

    myFile << "KA-" << constelaciones.size() << " "<< constelaciones.size()*(constelaciones.size()-1)/2<<" 2022" << endl;
    myFile.close();
}

