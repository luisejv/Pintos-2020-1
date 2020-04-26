cd ../threads
make clean
make all
cd ../userprog
make clean
make all 
cd build
make check





#pintos -v -k -T 60 --qemu  --filesys-size=2 -p tests/userprog/args-none -a args-none -- -q  -f run args-none < /dev/null 2> tests/userprog/args-none.errors > tests/userprog/args-none.output
#perl -I../.. ../../tests/userprog/args-none.ck tests/userprog/args-none tests/userprog/args-none.result





#pintos -p tests/userprog/args-none -a args-signle -- -q

#pintos -v -k -T 60 --qemu  --filesys-size=2 -p tests/userprog/args-single -a args-single -- -q  -f run 'args-single onearg' < /dev/null 2> tests/userprog/args-single.errors > tests/userprog/args-single.output
#perl -I../.. ../../tests/userprog/args-single.ck tests/userprog/args-single tests/userprog/args-single.result
#pintos-mkdisk filesys.dsk --filesys-size=2
#pintos -f -q
#pintos -q run 'args-none'
#cd tests/userprog
#vim *.output
#make check
