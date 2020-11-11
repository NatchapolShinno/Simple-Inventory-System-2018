/****************************************************************************
*
* CPE Inventory System
*
* This program will keep your CPE Inventory data and dump to text files.
* This program can
* - display the current contents of the database on the screen.
* - add a new object.
* - search for an object that is in the database.
* - delete the object from the database.
* - modify its properties.
* - dump the entire database to a text file for examination and debugging.
*
* Created by Team (NULL)
* 12 November 2018
* Recently updated 12 December 2018
*
*****************************************************************************
*/

/****************************************************************************
 *
 * Searching program
 *
 * This program will search from the database by
 * - Inventory code
 * - Category
 * - Year purchased
 * - Location 
 *
 * This function is wroten by Wannakorn Mahisaranon (Mill) 3429
 * 12 November 2018
 * Recently updated 12 December 2018
 *
*****************************************************************************
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "searchFunction.h"

#define MAXCOUNT 99

int searchCount = 0;
int display = 0;

/****************************************************************************
 * displayInformation 
 * this function will print out the information for database 
 * CPE inventory system.
 * 'cpe' is the database that we will print
 */
void displayInformation(DATABASE_T cpe)
	{
	printf("Inventory Code: \t%s\n", cpe.Incode);
	printf("Category: \t\t%s\n", cpe.category);
	printf("Sub category: \t\t%s\n", cpe.subcategory);
	printf("Operating system: \t%s\n", cpe.operating_system);
	printf("Date Purchase: \t\t%d-%02d-%02d\n", cpe.year, cpe.month, cpe.day);
	printf("Person Responsible: \t%s %s\n", cpe.firstname, cpe.lastname);
	printf("Phone Number: \t\t%s\n", cpe.phoneNumber);
	printf("Location room: \t\t%s\n", cpe.location);
	printf("Description: \t\t%s\n\n", cpe.description);
	}

/****************************************************************************
 * AlphaCode
 * This function will check alphabetica of code that user input.
 * 'code' is the input fron the user
 * This function will return alpha = 1 if has alphabet
 */
int AlphaCode(char code[])
	{
	int i = 0;				/* variable which is used in loop */
	int alpha = 0;			/* variable which assigned value if has alphabet */
	int string_Length = 0; 	/* the length of code */

	/* count the length of code */
	string_Length = strlen(code);

	/* this loop will check alphabet */
	for(i = 0; i < string_Length; i++)
		{
		if (strcasecmp(code, "DONE")==0)
			alpha = 0;
		else if ((code[i] >= 'A' && code[i] <= 'Z') || (code[i] >= 'a' && code[i] <= 'z'))
			alpha = 1;
		}
	return alpha;
	}

/****************************************************************************
 * searchInventoryCode
 * A function of searching CPE inventory code.
 * 'pIn' is the pointer for reading
 * This function will search from inventory code until the user enters "N".
 */
void InventoryCode(FILE* pIn)
	{
	DATABASE_T cpe[MAXCOUNT];	/* array of structures for cpe inventory data */
	char inputString[256];		/* A string that receive from the user */
	char code[16];				/* input code, from user */		
	int i = 0;					/* loop counter */
	int object = 0;				/* object to select mode */
	int count = 0;				/* count how many data */
	int found = 0;				/* the code was found */
	char alpha[2];				/* answer to repeat question again */

	/* read each line, then store the data in the next strcture */
	while(fgets(inputString, sizeof(inputString), pIn) != NULL)
		{
		sscanf(inputString, "%s %s %s %s %d-%02d-%02d %s %s %s %s %[^\n]", cpe[count].Incode, cpe[count].category, cpe[count].subcategory, cpe[count].operating_system, &cpe[count].year, &cpe[count].month, &cpe[count].day, cpe[count].firstname, cpe[count].lastname, cpe[count].phoneNumber, cpe[count].location, cpe[count].description);
		count++;
		}
	fclose(pIn);

	/* print the question */
    while(1)
        {
        printf("\n\t-> Search by Inventory code (DONE to end): CPE_");
	    fgets(inputString, sizeof(inputString), stdin);
	    sscanf(inputString, "%s", code);
		/* check alphabetica from the user input */
        if(AlphaCode(code))
			printf("Please search Inventory code by number only!\n\n");
        else if(strcasecmp(code, "DONE")==0)
            {
            break;
            }
        else
            {
		    /* search in loop */
		    for (i=0; i<count; i++)
				{
			    if (strcmp(code, cpe[i].Incode)==0)
					{
				    printf("Inventory Code: %s\nCategory: %s\nSub category: %s\nOperating system: %s\n\n",cpe[i].Incode,cpe[i].category,cpe[i].subcategory,cpe[i].operating_system);
				    found = 1;
					searchCount++;
				    }
			    }
			if(found == 0)
			    printf("Sorry, we couldn't find %s to show in Inventory code\n\n", code);
		    }
		/* Select object to modify, delete or display detail */
		if(found == 1)
			{
			printf("\t-> Please select an object \nPress 1: Modify\nPress 2: Delete\nPress 3: Display detail\n\tI want to select: ");
			fgets(inputString, sizeof(inputString), stdin);
			sscanf(inputString, "%d", &object);
			
			switch(object)
				{
				case 2:
					for (i=0; i<count; i++)
			        {
			        if (strcmp(code, cpe[i].Incode)==0)
				        {
				        deleteItem(cpe[i]);
				        }
					}
					break;
				case 3:
					for (i=0; i<count; i++)
			        {
			        if (strcmp(code, cpe[i].Incode)==0)
				        {
						displayInformation(cpe[i]);
						display++;
						}
					}
					break;
				}
			}
		found = 0;
		}
	}

/****************************************************************************
 * searchCategory
 * A function of searching by category.
 * 'pIn' is the pointer for reading
 * This function will search from inventory code until the user enters "N".
 */
void Category(FILE* pIn)
	{
 	DATABASE_T cpe[MAXCOUNT];	/* arrat of structure for cpe inventory data */
	char inputString[256];		/* A string that recieved from the user */
	char Incate[64];			/* input category, from user */
	char chooseCode[6];			/* code to select on each mode */
	int i = 0;					/* loop counter */
	int object = 0;				/* object to select mode */
	int count = 0;				/* count how many data */
	int found = 0;				/* the category was found */
	char alpha[2];				/* answer to repeat question again */

	/* read each line, then stroe the data in the next structure */
	while(fgets(inputString, sizeof(inputString), pIn) != NULL)
		{
		sscanf(inputString, "%s %s %s %s %d-%02d-%02d %s %s %s %s %[^\n]", cpe[count].Incode, cpe[count].category, cpe[count].subcategory, cpe[count].operating_system, &cpe[count].year, &cpe[count].month, &cpe[count].day, cpe[count].firstname, cpe[count].lastname, cpe[count].phoneNumber, cpe[count].location, cpe[count].description);
		count++;
		}
	fclose(pIn);

	/* print the question */
	while(1)
		{
		printf("\n\t-> Search by category (DONE to end): ");
		fgets(inputString, sizeof(inputString), stdin);
		sscanf(inputString, "%s", Incate);
	
		if(strcasecmp(Incate, "DONE")==0)
			{
			break;
			}
		else
           	{
			/* search in loop */
			for (i=0; i<count; i++)
				{
				if (strcasecmp(Incate, cpe[i].category)==0)
					{
					printf("Inventory Code: %s\nCategory: %s\nSub category: %s\nOperating system: %s\n\n",cpe[i].Incode,cpe[i].category,cpe[i].subcategory,cpe[i].operating_system);
					found = 1;
					searchCount++;
					}
				}
			if(found == 0)
				printf("Sorry, we couldn't find %s to show in Category\n\n", Incate);
			}
		/* Select object to modify, delete or display detail */
		if(found == 1)
			{
			printf("\t-> Please select an object \nPress 1: Modify\nPress 2: Delete\nPress 3: Display detail\n\tI want to select: ");
			fgets(inputString, sizeof(inputString), stdin);
			sscanf(inputString, "%d", &object);
			
			switch(object)
				{
				case 2:
					printf("Choose inventory code to delete: ");
					fgets(inputString,sizeof(inputString),stdin);
					sscanf(inputString, "%s",chooseCode);
					for (i=0; i<count; i++)
			        {
			        if (strcasecmp(chooseCode, cpe[i].Incode)==0)
				        {
						deleteItem(cpe[i]);
						display++;
						}
					}
					break;
				case 3:
					printf("Choose inventory code to display: ");
					fgets(inputString,sizeof(inputString),stdin);
					sscanf(inputString, "%s",chooseCode);
					for (i=0; i<count; i++)
			        {
			        if (strcasecmp(chooseCode, cpe[i].Incode)==0)
				        {
						displayInformation(cpe[i]);
						display++;
						}
					}
					break;
				}
			}
		found = 0;
		}
	}

/****************************************************************************
 * searchDate
 * A function of searching by year purchased.
 * 'pIn' is the pointer for reading
 * This function will search from inventory code until the user enters "N".
 */
void Date(FILE* pIn)
	{
	DATABASE_T cpe[MAXCOUNT];	/* array of structure for cpe inventory data */
	char inputString[256];		/* A string that received from the user */
	int date = 0;				/* input date, from user */
	char chooseCode[6];			/* code to select on each mode */
	int i = 0;					/* loop counter */
	int object = 0;				/* object to select mode */
	int found = 0;				/* the year purchased was found */
	int count = 0;				/* count how many data */
	char alpha[2];				/* answer to repeat question again */
	
	/* read each line, then store the data in the next structure */
	while(fgets(inputString, sizeof(inputString), pIn) != NULL)
		{
		sscanf(inputString, "%s %s %s %s %d-%02d-%02d %s %s %s %s %[^\n]", cpe[count].Incode, cpe[count].category, cpe[count].subcategory, cpe[count].operating_system, &cpe[count].year, &cpe[count].month, &cpe[count].day, cpe[count].firstname, cpe[count].lastname, cpe[count].phoneNumber, cpe[count].location, cpe[count].description);
		count++;
		}
		fclose(pIn);

		/* print the question */
	while(1)
		{
		printf("\n\t-> Search by year purchased (DONE to end): ");
		fgets(inputString, sizeof(inputString), stdin);
		sscanf(inputString, "%s",inputString);
		if(strcasecmp(inputString, "DONE")==0)
			{
			break;
			}
		sscanf(inputString, "%d", &date);
		if(date >= 2500 || date < 100)
			printf("Please search in western year format\n");
		else
           	{
			/* search in loop */
			for (i=0; i<count; i++)
				{
				if (date == cpe[i].year)
					{
					printf("Inventory Code: %s\nCategory: %s\nSub category: %s\nOperating system: %s\n\n",cpe[i].Incode,cpe[i].category,cpe[i].subcategory,cpe[i].operating_system);
					found = 1;
					searchCount++;
					}
				}
			if(found == 0)
				printf("Sorry, we couldn't find %d to show in Year purchased\n\n", date);
			}
		/* Select object to modify, delete or display detail */
		if(found == 1)
			{
			printf("\t-> Please select an object \nPress 1: Modify\nPress 2: Delete\nPress 3: Display detail\n\tI want to select: ");
			fgets(inputString, sizeof(inputString), stdin);
			sscanf(inputString, "%d", &object);
			
			switch(object)
				{
				case 2:
					printf("Choose inventory code to delete: ");
					fgets(inputString,sizeof(inputString),stdin);
					sscanf(inputString, "%s",chooseCode);
					for (i=0; i<count; i++)
			        {
			        if (strcasecmp(chooseCode, cpe[i].Incode)==0)
				        {
						deleteItem(cpe[i]);
						display++;
						}
					}
					break;
				case 3:
					printf("Choose inventory code to display: ");
					fgets(inputString,sizeof(inputString),stdin);
					sscanf(inputString, "%s",chooseCode);
					for (i=0; i<count; i++)
			        {
			        if (strcasecmp(chooseCode, cpe[i].Incode)==0)
				        {
						displayInformation(cpe[i]);
						display++;
						}
					}
					break;
				}
			}
		found = 0;
		}
	}

/****************************************************************************
 * alphaLocation
 * This function will check that has alphabet in location or not?
 * 'location' is the input from the user
 * This function will return alpha = 1 if has alphabet.
 */
int alphaLocation(char location[])
	{
	int i = 0;				/* variable which is used in loop */
	int alpha = 0;			/* variable which assigned value if has alphabet */
	int string_Length = 0;	/* the length of the location */
	
	/* count the length of the location */
	string_Length = strlen(location);
	/* this loop will check alphabet */
	for(i = 0; i < string_Length; i++)
		{
		if(strcasecmp(location, "DONE")==0)
			alpha = 0;
		else if ((location[i] >= 'A' && location[i] <= 'Z') || (location[i] >= 'a' && location[i] <= 'z'))
			alpha = 1;
		}
	return alpha;
	}

/****************************************************************************
 * checkLocation
 * This function will check that the location on 10th or 11th floors.
 * 'location' is the input from the user 
 * This function will return check = 1 if location is not 
 * on 10th or 11th floors
 */ 
int checkLocation(char location[])
	{
	int check = 0;			/* variable which assigned value if location not on 10th or 11th floors */
	int i = 0;				/* variable which used in loop */
	int string_Length = 0;	/* the length of the location */

	/* count the length of the location */
	string_Length = strlen(location);
	/* this loop will check floors */
	for(i=0; i<2; i++)
		{
		if(location[i] != '1')
			{
			i++;
			if((location[1] != '0') && (location[1] != '1'))
			check = 1;
			}
		}
	return check;
	}	

/****************************************************************************
 * searchLocation
 * A function of searching by location
 * 'pIn' is the pointer for reading
 * This function will search from inventory code until the user enters "N".
 */
void Location(FILE* pIn)
	{
	DATABASE_T cpe[MAXCOUNT];	/* array of structure for cpe inventory data */
	char inputString[256];		/* A string that received from the user */
	char location[10];			/* input location, from user */
	char chooseCode[6];			/* code to select on each mode */
	char alpha[2];				/* answer to repeat question again */
	int count = 0;				/* count how many data */
	int found = 0;				/* the location was found */
	int i = 0;					/* loop counter */
	int object = 0;				/* object to select mode */

	/* read each line, the store the data in the next structure */
	while(fgets(inputString, sizeof(inputString), pIn) != NULL)
		{
		sscanf(inputString, "%s %s %s %s %d-%02d-%02d %s %s %s %s %[^\n]", cpe[count].Incode, cpe[count].category, cpe[count].subcategory, cpe[count].operating_system, &cpe[count].year, &cpe[count].month, &cpe[count].day, cpe[count].firstname, cpe[count].lastname, cpe[count].phoneNumber, cpe[count].location, cpe[count].description);
		count++;
		}
		fclose(pIn);
	/* print the question */
	while(1)
		{
		printf("\n\t-> Search by location (DONE to end): ");
		fgets(inputString, sizeof(inputString), stdin);
		sscanf(inputString, "%s", location);
	
		if(strcasecmp(location, "DONE")==0)
			{
			break;
			}
		else
           	{
			/* search in loop */
			for (i=0; i<count; i++)
				{
				if (strcasecmp(location, cpe[i].location)==0)
					{
					printf("Inventory Code: %s\nCategory: %s\nSub category: %s\nOperating system: %s\n\n",cpe[i].Incode,cpe[i].category,cpe[i].subcategory,cpe[i].operating_system);
					found = 1;
					searchCount++;
					}
				}
			if(found == 0)
				printf("Sorry, we couldn't find %s to show in Location\n\n", location);
			}
		/* Select object to modify, delete or display detail */
		if(found == 1)
			{
			printf("\t-> Please select an object \nPress 1: Modify\nPress 2: Delete\nPress 3: Display detail\n\tI want to select: ");
			fgets(inputString, sizeof(inputString), stdin);
			sscanf(inputString, "%d", &object);
			
			switch(object)
				{
				case 2:
					printf("Choose inventory code to delete: ");
					fgets(inputString,sizeof(inputString),stdin);
					sscanf(inputString, "%s",chooseCode);
					for (i=0; i<count; i++)
			        {
			        if (strcasecmp(chooseCode, cpe[i].Incode)==0)
				        {
						deleteItem(cpe[i]);
						display++;
						}
					}
					break;
				case 3:
					printf("Choose inventory code to display: ");
					fgets(inputString,sizeof(inputString),stdin);
					sscanf(inputString, "%s",chooseCode);
					for (i=0; i<count; i++)
			        {
			        if (strcasecmp(chooseCode, cpe[i].Incode)==0)
				        {
						displayInformation(cpe[i]);
						display++;
						}
					}
					break;
				}
			}
		found = 0;
		}
	}

void deleteItem(DATABASE_T cpe)
	{
	char stringInput[128];
	FILE * dataOld = NULL;
	DATABASE_T * Old;
	DATABASE_T * New;
	int countOld = 0;
	int countNew = 0;
	int countfor = 0;
	dataOld = fopen("database.txt","r");
	if(dataOld == NULL)
		printf("ERROR to read database\n");
	else
		{
		while(fgets(stringInput,sizeof(stringInput),dataOld) != NULL)
			{	
			countOld++;
			}
		Old = calloc(countOld,sizeof(DATABASE_T));
		New = calloc(countOld-1,sizeof(DATABASE_T));
		fclose(dataOld);

		dataOld = fopen("database.txt","r");
		countOld = 0;
		while(fgets(stringInput,sizeof(stringInput),dataOld) != NULL)
			{
			sscanf(stringInput,"%s %s %s %s %d-%02d-%02d %s %s %s %s %[^\n]",
				Old[countOld].Incode,Old[countOld].category,
				Old[countOld].subcategory,Old[countOld].operating_system,
				&Old[countOld].year,&Old[countOld].month,&Old[countOld].day,
				Old[countOld].firstname,Old[countOld].lastname,Old[countOld].phoneNumber,
				Old[countOld].location,Old[countOld].description);
			if(strcasecmp(Old[countOld].Incode,cpe.Incode) != 0)
				{
				sscanf(stringInput,"%s %s %s %s %d-%02d-%02d %s %s %s %s %[^\n]",
				New[countNew].Incode,New[countNew].category,
				New[countNew].subcategory,New[countNew].operating_system,
				&New[countNew].year,&New[countNew].month,&New[countNew].day,
				New[countNew].firstname,New[countNew].lastname,New[countNew].phoneNumber,
				New[countNew].location,New[countNew].description);
				countNew++;
				}
			countOld++;
			}
		fclose(dataOld);
		FILE * dataNew = NULL;
		dataNew = fopen("database.txt","w");
		if(dataNew == NULL)
			printf("ERROR to crate file.\n");
		else
			{
			for(countfor = 0; countfor < countNew; countfor++)
				{
				fprintf(dataNew, "%s %s %s %s %d-%02d-%02d %s %s %s %s %s\n",
				New[countfor].Incode,New[countfor].category,
				New[countfor].subcategory,New[countfor].operating_system,
				New[countfor].year,New[countfor].month,New[countfor].day,
				New[countfor].firstname,New[countfor].lastname,New[countfor].phoneNumber,
				New[countfor].location,New[countfor].description);
				}
			}
		if(fclose(dataOld) != 0)
			printf("ERROR to close file.\n");
		}
	printf("|--------------|\n");
	printf("|DELETE SUCCESS|\n");
	printf("|--------------|\n");
	}