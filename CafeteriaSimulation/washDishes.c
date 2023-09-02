#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <time.h>

#define clear() printf("\033[H\033[J")
#define yellow() printf("\033[0;33m")
#define green() printf("\033[0;32m")
#define reset() printf("\033[0m")
#define red() printf("\033[1;31m");

#define keyEnterence_Toout 14550
#define keyEnterence_Toin 14551

#define keyChasire1_Toout 14552
#define keyChasire1_Toin 14553

#define keyChasire2_Toout 14554
#define keyChasire2_Toin 14555

#define keyFoodPick_Toout 14556
#define keyFoodPick_Toin 14557

#define keyEating_Toout 14558
#define keyEating_Toin 14559

#define keyWashDishes_Toout 14560
#define keyWashDishes_Toin 14561

#define start_addres 14562

#define param_send 16000
#define param_send_chasier1 16001
#define param_send_chasier2 16002
#define param_send_foodpick 16003
#define param_send_eating 16004
#define param_send_wash 16005


#define chasir_1_powerup 17000
#define chasir_2_powerup 17001
#define foodpick_powerup 17002
#define eating_powerup 17003
#define washing_powerup 17004

struct mesg_buffer {
	long mesg_type;
	int mesg_data[100];
} message;

struct mesg_buffer1 {
	long mesg_type1;
	int mesg_data1[100];
} message1;


struct msqid_ds buf;

int main(){
	key_t powerUP;
	key_t dataIn;
	key_t dataOut;
	key_t param_key;
	key_t toMonitor;
	int peoplenum;
	int min;
	int max;
	int MaxLine;
	
	int msgid_powerup;
	powerUP = washing_powerup;
	msgid_powerup =  msgget(powerUP, 0666 | IPC_CREAT);
	while(1){
		clear();
		green();
		printf("WASH DISHES SECTION NODE POWERING ON\n");
		message.mesg_type = 1;
		message.mesg_data[0]=1;
		msgsnd(msgid_powerup, &message, sizeof(message), 0);
		sleep(3);
		reset();
		printf("WASH DISHES SECTION  NODE, TURNED ON ! \n");
		sleep(1);
		break;
		
	}
	
	int msgid_params;
	param_key = param_send_wash;
	msgid_params = msgget(param_key, 0666 | IPC_CREAT);
	//load parameter
	while(1){
		clear();
		printf("WASH DISHES SECTION NODE, PARAM LOAD, WAITING..\n");
		message.mesg_type = 1;
		msgrcv(msgid_params, &message, sizeof(message), 0, 0);
		min = message.mesg_data[0]; 
		max = message.mesg_data[1]; 
		MaxLine = message.mesg_data[2];
		peoplenum = message.mesg_data[3]; 
		printf("[INFO] WASH DISHES SECTION  PARAM | MIN TIME WAIT                  ->> %d s\n", min);
		printf("[INFO] WASH DISHES SECTION  PARAM | MAX TIME WAIT                  ->> %d s\n", max);
		printf("[INFO] WASH DISHES SECTION  PARAM | MAX QUEUE                      ->> %d\n", MaxLine);
		sleep(3);
		printf("WASH DISHES SECTION NODE, PARAM LOADED ! \n");
		sleep(1);
		break;
		
	}
	
	
	int msgid_datain;
	int msgid_dataout;
	int msgid_monitor;
	int lineAvailable;
	int timerCounter = 0;
	int delay=1;
	int peopleID = 0;
	int timeLeft = 0;
	int overFLow = 0;
	dataIn = keyWashDishes_Toout;
	msgid_datain = msgget(dataIn, 0666 | IPC_CREAT);
	//dataOut = keyWashDishes_Toout;
	//msgid_dataout = msgget(dataOut, 0666 | IPC_CREAT);
	toMonitor = keyWashDishes_Toin;
	msgid_monitor = msgget(toMonitor, 0666 | IPC_CREAT);
	int lastQueue=0;
	int isOverflow = 0;
	int flag=0;
	int peopleEnter=0;
	srand(time(0));
	int fristStages=0;
	while(1){
	        printf("****************WASH DISHES SECTION***********\n");
		printf("[INFO] Runing... \n");
	        clear(); 
	        msgctl(msgid_datain, IPC_STAT, &buf);
	         if (fristStages>=1){
	        for (int timer=0; timer<=delay; timer++){
	        	lineAvailable = MaxLine - (int)buf.msg_qnum;
	        	timeLeft = delay - timer;
	        	if (lineAvailable<=1){
	        	        isOverflow = 1;
	        	        if (timer==1){
			        overFLow++;
			        }
				red();
				
			
			}else{
			  isOverflow = 0;
			  reset();
			 
			
			}
			
	                message.mesg_data[1]=lineAvailable;
			message.mesg_data[2]=peopleID;
			message.mesg_data[3]=timeLeft;
			message.mesg_data[4]=overFLow;
			message.mesg_data[5]=isOverflow;
			message.mesg_data[6]=MaxLine;
			message.mesg_data[7]=(int)buf.msg_qnum;
			message.mesg_data[8]=peopleEnter;
			if ((peoplenum==peopleEnter) && (timer==delay))message.mesg_data[9]=1;
			else message.mesg_data[9]=0;
		        msgsnd(msgid_monitor, &message, sizeof(message), 0);
	   
	        	sleep(1);
	        }
	        
	        //message.mesg_data[0]=peopleID;
	        //msgsnd(msgid_dataout, &message, sizeof(message), 0);
	        }
	        fristStages++;
	        delay = (rand() %(max - min + 1)) + min;
	        if (peoplenum==peopleEnter)break;
	        flag = msgrcv(msgid_datain, &message1, sizeof(message), 0, 0);
	        
	        peopleEnter++;
	        peopleID = message1.mesg_data1[0];
	        
	        

	
	}
	
	
}



