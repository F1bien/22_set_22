#include <stdio.h>



int CpyFile( char fileN_in[], char fileN_out[] ) {
	
	char buffer [100];
	int exit = 1;
	FILE * fileP_in = fopen(fileN_in, "r");
	FILE * fileP_out = fopen(fileN_out, "w");
	if ( fileP_in== NULL ) {
		printf("\nERRORE imposibile aprire file %s", fileN_in);
		exit = -1;
	}
	if ( fileP_out== NULL ) {
		printf("\nERRORE imposibile aprire file %s", fileN_out);
		exit = -1;
	}
	else {
		//printf("\nfile aperto\n");
		while ( !feof(fileP_in) ) {
			fgets(buffer, 1000, fileP_in);
			fprintf(fileP_out, buffer);
			
			//printf("%d %s\n", count, buffer);
		}
	}
	
	fclose(fileP_in);
	fclose(fileP_out);
	return exit;
}



int main () {
	
	printf("inserire nome file in ");
	char fileN_in[100];
	scanf("%s",fileN_in);
	printf("inserire nome file out ");
	char fileN_out[100];
	scanf("%s",fileN_out);
	int exit = CpyFile(fileN_in, fileN_out);
	
	
	return 0;
}

