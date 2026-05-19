#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// Avaliação de um Polinômio
// ==========================================

// Avaliação Iterativa (Método de Horner)
double avaliarIterativo(const vector<double>& coeff, double x) {
    double resultado = 0.0;
    for (int i = coeff.size() - 1; i >= 0; i--) {
        resultado = resultado * x + coeff[i];
    }
    return resultado;
}

// Avaliação Recursiva (Método de Horner)
double avaliarRecursivo(const vector<double>& coeff, double x, int i) {
    // Caso base: verifica se chegamos no último índice (maior grau)
    if (i == coeff.size() - 1) {
        return coeff[i];
    }
    // Retorna o coeficiente atual + x * (avaliação do resto do polinômio)
    return coeff[i] + x * avaliarRecursivo(coeff, x, i + 1);
}

// ==========================================
// Sequência de Fibonacci
// ==========================================

// Fibonacci Iterativo (Retorna o n-ésimo termo)
int fibonacciIterativo(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    int ultimo = 1;
    int anterior = 1;
    int proximo;
    
    for (int i = 3; i <= n; ++i) {
        proximo = anterior + ultimo;
        anterior = ultimo;
        ultimo = proximo;
    }
    return ultimo;
}

// Fibonacci Recursivo (Retorna o n-ésimo termo)
int fibonacciRecursivo(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

// ==========================================
// Torre de Hanoi
// ==========================================

// Torre de Hanoi Iterativa
void hanoiIterativo(int n) {
    int total_movimentos = (1 << n) - 1; 
    for (int k = 1; k <= total_movimentos; k++) {
        int from = (k & (k - 1)) % 3;
        int to = ((k | (k - 1)) + 1) % 3;
        
        char from_char = 'A' + from;
        char to_char = 'A' + to;
        
        cout << "Mova disco de " << from_char << " para " << to_char << "\n";
    }
}

// Torre de Hanoi Recursiva
void hanoiRecursivo(int n, const char* from, const char* temp, const char* to) {
    if (n == 0) return;
    
    hanoiRecursivo(n - 1, from, to, temp);
    cout << "Mova disco " << n << " de " << from << " para " << to << "\n";
    hanoiRecursivo(n - 1, temp, from, to);
}

// FUNÇÃO PRINCIPAL (Testes da Questão 1)

int main() {
cout << "=========== QUESTAO 1 ===========" << endl;

    // --- Teste Polinômio ---
    cout << "\n[1] AVALIACAO DE POLINOMIO" << endl;
    vector<double> coeficientes = {-1, 2, -6, 2}; 
    double x = 3.0;
    cout << "P(x) = 2x^3 - 6x^2 + 2x - 1, para x = 3" << endl;
    
    cout << "Iterativo: " << avaliarIterativo(coeficientes, x) << endl;
    
    // índice 'i' começa em 0
    cout << "Recursivo: " << avaliarRecursivo(coeficientes, x, 0) << endl;

    // --- Teste Fibonacci ---
    cout << "\n[2] SEQUENCIA DE FIBONACCI" << endl;
    int n_fib = 6; // Teste com o 6º termo (pode ser alterado)
    cout << "Termo " << n_fib << " da sequencia" << endl;
    cout << "Iterativo: " << fibonacciIterativo(n_fib) << endl;
    cout << "Recursivo: " << fibonacciRecursivo(n_fib) << endl;

    // --- Teste Torre de Hanoi ---
    cout << "\n[3] TORRE DE HANOI" << endl;
    int n_hanoi = 3;
    cout << "Iterativa (" << n_hanoi << " discos):" << endl;
    hanoiIterativo(n_hanoi);
    cout << "\nRecursiva (" << n_hanoi << " discos):" << endl;
    hanoiRecursivo(n_hanoi, "A", "B", "C");

    cout << "\n=================================" << endl;
    return 0;
}