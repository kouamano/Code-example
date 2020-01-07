#!/bin/bash
for file in *.compile; do echo "-- ${file} --"; bash $file; done
