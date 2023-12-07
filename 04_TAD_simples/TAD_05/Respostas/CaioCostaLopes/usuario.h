#ifndef _USUARIO_H_
#define _USUARIO_H_

typedef struct Usuario {
    char nome[50]; // Nome do usuário;
    char cpf[15]; //CPF do usuário;
}tUsuario;

/**
 * @brief Cria um novo usuário;
 * 
 * @param nome Nome do usuário;
 * @param cpf CPF do usuário;
 * @return tUsuario Novo usuário criado;
 */
tUsuario CriaUsuario(char nome [20], char cpf[15]);

/**
 * @brief Imprime os dads de um usuário;
 * 
 * @param user Usuário a ser impresso;
 */
void ImprimeUsuario(tUsuario user);

#endif