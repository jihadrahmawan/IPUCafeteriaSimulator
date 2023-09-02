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

struct mesg_buffer2 {
	long mesg_type1;
	int mesg_data[100];
} monitor;


struct msqid_ds buf;

int main(){
	key_t powerUP;
	key_t keyChasier2;
	key_t sendtofoodpick;
	key_t param_key;
	key_t toMonitor;
	
	int minChashier;
	int maxChashier;
	int MaxLineRangeChasier;
	int peoplenum;
	int msgid_powerup;
	powerUP = chasir_2_powerup;
	msgid_powerup =  msgget(powerUP, 0666 | IPC_CREAT);
	while(1){
		clear();
		green();
		printf("CHASIER 2 NODE POWERING ON\n");
		message.mesg_type = 1;
		message.mesg_data[0]=1;
		msgsnd(msgid_powerup, &message, sizeof(message), 0);
		sleep(3);
		reset();
		printf("CHASIER 2 NODE, TURNED ON ! \n");
		sleep(1);
		break;
		
	}
	
	int msgid_params;
	param_key = param_send_chasier2;
	msgid_params = msgget(param_key, 0666 | IPC_CREAT);
	//load parameter
	while(1){
		clear();
		printf("CHASIER 2 NODE, PARAM LOAD, WAITING..\n");
		message.mesg_type = 1;
		msgrcv(msgid_params, &message, sizeof(message), 0, 0);
		minChashier = message.mesg_data[0]; 
		maxChashier = message.mesg_data[1]; 
		MaxLineRangeChasier = message.mesg_data[2]; 
		peoplenum = message.mesg_data[3];
		printf("[INFO] CHASIER PARAM | MIN TIME WAIT                  ->> %d s\n", minChashier);
		printf("[INFO] CHASIER PARAM | MAX TIME WAIT                  ->> %d s\n", maxChashier);
		printf("[INFO] CHASIER PARAM | MAX QUEUE                      ->> %d\n", MaxLineRangeChasier);
		sleep(3);
		printf("CHASIER 2 NODE, PARAM LOADED ! \n");
		sleep(1);
		break;
		
	}
	
	
	int msgid_chasier2;
	int msgid_foodpick;
	int msgid_monitor;
	char infoChasier[100];
	int sendDataQueueChasier2;
	int lineAvailable;
	int timerCounter = 0;
	int delay=1;
	int peopleID = 0;
	int timeLeft = 0;
	int overFLow = 0;
	keyChasier2 = keyChasire2_Toout;
	msgid_chasier2 = msgget(keyChasier2, 0666 | IPC_CREAT);
	sendtofoodpick = keyFoodPick_Toout;
	msgid_foodpick = msgget(sendtofoodpick, 0666 | IPC_CREAT);
	toMonitor = keyChasire2_Toin;
	msgid_monitor = msgget(toMonitor, 0666 | IPC_CREAT);
	int lastQueue=0;
	int isOverflow = 0;
	int flag=0;
	int peopleEnter=0;
	int fristStages=0;
	srand(time(0));
	while(1){
	        
	        printf("****************CHASIER #2 ***********\n");
		printf("[INFO] Runing... \n");
	        clear(); 
	        msgctl(msgid_chasier2, IPC_STAT, &buf);
	        if (fristStages>=1){
	        for (int timer=0; timer<=delay; timer++){
	                
	        	lineAvailable = MaxLineRangeChasier - (int)buf.msg_qnum;
	        	timeLeft = delay - timer;
	        	if (lineAvailable<=1){
	        	        isOverflow = 1;
	        	        if (timer==1){
			        overFLow++;
			        }
				red();
				strcpy(infoChasier,"Ups, CHASIER 2 IS FULL!"); 
			
			}else{
			  isOverflow = 0;
			  reset();
			  strcpy(infoChasier,"CHASIER 2 GOOD!"); 
			
			}
			/*
			printf("****************CHASIER #2 ***********\n");
			printf("[INFO] CHASIER LINE AVAILABLE                         ->> %d\n", lineAvailable);
			printf("[INFO] THE CHASIER 2 IS SERVING CUSTOMER_ID           ->> %d\n", peopleID);
			printf("[INFO] THE CHASIER 2 IS TIME LEFT                     ->> %d\n", timeLeft);
			printf("[INFO] THE CHASIER 2 SITUATION INFO (GOOD/OVERFLOW)   ->> %s\n", infoChasier);
			printf("[INFO] THE CHASIER 2 OVERFLOW NUMBER                  ->> %d\n", overFLow);
			printf("*************************************\n");
	                */
	                message.mesg_data[1]=lineAvailable;
			message.mesg_data[2]=peopleID;
			message.mesg_data[3]=timeLeft;
			message.mesg_data[4]=overFLow;
			message.mesg_data[5]=isOverflow;
			message.mesg_data[6]=MaxLineRangeChasier;
			message.mesg_data[7]=(int)buf.msg_qnum;
			message.mesg_data[8]=peopleEnter;
		        msgsnd(msgid_monitor, &message, sizeof(message), 0);
	   
	        	sleep(1);
	        }
	        
	        message.mesg_data[0]=peopleID;
	        msgsnd(msgid_foodpick, &message, sizeof(message), 0);
	        }
	        fristStages++;
	        delay = (rand() %(maxChashier - minChashier + 1)) + minChashier;
	        if (peoplenum==peopleEnter)break;
	        flag = msgrcv(msgid_chasier2, &message1, sizeof(message), 0, 0);
	        
	        peopleEnter++;
	        peopleID = message1.mesg_data1[0];
	        

	
	}
	return 0;
	
	
}



