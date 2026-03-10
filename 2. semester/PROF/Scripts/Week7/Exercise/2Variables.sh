#!/bin/bash

echo "give me 2 numbers"

read A
read B

echo "the sum is $((A+B))"
echo "the difference is $((A>B?A-B:B-A))"
echo "the product is $((A*B))"
echo "the quotient is $((A/B))"