#include<stdio.h>

void reset(int ary[]){
	for(int i=0;i<20000;i++){
		ary[i]=0;
	}
	
}

void set(int ary[],int n){
	if(n>=10){
	ary[0]=n%10;
	n = n/10;
	ary[1] = n;	
	}
	else{
		ary[0]=n;
		ary[1]=0;
	}
	
	
}

int main(){
	
	int ary1[20000];
	int ary2[20000];
	int answer[20000];
	int tmp[2];
	
	reset(ary1);
	reset(ary2);
	reset(answer);
	
	answer [0] = 0;
	answer [1] = 0;
	answer [2] = 1;
	
	int index=2;
	int count=0;
	int carry=0;
	
	for(int i=99;i>=1;i--){
		
		set(tmp,i);
		
		for(int j=0;j<20000;j++){
			
			count = answer[j]*tmp[1];
		
			//ary1[j+1] = count % 10;
			if(j==0){
				
				ary1[j+1] = ary1[j+1]+count%10;
			
				ary1[j+2] = ary1[j+2] + (count/10)%10;
				
			}
			else{
				
				if(ary1[j+1]+count%10>=10){
				carry=1;	
				}
				else{
				carry=0;	
				}
				
				
				ary1[j+1] = (ary1[j+1]+count%10)%10;
				
				if(ary1[j+2]+(count/10)%10+carry>=10){
					ary1[j+3] = ary1[j+3]+1;
				} 
				
				ary1[j+2] = (ary1[j+2]+ (count/10)%10 + carry)%10;
				
				
				
				
			}
			
				
		}
		
		if(i==99){
			for(int m=5;m>=0;m--){
				printf("%d",ary1[m]);
			}
			printf("\n");
		}
		ary1[0]=0;
		
		for(int k=0;k<20000;k++){
			
			count = answer[k]*tmp[0];
		
			//ary1[j+1] = count % 10;
			if(k==0){
				
				ary2[k] = ary2[k]+count%10;
			
				ary2[k+1] = ary2[k+1] + (count/10)%10;
				
			}
			else{
				
				if(ary2[k]+count%10>=10){
				carry=1;	
				}
				else{
				carry=0;	
				}
				
				
				ary2[k] = (ary2[k]+count%10)%10;
				
				if(ary2[k+1]+(count/10)%10+carry>=10){
					ary2[k+2] = ary2[k+2]+1;
				} 
				
				ary2[k+1] = (ary2[k+1]+ (count/10)%10 + carry)%10;
				
				
				
				
			}
		
				
		}
		
		
		if(i==99){
			for(int m =4;m>=0;m--){
				printf("%d",ary2[m]);
			}
			printf("\n");
		}
		
		carry=0;
		
		for(int h=0;h<20000;h++){
			if(ary1[h]+ary2[h]+carry>=10){
				answer[h]=(ary1[h]+ary2[h]+carry)%10;
				carry=1;
			}
			else{
				answer[h] = ary1[h] + ary2[h]+carry;
				carry=0;
			}
			
		}
		/* 
		if(i==90){
			for(int m=25;m>=0;m--){
				printf("%d",answer[m]);
			}
			printf("\n");
		}
		*/ 
		if(i==1){
			int saving = 0;
			for(int k=0;k<20000;k++){
				saving = saving + answer[k]; 
			}
			printf("%d",saving);
		} 
	
		
		reset(ary1);
		reset(ary2);
		carry=0; 
			
	}
	
	
	 
	
	return 0;
}
