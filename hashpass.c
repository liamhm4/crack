#include <stdio.h>
#include <string.h>
#include "md5.h"
#include <stdlib.h>

int main(int argc, char *args[])
{
	FILE *in = fopen(args[1], "r");
	FILE *out = fopen(args[2], "w");
	
	if(!in || !out){
		printf("Error: cannot read input and output files.\n");
		exit(1);
	}
	
	
	char word[30];
	while(fgets(word, 30, in) != NULL){
		word[strlen(word)-1]='\0';
		char *hash = md5(word, strlen(word));
		fprintf(out,"%s\n",hash);
	}
	
	fclose(in);
	fclose(out);
	
	
	
	/*
	char *hash = md5(args[1], strlen(args[1]));
	printf("Hash: %s\n", hash);
	free(hash);
	*/
}