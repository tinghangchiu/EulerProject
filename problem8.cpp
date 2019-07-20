#include <stdio.h>
#include <stdlib.h>




int main(){
	FILE *fs;
	char ch;
	int num;
	
	 int tmpp =1;

	 int tmp3 = 0;
	 int tmp22;
	int ary1[1000];
	int index = 0;
	int calculate[20];
	

	
	fs = fopen("number.txt", "r");
	
	while(ch != EOF){
	ch = fgetc(fs);
	if(index==1000)
	break;
	if(ch == '\n' ){
		//printf("\n");
		//printf("%d %d\n",ary1[index],index);
		//index++;
		continue;
	}
	else{ 
	num = ch - '0';
	ary1[index] = num;
	printf("%d %d %d\n",num,ary1[index],index);
	index++;
	
	} 	
}


long long int tmp;
long long int tmp2;
tmp = 1;
tmp2 = 0;
int j,i;
int k,l;
int count = 0;
bool r = true;
for(i=0;i<987;i++){
	
	for(j=i;j<i+13;j++){
		tmp = tmp * ary1[j];
	}
	if(tmp>tmp2 ){
		
		tmp2 = tmp;
		k=i;
		l=j;
		printf("%lld\n",tmp2);
		
		
	}
	tmp=1;
}

printf("%d %d",k,l);
for(i=88;i<101;i++){
	printf("hi: %d ",ary1[i]);
}



return 0 ;
}
