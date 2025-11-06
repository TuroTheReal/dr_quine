#!/bin/bash

echo "COLLEEN"
./Colleen.py > tmp_colleen
diff tmp_colleen Colleen.py
echo ""

echo "GRACE"
./Grace.py
diff Grace.py Grace_kid.py
echo ""

echo "SULLY"
mkdir -p tmp/
cd tmp
../Sully.py
ls -l
diff ../Sully.py Sully_5.py
