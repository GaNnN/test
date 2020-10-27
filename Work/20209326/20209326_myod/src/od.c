#include "od.h"

void od(char *argv[]){	//od函数
	FILE *fp;
	char ch;
	char str[16];
    int i=0;
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
			pm16(str);
		}
	}
	printf("%07d      ",k);
	pml(str,i);
	printf("\n%07d      \n",k+i%16);
	fclose(fp);
}

void pm16(char str[16]){	//处理字符个数能整除16的行的输出
	int j;
	for(j=0;j<16;j++){
		if((j+1)%4==0){
			printf("%02x%02x%02x%02x         ",str[j],str[j-1],str[j-2],str[j-3]);
		}
	}
	printf("\n");
	printf("	");
	for(j=0;j<16;j++){
		prc(str[j]);
	}
	printf("\n");
}

void pml(char str[16],int i){	//处理最后一行的输出
	int j;
	for(j=0;j<i;j++){
		if((j+1)%4==0){
			printf("%02x%02x%02x%02x         ",str[j],str[j-1],str[j-2],str[j-3]);
		} 
	}
	if((j+1)%4==0){
		printf("00%02x%02x%02x         ",str[j],str[j-1],str[j-2]);
	}else if((j+2)%4==0){
		printf("0000%02x%02x         ",str[j],str[j-1]);
	}else if((j+3)%4==0){
		printf("000000%02x         ",str[j]);
	}
	printf("\n");
	printf("	");
	for(j=0;j<i;j++){
		prc(str[j]);
	}
}

void prc(char ch){			//处理输出字符串
	if(ch=='\n'){
		printf(" \\n ");
	}else if(ch=='\t'){
		printf(" \\t ");
	}else if(ch=='\r'){
		printf(" \\r ");
	}else{
		printf("%4c",ch);
	}
}

