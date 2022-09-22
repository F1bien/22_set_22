#include <stdio.h>



int CountChar( char fileN[] ) {
	
	int count = 0;
	char buffer [100];
	FILE * fileP = fopen(fileN, "r");
	if ( fileP== NULL ) {
		printf("\nERRORE imposibile aprire file");
		count = -1;
	}
	else {
		//printf("\nfile aperto\n");
		while ( !feof(fileP) ) {
			count += fscanf(fileP,"%s", buffer);
			//printf("%d %s\n", count, buffer);
		
		}
	}
	
	fclose(fileP);
	return count+1;
}



int main () {
	
	printf("inserire nome file ");
	char fileN[100];
	scanf("%s",fileN);
	int count = CountChar(fileN);
	
	printf("\n%d\n", count);
	
	
	return 0;
}

