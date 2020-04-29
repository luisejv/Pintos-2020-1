cd ../../threads
make clean
make all
cd ../userprog
make clean
make all 
cd build

pintos -v -k -T 60 --qemu  --filesys-size=2 -p tests/userprog/sc-bad-sp -a sc-bad-sp -- -q  -f run sc-bad-sp < /dev/null 2> tests/userprog/sc-bad-sp.errors > tests/userprog/sc-bad-sp.output
perl -I../.. ../../tests/userprog/sc-bad-sp.ck tests/userprog/sc-bad-sp tests/userprog/sc-bad-sp.result

