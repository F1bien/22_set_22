#include <stdio.h>



int Cpyto( char fileN_1[], char fileN_2[] ) {
	
	char buffer [100];
	int exit = 1;
	FILE * fileP_1 = fopen(fileN_1, "r");
	FILE * fileP_2 = fopen(fileN_2, "a");
	if ( fileP_1== NULL ) {
		printf("\nERRORE imposibile aprire file %s", fileN_1);
		exit = -1;
	}
	if ( fileP_2== NULL ) {
		printf("\nERRORE imposibile aprire file %s", fileN_2);
		exit = -1;
	}
	else {
		//printf("\nfile aperto\n");
		fprintf(fileP_2, " ");
		while ( !feof(fileP_1) ) {
			fgets(buffer, 1000, fileP_1);
			fprintf(fileP_2, buffer);
			
			//printf("%d %s\n", count, buffer);
		}
	}
	
	fclose(fileP_1);
	fclose(fileP_2);
	return exit;
}



int main () {
	
	printf("inserire nome file 1 ");
	char fileN_1[100];
	scanf("%s",fileN_1);
	printf("inserire nome file 2 ");
	char fileN_2[100];
	scanf("%s",fileN_2);
	int exit = Cpyto(fileN_1, fileN_2);
	
	
	return 0;
}

