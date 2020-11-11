/*  searchFunction.h
 *
 *	This header file use to keep all about function to use in this programs
 *  that are located in searchFunction.c 
 *
 *	Created by: Mr.Supakij Buasod 61070503438 (9 December 2018)
 *	Update: 12 December 2018
 */
 
typedef struct
	{
	char Incode[6];				/* cpe inventory code */
	char category[32];
	char subcategory[32];
	char operating_system[32];
	int year;					/* Western year format eg. 2018 */
	int month;					/* month in form mm */
	int day;					/* date in form dd */
	char firstname[64];			/* first name of person responsible */
	char lastname[64];			/* last name of person responsible */
	char phoneNumber[12];		/* phone number of responsible person */
	char location[10];			/* four digit room in 10th and 11th floors */
	char description[512];		/* free from text */
	} DATABASE_T;
 
 /****************************************************************************
 * this function will print out the information for database 
 * CPE inventory system.
 * 'cpe' is the database that we will print
 */
 void Information();

/****************************************************************************
 * This function will check alphabetica of code that user input.
 * 'code' is the input fron the user
 * This function will return alpha = 1 if has alphabet
 */
 int AlphaCode();

/****************************************************************************
 * A function of searching CPE inventory code.
 * 'pIn' is the pointer for reading
 * This function will search from inventory code until the user enters "N".
 */
 void InventoryCode();

/****************************************************************************
 * A function of searching by category.
 * 'pIn' is the pointer for reading
 * This function will search from inventory code until the user enters "N".
 */
 void Category();

/****************************************************************************
 * A function of searching by year purchased.
 * 'pIn' is the pointer for reading
 * This function will search from inventory code until the user enters "N".
 */
 void Date();

/****************************************************************************
 * This function will check that has alphabet in location or not?
 * 'location' is the input from the user
 * This function will return alpha = 1 if has alphabet.
 */
 int alphaLocation();

/****************************************************************************
 * This function will check that the location on 10th or 11th floors.
 * 'location' is the input from the user 
 * This function will return check = 1 if location is not 
 * on 10th or 11th floors
 */ 
 int checkLocation();

/****************************************************************************
 * A function of searching by location
 * 'pIn' is the pointer for reading
 * This function will search from inventory code until the user enters "N".
 */
 void Location(); 

 void deleteItem();