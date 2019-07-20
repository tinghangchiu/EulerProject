#include <stdio.h>
#include <unistd.h>

void One_Pairs();
void Two_Pairs();
void Three_of_a_kind();
void Straight();
void Flush();
void Full_House();
void Four_of_a_kind();
void Straight_Flush();
void Royal_Flush();
void sort();
void A_chbk();
void High_Card();

int ary1[5];
int ary2[5];
int ary3[5];
int ary4[5];

struct index{
	int index1;
	int index2;	
	
}gg;

int play1 = 0;
int play2 = 0;

int one =0;
int two=0;
int three=0;
int four=0;
int st=0;
int flu=0;
int royal = 0;
int full = 0;




int main()
{
    FILE *fp;
     char temp[29];
    fp = fopen("poker.txt","r");
    
    gg.index1=0;
    gg.index2=0;
     
    int count =0 ;
    while( fgets (temp, 1000, fp)!= NULL ) {
  /* write contents to standard output */
        puts(temp);
        for(int i=0;i<29;i++){
        	
        	if(temp[i]=='T')
        	temp[i] = ':';
        	
        	if(temp[i]=='J')
        	temp[i] = ';';
			
			if(temp[i]=='Q')
			temp[i] = '<';
			
			if(temp[i]=='K')
			temp[i] = '=';
			
			if(temp[i]=='A')
			temp[i] = '1';       	
		}
		
		/*
		for(int i=0;i<5;i++){
			if(temp[i]>)
			ary[i] 
		}
		*/
		
        ary1[0] = temp[0] ;
        ary1[1] = temp[3] ;
        ary1[2] = temp[6] ;
        ary1[3] = temp[9] ;
        ary1[4] = temp[12] ;
        
        ary2[0] = temp[15] ;
        ary2[1] = temp[18] ;
        ary2[2] = temp[21] ;
        ary2[3] = temp[24] ;
        ary2[4] = temp[27] ;
        
        ary3[0] = temp[1] ; //suit for ary1
        ary3[1] = temp[4] ;
        ary3[2] = temp[7] ;
        ary3[3] = temp[10] ;
        ary3[4] = temp[13] ;
        
        ary4[0] = temp[16] ; //suit for ary2
        ary4[1] = temp[19] ;
        ary4[2] = temp[22] ;
        ary4[3] = temp[25] ;
        ary4[4] = temp[28] ;
        
      
        
       
        
        sort();
        
       
        
        //High_Card();
        One_Pairs();
        Two_Pairs();
        Three_of_a_kind();
        Straight();
        Flush();
        Full_House();
        Four_of_a_kind();
        Straight_Flush();
        Royal_Flush();
        
        if(gg.index1 > gg.index2)
        play1 ++;
        if(gg.index2> gg.index1)
        play2 ++;
        if(gg.index1 == gg.index2){
        	A_chbk();
        	sort();
        	High_Card();
		}
		
		printf("index 1: %d\n",gg.index1);
		printf("index 2: %d\n",gg.index2);
		
		if(gg.index1 == 8 || gg.index2 ==8)
		count=1;
		
		gg.index1 = 0;
		gg.index2 = 0;
		
		
              
     }
     printf("play1: %d\n",play1);
     printf("play2: %d\n",play2);
     printf("index: %d\n",count);
    
 	 fclose(fp);

    return 0;
}


void sort(){
	
	char tmp;
	for(int i=0;i<5;i++){
		for(int j=i+1;j<5;j++){
			if(ary1[i]>ary1[j]){
				tmp = ary1[i];
				ary1[i] = ary1[j];
				ary1[j] = tmp;
			}
			
			if(ary2[i]>ary2[j]){
				tmp = ary2[i];
				ary2[i] = ary2[j];
				ary2[j] = tmp;
			}
			
		}
	}
	
	
}

void Royal_Flush(){
	
	bool flush1=true;
	bool flush2=true;
	
	if(ary1[0]!='1' || ary1[1]!= ':' || ary1[2]!= ';' || ary1[3]!= '<' || ary1[4]!='=' )
	flush1 = false;
	if(ary2[0]!='1' || ary2[1]!= ':' || ary2[2]!= ';' || ary1[3]!= '<' || ary1[4]!='=' )
	flush2 = false;
	
	if(ary3[0]!=ary3[1] || ary3[0]!=ary3[2] || ary3[0]!=ary3[3] || ary3[0]!=ary3[4] )
	flush1 = false;
	if(ary4[0]!=ary4[1] || ary4[0]!=ary4[2] || ary4[0]!=ary4[3] || ary4[0]!=ary4[4] )
	flush2 = false;
	
	//missing special case
	
	if(flush1 == true)
	gg.index1=9;
	if(flush2 == true)
	gg.index2=9;
	
}

void Four_of_a_kind(){
	
	bool flush1=false;
	if(ary1[0]==ary1[1] && ary1[0]==ary1[2] && ary1[0]==ary1[3] )
	flush1=true;
	if(ary1[1]==ary1[2] && ary1[1]==ary1[3] && ary1[1]==ary1[4] )
	flush1=true;
	
	bool flush2=false;
	if(ary2[0]==ary2[1] && ary2[0]==ary2[2] && ary2[0]==ary2[3] )
	flush2=true;
	if(ary2[1]==ary2[2] && ary2[1]==ary2[3] && ary2[1]==ary2[4] )
	flush2=true;
	
	if(flush1 == true)
	gg.index1 = 7;
	
	if(flush2 == true)
	gg.index2 = 7;
	
	
}

void Straight_Flush(){
	
	bool flush1=true;
	bool flush2=true;
	for(int i=0;i<4;i++){
		if(ary1[i]+1!=ary1[i+1])
		flush1 = false;
		if(ary2[i]+1!=ary2[i+1])
		flush2 = false;
		if(flush1==false && flush2 == false)
		break;	
	}
	
	if(ary3[0]!=ary3[1] || ary3[0]!=ary3[2] || ary3[0]!=ary3[3] || ary3[0]!=ary3[4] )
	flush1 = false;
	if(ary4[0]!=ary4[1] || ary4[0]!=ary4[2] || ary4[0]!=ary4[3] || ary4[0]!=ary4[4] )
	flush2 = false;
	
	//missing special case
	
	if(flush1 == true)
	gg.index1= 8;
	if(flush2 == true)
	gg.index2= 8;
	
}

void Full_House(){
	
	bool flush1 = false;
	bool flush2 = false;
	
		
	if(ary1[0]==ary1[1] && ary1[0]==ary1[2] && ary1[3]==ary1[4] )
	flush1 = true;
	if(ary1[0]==ary1[1] && ary1[2]==ary1[3] && ary1[2]==ary1[4] )
	flush1 = true;
	
	
	if(ary2[0]==ary2[1] && ary2[0]==ary2[2] && ary2[3]==ary2[4] )
	flush2 = true;
	if(ary2[0]==ary2[1] && ary2[2]==ary2[3] && ary2[2]==ary2[4] )
	flush2 = true;
	

	//missing special case
	
	if(flush1 == true)
	gg.index1=6;
	if(flush2 == true)
	gg.index2=6;
	
	
	
}

void Flush(){
	
	bool flush1 = false;
	bool flush2 = false;
	
		
	if(ary3[0]==ary3[1] && ary3[0]==ary3[2] && ary3[0]==ary3[3] && ary3[0]==ary3[4]  )
	flush1 = true;
	
	
	
	if(ary4[0]==ary4[1] && ary4[0]==ary4[2] && ary4[0]==ary4[3] && ary4[0]==ary4[4]  )
	flush2 = true;
	
	

	//missing special case
	
	if(flush1 == true)
	gg.index1=5;
	if(flush2 == true)
	gg.index2=5;
		
}

void Straight(){
	
	bool flush1=true;
	bool flush2=true;
	for(int i=0;i<4;i++){
		if(ary1[i]+1!=ary1[i+1])
		flush1 = false;
		if(ary2[i]+1!=ary2[i+1])
		flush2 = false;
		if(flush1==false && flush2 == false)
		break;	
	}
	
	
		
	//missing special case	
	if(flush1 == true)
	gg.index1= 4;
	if(flush2 == true)
	gg.index2= 4;
		
}

void Three_of_a_kind(){
	
	bool flush1 = false;
	bool flush2 = false;
	
		
	if(ary1[0]==ary1[1] && ary1[0]==ary1[2]  )
	flush1 = true;
	if(ary1[1]==ary1[2] && ary1[1]==ary1[3]  )
	flush1 = true;
	if(ary1[2]==ary1[3] && ary1[2]==ary1[4]  )
	flush1 = true;
	
	if(ary2[0]==ary2[1] && ary2[0]==ary2[2]  )
	flush2 = true;
	if(ary2[1]==ary2[2] && ary2[1]==ary2[3]  )
	flush2 = true;
	if(ary2[2]==ary2[3] && ary2[2]==ary2[4]  )
	flush2 = true;
	
	

	//missing special case
	if(flush1 == true)
	gg.index1=3;
	if(flush2 == true)
	gg.index2=3;	
}

void Two_Pairs(){
	
	bool flush1 = false;
	bool flush2 = false;
	
		
	if(ary1[0]==ary1[1] && ary1[2]==ary1[3]  )
	flush1 = true;
	if(ary1[0]==ary1[1] && ary1[3]==ary1[4]  )
	flush1 = true;
	if(ary1[1]==ary1[2] && ary1[3]==ary1[4]  )
	flush1 = true;
	
	
	if(ary2[0]==ary2[1] && ary2[2]==ary2[3]  )
	flush2 = true;
	if(ary2[0]==ary2[1] && ary2[3]==ary2[4]  )
	flush2 = true;
	if(ary2[1]==ary2[2] && ary2[3]==ary2[4]  )
	flush2 = true;
	
	

	//missing special case
	if(flush1 == true)
	gg.index1=2;
	if(flush2 == true)
	gg.index2=2;
	
}

void One_Pairs(){
	
	bool flush1 = false;
	bool flush2 = false;
	
		
	if(ary1[0]==ary1[1])
	flush1 = true;
	if(ary1[1]==ary1[2]   )
	flush1 = true;
	if(ary1[2]==ary1[3]  )
	flush1 = true;
	if(ary1[3]==ary1[4]  )
	flush1 = true;
	
	
	if(ary2[0]==ary2[1])
	flush2 = true;
	if(ary2[1]==ary2[2]   )
	flush2 = true;
	if(ary2[2]==ary2[3]  )
	flush2 = true;
	if(ary2[3]==ary2[4]  )
	flush2 = true;
	
	

	//missing special case
	if(flush1 == true)
	gg.index1=1;
	if(flush2 == true)
	gg.index2=1;
	
	
	
	
}

void A_chbk(){
	for(int i=0;i<5;i++){
		if(ary1[i]=='1')
		ary1[i]='>'; 
		if(ary2[i]=='1')
		ary2[i]='>'; 
	}
}

void High_Card(){
	//A case
	
	switch(gg.index1){
		
		case 0: {
		for(int i=4;i>=0;i--){
			if(ary1[i]>ary2[i]){
				play1++;
				break;
			}
			if(ary1[i]<ary2[i]){
				play2++;
				break;
			}	
		}
		break; 
	}
	
		case 1: {
		
		char tmp1,tmp2;
		for(int i=0;i<4;i++){
			for(int j=i+1;j<5;j++){	
			if(ary1[i]==ary1[j])
			tmp1=ary1[i];
			if(ary2[i]==ary2[j])
			tmp2=ary2[i];
		}
		}
		if(tmp1>tmp2)
		play1++;
		if(tmp2>tmp1)
		play2++;
		if(tmp2==tmp1){
			for(int i=4;i>=0;i--){
			if(ary1[i]>ary2[i]){
				play1++;
			break;
			}
			if(ary1[i]<ary2[i]){
				play2++;
				break;
			}	
		}
		}
		break;
	}
	
		case 2: {
			char temp[4]={'0','0','0','0'};   //
			for(int i=0;i<5;i++){
			for(int j=i+1;j<5;i++){	
			if(ary1[i]==ary1[j]){
			if(temp[0]=='0')
			temp[0]=ary1[i];
			else
			temp[1]=ary1[i];
			}
			if(ary2[i]==ary2[j]){
			if(temp[2]=='0')
			temp[2]=ary1[i];
			else
			temp[3]=ary1[i];
			}
		}
		}
		if(temp[0]>temp[2]&&temp[0]>temp[3] || temp[1]>temp[2] && temp[1]>temp[3]){
		play1++;
		break;
	}
	
		if(temp[2]>temp[0]&&temp[2]>temp[1] || temp[3]>temp[0] && temp[3]>temp[1]){
		play2++;
		break;
	}
			break; 
		}
		
		case 3: {
	char atmp1,atmp2,atmp3,atmp4;
			if(ary1[0]==ary1[1] && ary1[0]==ary1[2] && ary1[3]==ary1[4] ){
				atmp1 = ary1[0];
				atmp3 = ary1[3];
			}
	if(ary1[0]==ary1[1] && ary1[2]==ary1[3] && ary1[2]==ary1[4] ){
		atmp1 = ary1[2]; //three
		atmp3 = ary1[1];
	}
		
	if(ary2[0]==ary2[1] && ary2[0]==ary2[2] && ary2[3]==ary2[4] ){
		atmp2 = ary2[0];
		atmp4 = ary2[3];
	}
	
	if(ary2[0]==ary2[1] && ary2[2]==ary2[3] && ary2[2]==ary2[4] ){
		atmp2 = ary2[2]; //three
		atmp4 = ary2[1];
	}
	if(atmp1 > atmp2)
	play1++;
	if(atmp1<atmp2)
	play2++;
		
		break;
	}
	
		case 4:{
			for(int i=4;i>=0;i--){
			if(ary1[i]>ary2[i]){ 
			play1++;
			break;
		}
			if(ary1[i]<ary2[i]){
				play2++;
				break;
			}	
		}
		break;
		}
			
		case 5:{
		
			for(int i=4;i>=0;i--){
			if(ary1[i]>ary2[i]){
				play1++;
				break;
			}
			if(ary1[i]<ary2[i]){
				play2++;
				break;
			}		
		}
		break;
	}
		
		case 6:{
		 char tmp1,tmp2,tmp3,tmp4;
			if(ary1[0]==ary1[1] && ary1[0]==ary1[2] && ary1[3]==ary1[4] ){
				tmp1 = ary1[0];
				tmp3 = ary1[3];
			}
	if(ary1[0]==ary1[1] && ary1[2]==ary1[3] && ary1[2]==ary1[4] ){
		tmp1 = ary1[2]; //three
		tmp3 = ary1[1];
	}
		
	if(ary2[0]==ary2[1] && ary2[0]==ary2[2] && ary2[3]==ary2[4] ){
		tmp2 = ary2[0];
		tmp4 = ary2[3];
	}
	
	if(ary2[0]==ary2[1] && ary2[2]==ary2[3] && ary2[2]==ary2[4] ){
		tmp2 = ary2[2]; //three
		tmp4 = ary2[1];
	}
	if(tmp1 > tmp2)
	play1++;
	if(tmp1<tmp2)
	play2++;		
		break;
	}
	
		case 7:{
		 char tmp1,tmp2,tmp3,tmp4;
		if(ary1[0]==ary1[1] && ary1[0]==ary1[2] && ary1[0]==ary1[3] ){
			tmp1 = ary1[0];
			tmp3 = ary1[4];
		}
		
	if(ary1[1]==ary1[2] && ary1[1]==ary1[3] && ary1[1]==ary1[4] ){
			tmp1 = ary1[1];
			tmp3 = ary1[0];
	}


	if(ary2[0]==ary2[1] && ary2[0]==ary2[2] && ary2[0]==ary2[3] ){
		tmp2 = ary2[0];
		tmp4 = ary2[4];
	}
	
	if(ary2[1]==ary2[2] && ary2[1]==ary2[3] && ary2[1]==ary2[4] ){
		tmp2 = ary2[1];
		tmp4 = ary2[0];
	}
	
	if(tmp1 > tmp2)
	play1++;
	if(tmp1<tmp2){
		play2++;
	}
	if(tmp1 == tmp2){
		if(tmp3>tmp4)
		play1++;
		else
		play2++;
	}	
		break;
	}
	
		case 8:{
		for(int i=4;i>=0;i--){
			if(ary1[i]>ary2[i]){
			play1++;
			break;
		}
			if(ary1[i]<ary2[i]){
			play2++	;
			break;
		}
		}			
		break;
	}
	
		case 9: {
		int tmp1 , tmp2;
			if(ary3[0]=='S')
			tmp1 = 4;
			if(ary3[0]=='H')
			tmp1 = 3;
			if(ary3[0]=='C')
			tmp1 = 2;
			if(ary3[0]=='D')
			tmp1 = 1;
			if(ary4[0]=='S')
			tmp2 = 4;
			if(ary4[0]=='H')
			tmp2 = 3;
			if(ary4[0]=='C')
			tmp2 = 2;
			if(ary4[0]=='D')
			tmp2 = 1;
			
			if(tmp1>tmp2)
			play1++;
			else
			play2++;
		break;
	}
	
	
	
}
}


