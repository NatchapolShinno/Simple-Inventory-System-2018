/***********************************************************************************
 *  
 *  CPE Inventory System 
 *  
 *      This programs will store information about the durable objects owned 
 *  by the Computer Engineering Department, such as computers, 
 *  items of furniture, projectors, etc.
 * 
 *  Create By:
 *  Mr.Thapanachart     Thumpreecha         ID: 61070503408
 *  Mr.Natchapol        Shinno              ID: 61070503412
 *  Ms.Wannakorn        Mahisaranon         ID: 61070503429
 *  Mr.Weerawit         Milinpattanakorn    ID: 61070503433
 *  Mr.Supakij          Buasod              ID: 61070503438
 *  Date: 18/11/2018 (Update: 13/12/2018)
 *
 ***********************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "checkFunction.h"
#include "searchFunction.h"
#include "displayFunction.h"

void addItem();
void searchItem();

int totalAdd    = 0;
int totalSearch = 0;

int main()
    {
    char stringInput[16];
    int selectMenu = 0;

    printf("\n\t\tWelcome to 'CPE INVENTORY SYSTEM'\n");
    printf("\tMenu\n");
    printf("\t1).Add item\n");
    printf("\t2).Search item\n");
    printf("\t3).Display item\n");
    printf("\n\tPress 0 to exit\n");

    printf("SELECT : ");
    fgets(stringInput,sizeof(stringInput),stdin);
    sscanf(stringInput,"%d",&selectMenu);

    if(selectMenu == 1) 
        addItem();
    else if(selectMenu == 2)
        searchItem();
    else if(selectMenu == 3)
        {
        displayAll();
        main();
        }
    else if(strlen(stringInput) == 1)
        main();
    else if(selectMenu == 0)
        {
        printf("\t~~ GOOD BYE ~~\n");
        exit(0);
        }
    else
        {
        printf("Please select 1-5\n");
        main();
        }

    }

void addItem()
    {
    // Variable Declaration zone
    char string[20];
    int d,day,pDay;
    int m,month,pMonth;
    int y,year,pYear;
    int check=0;
    INFO_T info;
    
    printf("\n\t     .: Welcome to Add item section :.\n\t.: Please follow the instructions below :.\n");
    printf("1. Item Code Format is only CPE_nnnnn and number must be unique\n");
    printf("2. You cann't modify the Inventory code of an object already in the database\n");
    printf("3. After Validing code the available category is Computer, Peripheral, AudioVisual, Appliance and Other\n");
    printf("4. The subcategory is for computer only, Leave blank for the other\n");
    printf("5. If the item is computer ,Please specify the Operating System\n");
    printf("6. The Date of purchased format is yyyy-mm-dd western year and it mustn't be in the Future\n");
    printf("7. These program is case insensitive ,Process as you wish\n\n");
    while (1)
    {
        while(1)
        {
            printf("Specify the category of an item (Done to End): ");
            fgets(string,sizeof(string),stdin);
            sscanf(string,"%s",info.category);

            if(strcasecmp(info.category,"Done")==0)
            {
                printf("Successfully added %d item(s)\n",totalAdd);
                printf("Going Back to main option...\n\n");
                main();
            }

            printf("Checking %s\n",info.category);
            check = checkCategory(info.category);
            while (check==0)
            {
                printf("Try Again(Category Error)\n\n");
                printf("Specify the category of an item (Done to End):");
                fgets(string,sizeof(string),stdin);
                sscanf(string,"%s",info.category);
                if(strcasecmp(info.category,"Done")==0)
                {
                    printf("Successfully added %d item(s)\n",totalAdd);
                    printf("Going Back to main option...\n\n");
                    main();
                }
                printf("Checking %s\n",info.category);
                check = checkCategory(info.category);

            }
            printf("Valid Category\n\n");
            
            if (strcasecmp(info.category,"Computer")==0)
            {
                printf("Specify the subcategory of an item (Done to End): ");
                fgets(string,sizeof(string),stdin);
                sscanf(string,"%s",info.subcategory);
        
                if(strcasecmp(info.subcategory,"Done")==0)
                {
                    printf("Successfully added %d item(s)\n",totalAdd);
                    printf("Going Back to main option...\n\n");
                    main();
                }

                printf("Checking %s \n",info.subcategory);
                check = checkSubcategory(info.subcategory,info.category);
                while (check==0)
                {
                    printf("Try Again(Subcategory Error)\n\n");
                    printf("Specify the subcategory of an item (Done to End):");
                    fgets(string,sizeof(string),stdin);
                    sscanf(string,"%s",info.subcategory);
                    if(strcasecmp(info.subcategory,"Done")==0)
                    {
                        printf("Successfully added %d item(s)\n",totalAdd);
                        printf("Going Back to main option...\n\n");
                        main();
                    }
                    printf("Checking %s \n",info.subcategory);
                    check = checkSubcategory(info.subcategory,info.category);
                }
                printf("Valid Subcategory\n\n");
                
                printf("Specify the Operating System (Done to End): ");
                fgets(string,sizeof(string),stdin);
                sscanf(string,"%s",info.operatingSystem);
                    
                if(strcasecmp(info.operatingSystem,"Done")==0)
                {
                    printf("Successfully added %d item(s)\n",totalAdd);
                    printf("Going Back to main option...\n\n");
                    main();
                }

                printf("Checking %s\n",info.operatingSystem);
                check = checkOS(info.operatingSystem,info.category);
                while (check==0)
                {
                    printf("Try Again(OS Error)\n\n");
                    printf("Specify the Operating System (Done to End):");
                    fgets(string,sizeof(string),stdin);
                    sscanf(string,"%s",info.operatingSystem);
                    if(strcasecmp(info.operatingSystem,"Done")==0)
                    {
                        printf("Successfully added %d item(s)\n",totalAdd);
                        printf("Going Back to main option...\n\n");
                        main();
                    }
                    printf("Checking %s\n",info.operatingSystem);
                    check = checkOS(info.operatingSystem,info.category);
                }
                printf("Valid Operating System\n\n");
            }
            
            dateToday(&pDay,&pMonth,&pYear);
            printf("The date today is %d-%d-%d \n\n",pYear,pMonth,pDay);
            d = pDay;   m = pMonth;   y = pYear;    // Prevent Terminal warning
            printf("Specify Date of Purchased (Done to End): ");
            fgets(string,sizeof(string),stdin);
            sscanf(string,"%s",info.date);
            if(strcasecmp(info.date,"Done")==0)
            {
                printf("Successfully added %d item(s)\n",totalAdd);
                printf("Going Back to main option...\n\n");
                main();
            }
        
            check = checkDate(info.date,day,month,year,d,m,y);
            while (check==0)
            {
                printf("Try Again(Date Format Error or In the Future)\n\n");
                dateToday(&pDay,&pMonth,&pYear);
                printf("The info.date today is %d-%d-%d \n",pYear,pMonth,pDay);
                d = pDay;   m = pMonth;   y = pYear;    // Prevent Terminal warning
                printf("Specify Date of Purchased (Done to End):");
                fgets(string,sizeof(string),stdin);
                sscanf(string,"%s",info.date);
                if(strcasecmp(info.date,"Done")==0)
                {
                    printf("Successfully added %d item(s)\n",totalAdd);
                    printf("Going Back to main option...\n\n");
                    main();
                }
                check = checkDate(info.date,day,month,year,d,m,y);
            }
            printf("Valid Date\n\n");
            
            printf("Specify Person Responsible (Done to End): ");
            fgets(string,sizeof(string),stdin);
            sscanf(string,"%s %s",info.fname,info.lname);
            if(strcasecmp(info.fname,"Done")==0)
                {
                    printf("Successfully added %d item(s)\n",totalAdd);
                    printf("Going Back to main option...\n\n");
                    main();
                }
            printf("Checking %s %s\n",info.fname,info.lname);
            check = checkName(info.fname,info.lname);
            while (check==0)
            {
                printf("Try Again(Name Error)\n\n");
                printf("Specify Person Responsible (Done to End):");
                fgets(string,sizeof(string),stdin);
                sscanf(string,"%s %s",info.fname,info.lname);
                if(strcasecmp(info.fname,"Done")==0)
                {
                    printf("Successfully added %d item(s)\n",totalAdd);
                    printf("Going Back to main option...\n\n");
                    main();
                }
                printf("Checking %s %s\n",info.fname,info.lname);
                check = checkName(info.fname,info.lname);
            }
            printf("Valid Name\n\n");

            printf("Specify Person Responsible Phone number (Done to End): ");
            fgets(string,sizeof(string),stdin);
            sscanf(string,"%s",info.phonenum);
            if(strcasecmp(info.phonenum,"Done")==0)
                {
                    printf("Successfully added %d item(s)\n",totalAdd);
                    printf("Going Back to main option...\n\n");
                    main();
                }
            printf("Checking %s \n",info.phonenum);
            check = checkPhonenum(info.phonenum);
            while (check==0)
            {
                printf("Try Again(Phone Number Error)\n\n");
                printf("Specify Person Responsible Phone number (Done to End):");
                fgets(string,sizeof(string),stdin);
                sscanf(string,"%s",info.phonenum);
                if(strcasecmp(info.phonenum,"Done")==0)
                {
                    printf("Successfully added %d item(s)\n",totalAdd);
                    printf("Going Back to main option...\n\n");
                    main();
                }
                printf("Checking %s \n",info.phonenum);
                check = checkPhonenum(info.phonenum);
            }
            printf("Valid Phone Number\n\n");

            printf("Specify Room location (Done to End): ");
            fgets(string,sizeof(string),stdin);
            sscanf(string,"%s",info.room);
            if(strcasecmp(info.room,"Done")==0)
                {
                    printf("Successfully added %d item(s)\n",totalAdd);
                    printf("Going Back to main option...\n\n");
                    main();
                }
            printf("Checking %s \n",info.room);
            check = checkRoom(info.room);
            while (check==0)
            {
                printf("Try Again(Room number Error)\n\n");
                printf("Specify Room location (Done to End):");
                fgets(string,sizeof(string),stdin);
                sscanf(string,"%s",info.room);
                if(strcasecmp(info.room,"Done")==0)
                {
                    printf("Successfully added %d item(s)\n",totalAdd);
                    printf("Going Back to main option...\n\n");
                    main();
                }
                printf("Checking %s \n",info.room);
                check = checkRoom(info.room);
            }
            printf("Valid Room Number\n\n");
            
            printf("Description (Required) (Done to End): ");
            fgets(string,sizeof(string),stdin);
            sscanf(string,"%[^\n]",info.description);
            if(strcasecmp(info.description,"Done")==0)
                {
                    printf("Successfully added %d item(s)\n",totalAdd);
                    printf("Going Back to main option...\n\n");
                    main();
                }
            while(strlen(string)-1<1 || strlen(string)-1>512)
            {
                printf("Try Again (Description Required)\n\n");
                printf("Description (Required) (Done to End) :");
                fgets(string,sizeof(string),stdin);
                sscanf(string,"%[^\n]",info.description);
                if(strcasecmp(info.description,"Done")==0)
                {
                    printf("Successfully added %d item(s)\n",totalAdd);
                    printf("Going Back to main option...\n\n");
                    main();
                }
            }
            printf("Adding item Completed !!\n\n");
            totalAdd++;

            databaseFile(info);
            }
        }   
    }

void searchItem()
    {
    char inputString[128];  /* A string that received from the user */
    int number = 0;         /* The number of program */
    FILE* pIn = NULL;       /* File pointer for reading */

    while(number != 6)
        {
        printf("\n\t\t\t  .: Searching page :.\n");
        printf("\t\t\tWhat do you looking for?\n");
        printf("Press 1: Inventory Code\n");
        printf("Press 2: Category\n");
        printf("Press 3: Date purchased\n");
        printf("Press 4: Location\n");
        printf("I would like to search in Press (Done to end): ");        
        fgets(inputString, sizeof(inputString), stdin);
        sscanf(inputString, "%s", inputString);
        if(strcasecmp(inputString,"DONE") == 0) 
            main();
        sscanf(inputString, "%d", &number);
    
        pIn = fopen("database.txt", "r");
        if(pIn == NULL)
            {
            printf("\terror openning\n");
            exit(0);
            }
        else
            {
            switch(number)
                {
                case 1: 
                    InventoryCode(pIn);
                    break;
                case 2: 
                    Category(pIn);
                    break;
                case 3: 
                    Date(pIn);
                    break;
                case 4: 
                    Location(pIn);
                    break;
                default:
                    printf("Please select function between 1 and 5 only!\n");
                    searchItem();
                }
            }
        }
    }
