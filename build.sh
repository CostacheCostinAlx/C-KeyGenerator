#!/bin/bash

if ! gcc main.c -o keygen -lraylib -lGL -lm -lpthread -ldl -lrt -lX11; then
    echo "Error compiling."
fi