#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

size_t strcspn(const char *str1, const char *str2);
void initCharQueue(CharQueue *q, int max_size);
int isCharQueueEmpty(CharQueue *q);
int isCharQueueFull(CharQueue *q);
void enqueueChar(CharQueue *q, char c);
void dequeueChar(CharQueue *q);
void displayCharQueue(CharQueue *q);
void  createQueue();

void initCharDeque(CharDeque *dq, int max_size);
int isCharDequeEmpty(CharDeque *dq);
int isCharDequeFull(CharDeque *dq);
int insertLeft(CharDeque *dq, char c);
int insertRight(CharDeque *dq, char c);
void displayCharDeque(CharDeque *dq);
void createDeck();

void initNumQueue(NumQueue *q, int max_size);
int isNumQueueEmpty(NumQueue *q);
int isNumQueueFull(NumQueue *q);
void enqueueNum(NumQueue *q, double num);
double dequeueNum(NumQueue *q);
void displayNumQueue(NumQueue *q);
void freeNumQueue(NumQueue *q);
void sumOfNumbers();
