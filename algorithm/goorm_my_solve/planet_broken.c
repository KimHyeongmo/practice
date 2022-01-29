# include <stdio.h>
# include <stdlib.h>

int *sorted;
int *death;
int *sorted_death;
int *current_array;
int *current_sorted_array;
/*
안녕하세요! 코드 보려고 들어왔는데 들어와 계시네요!

아까 코드 잠깐 살펴보았습니다.
*/

void merge(int list[], int left, int mid, int right){
  int i, j, k, l;
  

  i = left;
  j = mid+1;
  k = left;


  while(i<=mid && j<=right){
    if(list[i]<=list[j])
    {
      sorted[k] = list[i];
      sorted_death[k] = death[i];
      current_sorted_array[k] = current_array[i];
      k++;
      i++;
    }
    else
    {
      sorted[k] = list[j];
      sorted_death[k] = death[j] + mid + 1 - i;
      current_sorted_array[k] = current_array[j];
      k++;
      j++;
    }
  }

  
  if(i>mid){
    for(l=j; l<=right; l++)
    {
      sorted[k] = list[l];
      current_sorted_array[k] = current_array[l];
      sorted_death[k] = death[l];
      k++;
    }
  }
  
  else{
    for(l=i; l<=mid; l++)
    {
      sorted[k] = list[l];
      current_sorted_array[k] = current_array[l];
      sorted_death[k] = death[l];
      k++;
    }
  }

  for(l=left; l<=right; l++){
    list[l] = sorted[l];
    death[l] = sorted_death[l];
    current_array[l] = current_sorted_array[l];
  }
}


void mergesort(int *list, int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2;
    mergesort(list, left, mid);
    mergesort(list, mid+1, right);
    merge(list, left, mid, right);
  }
}

int main()
{
    int soldier_number;
    int * time;
    fscanf(stdin,"%lld",&soldier_number);
	
		time = (int *)malloc(sizeof(int)*soldier_number);
    sorted = (int *)malloc(sizeof(int)*soldier_number);
    death = (int *)malloc(sizeof(int)*soldier_number);
    current_array = (int *)malloc(sizeof(int)*soldier_number);
    sorted_death = (int *)malloc(sizeof(int)*soldier_number);
    current_sorted_array = (int *)malloc(sizeof(int)*soldier_number);
		
	for(int i = 0; i < soldier_number; i++)
	{
		fscanf(stdin,"%d",&time[i]);
        sorted[i] = 0;
        death[i] = 0;
        current_array[i] = i;
        current_sorted_array[i] = i;
        sorted_death[i] = 0;
	}

	mergesort(time, 0, soldier_number-1);	

  for(int i = 0; i < soldier_number; i++)
  {
  	sorted_death[current_array[i]] = death[i];
  }

  for(int i = 0; i < soldier_number; i++)
  {
		printf("%d\n",sorted_death[i]);
  }
	
	free(time);
	free(sorted);
	free(death);
	free(curre  nt_array);
	free(current_sorted_array);
	free(sorted_death);
	
}