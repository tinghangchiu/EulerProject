#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a,b,c;
	for(a=0;a<1001;a++){
		for(b=a+1;b<1000;b++){
			c = a*a + b*b;
			c = sqrt(c); 
			//printf("integer:%f\n",c);
			if(a+b+c == 1000){
				printf("a:%f b:%f c:%f",a,b,c); 
				//do not use %d to print double otherwise the number cannot be correctly printed e.g 0 or negative value use %f instead
			}
			//printf("float:%d\n",c);
		}
	}

	return 0;
}
