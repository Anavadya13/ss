#include <stdio.h>
#include <string.h>
//Second pass of a two-pass assembler.
void main()
{
	int i,j,loc,len,reclen=0;
	char s,symnam[5],code[5],start[10],opcode[10],operand[10],symloc[10],mnemonic[10],a[20],b[20],count[20],label[20];
	FILE *fp_int,*fp_op,*fp_len,*fp_sy,*fp_opc,*fp_samp,*fp_read;
	fp_int=fopen("intermediate.txt","r");
	fp_len=fopen("length.txt","r");
	fp_op=fp_opc=fopen("optab.txt","r");
	fp_sy=fopen("symtab.txt","r");
	fp_samp=fopen("output.txt","w");
	printf("\nPass 2 of a two pass assembler:\n");
	printf("_______________________________\n\n");
	printf("Header Record:\t");
	fscanf(fp_int,"\t%s\t%s\t%s\n",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		strcpy(start,operand);
		fscanf(fp_len,"%d",&len);
	}
	printf("H^%s^00%s^0000%X\t",label,start,len);
	printf("\nText Record:\t");
	printf("T^00%s^",start);
	reclen+=6;
	fscanf(fp_int,"%d\t%s\t%s\t%s",&loc,label,opcode,operand);
	while(strcmp(opcode,"END")!=0)
	{
		fscanf(fp_op,"%s%s",mnemonic,code);
		while(!feof(fp_op))
		{
			if(strcmp(opcode,mnemonic)==0)
			{
				fscanf(fp_sy,"%s\t%s",symnam,symloc);
				while(!feof(fp_sy))
				{
					if(strcmp(operand,symnam)==0)
					{
						reclen+=6;
						fprintf(fp_samp,"%s%s^",code,symloc);
						break;
					}
					else
					{
						fscanf(fp_sy,"%s%s",symnam,symloc);
					}
				}
				break;
			}
			else
			{
				fscanf(fp_op,"%s%s",mnemonic,code);
			}
		}
		if((strcmp(opcode,"BYTE")==0)	|| (strcmp(opcode,"WORD")==0))
		{
			if(strcmp(opcode,"WORD")==0)
			{
				fprintf(fp_samp,"00000%s^",operand);
				reclen+=6;
			}
			else
			{
				for(i=0,j=2;j<strlen(operand)-1;i++,j++)
				{
					count[i]=operand[2];
				}
				count[i]='\0';
				while(!feof(fp_opc))
				{
					fscanf(fp_opc,"%s\t%s",a,b);
					if(strcmp(count,a)==0)
					{
						fprintf(fp_samp,"0000%s",b);
						reclen+=6;
					}
				}
			}
		}
		fscanf(fp_int,"%d%s%s%s",&loc,label,opcode,operand);
		fseek(fp_op,SEEK_SET,0);
		fseek(fp_sy,SEEK_SET,0);
	}	
	fclose(fp_samp);
	fp_read=fopen("sample.txt","r");
	printf("%X^",reclen/2);
	while((s=fgetc(fp_read))!=EOF)
	{
		printf("%c",s);
	}
	printf("\nEnd Record:\t");
	printf("E^00%s\n\n",start);
	fclose(fp_int);
	fclose(fp_op);
	fclose(fp_sy);
	fclose(fp_len);
	fclose(fp_read);
}