#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct property {
    int no;
    char name[20];
    char phone[20];
    char age[20];
    char house[20];
    char car[20];
    char stock[20];
    char coin[20];
    char land[20];
    char dollar[20];
    char bank[20];
    char annual_salary[20];
    char save[20];
    struct property* link;
}property;

property* head = NULL;
property* tail = NULL;

void menu();

property* createnode()
{
    int no1;
    char name1[20], phone1[20], house1[20], car1[20], stock1[20], age1[20];
    char coin1[20], land1[20], dollar1[20], bank1[20], annual_salary1[20], save1[20];
    property *new_user = (property*)malloc(sizeof(property));
    
    
    printf("Input user number : ");
    scanf("%d", &no1);
    printf("Input Age: ");
    scanf("%s", age1);
    printf("Input Name: ");
    scanf("%s", name1);
    printf("Input Tel Number: ");
    scanf("%s", phone1);
    printf("unit is 100 million\n");
    printf("Input house price: ");
    scanf("%s", house1);
    printf("Input car price: ");
    scanf("%s", car1);
    printf("Input stock price: ");
    scanf("%s", stock1);
    printf("Input coin price: ");
    scanf("%s", coin1);
    printf("Input land price: ");
    scanf("%s", land1);
    printf("Input dollar property: ");
    scanf("%s", dollar1);
    printf("Input bank property: ");
    scanf("%s", bank1);
    printf("unit is 10 million\n");
    printf("Input annual_salary: ");
    scanf("%s", annual_salary1);
    printf("Input save property: ");
    scanf("%s", save1);

    new_user->no = no1;
    for (int i = 0; i < 20; i++) {
        new_user->name[i] = name1[i];
        new_user->age[i] = age1[i];
        new_user->phone[i] = phone1[i];
        new_user->house[i] = house1[i];
        new_user->car[i] = car1[i];
        new_user->stock[i] = stock1[i];
        new_user->coin[i] = coin1[i];
        new_user->land[i] = land1[i];
        new_user->dollar[i] = dollar1[i];
        new_user->bank[i] = bank1[i];
        new_user->annual_salary[i] = annual_salary1[i];
        new_user->save[i] = save1[i];

    }
    printf("		Data Inserted\n");

    new_user->link = NULL;
    return new_user;
}
void useradd(property** head)
{
    property* newnode = createnode();
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        property* new_user = *head;
        while (new_user->link != NULL)
        {
            new_user = new_user->link;
        }
        new_user->link = newnode;
    }
    
}


void user_delete()
{

    property* curr = head;
    property* prev_user = NULL;


    int input;

    printf("delete user no: ");
    scanf("%d", &input);
    while (curr != NULL)
    {
        if (curr->no == input)
        {
            if (head == curr)
                {
                    if (head->link == NULL)
                        head = tail = NULL;
                    else
                        head = head->link;

                }
            else if (tail == curr)
            {
                prev_user->link = NULL;
                    tail = prev_user;
            }
            else
            {
                prev_user->link = curr->link;
            }

            free(curr);
            break;
        }

        prev_user = curr;
        curr = curr->link;
    }
    
 }

void user_search()
{
    property* user_search = head;

    int input;

    printf("Input user no: ");
    scanf_s("%d", &input);

    if (user_search == NULL)
    {
        printf("not found data\n");
        return;
    }

    while (user_search != NULL)
    {
        if (user_search->no == input)
        {
            printf("name: %s\nage: %s\n", user_search->name,user_search->age);
            printf("phone: %s\nhouse: %s\n",user_search->phone, user_search->house);
            printf("car: %s\nstock: %s\n", user_search->car,user_search->stock);
            printf("coin: %s\nland: %s\n", user_search->coin,user_search->land );
            printf("dollar: %s\nbank: %s\n", user_search->dollar,user_search->bank);
            printf("annual_salary: %s\nsave: %s\n",user_search->annual_salary,user_search->save);
        }

        user_search = user_search->link;
    }
    
}

void user_print()
{
    property* user_print = head;

    if (user_print == NULL)
    {
        printf("not found data\n");
        menu();
        return;
    }
    
    while (user_print != NULL)
    {
        printf("==================user_data==================\n no: %d / user_age: %s / user_name: %s / user_phone: %s \n", user_print->no, user_print->age,user_print->name, user_print->phone);
        printf("user_house: %s / user_car: %s / user_stock: %s \n", user_print->house, user_print->car, user_print->stock);
        printf("user_coin: %s / user_land: %s / user_dollar: %s \n", user_print->coin, user_print->land, user_print->dollar);
        printf("user_bank: %s / user_annual_salary: %s / user_save: %s \n", user_print->bank, user_print->annual_salary, user_print->save);
        printf("=============================================\n");
        user_print = user_print->link;
    }
   
}
void user_manage()
{
    property* user_manage = head;
    int input;
    printf("Input user no: ");
    scanf("%d", &input);
    int j = 0;
    int avg = 0;
    float flex = 0;
    if (user_manage == NULL)
    {
        printf("not found data\n");
        return;
    }
    while (user_manage != NULL)
    {
        if (user_manage->no == input)
        {   
            avg = ( atoi(user_manage->house)+ atoi(user_manage->car)+ atoi(user_manage->coin)+ atoi(user_manage->stock)+ atoi(user_manage->dollar)+ atoi(user_manage->bank))/6;
            flex = ( atof(user_manage->annual_salary) - atof(user_manage->save)) / atof(user_manage->annual_salary);
            
            if (avg < atoi(user_manage->house))
                    j++;
            if (avg < atoi(user_manage->car))
                    j++;
            if (avg < atoi(user_manage->coin))
                    j++;
            if (avg < atoi(user_manage->stock))
                    j++;
            if (avg < atoi(user_manage->dollar))
                    j++;
            if (avg < atoi(user_manage->bank))
                    j++;

            switch (j) {
            case 0:
                printf("완벽한 분산 투자입니다.\n");
                break;
            case 1:
                printf("좋은 분산 투자입니다.\n");
                break;
            case 2:
                printf("분산 투자 입문을 환영합니다.\n");
                break;
            case 3:
                printf("분산 투자가 필요하실 수도 있습니다.\n");
                break;
            case 4:
                printf("분산 투자를 하지 않으면 재산 종류에 따라 위험이 있을 수 있습니다.\n");
                if (avg < atoi(user_manage->coin))
                    printf("코인은 변동성이 커서 위험합니다.!!\n");
                else if (avg < atoi(user_manage->stock))
                    printf("주식은 변동성이 커서 위험합니다.!!\n");
                break;
            case 5:
                printf("분산 투자를 하지 않으면 매우 위험합니다.\n");
                if (avg < atoi(user_manage->coin))
                    printf("코인은 변동성이 커서 위험합니다.!!\n");
                else if (avg < atoi(user_manage->stock))
                    printf("주식은 변동성이 커서 위험합니다.!!\n");
                break;
            case 6:
                printf("finance error");
                break;
            }
            if (20 <= atoi(user_manage->age) && 30 > atoi(user_manage->age))
                if (flex > 0.5)
                    printf("소비지수가 높습니다.\n 과소비중입니다.\n");
                else
                    printf("소비습관에 큰 문제는 없습니다.\n");
            if (30 <= atoi(user_manage->age) && 40 > atoi(user_manage->age))
                if (flex > 0.7)
                    printf("소비지수가 높습니다.\n 과소비중입니다.\n");
                else
                    printf("소비습관에 큰 문제는 없습니다.\n");
            if (40 <= atoi(user_manage->age) && 50 > atoi(user_manage->age))
                if (flex > 0.8)
                    printf("소비지수가 높습니다.\n 과소비중입니다.\n");
                else
                    printf("소비습관에 큰 문제는 없습니다.\n");
            if (50 <= atoi(user_manage->age))
                if (flex > 0.8)
                    printf("소비지수가 높습니다.\n 과소비중입니다.\n");
                else
                    printf("소비습관에 큰 문제는 없습니다.\n");


        }
        user_manage = user_manage->link;
    }
    
}
void reset()
{
    

        property* curr = head;


        int input;

        printf("delete user no: ");
        scanf("%d", &input);

        while (curr != NULL) {

            if (curr->no == input) {
                head = NULL;
                break;
            }
            curr = curr->link;
        }
    
}
void SaveFile() {
    property* curr = head;
    int i, state;
    FILE* fp = fopen("Data.txt", "wt");
    if (fp == NULL) {
        printf("File open error!\n");
        return -1;
    }
    while (curr != NULL){
        fprintf(fp, "no: %d, name: %s\n", curr->no, curr->name);
        fprintf(fp, "age: %s, phone: %s\n", curr->age, curr->phone);
        fprintf(fp, "house: %s car: %s\n", curr->house, curr->car);
        fprintf(fp, "stock: %s coin: %s\n", curr->stock, curr->coin);
        fprintf(fp, "land: %s dollar: %s\n", curr->land, curr->dollar);
        fprintf(fp, "bank: %s annual_salary: %s\n", curr->bank, curr->annual_salary);
        fprintf(fp, "save: %s\n", curr->save);
        fputc('\n', fp);
        curr = curr->link;
    }
    state = fclose(fp);
    if (state != 0) {
        printf("File Close Error!\n");
        return -1;
    }
    printf("		Data Save\n");
    return 0;
 }
    

void menu()
{
    int input;

    printf("***** MENU *****\n");
    printf("1. 추가\n2. 삭제\n3. 검색\n4. 데이터 출력\n5. 자산 관리\n6. 초기화\n7. 저장\n");
    printf("what's your choice?: ");
    scanf("%d", &input);
    switch (input) {
        case 1: 
            useradd(&head);     
            menu();
            break;
        case 2:
            user_delete();
            menu();
            break;
        case 3:
            user_search();
            menu();
            break;
        case 4:
            user_print();
            menu();
            break;
        case 5:
            user_manage();
            menu();
            break;
        case 6:
            reset();
            menu();
            break;
        case 7:
            SaveFile();
            menu();
            break;
    }
}

int main(void) {
    menu();
    return 0;
}
