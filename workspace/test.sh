echo
echo "Executando na pasta 'belem'"
echo ------------------------------
for file in tests/belem/*; do
	cat "$file" | ./main | java Main
done

echo
echo "Executando na pasta 'corumba'"
echo ------------------------------
for file in tests/corumba/*; do
	cat "$file" | ./main | java Main
done
