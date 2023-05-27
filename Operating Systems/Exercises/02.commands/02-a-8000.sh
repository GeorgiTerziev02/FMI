#!/bin/bash

find /etc/ -type f -perm /a+r -exec cp {} ~/myetc -r -p \;   