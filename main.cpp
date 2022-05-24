#include "Graph.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stdio.h>

using namespace std;

queue<int> uploadStellarMap(string fileName);
void saveConstellationsTack(string fileName);

int main(){

    Graph<int, int> myGraph(2);
    queue<int> queueStellarMap;
    char matrixAdj[29][29];


    /*
    
    myGraph.agregarArista(2, 3);
    myGraph.agregarArista(2, 3);
    myGraph.agregarArista(2, 4, 0, 1);
    myGraph.agregarArista(2, 4, 3);
    cout << myGraph.printGraph();

    Graph<int> grafo(1);
    grafo.agregarArista(1, 2);
    grafo.agregarArista(1, 6);
    grafo.agregarArista(2, 3);
    grafo.agregarArista(2, 4);
    grafo.agregarArista(3, 4);
    grafo.agregarArista(5, 4);
    grafo.agregarArista(6, 5);
    cout << grafo.printGraph();
    cout<<grafo.cantidadCamposConectados()<<endl;
   */

    cout<<"Hello the Stellar Traker program"<<endl;
//Cargando Mapa estelar
    queueStellarMap = uploadStellarMap("stellarMap.txt");

//Creando matriz de adya
    for(int filas = 0; filas < 28; filas++){

        for (int columnas = 0; columnas < 28; columnas++){
            matrixAdj[filas][columnas] = queueStellarMap.front();
            cout << queueStellarMap.front() << " ";
            queueStellarMap.pop();
            
        }
        cout << endl;
    }


//Creando grafo

//Buscando constelaciones

    
    


  
   
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

void saveConstellationsTack(string fileName){
    fstream newfile;
    newfile.open(fileName,ios::out);  // open a file to perform write operation using file object
    if(newfile.is_open())     //checking whether the file is open
    {
        newfile<<"Tutorials point \n"; //inserting text
        newfile.close(); //close the file object
    }
    newfile.open(fileName,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;
        while(getline(newfile, tp)){  //read data from file object and put it into string.
            cout << tp << "\n";   //print the data of the string
        }
        newfile.close();   //close the file object.
    }
}

