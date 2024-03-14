filename=$*

rm -f output

g++ -Wall -std=c++11 -g -o output $filename

./output
rm output