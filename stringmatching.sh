if [ "$1" == "" ]; then
    echo "Usage: $(basename $0) text_filename pattern"
    exit 1
fi

text="$1"
pattern="$2"
algorithm=("naive" "automaton" "kmp")
folder="results"

for i in "${algorithm[@]}"; do
    filename_out=$folder/sm_$text'_'$pattern'_'${i}.dat
    build/./stringmatching $text $pattern ${i} $filename_out
done