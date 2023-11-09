# MANDATORY PART

# Infile error

./pipex nonexistingfile.txt "cat" "head -n 2" outfile.txt
./pipex unreadablefile.txt "cat" "ls -l" outfile.txt

# Outfile error

./pipex infile.txt "cat" "head -n 2" unwriteablefile.txt

# Non-existing command

./pipex infile.txt "hellocmd" "wc -l" outfile.txt
./pipex infile.txt "cat" "hellocmd" outfile.txt

# Illegal option

./pipex infile.txt "cat" "wc -z" outfile.txt
./pipex infile.txt "cat -q" "wc -l" outfile.txt
./pipex infile.txt "cat -q" "ls -l" outfile.txt 

# Absolute path

./pipex infile.txt "/usr/bin/cat" "wc -l" outfile.txt

# Combined

./pipex unreadablefile.txt "cat" "wc -l" unwriteablefile.txt
./pipex infile.txt "hellocmd" "wc -z" outfile.txt
./pipex infile.txt "cat" "ls -z" unwriteablefile.txt    
./pipex nonexistingfile.txt "cat" "wc -z" outfile.txt
./pipex unreadablefile.txt "hellocmd" "wc -z" unwriteablefile.txt

# Test cases valid input 

compare_outputs "infile.txt" "head -n 5" "cat" "outfile.txt"
compare_outputs "infile.txt" "tail -n 10" "sort" "sorted_tail.txt"
compare_outputs "infile.txt" "grep 'ipsum'" "wc -l" "word_count.txt"
compare_outputs "infile.txt" "sed 's/Lorem/IPSUM/g'" "grep 'IPSUM'" "uppercase_ ipsum.txt"
compare_outputs "infile.txt" "sort" "uniq" "unique_lines.txt"
compare_outputs "infile.txt" "tr 'a-z' 'A-Z'" "sort" "uppercase_sorted.txt"
compare_outputs "infile.txt" "cut -f1 -d ' '" "sort -u" "unique_words.txt"
compare_outputs "infile.txt" "grep -v 'Sed'" "wc -l" "line_count.txt"
compare_outputs "infile.txt" "cut -f1 -d ' '" "uniq -c" "word_frequency.txt"
compare_outputs "infile.txt" "grep 'arcu'" "sed 's/arcu/ARCUS/g'" "replace_arcu.txt"


# BONUS PART

# Test cases valid input (BONUS)

compare_outputs "infile.txt" "cut -f1 -d ' '" "sort" "uniq" "unique_words.txt"
compare_outputs "infile.txt" "grep 'ipsum'" "sed 's/ipsum/IPSUM/g'" "grep 'IPSUM'" "sort" "uppercase_sorted.txt"
compare_outputs "infile.txt" "tr 'a-z' 'A-Z'" "sort" "uniq" "wc -l" "word_count.txt"
compare_outputs "infile.txt" "grep 'Lorem'" "sed 's/Lorem/IPSUM/g'" "grep 'IPSUM'" "cut -d' ' -f2" "sort" "uniq" "unique_second_words.txt"
compare_outputs "infile.txt" "grep 'Sed'" "sed 's/Sed/SED/g'" "grep 'SED'" "cut -d' ' -f3" "sort" "uniq" "wc -l" "count_of_unique_third_words.txt"

