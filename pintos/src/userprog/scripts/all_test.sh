cd ../../threads
make clean
make all
cd ../userprog
make clean
make all 
cd build
make check
cp results ../scripts
cp results ../../../../
cd ../../../../
mv results results_userprog.txt