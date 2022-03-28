#!/bin/bash

rm out.txt
gcc fileIO.c utils.c -o fileIO
./fileIO
