/*	checkFunction.c
 *	
 *	This module keep all function to use in programs.
 * 
 *	Created by: Mr.Supakij Buasod 61070503438 (24 November 2018)
 * 	Update: 12 December 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "checkFunction.h"

/******************************************************************************	
 *	Created by Natchapol Shinno (Nath) 61070503412
 *	This function is use to created the code digit of each of inventory 
 */
int randomDigit(INFO_T info)
	{
	int i = 0;						/*counter*/
	int j = 1;						/*counter*/
	int k = 0;						/*counter*/
	FILE* pIn = NULL;				/*use to check the file database*/
	char stringInput[256];			/*  */
	char type[6][15] = {"Computer","AudioVisual","Peripheral","Appliance","Other"}; //check type of item*/
	int digit;						/*diget of item*/
	int numInven[6] = {0};			/*number of each type*/
	int numCheck ;					/*check type of item*/

	for (i = 0; i < 5; i++)
		{
		if (strcasecmp(type[i],info.category) == 0)
			{
			break;
			}
		}
	pIn = fopen("database.txt","r");
	while (fgets(stringInput,sizeof(stringInput),pIn) != NULL)
		{
		sscanf(stringInput,"%1d",&numCheck);
		for (k = 0;k < 5;k++)
			{
			if (numCheck == k+1)
				{
				numInven[k]++;
				}
			}
		}
	digit = ((i+1)*10000)+(numInven[i]+1);
	return(digit);
	}

/******************************************************************************
 *	Database File created by Natchapol Shinno (Nath) 61070503412
 * 	This function is use to dumpfile database and inventory
 */
void databaseFile(INFO_T info)
	{
	FILE *pOutdata = NULL;		/*This file is database that use to collect information and search*/
	FILE *pOutread = NULL;		/*This file is readable file that use to read a details about each item*/
	char alphaMonth[13][4] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	/*Array of month that use in readable file*/
	int whichMonth = 13 ; 		/*It use to locate the alphaMonth array*/
	int i = 0 ;					/*counter*/
	int day = 0;				/*day is use to dumpfile*/
	int month = 0;				/*month is use to dumpfile*/	
	int year = 0;				/*year is use to dumpfile*/
	int digit = 0;				/*digit code of each item*/

	sscanf(info.date,"%d-%d-%d",&year,&month,&day);
	whichMonth = month-1;

	digit = randomDigit(info);

	pOutdata = fopen("database.txt","a");
	pOutread = fopen("Inventory.txt","a");

	fprintf(pOutread, "DigitCode    : CPE_%05d \n",digit );
	fprintf(pOutread, "Category     : %s\n",info.category);

	fprintf(pOutdata, "%05d ",digit );
	/*If the item doesn't in computer the category It will does't has Subcategory& OS */
	if (strcasecmp(info.category,"Computer"))
		{
		strcpy(info.subcategory,"-");
		strcpy(info.operatingSystem,"-");
		fprintf(pOutread, "Subcategory  : %s\n",info.subcategory );
		fprintf(pOutread, "Operating System : %s\n",info.operatingSystem );
		}

	fprintf(pOutread, "Date         : %d %s %d \n",day ,alphaMonth[whichMonth] ,year );
	fprintf(pOutread, "Name         : %s %s\n",info.fname,info.lname );
	fprintf(pOutread, "Phone Number : %s\n",info.phonenum );
	fprintf(pOutread, "Room         : %s\n",info.room );
	fprintf(pOutread, "Description  : %s \n\n",info.description );
	
	fprintf(pOutdata, "%s %s %s %s ",info.category,info.subcategory,info.operatingSystem,info.date);
	fprintf(pOutdata, "%s %s %s %s %s\n",info.fname,info.lname,info.phonenum,info.room,info.description );
	
	fclose(pOutdata);
	fclose(pOutread);
	}

/******************************************************************************
 * Category Checking Function by Boss Thapanachart 3408 
 */
int checkCategory(char* category)
	{
	int returnVal = 0;
	char categorylist[6][12]={"Computer","Peripheral","AudioVisual","Appliance","Other"};
	int i=0;
	int wrongstack=0;
	for (i=0;i<6;i++)
		{
		if (strcasecmp(category,categorylist[i])==0)
			{
			returnVal = 1;
			break;
			}
		else
			wrongstack++;
		if (wrongstack==5)
			{
			printf("Invalid Category\n");
			returnVal = 0;
			break;
			}
		}
	return returnVal;
	}

/******************************************************************************
 * Subcategory Checking Function By Boss Thapanachart 3408 
 */
int checkSubcategory(char* subcategory,char* category)
	{
	int returnVal = 0;
	char subcategorylist[7][10]={"Server","Desktop","Notebook","Tablet","Embedded","Other"};
	int i=0;
	int wrongstack=0;
	
	if (strcasecmp(category,"Computer")==0)
		{
		for (i=0;i<7;i++)
			{
			if (strcasecmp(subcategory,subcategorylist[i])==0)
				{
				returnVal = 1;
				break;
				}
			else
				wrongstack++;
			if (wrongstack==6)
				{
				printf("Invalid Computer Subcategory\n");
				returnVal = 0;
				break;
				}
			}
		}
	return returnVal;
	}

/******************************************************************************
 * Operating System checking Function by Boss Thapanachart 3408 
 */
int checkOS(char* operatingSystem,char* category)
{
	int returnVal = 0;
	char listofOS[8][10]={"Windows","Linux","Mac_OSX","iOS","Android","Multiple","Other"};
	int i=0;
	int wrongstack=0;
	
	if(strcasecmp(category,"Computer")==0)
		{
		for (i=0;i<8;i++)
			{
			if (strcasecmp(operatingSystem,listofOS[i])==0)
				{
				returnVal = 1;
				break;
				}
			else
				wrongstack++;
			if (wrongstack==7)
				{
				printf("Invalid Computer Operating System\n");
				returnVal = 0;
				break;
				}
			}
		}
	return returnVal;
}

/******************************************************************************
 * Date Checking Function by Boss Thapanachart 3408 
 */
int checkDate(char* date,int day,int month,int year,int d,int m,int y)
{
	int dateCompare();
	int cmp=0;
	int digit=0;
	int i=0;
	int dayinmonth[13]={31,28,31,30,31,30,31,31,30,31,30,31};
	if (strlen(date)!=10)
		{
		printf("Invalid lenght of date\n");
		return 0;
		}
	if ((date[4]!='-')||(date[7]!='-'))
		{
		printf("Invalid Format of date\n");
		return 0;
		}
	for (i=0;i<11;i++)
		{
		if (isdigit(date[i]))
			digit++;
		}
	if (digit!=8)
		{
		printf("Invalid date\n");
		printf("The number of digit must equal to 8\n");
		return 0;
		}
	sscanf(date,"%4d-%2d-%2d",&year,&month,&day);
	printf("Checking %d-%d-%d\n",year,month,day);
	if (year < 1)
		{
		printf("Invalid year\n");
		return 0;
		}
	if ((month > 12)||(month < 1))
		{
		printf("Invalid month\n");
		return 0;
		}
	if (((year % 4 == 0)&&(year % 100 !=0))||(year % 400 ==0))
		dayinmonth[1]=29;
	if ((day > dayinmonth[month-1])||(day < 1))
		{
		printf("Invalid day\n");
		return 0;
		}
	else
		{
		cmp = dateCompare(day,month,year,d,m,y);
		return cmp;
		}
}

/******************************************************************************
 * Name checking Function by Boss Thapanachart 3408 
 */
int checkName(char* fname,char* lname)
	{
	int returnVal = 0;
	int isAlphaString();
	if ((isAlphaString(fname)==1)&&(isAlphaString(lname)==1))
		{
		returnVal = 1;
		}
	else
		{
		printf("Invalid name both first and last name must contain only Alphabet\n");
		returnVal = 0;
		}
	return returnVal;
	}

/******************************************************************************
 * Phone number checking Function by Boss Thapanachart 3408 
 */
int checkPhonenum(char* phonenum)
	{
	int returnVal = 0;
	int isDigitString();
	if ((strlen(phonenum)!=9)&&(strlen(phonenum)!=10))
		{
		printf("Invalid lenght of phone number\n");
		returnVal = 0;
		}
	if (isDigitString(phonenum)==0)
		{
		printf("Invalid phone number must only contain Digit\n");
		returnVal = 0;
		}
	if (phonenum[0]!='0')
		{
		printf("Invalid phone number must start with 0\n");
		returnVal = 0;
		}
	else
		returnVal = 1;
	return returnVal;
	}

/******************************************************************************
 * Room number Checking Function by Boss Thapanachart 3408 
 */
int checkRoom(char* room)
	{
	int returnVal = 1;
	int isDigitString();
	if (isDigitString(room)==0)
		{
		printf("Invalid Room number must contain only Numeric Character\n");
		returnVal = 0;
		}
	if ((room[0]!='1'))
		{
		printf("Invalid Room number must start with 10 or 11\n");
		returnVal = 0;
		}
	if (((room[1]!='0')&&(room[1]!='1')))
		{
		printf("Invalid Room number must start with 10 or 11\n");
		returnVal = 0;
		}
	if (strlen(room)!=4)
		{
		printf("Invalid lenght of room number\n");
		returnVal = 0;
		}
	return returnVal;
	}

/******************************************************************************
 * Modified Function by Boss 3408 from ioFunction.c sponsored by Aj.Sally 
 */
int isDigitString(char* digitCode)
	{
    int bOk = 1; 
    int i;
    for (i = 0; i < strlen(digitCode); i++)
        {
        if (!isdigit(digitCode[i]))
		    {
		    bOk = 0;
		    break;
		    }
		}
    return bOk;
	}

/******************************************************************************
 * Modified Function by Boss 3408 from ioFunction.c sponsored by Aj.Sally 
 */
int isAlphaString(char* testString)
    {
    int bOk = 1; 
    int i;
    for (i = 0; i < strlen(testString); i++)
		{
		if (!isalpha(testString[i]))
		    {
		    bOk = 0;
		    break;
		    }
		}
    return bOk;
    }

/******************************************************************************
 * Modified Function by Boss 3408 from dateFunction.c sponsored by Aj.Sally 
 */
void dateToday(int* pDay, int *pMonth, int* pYear)
	{
    time_t seconds = 0;    
    struct tm * pTimeStruct;

    seconds = time(&seconds);
    pTimeStruct = localtime(&seconds);
    *pDay = pTimeStruct->tm_mday;
    *pMonth = pTimeStruct->tm_mon + 1;
    *pYear = pTimeStruct->tm_year + 1900;
	}

/******************************************************************************
 * Modified Function by Boss 3408 from dateFunction.c sponsored by Aj.Sally 
 */
int dateCompare(int day,int month,int year,int d,int m,int y)
	{
	int cmp=0;

    if (year > y)
       	cmp = 0;
    else if (year < y)
       	cmp = 1;
    else if (month > m)
       	cmp = 0;
    else if (month < m)
       	cmp = 1;
    else if (day > d)
       	cmp = 0;
    else if (day < d)
       	cmp = 1;
    else	
    	cmp = 1;	
	return cmp;
	} 