# nproc --all

for file_ in imgs_test/*.jpg; do
        echo
	echo ----------------------------------------
        ./main "$file_" -s 
	echo ----------------------------------------
        ./main "$file_" -t 4
	echo ----------------------------------------
        ./main "$file_" -p 4
	echo ----------------------------------------
        echo
done
