#!/bin/bash

set -e

arduino-cli compile --fqbn arduino:avr:nano:cpu=atmega328 main
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:nano:cpu=atmega328 main

minicom -D /dev/ttyUSB0
