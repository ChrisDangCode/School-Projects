#!/bin/bash

trap "trap - SIGTERM && kill -- -$$" SIGINT SIGTERM EXIT

# defualt poort is 9001
python3 dangx225_server.py -p 9002 &

sleep 3

# firefox -new-window "localhost:9002/calendar.html"&
curl -i -H "Accept: text/html" http://localhost:9002/calendar.html


read -n1 -r -p "Press space to continue..." key