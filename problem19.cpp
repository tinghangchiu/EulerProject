#include <stdio.h>

bool leapyear(int year){
	
	if(year%4==0){
		
		if(year%100 == 0){
			if(year%400==0){
				return true;
			}
			else
				return false;
		}
		return true;
	}
	else{
	return false;	
	}
	
	
	
	
}

int main(){
	int year = 1901;
	int month = 1;
	int day = 1;
	int sunday = 0;
	int currentday=2;
	bool checkflag = false;
	bool is_leapyear = false;
		
	while(year<=2000){
		
	if(checkflag == false){
		is_leapyear = leapyear(year);
		
		checkflag = true;
	}
	
	day++;
	currentday++;
	
	
	if(currentday==7 ){
		
		if(day==1)
		sunday++;
		
	
		currentday=0;	
		
	}
	
	if(month == 2){
		
		if(is_leapyear==true){
			if(day==29){
				//printf("%d\n",year);
				month++;
				day=0;
			}
			
		}
		else{
			if(day==28){
				
				month++;
				day=0;
			}
			
		}	
	}
	
	if(month == 1 || month ==3 || month ==5 || month ==7|| month ==8||month==10||month==12){
		if(day==31){
			month++;
			day=0;
		}
		
	}
	
	if(month == 4 || month ==6 || month ==9 || month ==11){
		if(day==30){
			month++;
			day=0;
		}
	}
	
	if(month>=13){
		year++;
		month=1;
		checkflag = false;
	}
		
		
		
		
		
		
	}
	
	printf("sunday: %d",sunday);
	
	return 0;
}
