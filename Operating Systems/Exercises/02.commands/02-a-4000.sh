#!/bin/bash


touch ~/permissions.txt
chmod u=r,g=wx,o=rx ~/permissions.txt
#     100 011  101
chmod 435 ~/permissions.txt