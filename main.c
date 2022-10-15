
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
time_t t;

void menu();
void staff_menu();
void student_menu();
void new1_entry();
void view_all();
void edit();
void delete_record();
void view_student();

struct datedob
{
    int date,month,year;
};

struct details
{
    char name[50];
    int usn;
    char father_name[50];
    long phone_no;
    long father_no;
    struct datedob dob;
    char address[100];
    int year_of_adm;
    char email[50];
    int year;
    char branch[50];
    char section[1];
    int room_no;
    char code[10];
}new1,v,e,del,check,upd;

void main()
{
    sleep(2);
    printf("\t\t\tW        W   EEEEE    L      CCC    OOO    M     M    EEEEE");
    printf("\n\t\t\t W  W  W     EEEE     L     C       O O    M  M  M    EEEE");
    printf("\n\t\t\t  W   W      EEEEE    LLL    CCC    OOO    M     M    EEEEE\n\n");
    printf("\t\t\t\t      TO THE HOSTEL MANAGEMENT SYSTEM!!\n\n");
    menu();
}
void menu()
{
    int choice;
    for(;;)
    {
        printf("Press 1: Staff Login \n \t 2: Student\n \t 3: Exit\n");
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1: staff_menu();
                    break;
            case 2: student_menu();
                    break;
            case 3: printf("***THANK YOU***\n");
                    exit(0);
            default:printf("Enter your correct choice\n");
        }
    }
}

void staff_menu()
{
    int choice;
    int attempts,i=0,flag=0;
    char c=' ';
    char guser[20]="abc";
    char gpass[20]="1234";
    char username[20],password[20];
    printf("\n\t\tWELCOME!!\n\n");
    for(;;)
    {
        attempts=0;
        while(attempts<=2)
        {
            printf("Enter username - ");
            fflush(stdin);
            scanf("%s" , username);
            fflush(stdin);
            printf("\nEnter password - ");
            scanf("%s" , password);
            if(strcmp(gpass , password)==0 && strcmp(guser , username)==0)
            {
                printf("\nLogin Successfull!!\n");
                flag=1;
                break;
            }
            else if(attempts<=2)
            {
                attempts++;
                printf("Try again!\n");
            }
        }
        if(attempts>2)
        {
            printf("You have already attempted thrice!\n");
            printf("Try again in 10 seconds\n");
            sleep(10);
            continue;
        }
        if(flag==1)
            break;
      }
    staff_menu:
    for(;;)
    {
        printf("\n\nPress   1: View existing record\n\t2: Edit existing record");
        printf("\n\t3: Delete existing record\n\t4: Exit\n");
        printf("Enter your choice\n");
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1: view_all();
                    break;
            case 2: edit();
                    break;
            case 3: delete_record();
                    break;
            case 4: menu();
                    break;
            default:printf("Enter correct choice\n");
                    goto staff_menu;
        }
    }
}

void student_menu()
{
    int choice;
    for(;;)
    {
        student_menu:
        printf("Press 1:New admission\n\t2:View your record\n\t3:Exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: new1_entry();
                    break;
            case 2: view_student();
                    break;
            case 3: menu();
                    break;
            default:printf("Enter your correct choice\n");
                    goto student_menu;
        }
    }
}

void new1_entry()
{
    srand((unsigned) time(&t));
    FILE *file;
    file=fopen("details.dat" , "a+");
    printf("Enter your USN\n");
    scanf("%d" , &check.usn);

    while(fscanf(file , "%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,&new1.usn,&new1.year_of_adm,&new1.year,new1.branch,
    new1.section,new1.address,&new1.dob.date,&new1.dob.month,&new1.dob.year,new1.father_name,&new1.phone_no,&new1.father_no,new1.email,
    &new1.room_no,new1.code)!=EOF)
    {
        if(check.usn==new1.usn)
        {
            printf("Record already exists\n");
            student_menu();
        }
    }

    new1.usn=check.usn;
    printf("Enter your name\n");
    scanf("%s",new1.name);

    year:
    printf("Enter year of admission\n");
    scanf("%d",&new1.year_of_adm);
    if(new1.year_of_adm<2017 || new1.year_of_adm>2020)
    {
        printf("Enter correct year of admission(2017-2020)\n");
        goto year;
    }

    if(new1.year_of_adm==2017)
        new1.year=4;
    if(new1.year_of_adm==2018)
        new1.year=3;
    if(new1.year_of_adm==2019)
        new1.year=2;
    if(new1.year_of_adm==2020)
        new1.year=1;

    printf("Enter branch\n");
    scanf("%s",new1.branch);

    printf("Enter section\n");
    scanf("%s",new1.section);

    printf("Enter your address\n");
    scanf("%s",new1.address);

    printf("Enter your date of birth (dd/mm/yyyy)\n");
    scanf("%d/%d/%d",&new1.dob.date,&new1.dob.month,&new1.dob.year);

    printf("Enter fathers name\n");
    scanf("%s",new1.father_name);

    printf("Enter your phone number\n");
    scanf("%ld",&new1.phone_no);

    printf("Enter guardian`s phone number\n");
    scanf("%ld",&new1.father_no);

    printf("Enter your email id\n");
 	  scanf("%s",new1.email);

    if(new1.year==1)
      new1.room_no=(rand()%(199-100+1))+100;
    else if(new1.year==2)
      new1.room_no=(rand()%(299-200+1))+200;
    else if(new1.year==3)
      new1.room_no=(rand()%(399-300+1))+300;
    else
      new1.room_no=(rand()%(499-400+1))+400;

    char alpha[62]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
    for(int i=0;i<9;i++)
      new1.code[i]=alpha[rand()%(61)];

    fprintf(file,"\n%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s" , new1.name,check.usn,new1.year_of_adm,new1.year,new1.branch,new1.section,
    new1.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,new1.phone_no,new1.father_no,new1.email,new1.room_no,new1.code);

    printf("\n\nStudent data added successfully\n");

    printf("Your room number is %d\n\n" , new1.room_no);

    printf("Your code is %s\n\n" , new1.code);
    printf("When you enter the college, show this code to the college authorities to verify your details and then");
    printf(" you can avail the hostel facilities\n\n");
    printf("***DO NOT SHOW THIS CODE TO ANYONE ELSE***\n\n");
    fclose(file);

    student_menu();
}

void view_all()
{
    FILE *file;
    file=fopen("details.dat" , "r");
    printf("Name\t USN\tAdm_Year  Year\tBranch\tSection\tAddress\tDOB\t\tFather's name\tPhone number ");
    printf("Guardian's phone number\tEmail-ID\tRoom number\tCode\n\n");

    while(fscanf(file , "%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,&new1.usn,&new1.year_of_adm,&new1.year,
    new1.branch,new1.section,new1.address,&new1.dob.date,&new1.dob.month,&new1.dob.year,new1.father_name,&new1.phone_no,
    &new1.father_no,new1.email,&new1.room_no,new1.code)!=EOF)
    {
          printf("%s %d\t%d\t    %d\t%s\t%s\t%s\t%d/%d/%d\t%s\t%ld\t%ld\t\t%s\t%d\t\t%s\n\n",new1.name,new1.usn,new1.year_of_adm,
          new1.year,new1.branch,new1.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,new1.phone_no,
          new1.father_no,new1.email,new1.room_no,new1.code);
    }
    fclose(file);
}

void view_student()
{
    int view_usn;
    int test=0;
    char check_code[10];
    printf("Enter your USN\n");
    scanf("%d" , &view_usn);
    FILE *file;
    file=fopen("details.dat" , "r");
    while(fscanf(file , "%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,&new1.usn,&new1.year_of_adm,&new1.year,
    new1.branch,new1.section,new1.address,&new1.dob.date,&new1.dob.month,&new1.dob.year,new1.father_name,&new1.phone_no,
    &new1.father_no,new1.email,&new1.room_no,new1.code)!=EOF)
    {
        if(new1.usn==view_usn)
        {
            test=1;
            printf("Enter the secret code which was provided to you during registration\n");
            for(;;)
            {
                scanf("%s" , check_code);
                if(strcmp(check_code , new1.code)==0)
                {
                    printf("Name\t USN\tAdm_Year  Year\tBranch\tSection\tAddress\tDOB\t\tFather's name\tPhone number ");
                    printf("Guardian's phone number\tEmail-ID\tRoom number\tCode\n\n");
                    printf("%s %d\t%d\t    %d\t%s\t%s\t%s\t%d/%d/%d\t%s\t%ld\t%ld\t\t%s\t%d\t\t%s\n\n",new1.name,new1.usn,
                    new1.year_of_adm,new1.year,new1.branch,new1.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,
                    new1.father_name,new1.phone_no,new1.father_no,new1.email,new1.room_no,new1.code);
                    break;
                }
                else
                    printf("Enter correct code\n");
            }
        }
    }
    if(test==0)
        printf("Record does not exist\n");
}

void edit()
{
    int choice_edit=0,test=0;
    int find_usn;
    FILE* file,*new1_file;
    file=fopen("details.dat" , "r");
    new1_file=fopen("new1.dat","w");
    printf("Enter your USN\n");
    fflush(stdin);
    scanf("%d" , &find_usn);
    while(fscanf(file , "%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,&new1.usn,&new1.year_of_adm,&new1.year,
    new1.branch,new1.section,new1.address,&new1.dob.date,&new1.dob.month,&new1.dob.year,new1.father_name,&new1.phone_no,
    &new1.father_no,new1.email,&new1.room_no,new1.code)!=EOF)
    {
        if(new1.usn==find_usn)
        {
            test=1;
            printf("Which information do you want to edit?\n");
            choice:
            printf("Press    1:USN\n\t 2:Name\n\t 3:Year of admission and current year\n\t 4:Branch\n\t");
            printf(" 5:Section\n\t 6:Address\n\t 7:Date of Birth\n\t 8:Father's name\n\t");
            printf(" 9:Phone Number\n\t 10:Guardian's phone Number\n\t 11:EmailID\n");
            printf("Enter your choice - ");
            scanf("%d" , &choice_edit);
            switch (choice_edit)
            {
              case 1: printf("\nEnter correct USN\n");
                      scanf("%d" , &upd.usn);
                      fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,upd.usn,new1.year_of_adm,
                      new1.year,new1.branch,new1.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,
                      new1.phone_no,new1.father_no,new1.email,new1.room_no,new1.code);
                      printf("Changes updated successfully!!");
                      break;

              case 2: printf("\nEnter correct Name\n");
                      scanf("%s" , upd.name);
                      fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",upd.name,new1.usn,new1.year_of_adm,new1.year,
                      new1.branch,new1.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,new1.phone_no,
                      new1.father_no,new1.email,new1.room_no,new1.code);
                      printf("Changes updated successfully!!");
                      break;

              case 3: printf("\nEnter correct Year of admission\n");
                      scanf("%d" , &upd.year_of_adm);
                      printf("Enter current year of study\n");
                      scanf("%d", &upd.year);
                      srand((unsigned) time(&t));
                      if(upd.year==1)
                        upd.room_no=(rand()%(199-100+1))+100;
                      else if(upd.year==2)
                        upd.room_no=(rand()%(299-200+1))+200;
                      else if(upd.year==3)
                        upd.room_no=(rand()%(399-300+1))+300;
                      else
                        upd.room_no=(rand()%(499-400+1))+400;
                      printf("Your new room number is %d\n", upd.room_no);
                      fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,new1.usn,upd.year_of_adm,upd.year,
                      new1.branch,new1.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,new1.phone_no,
                      new1.father_no,new1.email,upd.room_no,new1.code);
                      printf("Changes updated successfully!!");
                      break;

              case 4: printf("\nEnter correct Branch\n");
                      scanf("%s" , upd.branch);
                      fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,new1.usn,new1.year_of_adm,new1.year,
                      upd.branch,new1.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,new1.phone_no,
                      new1.father_no,new1.email,new1.room_no,new1.code);
                      printf("Changes updated successfully!!");
                      break;

              case 5: printf("\nEnter correct Section\n");
                      scanf("%s" , upd.section);
                      fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,new1.usn,new1.year_of_adm,new1.year,
                      new1.branch,upd.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,new1.phone_no,
                      new1.father_no,new1.email,new1.room_no,new1.code);
                      printf("Changes updated successfully!!");
                      break;

              case 6: printf("\nEnter correct Address\n");
                      scanf("%s" , upd.address);
                      fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,new1.usn,new1.year_of_adm,new1.year,
                      new1.branch,new1.section,upd.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,new1.phone_no,
                      new1.father_no,new1.email,new1.room_no,new1.code);
                      printf("Changes updated successfully!!");
                      break;

              case 7: printf("\nEnter correct Date of Birth\n");
                      scanf("%d/%d/%d" , &upd.dob.date,&upd.dob.month,&upd.dob.year);
                      fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,new1.usn,new1.year_of_adm,new1.year,
                      new1.branch,new1.section,new1.address,upd.dob.date,upd.dob.month,upd.dob.year,new1.father_name,new1.phone_no,
                      new1.father_no,new1.email,new1.room_no,new1.code);
                      printf("Changes updated successfully!!");
                      break;

              case 8: printf("\nEnter correct Father Name\n");
                      scanf("%s" , upd.father_name);
                      fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,new1.usn,new1.year_of_adm,new1.year,
                      new1.branch,new1.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,upd.father_name,new1.phone_no,
                      new1.father_no,new1.email,new1.room_no,new1.code);
                      printf("Changes updated successfully!!");
                      break;

              case 9: printf("\nEnter correct Phone Number\n");
                      scanf("%ld" , &upd.phone_no);
                      fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,new1.usn,new1.year_of_adm,new1.year,
                      new1.branch,new1.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,upd.phone_no,
                      new1.father_no,new1.email,new1.room_no,new1.code);
                      printf("Changes updated successfully!!");
                      break;

              case 10:printf("\nEnter correct Guardian Number\n");
                      scanf("%ld" , &upd.father_no);
                      fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,new1.usn,new1.year_of_adm,new1.year,
                      new1.branch,new1.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,new1.phone_no,
                      upd.father_no,new1.email,new1.room_no,new1.code);
                      printf("Changes updated successfully!!");
                      break;

              case 11:printf("\nEnter correct EmailID\n");
                      scanf("%s" , upd.email);
                      fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,new1.usn,new1.year_of_adm,new1.year,
                      new1.branch,new1.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,new1.phone_no,
                      new1.father_no,upd.email,new1.room_no,new1.code);
                      printf("Changes updated successfully!!");
                      break;

              default:printf("Enter valid value\n\n");
                      goto choice;
            }
        }
        else
        {
            fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s\n",new1.name,new1.usn,new1.year_of_adm,new1.year,new1.branch,
            new1.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,new1.phone_no,new1.father_no,new1.email,
            new1.room_no,new1.code);
        }
    }

    fclose(file);
    fclose(new1_file);
    remove("details.dat");
    rename("new1.dat","details.dat");

    if(test!=1)
        printf("Record not found\n");
}

void delete_record()
{
    FILE *file,*new1_file;
    file=fopen("details.dat" , "r");
    new1_file=fopen("new1.dat" , "w");
    printf("Enter USN of student whose data you want to delete\n");
    scanf("%d" , &check.usn);
    int test=0;
    while(fscanf(file , "%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s",new1.name,&new1.usn,&new1.year_of_adm,&new1.year,
    new1.branch,new1.section,new1.address,&new1.dob.date,&new1.dob.month,&new1.dob.year,new1.father_name,&new1.phone_no,
    &new1.father_no,new1.email,&new1.room_no,new1.code)!=EOF)
    {
        if(new1.usn!=check.usn)
        {
          fprintf(new1_file,"%s %d %d %d %s %s %s %d/%d/%d %s %ld %ld %s %d %s\n",new1.name,new1.usn,new1.year_of_adm,new1.year,
          new1.branch,new1.section,new1.address,new1.dob.date,new1.dob.month,new1.dob.year,new1.father_name,new1.phone_no,
          new1.father_no,new1.email,new1.room_no,new1.code);
        }
        else
        {
            test=1;
            printf("Record deleted successfully!\n");
        }
      }
      fclose(file);
      fclose(new1_file);
      remove("details.dat");
      rename("new1.dat","details.dat");
      if(test==0)
          printf("Record not found\n");
}
