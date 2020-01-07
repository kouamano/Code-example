#!/bin/bash
echo === start ===
for file in *.compile; do echo "-- ${file} --"; bash $file; done
echo === finish ===
