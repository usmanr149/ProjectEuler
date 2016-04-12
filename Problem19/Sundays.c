#include<stdio.h>
//get the day on a given date

int days_in_month[] = {0, 31, 28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
char *days[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};

void is_leapyear(int year){

	if(year%4 == 0)
		if(year/100 != 1 || year%400 == 0)
			days_in_month[2] = 28;
	else 
		days_in_month[2] = 29;
}

void calendar(int year){
	int month = 1, day;
	int i = 0, total = 0;
	int y, day_code;
	int number_of_interest, number_of_sundays = -2;

	for(y = 1900; y < 2001; y++){
		total += days_in_month[month - 1];
		is_leapyear(y);
		for(month = 1; month <= 12; month++){
			total += days_in_month[month - 1];
			day_code = total%7;
			for (day = 1; day <= days_in_month[month]; day++){
				number_of_interest = (day + day_code)%7;
				//printf("%d\t", day);
				//printf("%d : %s : %d : %s \n", year, months[month], day, days[number_of_interest]);
				//getchar();
				if(day == 1 && days[number_of_interest] == "Sunday"){
					//printf("%d : %s : %d : %s \n", year, months[month], day, days[number_of_interest]);
					number_of_sundays++;
				}
			}
		}
	}
	printf("number_of_sundays = %d\n", number_of_sundays);
}

int main(){
	//printf("Hello World!\n");
	calendar(1900);
}