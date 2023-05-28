#!/bin/bash

cp $(find /etc/ -type f -exec wc -c {} \; | sort -t ' ' -k1 -n | head -n 1 | cut -d ' ' -f 2) ~