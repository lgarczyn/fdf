make
for f in test_maps/*.fdf
do
./fdf "$f" 1000 5 1 &
done
