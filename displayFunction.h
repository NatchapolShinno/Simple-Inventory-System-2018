/*  displayFunction.h
 *
 *	This header file use to keep all about function to use in this programs
 *  that are located in displayFunction.c 
 *
 *	Created by: Mr.Supakij Buasod 61070503438 (12 December 2018)
 *	Update:  12 December 2018
 */

typedef struct 
	{
	char digitCode[10];			/*digit code of an item*/
	char category[128];			/*category of an item*/
	char subCategory[128];		/*subcategory of an item*/
	char os[128];				/*operating system of an item*/
	char date[128];				/*date the item purchase*/
	char firstName[128];		/*first name of person responsibly with an item*/
	char lastName[128];			/*last name of person responsibly with an item*/
	char phoneNumber[128];		/*phone number of person responsibly with an item*/
	char room[10];				/*room where an item is*/
	char description[1024];		/*description of an item*/
	}INV_T;

/* 	This function display the current contents of the 
 *  database (all objects) on the screen. */
void displayAll();