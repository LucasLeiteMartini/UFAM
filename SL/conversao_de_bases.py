quantidade, base_origem, base_final = input().split()

quantidade = int(quantidade)

# Função que checa se a base foi informada ou não, se naão for
# Define a base padrão para 10.
def checkBase(base_origem, base_final):
    baseO = 0
    baseF = 0


    if base_origem == ' ' and base_final != ' ':
        baseO = 10
    elif base_final == ' ' and base_origem != ' ':
        baseF = 10
    else:
        baseO = int(base_origem)
        baseF = int(base_final)
    return baseO, baseF

base_origem = checkBase(base_origem,base_final)[0]
base_final = checkBase(base_origem,base_final)[1]

valor_base10 = 0
valor_base_final = ''

# Transformando qualquer outra base para base 10
if base_origem == 10 and base_final == 10:
        valor_base10 = quantidade
elif base_origem == 10:
        valor_base10 = quantidade
else:
    for i, digito in enumerate(reversed(str(quantidade))):
        valor_base10 += int(digito) * (base_origem ** i)

temp = valor_base10


if base_final != 0:
    while temp != 0:
        valor_base_final += str(temp % base_final)
        temp = temp // base_final

valor_base_final = valor_base_final[::-1]

print(valor_base10)
print(int(valor_base_final))