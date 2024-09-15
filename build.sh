#!/bin/sh

set -xe

gcc -Wall -Wextra -lm -o main main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
