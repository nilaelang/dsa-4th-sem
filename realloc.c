#include<stdio.h>
#include<stdlib.h>

int main(){
  int num_integers,i;
  printf("Enter the number of integers : ");
  scanf("%d", &num_integers);
  int*ptr=(int*)malloc(num_integers*sizeof(int));
  if(ptr==NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }
  for(i=0;i<num_integers;i++) {
    printf("Enter an integer for element %d: ",i+1);
    scanf("%d",ptr+i);
  }

  printf("\nThe entered integers are: ");
  for(i=0;i<num_integers;i++) {
    printf(" %d ",*(ptr+i));
  }
  printf("\n");
  
  int new_num_integers;
  printf("Enter the new number of integers : ");
  scanf("%d", &new_num_integers);
  int*ptr_new=(int*)realloc(ptr,new_num_integers*sizeof(int));
  if(ptr_new==NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }
  for(i=0;i<new_num_integers;i++) {
    printf("Enter an integer for element %d: ",i+1);
    scanf("%d",ptr_new+i);
  }

  printf("\nThe newly entered integers are: ");
  for(i=0;i<new_num_integers;i++) {
    printf(" %d ",*(ptr+i));
  }
  printf("\n");
  
  return 0;
}

