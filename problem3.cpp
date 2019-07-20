#include <stdio.h>
#include <cmath>
#include <iostream> 
#include <limits>

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

int main(){
	
	// floor return largest integer that is smaller than or equal to x
	//printf("%lld",n); //remember to use lld instead of %d to print long long int 
	//std::cout << sizeof(long long int)<<std::endl;
	//std::cout << std::numeric_limits<long long int>::max() << std::endl;
    //std::cout << std::numeric_limits<unsigned long long int>::max() << std::endl;
	
	long long int n = 600851475143;
	bool flag = false;
	//n = floor(sqrt((double)n)); // 775146
	for(int i=775146;i>0;i--){
		flag = is_prime(i);
		if(flag == true){
			if(n%i == 0){
				printf("found: %d\n",i);
				break;
			}
			
		}
		
	}
	printf("%lld",n);
	//n = sqrt(600851475143);
	
	
	return 0;
}


