#!/bin/bash

find /tmp -type f -group $(id -g) -perm /o=w,g=w