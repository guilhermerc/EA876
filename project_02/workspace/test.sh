for dir_ in tests/*; do
	echo "Executando na pasta '$dir_'"
	echo ------------------------------
	for file_ in "${dir}_/*.xml"; do
		cat "$file_" | ./main | java Main | python3 tratamento_final.py codigo_municipal.csv
	done
done

echo
echo "Executando na pasta 'belem'"
echo ------------------------------
for file in tests/belem/*; do
	cat "$file" | ./main | java Main | python3 tratamento_final.py codigo_municipal.csv 
done

echo
echo "Executando na pasta 'corumba'"
echo ------------------------------
for file in tests/corumba/*; do
	cat "$file" | ./main | java Main | python3 tratamento_final.py codigo_municipal.csv 
done

echo
echo "Executando na pasta 'joao_monlevade'"
echo ------------------------------
for file in tests/joao_monlevade/*; do
	cat "$file" | ./main | java Main | python3 tratamento_final.py codigo_municipal.csv 
done

echo
echo "Executando na pasta 'nova_lima'"
echo ------------------------------
for file in tests/nova_lima/*; do
	cat "$file" | ./main | java Main | python3 tratamento_final.py codigo_municipal.csv 
done

echo
echo "Executando na pasta 'parauapebas'"
echo ------------------------------
for file in tests/parauapebas/*; do
	cat "$file" | ./main | java Main | python3 tratamento_final.py codigo_municipal.csv 
done

echo
echo "Executando na pasta 'rio_de_janeiro'"
echo ------------------------------
for file in tests/rio_de_janeiro/*; do 
	cat "$file" | ./main | java Main | python3 tratamento_final.py codigo_municipal.csv 
done

echo
echo "Executando na pasta 'sao_luis'"
echo ------------------------------
for file in tests/sao_luis/*; do
	cat "$file" | ./main | java Main | python3 tratamento_final.py codigo_municipal.csv 
done
