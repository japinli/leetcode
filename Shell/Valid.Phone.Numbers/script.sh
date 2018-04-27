#!/bin/bash

# Solution 1
sed -nr '/^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$/p' file.txt

# Solution 2 - use perl regex expression
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
