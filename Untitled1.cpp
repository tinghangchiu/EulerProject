#include <stdio.h>
#include <stdlib.h>

typedef struct queueCDT *queueADT;

queueADT EmptyQueue();
void Enqueue(queueADT queue, int element);
int Dequeue(queueADT queue);
int tail_Length(queueADT queue);
int QueueIsEmpty(queueADT queue);

struct cellT{
	int data;
	struct cellT *next;
}cell;

struct queueCDT{
	cellT *head;
	cellT *tail;
};

queueADT EmptyQueue() {
   queueADT queue;
   queue =(queueADT) malloc(sizeof(struct queueCDT));
   queue->head = NULL;
   queue->tail = NULL;
   return queue;
}


void enqueue(queueADT queue,int n){
	cellT *cell;
   cell = (cellT *)malloc(sizeof(cellT));
   cell->data = n;
   cell->next = NULL;
   if (QueueIsEmpty(queue))
      queue->head = cell;
   else
      queue->tail->next = cell;
   queue->tail = cell;

}

int dequeue(queueADT queue){
	int data;
   cellT *cell;
   
   if (QueueIsEmpty(queue))
      exit(0);
      
   cell = queue->head;
   data = cell->data;
   queue->head = cell->next;
   free(cell);
   return data;	
}

int tail_length(queueADT queue){
	cellT *cell;
   int count = 0;
   cell = queue->head;
   while (cell != NULL) {
      count++;
      cell = cell->next;
   }
   return count;
}

int QueueIsEmpty(queueADT queue){
   return (tail_Length(queue) == 0);
   // or: return (QueueLength(queue) == 0);
}

	


int main(){
	FILE *fs;
	char ch;
	int num;
	int tmp =1;
	int tmp2 = 0;
	
	 queueADT queue = EmptyQueue();
	 queueADT queue2 = EmptyQueue();
	
	fs = fopen("number.txt", "r");
	
	while(ch != EOF){
	ch = fgetc(fs);
	if(ch == '\n' || ch==EOF)
	printf("\n");
	else{ 
	num = atoi(&ch);
	enqueue(queue,num);
	} 	
}

for(int i=0;i<13;i++){
	int j = dequeue(queue);
	tmp = j * tmp;
	enqueue(queue2 , j);
}
printf("%d",tmp);
 tmp2 = tmp;
//printf("%d", tail_length(queue2));


	int j = dequeue(queue2);
	printf("%d", j);
	/*
	int k = dequeue(queue);
	tmp2 = tmp2/j;
	tmp2 = tmp2*k;
	if(tmp2 >tmp)
	tmp = tmp2;
	enqueue(queue2,k);
	

printf("%d",tmp);
*/
return 0 ;
}
