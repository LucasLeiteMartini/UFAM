def sum_bin(num1, num2):
    if len(num1) != len(num2):
        if len(num1) > len(num2):
            num2 = '0' * (len(num1) - len(num2)) + num2
        else:
            num1 = '0' * (len(num1) - len(num2)) + num1
        
    resultado = ''
    carry = 0

    for i in range(len(num1)-1,-1,-1):
        soma = int(num1[i]) + int(num2[i]) + carry
        if soma == 0:
            resultado = '0' + resultado
            carry = 0
        elif soma == 1:
            resultado = '1' + resultado
            carry = 0
        elif soma == 2:
            resultado = '0' + resultado
            carry = 1
        else:
            resultado = '1' + resultado
            carry = 0
    return resultado