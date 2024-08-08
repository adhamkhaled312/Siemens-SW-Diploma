#!/bin/bash
cat /etc/passwd | cut -d: -f1,6 | while IFS=: read -r user dir; do
  echo "user $user and its directory is $dir"
done

