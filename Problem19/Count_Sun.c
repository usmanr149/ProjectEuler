#include<stdio.h>

#define TRUE 1
#define FALSE 0

int days_in_month[] = {0, 31, 28,31,30,31,30,31,31,30,31,30,31};

void is_leapfire(int year){

	if(year%4 == 0 && (year/100 != 0 || year/400 == 0)) {
		days_in_month[2] = 29;
	}	
	else 
		days_in_month[2] = 28;
}

void calendar(int year){
	int month = 1, day;
	int i = 0, total = 0;
	int y, day_code;
	for(y = 1901; y < 2001; y++){
		total += days_in_month[month - 1];
		is_leapfire(y);
		printf("year = %d\n", y);
		getchar();
		for(month = 1; month <= 12; month++){
			printf("\nSun\tMon\tTue\tWed\tThu\tFri\tSat\n");
			total += days_in_month[month - 1];
			day_code = total%7;
			//printf("day_code = %d\n", day_code);
			for(i = 0; i < (day_code); i++)
				printf(" \t");
			for (day = 1; day <= days_in_month[month]; day++){
				printf("%d\t", day);
				if((day + day_code)%7 == 0)	printf("\n");
			}
			printf("\n");
		}
	}
}

int main(){
	//printf("Hello World!\n");
	calendar(2000);
}