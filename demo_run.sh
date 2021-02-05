#!/bin/sh

# build all
make clean all

echo "\n\n\n"

# Test cgrep
echo Testing ./cgrep
echo ------------
cat > ./.tmpfile << EOF
Hello world
Welcome to California
Goodbye
Big sky
Nice job
Blue sky
Hey Joe
EOF
cat ./.tmpfile | ./cgrep 2 sky
rm -rf ./.tmpfile
echo ------------

echo "\n\n\n"

# Test words
echo Testing ./words
echo ------------
echo Richard of York gave battle in vain | ./words
echo ------------

echo "\n\n\n"

# Test btree
echo Testing btree
echo ------------
./btree
echo ------------

