#!/bin/bash
for filename in ./map/bad/*; do
    #for ((i=0; i<=3; i++)); do
        ./cube "$filename"
    #done
done

