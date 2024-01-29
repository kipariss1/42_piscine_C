TIMESTAMP=$(stat bomb.txt -c %X)
while [ $TIMESTAMP -gt 0 ]; do 
    echo $TIMESTAMP;  # (( )) are used to encapsulate mathematical operations
    TIMESTAMP=$((TIMESTAMP - 1)); 
done 