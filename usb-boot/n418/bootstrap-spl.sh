#!/bin/sh

IP="192.168.2.3"
PORT="8000"
KERNEL_FILE="zImage-root"

wget "${IP}:${PORT}/${KERNEL_FILE}"
kexec -l "${KERNEL_FILE}"
kexec -e
