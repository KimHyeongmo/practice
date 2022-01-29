# include <stdio.h>
# include <stdlib.h>
int *time; // 추가적인 공간이 필요
int *sorted;

// i: 정렬된 왼쪽 리스트에 대한 인덱스
// j: 정렬된 오른쪽 리스트에 대한 인덱스
// k: 정렬될 리스트에 대한 인덱스
/* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */
void merge(int list[], int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  /* 분할 정렬된 list의 합병 */
  while(i<=mid && j<=right){
    if(list[i]<=list[j])
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }

  // 남아 있는 값들을 일괄 복사
  if(i>mid){
    for(l=j; l<=right; l++)
      sorted[k++] = list[l];
  }
  // 남아 있는 값들을 일괄 복사
  else{
    for(l=i; l<=mid; l++)
      sorted[k++] = list[l];
  }

  // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}

// 합병 정렬
void mergesort(int *list, int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
    mergesort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
    mergesort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
  }
}

int main()
{
    int N;
    
    fscanf(stdin,"%d",&N);
	time = (int *)malloc(sizeof(int)*N);
    sorted = (int *)malloc(sizeof(int)*N);
 
	for(int i = 0; i < N; i++)
	{
		fscanf(stdin,"%d",&time[i]);
        sorted[i] = 0;
	}

	mergesort(time, 0, N-1);	

    for(int i = 0; i < N; i++)
    {
        printf("%d\n",sorted[i]);
    }
}

  // 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
  
  // 정렬 결과 출력


//https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html