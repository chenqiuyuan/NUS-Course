#include <stdio.h>
#include <stdlib.h>
#define N 5

int free_stack_top;
int free_stack[N];//for free rooms
int busy_stack_top;
int busy_stack[N];//for busy rooms

struct T{
	int t;//value of point
	int flag;//0-start & 1-end
	int id_sf;
};

void setT(T time,int t,int flag,int id_sf){
	time.t=t;
	time.flag=flag;
	time.id_sf=id_sf;
}

struct R{
	int id;//index of activity
//	int id[N];
	int num;
};
int room_num;//number of room
void setR(R room,int id,int num){
	R.id = id;
	R.num = num;
}

T time[2*N];
R r[N];

void initialize(){
	room_num=0;
//test example:A1[0,3]A2[1,3]A3[3,4]A4[5,7]A5[6,10]	
	setT(time[1],0,0,1)
	setT(time[2],1,0,2)
	setT(time[3],3,1,1)
	setT(time[4],3,1,2)
	setT(time[5],3,0,3)
	setT(time[6],4,1,3)
	setT(time[7],5,0,4)
	setT(time[8],6,0,5)
	setT(time[9],7,1,4)
	setT(time[10],10,1,5)
}

	

void busy(){
	printf("busy\n");
}//put the R into the busy
void free(){
	printf("free\n");
}//push the R into the stack
void get_free(){
	printf("get_free\n");
} 
void match(){
	printf("match, value> map;\n");
}//find the match of activity
void new_room(){
	room_num++;//produce a new room

		
	printf("new_room\n");
}//new a Room
void assign(){
	printf("assign\n");
} 




void sweep(){
	for (int i = 0; i < (2*N); ++i){
		if (time[i].flag == 1){
			match();
			assign();
			free();
		
		}else if(time[i].flag  == 0)
		{
			if (free_stack == 0){
				new_room();
				busy();
				get_free();

			}else{
				busy();
			}
		}
	}
}



int main(void){	
		initialize();

		printf("helloworld!\n");
		printf("%d\n",time[0].t );
	}

