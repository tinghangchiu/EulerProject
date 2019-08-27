#include <stdio.h>




int main(){
	int ary[20][20];
	
	int i=0;
	int j=0;
	int count = 0;
	int age;
	char ch;
	FILE *fs;
	fs = fopen("p11.txt", "r");
	
	while(count<400 ){ //fscanf will auto ignore '\n' and " " and need to count how many item is inserted which unable to read eof
	//fscanf (fs, "%d", &ch) != EOF can be used but the first number will be missed . To solve this, use do and while loop
	//fscanf() returns the number of items successfully scanned
	fscanf (fs, "%d", &age);//fscanf use space to descriminate end of number
	//ch = getw(fs);
	//printf("%d\n",age);
	
	ary[i][j]=age;
	j++;
	if(j>19){
		i++;
		j=0;
	} 
	count ++;
	//printf("cout:%d\n",count);
		 	
}

	for(int a=0;a<20;a++){
		for(int b=0;b<20;b++){
			printf("%d",ary[a][b]);
			printf(" ");
		}
		printf("\n");
	}
	
	//horizontal()
	long long int tmp=0;
	long long int tmp2=0;
	
	long long int hori = 0;
	for(int a=0;a<20;a++){
		for(int b=0;b<17;b=b+1){
			tmp = ary[a][b] * ary[a][b+1]*ary[a][b+2]*ary[a][b+3];
			if(tmp>tmp2)
			tmp2=tmp;
		}
			
	}
	hori = tmp2;
	printf("max h:%lld\n",hori);
	
	//vertical()
	long long int vertical;
	for(int a=0;a<20;a++){
		for(int b=0;b<17;b=b+1){
			tmp = ary[b][a] * ary[b+1][a]*ary[b+2][a]*ary[b+3][a];
			if(tmp>tmp2)
			tmp2=tmp;
		}	
	}
	vertical = tmp2;
	printf("max v:%lld\n",vertical);
	
	//NW diagonal
	// a=16 b=0, start point
	int nwdiag;
	for(int a=16;a>-1;a--){
		for(int b=0;b<19-2-a;b++){
			//printf("%d %d %d %d\n",ary[a+b][b],ary[a+b+1][b+1],ary[a+b+2][b+2],ary[a+b+3][b+3]);
			tmp = ary[a+b][b]*ary[a+1+b][b+1]*ary[a+b+2][b+2]*ary[a+b+3][b+3]; 
			if(tmp>tmp2)
			tmp2 = tmp;
		}
	}
	nwdiag = tmp2;
	printf("max nw:%d\n",nwdiag);
	
		for(int a=16;a>=0;a--){
		for(int b=0;b<19-a-2;b++){
			//printf("%d %d %d %d\n",ary[a+b][b],ary[a+b+1][b+1],ary[a+b+2][b+2],ary[a+b+3][b+3]);
			tmp = ary[b][a+b]*ary[b+1][a+1+b]*ary[b+2][a+2+b]*ary[b+3][a+3+b]; 
			if(tmp>tmp2)
			tmp2 = tmp;
		}
	}
	nwdiag = tmp2;
	printf("max nw:%d\n",nwdiag);
	
	
	//SW diagonal
	long long int swdiag;
	for(int a=16;a>-1;a--){
		for(int b=19;b>a+2;b--){
			int c = b-a-3;
			tmp = ary[a+c][b]*ary[a+1+c][b-1]*ary[a+2+c][b-2]*ary[a+3+c][b-3]; 
			if(tmp>tmp2)
			tmp2 = tmp;
		}
	}
	swdiag = tmp2;
	printf("max sw:%lld\n",swdiag);
	
	for(int a=3;a<20;a++){
		for(int b=0;b<a-2;b++){
			//tmp = ary[b][a]*ary[b+1][a-1]*ary[b+2][a-2]*ary[b+3][a-3]; 
			tmp = ary[a-b][b]*ary[a-1-b][b+1]*ary[a-2-b][b+2]*ary[a-3-b][b+3];
			if(tmp>tmp2)
			tmp2 = tmp;
		}
	}
	swdiag = tmp2;
	printf("maxsw :%lld\n",swdiag);
	
		
	return 0;
}
