#! /usr/bin/env python3

import csv 
import sys 

try:
    input_file = sys.argv[1]

except:
    print('Usage: data_base.csv')
    exit()

with open(input_file, newline='') as csv_file:

    database = csv.reader(csv_file, delimiter=',', quotechar='"')

    for line in sys.stdin:
        fields = line.split('-')
        fields[2].replace(',', '.')
        fields[3].replace(',', '.')
        for row in database:
            if fields[0] == row[1]:
                print("ACHEI")
                fields[0] = row[0]
            if fields[1] == row[1]:
                print("ACHEI")
                fields[1] = row[0]

#print(campos[0] + "," + campos[1] + "," + campos[2] + "," + campos[3])
