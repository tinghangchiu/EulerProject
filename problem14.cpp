#include <stdio.h>

int count = 10;
int tmp = 0;
int tmp2 =0;

int odd(int i);
int even(int i);

int main(){
	
	long long int i=13;
	while(i<=1000000){
		long long int j = i;
		//printf("%d\n",j);
		//tmp++;
		while(j>1){
			tmp++;
			if(j%2==0){
			//printf(" %d ",j);
			j=j/2;	
			}
			else{
			//printf(" %d ",j);
			j=3*j+1;
			}
				
			if(j==1){
			tmp++;
			tmp2++;	
			}
			
			//printf(" %d ",j);
		}
		//printf(" tmp:%d",tmp);
		//printf(" tmp2: %d",tmp2);
		//printf("\n");
		
			if(tmp>count){
				printf(" i:%lld %lld\n",i,tmp);
				count = tmp;
			}
			
			
		
		
		tmp=0;
		i++;
	}
	
	
	
	
	return 0;
}

/*
int main(){ //recurrsion version unable to function since terms too large
	
	int i=13;
	int j=0;
	while(i<=1000000){
	
	if(i%2!=0){
	tmp++;
	j=odd(i);
	}
	else{
	tmp++;
	j=even(i);
	}
	i++;
	
	
	if(tmp>count){
		count = tmp;
		printf("i:%d count:%d\n",i,count);
	}
	
	
	
	
	tmp = 0;
}
	
	return 0;
}

int odd(int i){
	i = 3*i+1;
	//printf(" %d",i);
	if(i==1||tmp>count){
	tmp++;
	return tmp;	
	}
	 
	if(i%2!=0){
		tmp++;
		return odd(i);
	}
	else{
		tmp++;
		return even(i);
	}
	
	
	
	
}


int even(int i){
	i=i/2; 
	//printf(" %d ",i);
	if(i==1 || tmp>count){
		tmp++;
		return tmp;
	}
	
	
	if(i%2!=0){
		tmp++;
		return odd(i);
	}
	else{
		tmp++;
		return even(i);
	}
	
	
	
}
*/
