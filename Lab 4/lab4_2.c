#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct node *addFront(struct node *head,int v) {
  if (head == NULL) {
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    newNode->value = v;
    newNode->next = NULL;
    return newNode;
  }
  else {
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    newNode->value = v;
    newNode->next = head;
    return newNode;
  }
}

struct node *removeFromFront(struct node *head) {
  if (head == NULL) {
    return NULL;
  }
  else {
    head = head->next;
    return head;
  }
}

void printElements(struct node *head) {
  struct node *aux;
  aux = head;
  while(aux != NULL) {
    printf("%d\n",aux->value);
    aux = aux->next;
  }
}

int main(void)
{

  struct node *head = NULL;

  head = addFront(head,5);
  head = addFront(head,4);
  head = addFront(head,3);
  head = addFront(head,2);
  head = addFront(head,1);

  printElements(head);
  
  while(head != NULL) {
    printf("----\n");
    head = removeFromFront(head);
    printElements(head);
  }

  return 0;
}

