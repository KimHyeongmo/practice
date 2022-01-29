# include <stdio.h>
# include <stdlib.h>

struct soldier_inform{
	int size;
	int kill;
};


struct soldier_inform * sorted;

void merge(struct soldier_inform * list, int left, int mid, int right){
  int i, j, k, l;
  
  i = left;
  j = mid+1;
  k = left;

	int tempt;
	
  while(i<=mid && j<=right){
    if(list[i].size<=list[j].size)
    {
      sorted[k] = list[i];
			k++;
      i++;
    }
    else
    {
      list[j].kill += mid + 1 - i;
      sorted[k] = list[j];
      k++;
      j++;
    }
  }

  
  if(i>mid){
    for(l=j; l<=right; l++)
    {
      sorted[k] = list[l];
      k++;
    }
  }
  
  else{
    for(l=i; l<=mid; l++)
    {
      sorted[k] = list[l];
      k++;
    }
  }

  for(l=left; l<=right; l++){
    list[l] = sorted[l];
    }
}


void mergesort(struct soldier_inform * list, int left, int right){
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
  struct soldier_inform * time;
  fscanf(stdin,"%d",&soldier_number);
	
	time = (struct soldier_inform *)malloc(sizeof(struct soldier_inform)*soldier_number);
	sorted = (struct soldier_inform *)malloc(sizeof(struct soldier_inform)*soldier_number);

	for(int i = 0; i < soldier_number; i++)
	{
		fscanf(stdin,"%d",&time[i].size);
    time[i].kill = 0;
    sorted[i].size = 0;
    sorted[i].kill = 0;
	}

	mergesort(time, 0, soldier_number-1);	

  
  for(int i = 0; i < soldier_number; i++)
  {
		//printf("size : %d / kill : %d\n",time[i].size,origin[i]);
    printf("kill :%d / size :%d\n",time[i].kill,time[i].size);
  }
	
}