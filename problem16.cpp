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
	
	for(int i=0;i<1000;i++){
		for(int j=0;j<=index;j++){
			product = (ary[0]+carry)*2;
			if(product>=10){
				carry=1;
				ary[j]=product%10;
				index++;
			}
			else{
				carry=0;
				ary[j]=product;
			}
			if(j==index && carry ==1){
				ary[index+1] = ary[index+1] + 1;
			}
			
			//printf("%d\n",j);
		} 
		
		
		
		
	}
	
	
	
	for(int i=index+1;i>=0;i--){
		printf("%d",ary[i]);
}
	return 0;
} 
