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
#define monitor_powerup 17005


struct mesg_buffer {
	long mesg_type;
	int mesg_data[100];
} message;

struct msqid_ds buf;

int main(){

       	int delay = 0;
        int gateChasier = 1;
        int timerCounter = 0;
        
	
	int nothing;
	int peopleIn;
	int minPeople;
	int maxPeople;
	
	int minChashier;
	int maxChashier;
	int MaxLineRangeChasier;
	
	int minFoodPick;
	int maxFoodPick;
	int MaxLineRangeFoodPick;
	
	int minEating;
	int maxEating;
	int MaxLineRangeEating;
	
	int minPlateWash;
	int maxPlateWash;
	int MaxLineRangePlateWash;
	
	while (1)
	{
		clear();
		printf("IPU CAFETARIA SIMULATION INPUT ******************\n");
		printf("INPUT PARAMETER :\n");
		printf("HOW MANY PEOPLE WILL ENTER THE CAFETARIA ? ->>\n");
		scanf("%d", &peopleIn);
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MINIMUM WAITING TIME FOR QUEUING PEOPLE ENTERENCE (second)? ->>\n");
		scanf("%d", &minPeople);
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MAXIMUM WAITING TIME FOR QUEUING PEOPLE ENTERENCE (second)? ->>\n");
		scanf("%d", &maxPeople);
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MINIMUM WAITING TIME FOR QUEUING CHASIER ENTERENCE (second)? ->>\n");
		scanf("%d", &minChashier);
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MAXIMUM WAITING TIME FOR QUEUING CHASIER ENTERENCE (second)? ->>\n");
		scanf("%d", &maxChashier);
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MAXIMUM WAITING PEOPLE FOR QUEUING CHASIER ENTERENCE ? ->>\n");
		scanf("%d", &MaxLineRangeChasier);
		
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MINIMUM WAITING TIME FOR QUEUING FOOD PICKING (second)? ->>\n");
		scanf("%d", &minFoodPick);
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MAXIMUM WAITING TIME FOR QUEUING FOOD PICKING (second)? ->>\n");
		scanf("%d", &maxFoodPick);
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MAXIMUM WAITING PEOPLE FOR QUEUING FOOD PICKING ? ->>\n");
		scanf("%d", &MaxLineRangeFoodPick);
		
		
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MINIMUM WAITING TIME FOR PEOPLE EATING (second)? ->>\n");
		scanf("%d", &minEating);
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MAXIMUM WAITING TIME FOR PEOPLE EATING (second)? ->>\n");
		scanf("%d", &maxEating);
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH TABLE AVAILABLE FOR PEOPLE EATING ? ->>\n");
		scanf("%d", &MaxLineRangeEating);
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MINIMUM WAITING TIME FOR QUEUING PLATE WASH (second)? ->>\n");
		scanf("%d", &minPlateWash);
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MAXIMUM WAITING TIME FOR QUEUING PLATE WASH (second)? ->>\n");
		scanf("%d", &maxPlateWash);
		printf("INPUT PARAMETER :\n");
		printf("HOW MUCH MAXIMUM WAITING PEOPLE FOR QUEUING PLATE WASH ? ->>\n");
		scanf("%d", &MaxLineRangePlateWash);
		/**/
		clear();
		break;
	}
	
	
	//==========================================================Display the param
	//char nothing[100];
	while (1)
	{
		
		printf("* IPU CAFETARIA SIMULATION INPUT *\n");
		printf("EVERYTHING IS CORRECT?:\n");
		printf("NUMBER PEOPLE IN	 	 ->> %d\n",peopleIn);
		printf("MIN TIME WAITING PEOPLE IN	 ->> %d s\n",minPeople);
		printf("MAX TIME WAITING PEOPLE IN	 ->> %d s\n",maxPeople);
		printf("MIN TIME WAITING CHASHIER	 ->> %d s\n",minChashier);
		printf("MAX TIME WAITING CHASHIER	 ->> %d s\n",maxChashier);
		printf("MAX QUEUE CHASHIER	         ->> %d\n\n",MaxLineRangeChasier);
		printf("MIN TIME WAITING FOOD PICK	 ->> %d s\n",minFoodPick);
		printf("MAX TIME WAITING FOOD PICK	 ->> %d s\n",maxFoodPick);
		printf("MAX QUEUE FOOD PICK	         ->> %d\n\n",MaxLineRangeFoodPick);
		printf("MIN TIME WAITING EATING		 ->> %d s\n",minEating);
		printf("MAX TIME WAITING EATING	 	 ->> %d s\n",maxEating);
		printf("TABLE AVAILABLE	         	 ->> %d\n\n",MaxLineRangeEating);
		printf("MIN TIME WAITING PLATE WASH	 ->> %d s\n",minPlateWash);
		printf("MAX TIME WAITING PLATE WASH	 ->> %d s\n",maxPlateWash);
		printf("MAX QUEUE FOOD PLATE WASH        ->> %d\n\n",MaxLineRangePlateWash);
		printf("***********************************\n");
		sleep(3);
		break;
		
	}
	while(1){
	
		printf("FILL ANY NUMBER AND ENTER TO STRAT THE SIMULATION ... ->>\n");
		scanf("%d", &nothing);
		//sleep(1);
		break;
	
	}
      //make sure All SHM memory will used is free
      key_t key;
      int msgid;
       while(1){
	yellow();
	key = keyEnterence_Toout;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	key = keyEnterence_Toin;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	printf("[INFO] ENterence Nodes Shm Cleared\n");
	key = keyChasire1_Toout;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	
	key = keyChasire1_Toin;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	printf("[INFO] chasier 1 Nodes Shm Cleared\n");
	key = keyChasire2_Toout;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	
	key = keyChasire2_Toin;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	printf("[INFO] chasier 2 Nodes Shm Cleared\n");
	key = keyFoodPick_Toout;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	key = keyFoodPick_Toin;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	printf("[INFO] Food Pick Nodes Shm Cleared\n");
	key = keyEating_Toout;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	key = keyEating_Toin;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	printf("[INFO] Eating Nodes Shm Cleared\n");
	key = keyWashDishes_Toout;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	key = keyWashDishes_Toin;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	printf("[INFO] Plate Wash Nodes Shm Cleared\n");
	key = start_addres;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	key = param_send;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	key = param_send_chasier1;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	key = param_send_chasier2;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	
	key = param_send_foodpick;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	
	key = param_send_eating;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	
	key = param_send_wash;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	
	key = chasir_1_powerup;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	
	key = chasir_2_powerup;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	
	key = foodpick_powerup;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	
	key = eating_powerup;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	
	key = washing_powerup;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	
	key = monitor_powerup;
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgctl(msgid, IPC_RMID, NULL);
	
	printf("[INFO] System Sync Shm Cleared\n");
	green();
	printf("[INFO] POWERING UP, CLEANING SHM..\n");
	sleep(3);
	reset();
	break;
	}
	
	key = monitor_powerup;
	msgid = msgget(key, 0666 | IPC_CREAT);
	while(1){
		message.mesg_type = 1;
		//clear();
		yellow();
		printf("NODES POWERING UP...\n");
		red();
		printf("PLEASE RUN ./monitor | PLEASE RUN MONITOR NODE ON OTHER TERMINAL\n");
		msgrcv(msgid, &message, sizeof(message), 0, 0);
		green();
		printf("MONITOR NODE POWERED UP !\n");
		reset();
		sleep(1);
		break;
	}
	
	
	key = chasir_1_powerup;
	msgid = msgget(key, 0666 | IPC_CREAT);
	while(1){
		message.mesg_type = 1;
		//clear();
		yellow();
		printf("NODES POWERING UP...\n");
		red();
		printf("PLEASE RUN ./chasier1 | PLEASE RUN CHASIER 1 NODE ON OTHER TERMINAL\n");
		msgrcv(msgid, &message, sizeof(message), 0, 0);
		green();
		printf("CHAISER 1 NODE POWERED UP !\n");
		reset();
		sleep(1);
		break;
	}
	
	key = chasir_2_powerup;
	msgid = msgget(key, 0666 | IPC_CREAT);
	while(1){
		message.mesg_type = 1;
		//clear();
		yellow();
		printf("NODES POWERING UP...\n");
		red();
		printf("PLEASE RUN ./chasier2 | PLEASE RUN CHASIER 2 NODE ON OTHER TERMINAL\n");
		msgrcv(msgid, &message, sizeof(message), 0, 0);
		green();
		printf("CHAISER 2 NODE POWERED UP !\n");
		reset();
		sleep(1);
		break;
	}
	
	
	key = foodpick_powerup;
	msgid = msgget(key, 0666 | IPC_CREAT);
	while(1){
		message.mesg_type = 1;
		//clear();
		yellow();
		printf("NODES POWERING UP...\n");
		red();
		printf("PLEASE RUN ./foodpick | PLEASE RUN FOOD PICK ROOM NODE ON OTHER TERMINAL\n");
		msgrcv(msgid, &message, sizeof(message), 0, 0);
		green();
		printf("FOOD PICK NODE POWERED UP !\n");
		reset();
		sleep(2);
		break;
	}
	
	
	
	key = eating_powerup;
	msgid = msgget(key, 0666 | IPC_CREAT);
	while(1){
		message.mesg_type = 1;
		//clear();
		yellow();
		printf("NODES POWERING UP...\n");
		red();
		printf("PLEASE RUN ./eatingRoom | PLEASE RUN EATING ROOM NODE ON OTHER TERMINAL\n");
		msgrcv(msgid, &message, sizeof(message), 0, 0);
		green();
		printf("EATING ROOM NODE POWERED UP !\n");
		reset();
		sleep(2);
		break;
	}
	
	
	key = washing_powerup;
	msgid = msgget(key, 0666 | IPC_CREAT);
	while(1){
		message.mesg_type = 1;
		//clear();
		yellow();
		printf("NODES POWERING UP...\n");
		red();
		printf("PLEASE RUN ./washDishes | PLEASE RUN WASH DISHES NODE ON OTHER TERMINAL\n");
		msgrcv(msgid, &message, sizeof(message), 0, 0);
		green();
		printf("CHAISER 1 NODE POWERED UP !\n");
		reset();
		sleep(2);
		break;
	}
	
	/**/
	key_t keyChasier1;
	key_t keyChasier2;
	
	key_t keyChasier1_getdata;
	key_t keyChasier2_getdata;
	
	key_t strat_key;
	key_t param_key;
	
	key_t param_key_chasier1;
	key_t param_key_chasier2;
	key_t param_foodpick;
	key_t param_eating;
	key_t param_wash;
	
	key_t toMonitor;
	
	
	

	int msgid_params_chasier1;
	param_key_chasier1 = param_send_chasier1;
	msgid_params_chasier1 = msgget(param_key_chasier1, 0666 | IPC_CREAT);
	while(1){
		clear();
		message.mesg_type = 1;
		printf("SENDING PARAMETER TO CHASIER 1 NODE...\n");
		printf("[INFO] CHASIER PARAM | MIN TIME WAIT                  ->> %d s\n", minChashier);
		printf("[INFO] CHASIER PARAM | MAX TIME WAIT                  ->> %d s\n", maxChashier);
		printf("[INFO] CHASIER PARAM | MAX QUEUE                      ->> %d\n", MaxLineRangeChasier);
		message.mesg_data[0]=minChashier;
		message.mesg_data[1]=maxChashier;
		message.mesg_data[2]=MaxLineRangeChasier;
		message.mesg_data[3]=peopleIn;
		msgsnd(msgid_params_chasier1, &message, sizeof(message), 0);
		//sleep(2);
		green();
		printf("SEND SUCCESFULLY TO CHASIER 1 !\n");
		reset();
		break;
	}
	
	int msgid_params_chasier2;
	param_key_chasier2 = param_send_chasier2;
	msgid_params_chasier2 = msgget(param_key_chasier2, 0666 | IPC_CREAT);
	while(1){
		//clear();
		message.mesg_type = 1;
		printf("SENDING PARAMETER TO CHASIER 2 NODE...\n");
		printf("[INFO] CHASIER PARAM | MIN TIME WAIT                  ->> %d s\n", minChashier);
		printf("[INFO] CHASIER PARAM | MAX TIME WAIT                  ->> %d s\n", maxChashier);
		printf("[INFO] CHASIER PARAM | MAX QUEUE                      ->> %d\n", MaxLineRangeChasier);
		message.mesg_data[0]=minChashier;
		message.mesg_data[1]=maxChashier;
		message.mesg_data[2]=MaxLineRangeChasier;
		message.mesg_data[3]=peopleIn;
		msgsnd(msgid_params_chasier2, &message, sizeof(message), 0);
		//sleep(2);
		green();
		printf("SEND SUCCESFULLY TO CHASIER 2!\n");
		reset();
		break;
	}
	 
	int msgid_params_foodpick;
	param_foodpick = param_send_foodpick;
	msgid_params_foodpick = msgget(param_foodpick, 0666 | IPC_CREAT);
	while(1){
		//clear();
		message.mesg_type = 1;
		printf("SENDING PARAMETER TO FOOD PICKING NODE...\n");
		printf("[INFO] FOOD PICK PARAM | MIN TIME WAIT                  ->> %d s\n", minFoodPick);
		printf("[INFO] FOOD PICK PARAM | MAX TIME WAIT                  ->> %d s\n", maxFoodPick);
		printf("[INFO] FOOD PICK PARAM | MAX QUEUE                      ->> %d\n", MaxLineRangeFoodPick);
		message.mesg_data[0]=minFoodPick;
		message.mesg_data[1]=maxFoodPick;
		message.mesg_data[2]=MaxLineRangeFoodPick;
		message.mesg_data[3]=peopleIn;
		msgsnd(msgid_params_foodpick, &message, sizeof(message), 0);
		//sleep(2);
		green();
		printf("SEND SUCCESFULLY TO FOOD PICKNODE!\n");
		reset();
		break;
	}
	
	
	
	int msgid_params_eating;
	param_eating = param_send_eating;
	msgid_params_eating = msgget(param_eating, 0666 | IPC_CREAT);
	while(1){
		//clear();
		message.mesg_type = 1;
		printf("SENDING PARAMETER TO EATING ROOM NODE...\n");
		printf("[INFO] EATING ROOM PARAM | MIN TIME WAIT                  ->> %d s\n", minEating);
		printf("[INFO] EATING ROOM PARAM | MAX TIME WAIT                  ->> %d s\n", maxEating);
		printf("[INFO] EATING ROOM PARAM | MAX QUEUE                      ->> %d\n", MaxLineRangeEating);
		message.mesg_data[0]=minEating;
		message.mesg_data[1]=maxEating;
		message.mesg_data[2]=MaxLineRangeEating;
		message.mesg_data[3]=peopleIn;
		msgsnd(msgid_params_eating, &message, sizeof(message), 0);
		//sleep(2);
		green();
		printf("SEND SUCCESFULLY TO EATING ROOM !\n");
		reset();
		break;
	}
	
	int msgid_params_wash;
	param_wash = param_send_wash;
	msgid_params_wash = msgget(param_wash, 0666 | IPC_CREAT);
	while(1){
		//clear();
		message.mesg_type = 1;
		printf("SENDING PARAMETER TO WASHING ROOM NODE...\n");
		printf("[INFO] WASHING ROOM PARAM | MIN TIME WAIT                  ->> %d s\n", minPlateWash);
		printf("[INFO] WASHING ROOM PARAM | MAX TIME WAIT                  ->> %d s\n", maxPlateWash);
		printf("[INFO] WASHING ROOMPARAM | MAX QUEUE                      ->> %d\n", MaxLineRangePlateWash);
		message.mesg_data[0]=minPlateWash;
		message.mesg_data[1]=maxPlateWash;
		message.mesg_data[2]=MaxLineRangePlateWash;
		message.mesg_data[3]=peopleIn;
		msgsnd(msgid_params_wash, &message, sizeof(message), 0);
		sleep(3);
		green();
		printf("SEND SUCCESFULLY WASH ROOM!\n");
		reset();
		break;
	}
	
	
	
	//key = clockSync;
	//msgid = msgget(key, 0666 | IPC_CREAT);
	int msgid_chasier1,msgid_chasier2;
	int msgid_getDataChasier1,msgid_getDataChasier2;
	int msgid_monitor;
	char infoEnterence[100];
	int getDataQueueChasier1;
	int getDataQueueChasier2;
	//create SHM
	int overFLow = 0;
	keyChasier1 = keyChasire1_Toout;
	msgid_chasier1 = msgget(keyChasier1, 0666 | IPC_CREAT);
	keyChasier2 = keyChasire2_Toout;
	msgid_chasier2 = msgget(keyChasier2, 0666 | IPC_CREAT);
	//toMonitor = keyChasire1_Toin;
	//msgid_monitor = msgget(toMonitor, 0666 | IPC_CREAT);
	
        int custID1[peopleIn];
        int custID2[peopleIn];
        int tochs1;
        int tochs2;
	srand(time(0));
	
	while(1){
		clear();
		message.mesg_type = 1;
		//keeping update the chasier situation
		
		timerCounter++;
		
		printf("**************ENTERENCE NODE***********\n");
		printf("[INFO] Interval Entering      ->> %d\n", delay);
		printf("[INFO] TImer COunter          ->> %d\n", timerCounter);
		printf("[INFO] Number People entering ->> %d\n", peopleIn);
		printf("---------------------------------------\n");
		printf("[INFO] People Will Enter to Chasier->> %d\n", gateChasier);
		
		printf("*************************************\n");
		if (timerCounter>=delay){ //create delay using counting every 1s.
			
				delay = (rand() %(maxPeople - minPeople + 1)) + minPeople;
				
					gateChasier = (rand() %(2 - 1 + 1)) + 1;
					if (gateChasier==1){
					        custID1[tochs1]=peopleIn;
					        tochs1++;
						message.mesg_data[0]=peopleIn;
						msgsnd(msgid_chasier1, &message, sizeof(message), 0);
						//msgsnd(msgid_monitor, &message, sizeof(message), 0);
					//people send to chasier 2
					}
					
					if (gateChasier==2){
					 custID2[tochs2]=peopleIn;
					 tochs2++;
					message.mesg_data[0]=peopleIn;
					msgsnd(msgid_chasier2, &message, sizeof(message), 0);
					//msgsnd(msgid_monitor, &message, sizeof(message), 0);
					//people send to chasier 1
					
					}

			peopleIn--;
			timerCounter=0;	
			if (peopleIn<=0)break;
			}
			    
		
		sleep(1);
		
	}
	
	while(1){
	clear();
	printf("**************ENTERENCE NODE ENDED***********\n");
	printf("[INFO] THe number people go to chasier 1      ->> %d\n", tochs1);
	printf("[INFO] THe people ID go to chasier 1      ->> \n");
	for (int k=0; k<tochs1; k++){
	 printf("%d ,",custID1[k]);
	}
	printf("\n");
	printf("[INFO] THe number people go to chasier 2      ->> %d\n", tochs2);
	printf("[INFO] THe people ID go to chasier 2      ->> \n");
	for (int k=0; k<tochs2; k++){
	 printf("%d ,",custID2[k]);
	}
	printf("\n");
	printf ("Ctrl + C to terminated");
	printf("*************************************\n");
	break;
	
	}
	
	return 0;
	
}
