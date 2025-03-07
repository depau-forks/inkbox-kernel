#!/bin/sh

IP="192.168.2.1"

nbd-client "${IP}" 10809 /dev/nbd0
nbd-client "${IP}" 10810 /dev/nbd1
nbd-client "${IP}" 10811 /dev/nbd2
nbd-client "${IP}" 10812 /dev/nbd3
nbd-client "${IP}" 10813 /dev/nbd4

ln -s /dev/nbd0 /dev/mmcblk0
ln -s /dev/nbd1 /dev/mmcblk0p1
ln -s /dev/nbd2 /dev/mmcblk0p2
ln -s /dev/nbd3 /dev/mmcblk0p3
ln -s /dev/nbd4 /dev/mmcblk0p4
