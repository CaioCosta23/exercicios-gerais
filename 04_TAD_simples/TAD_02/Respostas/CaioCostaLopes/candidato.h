#ifndef _CANDITADO_H_
#define _CANDIDATO_H_

typedef struct {
    char nome[50];
    char partido[50];
    char cargo;
    int id;
    int votos;
}tCandidato;

/**
 * @brief Cria um candidato e seus dados informados;
 * 
 * @param nome Nome do candidato;
 * @param partido Partido do candidato;
 * @param cargo Cargo do candidato;
 * @param id Identificador (número - ID) do candidato
 * @return tCandidato Candidato criado;
 */
tCandidato CriarCandidato(char nome[], char partido[], char cargo, int id);

/**
 * @brief Lê um candidato (suas informações);
 * 
 * @return tCandidato Candidato lido (e suas informações que foram coletadas na leitura);
 */
tCandidato LeCandidato();

/**
 * @brief Verifica se o id do candidato é igual ao do informado;
 * 
 * @param candidato Candidato a ser verificado;
 * @param id id a ser verificado/comparado com o do canditado;
 * @return int 1 Se o id informado for o mesmo do candidato e 0, caso contrário;
 */
int VerificaIdCandidato(tCandidato candidato, int id);

/**
 * @brief Verifica se dois candidatos são iguais;
 * 
 * @param candidato1 Candidato 1;
 * @param candidato2 Candidato 2;
 * @return int 1 se o candidato for o mesmo e 0, caso contrário;
 * OBS: A função pode ser usada também para verificar um caso de empate;
 */
int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2);

/**
 * @brief Obtém o cargo do candidato;
 * 
 * @param candidato Candidato analisado;
 * @return char Cargo do candidato;
 */
char ObtemCargo(tCandidato candidato);

/**
 * @brief Incrementa 1 voto para o candidato;
 * 
 * @param candidato Candidato que terá a quantidade de votos incrementada;
 * @return tCandidato Candidto com a quantidade de votos já incrementada (+ 1 voto);
 */
tCandidato IncrementaVotoCandidato(tCandidato candidato);

/**
 * @brief Obtém a quantidade de votos do candidato analisado;
 * 
 * @param candidato Candidato que terá a quantidade de votos coletados;
 * @return int Quantidade de votos que o candidato possui;
 */
int ObtemVotos(tCandidato candidato);

/**
 * @brief Calcula na forma percentual (porcentagem do total) a quantidade de votos que o candidato obteve;
 * 
 * @param candidatos Candidato que terá a quantidade de votos coletados;
 * @param totalVotos Total de votos (unitários) que o candidato obteve;
 * @return float Quantidade percentual (porcentagem) do total de votos que o candidato obteve;
 */
float CalculaPercentualVotos(tCandidato candidatos, int totalVotos);

/**
 * @brief Imprime os dados do candidato na tela;
 * 
 * @param candidato Candidato que terá seus dados impressos;
 * @param percentualVotos Percentual (porcentagem) do total de votos que o candidato obteve na eleição;
 */
void ImprimeCandidato(tCandidato candidato, float percentualVotos);

#endif