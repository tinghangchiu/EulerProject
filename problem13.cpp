#include <stdio.h>


int main(){
	
	FILE *fs;
	fs = fopen("p13.txt", "r");
	int ary[5000];
	int ary2[5000];
	char ch = ' ';
	int index = 0;
	int num;
	long long int tmp = 0;
	
	while(index<5000){
	ch = fgetc(fs);
	if(ch == '\n' ){
		//printf("\n");
		continue;
	}
	else{ 
	num = ch - '0';
	ary[index] = num;
	tmp = ary[index]+tmp;
	//printf("%lld\n",tmp);
	//printf("%d",ary[index]);
	index++;
	
	} 
	
}

long long int n;
int count = 0;
int carry = 0;
int max=50;

int tmp_ary[50];

for(int i=0;i<5000;i++){
	ary2[i]=0;
}

for(int i=49;i>=0;i--){
	ary2[count] = ary[i];	//ary2 is inserted completely
	////printf("%d",ary2[count]);
	count++;
}

//printf("\n");


count = 49;
max=50;
carry = 0;
bool calculate = false;
int sum = 0;
//int tmp = 0;

for(int j=0;j<99;j++){
	count =49;
	
for(int q=(j+1)*50;q<(j+2)*50;q++){//insert the second array to the 50th array for summation //correct
	tmp_ary[count]=ary[q];
	count--;	
}

carry=0;
for(int i=0;i<50;i++){
	sum = tmp_ary[i] + ary2[i]+carry; //sumation of two array
	
	if(sum>=10){
		
		ary2[i]=sum%10;
		
		carry = 1;
	}
	else{
		ary2[i]=sum;
		carry=0;
	}
	
	if(i == 49 && carry==1)
	calculate = true;
	else
	calculate = false;
}



if(calculate == true){ //need to do the sum after 50th digit
	for(int i=50;i<=max;i++){
		sum = ary2[i]+carry;
		if(sum>=10){
			ary2[i]=sum%10;
			
			carry = 1;
			max++;
		}
		else{
			ary2[i]=sum;
			carry=0;
		}
	}
}


} 

printf("%d\n",max);
for(int i =max+8;i>=0;i--){
	printf("%d",ary2[i]);
}

	
	return 0;
}
