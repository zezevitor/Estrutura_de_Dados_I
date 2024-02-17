#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *next;
} Node;

void insertAsHead(Node **list, int val) {

  Node *new = malloc(sizeof(Node));

  if (new) {
    new->value = val; 
    new->next = *list;
    *list = new;
  } else
    printf("Memoria mal alocada."); 

};

void insertAsTail(Node **list, int val) {

  Node *new = malloc(sizeof(Node));

  if (new) {
    new->value = val;
    new->next = NULL;     // aponta para NULL

    // primeiro?
    if (*list == NULL) 
      *list = new;        // único da lista
    else {
      Node *aux = *list;  // auxiliar percorre a lista

      // percorre a lista até o último
      while (aux->next != NULL) {
        aux = aux->next;
      } 

      aux->next = new;    // chego no final, insere o novo elemento
    }

  } else
    printf("Memoria mal alocada.");

};

void insertInMiddle(Node **list, int val, int prev) {
  Node *aux, *new = malloc(sizeof(Node));

  if (new) {
    new->value = val;

    // primeiro?
    if(*list == NULL) { 
      new->next = NULL;
      *list = new;      // único da lista
    } else {
      aux = *list;      // aux aponta para o início da lista

      // enquanto não chegar no final ou não encontrar a posição
      while (aux->value != prev && aux->next != NULL) { 
        aux = aux->next;
      }

      // após encontrar a posição, insere o novo elemento
      new->next = aux->next; // next do novo aponta para o next do aux
      aux->next = new;       // novo se torna next do aux
    }

  } else
    printf("Memoria mal alocada.");

}

void printList(Node *list) {

  printf("\n\n\tLista: ");

  // segue até chegar no final da lista
  while (list) {
    printf("%d ", list->value);
    list = list->next;
  }
};

void findInList(Node *list, int val) {
  int i = 1;
  int found = 0;

  // segue até chegar no final da lista
  while (list) {

    // encontrou o valor?
    if (list->value == val) {
      printf("\n\n\tValor %d é o %d° na lista.", val, i);
      found = 1;
    }

    list = list->next;
    i++;
  }

  //se não encontrar
  if (!found) {
    printf("\n\n\tValor %d não encontrado.", val);
  }
}

int main(void) {
  Node *list = NULL;

  insertAsHead(&list, 2);
  printList(list);

  insertAsHead(&list, 1);
  printList(list);

  insertAsTail(&list, 4);
  printList(list);

  insertInMiddle(&list, 3, 2);
  printList(list);

  findInList(list, 3);
  findInList(list, 5);

  return 0;
}
