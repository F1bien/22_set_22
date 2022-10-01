/*
	Dopo aver creato due file di testo parole1.txt e parole2.txt,
	ciascuno contenente un elenco di parole separate da uno spazio,
	scrivere un programma che accodi il contenuto del primo file
	al secondo file.
	Alla fine dell' esecuzione,
	osservare il contenuto del secondo file con un editor testuale.
*/

#include <stdio.h>

// funzione per aggiungere il contenuto di un file ad un altro
int Cpyto( char fileN_1[], char fileN_2[] ) { // come argomento vengono passati i nomi dei 2 file
	
	char buffer [100];
	int exit = 1;
	FILE * fileP_1 = fopen(fileN_1, "r");// apertura del file in input avviene in read mod
	FILE * fileP_2 = fopen(fileN_2, "a");// apertura del file per l' uotput avviene in append mod
	if ( fileP_1== NULL ) { // controlo se il file si e aperto
		printf("\nERRORE imposibile aprire file %s", fileN_1);
		exit = -1;
	}
	if ( fileP_2== NULL ) { // controlo se il file si e aperto
		printf("\nERRORE imposibile aprire file %s", fileN_2);
		exit = -1;
	}

	else { // file aperti coretamente
		//printf("\nfile aperto\n");
		fprintf(fileP_2, " ");
		while ( !feof(fileP_1) ) { // ciclo finche il file in input non finisce
			fgets(buffer, 1000, fileP_1); // legge il file in input
			fprintf(fileP_2, buffer); // scrive nel file per l' output
			
			//printf("%d %s\n", count, buffer);
		}
	}
	
	 // chiusura dei file
	fclose(fileP_1);
	fclose(fileP_2);
	return exit; // il risultato e 1 se la funzione e riusita a copiare i file altrimenti -1
}



int main () {
	
	printf("inserire nome file 1 ");
	char fileN_1[100];
	scanf("%s",fileN_1); // input nome del file in input da user 
	printf("inserire nome file 2 ");
	char fileN_2[100];
	scanf("%s",fileN_2); // input nome del file in output da user 
	int exit = Cpyto(fileN_1, fileN_2);
	
	if ( exit == 1 ) { // stampa a video il risultato della funzione
		printf("\n\toperazione di aggiungere riuscita coretamente");
	}
	else {
		printf("\n\toperazione falita");
	}
	

	
	return 0;
}

