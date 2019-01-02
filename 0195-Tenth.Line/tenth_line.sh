##############################################################################
#
# tenth_line.sh
#   Given a text file `file.txt`, print just the 10th line of the file.
#
##############################################################################

# using sed
sed -n '10p' file.txt

# using awk
awk 'FNR == 10 {print}' file.txt
# or
awk 'NR == 10' file.txt

# using head & tail
tail -n+10 file.txt | head -1
