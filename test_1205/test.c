#include<stdio.h>
#include<Windows.h>
int is_leap_year(int y)
{
	
		if ((y % 4 == 0) && (y % 100 != 0) || y % 400 == 0)
		{
			return 1;
		}

		else
		{
			return 0;
		}
	

}



//int main()
//{
//	int year;
//
//	for (year = 1000; year <= 2000; year++)
//	{
//		if ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0)
//		{
//			printf("%d ", year);
//		}
//	}
//	
//
//
//
//
//
//	return 0;
//}


int main()
{
	int year;

	for (year = 1000; year <= 2000; year++)
	{
		if (is_leap_year(year))
		{
			system("color 0a");
			printf("%d ", year);
		}
	}
		


	return 0;
}