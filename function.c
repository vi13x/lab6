#include "function.h"

void initCharQueue(CharQueue *q, int max_size) {
    q->data = (char*)malloc(max_size * sizeof(char));
    q->front = q->rear = -1;
    q->capacity = max_size;
}

int isCharQueueEmpty(CharQueue *q) {
    return q->front == -1;
}

int isCharQueueFull(CharQueue *q) {
    return (q->rear + 1) % q->capacity == q->front;
}

void enqueueChar(CharQueue *q, char c) {
    if (isCharQueueFull(q)) return;
    if (isCharQueueEmpty(q)) q->front = 0;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = c;
}

void dequeueChar(CharQueue *q) {
    if (isCharQueueEmpty(q)) return;
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % q->capacity;
}

void displayCharQueue(CharQueue *q) {
    if (isCharQueueEmpty(q)) {
        printf("Очередь пуста.\n");
        return;
    }
    int i = q->front;
    do {
        printf("%c ", q->data[i]);
        i = (i + 1) % q->capacity;
    } while (i != (q->rear + 1) % q->capacity);
    printf("\n");
}

void task1() {
    int max_size;
    printf("Введите размер очереди: ");
    if (scanf("%d", &max_size) != 1 || max_size <= 0) {
        printf("Неверный размер.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    CharQueue q;
    initCharQueue(&q, max_size);

    char ch;
    while (1) {
        printf("Введите символ (0 для выхода): ");
        ch = getchar();
        while (getchar() != '\n');

        if (ch == '0') break;

        if (!isCharQueueEmpty(&q) && ch == q.data[q.rear]) {
            dequeueChar(&q);
            printf("Удален первый элемент.\n");
        } else {
            if (isCharQueueFull(&q))
                printf("Очередь полна.\n");
            else
                enqueueChar(&q, ch);
        }
        printf("Состояние очереди: ");
        displayCharQueue(&q);
    }
    free(q.data);
}




void initCharDeque(CharDeque *dq, int max_size) {
    dq->data = (char*)malloc(max_size * sizeof(char));
    dq->front = -1;
    dq->rear = 0;
    dq->capacity = max_size;
    dq->size = 0;
}

int isCharDequeEmpty(CharDeque *dq) {
    return dq->size == 0;
}

int isCharDequeFull(CharDeque *dq) {
    return dq->size == dq->capacity;
}

int insertLeft(CharDeque *dq, char c) {
    if (isCharDequeFull(dq)) return 0;
    if (dq->front == -1) dq->front = dq->rear = 0;
    else dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->data[dq->front] = c;
    dq->size++;
    return 1;
}

int insertRight(CharDeque *dq, char c) {
    if (isCharDequeFull(dq)) return 0;
    if (dq->front == -1) dq->front = dq->rear = 0;
    else dq->rear = (dq->rear + 1) % dq->capacity;
    dq->data[dq->rear] = c;
    dq->size++;
    return 1;
}

void displayCharDeque(CharDeque *dq) {
    if (isCharDequeEmpty(dq)) {
        printf("Дек пуст.\n");
        return;
    }
    int i = dq->front;
    for (int count = 0; count < dq->size; count++) {
        printf("%c ", dq->data[i]);
        i = (i + 1) % dq->capacity;
    }
    printf("\n");
}

void task2() {
    int max_size;
    int c;
    printf("Введите размер дека: ");
    if (scanf("%d", &max_size) != 1 || max_size <= 0) {
        printf("Неверный размер.\n");
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }
    while ((c = getchar()) != '\n' && c != EOF);

    CharDeque dq;
    initCharDeque(&dq, max_size);

    char ch;
    int flag = 1;
    int result;

    while (1) {
        printf("Введите символ (0 для выхода): ");
        ch = getchar();
        while ((c = getchar()) != '\n' && c != EOF);

        if (ch == '0') break;

        int result = 0;
        if (flag) {
            if (!isCharDequeEmpty(&dq) && dq.data[dq.front] == ch)
                printf("Символ совпадает с левым концом.\n");
            else
                result = insertLeft(&dq, ch);
        } else {
            if (!isCharDequeEmpty(&dq) && dq.data[dq.rear] == ch)
                printf("Символ совпадает с правым концом.\n");
            else
                result = insertRight(&dq, ch);
        }
        flag = !flag;

        printf("Состояние дека: ");
        displayCharDeque(&dq);
    }
    free(dq.data);
}




void initNumQueue(NumQueue *q, int max_size) {
    q->data = (double*)malloc(max_size * sizeof(double));
    q->front = q->rear = -1;
    q->capacity = max_size;
}

int isNumQueueEmpty(NumQueue *q) {
    return q->front == -1;
}

int isNumQueueFull(NumQueue *q) {
    return (q->rear + 1) % q->capacity == q->front;
}

void enqueueNum(NumQueue *q, double num) {
    if (isNumQueueFull(q)) return;
    if (isNumQueueEmpty(q)) q->front = 0;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = num;
}

double dequeueNum(NumQueue *q) {
    if (isNumQueueEmpty(q)) return 0;
    double num = q->data[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % q->capacity;
    return num;
}

void displayNumQueue(NumQueue *q) {
    if (isNumQueueEmpty(q)) {
        printf("Очередь пуста.\n");
        return;
    }
    int i = q->front;
    do {
        printf("%.2f ", q->data[i]);
        i = (i + 1) % q->capacity;
    } while (i != (q->rear + 1) % q->capacity);
    printf("\n");
}

void freeNumQueue(NumQueue *q) {
    free(q->data);
}

void task3() {
    char input[1000];
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    NumQueue q;
    initNumQueue(&q, 100);

    char *ptr = input;
    while (*ptr) {
        if (isdigit(*ptr) || (*ptr == '.' && isdigit(*(ptr+1))) ||
            ((*ptr == '+' || *ptr == '-') && isdigit(*(ptr+1)))) {
            char *end;
            double num = strtod(ptr, &end);
            if (!isNumQueueFull(&q)) enqueueNum(&q, num);
            ptr = end;
        } else ptr++;
    }

    printf("Очередь чисел: ");
    displayNumQueue(&q);

    double sum = 0;
    while (!isNumQueueEmpty(&q)) sum += dequeueNum(&q);
    printf("Сумма чисел: %.2f\n", sum);

    freeNumQueue(&q);
}