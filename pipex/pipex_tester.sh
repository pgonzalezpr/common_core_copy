#!/bin/bash

# Function to compare pipex output with real command output
compare_outputs() {
    local input_file="$1"
    local command1="$2"
    local command2="$3"
    local output_file="$4"
    
    # Run the real command and save the output
    real_output=$(< "$input_file" $command1 | $command2)

    # Run pipex and save the output
    ./pipex "$input_file" "$command1" "$command2" "pipex_output.txt"

    # Compare the outputs
    if diff -q "pipex_output.txt" <(echo -e "$real_output"); then
        echo "Test PASSED: '$input_file' '$command1' '$command2' '$output_file'"
    else
        echo "Test FAILED: '$input_file' '$command1' '$command2' '$output_file'"
    fi
}

# Test cases with infile.txt
compare_outputs "infile.txt" "head -n 5" "cat" "outfile.txt"
compare_outputs "infile.txt" "tail -n 10" "sort" "sorted_tail.txt"
compare_outputs "infile.txt" "grep 'ipsum'" "wc -l" "word_count.txt"
compare_outputs "infile.txt" "sed 's/Lorem/IPSUM/g'" "grep 'IPSUM'" "uppercase_ipsum.txt"
compare_outputs "infile.txt" "sort" "uniq" "unique_lines.txt"
compare_outputs "infile.txt" "tr 'a-z' 'A-Z'" "sort" "uppercase_sorted.txt"
compare_outputs "infile.txt" "cut -f1 -d ' '" "sort -u" "unique_words.txt"
compare_outputs "infile.txt" "grep -v 'Sed'" "wc -l" "line_count.txt"
compare_outputs "infile.txt" "cut -f1 -d ' '" "uniq -c" "word_frequency.txt"
compare_outputs "infile.txt" "grep 'arcu'" "sed 's/arcu/ARCUS/g'" "replace_arcu.txt"

# Clean up temporary files
rm -f "pipex_output.txt" "sorted_tail.txt" "word_count.txt" "uppercase_ipsum.txt" "unique_lines.txt" "uppercase_sorted.txt" "unique_words.txt" "line_count.txt" "word_frequency.txt" "replace_arcu.txt"



