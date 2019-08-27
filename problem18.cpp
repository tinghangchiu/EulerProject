#include<stdio.h>
#include<math.h>

struct node{
	
	int tmp=0;
	int row=0;
	int column=0;
};

int main(){
	
	node total[16384];
	int ary [15][15];
	
	FILE *fs;
	fs = fopen("number_18.txt", "r");
	int a=0;
	int b=0;
	int count =0;
	int age;
	int line = 0;


	
	while(count<120 ){ //fscanf will auto ignore '\n' and " " and need to count how many item is inserted which unable to read eof
	//fscanf (fs, "%d", &ch) != EOF can be used but the first number will be missed . To solve this, use do and while loop
	//fscanf() returns the number of items successfully scanned
	fscanf (fs, "%d", &age);//fscanf use space to descriminate end of number
	//ch = getw(fs);
	//printf("%d\n",age);
	
	ary[a][b]=age;
	//printf("%d ",age);
	b++;
	if(b>line){
		a++;
		b=0;
		//printf("\n");
		line++;
	} 
	count ++;
	//printf("cout:%d\n",count);
		 	
}
 
 /*
for(int i=0;i<15;i++){
	for(int j=0;j<15;j++){
		printf("%d ",ary[i][j]);
	}
	printf("\n"); 
}
*/

	for(int i=0;i<16384;i++){
		total[i].tmp=75;
		total[i].column=0;
		total[i].row=0;
	}
	
	int n;
	int aryindex;
	int current;
	int index;
	int index2;
	int countloop;
	int startingpos;
	bool flag;
	
	
	for(int i=1;i<15;i++){//15
		
		
		index = 16384/pow(2,i);//wrong
		//printf("%d ",index);
		index2 = index;
		//printf("%d ",index);
		aryindex=0;
		current=0;
		startingpos=0;
		flag = true;
		//printf("go");
		while(1){
			
			
			while(current<index){
				if(flag==true){
					
					total[current].row = total[current].row + 1;
					total[current].column = total[current].column;
					total[current].tmp = ary[total[current].row][total[current].column]+total[current].tmp;//ary index never exceed 15
					
				}
				else{
					total[current].row = total[current].row + 1;
					total[current].column = total[current].column + 1;
					total[current].tmp = ary[total[current].row][total[current].column]+total[current].tmp;//ary index never exceed 15
				}
			
				
				current++;
				
				
			}
			
			if(flag == true)
			flag = false;
			else
			flag = true;

			if(current==16384)
			break;
			
			index=index+index2;
			
			
			
			
			
		}
		
		
					if(i==2){
			for(int l=0;l<16384;l++){
				if(total[l+1].tmp!=total[l].tmp)
		printf("%d %d\n",total[l].tmp,l);	
	}
	//printf("%d",aryindex);
}



	} 
	
	int tmp=0;
	for(int i=0;i<16384;i++){
		if(tmp<total[i].tmp)
		tmp = total[i].tmp;	
		//printf("%d\n ",total[i]);	
	}
	printf("largest: %d\n",tmp);
	
	
	return 0;
}
