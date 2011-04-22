#!/usr/bin/env python

import csv, os, subprocess, sys

s = []
with open('../../hash-mac-serial-0001-1000.csv', 'rb') as f:
    serials = csv.reader(f)
    for row in serials:
        s.append([row[0], row[1], row[2]])

os.environ['CROSS_COMPILE'] = 'arm-linux-'
os.environ['PATH'] = os.environ['PATH'] + ':/opt/eldk/usr/bin:/opt/eldk/bin:/opt/cs/bin'

for i in range(int(sys.argv[1]), int(sys.argv[2]) + 1):
    pwhash = s[i][0]
    mac = s[i][1]
    serial = s[i][2]
    hostname = 'rascal' + serial[2:6].lstrip('0')

    config_text ="""#define CONFIG_RASCAL_DEFAULT_PASSWORD_HASH {0}
#define CONFIG_RASCAL_ETHADDR {1}
#define CONFIG_RASCAL_HOSTNAME {2}""".format(pwhash, mac, hostname)

    commands = [
        'env',
        'cp include/configs/rascal.h rascal.h.orig',
        'echo "' + config_text + '" >> include/configs/rascal.h',
        'make distclean; make rascal_config; make all',
        'cp u-boot.bin ../u-boot-{0}'.format(serial.lower()),
        'cp rascal.h.orig include/configs/rascal.h',
    ]
    for cmd in commands:
        print(cmd)
        subprocess.Popen(cmd, shell=True)
