#include <stdio.h>
#include <stdlib.h>
#include <fftw3.h>

int main() {
    int N = 1024; // Número de puntos
    fftw_complex *x, *out;
    fftw_plan p;

    // Alocar memoria
    x = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

    // Inicializar la señal
    for (int i = 0; i < N; i++) {
        x[i][0] = sin(2 * M_PI * 5 * i / N); // Parte real
        x[i][1] = 0.0; // Parte imaginaria
    }

    // Crear un plan para la FFT
    p = fftw_plan_dft_1d(N, x, out, FFTW_FORWARD, FFTW_ESTIMATE);

    // Ejecutar la FFT
    fftw_execute(p);

    // Imprimir resultados
    for (int i = 0; i < N; i++) {
        printf("Frecuencia %d: %f + %fi\n", i, out[i][0], out[i][1]);
    }

    // Liberar memoria
    fftw_destroy_plan(p);
    fftw_free(x);
    fftw_free(out);

    return 0;
}
