#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define N 10

bool IsLeapYear(int year);
int MonthDays(int month, int year);
bool valide_date(int dd, int mm, int yy);
long Read_and_Calculate(int curyear);

main() {
    int curyear;
    
	printf("Current year ? "); curyear = GetInteger();

	printf("SYNOLO FPA ---> %ld\n", Read_and_Calculate(curyear));
}

bool IsLeapYear(int year)
{
    return ( ((year % 4 == 0) && (year % 100 != 0))
             || (year % 400 == 0) );
}

int MonthDays(int month, int year)
{
	switch (month)
	{
		case  2:		
			if (IsLeapYear(year)) return (29);
			return(28);
		case 4: case 6:	case 9:	case 11:
            return(30);
		default:
			return(31);
	}
}

bool valide_date(int dd, int mm, int yy)
{
	int days;

	days = MonthDays(mm, dd);

	if ( (yy>0) &&	((mm>=1)&&(mm<=12)) && ((dd>=1)&&(dd<=days)) )
			return TRUE;
	else
			return FALSE;
}



long Read_and_Calculate(int curyear)
{
	int day, month, year, tax;
	long sumFPA;

	sumFPA = 0;
	printf("Day ? ");	day = GetInteger();
	while ( day != -1 )
    {
	 	printf("Month ? ");	month = GetInteger();
   		printf("Year ? ");	year = GetInteger();
		printf("FPA ? ");	tax = GetInteger();
		
		if ( (year == curyear) && (valide_date(day, month, year)) )
		      sumFPA += tax; 
		
		printf("Day ? ");	day = GetInteger();
	}
    
	return sumFPA;
}


