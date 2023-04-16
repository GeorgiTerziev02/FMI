#!/bin/bash

mkdir -p ~/practice/01 ~/dir1
touch ~/practice/01/f{1..3}   # touch f1 f2 f3
cp ~/practice/01/f{1...3} ~/dir1