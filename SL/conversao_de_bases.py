quantidade = input()
base_original = input()
base_final = input()
valor_base10 = 0
valor_base_final = ''



if base_final == '' and base_final == '':
    base_original = 10
    base_final = 10
    valor_base_final = quantidade
elif base_original == '':
    base_original = 10
elif base_final == '':
    base_final = 10
else:
    base_final = int(base_final)
    base_original = int(base_original)

if base_final != 10:
    for i, digito in enumerate(reversed(quantidade)):
        valor_base10 += int(digito) * (base_original ** i)
else:
    