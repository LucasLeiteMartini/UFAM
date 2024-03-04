#include "stdio.h"
#include "stdlib.h"
#include "time.h"


typedef struct {
    int hora, min, seg;
} t_time_stamp;

typedef struct {
    int t_sensor;
    union {
        double temperatura;
        int luminosidade;
        int movimento_duracao;
        int umidade;
    } value;
    int hora, min, seg;
} t_sample;

t_time_stamp timestamp() {
  // Get the current time in seconds since the epoch (Jan 1, 1970)
  time_t current_time = time(NULL);

  // Convert the time to a human-readable format using local time zone
  struct tm *local_time = localtime(&current_time);

  // Access individual time components (e.g., hour, minute, second)
  int hour = (local_time->tm_hour + rand()) % 24;
  int minute = (local_time->tm_min + rand()) % 60;
  int second = (local_time->tm_sec + rand()) % 60;

  return (t_time_stamp){.hora=hour, .min = minute, .seg =second};
}


int sensor(int nro_sensores){
    //srand(time(NULL));
    return (1 + (rand()%nro_sensores));
}

#define MIN_TEMP -10 // Minimum measurable temperature (°C)
#define MAX_TEMP 50 // Maximum measurable temperature (°C)

double temperatura(float baseTemp, float ambientTemp) {
  // Simulate heat transfer between sensor and environment
  float temperatureChange = 0.1 * (ambientTemp - baseTemp); // Adjust coefficient for desired thermal response

  // Introduce random noise to mimic sensor imperfections
  //srand(time(NULL));
  float noise = (float)rand() / RAND_MAX * 0.5; // Random noise between -0.25 and 0.25 °C
  temperatureChange += noise;

  // Update base temperature considering heat transfer and noise
  float newTemp = baseTemp + temperatureChange;

  // Ensure value stays within the measurable range
  newTemp = (newTemp < MIN_TEMP) ? MIN_TEMP : newTemp;
  newTemp = (newTemp > MAX_TEMP) ? MAX_TEMP : newTemp;

  return newTemp;
}



#define SENSOR_RANGE 5 // Detection range in meters (adjust as needed)

int movimento(int short_duration, int long_duration){

    //srand(time(NULL));
    int movement = rand() % 10; // Generate random number between 0 and 9

    if (movement < 3){ // Movement detected if random number is less than 3 (adjust probability as needed)
        return rand()%long_duration;
    }else{
        return rand()%short_duration;
    }
}

#define MIN_LUMEN 0 // Minimum measurable lumen value
#define MAX_LUMEN 1000 // Maximum measurable lumen value

int luminosidade(int ambientLight) {
  // Simulate external light affecting sensor readings
  int baseValue = ambientLight * (rand() % 50); // Adjust multiplier for desired sensitivity

  // Introduce random noise to mimic sensor imperfections
  //srand(time(NULL));
  int noise = rand() % 10; // Generate random noise between -5 and 4 lumens
  baseValue += noise;

  // Ensure value stays within the measurable range
  baseValue = (baseValue < MIN_LUMEN) ? MIN_LUMEN : baseValue;
  baseValue = (baseValue > MAX_LUMEN) ? MAX_LUMEN : baseValue;

  return baseValue;
}


#define MIN_HUMIDITY 0 // Minimum measurable humidity percentage (%)
#define MAX_HUMIDITY 100 // Maximum measurable humidity percentage (%)

int umidade(int baseHumidity, int ambientTemp) {
  // Simulate humidity change based on ambient temperature
  int humidityChange = (ambientTemp - 20) * 2; // Adjust coefficient for desired sensitivity

  // Introduce random noise to mimic sensor imperfections
  //srand(time(NULL));
  int noise = rand() % 5; // Random noise between -2 and 2 percentage points

  // Update base humidity considering ambient temperature and noise
  int newHumidity = baseHumidity + humidityChange + noise;

  // Ensure value stays within the measurable range
  newHumidity = (newHumidity < MIN_HUMIDITY) ? MIN_HUMIDITY : newHumidity;
  newHumidity = (newHumidity > MAX_HUMIDITY) ? MAX_HUMIDITY : newHumidity;

  return newHumidity;
}

t_sample* generate_samples_array(int samples)
{
    srand(time(NULL));

    t_sample* samples_array = malloc(samples * sizeof(t_sample));

    for (int i = 0;i <= samples; i++){
        int t_sensor = sensor(4);
        t_time_stamp t = timestamp();
        samples_array[i].t_sensor = t_sensor;
        samples_array[i].hora = t.hora;
        samples_array[i].min = t.min;
        samples_array[i].seg = t.seg;
        if (t_sensor == 1){ //temperatura
            samples_array[i].value.temperatura = temperatura(17,50);
        }else if (t_sensor == 2){ // luminosidade
            samples_array[i].value.luminosidade = luminosidade(10);              
        }else  if(t_sensor == 3){ // movimento
            samples_array[i].value.movimento_duracao = movimento(1000, 1000 * 60);
            // int duracao = movimento(1000, 1000*60);
        }else { // umidade
            samples_array[i].value.umidade = umidade(75, 40);
        }

    }

    return samples_array;
}

long long swap_count = 0;        // Contador global de trocas

void counting_sort(t_sample *arr, int n, int exp) {
    const int RADIX = 10;  // Base decimal

    t_sample output[n];
    int count[RADIX];

    for(int i = 0; i < RADIX; i++){
        count[i] = 0;
    }

    // Contagem de ocorrências
    for (int i = 0; i < n; i++)
        count[(arr[i].t_sensor / exp) % RADIX]++;

    // Atualização de count para armazenar a posição correta de cada elemento
    for (int i = 1; i < RADIX; i++)
        count[i] += count[i - 1];

    // Construção do array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i].t_sensor / exp) % RADIX] - 1] = arr[i];
        count[(arr[i].t_sensor / exp) % RADIX]--;
    }

    // Copiar o array de saída de volta para arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        swap_count++;  // Incrementar o contador de trocas
    }
}

void radix_sort_samples(t_sample *arr, int n) {
    clock_t start_time, end_time;
    start_time = clock();

    swap_count = 0;        // Zerar o contador de trocas antes de iniciar

    // Encontrar o maior número para saber o número de dígitos
    int max_t_sensor = arr[0].t_sensor;
    for (int i = 1; i < n; i++) {
        if (arr[i].t_sensor > max_t_sensor) {
            max_t_sensor = arr[i].t_sensor;
        }
    }

    // Aplicar o counting sort para cada dígito
    for (int exp = 1; max_t_sensor / exp > 0; exp *= 10) {
        counting_sort(arr, n, exp);
    }

    // Ordenar por ordem cronológica após a ordenação por tipo
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].t_sensor == arr[j].t_sensor &&
                (arr[i].hora > arr[j].hora || (arr[i].hora == arr[j].hora &&
                                                 (arr[i].min > arr[j].min || (arr[i].min == arr[j].min && arr[i].seg > arr[j].seg))))) {
                // Trocar as posições se necessário
                t_sample temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swap_count++;  // Incrementar o contador de trocas
            }
        }
    }

    end_time = clock();
    double total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    for (int i = 0; i < n; i++) {
        if (arr[i].t_sensor == 1) {
            printf("%d %.3lf %02d:%02d:%02d\n", arr[i].t_sensor, arr[i].value.temperatura,
                   arr[i].hora, arr[i].min, arr[i].seg);
        } else {
            printf("%d %d %02d:%02d:%02d\n", arr[i].t_sensor, arr[i].value.luminosidade,
                   arr[i].hora, arr[i].min, arr[i].seg);
        }
    }

    printf("Tempo de execução do Radix Sort: %f segundos\n", total_time);
    printf("Número total de trocas: %lld\n", swap_count);
}

int main(int argc, char const *argv[]){
    int samples;
    scanf("%d", &samples);
    int count = 0;

    t_sample* samples_array = generate_samples_array(samples);
    
    radix_sort_samples(samples_array, samples);
    return 0;
}