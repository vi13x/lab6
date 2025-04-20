#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#define MAX_STRING 100

typedef struct {
    char *data;
    int front, rear, size, capacity;
} CharQueue;

typedef struct {
    int *data;
    int front, rear, size, capacity;
} IntQueue;

typedef struct {
    char *data;
    int front, rear, size, capacity;
} CharDeque;

CharQueue* initCharQueue(int capacity) {
    CharQueue *q = (CharQueue*)malloc(sizeof(CharQueue));
    q->capacity = capacity;
    q->data = (char*)malloc(capacity * sizeof(char));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

int isCharQueueFull(CharQueue *q) {
    return q->size == q->capacity;
}

int isCharQueueEmpty(CharQueue *q) {
    return q->size == 0;
}

void enqueueChar(CharQueue *q, char ch) {
    if (isCharQueueFull(q)) {
        printf("Очередь полна!\n");
        return;
    }
    if (q->size == 0 || q->data[q->rear] != ch) {
        q->rear = (q->rear + 1) % q->capacity;
        q->data[q->rear] = ch;
        q->size++;
    } else {
        q->front = (q->front + 1) % q->capacity;
        q->size--;
    }
}

void printCharQueue(CharQueue *q) {
    if (isCharQueueEmpty(q)) {
        printf("Очередь пуста\n");
        return;
    }
    printf("Очередь: ");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        printf("%c ", q->data[index]);
    }
    printf("\n");
}

CharDeque* initCharDeque(int capacity) {
    CharDeque *d = (CharDeque*)malloc(sizeof(CharDeque));
    d->capacity = capacity;
    d->data = (char*)malloc(capacity * sizeof(char));
    d->front = capacity / 2;
    d->rear = capacity / 2 - 1;
    d->size = 0;
    return d;
}

void pushLeftChar(CharDeque *d, char ch) {
    if (d->front > 0 && d->data[d->front - 1] != ch) {
        d->front--;
        d->data[d->front] = ch;
        d->size++;
    }
}

void pushRightChar(CharDeque *d, char ch) {
    if (d->rear < d->capacity - 1 && d->data[d->rear] != ch) {
        d->rear++;
        d->data[d->rear] = ch;
        d->size++;
    }
}

void printCharDeque(CharDeque *d) {
    if (d->size == 0) {
        printf("Дек пуст\n");
        return;
    }
    printf("Дек: ");
    for (int i = d->front; i <= d->rear; i++) {
        printf("%c ", d->data[i]);
    }
    printf("\n");
}

IntQueue* initIntQueue(int capacity) {
    IntQueue *q = (IntQueue*)malloc(sizeof(IntQueue));
    q->capacity = capacity;
    q->data = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

void enqueueInt(IntQueue *q, int value) {
    if (q->size < q->capacity) {
        q->rear = (q->rear + 1) % q->capacity;
        q->data[q->rear] = value;
        q->size++;
    }
}

void printIntQueueAndSum(IntQueue *q) {
    int sum = 0;
    printf("Числа из строки: ");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        printf("%d ", q->data[index]);
        sum += q->data[index];
    }
    printf("\nСумма чисел: %d\n", sum);
}

void extractDigitsToQueue(const char *str, IntQueue *q) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            enqueueInt(q, str[i] - '0');
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int size;

    printf("Введите размер очереди: ");
    while (scanf("%d", &size) != 1 || size <= 0) {
        printf("Неверный ввод. Повторите попытку: ");
        while (getchar() != '\n');
    }
    getchar();
    CharQueue *q = initCharQueue(size);
    char ch;
    printf("Введите символы для очереди ('.' для завершения): ");
    while ((ch = getchar()) != '.') {
        if (ch != '\n') enqueueChar(q, ch);
    }
    printCharQueue(q);

    printf("Введите размер дека: ");
    while (scanf("%d", &size) != 1 || size <= 0) {
        printf("Неверный ввод. Повторите попытку: ");
        while (getchar() != '\n');
    }
    getchar();
    CharDeque *d = initCharDeque(size);
    int turn = 0;
    printf("Введите символы для дека ('.' для завершения): ");
    while ((ch = getchar()) != '.') {
        if (ch != '\n') {
            if (turn % 2 == 0) pushRightChar(d, ch);
            else pushLeftChar(d, ch);
            turn++;
        }
    }
    printCharDeque(d);

    getchar();
    char input[MAX_STRING];
    printf("Введите строку: ");
    fgets(input, MAX_STRING, stdin);
    IntQueue *iq = initIntQueue(strlen(input));
    extractDigitsToQueue(input, iq);
    printIntQueueAndSum(iq);

    free(q->data); free(q);
    free(d->data); free(d);
    free(iq->data); free(iq);
    return 0;
}
