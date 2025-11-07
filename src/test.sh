#!/bin/bash

make

echo "COLLEEN"
./Colleen > tmp_colleen
diff tmp_colleen Colleen.c
rm -f tmp_colleen
echo ""

echo "GRACE"
rm -f Grace_kid.c
./Grace
diff Grace.c Grace_kid.c
echo ""

echo "SULLY"
mkdir -p tmp
cp Sully tmp/
cd tmp
./Sully
ls -l Sully*
diff ../Sully.c Sully_5.c
cd ..
rm -rf tmp

make fclean