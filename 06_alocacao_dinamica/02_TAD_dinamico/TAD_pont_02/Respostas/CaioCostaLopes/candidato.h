#ifndef _CANDIDATO_H_
#define _CANDIDATO_H_

typedef struct {
    char *nome;
    char *partido;
    char cargo;
    int id;
    int votos;
}tCandidato;

/**
 * @brief Cria um candidato "vazio" (seus dados, neste caso);
 * Os ponteiros devem ser inicializados com "NULL" e os campos numéricos com o valor - 1;
 * 
 * @return tCandidato* Ponteiro para o candidato criado;
 */
tCandidato *CriaCandidato();

/**
 * @brief Apaga toda a memória alocada dinamicamente para guardar as informações de um candidato;
 * 
 * @param candidato Ponteiro para o candidato criado;
 */
void ApagaCandidato(tCandidato *candidato);

/**
 * @brief Lê um candidato
 * 
 * @param candidato Ponteiro para o candidato a ser lido;
 * 
 * OBS: O número de votos de um candidato deve ser zerado aqui;
 */
void LeCandidato(tCandidato *candidato);

/**
 * @brief Verifica se o identificador do candidato é igual ao informado;
 * 
 * @param candidato Ponteiro para o candidato a ser verificado;
 * @param id Identificador a ser comparado;
 * @return int 1 se o identificador é igual, 0 caso contrário;
 */
int VerificaIdCandidato(tCandidato *candidato, int id);

/**
 * @brief Verifica se dois candidatos são iguais;
 * 
 * @param candidato1 Ponteiro para o primeiro candidato a ser comparado;
 * @param candidato2 Ponteiro para o segundo candidato a ser comparado;
 * @return int 1 se os candidatos forem iguais, 0 caso contrário;
 * 
 * OBS: Utilize esta função para verificar se houve empate;
 */
int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2);

/**
 * @brief Obtém o cargo do candidato;
 * 
 * @param candidato Ponteiro para o candidato a ser verificado;
 * @return char Cargo do candidato;
 */
char ObtemCargo(tCandidato *candidato);

/**
 * @brief Incrementa 1 voto ao candidato;
 * 
 * @param candidato Ponteiro para o candidato a ter o(s) voto(s) incrementado(s);
 */
void IncrementaVotoCandidato(tCandidato *candidato);

/**
 * @brief Obtém a quantidade de votos do candidato;
 * 
 * @param candidato ponteiro para o candidato a ser verificado;
 * @return int Quantidade de votos do candidato;
 */
int ObtemVotos(tCandidato *candidato);

/**
 * @brief Calcula o percentual de votos do candidato em relação ao total de votos (do mesmo cargo);
 * 
 * @param candidato Ponteiro para o candidato a ser verificado;
 * @param totalVotos Total de votos da eleição;
 * @return float Percentual de votos do candidato;
 */
float CalculaPercentualVotos(tCandidato *candidato, int totalVotos);

/**
 * @brief Imprime os dados do candidato na tela;
 * 
 * @param candidato Ponteiro para o candidato a ser impresso;
 * @param percentualVotos percentual de votos do candidato;
 */
void ImprimeCandidat(tCandidato *candidato, float percentualVotos);

#endif