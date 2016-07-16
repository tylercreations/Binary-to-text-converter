#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXX 255

 void sF(char *input){
   
  char buf[MAXX];
  int num;
unsigned char length;
  size_t result;
  size_t result1;
  size_t result2;
  size_t result4;
  unsigned long fileLen;

  int numSize = 0;
  int longestEnteredString = 0;
  int shortestEnteredString = 1;
  int maximumInteger = 0;
  int minimumInteger = 1;

	FILE *fpInput, *fpOutput;

	fpInput = fopen(input, "rb");
	if(!fpInput){printf("There was a problem opening file in sF\n");exit(1);}

	
	//Get file length
	fseek(fpInput,0,SEEK_END);
	fileLen = ftell(fpInput);
	rewind(fpInput);
	
	while(!feof(fpInput)){
	

	fread((void *)&length,1,1,fpInput);

	if(longestEnteredString < length){
	longestEnteredString = length;
	}

	if(shortestEnteredString > length){
	shortestEnteredString = length;
	}


	fread(&buf,1,sizeof(buf),fpInput);
	
	fread((void *)&num,sizeof(int),1,fpInput);
		
	if(maximumInteger < num){
	maximumInteger = num;
	}

	if(minimumInteger > num){
	minimumInteger = num;
	}
	
	

	
	
	
	}
	printf("The length of the longest entered string is %d  \n",longestEnteredString);
	printf("The length of the shortest entered string is %d  \n",shortestEnteredString);
	printf("The value of the maximum integer entered string is %d  \n",maximumInteger);
	printf("The value of the minimum integer entered string is %d  \n",minimumInteger);
	fclose(fpInput);
	
	
	}
