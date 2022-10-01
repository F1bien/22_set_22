/*
	Scrivere una funzione che, ricevuto in ingresso il nome di un file,
	restituisca il conteggio dei caratteri presenti al suo interno.
	oppure -1 nel caso in cui non sia possibile accedere al file.

	nel programa non ho condiderato nella conta gli spazi

*/

#include <stdio.h>

// funzione èer contrare i careteri al interno di un file
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
		while ( fscanf(fileP,"%s", buffer) > 0 ) { // ciclo finche il file non finisce
			count += strlen(buffer); // nella funzione strlen() viene pasato la stringa
									 //e restituisce il numero di caratteri 
			//printf("%d %s\n", count, buffer);
		
		}
	}
	
	fclose(fileP); // chiusura del file
	return count; // la funzione restituisce il numero di caratteri
}



int main () {
	
	printf("inserire nome file ");
	char fileN[100];
	scanf("%s",fileN); // input nome del file da user 
	int count = CountChar(fileN);
	
	printf("\n%d\n", count); // stampa a video del numero di caratteri
	
	return 0;
}

