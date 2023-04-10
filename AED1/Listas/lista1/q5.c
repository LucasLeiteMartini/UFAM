#include <stdio.h>

int main() {
    int pc, dc, dl, soma;

	scanf("%d", &pc);

	scanf("%d %d", &dc, &dl);
	
    soma = dc + dl;

    if ((soma % 2 == 0 && pc == 1) || (soma % 2 == 1 && pc == 0)) {
        printf("Codibentinho venceu\n");
    } else {
        printf("Labiana venceu\n");
    }

    return 0;
}
