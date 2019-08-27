#include <stdio.h>


int main(){
	
	int ary[500];
	for(int i=0;i<500;i++){
		ary[i]=0;
	}
	ary[0]=1;
	int index = 0;
	int product = 0;
	int carry = 0;
	int j;
	
	for(int i=0;i<1000;i++){
		carry=0;
		for(j=0;j<=index;j++){
			product = ary[j]*2+carry;
			//printf("%d: %d\n",ary[0],carry);
			if(product>=10){
				carry=1;
				ary[j]=product%10;		
			}
			else{
				carry=0;
				ary[j]=product;
			}
			//printf("%d\n",j);
		} 	
			if(j==index+1 && carry ==1){
				ary[index+1] = ary[index+1]+1;
				index++;
			}
		
		
	}
	
	
	
	
	
	int count=0;
	for(int i=301;i>=0;i--){
		printf("%d",ary[i]);
		count = count + ary[i];
}
	printf("\n %d",count);
	return 0;
} 
