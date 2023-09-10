#!/bin/bash
#enter input encoding here
FROM_ENCODING="ISO-8859-1"
#output encoding(UTF-8)
TO_ENCODING="UTF-8"
#convert
CONVERT="iconv -f $FROM_ENCODING -t $TO_ENCODING"
#loop to convert multiple files 
for  file in *.h; do
     $CONVERT   "$file"   -o  "${file%.h}.utf8.converted"
     mv -f "${file%.h}.utf8.converted" "$file"
done
exit 0

