#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc,char *argv[])
{
	FILE *fp;
	char ch;
	char str[16];
    int i=0,j;
	int k=0;
	if((fp = fopen(argv[1],"r"))==NULL)
	{
		printf("Failure to open %s !\n",argv[0]);
		exit(0);
	}
	while((ch=fgetc(fp))!=EOF)
	{
		str[i]=ch;
		i++;
		if(i==16)
		{
			i=0;
			printf("%07d      ",k);
			k+=20;
            for(j=0;j<16;j++){
				if((j+1)%4==0){
					printf("%02x%02x%02x%02x         ",str[j],str[j-1],str[j-2],str[j-3]);
				}
			}
			printf("\n");
			printf("	");
			for(j=0;j<16;j++){
				if(str[j]=='\n'){
					printf(" \\n ");
				}else if(str[j]=='\t'){
					printf(" \\t ");
				}else if(str[j]=='\r'){
					printf(" \\r ");
				}else{
					printf("%4c",str[j]);
				}
			}
			printf("\n");
		}
	}
	printf("%07d      ",k);
	for(j=0;j<i;j++){
		if((j+1)%4==0){
			printf("%02x%02x%02x%02x         ",str[j],str[j-1],str[j-2],str[j-3]);
		} 
	}
	if((j+1)%4==0){
		printf("00%02x%02x%02x         ",str[j],str[j-1],str[j-2]);
	}else if((j+2)%4==0){
		printf("0000%02x%02x         ",str[j],str[j-1]);
	}else if(j%3==0){
		printf("000000%02x         ",str[j]);
	}
	printf("\n");
	printf("	");
	for(j=0;j<i;j++){
		if(str[j]=='\n'){
			printf(" \\n ");
		}else if(str[j]=='\t'){
			printf(" \\t ");
		}else if(str[j]=='\r'){
			printf(" \\r ");
		}else{
			printf("%4c",str[j]);
		}
	}
	printf("\n%07d      \n",k+i%16);
	fclose(fp);
	return 0;
}

