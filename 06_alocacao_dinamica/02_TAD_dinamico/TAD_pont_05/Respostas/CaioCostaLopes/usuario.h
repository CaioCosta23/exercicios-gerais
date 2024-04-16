#ifndef _USUARIO_H_
#define _USUARIO_H_

typedef struct Usuario {
    char nome[50];
    char cpf[50];
}tUsuario;

/**
 * @brief Cria um novo usuário;
 * 
 * @return tUsuario* Ponteiro para um novo usuário criado;
 */
tUsuario *CriaUsuario();

/**
 * @brief Lê os dados de um usuário da entrada padrão;
 * 
 * @param user Ponteiro para o usuário que terá os dados lido;
 */
void LeUsuario(tUsuario *user);

/**
 * @brief Imprime os dados de um usuário;
 * 
 * @param user Ponteiro para o usuário a ser impresso;
 */
void ImprimeUsuario(tUsuario *user);

/**
 * @brief Destrói (desaloca a memória do) usuário; 
 * 
 * @param user Ponteiro para o usuário a ser "destruído" (ter sua memória desalocada);
 */
void DestroiUsuario(tUsuario *user);
#endif