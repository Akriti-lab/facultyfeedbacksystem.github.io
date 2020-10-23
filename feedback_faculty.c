#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define size 1000
void admin();
void student();
void faculty();
int main()
{
    int choice;
    char c,c1;
    FILE *p;
    p=fopen("c:\\mini_project\\view.txt","r");
    if(p==NULL)
    {
        printf("File not found\n");
        exit(0);
    }
    c1=fgetc(p);
    while(c1 !=EOF)
    {
        printf("%c",c1);
        c1=fgetc(p);
    }
    fclose(p);
    getchar();
    while(1)
    {
        FILE *fptr;
        fptr=fopen("c:\\mini_project\\choice.txt" ,"r");
        if(fptr==NULL)
        {
            printf("Unable to open file \n");
            exit(0);
        }
        c = fgetc(fptr);
        while(c != EOF)
        {
            printf("%c",c);
            c=fgetc(fptr);
        }
        fclose(fptr);
        printf("\n\nPlease enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                admin();
                break;
            case 2:
                student();
                break;
            case 3:
                faculty();
                break;
                default:exit(0);
        }
    }
    return 0;
}
void student()
{
    int i=0,len1,len2;
    char array1[1000],array2[1000],username[50],password[50];
    printf("\nEnter details\n");
    printf("\nUser name:");
    scanf("%s",username);
    printf("\nEnter Password:");
    scanf("%s",&password);
    len1=strlen(username);
    len2=strlen(password);
    FILE *fp;
    fp=fopen("c:\\login_details.txt","r");
    while(!feof(fp))
    {
        int c = fgetc(fp);
        if(c==EOF)
            break;
        if(c==username[0])
        {
            do
            {
                array1[i++]=c;
                c=fgetc(fp);
            }while(!feof(fp)&&i<len1&&i<1000);
            array1[i]='\0';
            if(strcmp(array1,username)==0)
                printf("Successful\n");
            else
                printf("Unsuccessful\n");
        }
    }
}
void admin()
{
    int m;
    FILE *pp,*p,*fpp;
    char data[size],c,c1,c2,array1[1000],array2[1000],username[50],password[50];
    int i=0,len1,len2,re=0;
    printf("\nEnter details\n");
    printf("\nUser name:");
    scanf("%s",&username);
    printf("\nEnter Password:");
    scanf("%s",&password);
    len1=strlen(username);
    len2=strlen(password);
    FILE *fp;
    fp=fopen("c:\\login_details.txt","r");
    while((c=fgetc(fp))!=EOF)
    {
        i=0;
        if(c==username[0])
        {
            do
            {
                array1[i++]=c;
                c=fgetc(fp);
            }while(!feof(fp)&&i<len1&&i<1000);
            array1[i]='\0';
            if(strcmp(array1,username)==0)
                {printf("Successful\n");re=1;}
            else
               {printf("Unsuccessful\n");re=0;}
        }
    }
    while(re==1)
    {
        printf("\nEnter choice\n1. Add\n2. Read\n3.Exit");
        scanf("%d",&m);
        switch(m)
        {
            case 1:
               {
                p=fopen("c:\\mini_project\\login_details.txt","a");
                if(p==NULL)
                {
                    printf("Unable to open file\n");
                    exit(0);
                }
                else
                {
                printf("Enter students details:\n");
                fgets(data,size,stdin);
                fputs(data,p);
                fclose(p);
                }
               }
                break;
            case 2:
                {
                pp=fopen("c:\\mini_project\\faculty.txt","r");
                if(pp==NULL)
                {
                    printf("Unable to open file \n");
                    exit(0);
                }
                c = fgetc(pp);
                while(c != EOF)
                {
                    printf("%c",c);
                    c = fgetc(pp);
                }
                fclose(pp);
                fpp = fopen("c:\\mini_project\\login_details.txt","r");
                if(fpp == NULL)
                {
                    printf("Unable to open file\n");
                    exit(0);
                }
                c1 = fgetc(fpp);
                while(c1 != EOF)
                {
                    printf("%c",c1);
                    c1 = fgetc(fpp);
                }
                fclose(fpp);
                }
                case 3:exit(1);
        }
    }
}
void faculty()
{
    char c;
    FILE *fptr;
    fptr=fopen("c:\\mini_project\\faculty.txt","r");
    if(fptr==NULL)
        {
            printf("Unable to open file \n");
            exit(0);
        }
        c = fgetc(fptr);
        while(c != EOF)
        {
            printf("%c",c);
            c=fgetc(fptr);
        }
        printf("\n");
        fclose(fptr);
}
