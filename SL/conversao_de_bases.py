quantidade = input()
base_origem = input()
base_final = input()

'''if (letra >= 65 and letra <= 90):
    numero = int(letra) - 55

if (numero >= 10 and numero <= 35):
    letra = chr(numero + 55)
'''
if base_origem == '' and base_final == '':
    base_origem = 10
    base_final = 10
elif base_origem == '':
    base_origem = 10
elif base_final == '':
    base_final = 10
else:
    base_origem = int(base_origem)
    base_final = int(base_final)

valor_base10 = 0

if base_origem == 10 and base_final == 10:
    valor_base10 = int(quantidade)
elif base_origem == 10:
    valor_base10 = int(quantidade)
else:
    for i, digito in enumerate(reversed(quantidade)):
        valor_base10 += int(digito) * (base_origem ** i)

temp = valor_base10

valor_base_final = ''

while temp != 0:
    valor_base_final += str(temp % base_final)
    temp = temp // base_final



print(valor_base_final[::-1])

print(valor_base10)