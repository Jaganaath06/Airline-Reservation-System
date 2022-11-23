#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void validate(int,int);
void details();
void disp_seating(int);
void booking_check();
void reservation(int,int);
void disp_flight_sub(int);
void disp_all();
void disp_tickets();
void cancel();
void disp_main_menu();
void login();
void registration();
void header();
int main(void);


int no_of_entry=0;
int flag=0;
int flight_seats[90]={0};
char booking_user[20];
int apin = 1029;

struct login_details{
  int pin;
  char username[20];
  
};


struct ticket_details{
    unsigned long int phone_no;
    int seat_no;
    int flight_no;
    int class;
	char first_name[20];
	char last_name[20];
	char passport_no[15];
    char booking_user[20];
    struct ticket_details* following;
};

struct ticket_details *head=NULL,*stream=NULL,*dummy;


void validate(int flight_no,int seat_no){
    int check = ((flight_no-1)*15)+(seat_no-1);
    if(flight_seats[check]==0){
        flight_seats[check] = 1;
        if(seat_no<7) stream->class = 1;
        else stream->class=2;
        system("clear");
        printf("\n\n\t\t\t{{Your seat has been booked!!}}\n\n");
        
    }
    else{
        printf("\n\t\t\t{{This seat has been already booked!! Choose another seat number}}");
        printf("\n\n\t\t\tEnter the seat number to reserve: ");
        scanf("%d",&stream->seat_no);
        
        validate(flight_no,stream->seat_no);
    }
    
}

void details(){
    
    
    printf("\n\n\t\t\tEnter your passport number: ");
    scanf("%s",stream->passport_no);
    printf("\n\t\t\tEnter your first name: ");
    scanf("%s",stream->first_name);
    printf("\n\t\t\tEnter your second name: ");
    scanf("%s",stream->last_name);
    printf("\n\t\t\tEnter your phone number: +91 ");
    scanf("%lu",&stream->phone_no);
    printf("\n\t\t\t\t1-> CCFL1 - Chennai - Coimbatore\n\t\t\t\t2-> BCFL1 - Bengaluru - Coimbatore\n\t\t\t\t3-> PCFL1 - Pune - Chennai\n\t\t\t\t4-> CCFL2 - Coimbatore - Chennai\n\t\t\t\t5-> BCFL2 - Coimbatore - Bengaluru\n\t\t\t\t6-> PCFL2 - Chennai - Pune");
    printf("\n\n\t\t\tPick your flight: ");
    scanf("%d",&stream->flight_no);
    printf("\n\t\t\tEnter the seat number to reserve: ");
    scanf("%d",&stream->seat_no);
    
    validate(stream->flight_no,stream->seat_no);

}

void disp_seating(int flight){
    int i=0,j=flight*15,flag=0;
    printf("\n\t\t\t=====================================================");
    printf("\n\t\t\t\t\t  Available seats");
    printf("\n\t\t\t=====================================================");
    printf("\n\n\t\t\tBusiness class  - ");
    for(i=j+0;i<j+6;i++){
        if(flight_seats[i]==0){
            printf("%d ",i+1-(flight*15));
            flag=1;
        }
    }
    
    
    printf("\n\t\t\tEconomy class   - ");
    for(i=j+6;i<j+15;i++){
        if(flight_seats[i]==0){
            printf("%d ",i+1-(flight*15));
            flag=1;
        }
    }
    

    if(!flag) printf("\n\t\t\tOh sorry!!! All tickets for flight has been reserved");
    
    
    
}

void booking_check(){
    int no_of_seats,count=0,flight,proceed=0;
    
    system("clear");
    header();
    
    
    printf("\n\t\t\tUser{%s}",booking_user);
    printf("\n\n\t\t\tEnter the no of seats: ");
    scanf("%d",&no_of_seats);
    printf("\n\t\t\tPick the flight to view seating\n\n\t\t\t1-> CCFL1 - Chennai - Coimbatore\n\t\t\t2-> BCFL1 - Bengaluru - Coimbatore\n\t\t\t3-> PCFL1 - Pune - Chennai\n\t\t\t4-> CCFL2 - Coimbatore - Chennai\n\t\t\t5-> BCFL2 - Coimbatore - Bengaluru\n\t\t\t6-> PCFL2 - Chennai - Pune");
    printf("\n\n\t\t\tEnter your choice: ");
    scanf("%d",&flight);
    disp_seating(flight-1);
    printf("\n\n\t\t\tPlease verify number of seats available and number of \n\t\t\tseats needed for you and proceed for reservation\n");
    printf("\n\t\t\tAre u ready to reserve?\n\t\t\t\t1 Yes\n\t\t\t\t0 No");
    printf("\n\n\t\t\tEnter your choice: ");
    scanf("%d",&proceed);
    
    while(no_of_seats-- && proceed) reservation(++count,flight-1);
    if(!proceed) disp_main_menu();
    
}



void reservation(int count,int flight){
   
    system("clear");
    header();
    printf("\n\t\t\tUser{%s}",booking_user);
    int i;
    disp_seating(flight);
    printf("\n\n\t\t\tDetails for Ticket %d",count);
    
    
    stream = head;
    
    if(head==NULL){
        stream = head = (struct ticket_details*)malloc(sizeof(struct ticket_details)*1);
        strcpy(stream->booking_user,booking_user);
        details();
        stream->following=NULL;
    }
    else{
        
        while(stream->following) stream = stream->following;
        
        stream->following = (struct ticket_details*)malloc(sizeof(struct ticket_details)*1);
        stream = stream->following;
        strcpy(stream->booking_user,booking_user);
        details();
        stream->following = NULL;
    }
    
}




struct login_details login_array[50];

void disp_flight_sub(int flight_no){
    printf("\n\t\t\tYour flight     : ");
    switch(stream->flight_no){
        case 1:
            printf("1 CCFL1 - Chennai - Coimbatore");
            break;
        case 2:
            printf("2 BCFL1 - Bengaluru - Coimbatore");
            break;
        case 3:
            printf("3 PCFL1 - Pune - Chennai");
            break;
        case 4:
            printf("4 CCFL2 - Coimbatore - Chennai");
            break;
        case 5:
            printf("5 BCFL2 - Coimbatore - Bengaluru");
            break;
        case 6:
            printf("6 PCFL2 - Chennai - Pune");
            break;
    }
}

void disp_all(){
    system("clear");
    header();
    printf("\n\t\t\tUser{%s}",booking_user);
    flag=0;
    stream = head;
    while(stream){
    flag=1;
    printf("\n\t\t\t=====================================================");
    printf("\n\n\t\t\tPassport number : %s",stream->passport_no);
    printf("\n\t\t\tFirst name      : %s",stream->first_name);
    printf("\n\t\t\tSecond name     : %s",stream->last_name);
    printf("\n\t\t\tPhone number    : +91 %lu",stream->phone_no);
    disp_flight_sub(stream->flight_no);
    printf("\n\t\t\tClass           : %d",stream->class);
    printf("\n\t\t\tSeat no         : %d",stream->seat_no);
    if(stream->flight_no<4) printf("\n\t\t\tTiming         : 08:30");
    else printf("\n\t\t\tTiming         : 14:30");
    printf("\n\n\t\t\tBooked by %s",stream->booking_user);
    printf("\n\t\t\t=====================================================");
    stream = stream->following;
    }
    if(!flag) printf("\n\n\t\t\tNo records found!!!");
    flag = 0;
    printf("\n\n\t\t\tPress any number to continue ");
    scanf("%d",&flag);
    if(flag){
        system("clear");
    }
}

void disp_tickets(){
    system("clear");
    header();
    printf("\n\t\t\tUser{%s}",booking_user);
    
    flag=0;
    stream = head;
    while(stream){
        if(!strcmp(stream->booking_user,booking_user)){
            flag = 1;
            printf("\n\t\t\t=====================================================");
            printf("\n\n\t\t\tPassport number: %s",stream->passport_no);
            printf("\n\t\t\tFirst name     : %s",stream->first_name);
            printf("\n\t\t\tSecond name    : %s",stream->last_name);
            printf("\n\t\t\tPhone number   : +91 %lu",stream->phone_no);
            disp_flight_sub(stream->flight_no);
            printf("\n\t\t\tYour class     : %d \n\t\t\t 1 -> Economy \n\t\t\t 2 -> Business",stream->class);
            printf("\n\t\t\tYour seat      : %d",stream->seat_no);
            if(stream->flight_no<4) printf("\n\t\t\tTiming         : 08:30");
            else printf("\n\t\t\tTiming         : 14:30");
            printf("\n\n\t\t\tBooked by %s",stream->booking_user);
            printf("\n\t\t\t=====================================================");
        }
    
        stream = stream->following;
    }
    
    if(!flag) printf("\n\n\t\t\tNo records found!!!");
    flag = 0;
    printf("\n\n\t\t\tPress any number to continue ");
    scanf("%d",&flag);
    if(flag){
        system("clear");
    }
}

void cancel(){
    system("clear");
    header();
    printf("\n\t\t\tUser{%s}",booking_user);
    
    printf("\n\t\t\tCancellation");
    printf("\n\n\t\t\t\t1 Cancel all tickets under my booking\n\t\t\t\t2 Cancel via passport number");
    printf("\n\n\t\t\t Enter your choice: ");
    int option_1,option_2,flag1=0;
    flag = 0;
    char passport[8];
    scanf("%d",&option_1);
    
    stream = head;
    
    switch(option_1){
        case 1:
            printf("\n\t\t\tThis action will delete all records under your bookings.Are you sure??\n\n\t\t\t\t1 Yes\n\t\t\t\t2 No");
            printf("\n\n\t\t\t Enter your choice: ");
            scanf("%d",&option_2);
            if(option_2-2){
                stream = head;
                dummy = NULL;
                while(stream != NULL){
                if(!strcmp(stream->booking_user,booking_user) && !flag){
                    flag1=1;
                    head = stream->following; 
                    flight_seats[(((stream->flight_no)-1)*15)+(stream->seat_no)-1]=0;
                    free(stream);
                    stream = head;
                    continue;
                }
                
                else if(strcmp(stream->booking_user,booking_user)!=0){
                    flag = 1;
                    dummy = stream;
                    stream = stream->following;
                    
                }
                
                else if(!strcmp(stream->booking_user,booking_user) && flag){
                    flag1=1;
                   dummy->following = stream->following;
                   flight_seats[(((stream->flight_no)-1)*15)+(stream->seat_no)-1]=0;
                   free(stream);
                   stream = dummy->following;
                }
            }
            }
            
            if(!flag1) printf("\n\n\t\t\tNo tickets found!!!");
            system("clear");
            break;
        case 2:
            
            printf("\n\t\t\tEnter your passport number: ");
            scanf("%s",passport);
            stream = head;
            dummy = NULL;
            while(stream != NULL){
                if(!strcmp(stream->passport_no,passport) && !flag){
                    flag1=1;
                    head = stream->following; 
                    flight_seats[(((stream->flight_no)-1)*15)+(stream->seat_no)-1]=0;
                    free(stream);
                    stream = head;
                    continue;
                }
                
                else if(strcmp(stream->passport_no,passport)!=0){
                    flag = 1;
                    dummy = stream;
                    stream = stream->following;
                    
                }
                
                else if(!strcmp(stream->passport_no,passport) && flag){
                    flag1=1;
                   dummy->following = stream->following;
                   flight_seats[(((stream->flight_no)-1)*15)+(stream->seat_no)-1]=0;
                   free(stream);
                   stream = dummy->following;
                }
            }
            
            if(!flag1) printf("\n\n\t\t\tNo tickets found!!!");
            system("clear");
            break;
        default:
            printf("\n\t\t\tInvalid Operation\n");
            break;
    }
    
    
    
}

void disp_main_menu(){
    
    system("clear");
    
    while(1){
    header();
    printf("\n\t\t\tUser{%s}",booking_user);

    
    int option_1,flight_no,admin;
    
    printf("\n\n\t\t\tSelect one\n\n\t\t\t1 Reservation\n\t\t\t2 Display tickets\n\t\t\t3 Cancel tickets\n\t\t\t4 Display all records\n\t\t\t5 Display seating\n\t\t\t6 Exit");
    printf("\n\n\t\t\tEnter your choice: ");
    scanf("%d",&option_1);
    
    switch(option_1){
        case 1:
            booking_check();
            break;
        case 2:
            disp_tickets();
            break;
        case 3:
            cancel();
            break;
        case 4:
            system("clear");
            printf("\n\t\t\tEnter admin pin: ");
            scanf("%d",&admin);
            if(admin==apin) disp_all();
            break;
        case 5:
            printf("\n\n\t\t\t1-> CCFL1 - Chennai - Coimbatore\n\t\t\t2-> BCFL1 - Bengaluru - Coimbatore\n\t\t\t3-> PCFL1 - Pune - Chennai\n\t\t\t4-> CCFL2 - Coimbatore - Chennai\n\t\t\t5-> BCFL2 - Coimbatore - Bengaluru\n\t\t\t6-> PCFL2 - Chennai - Pune");
            printf("\n\n\t\t\t Enter your choice: ");
            scanf("%d",&flight_no);
            disp_seating(flight_no-1);
            break;
        case 6:
            main();
            break;
        default:
            printf("\n\t\t\t====================================================");
            printf("\n\t\t\t|\t\tInvalid operation\t\t   |");
            printf("\n\t\t\t====================================================");
            break;
    
    }
}
}

void login(){
    int pin,i;
    system("clear");
    printf("\n\t\t\t=====================================================");
    printf("\n\t\t\t\t\t\tLogin");
    printf("\n\t\t\t=====================================================");
    printf("\n\n\t\t\tEnter the username: ");
    scanf("%8s",booking_user);
    printf("\n\t\t\tEnter the pin: ");
    scanf("%d",&pin);
    
    for(i=0;i<no_of_entry;i++){
        if(strcmp(booking_user,login_array[i].username)==0 && pin==login_array[i].pin){
                system("clear");
                disp_main_menu();
                return;
        }
        
    }
    
    
    printf("\n\t\t\t====================================================");
    printf("\n\t\t\t|\t\tInvalid username or pin\t\t   |");
    printf("\n\t\t\t====================================================");
    
    
}

void registration(){
    
    
    if(no_of_entry==50){
        printf("Registration limit exceeded!! Please Check back after some time");
        return;
    }
    
    system("clear");
    int i = no_of_entry++;
    printf("\n\t\t\t=====================================================");
    printf("\n\t\t\t\t\t   Registration");
    printf("\n\t\t\t=====================================================");
    printf("\n\n\t\t\tEnter the username: ");
    scanf("%s",login_array[i].username);
    printf("\n\t\t\tEnter the pin: ");
    scanf("%d",&login_array[i].pin);
    
    
}

void header(){
    printf("\n\n\t\t\t----------------------------------------------------");
    printf("\n\t\t\t|\t Airline Reservation System By Jaganaath   |");
    printf("\n\t\t\t----------------------------------------------------");
}

int main()
{
    system("clear");
    header();
    
    while(1){
    
    int option_1;
    printf("\n\n\t\t\tSelect one:\n\n\t\t\t1 Login\n\t\t\t2 Register\n\t\t\t3 Exit\n");
    printf("\n\t\t\tEnter your choice: ");
    scanf("%d",&option_1);
    
    switch(option_1){
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            exit(0);
        default:
            printf("\nInvalid Operation\n");
            return 0;
    }
    }
    return 0;
}













