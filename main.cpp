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
    cout << myGraph.printGraph();

    
    //Buscando constelaciones

    //Constelaciones Euler 20



    cout << myGraph.printBFS(0);
    cout << myGraph.printDFS(0);
    cout << myGraph.getDirigido();

    cout << endl;
    cout << endl;

    cout << "Dijkstra de 0"<<endl;
    map<int, pair<int, int >> dijkstraReult;
    dijkstraReult = myGraph.dijkstra(0);
    for (map<int, pair<int, int >>::iterator it = dijkstraReult.begin(); it != dijkstraReult.end(); ++it){
        cout << "| " << it->first << ": (" << it->second.first << ", [" << it->second.second << "]) |" << endl;
    }

    cout << endl;
    cout << endl;

    cout << "Prim de 0"<<endl;
    vector<int> myGraphPim = myGraph.prim(0);
    for (vector<int>::iterator it = myGraphPim.begin(); it != myGraphPim.end(); ++it){
        cout << *it << " ";
    }

    cout << endl;
    cout << endl;

    


  
   
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

