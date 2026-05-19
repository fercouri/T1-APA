#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// =========================================================
// AS FUNÇÕES FORAM LIMPAS (SEM COUT) PARA MEDIR APENAS CPU
// =========================================================

// 1. Polinômio Iterativo
double avaliarPolinomio(const vector<double>& coeficientes, double x) {
    double resultado = 0.0;
    for (int i = coeficientes.size() - 1; i >= 0; i--) {
        resultado = resultado * x + coeficientes[i];
    }
    return resultado;
}

// 1. Polinômio Recursivo
double hornerRec(const vector<double>& a, int i, double x) {
    if (i == a.size() - 1) return a[i];
    return a[i] + x * hornerRec(a, i + 1, x);
}

// 2. Fibonacci Iterativo
long long fibonacciIterativo(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    long long a = 0, b = 1, fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

// 2. Fibonacci Recursivo
int fibonacciRecursivo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

// 3. Torre de Hanói Iterativo 
void torreHanoiIterativo(int n) {
    int totalMovimentos = pow(2, n) - 1;
    for (int i = 1; i <= totalMovimentos; i++) {
        int pinoOrigem = (i & (i - 1)) % 3;
        int pinoDestino = ((i | (i - 1)) + 1) % 3;
        // O cálculo do disco e do pino é feito, mas não impresso
        volatile int dummy1 = pinoOrigem; 
        volatile int dummy2 = pinoDestino;
    }
}

// 3. Torre de Hanói Recursivo 
void hanoiRecursivo(int n, char origem, char destino, char auxiliar) {
    if (n == 1) return;
    hanoiRecursivo(n - 1, origem, auxiliar, destino);
    hanoiRecursivo(n - 1, auxiliar, destino, origem);
}

// =========================================================
// FUNÇÃO DE TESTE E MEDIÇÃO DE TEMPO
// =========================================================

int main() {
    cout << fixed << setprecision(4);
    cout << "=========== QUESTAO 3: ANALISE DE COMPLEXIDADE ===========" << endl;

    // --- TESTE 1: AVALIAÇÃO DE POLINÔMIO ---
    cout << "\n[1] POLINOMIO (Executando 1000 vezes para medir com precisao)" << endl;
    vector<int> tamanhos_polinomio = {500, 1000, 2000, 4000};
    double x = 1.5;
    int repeticoes = 1000; // Multiplicador de carga
    
    for (int n : tamanhos_polinomio) {
        vector<double> coef(n, 1.1); 
        
        // Medindo o Iterativo 1000 vezes
        auto inicio = high_resolution_clock::now();
        for(int r = 0; r < repeticoes; r++) {
            avaliarPolinomio(coef, x);
        }
        auto fim = high_resolution_clock::now();
        duration<double, std::milli> tempoIterativo = fim - inicio;
        
        // Medindo o Recursivo 1000 vezes
        inicio = high_resolution_clock::now();
        for(int r = 0; r < repeticoes; r++) {
            // CORREÇÃO: O índice inicial agora é 0, e não mais n - 1
            hornerRec(coef, 0, x);
        }
        fim = high_resolution_clock::now();
        duration<double, std::milli> tempoRecursivo = fim - inicio;

        cout << "Grau N = " << n 
             << " | Iterativo: " << tempoIterativo.count() << " ms"
             << " | Recursivo: " << tempoRecursivo.count() << " ms" << endl;
    }

    // --- TESTE 2: FIBONACCI ---
    cout << "\n[2] FIBONACCI (Diferenca entre O(n) e O(2^n))" << endl;
    vector<int> tamanhos_fib = {10, 20, 35, 40};
    
    for (int n : tamanhos_fib) {
        auto inicio = high_resolution_clock::now();
        fibonacciIterativo(n);
        auto fim = high_resolution_clock::now();
        duration<double, std::milli> tempoIterativo = fim - inicio;

        inicio = high_resolution_clock::now();
        fibonacciRecursivo(n);
        fim = high_resolution_clock::now();
        duration<double, std::milli> tempoRecursivo = fim - inicio;

        cout << "N = " << n 
             << " | Iterativo: " << tempoIterativo.count() << " ms"
             << " | Recursivo: " << tempoRecursivo.count() << " ms" << endl;
    }

    // --- TESTE 3: TORRE DE HANOI ---
    cout << "\n[3] TORRE DE HANOI" << endl;
    vector<int> tamanhos_hanoi = {10, 20, 25, 28};
    
    for (int n : tamanhos_hanoi) {
        auto inicio = high_resolution_clock::now();
        torreHanoiIterativo(n);
        auto fim = high_resolution_clock::now();
        duration<double, std::milli> tempoIterativo = fim - inicio;

        inicio = high_resolution_clock::now();
        hanoiRecursivo(n, 'A', 'C', 'B');
        fim = high_resolution_clock::now();
        duration<double, std::milli> tempoRecursivo = fim - inicio;

        cout << "Discos N = " << n 
             << " | Iterativo: " << tempoIterativo.count() << " ms"
             << " | Recursivo: " << tempoRecursivo.count() << " ms" << endl;
    }

    cout << "\n==========================================================" << endl;
    return 0;
}