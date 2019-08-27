#include<stdio.h>

int one = 3;
int two = 3;
int three = 5;
int four = 4;
int five = 4;
int six = 3;
int seven = 5;
int eight = 5;
int nine = 4;
int ten = 3;
int teen = 4;
int eleven= 6;
int twelve = 6;
int thirteen = 8;
int twenty = 6;
int thirty = 6;
int fourty = 5;
int fifty = 5;
int sixty = 5;
int seventy = 7;
int eighty = 6;
int ninety = 6;
int hundred = 7;
int a_n_d = 3;
	
int number(int n){ //1 - 10

	if(n==0)
	return 0;
	if(n == 1)
	return one;
	if(n ==2)
	return two;
	if(n == 3)
	return three;
	if(n ==4)
	return four;
	if(n==5)
	return five;
	if(n==6)
	return six;
	if(n==7)
	return seven;
	if(n==8)
	return eight;
	if(n==9)
	return nine;
	if(n==10)
	return ten;
	if(n == 11)
	return eleven;
	if(n==12)
	return twelve;
	if(n == 13)
	return thirteen;
	if(n== 14)
	return 8;
	if(n ==15)
	return 7;
	if(n==16)
	return 7;
	if(n==17)
	return 9;
	if(n==18)
	return 8;
	if(n==19)
	return 8;
	
}

int number2(int n){ // 20 - 90

	
	if(n ==2)
	return twenty;
	if(n == 3)
	return thirty;
	if(n ==4)
	return fourty;
	if(n==5)
	return fifty;
	if(n==6)
	return sixty;
	if(n==7)
	return seventy;
	if(n==8)
	return eighty;
	if(n==9)
	return ninety;
	
	return 0;
	
}

int main(){
	
	
	
	
	int count = 0;
	int tmp;
	
	for(int i=1;i<=1000;i++){
		
		if(i>=1 && i<=19){
			count = count + number(i);
			printf("%d\n",number(i));
			continue;
		}
		
		if(i>=20 && i<=99){
			count = count + number(i%10) + number2(i/10);
			continue;
		}
		
	
		if(i >=100 && i<=999){
			
			if(i%10 == 0 && i%100 == 0){
				count = count + number(i/100) + hundred;
			}
			else{
				
				if(i%100<=19){
					count = count + number(i/100) + hundred + a_n_d + number(i%100);
				}
				else{
					
					count = count + number(i/100) + hundred + a_n_d + number2((i/10)%10) + number(i%10);
				}
				
	
			}
			continue;
		}
		
		if(i==1000){
				count = count + 11;
				continue;
		}
	
	} 
	
	printf("%d",count);
	
	
	
	return 0;
}
