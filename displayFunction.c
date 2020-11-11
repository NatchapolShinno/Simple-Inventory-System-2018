/**************************************************************
*  
* 	displaycpe
*
*   This function display the current contents of the 
*   database (all objects) on the screen.
*
*   Created by Weerawit Milinpattanakorn (Talent)  ID 3433
*     7 December 2018
*
***************************************************************
*/  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "displayFunction.h"

void displayAll()
	{
	char input[1024];			/*store data from user*/
	INV_T item[500];			/*store each item data*/
	int iDisplay = 0;					/*loop counter*/
	int j = 0;					/*loop counter*/
	int k = 0;					/*loop counter*/
	int totalstrlength = 0;		/*total string length of the data*/
	FILE* pIn = NULL;			/*store data from file*/
	
	pIn = fopen("database.txt","r");
	
	if(pIn == NULL)
		{
		printf("Error opening database file\n");
		exit (0);
		}
	
	while(fgets(input,sizeof(input),pIn)!=NULL)
		{
		/*item = calloc(1,sizeof(INV_T));*/
		totalstrlength = 0;
		sscanf(input,"%s %s %s %s %s %s %s %s %s",item[iDisplay].digitCode,item[iDisplay].category,item[iDisplay].subCategory,item[iDisplay].os,
			item[iDisplay].date,item[iDisplay].firstName,item[iDisplay].lastName,item[iDisplay].phoneNumber,item[iDisplay].room);

		/*totalstrlength = length of string before description*/
		totalstrlength = strlen(item[iDisplay].digitCode)+strlen(item[iDisplay].category)+strlen(item[iDisplay].subCategory)
		+strlen(item[iDisplay].os)+strlen(item[iDisplay].date)+strlen(item[iDisplay].firstName)+strlen(item[iDisplay].lastName)
		+strlen(item[iDisplay].phoneNumber)+strlen(item[iDisplay].room)+8;

		/*stored description in variable*/
		for(k=totalstrlength+1;k<strlen(input)-1;k++)
			{
			sprintf(item[iDisplay].description,"%s%c",item[iDisplay].description,input[k]);
			}
		/*set last character to NULL for end string*/
		item[iDisplay].description[k+1]='\0';
		iDisplay++;
		}
	
	for(j=0;j<iDisplay;j++)
		{
		printf("CPE%-8s %-16s %-16s %-16s %-16s %-16s %-16s %-13s %-10s %s\n",item[j].digitCode,item[j].category,item[j].subCategory,item[j].os,item[j].date,item[j].firstName,item[j].lastName,item[j].phoneNumber,
			item[j].room,item[j].description);
		}
	}
