# Base test cases
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

# Bonus test cases

compare_outputs "infile.txt" "grep 'Lorem'" "cut -f2 -d ' '" "sort" "sorted_words.txt"
compare_outputs "infile.txt" "cat" "grep 'Sed'" "sed 's/Sed/SED/g'" "sed_output.txt"
compare_outputs "infile.txt" "cut -f1 -d ' '" "sort" "uniq" "unique_words.txt"
compare_outputs "infile.txt" "grep 'ipsum'" "sed 's/ipsum/IPSUM/g'" "grep 'IPSUM'" "sort" "uppercase_sorted.txt"
compare_outputs "infile.txt" "tr 'a-z' 'A-Z'" "sort" "uniq" "wc -l" "word_count.txt"
compare_outputs "infile.txt" "grep 'Lorem'" "sed 's/Lorem/IPSUM/g'" "grep 'IPSUM'" "cut -d ' ' -f2" "sort" "uniq" "unique_second_words.txt"
compare_outputs "infile.txt" "grep 'Sed'" "sed 's/Sed/SED/g'" "grep 'SED'" "cut -d ' ' -f3" "sort" "uniq" "wc -l" "count_of_unique_third_words.txt"




