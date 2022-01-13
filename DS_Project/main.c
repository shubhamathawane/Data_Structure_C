#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int changeprize(int);
void reservation(int *, int, int);
int choice1(void);
void cancel(int *);
void ticket1(int choice, char name[10], int id2, int price);
void ticket2(int choice, char name[10], int id2, int price);
void ticket3(int choice, char name[10], int id2, int price);
int cmovie(void);
int movie(void);
void details(void);
// Creating movie struct to store user's data
struct moviedetails
{
    char name[25];
    char phone[15];
    int seat;
    int id;
};

struct moviedetails person[300];
int count = 0;
int id2 = 1000;

int main()
{
    int **seat, choice, price = 500, selection, i;
    seat = (int **)calloc(101, sizeof(int *));
    for (i = 0; i < 3; i++)
    {
        *(seat + i) = (int *)calloc(101, sizeof(int));
    }
    int x;
    while (x != 5)
    {
        choice = choice1();
        switch (choice)
        {
        case 1:
            price = changeprize(price);
            break;
        case 2:
            details();
            break;
        case 3:
            selection = movie();
            reservation(seat[selection - 1], price, selection);
            count++;
            break;
        case 4:
            selection = cmovie();
            cancel(seat[selection - 1]);
            break;
        case 5:
            x = 5;
            break;
        default:
            printf("Choice not available\b");
            break;
        }
    }
}

int changeprize(int prize)
{
	char pass[10], pak[10] = "pass";
	printf("Enter the password to change price of ticket: ");
	scanf("%s", &pass);
	if (strcmp(pass, pak) == 0)
	{
		printf("Please enter new price: ");
		scanf("%d", &prize);
		system("PAUSE");
		system("CLS");
	}
	else
		printf("The entered password is wrong! ");
	return prize;
}

void reservation(int *array, int price, int selection)
{
    int i, j;
    printf("\t      Screen\n\n\n\n");
    for (i = 0; i <= 100; i++)
    {
        if (array[i] == 0)
        {
            printf("%d\t", i);
        }
        else
        {
            printf("*\t", i);
        }
        if (i % 10 == 0)
        {
            printf("\n\n");
        }
    }
    printf("\nPlease enter your name: \n");
    scanf(" %19[^\n]%*[^\n]", &person[count].name);
    printf("\nPlease enter your phone number : \n");
    scanf("%u", &person[count].phone);
    printf("\nWhich seat number you want ? \n");
    scanf("%d", &j);
    if (j > 100 || j < 1)
    {
        printf("Seat1 number is unavailable in this theater !");
        printf("Please re-enter seat number: ");
        scanf("%d", &j);
    }
    if (array[j] == 1)
    {
        printf("Sorry, this ticket is already booked! please choose another seat.\n");
        scanf("%d", &j);
    }
    else
    {
        array[j] = 1;
    }
    person[count].seat = j;
    if (selection == 1)
    {
        ticket1(j, person[count].name, id2, price);
    }
    else if (selection == 2)
    {
        ticket2(j, person[count].name, id2, price);
    }
    else
    {
        ticket3(j, person[count].name, id2, price);
    }
    id2++;
}

int choice1(void)
{
    int choice;
    printf("     Simple Movie Ticket Booking App\n");
    printf("=======================================\n");
    printf("1. To edit price of ticket (admin Only) : \n");
    printf("2. To view researved tickets (admin Only) : \n");
    printf("3. To purchase ticket : \n");
    printf("4. To cancel the ticket : \n");
    printf("5. To Exit : \n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    return choice;
}

void cancel(int *array)
{
    int cSeat, i, stop;
    printf("Please enter ID number of ticket : ");
    scanf("%d", &cSeat);
    for (i = 0; i < 300; i++)
    {
        if (cSeat == person[i].id)
        {
            stop = 5;
            system("cls");
            printf("%s your seat is %d cancelled", person[i].name, person[i].id);
            array[person[i].seat] = 0;
            i = 300;
        }
    }
    if (stop != 5)
    {
        printf("Ticket id number is not valid, Enter valid id number \n");
    }
}

void ticket1(int choice, char name[10], int id2, int price)
{
    system("cls");
    printf("\n\n");
    printf("\t-------------THEATER BOOKING APP-----------\n");
    printf("\t===========================================\n");
    printf("\t Booking id : %d \tShow Name : 3 Idiots\n", id2);
    printf("\t Customer : %s\n", name);
    printf("\t             Date     : 29-08-2022\n");
    printf("\t                        Time      : 9:30PM\n");
    printf("\t                        Hall      : 02\n");
    printf("\t                        Seats No. : %d \n", choice);
    printf("\t                        price .   : %d\n\n", price);
    person[count].id = id2;
    printf("\t===========================================\n");
    return;
}

void details(void)
{
    int i;
    char pass[10], pak[10] = "pass";
    printf("Enter the password to see details: ");
    scanf("%s", &pass);
    if (strcmp(pass, pak) == 0)
    {
        for (i = 0; i < count; i++)
        {
            printf("Seat No: %d is booked by %s booking id is %d\n", person[i].seat, person[i].name, person[i].id);
        }
    }
    else
    {
        printf("Wrong password!\n");
    }
    system("PAUSE");
    system("CLS");
}

int movie(void)
{
    int i;
    system("cls");
    printf("\twhich movie you want to see?\n");
    printf("\t----------------------------\n\n");
    printf("\tpress 1 for  3 Idiots\n\n");
    printf("\tpress 2 for  Interstellar\n\n");
    printf("\tpress 3 for  The Social Media\n");
    scanf("%d", &i);
    system("cls");
    return i;
}

void ticket2(int choice, char name[10], int id2, int price)
{
    system("cls");
    printf("\n\n");
    printf("\t-------------THEATER BOOKING APP-----------\n");
    printf("\t===========================================\n");
    printf("\t Booking id : %d \tShow Name : Interstellar\n", id2);
    printf("\t Customer : %s\n", name);
    printf("\t             Date     : 9-01-2022\n");
    printf("\t                        Time      : 3:30PM\n");
    printf("\t                        Hall      : 03\n");
    printf("\t                        Seats No. : %d \n", choice);
    printf("\t                        price .   : %d\n\n", price);
    person[count].id = id2;
    printf("\t===========================================\n");
    return;
}

int cmovie(void)
{
    int i;
    printf("\tWhich movie ticket you want to cancel?\n");
    printf("\t----------------------------------\n");
    printf("\tpress 1 for 3 Idiots\n\n");
    printf("\tpress 2 for Interstellar\n\n");
    printf("\tpress 3 for The social Media\n\n");
    scanf("%d", &i);
    return i;
}

void ticket3(int choice, char name[10], int id2, int price)
{
    system("cls");
    printf("\n\n");
    printf("\t-------------THEATER BOOKING APP-----------\n");
    printf("\t===========================================\n");
    printf("\t Booking id : %d \tShow Name : The Social Media\n", id2);
    printf("\t Customer : %s\n", name);
    printf("\t                         Date     : 10-01-2022\n");
    printf("\t                        Time      : 3:30PM\n");
    printf("\t                        Hall      : 04\n");
    printf("\t                        Seats No. : %d \n", choice);
    printf("\t                        price .   : %d\n\n", price);
    person[count].id = id2;
    printf("\t===========================================\n");
    return;
}
