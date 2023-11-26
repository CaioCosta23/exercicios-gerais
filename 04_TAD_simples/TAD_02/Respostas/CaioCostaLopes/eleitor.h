#ifndef _ELIETOR_H_
#define _ELEITOR_H

typedef struct {
    int id;
    int votoP;
    int votoG;
}tEleitor;

/**
 * @brief Cria um eleitor com os dados informados;
 * 
 * @param id Identificador (ID) do eleitor;
 * @param votoP Voto para presidente do eleitor;
 * @param votoG Voto para governador do eleitor;
 * @return tEleitor Eleitor criado;
 */
tEleitor CriaEleitor(int id, int votoP, int votoG);

/**
 * @brief Lê um eleitor da entrada padrão;
 * 
 * @return tEleitor Retorna o Eleitor com as suas respectivas informações lidas;
 */
tEleitor LeEleitor();

/**
 * @brief Obtém o voto para presidente do eleitor;
 * 
 * @param eleitor Eleitor a ter seu voto (para presidente) verificado;
 * @return int Voto do eleitor (para presidente);
 */
int ObtemVotosPresidente(tEleitor eleitor);

/**
 * @brief Obtém o voto para governador do eleitor;
 * 
 * @param eleitor Eleitor a ter seu voto (para governador) verificado;
 * @return int Voto do eleitor (para governador);
 */
int ObtemVotoGoverador(tEleitor eleitor);

/**
 * @brief Verifica se os dois eleitores são "iguais" (ou seja se o eleitor, na verdade é o mesmo);
 * 
 * @param eleitor1 Primeiro eleitor da comparação;
 * @param eleitor2 Segundo eleitor da comparação;
 * @return int 1se o eleitor na verdade for o mesmo e 0, caso contrário;
 * OBS: Pode-se utilizar a função para verificar se o mesmo eleitor tentou votar duas vezes;
 */
int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2);

#endif