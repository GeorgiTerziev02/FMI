#!/bin/bash

find /bin/ -type f -perm 777

# alternative
find /bin/ -type f -perm ugo=rwx