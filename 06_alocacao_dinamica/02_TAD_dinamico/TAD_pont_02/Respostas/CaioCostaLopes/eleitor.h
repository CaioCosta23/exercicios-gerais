#ifndef _ELEITOR_H_
#define _ELEITOR_H_

typedef struct {
    int id;
    int votoP;
    int votoG;
}tEleitor;

/**
 * @brief Cria um eleitor "vazio" (seus dados, neste caso);
 * 
 * @return tEleitor* Ponteiro para o eleitor criado (com os dados vazios);
 * 
 * OBS: O ponteiros devem ser inicializados com NULL e os campos numéricos com o valor -1;
 */
tEleitor *CriaEleitor();

/**
 * @brief Lê um eleitor do teclado;
 * 
 * @param eleitor Ponteiro para o eleitor terá seus dados apagados;
 */
void ApagaEleitor(tEleitor *eleitor);

/**
 * @brief Lê os dados de um eleitor pela entrada padrão (teclado);
 * 
 * @param eleitor Ponteiro para o eleitor que terá os seus dados armazenados;
 */
void LeEleitor(tEleitor *eleitor);

/**
 * @brief Obtém o voto para presidente do eleitor;
 * 
 * @param eleitor Ponteiro para o eleitor a ser verificado;
 * @return int Voto para presidente do eleitor;
 */
int ObtemVotoPresidente(tEleitor *eleitor);

/**
 * @brief Obtém o voto para governador do eleitor;
 * 
 * @param eleitor Ponteiro para eleitor a ser verificado;
 * @return int Voto para governador do eleitor;
 */
int ObtemVotoGovernador(tEleitor *eleitor);

/**
 * @brief Verifica se dois eleitores são iguais;
 * 
 * @param eleitor1 Ponteiro para primeiro eleitor a ser comparado;
 * @param eleitor2 Ponteiro para segundo eleitor a ser comparado;
 * @return int 1 se os eleitores são iguais, 0 caso contrário;
 * 
 * OBS: Use a função para verificar se algum eleitor tentou votar mais de uma vez;
 */
int EhMesmoEleitor(tEleitor *eleitor1, tEleitor *eleitor2);

#endif