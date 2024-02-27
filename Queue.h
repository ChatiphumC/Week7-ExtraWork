typedef struct {
	 NodePtr headPtr,tailPtr;
	 int size;
}Queue;

void enqueue_struct(Queue* q, int order_n, int amount){
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node){ 
  new_node->order_number = order_n;
  new_node->amount = amount;
  new_node->nextPtr = NULL;
  if(q->headPtr == NULL)
  {
    q->headPtr = new_node;
  }
  else
  {
    q->tailPtr->nextPtr = new_node;
  }
  q->tailPtr = new_node;
  printf("My order is %d\n", order_n);
 }
 q->size += 1;
}


int dequeue_struct(Queue *q){
   NodePtr tempPtr=q->headPtr;
   char order_name[30];
   int price = 0;
   int value = 0;
   int pay = 0;
   int food = 0;
   int static count = 1;

   if(tempPtr){
    switch(tempPtr->order_number)
    {
      case 1: value = 100;
              food = 1;
              strcpy(order_name, "Ramen"); 
              break;
      case 2: value = 20;
              food = 1;
              strcpy(order_name, "Somtum");
              break;
      case 3: value = 50;
              food = 1;
              strcpy(order_name, "Fried Chicken");
              break;
      default: 
              value = 1;
              food = 0;
              printf("Customer No. : %d\n", count);
              printf("No Food!!\n");

    }
    if(food == 1)
    {
      price = value*tempPtr->amount;
      printf("Customer No. : %d\n", count);
      printf("%s\n", order_name);
      printf("You have to pay %d\n", price);
      while(1)
      {
        printf("Cash : ");
        scanf("%d", &pay);
        if(pay == price)
        {
          printf("Thank You\n");
          break;
        }
        else if(pay > price)
        {
          printf("Thank You\n");
          printf("Change is %d\n", pay - price);
          break;
        }
      }
    }

   q->headPtr = q->headPtr->nextPtr;
   free(tempPtr);
   q->size -= 1;
   count += 1;
   return value;
   }
   return 0;
}

