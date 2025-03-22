#!/bin/sh

sudo chown "${USER}:${USER}" /dev/loop${1}*
nbdkit file /dev/loop${1} -p 10809
nbdkit file /dev/loop${1}p1 -p 10810
nbdkit file /dev/loop${1}p2 -p 10811
nbdkit file /dev/loop${1}p3 -p 10812
nbdkit file /dev/loop${1}p4 -p 10813
