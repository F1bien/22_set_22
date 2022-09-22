#include <stdio.h>


void printFile ( char fileN[] ) {
	
	FILE * fileP = fopen(fileN, "r");	
	if ( fileP == NULL ) {
		printf("ERRORE nel apertura file %s", fileN);
	}
	
	else {
		//printf("file aperto");
		char buffer[100];
		while (!feof(fileP)) {
			fgets(buffer, 1000, fileP);
			if( buffer != "\n\r" )
				printf("%s", buffer);
			
		}
	}
	
	fclose(fileP);
}



int main () {
	
	printf("inserire nome file ");
	char fileN[100];
	scanf("%s",fileN);
	printFile(fileN);
	
	return 0;
}

