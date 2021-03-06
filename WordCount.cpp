#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int CountWord (char *file)
{  
	FILE *fp;
    char buffer[5000];
    char c;
    int bufferlen=0;
    int LastComma = 0;
    int WordCount=0;
    int i;
    if((fp=fopen(file,"r"))==NULL)
	{
        printf("文件不能打开\n");
        exit(0);
    }
	while(fgets(buffer,1000,fp)!=NULL)
	{	
        bufferlen=strlen(buffer);
        for(i=0;i<bufferlen;i++)
		{
            c=buffer[i];
            if(c==' ' ||c==',')
			{
                if(LastComma==0)
				{
                    WordCount++;
                }
                LastComma=1;
            }
			else if(c!='\n'&&c!='\r')
			{
                LastComma=0;
            }
 
        } 
        if(LastComma==0)
            WordCount++;
        LastComma=1;
    }
    fclose(fp); 
		printf("WordNum:%d\n",WordCount);                     	
}
int CountChar (char *file)
	{   
		FILE *fp;
		int CharCount=0;
    	fp = fopen(file, "r");
    	char a;
    	if(NULL==(fp=fopen(file,"r")))
    		{
        		printf("文件为空");
    		}
    	while (!feof(fp))
    		{
        		a=fgetc(fp);
                	CharCount++;
    		}
    		
    	fclose(fp);
		printf("CharNum:%d ",CharCount-1);
	}
	
int main(int argc, char* argv[])             
{
    FILE *fp;
    while(1)
    {
    	if(strcmp(argv[1],"-h")&&strcmp(argv[1],"-w")&&strcmp(argv[1],"-c"))
    		{
            	printf("没用该功能\n!提示!\n-w 读出单词数量\n-c 读出字符数量\n"); 
            	return 0;
    		}
		if(!strcmp(argv[1],"-h"))
    		{
		    	printf("\n-w 读出单词数量\n-c 读出字符数量\n");
		    	return 0;
			}
        if((fp=fopen(argv[2],"r"))==NULL)
        	{  
        		printf("没用该文件\n\n\n");
        		scanf("%s%s%s",argv[0],argv[1],argv[2]);
        		continue;
        	}
        else if(!strcmp(argv[1],"-w")) 
        	{ 
        		CountWord (argv[2]);                
        	} 
		else if(!strcmp(argv[1],"-c"))  
        	{ 
				CountChar (argv[2]);     
        	} 
		printf("\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
    }
    return 0;
}
