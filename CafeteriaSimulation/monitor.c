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
#define red() printf("\033[1;31m")

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
#define monitor_powerup 17005
struct mesg_buffer {
	long mesg_type;
	int mesg_data[100];
} message;

struct mesg_buffer_1 {
	long mesg_type;
	int mesg_data[100];
} message_chs1;



struct msqid_ds buf;

int main(){
	key_t powerUP;
        int msgid_powerup;
	powerUP = monitor_powerup;
	msgid_powerup =  msgget(powerUP, 0666 | IPC_CREAT);
	while(1){
		clear();
		green();
		printf("MONITOR NODE POWERING ON\n");
		message.mesg_type = 1;
		message.mesg_data[0]=1;
		msgsnd(msgid_powerup, &message, sizeof(message), 0);
		sleep(3);
		reset();
		printf("MONITOR NODE, TURNED ON ! \n");
		sleep(1);
		break;
		
	}

	key_t chs;
	key_t chs2;
	key_t foodpickdata;
	key_t eatingdata;
	key_t washdata;
    
	int msgid_chasier1;
	int msgid_chasier2;
	int msgid_foodpick;
	int msgid_eating;
	int msgid_washdata;
	
	
	char infoChasier1[100];
	char infoChasier2[100];
	char infofoodpick[100];
	char infoeating[100];
	char infowashdata[100];
	
	int lineAvailable[5];
	int peopleID[5];
	int timeLeft[5];
	int infoChasier[5];
	int overFLow[5];
	int isOverflow[5];
	int maxQueue[5];
	int Queue[5];
	int peopleEntered[5];
	int isNOdesAvailable[5]={0,0,0,0,0};
	int peopleExited[300];
	int isMsgCome[5];
	int terminted;
	int timerCounter = 0;
	
	chs = keyChasire1_Toin;
	msgid_chasier1 = msgget(chs, 0666 | IPC_CREAT);
	
	chs2 = keyChasire2_Toin;
	msgid_chasier2 = msgget(chs2, 0666 | IPC_CREAT);
	
	foodpickdata = keyFoodPick_Toin;
	msgid_foodpick = msgget(foodpickdata, 0666 | IPC_CREAT);
	
	eatingdata = keyEating_Toin;
	msgid_eating = msgget(eatingdata, 0666 | IPC_CREAT);
	
	washdata = keyWashDishes_Toin;
	msgid_washdata = msgget(washdata, 0666 | IPC_CREAT);
	
	
	while(1){
	         timerCounter++;
	        
	         if (msgrcv(msgid_chasier1, &message_chs1, sizeof(message_chs1), 0, IPC_NOWAIT) >= 0){
	         	lineAvailable[0]=message_chs1.mesg_data[1];
			peopleID[0]=message_chs1.mesg_data[2];
			timeLeft[0]=message_chs1.mesg_data[3];
			overFLow[0]=message_chs1.mesg_data[4];
			isOverflow[0]=message_chs1.mesg_data[5];
	         	isMsgCome[0]=message_chs1.mesg_data[5];
	         	maxQueue[0]=message_chs1.mesg_data[6];
	         	Queue[0]=message_chs1.mesg_data[7];
	         	isNOdesAvailable[0]=1;
	         	peopleEntered[0]=message_chs1.mesg_data[8];
	         }
	         
	         if (msgrcv(msgid_chasier2, &message_chs1, sizeof(message_chs1), 0, IPC_NOWAIT) >= 0){
	         	lineAvailable[1]=message_chs1.mesg_data[1];
			peopleID[1]=message_chs1.mesg_data[2];
			timeLeft[1]=message_chs1.mesg_data[3];
			overFLow[1]=message_chs1.mesg_data[4];
			isOverflow[1]=message_chs1.mesg_data[5];
	         	isMsgCome[1]=message_chs1.mesg_data[5];
	         	maxQueue[1]=message_chs1.mesg_data[6];
	         	Queue[1]=message_chs1.mesg_data[7];
	         	isNOdesAvailable[1]=1;
	         	peopleEntered[1]=message_chs1.mesg_data[8];
	         	
	         }
	         
	         if (msgrcv(msgid_foodpick, &message_chs1, sizeof(message_chs1), 0, IPC_NOWAIT) >= 0){
	         	lineAvailable[2]=message_chs1.mesg_data[1];
			peopleID[2]=message_chs1.mesg_data[2];
			timeLeft[2]=message_chs1.mesg_data[3];
			overFLow[2]=message_chs1.mesg_data[4];
			isOverflow[2]=message_chs1.mesg_data[5];
	         	isMsgCome[2]=message_chs1.mesg_data[5];
	         	maxQueue[2]=message_chs1.mesg_data[6];
	         	Queue[2]=message_chs1.mesg_data[7];
	         	isNOdesAvailable[2]=1;
	         	peopleEntered[2]=message_chs1.mesg_data[8];
	         	
	         }
	         
	         if (msgrcv(msgid_eating, &message_chs1, sizeof(message_chs1), 0, IPC_NOWAIT) >= 0){
	         	lineAvailable[3]=message_chs1.mesg_data[1];
			peopleID[3]=message_chs1.mesg_data[2];
			timeLeft[3]=message_chs1.mesg_data[3];
			overFLow[3]=message_chs1.mesg_data[4];
			isOverflow[3]=message_chs1.mesg_data[5];
	         	isMsgCome[3]=message_chs1.mesg_data[5];
	         	maxQueue[3]=message_chs1.mesg_data[6];
	         	Queue[3]=message_chs1.mesg_data[7];
	         	isNOdesAvailable[3]=1;
	         	peopleEntered[3]=message_chs1.mesg_data[8];
	         	
	         }
	         
	         if (msgrcv(msgid_washdata, &message_chs1, sizeof(message_chs1), 0, IPC_NOWAIT) >= 0){
	         	lineAvailable[4]=message_chs1.mesg_data[1];
			peopleID[4]=message_chs1.mesg_data[2];
			timeLeft[4]=message_chs1.mesg_data[3];
			overFLow[4]=message_chs1.mesg_data[4];
			isOverflow[4]=message_chs1.mesg_data[5];
	         	isMsgCome[4]=message_chs1.mesg_data[5];
	         	maxQueue[4]=message_chs1.mesg_data[6];
	         	Queue[4]=message_chs1.mesg_data[7];
	         	isNOdesAvailable[4]=1;
	         	peopleEntered[4]=message_chs1.mesg_data[8];
	         	terminted = message_chs1.mesg_data[9];
	         	
	         }
	         
	         
	         
	         if (timerCounter>=1000){
	         	if (isNOdesAvailable[0]==1){
		       		if (isOverflow[0]==0){
		       		green();
		       		printf("_____________________________________________________________\n");
				printf("NODES : CHASIER #1\n");
				printf("[INFO] CHASIER LINE AVAILABLE                         ->> %d\n", lineAvailable[0]);
				printf("[INFO] CHASIER QUEUE NUMBER                           ->> %d\n", Queue[0]);
				printf("[INFO] THE CHASIER 1 IS SERVING CUSTOMER_ID           ->> %d\n", peopleID[0]);
				printf("[INFO] THE CHASIER 1 IS TIME LEFT                     ->> %d\n", timeLeft[0]);
				printf("[INFO] THE CHASIER 1 OVERFLOW NUMBER                  ->> %d\n", overFLow[0]);
				if ((isOverflow[0]==0) && (lineAvailable[0]>=maxQueue[0])){
				   strcpy(infoChasier1,"CHASIER 1 IS WAITING NEW CUSTOMER");
				}else{
				 strcpy(infoChasier1,"CHASIER 1 IS SERVING CUSTOMER");
				}
				printf("[INFO] THE CHASIER 1 IS                               ->> %s\n", infoChasier1);
				printf("[INFO] NUMBER PEOPLE ENTERED                          ->> %d\n", peopleEntered[0]);
				reset();
				}else{
				
				red();
				printf("_____________________________________________________________\n");
				printf("NODES : CHASIER #1\n");
				
				printf("[INFO] CHASIER LINE AVAILABLE                         ->> %d\n", lineAvailable[0]);
				printf("[INFO] CHASIER QUEUE NUMBER                           ->> %d\n", Queue[0]);
				printf("[INFO] THE CHASIER 1 IS SERVING CUSTOMER_ID           ->> %d\n", peopleID[0]);
				printf("[INFO] THE CHASIER 1 IS TIME LEFT                     ->> %d\n", timeLeft[0]);
				printf("[INFO] THE CHASIER 1 OVERFLOW NUMBER                  ->> %d\n", overFLow[0]);
				strcpy(infoChasier1,"CHASIER 1 IS FULL !!!");
				printf("[INFO] THE CHASIER 1 IS                               ->> %s\n", infoChasier1);
				printf("[INFO] NUMBER PEOPLE ENTERED                          ->> %d\n", peopleEntered[0]);
				reset();

				}
			}
			
			if (isNOdesAvailable[1]==1){
				if (isOverflow[1]==0){
		       		green();
				printf("_____________________________________________________________\n");
				printf("NODES : CHASIER #2\n");
				printf("[INFO] CHASIER LINE AVAILABLE                         ->> %d\n", lineAvailable[1]);
				printf("[INFO] CHASIER QUEUE NUMBER                           ->> %d\n", Queue[1]);
				printf("[INFO] THE CHASIER 2 IS SERVING CUSTOMER_ID           ->> %d\n", peopleID[1]);
				printf("[INFO] THE CHASIER 2 IS TIME LEFT                     ->> %d\n", timeLeft[1]);
				printf("[INFO] THE CHASIER 2 OVERFLOW NUMBER                  ->> %d\n", overFLow[1]);
				if ((isOverflow[1]==0) && (lineAvailable[1]==maxQueue[1])){
				   strcpy(infoChasier2,"CHASIER 2 IS WAITING NEW CUSTOMER");
				}else{
				 strcpy(infoChasier2,"CHASIER 2 IS SERVING CUSTOMER");
				}
				printf("[INFO] THE CHASIER 2 IS                               ->> %s\n", infoChasier2);
				printf("[INFO] NUMBER PEOPLE ENTERED                          ->> %d\n", peopleEntered[1]);
				reset();
				}else{
				
				red();
				printf("_____________________________________________________________\n");
				printf("NODES : CHASIER #2\n");
				printf("[INFO] CHASIER LINE AVAILABLE                         ->> %d\n", lineAvailable[1]);
				printf("[INFO] CHASIER QUEUE NUMBER                           ->> %d\n", Queue[1]);
				printf("[INFO] THE CHASIER 2 IS SERVING CUSTOMER_ID           ->> %d\n", peopleID[1]);
				printf("[INFO] THE CHASIER 2 IS TIME LEFT                     ->> %d\n", timeLeft[1]);
				printf("[INFO] THE CHASIER 2 OVERFLOW NUMBER                  ->> %d\n", overFLow[1]);
				strcpy(infoChasier2,"CHASIER 2 IS FULL !!!");
				printf("[INFO] THE CHASIER 2 IS                               ->> %s\n", infoChasier2);
				printf("[INFO] NUMBER PEOPLE ENTERED                          ->> %d\n", peopleEntered[1]);
				reset();

				}
			
			}
			
			if (isNOdesAvailable[2]==1){
				if (isOverflow[2]==0){
		       		green();
				printf("_____________________________________________________________\n");
				printf("NODES : FOOD PICKING\n");
				printf("[INFO] FOOD PICK LINE AVAILABLE                         ->> %d\n", lineAvailable[2]);
				printf("[INFO] FOOD PICK QUEUE NUMBER                           ->> %d\n", Queue[2]);
				printf("[INFO] FOOD PICK IS SERVING CUSTOMER_ID           	->> %d\n", peopleID[2]);
				printf("[INFO] FOOD PICK IS TIME LEFT                     	->> %d\n", timeLeft[2]);
				printf("[INFO] FOOD PICK OVERFLOW NUMBER                  	->> %d\n", overFLow[2]);
				if ((isOverflow[2]==0) && (lineAvailable[2]==maxQueue[2])){
				   strcpy(infofoodpick,"FOOD PICK IS WAITING NEW CUSTOMER");
				}else{
				 strcpy(infofoodpick,"FOOD PICK IS SERVING CUSTOMER");
				}
				printf("[INFO] FOOD PICK IS                               	->> %s\n", infofoodpick);
				printf("[INFO] NUMBER PEOPLE ENTERED                          	->> %d\n", peopleEntered[2]);
				reset();
				}else{
				
				red();
				printf("_____________________________________________________________\n");
				printf("NODES : FOOD PICK\n");
				printf("[INFO] FOOD PICK AVAILABLE                         	->> %d\n", lineAvailable[2]);
				printf("[INFO] FOOD PICK QUEUE NUMBER                           ->> %d\n", Queue[2]);
				printf("[INFO] FOOD PICK IS SERVING CUSTOMER_ID           	->> %d\n", peopleID[2]);
				printf("[INFO] FOOD PICK IS TIME LEFT                     	->> %d\n", timeLeft[2]);
				printf("[INFO] FOOD PICK OVERFLOW NUMBER                  	->> %d\n", overFLow[2]);
				strcpy(infofoodpick,"FOOD PICK IS FULL !!!");
				printf("[INFO] FOOD PICK IS                               	->> %s\n", infofoodpick);
				printf("[INFO] NUMBER PEOPLE ENTERED                          	->> %d\n", peopleEntered[2]);
				reset();

				}
			
			}
			
			if (isNOdesAvailable[3]==1){
				if (isOverflow[3]==0){
		       		green();
				printf("_____________________________________________________________\n");
				printf("NODES : EATING ROOM \n");
				printf("[INFO] EATING ROOM LINE AVAILABLE                       ->> %d\n", lineAvailable[3]);
				printf("[INFO] EATING ROOM QUEUE NUMBER                         ->> %d\n", Queue[3]);
				printf("[INFO] EATING ROOM IS SERVING CUSTOMER_ID           	->> %d\n", peopleID[3]);
				printf("[INFO] EATING ROOM IS TIME LEFT                     	->> %d\n", timeLeft[3]);
				printf("[INFO]EATING ROOM OVERFLOW NUMBER                  	->> %d\n", overFLow[3]);
				if ((isOverflow[3]==0) && (lineAvailable[3]==maxQueue[3])){
				   strcpy(infoeating,"EATING ROOM IS WAITING NEW CUSTOMER");
				}else{
				 strcpy(infoeating,"EATING ROOM IS SERVING CUSTOMER");
				}
				printf("[INFO] EATING ROOM IS                               	->> %s\n", infoeating);
				printf("[INFO] NUMBER PEOPLE ENTERED                          	->> %d\n", peopleEntered[3]);
				reset();
				}else{
				
				red();
				printf("_____________________________________________________________\n");
				printf("NODES : EATING ROOM\n");
				printf("[INFO] EATING ROOM AVAILABLE                         	->> %d\n", lineAvailable[3]);
				printf("[INFO] EATING ROOM QUEUE NUMBER                         ->> %d\n", Queue[3]);
				printf("[INFO] EATING ROOM IS SERVING CUSTOMER_ID           	->> %d\n", peopleID[3]);
				printf("[INFO] EATING ROOM IS TIME LEFT                     	->> %d\n", timeLeft[3]);
				printf("[INFO] EATING ROOM OVERFLOW NUMBER                  	->> %d\n", overFLow[3]);
				strcpy(infoeating,"EATING ROOM IS FULL !!!");
				printf("[INFO] EATING ROOM IS                               	->> %s\n", infoeating);
				printf("[INFO] NUMBER PEOPLE ENTERED                          	->> %d\n", peopleEntered[3]);
				reset();

				}
			
			}
			
			if (isNOdesAvailable[4]==1){
				if (isOverflow[4]==0){
		       		green();
				printf("_____________________________________________________________\n");
				printf("NODES : WASH DISHES ROOM \n");
				printf("[INFO] WASH DISHES ROOM LINE AVAILABLE                  ->> %d\n", lineAvailable[4]);
				printf("[INFO] WASH DISHES ROOM QUEUE NUMBER                   	->> %d\n", Queue[4]);
				printf("[INFO] WASH DISHES ROOM IS SERVING CUSTOMER_ID          ->> %d\n", peopleID[4]);
				printf("[INFO] WASH DISHES ROOM IS TIME LEFT                    ->> %d\n", timeLeft[4]);
				printf("[INFO]WASH DISHES ROOM OVERFLOW NUMBER                  ->> %d\n", overFLow[4]);
				if ((isOverflow[4]==0) && (lineAvailable[4]==maxQueue[4])){
				   strcpy(infowashdata,"WASH DISHES ROOM IS WAITING NEW CUSTOMER");
				}else{
				 strcpy(infowashdata,"WASH DISHES ROOM IS SERVING CUSTOMER");
				}
				printf("[INFO] WASH DISHES ROOM IS                              ->> %s\n", infowashdata);
				printf("_____________________________________________________________\n");
				printf("[INFO] NUMBER PEOPLE ENTERED                          	->> %d\n", peopleEntered[4]);
				if (terminted)printf("[INFO] SIMULATION FINISHED :) \n");
				
				
				reset();
				}else{
				
				red();
				printf("_____________________________________________________________\n");
				printf("NODES : WASH DISHES ROOM\n");
				printf("[INFO] WASH DISHES ROOM AVAILABLE                     	->> %d\n", lineAvailable[4]);
				printf("[INFO] WASH DISHES DISHESNG ROOM QUEUE NUMBER          	->> %d\n", Queue[4]);
				printf("[INFO] WASH DISHES ROOM IS SERVING CUSTOMER_ID          ->> %d\n", peopleID[4]);
				printf("[INFO] WASH DISHES ROOM IS TIME LEFT                    ->> %d\n", timeLeft[4]);
				printf("[INFO] WASH DISHES ROOM OVERFLOW NUMBER                 ->> %d\n", overFLow[4]);
				strcpy(infowashdata,"WASH DISHES ROOM IS FULL !!!");
				printf("[INFO] WASH DISHES ROOM IS                              ->> %s\n", infowashdata);
				printf("_____________________________________________________________\n");
				printf("[INFO] NUMBER PEOPLE ENTERED                          	->> %d\n", peopleEntered[4]);
				if (terminted)printf("[INFO] SIMULATION FINISHED :) \n");
				
				reset();

				}
			
			}
			
			
			
			
			clear();
			timerCounter=0;
	        	
	        }
	        
	       usleep(1);
	        

	
	}
	
	
}



