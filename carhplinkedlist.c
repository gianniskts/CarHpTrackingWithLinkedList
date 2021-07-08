#include <stdio.h>
#include <stdlib.h>

struct car{
        int car;
        int hp;
        struct car* next;
};
struct car* createCar(int, int);
void connect(struct car*, struct car*);
void printAll(struct car*);
void freeAll(struct car*);

int main(void){
        printf("Enter the number of cars you want to track\n");
        int num;
                scanf("%d", &num);
        struct car* newEnd;
        struct car* start;
        struct car* end;
        
        for(int i=0; i<num; i++){
                int carNum, carHp;
                printf("Enter the car(1=Audi, 2=BMW, 3=Mercedes)\n");
                        scanf("%d", &carNum);
                printf("Enter HorsePower\n");
                        scanf("%d", &carHp);
                newEnd = createCar(carNum, carHp);
                        if(i==0){
                                start=end=newEnd;
                        }
                        connect(newEnd, end);
                        end=newEnd;
        }
        printAll(start);
        freeAll(start);
                return 0;
}

struct car* createCar(int carNum, int hp){
        struct car* newCar = (struct car*)malloc(sizeof(*newCar));
        newCar->car = carNum;
        newCar->hp = hp;
                return newCar;
}
void connect(struct car* new, struct car* previous){
        previous->next = new;
}
void printAll(struct car* start){
        struct car* x=start;
        while(x!=NULL){
                printf("%d  %d\n", x->car, x->hp);
                x = x->next;
        }
}
void freeAll(struct car* start){
        struct car* x = start->next;
        free(start);
        struct car* next;
        while(x!=NULL){
                next = x->next;
                free(x);
                x=next;
        }
}
