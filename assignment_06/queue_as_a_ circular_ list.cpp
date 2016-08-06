//Write a program to implement queue as a circular list with comments on each line.
#include<stdio.h>
#include<stdlib.h>
typedef struct cqueue
{
 int info;
 struct cqueue *next;
}node;
