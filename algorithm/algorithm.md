# 알고리즘 정리

## 완전탐색

### 발생 가능한 모든 경우의 수를 확인하는 방법

입력으로 주어지는 수가 작은 경우 쉽게 사용 가능하며, 일반적으로 시간이 오래 걸리는 경우가 많기 때문에 시간복잡도를 먼저 계산해 보고 완전 탐색을 구현해야 한다.

예시
* for, if사용 반복문
* 재귀함수
  ```
  int fibonachi(int n)
  {
      if(n <= 1)
      {
          return n;
      }

      return fibonachi(n-1) + fibonachi(n-2);
  }
  ```

## 탐욕(greedy) 알고리즘

### 근시안적 선택을 수행하는 알고리즘 기법

현시점에서 가장 적합하다고 생각하는 요소를 선택

최적화 문제 해결에 사용 가능

선택의 방법을 주의해야 함

어느 조건을 이용하여 최적 해를 선택했다면, 모든 단계에서 그 조건을 이용하여 해를 구해야 한다.


예시
* 거스름돈 거슬러주기
* 최소비용 신장 트리



## 투 포인터

### 정렬된 배열에서 두 개의 포인터(인덱스)를 이용하여 해당 값들과 원하는 값을 비교한 뒤 포인터를 조작하여 원하는 결과를 얻어내는 기법

이중 반복문을 이용하는 경우에 비해(O(N^2)) O(N)이라는 빠른 시간 내에 순서상을 찾을 수 있다. (비정렬 배열의 경우 O(NlogN))


예시
* 배열 내 합이 S가 되는 순서쌍 찾기
  ```
  void two_pointer()
  {
    int array[13] = {1,3,5,6,9,11,
    12,16,17,19,22,25,28};

    int count = 0;

    int S = 27;
    int l = 0;
    int r = 12;

    while(l<=r)
    {
        int sum = array[l] + array[r];
        if(sum > S)
            r--;
        else if(sum < S)
            l++;
        else
        {
            l++;
            r--;
            count++;
        }
    }

    fprintf(stdout,"%d",count);
  }
  ```



## 동적 계획법(Dynamic Programming)

### 어렵거나 큰 문제를 간단하고 작은 여러개의 문제로 나누어서 풀고 작은 문제의 답들을 이용하여 원래 문제의 답을 구하는 방식

특징
* 최적 부분 구조
  
  문제의 정답이 작은 문제에 대해서도 정답

* 부분 문제 반복
  
  문제를 여러개의 작은 문제로 나눌 수 있음

똑같은 문제를 여러 번 푸는 것을 막기 위해 **메모이제이션** 기법 사용. 이를 가장 잘 서명하는 것이 점화식(인접 항들 사이의 관계)

접근 방식
* 상향식

  가장 작은 문제부터 시작하여 큰 문제를 풀 수 있을 때까지 차례대로 문제들을 풀어나가는 방식. 주로 반복문을 이용해 구현.

* 하향식

  큰 문제를 풀 수 있는 작은 문제가 될 때까지 나눈 후, 작은 문제들을 풀어 얻은 정답들을 합쳐가며 큰 문제의 답을 구함. 주로 재귀 함수 이용


## 이분 탐색(binary search)

### 이미 정렬된 배열에서 특정 원소가 포함되어 있는지 아닌지를 빠르게 판단할 수 있는 기법

값이 포함된 것으로 예상되는 범위의 가운데 값을 확인하며 찾는 값이 있을 수 있는 곳만 탐색

O(logN) : 정렬이 이미 되어 있을 때
O(NlogN) : 정렬이 되어있지 않은 경우

이러한 경우 뿐만 아니라 어떤 문제를 풀며 답을 직접 구하기는 어렵지만, 답을 가정할 수 있고, 해당 답이 맞는지 틀린지 확인하는 문제에서 자주 사용된다.

## 분할 정복

### 전체 문제를 분할하여 풀 수 있을 만큼 작은 문제로 분할한 다음, 작은 문제를 각각 풀어 얻은 답들을 토대로 전체 문제의 답을 구하는 알고리즘

분할 정복은 동적 계획법과 비교하여, 작은 문제로 나눌 때 문제가 겹치지 않게 나눈다는 차이점을 가짐

절차
  
1. 문제나누기. 겹치지 않고, 빠진 부분 없이
2. 아직 나눌 수 있다면 1 반복
3. 나눌 수 없다면 나눠진 문제 해결
4. 해결한 문제 합치기
5. 아직 합칠 수 있다면 4 반복

예시

* 합병 정렬
* a^n 구하기

알고리즘 그 자체를 이용하기보다 다른 알고리즘과 함께 사용하는 경우가 많다. 문제 특성상 반으로 나누는 경우가 많아 일반적으로 시간 복잡도에 logN이 붙는다.

## 너비 우선 탐색(BFS(Breadth First Search))

### 그래프를 방문하거나 탐색하는 방법의 하나로, 최단거리, 최소비용과 같이 최솟값 관련 문제를 해결할 수 있다. 이 때 그래프의 가중치(시간, 비용, 거리 등)가 1이어야만 한다.

BFS는 모든 경로에 대한 동시 탐색이 가능하여 최대 경로를 몰라도 사용할 수 있다.

절차

1. 저장된 정점 중 첫 정점을 선택, 저장 정점에서 제거
2. 제거한 정점에서 해야 할 작업 진행
3. 제거한 정점과 연결된 정점 중 방문하지 않은 모든 정점 저장 (2,3의 순서는 의미 없음)
4. 저장 정점이 빌 때까지 1~3번 과정 반복
