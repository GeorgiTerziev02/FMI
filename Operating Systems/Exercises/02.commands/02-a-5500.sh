#!/bin/bash

find /etc -type d -mindepth 1 -maxdepth 1 | tail -n 10 > ~/test.txt