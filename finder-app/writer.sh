#!/bin/bash
if [ $# -eq 2 ]
    then
    writefile="$1"
    writestr="$2"
    if [ -d writefile ]
        then
        echo "$writestr" > "$writefile"
    else
        mkdir -p "$(dirname $writefile)" && touch "$writefile"
        echo "$writestr" > "$writefile"
    fi
else
    echo "More or less args are passed"
    exit 1
fi

