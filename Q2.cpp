#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ==========================================
// QUESTAO 2: Códigos gerados por LLMs
// ==========================================

// ------------------------------------------
// Avaliação de um Polinômio
// ------------------------------------------

// Iterativo (Gerado por DeepSeek)
double avaliarPolinomio(const vector<double>& coeficientes, double x) {
    double resultado = 0.0;
    // Método de Horner: começa do coeficiente de maior grau
    for (int i = coeficientes.size() - 1; i >= 0; i--) {
        resultado = resultado * x + coeficientes[i];
    }
    return resultado;
}

// Recursivo (Gerado por: ChatGPT - Corrigido manualmente)
// obs: modelo original alucinou a ordem matemática do método de Horner, 
// avaliando o vetor de trás para frente. A lógica foi ajustada.
double hornerRec(const vector<double>& a, int i, double x) {
    // Caso base: verifica se chegamos no último índice (maior grau)
    if (i == a.size() - 1) {
        return a[i];
    }
    // Passo recursivo correto: constrói a equação de dentro para fora
    return a[i] + x * hornerRec(a, i + 1, x);
}

// ------------------------------------------
// PROBLEMA 2: Sequência de Fibonacci
// ------------------------------------------

// Iterativo (Gerado por DeepSeek)
long long fibonacciIterativo(int n) {
    if (n < 0) return -1;  // tratamento para entrada inválida
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    long long a = 0;  // F(0)
    long long b = 1;  // F(1)
    long long fib = 0;
    
    // Itera de 2 até n
    for (int i = 2; i <= n; i++) {
        fib = a + b;  // F(i) = F(i-1) + F(i-2)
        a = b;        // atualiza F(i-2) para o próximo ciclo
        b = fib;      // atualiza F(i-1) para o próximo ciclo
    }
    return fib;
}

// Recursivo (Gerado por ChatGPT)
int fibonacciRecursivo(int n) {
    // Casos base
    if (n == 0) return 0;
    if (n == 1) return 1;
    // Chamada recursiva
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

// ------------------------------------------
// PROBLEMA 3: Torre de Hanoi
// ------------------------------------------

// Iterativo (Gerado por DeepSeek)
void torreHanoiIterativoSimplificado(int n) {
    int totalMovimentos = pow(2, n) - 1;
    char pinos[3] = {'A', 'B', 'C'};
    
    for (int i = 1; i <= totalMovimentos; i++) {
        int disco = 0;
        int temp = i;
        while (temp % 2 == 0) {
            disco++;
            temp /= 2;
        }
        disco++; // Disco 1 é o menor
        
        int pinoOrigem = (i & (i - 1)) % 3;
        int pinoDestino = ((i | (i - 1)) + 1) % 3;
        
        if (n % 2 == 0) {
            if (pinoDestino == 1) pinoDestino = 2;
            else if (pinoDestino == 2) pinoDestino = 1;
        }
        
        cout << "Movimento " << i << ": mover disco " << disco
             << " de " << pinos[pinoOrigem] << " para " << pinos[pinoDestino] << endl;
    }
}

// Recursivo (Gerado por ChatGPT)
void hanoiRecursivo(int n, char origem, char destino, char auxiliar) {
    // Caso base
    if (n == 1) {
        cout << "Mover disco 1 de " << origem << " para " << destino << endl;
        return;
    }
    // Passo recursivo
    hanoiRecursivo(n - 1, origem, auxiliar, destino);
    cout << "Mover disco " << n << " de " << origem << " para " << destino << endl;
    hanoiRecursivo(n - 1, auxiliar, destino, origem);
}

// ==========================================
// FUNÇÃO PRINCIPAL (Testes da Questão 2)
// ==========================================

int main() {
    cout << "=========== QUESTAO 2 (LLMs) ===========" << endl;

    // --- Teste Polinômio ---
    cout << "\n[1] AVALIACAO DE POLINOMIO" << endl;
    vector<double> coef = {-1, 2, -6, 2}; // a0, a1, a2, a3
    double x = 3;
    cout << "P(" << x << ") = 2x^3 - 6x^2 + 2x - 1" << endl;
    
    cout << "Iterativo (DeepSeek): " << avaliarPolinomio(coef, x) << endl;
    // CORREÇÃO: O índice inicial 'i' agora começa em 0
    cout << "Recursivo (ChatGPT): " << hornerRec(coef, 0, x) << endl;

    // --- Teste Fibonacci ---
    cout << "\n[2] SEQUENCIA DE FIBONACCI" << endl;
    int n_fib = 6;
    cout << "Iterativo F(" << n_fib << ") (DeepSeek): " << fibonacciIterativo(n_fib) << endl;
    cout << "Recursivo F(" << n_fib << ") (ChatGPT): " << fibonacciRecursivo(n_fib) << endl;

    // --- Teste Torre de Hanoi ---
    cout << "\n[3] TORRE DE HANOI (3 Discos)" << endl;
    int n_hanoi = 3;
    cout << "--- Metodo Iterativo (DeepSeek) ---" << endl;
    torreHanoiIterativoSimplificado(n_hanoi);
    cout << "--- Metodo Recursivo (ChatGPT) ---" << endl;
    hanoiRecursivo(n_hanoi, 'A', 'C', 'B');

    cout << "\n========================================" << endl;
    return 0;
}