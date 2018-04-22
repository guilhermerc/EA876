for file in tests/belem/*; do
	cat "$file" | ./main | java Main
done
