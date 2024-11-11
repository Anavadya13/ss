#include <stdio.h>
#include <string.h>
void masktobit(char bitmaskbit[12]);
char bitmask[12];
char bits[12]={0};
void main()
{
    FILE *fp_in,*fp_ou;
    char input[10],binary[12],relocbit,ch,ctrlsec[6];
    int start,masklen,i,texaddr,opcode,opaddr,realaddr,texlen,straddr[6],oblen[10],copytexlen,counter=0;
    printf("\n\nSIC RELOCATING LOADER WITH BIT MASK\n");
    printf("\nEnter the address to which object program should be relocated: ");
    scanf("%x",&start);
    fp_in=fopen("objcode.txt","r");
    fp_ou=fopen("output.txt","w");
    fscanf(fp_in,"%s",input);
    fprintf(fp_ou,"---------------------------------------\n");
    fprintf(fp_ou,"RELOCATED ADDRESS\t\tCONTENT\n");
    fprintf(fp_ou,"---------------------------------------\n");
    while(strcmp(input,"E")!=0)
    {
        if(strcmp(input,"H")==0)
        {
            fscanf(fp_in,"%s",ctrlsec);
            fscanf(fp_in,"%x",straddr);
            fscanf(fp_in,"%x",oblen);
            fscanf(fp_in,"%s",input);
        }
        if(strcmp(input,"T")==0)
        {
            fscanf(fp_in,"%x",&texaddr);
            fscanf(fp_in,"%x",&texlen);
            fscanf(fp_in,"%s",bitmask);
            copytexlen=texlen/3;
            texaddr+=start;
            masktobit(bitmask);
            masklen=strlen(bits);
            if(masklen>=12)
            masklen=10;
            counter=0;
            if(masklen>copytexlen)
            {
                for(i=0;i<=copytexlen;i++)
                {
                    fscanf(fp_in,"%x",&opcode);
                    if(opcode==241)
                    {
                        fprintf(fp_ou,"\n%x\t\t\t\t",texaddr);
                        fprintf(fp_ou,"%x\n",opcode);
                        texaddr++;
                        i++;
                        fscanf(fp_in,"%x",&opcode);
                    }
                    if(opcode==5)
                    {
                        fprintf(fp_ou,"\n%x\t\t\t\t",texaddr);
                        fprintf(fp_ou,"0%x\n",opcode);
                        texaddr++;
                        i++;
                        break;
                    }
                    fscanf(fp_in,"%x",&opaddr);
                    relocbit=bits[i];
                    if(relocbit=='0')
                    realaddr=opaddr;
                    else
                    realaddr=opaddr+start;
                    fprintf(fp_ou,"\n%x\t\t\t\t",texaddr);
                    if(opcode==0)
                    fprintf(fp_ou,"00");
                    else if(opcode==1)
                    fprintf(fp_ou,"01");
                    else if(opcode==2)
                    fprintf(fp_ou,"02");
                    else if(opcode==3)
                    fprintf(fp_ou,"03");
                    else if(opcode==4)
                    fprintf(fp_ou,"04");
                    else if(opcode==6)
                    fprintf(fp_ou,"06");
                    else if(opcode==7)
                    fprintf(fp_ou,"07");
                    else if(opcode==8)
                    fprintf(fp_ou,"08");
                    else if(opcode==9)
                    fprintf(fp_ou,"09");
                    else if(opcode==10)
                    fprintf(fp_ou,"0A");
                    else if(opcode==11)
                    fprintf(fp_ou,"0B");
                    else if(opcode==12)
                    fprintf(fp_ou,"0C");
                    else if(opcode==13)
                    fprintf(fp_ou,"0D");
                    else if(opcode==14)
                    fprintf(fp_ou,"0E");
                    else if(opcode==15)
                    fprintf(fp_ou,"0F");
                    else
                    fprintf(fp_ou,"%x",opcode);
                    if(realaddr==0)
                    fprintf(fp_ou,"0000\n");
                    else
                    if(realaddr==3)
                    fprintf(fp_ou,"0003\n");
                    else
                    fprintf(fp_ou,"%x\n",realaddr);
                    texaddr+=3;
                }
            }
            if(masklen<=copytexlen)
            {
                for(i=0;i<masklen;i++)
                {
                    fscanf(fp_in,"%x",&opcode);
                    fscanf(fp_in,"%x",&opaddr);
                    counter++;
                    relocbit=bits[i];
                    if(relocbit=='0')
                    realaddr=opaddr;
                    else
                    realaddr=opaddr+start;
                    fprintf(fp_ou,"\n%x\t\t\t\t",texaddr);
                    if(opcode==0)
                    fprintf(fp_ou,"00");
                    else if(opcode==1)
                    fprintf(fp_ou,"01");
                    else if(opcode==2)
                    fprintf(fp_ou,"02");
                    else if(opcode==3)
                    fprintf(fp_ou,"03");
                    else if(opcode==4)
                    fprintf(fp_ou,"04");
                    else if(opcode==6)
                    fprintf(fp_ou,"06");
                    else if(opcode==7)
                    fprintf(fp_ou,"07");
                    else if(opcode==8)
                    fprintf(fp_ou,"08");
                    else if(opcode==9)
                    fprintf(fp_ou,"09");
                    else if(opcode==10)
                    fprintf(fp_ou,"0A");
                    else if(opcode==11)
                    fprintf(fp_ou,"0B");
                    else if(opcode==12)
                    fprintf(fp_ou,"0C");
                    else if(opcode==13)
                    fprintf(fp_ou,"0D");
                    else if(opcode==14)
                    fprintf(fp_ou,"0E");
                    else if(opcode==15)
                    fprintf(fp_ou,"0F");
                    else
                    fprintf(fp_ou,"%x",opcode);
                    if(realaddr==0)
                    fprintf(fp_ou,"0000\n");
                    else if(realaddr==3)
                    fprintf(fp_ou,"0003\n");
                    else
                    fprintf(fp_ou,"%x\n",realaddr);
                    texaddr+=3;
                }
            }
            while((copytexlen>masklen) && (counter!=copytexlen))
            {
                fscanf(fp_in,"%x",&opcode);
                fscanf(fp_in,"%x",&opaddr);
                realaddr=opaddr;
                fprintf(fp_ou,"\n%x\t\t\t\t",texaddr);
                if(opcode==0)
                fprintf(fp_ou,"00");
                else if(opcode==1)
                fprintf(fp_ou,"01");
                else if(opcode==2)
                fprintf(fp_ou,"02");
                else if(opcode==3)
                fprintf(fp_ou,"03");
                else if(opcode==4)
                fprintf(fp_ou,"04");
                else if(opcode==6)
                fprintf(fp_ou,"06");
                else if(opcode==7)
                fprintf(fp_ou,"07");
                else if(opcode==8)
                fprintf(fp_ou,"08");
                else if(opcode==9)
                fprintf(fp_ou,"09");
                else if(opcode==10)
                fprintf(fp_ou,"0A");
                else if(opcode==11)
                fprintf(fp_ou,"0B");
                else if(opcode==12)
                fprintf(fp_ou,"0C");
                else if(opcode==13)
                fprintf(fp_ou,"0D");
                else if(opcode==14)
                fprintf(fp_ou,"0E");
                else if(opcode==15)
                fprintf(fp_ou,"0F");
                else
                fprintf(fp_ou,"%x",opcode);
                if(realaddr==0)
                fprintf(fp_ou,"0000\n");
                else if(realaddr==3)
                fprintf(fp_ou,"0003\n");
                else
                fprintf(fp_ou,"%x\n",realaddr);
                texaddr+=3;
                counter++;
            }
            fscanf(fp_in,"%s",input);
        }
    }
    fprintf(fp_ou,"---------------------------------------\n");
    fclose(fp_in);
    fclose(fp_ou);
    printf("\n\nAfter relocation:\n\n");
    fp_ou=fopen("output.txt","r");
    ch=fgetc(fp_ou);
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch=fgetc(fp_ou);
    }
    fclose(fp_ou);
}
void masktobit(char bitmaskbit[12])
{
    int i,size;
    strcpy(bits,"");
    size=strlen(bitmaskbit);
    for(i=0;i<size;i++)
    {
        switch(bitmaskbit[i])
        {
            case '0':
            strcat(bits,"0");
            break;
            case '1':
            strcat(bits,"1");
            break;
            case '2':
            strcat(bits,"10");
            break;
            case '3':
            strcat(bits,"11");
            break;
            case '4':
            strcat(bits,"100");
            break;
            case '5':
            strcat(bits,"101");
            break;
            case '6':
            strcat(bits,"110");
            break;
            case '7':
            strcat(bits,"111");
            break;
            case '8':
            strcat(bits,"1000");
            break;
            case '9':
            strcat(bits,"1001");
            break;
            case 'A':
            strcat(bits,"1010");
            break;
            case 'B':
            strcat(bits,"1011");
            break;
            case 'C':
            strcat(bits,"1100");
            break;
            case 'D':
            strcat(bits,"1101");
            break;
            case 'E':
            strcat(bits,"1110");
            break;
            case 'F':
            strcat(bits,"1111");
            break;
        }
    }
}