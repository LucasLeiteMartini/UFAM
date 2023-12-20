#Definindo as funções auxiliares
def base_to_dec(num,base): #Base máxima -> 36
    num = num[::-1]
    valor_base10 = 0
    for i in range(len(num)):
        digito = num[i]
        if digito.isdigit():
            digito = int(digito)
        else:
            digito = ord(digito.upper())-ord('A')+10
        valor_base10 += digito * (base ** i)
    return valor_base10

def dec_to_base(num,base):  #Base máxima -> 36
    base_num = ""
    while num>0:
        dig = int(num%base)
        if dig<10:
            base_num += str(dig)
        else:
            base_num += chr(ord('A')+dig-10)  # Faz o cálculo para achar a letra correspondente ao digito.
        num //= base

    base_num = base_num[::-1]  #Inverte a string
    return base_num

quantidade = input("Digite o valor a ser convertido: ")
base_origem = input("Digite sua base de origem(limite de base 36): ")
base_final = input("Digite a base final desejada(limite de base 36): ")

# Checa se o input das bases são vazios ou não, se forem, assumem o valor 10 como base padrão.
if base_origem == '' and base_final == '':
    base_origem = 10
    base_final = 10
elif base_origem == '':
        base_origem = 10
        base_final = int(base_final)
elif base_final == '':
        base_final = 10
        base_origem = int(base_origem)
else:
        base_origem = int(base_origem)
        base_final = int(base_final)

def conversao(quantidade, base_origem, base_final):

    base10 = base_to_dec(quantidade, base_origem) #Converte o valor original para a base decimal.
    valor_final = dec_to_base(base10,base_final) #Converte da base decimal para a base desejada.

    if base_final == 10:
        print(f"O resultado de {quantidade} na base {base_origem} para base 10 é: {valor_final}")
    else:
        print(f"Resultado = {valor_final} na base {base_final} ,e, na base 10, é: {base10}")

conversao(quantidade,base_origem,base_final)
