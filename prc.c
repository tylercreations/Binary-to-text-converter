#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXX 255

  int sizeOf(char *input);
  int lineLength(FILE *input);
  void convertText(char *input, char *output);
  void convertBinary(char *input, char *ouput);

  int sizeOf(char *input){
    
   int numLines = 0;
   int ch =0;
   FILE *fp = fopen(input, "r");
	/*error check*/
	if(!fp){
	printf("The given file cannot be opened \nsizeOf error\n");
	exit(1);
	}
	numLines++;
   while((ch = fgetc(fp)) != EOF){
	if(ch == '\n')
	numLines++;
	}
	
	fclose(fp);
	printf("The number of lines in this file is %d \n",numLines);
	return numLines;
  }



  int lineLength(FILE *input){
  
   int length = 0;
   int c;

   while(!feof(input)){
   	c = fgetc(input);
	if(c == '\t'){
	  break;
	}else {
	  length++;
	}
	
  }
	return length;
 }
    

  void convertText(char *input, char *output){
   int num;
    char buf[MAXX];
   int length = 0;
   int stringLength;
   size_t result;
   size_t result1;
   size_t result2;
   size_t result4;
   
  
	FILE *fp, *fp2;

	fp = fopen(input, "r");//error 
	if(!fp){printf("There was a problem opening the input file in convertText\n");exit(1);}

	fp2 = fopen(output, "wb");
	if(!fp2){printf("There was a problem opening the output file in convertText\n");exit(1);}
	
   
	while(!feof(fp)){
	
	  fscanf(fp,"%s %d",buf,&num);
	  length = strlen(buf);
	 unsigned char c = (unsigned char)length;
	


	result1 = fwrite((const void*)&c,1,1,fp2);//writing the length of the string as a byte
	

	   result = fwrite(buf,1,sizeof(buf),fp2);
		
	
		result2 = fwrite((const void*)&num,1,sizeof(int),fp2);
	
		}

	
	fclose(fp);
	fclose(fp2);
	}


  void convertBinary(char *input, char *output){
   
  char buf[MAXX];
  int num;
unsigned char length;
  size_t result;
  size_t result1;
  size_t result2;
  size_t result4;

  unsigned long fileLen;
  

	FILE *fpInput, *fpOutput;

	fpInput = fopen(input, "rb");
	if(!fpInput){printf("There was a problem opening file in convertBinary\n");exit(1);}

	fpOutput = fopen(output, "w");
	if(!fpOutput){printf("There was a problem opening the output file in convertBinary\n");exit(1);}

	//Get file length
	fseek(fpInput,0,SEEK_END);
	fileLen = ftell(fpInput);
	rewind(fpInput);
	//printf("The length of the file %d bytes \n",fileLen);

	int c;
	while(!feof(fpInput)){
	

	 result2 =  fread((void *)&length,1,1,fpInput);
	
	c = length;
	
	//printf("The length is [%d] \n",length);
	

	 result = fread(&buf,1,sizeof(buf),fpInput);
	//printf("This is what buf has read in [%s] \n",buf);
	 
	
	 result1 = fread((void *)&num,sizeof(int),1,fpInput);
	
	// printf("The num has read this in [%d] \n",num);

	
	//fwrite((const void*)&length,1,1,fpOutput);//is not printing the bytes to the 
	
	fwrite(buf,1,c,fpOutput);
	fprintf(fpOutput,"\t");
	
	//result4 = fwrite((const void*)&ch,1,sizeof(int),fpOutput);
	fprintf(fpOutput,"%d",num);
	fprintf(fpOutput,"\n");
	//printf("has written this element [%d][%d] \n",num,result4);
	
	
	}
	fclose(fpInput);
	fclose(fpOutput);
	
	}
	
	




