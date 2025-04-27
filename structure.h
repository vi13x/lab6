typedef struct {
    char *data;
    int front;
    int rear;
    int capacity;
} CharQueue;

typedef struct {
    char *data;
    int front;
    int rear;
    int capacity;
    int size;
} CharDeque;

typedef struct {
    double *data;
    int front;
    int rear;
    int capacity;
} NumQueue;