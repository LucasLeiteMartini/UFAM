#include "stdio.h"
#include "stdlib.h"
#include "gerador.h"
#include "time.h"


void swap_samples(t_sample *a, t_sample *b) {
    t_sample temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort_samples(t_sample *samples_array, int num_samples, int *troca_count) {
    clock_t start_time, end_time;
    start_time = clock();

    for (int i = 0; i < num_samples - 1; i++) {
        int min_index = i;

        // Encontrar o índice do menor elemento pelo tipo e tempo
        for (int j = i + 1; j < num_samples; j++) {
            if (samples_array[j].t_sensor < samples_array[min_index].t_sensor ||
                (samples_array[j].t_sensor == samples_array[min_index].t_sensor &&
                 (samples_array[j].hora < samples_array[min_index].hora ||
                  (samples_array[j].hora == samples_array[min_index].hora &&
                   (samples_array[j].min < samples_array[min_index].min ||
                    (samples_array[j].min == samples_array[min_index].min &&
                     samples_array[j].seg < samples_array[min_index].seg)))))) {
                min_index = j;
            }
        }

        // Trocar os elementos
        swap_samples(&samples_array[i], &samples_array[min_index]);
        (*troca_count)++;  // Incrementar o contador de trocas
    }

    end_time = clock();
    double total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", total_time);
    printf("Número total de trocas: %d\n", *troca_count);
}

int main(int argc, char const *argv[]){
    int samples;
    scanf("%d", &samples);
    int count = 0;

    t_sample* samples_array = generate_samples_array(samples);
    
    selection_sort_samples(samples_array, samples, &count);
    return 0;
}