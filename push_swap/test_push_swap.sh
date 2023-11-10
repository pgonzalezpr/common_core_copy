#!/bin/bash

# Check if the number of arguments is provided and is a positive integer
if [ "$#" -ne 1 ] || ! [[ "$1" =~ ^[1-9][0-9]*$ ]]; then
  echo "Usage: $0 <size_of_list>"
  exit 1
fi

size_of_list="$1"

# Function to generate a unique random number
generate_unique_random() {
  local num
  while true; do
    num=$((RANDOM % 2001 - 1000))
    if [[ ! " ${random_args[@]} " =~ " $num " ]]; then
      random_args+=("$num")
      break
    fi
  done
}

# Generate a random list of unique integers between -1000 and 1000 with the specified size
random_args=()
for ((i = 0; i < size_of_list; i++)); do
  generate_unique_random
done

# Run the push_swap executable with the random list as separate arguments
instructions=$(./push_swap "${random_args[@]}")

# Count the number of instructions
num_instructions=$(echo "$instructions" | wc -l)

# Run checker_linux with the generated instructions and the original list
checker_output=$(echo "$instructions" | ./checker_linux "${random_args[@]}")

# Print the number of instructions followed by checker_linux output
echo "$num_instructions"
echo "$checker_output"

