#!/bin/bash

JC_MAIL="jcarra <jcarra@student.42.fr>"
NS_MAIL="nsikora <marvin@42.fr>       "
JC_NAME="jcarra "
JC_NAM2="nathan "
NS_NAME="nsikora"

n=1
if [ $n -eq 0 ]
then
    sed -i '' -E "s/$JC_MAIL/$NS_MAIL/g" $(find . -name "*.[ch]")
    sed -i '' -E "s/$JC_NAME/$NS_NAME/g" $(find . -name "*.[ch]")
    sed -i '' -E "s/$JC_NAM2/$NS_NAME/g" $(find . -name "*.[ch]")
    sed -i '' -E "s/$JC_MAIL/$NS_MAIL/g" $(find . -name "Makefile")
    sed -i '' -E "s/$JC_NAME/$NS_NAME/g" $(find . -name "Makefile")
    sed -i '' -E "s/$JC_NAM2/$NS_NAME/g" $(find . -name "Makefile")
    echo "nsikora" > author
    sed -i '' -E 's/(n=)0/\11/' $0
    echo "$JC_NAME -> $NS_NAME"
else
    sed -i '' -E "s/$NS_MAIL/$JC_MAIL/g" $(find . -name "*.[ch]")
    sed -i '' -E "s/$NS_NAME/$JC_NAME/g" $(find . -name "*.[ch]")
    sed -i '' -E "s/$NS_MAIL/$JC_MAIL/g" $(find . -name "Makefile")
    sed -i '' -E "s/$NS_NAME/$JC_NAME/g" $(find . -name "Makefile")
    echo "jcarra" > author
    sed -i '' -E 's/(n=)1/\10/' $0
	echo "$NS_NAME -> $JC_NAME"
fi
rm -f $(find . -name "*.[ch]E*")
rm -f $(find . -name "MakefileE*")