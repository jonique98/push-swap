#!/bin/bash

# 설정 값들
CNT=10
LIMIT=100000000
ITER=5
NUM_OVER=0
MAX=$LIMIT
REALMAX=0

# 반복 실행하는 함수 정의
run_a_out_and_compare() {
  for ((INDEX=0; INDEX<$ITER; INDEX++)); do
# 랜덤한 양수값들을 생성하여 저장
    ARG=$(shuf -i 1-2147483647 -n $CNT | tr "\n" " ")
#a.out 실행 및 결과값 저장 (표준 출력으로 출력되는 값을 변수에 저장)
    NUM=$(./a.out $ARG)
#결과값 출력
    echo "$INDEX : $NUM"
#결과값을 정수로 변환하여 비교
    if [[ $NUM -ge $LIMIT ]]; thendsasfdfasfsdfasdsdfsdsdsfsddsd
      NUM_OVER=$((NUM_OVER + 1))
    fi
    if [[ $NUM -gt $MAX ]]; then
      MAX=$NUM
    fi
	if [[ $NUM -gt $REALMAX ]]; then
		REALMAX=$NUM
	fi
  done
}

# main 함수 실행

run_a_out_and_compare

echo "$NUM_OVER overred operations for $ITER times"
echo "최대값 : $REALMAX"
if [[ $NUM_OVER -gt 0 ]]; then
  echo "Biggest operation number: $MAX"
  echo "fix it!!!!!!!!!!"
fi

