//sleman hilal mohammed ghithan
//1202009
//sec 1
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
struct Passengers{//build the passengers struct
    int travellerID;
    int travellingDate;
    char travellingTime[30];
    char from[50];
    char into[50];
    struct Passengers *Next;
};
struct Busses{//build the busses struct
    int busNumber;
    int busDate;
    char busTime [30];
    char busFrom [50];
    char busInto [50];
    int  ticketPrice;
    int capacity;
    struct Busses* nextBus;
    struct Passengers* passenger;

};
struct Passengers* BulidPassengerLinkedList(struct Passengers*);//used to build the passengers list
struct Passengers* insertCall(struct Passengers* );
struct Busses* BulidBusesLinkedList(struct Busses* );//used to build the busses list
struct Passengers* InsertPassenger(struct Passengers*,int,int,char[30],char[50],char [50],struct Passengers*);//to add a passenger to the list
void PrintPassengersList(struct Passengers*);//print the data in the passengers list
int PassengerLinkedListLength(struct Passengers*);//return the number of passengers in the list
struct Passengers* DeletePassenger( struct Passengers*,int );//used to delete an passenger from list by his index
struct Passengers* ReadPassengersFile(struct Passengers*);//read the data from passengers file and add it into the list
struct Busses* InsertBus(struct Busses* ,int ,int ,char  [30],char  [50],char  [50]
        ,int ,int ,struct Busses* ,struct Passengers* );//to add a bus to the list
void PrintBussesList(struct Busses*);//print the data in the busses list(not used)
int BussesLinkedListLength(struct Busses* );//return the number of busses in the list
struct Busses* DeleteBus( struct Busses*,int );//used to delete an passenger from list by it's index
struct Busses* ReadBusesFile(struct Busses* );//read the data from busses file and add it into the list
struct Busses* Assigning(struct Busses*,struct Passengers*);//add the passenger to right bus
int IsEmpty(struct Passengers* P);//check if passenger list Empty(unused in project)
void PrintSpecifecBusInfo(struct Busses*);//print a specific bus info by its number
struct Busses* DeleteBusByItsNumber(struct Busses*,struct Passengers*,int);//used to delete a bus by its number
void PrintAllBussesData(struct Busses*);//used to print all busses info
struct Busses* DeleteBusCalling(struct Busses*,struct Passengers*);//call the method of deleting bus by its number
struct Busses* AddNewPassenger(struct Busses*);//add a new passenger into a bus
struct Busses* DeletePassengerFromBus(struct Busses*);//delete a passenger from a bus
int main() {
    //build three lists one for busses ,one for passengers and one for unmatched passengers
    struct Passengers* passgengersLinkedList;
    passgengersLinkedList=BulidPassengerLinkedList(passgengersLinkedList);
    struct Busses* bussesLinkedList;
    bussesLinkedList=BulidBusesLinkedList(bussesLinkedList);
    struct Passengers* unMatchedPassengers=passgengersLinkedList;
    int choice=0;
    printf("enter the number of the process you want,(you should read the passengers and busses files data\n");
    printf("1. Load the bus and passengers information file\n"
           "2. Assign passengers and print assignment information of all busses\n"
           "3. Print a specific bus information along with its passengers information\n"
           "4. Print unmatched passengers\n"
           "5. Add new passenger\n"
           "6. Delete passenger\n"
           "7. Delete bus number\n"
           "8 add passenger to the main list\n"
           "9. Exit\n");
    //it's very urgent to read the files data to avoid the errors
    scanf("%d", &choice);
    if(choice==9){
        return 0;
    }
    if (choice == 1) {
        bussesLinkedList = ReadBusesFile(bussesLinkedList);
        passgengersLinkedList = ReadPassengersFile(passgengersLinkedList);
        printf("the data files readied successfully\n\n");
    }
    while (choice != 1) {
        printf("you need to enter 1 to read the data files\n"
               "enter 8 to exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            bussesLinkedList = ReadBusesFile(bussesLinkedList);
            passgengersLinkedList = ReadPassengersFile(passgengersLinkedList);
            printf("the data files readied successfully\n");
        }
        if (choice == 8) {
            return 0;
        }

    }
    printf("________________________________________________________________________________\n");
    while (choice!=9) {
        printf("2. Assign passengers and print assignment information of all busses\n"
               "3. Print a specific bus information along with its passengers information\n"
               "4. Print unmatched passengers\n"
               "5. Add new passenger to a bus\n"
               "6. Delete passenger from a bus\n"
               "7. Delete bus number\n"
               "8 add passenger to the main list\n"
               "9. Exit\n");
        scanf("%d",&choice);
        if(choice==9){
            return 0;
        }
        //calling methods depends on the number
        switch (choice) {
            case 2:bussesLinkedList= Assigning(bussesLinkedList,passgengersLinkedList);break;
            case 3:PrintSpecifecBusInfo( bussesLinkedList);break;
            case 4:PrintPassengersList(unMatchedPassengers);break;
            case 5:bussesLinkedList=AddNewPassenger( bussesLinkedList);break;
            case 6:bussesLinkedList= DeletePassengerFromBus(bussesLinkedList);break;
            case 7:bussesLinkedList= DeleteBusCalling(bussesLinkedList,unMatchedPassengers);break;
            case 8:passgengersLinkedList= insertCall(passgengersLinkedList);break;
            case 9:return 0;
        }
    }
    return 0;
}
struct Passengers* BulidPassengerLinkedList(struct Passengers* passgengersLinkedList){//used to build the passengers list

    passgengersLinkedList=(struct Passengers*) malloc(sizeof (struct Passengers));//get a size in the memory
    if(passgengersLinkedList==NULL){//if creation failed return null
        printf("out of memory\n");
        return NULL;
    }
    passgengersLinkedList->Next=NULL;//let head point in null
    return passgengersLinkedList;

}
struct Busses* BulidBusesLinkedList(struct Busses* BussesLinkedList){//used to build the busses list
    BussesLinkedList=(struct Busses*) malloc(sizeof (struct Busses));//get a size in the memory
    if(BussesLinkedList==NULL){//if creation failed return null
        printf("out of memory \n");
        return NULL;
    }
    BussesLinkedList->nextBus=NULL;//let head point in null
    return BussesLinkedList;
}
struct Passengers* insertCall(struct Passengers* passgengersLinkedList){
    int travellerIDN;
    int travellingDateN;
    char travellingTimeN [30];
    char fromN [50];
    char intoN [50];
    struct Passengers* NextN=NULL;
    printf("------------------------------------------------------------------------------------------------------------------------");
    fflush(stdin);
    printf("enter student id\n");
    scanf("%d",&travellerIDN);
    fflush(stdin);
    printf("enter travellingDateN\n");
    scanf("%d",&travellingDateN);
    fflush(stdin);
    printf("enter the travellingTimeN\n");
    scanf("%s",travellingTimeN);
    fflush(stdin);
    printf("enter the fromN\n");
    scanf("%[a-z,A-Z,0-9,' ']c",fromN);
    fflush(stdin);
    printf("enter the intoN\n");
    scanf("%[a-z,A-Z,0-9,' ']c",intoN);
    passgengersLinkedList= InsertPassenger(passgengersLinkedList,travellerIDN,travellingDateN,travellingTimeN,fromN,intoN,NULL);
    return passgengersLinkedList;
}
struct Passengers* InsertPassenger(struct Passengers* passgengersLinkedList,int travellerIDN,
                                   int travellingDateN,char travellingTimeN [30],char fromN [50],char intoN [50],struct Passengers* nextN) {//to add a passenger to the list

    if(passgengersLinkedList==NULL){//if the list is not created yet return null
        return NULL;
    }
    //build a node and get size in memory for it
    struct Passengers* newPassenger;
    newPassenger=(struct Passengers*) malloc(sizeof (struct Passengers));

    if(newPassenger==NULL){//if creation failed return the list
        printf("out of memory\n");
        return passgengersLinkedList;
    }
    //insert the data of passenger into the node
    newPassenger->travellerID=travellerIDN;
    newPassenger->travellingDate=travellingDateN;
    strcpy(newPassenger->travellingTime,travellingTimeN);
    strcpy(newPassenger->from,fromN);
    strcpy(newPassenger->into,intoN);
    newPassenger->Next=nextN;

    if(passgengersLinkedList->Next==NULL){//if the list is null jest let head point in the new passenger node
        passgengersLinkedList->Next=newPassenger;
        return passgengersLinkedList;
    }
    struct Passengers* tempPassengers;
    tempPassengers=passgengersLinkedList;
    while (tempPassengers->Next!=NULL){//go to the last node
        tempPassengers=tempPassengers->Next;
    }
    tempPassengers->Next=newPassenger;//let the last node point in the new node
    return passgengersLinkedList;
}
int PassengerLinkedListLength(struct Passengers* passgengersLinkedList){//return the number of passengers in the list
    if(passgengersLinkedList==NULL){//if the list is not created yet return -1
        printf("linked list is not created");
        return -1;
    }
    if(passgengersLinkedList->Next==NULL){//if list empty return 0
        return 0;
    }
    if(passgengersLinkedList->Next->Next==NULL){//if it has just one node expect the head return 1
        return 1;
    }
    struct Passengers* tempPassengers=passgengersLinkedList;
    int counter=0;
    while(tempPassengers->Next!=NULL){//while the list has nodes increment the counter
        tempPassengers=tempPassengers->Next;
        counter++;
    }
    return counter;
}
void PrintPassengersList(struct Passengers* passgengersLinkedList){//print the data in the passengers list
    if(passgengersLinkedList==NULL){//if list not created yet return
        printf("list is not create yet \n");
        return;
    }
    if(passgengersLinkedList->Next==NULL){//if list has no nodes yet return
        printf("there is no Passengers added yet\n");
        return;
    }
    int x=1;
    struct Passengers* tempPassengers=passgengersLinkedList;
    tempPassengers=tempPassengers->Next;
    while(tempPassengers->Next!=NULL||tempPassengers->Next==NULL){//while list has nodes print the data of each node
        printf("info of Passenger number %d is:\n\n",x);
        printf("teaveller id: %d\n",tempPassengers->travellerID);
        printf("travelling date is: %d\n",tempPassengers->travellingDate);
        printf("travelling time is: %s\n",tempPassengers->travellingTime);
        printf("travel from: %s\n",tempPassengers->from);
        printf("travel to: %s\n\n",tempPassengers->into);
        x++;
        printf("________________________________________________________________________________\n");
        if(tempPassengers->Next==NULL){
            return;
        }

        tempPassengers=tempPassengers->Next;
    }
}
struct Passengers* DeletePassenger( struct Passengers* passgengersLinkedList,int position){//used to delete an passenger from list by his index

    if(passgengersLinkedList==NULL){//if list is not created yet return null
        printf("the list is not created yet\n");
        return NULL;
    }

    if(passgengersLinkedList->Next==NULL){//if the list is empty return the null list
        printf("the list is empty\n");
        return passgengersLinkedList;
    }
    if(position==0){//the position must be more than zero
        printf("list start from 1 there is no passenger it's number equal 0\n");
        return passgengersLinkedList;
    }
    if(position==1){//if first node just let the heat point on second node and delete the first one
        struct Passengers* tempPassengers=passgengersLinkedList;
        tempPassengers=tempPassengers->Next;
        passgengersLinkedList->Next=tempPassengers->Next;
        free(tempPassengers);
        return passgengersLinkedList;
    }

    if(position>=2&&position<=PassengerLinkedListLength(passgengersLinkedList)){//if the node number is between 2 and number of nodes in list
        struct Passengers *tempPassengers=passgengersLinkedList,*current;
        int counter=0;
        while(counter<position-1){//go to the previous of node you need to delete
            tempPassengers=tempPassengers->Next;
            counter++;
        }

        current=tempPassengers->Next;//set current point on the node
        tempPassengers->Next=current->Next;//set the list point on the next node of current
        free(current);//free the deleted node
        return passgengersLinkedList;

    }
    if(position> PassengerLinkedListLength(passgengersLinkedList)){//if the position is more than the number of nodes
        printf("the Passenger is not found\n");
        return passgengersLinkedList;//return the list
    }
    return passgengersLinkedList;
}
struct Passengers* ReadPassengersFile(struct Passengers* passengersLinkedList){//read the data from passengers file and add it into the list
    FILE *fileReader;//make file pointer
    fileReader= fopen("passengers.txt","r");//open the file in reading mode
    if(fileReader==NULL){//if the file empty return null
        printf("error while reading file\n");
        return NULL;
    }
    else{
        char line [150];//string to set line from file on it
        while( fgets(line,sizeof (line),fileReader)!=NULL) {//while the file not empty, read a line
            int travellerIDN;
            int travellingDateN;
            char travellingTimeN [30];
            char fromN [50];
            char intoN [50];
            struct Passengers* NextN=NULL;

            {//this code to add '#' at the last of the line
                //because its takes taps and spaces after last string
                //help in trim
                int x = 0;
                while (line[x] != '\0') {
                    x++;
                }

                line[x - 1] = '#';

                line[x] = '\0';
            }
            char *token= strtok(line,"#");//trim the line depends on hash sign
            int tokenCount=1;
            while(token!=NULL){

                //atoi to convert from string into integer
                if(tokenCount==1){
                    travellerIDN= atoi(token);
                }
                if(tokenCount==2){
                    travellingDateN= atoi(token);
                }
                if(tokenCount==3){
                    strcpy(travellingTimeN,token);
                }
                if(tokenCount==4){
                    strcpy(fromN,token);
                }
                if(tokenCount==5){
                    strcpy(intoN,token);
                }

                tokenCount++;
                token = strtok(NULL, "#");
            }
            //insert passenger for each line
            passengersLinkedList= InsertPassenger(passengersLinkedList,travellerIDN,travellingDateN,travellingTimeN,fromN,intoN,NextN);

        }
    }
    return passengersLinkedList;
}
struct Busses* InsertBus(struct Busses* bussesLinkedList,int busNumberN,int busDateN,char busTimeN [30],char busFromN [50],char busIntoN [50]
        ,int tecketPriceN,int capacityN,struct Busses* nextBusN,struct Passengers* nextPassengereN){//to add a bus to the list
    if(bussesLinkedList==NULL){//if list not created return null
        return NULL;
    }
    struct Busses *newBus;//node for new bus
    newBus=(struct Busses*) malloc(sizeof (struct Busses));//get size in memory for the node
    if(newBus==NULL){//if node creation failed reurn the list
        printf("out of memory\n");
        return bussesLinkedList;
    }
    //set the data on the node
    newBus->busNumber=busNumberN;
    newBus->busDate=busDateN;
    strcpy(newBus->busTime,busTimeN);
    strcpy(newBus->busFrom,busFromN);
    strcpy(newBus->busInto,busIntoN);
    newBus->ticketPrice=tecketPriceN;
    newBus->capacity=capacityN;
    newBus->nextBus=nextBusN;
    newBus->passenger=nextPassengereN;
    if(bussesLinkedList->nextBus==NULL){//if the list empty just set head point on the new node
        bussesLinkedList->nextBus=newBus;
        return bussesLinkedList;
    }
    struct Busses* tempBusses;
    tempBusses=bussesLinkedList;
    while(tempBusses->nextBus!=NULL){//go to last node
        tempBusses=tempBusses->nextBus;
    }
    tempBusses->nextBus=newBus;//set last node point on the new node
    return bussesLinkedList;

}
void PrintBussesList(struct Busses* bussesLinkedList){//print the data in the busses list(not used)

    if(bussesLinkedList==NULL){//if the list not created yet print it's not crated
        printf("list is not create yet \n");
        return;
    }
    if(bussesLinkedList->nextBus==NULL){//if the list null print that it's null
        printf("there is no busses added yet\n");
        return;
    }

    int x=1;
    struct Busses* tempBusses=bussesLinkedList;
    tempBusses=tempBusses->nextBus;
    while(tempBusses->nextBus!=NULL||tempBusses->nextBus==NULL){//for each node print data
        printf("info of Bus number %d is:\n\n",x);
        printf("bus number: %d\n",tempBusses->busNumber);
        printf("travelling date is: %d\n",tempBusses->busDate);
        printf("travelling time is: %s\n",tempBusses->busTime);
        printf("travel from: %s\n",tempBusses->busFrom);
        printf("travel to: %s\n",tempBusses->busInto);
        printf("ticket price: %d\n",tempBusses->ticketPrice);
        printf("capacity is: %d\n\n",tempBusses->capacity);
        x++;
        if(tempBusses->nextBus==NULL){
            return;
        }
        tempBusses=tempBusses->nextBus;
    }
}
int BussesLinkedListLength(struct Busses* bussesLinkedList){//return the number of busses in the list
    if(bussesLinkedList==NULL){//if the lsit is not created yet return -1
        printf("linked list is not created");
        return -1;
    }
    if(bussesLinkedList->nextBus==NULL){//if the list null retutn 0
        return 0;
    }
    if(bussesLinkedList->nextBus->nextBus==NULL){//if it has just one node return 1
        return 1;
    }
    struct Busses* tempBusses=bussesLinkedList;
    int counter=0;
    while(tempBusses->nextBus!=NULL){//for each node increase the counter by 1
        tempBusses=tempBusses->nextBus;
        counter++;
    }
    return counter;
}
struct Busses* ReadBusesFile(struct Busses* BussesLinkedList){//read the data from busses file and add it into the list
    FILE *fileReader;//make pointer of file
    fileReader= fopen("busses.txt","r");//open the dile on read mode
    if(fileReader==NULL){//if the file is empty return null
        printf("error while reading file\n");
        return NULL;
    } else{
        char line [150];//string for line from file
        while( fgets(line,sizeof (line),fileReader)!=NULL) {//while the file has more lines set string equal to line from file
            int busNumberN;
            int busDateN;
            char busTimeN [30];
            char busFromN [50];
            char busIntoN [50];
            int  ticketPricN;
            int capacityN;
            struct Busses* nextBusN=NULL;
            struct Passengers* passengerN=NULL;



            char *token= strtok(line,"#");//trim the string depands on hash sign
            int tokenCount=1;
            while(token!=NULL){
                if(tokenCount==1){
                    busNumberN= atoi(token);
                }
                if(tokenCount==2){
                    busDateN= atoi(token);
                }
                if(tokenCount==3){
                    strcpy(busTimeN,token);
                }
                if(tokenCount==4){
                    strcpy(busFromN,token);
                }
                if(tokenCount==5){
                    strcpy(busIntoN,token);
                }
                if(tokenCount==6){
                    ticketPricN= atoi(token);
                }
                if(tokenCount==7){
                    capacityN= atoi(token);
                }
                tokenCount++;
                token = strtok(NULL, "#");
            }
            //add the bus node to the list
            BussesLinkedList= InsertBus(BussesLinkedList,busNumberN,busDateN,busTimeN,busFromN,busIntoN,ticketPricN,capacityN,nextBusN,passengerN);

        }
    }
    return BussesLinkedList;
}
struct Busses* Assigning(struct Busses* bussesLinkedList,struct Passengers* passengersLinkedList){//add the passenger to right bus
    if(bussesLinkedList==NULL||passengersLinkedList==NULL){//if one of the lists is not created yet return the busses list
        return bussesLinkedList;
    }
    if(bussesLinkedList->nextBus==NULL||passengersLinkedList->Next==NULL){//if one of lists is empty return busses list
        return bussesLinkedList;
    }
    struct Busses* tempBus;
    struct Passengers* tempPassenger;
    tempBus=bussesLinkedList->nextBus;

    while (tempBus!=NULL){//for each bus
        tempPassenger=passengersLinkedList->Next;

        int counterPassenger=1;
        while(tempPassenger!=NULL){//for each passenger
            if(tempBus->busDate==tempPassenger->travellingDate&& strcmp(tempBus->busTime,tempPassenger->travellingTime)==0
               &&strcmp(tempBus->busFrom,tempPassenger->from)==0&&strcmp(tempBus->busInto,tempPassenger->into)==0&&
               tempBus->capacity>0){//if the data is right
                if(tempBus->passenger==NULL) {//if the bus passenger pointer is null bulid the list
                    tempBus->passenger = BulidPassengerLinkedList(tempBus->passenger);
                }
                //insert the passenger into bust passengers list
                tempBus->passenger= InsertPassenger(tempBus->passenger,tempPassenger->travellerID,tempPassenger->travellingDate
                        ,tempPassenger->travellingTime,tempPassenger->from,tempPassenger->into,NULL);
                //delete the passenger from the passengers list
                passengersLinkedList= DeletePassenger(passengersLinkedList,counterPassenger);

                tempBus->capacity--;//set the capacity by -1
                counterPassenger--;
            }
            counterPassenger++;
            tempPassenger=tempPassenger->Next;
        }
        tempBus=tempBus->nextBus;
    }
    PrintAllBussesData(bussesLinkedList);//print the busses and it's passengers after Assigning
    return bussesLinkedList;

}
int IsEmpty(struct Passengers* P){//check if passenger list Empty(unused in project)
    return P->Next==NULL;
}
void PrintSpecifecBusInfo(struct Busses* bussesLinkedList){//print a specific bus info by its number
    if(bussesLinkedList==NULL){//if the list of busses is not create yet return
        return;
    }
    if(bussesLinkedList->nextBus==NULL){//if the busses list empty return
        printf("the busses list is empty\n");
        return;
    }
    int busNumberN;
    printf("enter the bus number\n");
    scanf("%d",&busNumberN);
    struct Busses* tempBusses=bussesLinkedList,*tempBussesN=bussesLinkedList;
    tempBussesN=tempBussesN->nextBus;
    tempBusses=tempBusses->nextBus;
    bool found=false;
    //this code to check if bus found in the list
    while (tempBussesN->nextBus!=NULL||tempBussesN->nextBus==NULL){
        if(tempBussesN->busNumber==busNumberN){
            found=true;
            break;
        }

        if(tempBussesN->nextBus==NULL){
            break;
        }
        tempBussesN=tempBussesN->nextBus;
    }
    if(found==false){//if not found return
        printf("the bus you entered it's number is not found,please try again\n");
        return ;
    }
    while ((tempBusses->nextBus!=NULL||tempBusses->nextBus==NULL)){//for each bus

        if(busNumberN==tempBusses->busNumber){//when find the bus number print it's info
            printf("bus number: %d\n",tempBusses->busNumber);
            printf("travelling date is: %d\n",tempBusses->busDate);
            printf("travelling time is: %s\n",tempBusses->busTime);
            printf("travel from: %s\n",tempBusses->busFrom);
            printf("travel to: %s\n",tempBusses->busInto);
            printf("ticket price: %d\n",tempBusses->ticketPrice);
            printf("capacity is: %d\n\n",tempBusses->capacity);
            struct Passengers* tempPassengers=tempBusses->passenger;
            if(tempPassengers==NULL||tempPassengers->Next==NULL){
                printf("this bus has no passengers\n");
                printf("________________________________________________________________________________\n\n");
                return;
            }
            tempPassengers=tempPassengers->Next;
            printf("IDs of passenger for this bus is:\n");
            int count=1;
            while (tempPassengers->Next!=NULL||tempPassengers->Next==NULL) {//print the IDs of the passengers in the bus
                printf("%d     ", tempPassengers->travellerID);
                count++;
                if(count==5){
                    count=1;
                    printf("\n");
                }
                if(tempPassengers->Next==NULL){
                    break;
                }
                tempPassengers=tempPassengers->Next;
            }
            printf("\n\n________________________________________________________________________________\n");
        }
        if(tempBusses->nextBus==NULL){
            return;
        }
        tempBusses=tempBusses->nextBus;
    }
}
struct Busses* DeleteBusByItsNumber(struct Busses* bussesLinkedList,struct Passengers* unMatchedPassengers,int busNumberN){//used to delete a bus by its number
    if(bussesLinkedList==NULL){//if the list not created yet return it
        printf("busses list is not crated yet\n");
        return bussesLinkedList;
    }
    if(bussesLinkedList->nextBus==NULL){//if the list is empty return it
        printf("the list is empty\n");
        return bussesLinkedList;
    }
    struct Busses* tempBusses=bussesLinkedList,*tempBussesN=bussesLinkedList;
    tempBussesN=tempBussesN->nextBus;
    bool found=false;
    //this code to check if bus found in the list
    while (tempBussesN->nextBus!=NULL||tempBussesN->nextBus==NULL){
        if(tempBussesN->busNumber==busNumberN){
            found=true;
            break;
        }

        if(tempBussesN->nextBus==NULL){
            break;
        }
        tempBussesN=tempBussesN->nextBus;
    }
    if(found==false){
        printf("the bus you entered it's number is not found,please try again\n\n");
        printf("________________________________________________________________________________\n");
        return bussesLinkedList;
    }
    tempBusses=tempBusses->nextBus;
    int bussesCounter=1;
    while (tempBusses->nextBus!=NULL||tempBusses->nextBus==NULL){//for each bus
        if(tempBusses->busNumber==busNumberN){//when find the bus number
            if(tempBusses->passenger==NULL){//if the bus has no passengers just delete it
                bussesLinkedList=DeleteBus(bussesLinkedList,bussesCounter);
                break;
            }
            if(tempBusses->passenger!=NULL){//if bus has passengers
                struct Passengers* tempPassengers=tempBusses->passenger;
                while (tempPassengers->Next!=NULL){//for each passenger add it to the unmatched list and delete it from the bus passengers list

                    unMatchedPassengers=InsertPassenger(unMatchedPassengers,tempPassengers->Next->travellerID,tempPassengers->Next->travellingDate
                            ,tempPassengers->Next->travellingTime,tempPassengers->Next->from,tempPassengers->Next->into,NULL);
                    tempPassengers=DeletePassenger(tempPassengers,1);

                }
                bussesLinkedList= DeleteBus(bussesLinkedList,bussesCounter);
                printf("the bus deleted successfully\n\n");
                printf("________________________________________________________________________________\n");

                break;
            }

            if(tempBusses->nextBus==NULL){
                break;
            }
        }
        tempBusses=tempBusses->nextBus;
        bussesCounter++;
    }
    return bussesLinkedList;
}
struct Busses* DeleteBus( struct Busses* bussesLinkedList,int position){//used to delete an passenger from list by it's index
    if(bussesLinkedList==NULL){//if the list is not created yet return null
        printf("the list is not crated yet\n");
        return NULL;
    }
    if(bussesLinkedList->nextBus==NULL){//if the list is empty return the list
        printf("the list is empty\n");
        return bussesLinkedList;
    }
    if(position==0){//there is no index 0
        printf("list start from 1 there is no bus it's number equal to 0\n");
        return bussesLinkedList;
    }
    if(position==1){//if you need to delete the first node just set head point on the second node and free first node
        struct Busses* tempBusses=bussesLinkedList;
        tempBusses=tempBusses->nextBus;
        bussesLinkedList->nextBus=tempBusses->nextBus;
        free(tempBusses);
        return bussesLinkedList;
    }
    if(position>=2&&position<= BussesLinkedListLength(bussesLinkedList)){//if the node index between 2 and the length
        struct Busses* tempBusses=bussesLinkedList,*current;
        int counter=0;
        while (counter<position-1){//go to the previous node
            tempBusses=tempBusses->nextBus;
            counter++;
        }
        current=tempBusses->nextBus;//current point on the deleted node
        tempBusses->nextBus=current->nextBus;//the list point on the next of current
        free(current);//free current
        return bussesLinkedList;
    }
    if(position> BussesLinkedListLength(bussesLinkedList)){//if the index more than the length return list
        printf("the bus is not found\n");
        return bussesLinkedList;
    }
    return bussesLinkedList;
}
void PrintAllBussesData(struct Busses* bussesLinkedList){//used to print all busses info
    if(bussesLinkedList==NULL){//if the list is not created yet return
        printf("list is not create yet \n");
        return;
    }
    if(bussesLinkedList->nextBus==NULL){//if the list is empty return
        printf("there is no busses added yet\n");
        return;
    }

    int x=1;
    struct Busses* tempBusses=bussesLinkedList;
    tempBusses=tempBusses->nextBus;
    while(tempBusses->nextBus!=NULL||tempBusses->nextBus==NULL){//for each bus print the bus info
        printf("bus number: %d\n",tempBusses->busNumber);
        printf("travelling date is: %d\n",tempBusses->busDate);
        printf("travelling time is: %s\n",tempBusses->busTime);
        printf("travel from: %s\n",tempBusses->busFrom);
        printf("travel to: %s\n",tempBusses->busInto);
        printf("ticket price: %d\n",tempBusses->ticketPrice);
        printf("capacity is: %d\n\n",tempBusses->capacity);
        if(tempBusses->passenger==NULL||tempBusses->passenger->Next==NULL){//if the bus has no passengers
            printf("this bus has no passengers\n\n");
            printf("________________________________________________________________________________\n");
            if(tempBusses->nextBus==NULL){
                return;
            }
            tempBusses=tempBusses->nextBus;
            continue;
        }
        if(tempBusses->passenger!=NULL&&tempBusses->passenger->Next!=NULL){//if bus has passengers print the passengers IDs
            struct Passengers* tempPassengers=tempBusses->passenger->Next;
            printf("IDs of passenger for this bus is:\n");
            int count=1;
            while (tempPassengers->Next!=NULL||tempPassengers->Next==NULL) {
                printf("%d     ", tempPassengers->travellerID);
                count++;
                if(count==5){
                    count=1;
                    printf("\n");
                }
                if(tempPassengers->Next==NULL){
                    break;
                }
                tempPassengers=tempPassengers->Next;
            }
            printf("\n\n________________________________________________________________________________\n");
        }
        x++;
        if(tempBusses->nextBus==NULL){
            return;
        }
        if(tempBusses->nextBus==NULL){
            return;
        }
        tempBusses=tempBusses->nextBus;
    }
}
struct Busses* DeleteBusCalling(struct Busses* bussesLinkedList,struct Passengers* unMatchedPassengers){//used to print all busses info
    int busNumber;
    printf("enter the bus number\n");
    scanf("%d",&busNumber);
    return DeleteBusByItsNumber(bussesLinkedList,unMatchedPassengers,busNumber);

}
struct Busses* AddNewPassenger(struct Busses* bussesLinkedList){//add a new passenger into a bus
    int busNumberN;
    int passID;
    PrintAllBussesData(bussesLinkedList);//print the busses data to let user chose in which bus he wants to add
    printf("in witch bus you want to add the passenger?,enter the bus number carefully\n");
    scanf("%d",&busNumberN);
    printf("enter the ID of the passenger carefully\n");
    scanf("%d",&passID);
    struct Busses* tempBusses=bussesLinkedList;
    tempBusses=tempBusses->nextBus;
    while (tempBusses->nextBus!=NULL||tempBusses->nextBus==NULL){//for each bus
        if(tempBusses->busNumber==busNumberN){//when find bus number
            if(tempBusses->passenger==NULL){//if the list of bus passengers is not created yet ,create it
                tempBusses->passenger= BulidPassengerLinkedList(tempBusses->passenger);
            }
            if (tempBusses->capacity <= 0) {//if the bus is full
                printf("bus is full\n");
                return bussesLinkedList;
            } else {
                //add the passenger into the bus passengers list
                tempBusses->passenger = InsertPassenger(tempBusses->passenger, passID, tempBusses->busDate,
                                                        tempBusses->busTime,
                                                        tempBusses->busFrom, tempBusses->busInto, NULL);
                tempBusses->capacity--;
                printf("the passenger added to bus successfully\n");
                return bussesLinkedList;
            }
        }
        if(tempBusses->nextBus==NULL){
            break;
        }
        tempBusses=tempBusses->nextBus;
    }
    printf("the bus is not found\n");
    return bussesLinkedList;

}
struct Busses* DeletePassengerFromBus(struct Busses* bussesLinkedList){//delete a passenger from a bus
    int busNumberN;
    int passID;
    PrintAllBussesData(bussesLinkedList);//print the busses info to let user chose from which bus he wants to delete
    printf("from witch bus you want to delete the passenger?,enter the bus number carefully\n");
    scanf("%d",&busNumberN);
    printf("enter the ID of the passenger you want to delete carefully\n");
    scanf("%d",&passID);
    struct Busses* tempBusses=bussesLinkedList;
    tempBusses=tempBusses->nextBus;
    while (tempBusses->nextBus!=NULL||tempBusses->nextBus==NULL){//for each bus bus
        if(tempBusses->busNumber==busNumberN){//when bsu number is equal
            if(tempBusses->passenger==NULL||tempBusses->passenger->Next==NULL){//if the bus is empty
                printf("the bus is empty\n");
                return bussesLinkedList;
            }
            struct Passengers* tempPassengers=tempBusses->passenger->Next;
            int count=1;
            while (tempPassengers->Next!=NULL||tempPassengers->Next==NULL){//check all passengers
                if(tempPassengers->travellerID==passID){//when equal delete passenger
                    tempBusses->passenger= DeletePassenger(tempBusses->passenger,count);
                    printf("the passenger deleted successfully\n");
                    return bussesLinkedList;
                }
                count++;
                if(tempPassengers->Next==NULL){
                    break;
                }
                tempPassengers=tempPassengers->Next;
            }
            count--;

            int x=PassengerLinkedListLength(tempPassengers);
            int y=((count)== x);
            printf("%d\n",y);
            if(y==0){
                printf("the passenger s not in the bus\n");
                return bussesLinkedList;
            }
        }
        if(tempBusses->nextBus==NULL){
            break;
        }
        tempBusses=tempBusses->nextBus;
    }
    printf("the bus is not found\n");
    return bussesLinkedList;
}