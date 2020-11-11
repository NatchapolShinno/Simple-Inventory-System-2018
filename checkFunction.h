/*  checkFunction.h
 *
 *	This header file use to keep all about function to use in this programs
 *  that are located in checkFunction.c 
 *
 *	Created by: Mr.Supakij Buasod 61070503438 (24 November 2018)
 *	Update:  12 December 2018
 */

typedef struct 
	{
	char category[20];			/*Category of each item*/
	char subcategory[20];		/*Subcategory is only in computer category*/
	char operatingSystem[10];	/*It only computer category*/
	char date[15];				/*date that you add this item*/
	char fname[30];				/*first name of who responsible the item*/
	char lname[30];				/*last name of who responsible the item*/
	char phonenum[11];			/*phone number of who responsible the item*/
	char room[5];				/*room that you keep the item*/
	char description[512];		/*description about the item*/
	}	INFO_T;

/* 	Category checking function by Boss Thapanachart 3408 
 *	This function use to check category from input data 
 * 	If invalid return 0 , if valid return 1 */
int checkCategory();

/*	Subcategory checking function By Boss Thapanachart 3408
 * 	This function use to check subcategory about inventory 
 * 	If invalid return 0 , if valid return 1 */
int checkSubcategory();

/*  Operating system checking function by Boss Thapanachart 3408
 *	This function use to check operating system about inventory 
 * 	If invalid return 0 , if valid return 1 */
int checkOS();

/*  Date Checking function by Boss Thapanachart 3408
 *	This function use to check input date is valid or not in form 
 * 	If invalid return 0 , if valid return 1 */
int checkDate();

/*  Name checking function by Boss Thapanachart 3408
 * 	This function use to check only alphabet from input name of user
 * 	If invalid return 0 , if valid return 1 */
int checkName();

/*  Phone number checking function by Boss Thapanachart 3408
 * 	This function use to check only number input from phone number 
 * 	If invalid return 0 , if valid return 1 */
int checkPhonenum();

/*  Room number Checking Function by Boss Thapanachart 3408
 * 	This function use to check error about room in CPE
 * 	If invalid return 0 , if valid return 1 */
int checkRoom();

/*  Modified Function by Boss 3408 from ioFunction.c sponsored by Aj.Sally 
 * 	This function use to check all input is digit 
 * 	If invalid return 0 , if valid return 1 */
int isDigitString();

/*  Modified Function by Boss 3408 from ioFunction.c sponsored by Aj.Sally
 * 	This function use to check all input is alpha 
 * 	If invalid return 0 , if valid return 1 */
int isAlphaString();

/*  Modified Function by Boss 3408 from dateFunction.c sponsored by Aj.Sally
 *	This function use to check today date and keep it in pointer */
void dateToday();

/*  Modified Function by Boss 3408 from dateFunction.c sponsored by Aj.Sally
 *	Compares two dates. Returns 1 if the 
 * 	first date is later than the second, -1 if the 
 * 	first date is earlier than the second, and 0 if they are the same.*/
int dateCompare();

/*	Created by Natchapol Shinno (Nath) 61070503412 
 *	This function is use to created the code digit of each of inventory */
int randomDigit();

/* 	Database File created by Natchapol Shinno (Nath) 61070503412
 * 	This function is use to dumpfile database and inventory */
void databaseFile();
