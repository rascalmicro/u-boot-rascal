#!/usr/bin/env python

import csv, os, subprocess, sys, time

start = time.time()

# Load the data into memory

s = []
with open('./hash-mac-serial-0001-1000.csv', 'rb') as f:
    serials = csv.reader(f)
    for row in serials:
        s.append([row[0], row[1], row[2]])

os.environ['CROSS_COMPILE'] = 'arm-linux-'
os.environ['PATH'] = os.environ['PATH'] + ':/opt/eldk/usr/bin:/opt/eldk/bin:/opt/cs/bin'

# Build the binaries in the range specified on the command line

for i in range(int(sys.argv[1]), int(sys.argv[2]) + 1):
    pwhash = s[i][0]
    mac = s[i][1]
    serial = s[i][2]
    hostname = 'rascal' + serial[2:6].lstrip('0')

    print 'Building binary with these parameters: hostname: {0}, mac: {1}, hash: {2}'.format(hostname, mac, pwhash) 
    bootargs ='\'#define CONFIG_RASCAL_BOOTARGS "console=ttyS0,115200 ip=::::{0}:: pwhash={1}"\''.format(hostname, pwhash)
    ethaddr = '\'#define CONFIG_RASCAL_ETHADDR {0}\''.format(mac)

    commands = [
        'cp include/configs/rascal.h rascal.h.orig',
        'echo ' + bootargs + ' >> include/configs/rascal.h',
        'echo ' + ethaddr + ' >> include/configs/rascal.h',
        # 'touch u-boot.bin'
        'make distclean; make rascal_config; make all',
        'cp u-boot.bin ~/u-boot-{0}.bin'.format(serial.lower()),
        'cp rascal.h.orig include/configs/rascal.h',
    ]
    for cmd in commands:
        print(cmd)
        subprocess.call(cmd, shell=True)

# Print some stats

stop = time.time()
total = int(sys.argv[2]) + 1 - int(sys.argv[1])

print 'Built {0} U-boot binaries at a pace of {1} seconds per binary'.format(total , (stop - start)/total)
