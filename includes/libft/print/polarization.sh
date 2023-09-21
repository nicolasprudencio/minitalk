#!/bin/bash
c_files=$(find . -type f -name "*.c")
for file in $c_files; do
    sed -i 's/ft_/fp_/g' "$file"
done

echo "Replacement completed."

