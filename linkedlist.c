#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node * next;
};

  
void print_list(struct node * listElem) {
  if (listElem) {
    printf("%d ", listElem->val);
    print_list(listElem->next);
  }
  else printf("\n");
}

struct node * insert_front(struct node * listElem, int newVal) {
  struct node * newFirst = (struct node *) malloc( sizeof *newFirst );
  newFirst->val = newVal;
  newFirst->next = listElem;
  return newFirst;
}

struct node * free_list(struct node * listElem) {
  if (listElem) {
    free_list(listElem->next);
    free(listElem);
    listElem = NULL;
  }
  else return 0;  
  return listElem;
}

int main() {
  struct node * c = (struct node *) malloc(sizeof *c);
  c->val = 20;
  c->next = 0;
  print_list(c);
  
  struct node * b = insert_front(c, 5);
  print_list(b);
  struct node * a = insert_front(b, 1);
  print_list(a);
  
  free_list(a);
  return 0;
}







