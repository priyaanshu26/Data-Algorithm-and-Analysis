#include <stdio.h>
#define SIZE 100

struct Stack{
    int top;
    int arr[SIZE];
}s;

void push(int element){
    s.arr[++s.top]=element;
    printf("Element has been pushed\n");
}

void pop(){
    printf("Popped element is: %d \n", s.arr[s.top--]);
}

void change(int element, int index){
    s.arr[s.top-index+1]=element;
}

void display(){
    int i;
    for(i=s.top; i<=0;i++){
        printf("Elements are: %d \n", s.arr[i]);
    }
}

void main(){
    while(1){
        int choice = 0;
        printf("Enter your Choice: \n 1: Push \n 2: Pop \n 3: Change \n 4: Display \n 0: Exit \n");
        scanf("%d", &choice);
        if(choice == 1){
            int element;
            printf("Enter element: ");
            scanf("%d",&element);
            push(element);
        }else if(choice == 2){
            pop();
        }else if(choice == 3){
            int element;
            int index;
            printf("Enter index of element to change:");
            scanf("%d",&index);
            printf("Enter element: ");
            scanf("%d",&element);
            change(element, index);
        }else if(choice == 4){
            display();
        }else if(choice == 0){
            printf("Thank you.. Exiting.... \n");
            break;
        }
    }
}