'''
Alunos: Lucas Leite Martini, Kaike Ribas da Silva Maciel 
Matrículas: 22252570, 22250538
'''

from random import randint

def soma_binaria(num1, num2):
    # Adiciona zeros à esquerda para fazer os números terem o mesmo tamanho
    if len(num1) < 4:
        num1 = num1.zfill(4)
    if len(num2) < 4:
        num2 = num2.zfill(4)
    resultado = []
    carry = 0
    
    # Itera pelos bits da direita para a esquerda
    for i in range(len(num1)-1, -1, -1):
        soma = int(num1[i]) + int(num2[i]) + carry
        resultado.append(str(soma % 2))  # Adiciona o bit da soma ao resultado
        carry = soma // 2  # Calcula o carry para a próxima coluna
    
   
    # Inverte a ordem dos bits do resultado e retorna como string
    return ''.join(resultado[::-1])

def dec_to_base(num,base):  # Base máxima -> 36
    base_num = ""
    while num>0:
        dig = int(num%base)
        if dig<10:
            base_num += str(dig)
        else:
            base_num += chr(ord('A')+dig-10)  # Faz o cálculo para achar a letra correspondente ao digito
        num //= base

    base_num = base_num[::-1]  # Inverte a string
    return base_num


#Escolhe aleatóriamente um número de 0 a 15
#Após o número 7, a representação dos números de 8 a 15 são as mesmas de -8 a -1
sua_sorte = dec_to_base(randint(0,15),2)

print("Olá jogador! Esta é a Roda da Fortuna, um jogo em que você pode testar sua sorte... Mas qual será o seu resultado? FORTUNA OU INFORTÚNIO???\n")
print("Aqui segue algumas regras do jogo:")
print("[1] Você começa com um valor aleatório e faz a sua primeira jogada, sendo ela obrigatória.")
print("[2] Após sua primeira jogada obrigatória, você tem direito a mais 3 tentativas podendo decidir entre c de continue, ou p de parar")

print("="*140)
print(f"\nSeu valor inicial é {sua_sorte.zfill(4)}\n")
print("="*140)

#Calcula o novo valor de fortuna infortunio utilizando a função de soma binária
fortuna_infortunio = soma_binaria(sua_sorte,dec_to_base(randint(0,15),2))

print(f"Seu novo valor é: {fortuna_infortunio}")
print("A partir de agora você possui mais três tentativas")
tentativa = 1

def roda_da_fortuna(fortuna_infortunio,tentativa):
    # Um loop que funciona enquanto as tentativas forem menores que 3, ou se o jogador desejar continuar
    print('='*140)
    continua = input("Desejas continuar meu caro jogador? ")
    play = True
    while play:
        if continua == 'c' and tentativa < 3:
            fortuna_infortunio = soma_binaria(sua_sorte,dec_to_base(randint(0,15),2))
            print(f"Seu novo valor é: {fortuna_infortunio}")
            continua = input("Desejas continuar meu caro jogador? ")
            print("="*140)
            tentativa += 1
        else:
            play = False
    # Checa se o bit de sinal é positivo ou não
    if fortuna_infortunio[0] == '0':
        print("Você chegou ao fim jogador, e seu resultado foi... FORTUNA!!!!")
    else:
        print("Você chegou ao final jogador, e seu resultado foi... INFORTÚNIO HAHAHAHA!!!")

roda_da_fortuna(fortuna_infortunio, tentativa)