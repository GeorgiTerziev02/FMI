#!/bin/bash

rm -i $(find ~ -type f -newer ~/practice/01/f3)

# alternatives
# exec
find ~ -type f -newer ~/practice/01/f3 -exec rm -i {} \;

# delete
find ~ -type f -newer ~/practice/01/f3 -delete
