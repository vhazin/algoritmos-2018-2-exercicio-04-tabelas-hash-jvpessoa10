#include <stdio.h>
#include <stdlib.h>
typedef struct List_Item{
    struct List_Item * next;
    int value;
}ListItem;

typedef struct  {
    ListItem * start;
    ListItem * top;
    int total;  
}List;

int getHash(int value, int M){
  return value%M;
}

void appendList(List * lista, int value){
    
    ListItem  * new = (ListItem *)malloc(sizeof(ListItem));
    new->value = value;
    new -> next = NULL;
    

    if(lista->start == NULL){
        lista -> start = new;
        lista -> top = new;
        return;
    }

    lista->top->next = new;
    lista->top = new;

        
}

int main(void) {

  int N,M,C;
  scanf("%d",&N);

  while(N--){
    scanf("%d %d",&M,&C);
    List * tabela[M];

    for(int i = 0; i < M;i++){
      tabela[i] = malloc(sizeof(List));
    }
    
    while(C--){
      int value;
      scanf("%d",&value);
      appendList(tabela[getHash(value,M)],value);
      
    }

    for(int i = 0; i<M;i++){
      ListItem * index = malloc(sizeof(index));
      index = tabela[i] -> start;

      while(index->next != NULL){
        printf("%d",index->value);
        index = index->next;
      }

    }
  }

}