#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include<mmsystem.h>
struct person
{
    char name[35];
    char address[50];
    char father_name[35];
    char mother_name[30];
    char mble_no[12];
    char gen[8];
    char mail[100];
    char citision_no[20];
};
int repeat=0;
void menu();
void start();
void back();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();

int main()
{
	system("color 5f");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{	
    system("cls");
    struct tm* ptr;
	time_t t;
	t = time(NULL);
	ptr = localtime(&t);
	printf("%s", asctime(ptr));
    system("color 5f");
    printf("\n\t\t*****WELCOME TO PHONEBOOK****\n");
	printf("\t-----------------------------------------\n");
    printf("\n\n\t\t\t-----MENU-----\t\t\n\n");
    printf("\t1.Add New record   \t2.List of the record   \t3.Delete  \n\n\t4.Modify the record \t5.Search a record\t6.Exit\n\n\tPress your choice :");
    if(repeat==0){
    	PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\welcome.WAV"),NULL,SND_SYNC);
		repeat=1;
	}
	PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\choose.WAV"),NULL,SND_SYNC);
    switch (getch())
    {
    case '1':
        addrecord();
        break;
    case '2':
        listrecord();
        break;
    case '6':
    	system("cls");
    	system("color 4a");
    	printf("\n\t\tTEAM MEMBER");
    	printf("\n\t--------------------------\n");
    	printf("\n\t1.Sudheer Kumar\n\t2.Kunal Shaw\n\t3.Ritika Mishra\n\t4.Pavan Kumar\n\t5.Nitesh Kumar\n\t6.Swetashree Satapathy\n");
    	PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\exit0.WAV"),NULL,SND_SYNC);
    	printf("\n\tThank you for visiting\n");
    	PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\exit1.WAV"),NULL,SND_SYNC);
        exit(0);
        break;
    case '4':
        modifyrecord();
        break;
    case '5':
        searchrecord();
        break;
    case '3':
        deleterecord();
        break;
    default:
        system("cls");
        printf("\nEnter 1 to 6 only");
        printf("\n Enter any key");
        PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\menu.WAV"),NULL,SND_SYNC);
        getch();

        menu();
    }
}
void addrecord()
{
    system("cls");
    system("color 1f");
    PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\enter data.WAV"),NULL,SND_SYNC);
    FILE *f;
    struct person p;
    f = fopen("project.txt", "ab+");
    printf("\n Enter name: ");
    gets(p.name);
    printf("\nEnter the address: ");
    gets(p.address);
    printf("\nEnter father name: ");
    gets(p.father_name);
    printf("\nEnter mother name: ");
    gets(p.mother_name);
    printf("\nEnter Gender:");
    gets(p.gen);
    printf("\nEnter phone no.:");
    gets(p.mble_no);
    printf("\nEnter e-mail:");
    gets(p.mail);
    printf("\nEnter citizen no:");
    gets(p.citision_no);
    fwrite(&p, sizeof(p), 1, f);

    fflush(stdin);
    printf("\nrecord saved");
	PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\saved.WAV"),NULL,SND_SYNC);
    fclose(f);
	
    printf("\n\nEnter any key :");
	PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\menu.WAV"),NULL,SND_SYNC);
    getch();
    system("cls");
    menu();
}
void listrecord()
{	
	system("cls");
	system("color 0a");
	PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\save rec.WAV"),NULL,SND_SYNC);

    struct person p;
    FILE *f;
    f = fopen("project.txt", "rb");
    if (f == NULL)
    {
        printf("\nfile opening error in listing :");

        exit(1);
    }
    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nName=%s\nAdress=%s\nFather name=%s\nMother name=%s\nMobile no=%s\nGender=%s\nE-mail=%s\nCitizen no=%s", p.name, p.address, p.father_name, p.mother_name, p.mble_no, p.gen, p.mail, p.citision_no);

        getch();
        system("cls");
    }
    fclose(f);
    printf("\n Enter any key : ");
    PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\menu.WAV"),NULL,SND_SYNC);
    getch();
    system("cls");
    menu();
}
void searchrecord()
{
	system("cls");
	system("color 8f");
	PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\search.WAV"),NULL,SND_SYNC);
    struct person p;
    FILE *f;
    char name[100];

    f = fopen("project.txt", "rb");
    if (f == NULL)
    {
        printf("\n error in opening\a\a\a\a");
        exit(1);
    }
    printf("\nEnter name of person to search\n");
    gets(name);
    int m=0;
    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        if (strcmp(p.name, name) == 0)
        {
            printf("\n\tDetail Information About %s", name);
            printf("\nName:%s\naddress:%s\nFather name:%s\nMother name:%s\nMobile no:%s\nsex:%s\nE-mail:%s\nCitision no:%s", p.name, p.address, p.father_name, p.mother_name, p.mble_no, p.gen, p.mail, p.citision_no);
            PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\save rec.WAV"),NULL,SND_SYNC);
        	m++;
		}
    
           
    }
    if(m==0){
    printf("\nfile not found\n");
    PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\sorry.WAV"),NULL,SND_SYNC);
}
    fclose(f);
    printf("\n Enter any key");
	PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\menu.WAV"),NULL,SND_SYNC);
    getch();
    system("cls");
    menu();
}
void deleterecord()
{	system("cls");
	system("color 4f");
    struct person p;
    FILE *f, *ft;
    int flag;
    char name[100];
    f = fopen("project.txt", "rb");
    if (f == NULL)
    {

        printf("\nCONTACT'S DATA NOT ADDED YET.\n");
    }
    else
    {
        ft = fopen("temp.txt", "wb+");
        if (ft == NULL)

            printf("\nfile opaning error\n");
        else

        {

            printf("\n\n\tEnter CONTACT'S NAME:");
            PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\delete.WAV"),NULL,SND_SYNC);
            gets(name);

            fflush(stdin);
            while (fread(&p, sizeof(p), 1, f) == 1)
            {
                if (strcmp(p.name, name) != 0)
                    fwrite(&p, sizeof(p), 1, ft);
                if (strcmp(p.name, name) == 0)
                    flag = 1;
            }
            fclose(f);
            fclose(ft);
            if (flag != 1)
            {
                printf("\nNO CONACT'S RECORD TO DELETE.\n");
                PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\sorry.WAV"),NULL,SND_SYNC);
                remove("temp.txt");
            }
            else
            {
                remove("project.txt");
                rename("temp.txt", "project.txt");
                printf("RECORD DELETED SUCCESSFULLY.");
                PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\dels.WAV"),NULL,SND_SYNC);
            }
        }
    }
    printf("\n Enter any key");
	PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\menu.WAV"),NULL,SND_SYNC);
    getch();
    system("cls");
    menu();
}

void modifyrecord()
{
	system("color 0f");
    int c;
    FILE *f;
    int flag = 0;
    struct person p, s;
    char name[50];
    f = fopen("project.txt", "rb+");
    if (f == NULL)
    {

        printf("\nCONTACT'S DATA NOT ADDED YET.\nEnter any key to continue...");
        PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\menu.WAV"),NULL,SND_SYNC);
        getch();
        menu();
    }
    else
    {
        system("cls");
        printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
        PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\modify.WAV"),NULL,SND_SYNC);
        gets(name);
        while (fread(&p, sizeof(p), 1, f) == 1)
        {
            if (strcmp(name, p.name) == 0)
            {

                printf("\n Enter name:");
                gets(s.name);
                printf("\nEnter the address:");
                gets(s.address);
                printf("\nEnter father name:");
                gets(s.father_name);
                printf("\nEnter mother name:");
                gets(s.mother_name);
                printf("\nEnter gender:");
                gets(s.gen);
                printf("\nEnter phone no:");
                gets(s.mble_no);
                printf("\nEnter e-mail:");
                gets(s.mail);
                printf("\nEnter citizen no\n");
                gets(s.citision_no);
                fseek(f, sizeof(p), SEEK_CUR);
                fwrite(&s, sizeof(p), 1, f);
                flag = 1;
                break;
            }
            fflush(stdin);
        }
        if (flag == 1)
        {
            printf("\n your data id modified");
            PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\update.WAV"),NULL,SND_SYNC);
        }
        else
        {
            printf(" \n data is not found");
            PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\sorry.WAV"),NULL,SND_SYNC);
        }
        fclose(f);
    }
    printf("\n Enter any key");
    PlaySound(TEXT("C:\\Users\\dell\\OneDrive\\Documents\\C Code\\project folder\\menu.WAV"),NULL,SND_SYNC);
    getch();
    system("cls");
    menu();
}
