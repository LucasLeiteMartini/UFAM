quantidade, base_origem, base_final = input().split()

quantidade = int(quantidade)


def checkpadrao(base_origem, base_final):
    
    if base_origem == ' ':
        base_origem = 10
    elif base_final == ' ':
        base_final = 10
    else:
        base_final = int(base_final)
        base_origem = int(base_origem)
    return base_final, base_origem

checkpadrao(base_origem, base_final)

print(base_origem)
print(base_final)

'''
valor_base10 = 0
valor_base_final = ''

# Transformando qualquer outra base para base 10
if base_origem and base_final == 10:
    for i, digito in enumerate(reversed(str(quantidade))):
        valor_base10 += int(digito) * (base_origem ** i)
else:
    for i, digito in enumerate(reversed(str(quantidade))):
        valor_base10 += int(digito) * (base_origem ** i)

#  Transformando base 10 para qualquer outra base
while valor_base10 != 0:
    valor_base_final += str(valor_base10 % base_final)
    valor_base10 = valor_base10 // base_final


valor_base10 = valor_base10 // base_final

print(valor_base10)
print(valor_base_final)'''