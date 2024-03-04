#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

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

typedef struct {
    int hora, min, seg;
} t_time_stamp;

t_time_stamp timestamp();
int sensor(int nro_sensores);
double temperatura(float baseTemp, float ambientTemp);
int movimento(int short_duration, int long_duration);
int luminosidade(int ambientLight);
int umidade(int baseHumidity, int ambientTemp);
t_sample* generate_samples_array(int samples);

#endif /* SENSOR_DATA_H */
