#!/bin/bash

echo "give me 2 numbers"

#læs input fra brugeren
read A
read B

#meget af dether giver sig selv
echo "the sum is $((A+B))"
echo "the difference is $((A>B?A-B:B-A))" #for at få forskellen i positiv, vælges den der skal subtrakteres med ud fra hvilken der er mindst
echo "the product is $((A*B))"
echo "the quotient is $((A/B))"