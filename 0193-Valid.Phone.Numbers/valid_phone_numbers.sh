##############################################################################
#
# valid_phone_numbers.sh
#   Given a text file `file.txt` that contains list of phone numbers
#   (one per line), write a one line bash script to print all valid
#   phone numbers.
#
#   You may assume that a valid phone number must appear in one of the
#   following two formats: `(xxx) xxx-xxxx` or `xxx-xxx-xxxx`.
#   (x means a digit)
#
#   You may also assume each line in the text file must not contain
#   leading or trailing white spaces.
#
##############################################################################

# Solution 1
sed -nr '/^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$/p' file.txt

# Solution 2 - use perl regex expression
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
