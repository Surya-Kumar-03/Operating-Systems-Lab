for i in *
do
echo Before Converting to uppercase the filename is
echo $i
j=`echo $i | tr '[a-z]' '[A-Z]'`
echo After Converting to uppercase the filename is
echo $j
mv $i $j
done