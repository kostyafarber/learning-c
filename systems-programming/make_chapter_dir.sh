if [[ -z "$1" ]]
    then
        echo "usage: $0 chapter_num"
        exit 1;
fi;

chapter_num=$1
chapter_dir=chapter-$chapter_num

mkdir $chapter_dir
mkdir $chapter_dir/src
mkdir $chapter_dir/build
cp Makefile $chapter_dir/build
