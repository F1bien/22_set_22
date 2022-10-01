/*
	Scrivere una funzione che, ricevuti in ingresso i nomi di due file,
	effettui la copia carattere per carattere del primo file nel secondo file.
	La funzione restituisce true se la copia si e conclusa con successo,
	false in caso contrario.
	Utilizzare la funzione per copiare il file in.txt nel file out.txt.
*/

#include <stdio.h>

// funzione per copiare un file in un altro 
int CpyFile( char fileN_in[], char fileN_out[] ) { // come argomento vengono passati i nomi dei 2 file
	
	char buffer [100];
	int exit = 1;

	FILE * fileP_in = fopen(fileN_in, "r");// apertura del file in input avviene in read mod
	FILE * fileP_out = fopen(fileN_out, "w");// apertura del file per l' uotput avviene in write mod
	if ( fileP_in== NULL ) { // controlo se il file si e aperto
		printf("\nERRORE imposibile aprire file %s", fileN_in);
		exit = -1;
	}
	if ( fileP_out== NULL ) { // controlo se il file si e aperto
		printf("\nERRORE imposibile aprire file %s", fileN_out);
		exit = -1;
	}
	else { // file aperti coretamente
		//printf("\nfile aperto\n");
		while ( !feof(fileP_in) ) { // ciclo finche il file in input non finisce
			fgets(buffer, 1000, fileP_in); // legge il file in input
			fprintf(fileP_out, buffer); // scrive nel file per l' output
			
			//printf("%d %s\n", count, buffer);
		}
	}
	
	 // chiusura dei file
	fclose(fileP_in);
	fclose(fileP_out);
	return exit; // il risultato e 1 se la funzione e riusita a copiare i file altrimenti -1
}



int main () {
	
	printf("inserire nome file in ");
	char fileN_in[100];
	scanf("%s",fileN_in); // input nome del file in input da user 
	printf("inserire nome file out ");
	char fileN_out[100];
	scanf("%s",fileN_out);  // input nome del file in output da user 
	int exit = CpyFile(fileN_in, fileN_out);
	
	if ( exit == 1 ) { // stampa a video il risultato della funzione
		printf("\n\toperazione di copia riuscita coretamente");
	}
	else {
		printf("\n\toperazione falita");
	}



	return 0;
}
