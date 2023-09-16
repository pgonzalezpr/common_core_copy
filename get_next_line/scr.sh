#!/bin/bash

# Loop through each .c file in the current directory
for file in *.c; do
  # Check if the file exists and is a regular file
  if [ -f "$file" ]; then
    # Open the file in Vim and run the Stdheader command
    vim -c "Stdheader" "$file" -c ":x" "file"
    # You can add more Vim commands if needed by separating them with -c
  fi
done

