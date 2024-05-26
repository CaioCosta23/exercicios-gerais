#ifndef _USUARIO_H_
#define _USUARIO_H_

typedef struct Usuario tUsuario;

/**
 * @brief Cria (aloca a memória dinamicamente de) um usuário com seus dados inicializados;
 * 
 * @return tUsuario* Ponteiro para a estrutura do tipo "tUsuario";
 */
tUsuario *CriaUsuario();

/**
 * @brief Lê os dados de um usuário;
 * 
 * @param user Ponteiro para a estrutura do tipo "tUsuario" com os campos em que serão armazenados os dados dos usuários;
 */
void LeUsuario(tUsuario *user);

/**
 * @brief Imprime os dados de um usuário;
 * 
 * @param user Ponteiro para a estrutura do tipo "tUsuario" com os dados do usuário a serem impressos;
 */
void ImprimeUsuario(tUsuario *user);

/**
 * @brief Destói (desaloca a memória alocada dinamicamente de) um usuário;
 * 
 * @param user Ponteiro para a estrutura do tipo "tUsuario" que será destruída (desalocada);
 */
void DestroiUsuario(tUsuario *user);

#endif