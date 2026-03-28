#include <stdio.h>
#include <string.h>

#define MAX 100


// Q1: REVERSE A STRING USING STACK


char stack1[MAX];
int top1 = -1;

void push1(char ch) {
    stack1[++top1] = ch;
}

char pop1() {
    return stack1[top1--];
}


// Q2: BALANCED PARENTHESES USING STACK


char stack2[MAX];
int top2 = -1;

void push2(char ch) {
    stack2[++top2] = ch;
}

char pop2() {
    return stack2[top2--];
}

// Q3: NEXT GREATER ELEMENT USING STACK

int stack3[MAX];
int top3 = -1;

void push3(int x) {
    stack3[++top3] = x;
}

int pop3() {
    return stack3[top3--];
}

// Q4: PRINTER QUEUE USING SIMPLE QUEUE

int queue1[MAX];
int front1 = -1, rear1 = -1;

void enqueue1(int x) {
    if(rear1 == MAX - 1)
        printf("Queue Full\n");
    else {
        if(front1 == -1) front1 = 0;
        queue1[++rear1] = x;
    }
}

void dequeue1() {
    if(front1 == -1 || front1 > rear1)
        printf("Queue Empty\n");
    else
        printf("Printed document: %d\n", queue1[front1++]);
}

void display1() {
    int i;
    if(front1 == -1 || front1 > rear1)
        printf("No pending documents\n");
    else {
        printf("Pending documents: ");
        for(i = front1; i <= rear1; i++)
            printf("%d ", queue1[i]);
        printf("\n");
    }
}

// Q5: CIRCULAR QUEUE IMPLEMENTATION


int queue2[MAX];
int front2 = -1, rear2 = -1;

void enqueue2(int x) {
    if((rear2 + 1) % MAX == front2)
        printf("Queue Full\n");
    else {
        if(front2 == -1) front2 = 0;
        rear2 = (rear2 + 1) % MAX;
        queue2[rear2] = x;
    }
}

void dequeue2() {
    if(front2 == -1)
        printf("Queue Empty\n");
    else {
        printf("Removed: %d\n", queue2[front2]);
        if(front2 == rear2)
            front2 = rear2 = -1;
        else
            front2 = (front2 + 1) % MAX;
    }
}

void peek2() {
    if(front2 == -1)
        printf("Queue Empty\n");
    else
        printf("Front element: %d\n", queue2[front2]);
}

void display2() {
    int i = front2;
    if(front2 == -1)
        printf("Queue Empty\n");
    else {
        printf("Queue: ");
        while(1) {
            printf("%d ", queue2[i]);
            if(i == rear2) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}


// MAIN FUNCTION WITH MENU


int main() {
    int choice;

    do {
        printf("\n===== DATA STRUCTURE ASSIGNMENT =====\n");
        printf("1. Reverse String\n");
        printf("2. Balanced Parentheses\n");
        printf("3. Next Greater Element\n");
        printf("4. Printer Queue\n");
        printf("5. Circular Queue\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            // ---------------- Q1 ----------------
            case 1: {
                char str[100];
                int i;

                top1 = -1;

                printf("Enter string: ");
                scanf("%s", str);

                for(i = 0; str[i] != '\0'; i++)
                    push1(str[i]);

                printf("Reversed string: ");
                while(top1 != -1)
                    printf("%c", pop1());

                printf("\n");
                break;
            }

            // ---------------- Q2 ----------------
            case 2: {
                char exp[100];
                int i, balanced = 1;

                top2 = -1;

                printf("Enter expression: ");
                scanf("%s", exp);

                for(i = 0; exp[i] != '\0'; i++) {
                    if(exp[i] == '(')
                        push2(exp[i]);
                    else if(exp[i] == ')') {
                        if(top2 == -1) {
                            balanced = 0;
                            break;
                        }
                        pop2();
                    }
                }

                if(top2 != -1) balanced = 0;

                if(balanced)
                    printf("Balanced Expression\n");
                else
                    printf("Not Balanced\n");

                break;
            }

            // ---------------- Q3 ----------------
            case 3: {
                int arr[100], n, i, next;

                top3 = -1;

                printf("Enter number of elements: ");
                scanf("%d", &n);

                printf("Enter elements: ");
                for(i = 0; i < n; i++)
                    scanf("%d", &arr[i]);

                push3(arr[0]);

                for(i = 1; i < n; i++) {
                    next = arr[i];

                    while(top3 != -1 && stack3[top3] < next)
                        printf("%d -> %d\n", pop3(), next);

                    push3(next);
                }

                while(top3 != -1)
                    printf("%d -> -1\n", pop3());

                break;
            }

            // ---------------- Q4 ----------------
            case 4: {
                int ch, doc;

                do {
                    printf("\n--- Printer Queue ---\n");
                    printf("1.Add\n2.Print\n3.Display\n4.Back\n");
                    scanf("%d", &ch);

                    switch(ch) {
                        case 1:
                            printf("Enter document id: ");
                            scanf("%d", &doc);
                            enqueue1(doc);
                            break;
                        case 2:
                            dequeue1();
                            break;
                        case 3:
                            display1();
                            break;
                    }
                } while(ch != 4);

                break;
            }

            // ---------------- Q5 ----------------
            case 5: {
                int ch, val;

                do {
                    printf("\n--- Circular Queue ---\n");
                    printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Back\n");
                    scanf("%d", &ch);

                    switch(ch) {
                        case 1:
                            printf("Enter value: ");
                            scanf("%d", &val);
                            enqueue2(val);
                            break;
                        case 2:
                            dequeue2();
                            break;
                        case 3:
                            peek2();
                            break;
                        case 4:
                            display2();
                            break;
                    }
                } while(ch != 5);

                break;
            }
        }

    } while(choice != 6);

    return 0;
}