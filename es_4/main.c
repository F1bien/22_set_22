/*
	Un file di testo contiene un certo numero di parole.
	Ogni parola (a eccezione dell ultima)
	e separata da quella successiva da un solo carattere di whitespace.
*/

#include <stdio.h>

// funzione per contrare le parole al interno di un file
int CountChar( char fileN[] ) { // come argomento viene passato solo il nome del file
	
	int count = 0;
	char buffer [100];
	// apertura del file in read mod
	FILE * fileP = fopen(fileN, "r");
	if ( fileP== NULL ) { // controlo se il file si e aperto
		printf("\nERRORE imposibile aprire file");
		count = -1;
	}

	else { // file aperto coretamente
		//printf("\nfile aperto\n");
		while ( !feof(fileP) ) { // ciclo finche il file non finisce
			count += fscanf(fileP,"%s", buffer); // incremanta count ogni volta che legge una
												 // parola separate da uno spazio o newline
			//printf("%d %s\n", count, buffer);
		
		}
	}
	
	fclose(fileP); // chiusura del file
	return count+1; // la funzione restituisce il numero di parole
}



int main () {
	
	printf("inserire nome file ");
	char fileN[100];
	scanf("%s",fileN); // input nome del file da user 
	int count = CountChar(fileN);
	
	printf("\n%d\n", count); // stampa a video del numero di parole
	
	
	return 0;
}

