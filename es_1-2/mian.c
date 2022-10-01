/*
	Scrivere una funzione che riceva in ingresso il nome di un file,
	ne stampi a video il contenuto.

	Ho svolto gli esercizi 1 e 2 insieme.
*/

#include <stdio.h>

// funzione per la stampa del contenuto del file
void printFile ( char fileN[] ) { // come argomento viene passato solo il nome del file
	
	// apertura del file in read mod
	FILE * fileP = fopen(fileN, "r");	
	if ( fileP == NULL ) { // controlo se il file si e aperto
		printf("ERRORE nel apertura file %s", fileN);
	}
	
	else { // file aperto coretamente
		//printf("file aperto");
		char buffer[100];
		while (!feof(fileP)) { // ciclo finche il file non finisce
			fgets(buffer, 100, fileP); // letura del file
			if( buffer != "\n\r" ) // controllo se del "buffer" e presente la newline
				printf("%s", buffer); // stampa a vide del contenuto del file
			
		}
	}
	
	
	fclose(fileP); // chiusura del file
}



int main () {
	
	printf("inserire nome file ");
	char fileN[100];
	scanf("%s",fileN); // input nome del file da user 
	printFile(fileN);
	
	return 0;
}

