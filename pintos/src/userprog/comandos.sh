make clean
make all 
cd build
#pintos --gdb -v -k -T 60 --qemu  --filesys-size=2 -p tests/userprog/args-none -a args-none -- -q  -f run args-none < /dev/null 2
pintos -v -k -T 60 --qemu  --filesys-size=2 -p tests/userprog/args-single -a args-single -- -q  -f run 'args-single onearg' < /dev/null 2> tests/userprog/args-single.errors > tests/userprog/args-single.output
cd tests/userprog
vim *.output
