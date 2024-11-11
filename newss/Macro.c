#include <stdio.h>
#include <string.h>
//Program for a one-pass macro processor.
void main()
{
    FILE *fp_in,*fp_nam,*fp_def,*fp_arg,*fp_ou;
    int len,i,pos=1;
    char arg[20],mne[20],op[20],label[20],macnam[20],mne1[20],op1[20],str1[20],str2[20];
    fp_in=fopen("input.txt","r");
    fp_nam=fopen("namtab.txt","w+");
    fp_def=fopen("deftab.txt","w+");
    fp_arg=fopen("argtab.txt","w+");
    fp_ou=fopen("output.txt","w");
    fscanf(fp_in,"%s\t%s\t%s",label,mne,op);
    while(strcmp(mne,"END")!=0)
    {
        if(strcmp(mne,"MACRO")==0)
        {
            printf("\nInside MACRO\n");
            fprintf(fp_nam,"%s\n",label);
            fseek(fp_nam,SEEK_SET,0);
            fprintf(fp_def,"%s\t%s\n",label,op);
            printf("Entering macro prototype in DEFTAB\n");
            fscanf(fp_in,"%s\t%s\t%s",label,mne,op);
            while(strcmp(mne,"MEND")!=0)
            {
                if(op[0]=='&')
                {
                    sprintf(str1,"%d",pos);
                    strcpy(str2,"?");
                    strcpy(op,strcat(str2,str1));
                    pos+=1;
                }
                fprintf(fp_def,"%s\t%s\n",mne,op);
                printf("Entering macro definition in DEFTAB\n");
                fscanf(fp_in,"%s\t%s\t%s",label,mne,op);
            }
            printf("Reached MEND\n");
            fprintf(fp_def,"%s",mne);
        }
        else
        {
            fscanf(fp_nam,"%s",macnam);
            if(strcmp(mne,macnam)==0)
            {
                len=strlen(op);
                for(i=0;i<len;i++)
                {
                    if(op[i]!=',')
                    {
                        fprintf(fp_arg,"%c",op[i]);
                    }
                    else
                    {
                        fprintf(fp_arg,"\n");
                    }
                }
                fseek(fp_def,SEEK_SET,0);
                fseek(fp_arg,SEEK_SET,0);
                fprintf(fp_ou,"**\t.%s\t%s\n",mne,op);
                printf("\nEntering commented macro invocation statement\n");
                printf("**\t.%s\t%s\n",mne,op);
                fscanf(fp_def,"%s%s",mne1,op1);
                while(strcmp(mne1,"MEND")!=0)
                {
                    if(op1[0]=='?')
                    {
                        fscanf(fp_arg,"%s",arg);
                        fprintf(fp_ou,"**\t%s\t%s\n",mne1,arg);
                        printf("\nReplace arguements in input\n");
                        printf("**\t%s\t%s\n",mne1,arg);
                    }
                    else
                    {
                        if(op1[0]!='&')
                        {
                            fprintf(fp_ou,"**\t%s\t%s\n",mne1,op1);
                            printf("**\t%s\t%s\n",mne1,op1);
                        }
                    }
                    fscanf(fp_def,"%s%s",mne1,op1);
                }
            }
            else
            {
                fprintf(fp_ou,"%s\t%s\t%s\n",label,mne,op);
                printf("\nLine from input code\n");
                printf("%s\t%s\t%s\n",label,mne,op);
            }
        }
        fscanf(fp_in,"%s\t%s\t%s",label,mne,op);
    }
    printf("\nLine from input code\n");
    fprintf(fp_ou,"%s\t%s\t%s\n",label,mne,op);
    printf("%s\t%s\t%s\n\n",label,mne,op);
    fclose(fp_in);
    fclose(fp_nam);
    fclose(fp_def);
    fclose(fp_arg);
    fclose(fp_ou);
}