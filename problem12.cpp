#include <stdio.h>
#include <cmath>


int main(){
	int n;
	int tri;
	int count = 1;
	int tmp=0;
	int max;
	
	for(n=2;n<15000;n++){
		//n=41040;
		tri = n*(n+1)/2;
		//printf("tri: %d\n",tri);
		
		while(count<=sqrt((double)tri)){ 
		//important part here, divsor can be never greater than squart root of the divend ,ignore quotient which can be greater,and the
		// numer of divosr should be added by two coz quotient should be counted too
			
			if(tri%count==0){
				if(tri/count==count)
				tmp++;
				else
				tmp = tmp +2;
				if(tmp>=500){
					printf("done:%d\n",tri);
					break;
				}
			}
			count++;
			
		}
		
		
		//printf("tri:%d tmp:%d\n",tri,tmp);
		tmp=0;
		count=1;
	}
	
	
	
	
	
	
}
