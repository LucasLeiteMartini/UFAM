import java.util.Scanner;

public class DiaSemana {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] cargaTotalPorDia = new int[7];
        int count = 0;

        // Leitura das cargas horárias e cálculo da carga total por dia
        while (scanner.hasNextInt()) {
            for (int i = 0; i < 7; i++) {
                if (scanner.hasNextInt()) {
                    cargaTotalPorDia[i] += scanner.nextInt();
                    count++;
                } else {
                    break; // Encerra o loop interno se não houver mais entrada
                }
            }
        }

        // Verifica se há entrada suficiente para todos os dias da semana
        if (count % 7 != 0) {
            System.err.println("Entrada insuficiente para todos os dias da semana.");
            System.exit(1); // Encerra o programa com código de erro
        }

        // Encontrar a maior carga horária total
        int maxCargaHoraria = cargaTotalPorDia[0];
        for (int cargaHorariaDia : cargaTotalPorDia) {
            maxCargaHoraria = Math.max(maxCargaHoraria, cargaHorariaDia);
        }

        // Imprimir os dias da semana com a maior carga horária total
        for (int i = 0; i < 7; i++) {
            if (cargaTotalPorDia[i] == maxCargaHoraria) {
                System.out.println(i);
            }
        }

        scanner.close();
    }
}
