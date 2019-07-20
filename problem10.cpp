#include<stdio.h>
#include<cmath>

bool is_prime(int n){
	if(n == 1)
	return false;
	else if(n<4)
	return true;
	else if(n %2 ==0)
	return false;
	else if(n<9)
	return true;
	else if(n %3 == 0)
	return false;
	else{
		
		int r = floor(sqrt((double)n));
		int f = 5;
		while(f<=r){
			if(n%f==0)
			return false;
			if(n%(f+2)==0)
			return false;
			f=f+6;
		}
		return true;
		
		
		
	}
	
	
	
	
	
}

long long int calculate_prime(){
	long long int n = 17;
	 int tmp=12;
		while(tmp<2000000){
			if(is_prime(tmp-1))
			n=n+(tmp-1);
			if(is_prime(tmp+1))
			n=n+(tmp+1);
			tmp = tmp+6;
		}
		
		return n;
			
}



int main(){
	long long int tmp=0;
	bool flag = false;
	
	tmp = calculate_prime();
	
	
	printf("%lld",tmp);
	
	
	
	
	return 0;
}
