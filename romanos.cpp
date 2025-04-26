#include "romanos.hpp"
#include <map>

int ConversorRomano::converter(const string& romano) {
    map<char, int> valores = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;
    int valorAnterior = 0;
    int repeticoes = 1;
    char ultimoCaractere = '\0';
    for (int i = romano.length() - 1; i >= 0; i--) {
        char caractere = toupper(romano[i]); //toupper para aceitar entradas minusculas

        if (valores.count(caractere) == 0) {
            return -1;
        }
        int valorAtual = valores[caractere];

        if (caractere == ultimoCaractere) {  //verifica se o algarismo pode ser repetido e se é maior que 3 reps
            repeticoes++;
            if ((caractere == 'I' || caractere == 'X' || caractere == 'C' || caractere == 'M') && repeticoes > 3) {
                return -1;
            }
            if (caractere == 'V' || caractere == 'L' || caractere == 'D') {
                return -1;
            }
        } else {
            repeticoes = 1; //reseta contagem
        }

        if (valorAtual < valorAnterior) {
            if (!(
                (caractere == 'I' && (ultimoCaractere == 'V' || ultimoCaractere == 'X')) ||
                (caractere == 'X' && (ultimoCaractere == 'L' || ultimoCaractere == 'C')) ||
                (caractere == 'C' && (ultimoCaractere == 'D' || ultimoCaractere == 'M'))
            )) {
                return -1;  //verfica se a subtração é valida
            }
            total -= valorAtual;
        } else {
            total += valorAtual;
        }


        valorAnterior = valorAtual;
        ultimoCaractere = caractere;
    }

    return (total > 3000) ? -1 : total;
};