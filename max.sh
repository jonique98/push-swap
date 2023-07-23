CNT=100
LIMIT=700
INDEX=0
ITER=10000
NUM_OVER=0
MAX=$LIMIT
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`./a.out $ARG`
int_result=$NUM

while [ $INDEX -lt $ITER ]
int_result=$NUM
do
echo "$INDEX	:	$int_result"
if [[ $int_result -eq $TARGET_VALUE ]]; then
NUM_OVER=`expr $NUM_OVER + 1`
fi
if [ $int_result -gt $MAX ]; then
MAX=$int_result
fi
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`./a.out $ARG`
INDEX=`expr $INDEX + 1`
echo "$NUM_OVER overred operations for $ITER times"
if [ $NUM_OVER -gt 0 ]; then
echo "Biggest operation number : $MAX"
echo "fix it!!!!!!!!!!"
fi
