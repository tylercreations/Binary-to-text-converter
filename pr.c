#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

  int main(int argc, char* argv[]){

  
  int c,size;
  int length;
  char ch;
  size_t result;
  int length4 = 4;
  int length3 = 3;
	
	FILE *input;

	input = fopen(argv[2], "r");
	if(!input){
	printf("There was an error and the Input file cannot be opened\n");
	exit(1);
	}

	
	printf("The number of args is %d \n",argc);
	if(strcmp("-t", argv[1]) == 0)
	{

	if(argc > length4){
	printf("STOP you have entered too many arguments\nthe format\nfor this program is");
	printf("\nrun-command\t-t\tinputfile\toutputfile \n");
	exit(1);
	}
	  //run
	  size = sizeOf(argv[2]);
	  length = lineLength(input);
	  convertText(argv[2],argv[3]);
	}
	
	else if(strcmp("-s", argv[1]) == 0)
	{
	  if(argc > length3){
	printf("STOP you have entered too many arguments\nthe format\nfor this program is");
	printf("\nrun-command\t-s\tinputfile\toutputfile \n");
	exit(1);
	}
	  sF(argv[2]);
	}

	else if(strcmp("-b", argv[1]) == 0)//yes
	{
	  //run
	if(argc > length4){
	printf("STOP you have entered too many arguments\nthe format\nfor this program is");
	printf("\nrun-command\t-b\tinputfile\toutputfile \n");
	exit(1);
	}
	 size = sizeOf(argv[2]);
	  length = lineLength(input);
	 convertBinary(argv[2],argv[3]);
	}
	 
	else{
	//undefined exiting program
	printf("COMMAND UNCLEAR \n%s is not an appropriate command \nUser must enter -t or -b or -s \n",argv[1]);
	exit(1);
	}
	
	fclose(input);
	
	return 0;
  }








	
