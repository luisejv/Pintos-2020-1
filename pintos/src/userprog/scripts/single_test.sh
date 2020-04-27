cd ../../threads
make clean
make all
cd ../userprog
make clean
make all 
cd build

pintos -v -k -T 60 --qemu  --filesys-size=2 -p tests/userprog/args-many -a args-many -- -q  -f run 'args-many a b c d e f g h i j k l m n o p q r s t u v' < /dev/null 2> tests/userprog/args-many.errors > tests/userprog/args-many.output
perl -I../.. ../../tests/userprog/args-many.ck tests/userprog/args-many tests/userprog/args-many.result

