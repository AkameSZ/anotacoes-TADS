#include <stdio.h>    // Biblioteca padrão para entrada e saída (printf, scanf, fgets)
#include <string.h>   // Biblioteca para manipulação de strings (strcmp, strcspn)
#include <stdbool.h>  // Biblioteca que adiciona suporte ao tipo lógico 'bool' (true/false)
#include <stdlib.h>   // Biblioteca padrão para utilitários gerais (como funções de sistema)

#define MAX_FILMES 100 // Define uma constante: o catálogo terá no máximo 100 filmes

// --- DEFINIÇÃO DA ESTRUTURA (STRUCT) ---
// Define o tipo de dado 'Filme' que agrupa todas as informações de uma mídia
typedef struct {
    int codigo;         // Código identificador único do filme (ID)
    char nome[100];     // Vetor de caracteres para armazenar o título do filme (até 99 letras + '\0')
    char genero[50];    // Vetor de caracteres para o gênero (até 49 letras + '\0')
    int ano;            // Ano de lançamento
    int duracao;        // Duração do filme em minutos
    int disponivel;     // Status de disponibilidade: 1 para Disponível, 0 para Indisponível
} Filme;

// --- PROTÓTIPOS DAS FUNÇÕES ---
// Avisa ao compilador quais funções existem no código e como elas devem ser chamadas
void exibirMenu();
void cadastrarFilme(Filme filmes[], int *total); // Usa ponteiro (*total) pois altera a quantidade de filmes cadastrados
void listarFilmes(Filme filmes[], int total);
int pesquisarFilme(Filme filmes[], int total, int cod);
bool existeFilme(Filme filmes[], int total, int cod);
void alterarFilme(Filme filmes[], int total);
void removerFilme(Filme filmes[], int *total);    // Usa ponteiro (*total) pois diminui o número de filmes
void listarDisponiveis(Filme filmes[], int total);
int quantidadeFilmes(int total);
int quantidadeDisponiveis(Filme filmes[], int total);
void apresentarEstatisticas(Filme filmes[], int total);

// --- FUNÇÃO PRINCIPAL (PONTO DE PARTIDA DO PROGRAMA) ---
int main() {
    Filme catalogo[MAX_FILMES]; // Cria um vetor (array) do tipo 'Filme' capaz de guardar até 100 filmes
    int total_filme = 0;        // Variável que controla quantos filmes estão realmente cadastrados no momento
    int opcao;                  // Guarda a opção escolhida pelo usuário no menu

    // Estrutura de repetição que roda pelo menos uma vez e continua enquanto a opção não for 0
    do {
        exibirMenu(); // Chama a função para desenhar as opções na tela
        printf("Escolha a opcao: ");
        scanf("%i", &opcao);
        getchar(); // Limpa o caractere '\n' (Enter) deixado pelo scanf no buffer do teclado

        // Estrutura de controle que direciona o fluxo para a função correta baseado no número digitado
        switch(opcao) {
            case 1:
                // Passamos o endereço de total_filme (&total_filme) para que a função possa modificá-lo diretamente
                cadastrarFilme(catalogo, &total_filme);
                break;

            case 2:
                // Passamos apenas o valor pois a listagem não precisa modificar a quantidade de filmes
                listarFilmes(catalogo, total_filme);
                break;

            case 3: {
                // Bloco protegido por chaves {} para permitir a declaração de variáveis locais (como cod e indice)
                int cod;
                printf("\n--- Pesquisar Filme ---\n");
                printf("Digite o codigo do filme: ");
                scanf("%d", &cod);
                
                // Realiza a pesquisa e guarda a posição encontrada (ou -1 se não encontrar)
                int indice = pesquisarFilme(catalogo, total_filme, cod);
                if (indice != -1) {
                    printf("\nFilme Encontrado:\n");
                    // Exibe os detalhes utilizando um operador ternário (? :) para traduzir o status booleano para texto
                    printf("Codigo: %d | Titulo: %s | Genero: %s | Ano: %d | Duracao: %d min | Status: %s\n",
                           catalogo[indice].codigo, catalogo[indice].nome, catalogo[indice].genero,
                           catalogo[indice].ano, catalogo[indice].duracao, 
                           catalogo[indice].disponivel ? "Disponivel" : "Indisponivel");
                } else {
                    printf("Filme com codigo %d nao encontrado.\n", cod);
                }
                break;
            }

            case 4:
                alterarFilme(catalogo, total_filme);
                break;

            case 5:
                removerFilme(catalogo, &total_filme); // Envia o endereço de total_filme para reduzir o contador
                break;

            case 6:
                listarDisponiveis(catalogo, total_filme);
                break;

            case 7:
                apresentarEstatisticas(catalogo, total_filme);
                break;

            case 0:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!!\n");
                break;
        }
    } while (opcao != 0); // O loop só termina quando 'opcao' for igual a zero

    return 0; // Informa ao sistema operacional que o programa terminou com sucesso
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

// Apenas imprime as opções disponíveis na tela
void exibirMenu() {
    printf("\n------- MENU -------\n");
    printf("1. Cadastrar Filme\n");
    printf("2. Listar Todos os Filmes\n");
    printf("3. Pesquisar Filme por Codigo\n");
    printf("4. Alterar Informacoes de um Filme\n");
    printf("5. Remover Filme do Catalogo\n");
    printf("6. Listar Filmes Disponiveis\n");
    printf("7. Apresentar Estatisticas\n");
    printf("0. Sair\n");
    printf("===================================\n");
}

// Cadastra um novo filme se houver espaço livre no vetor
void cadastrarFilme(Filme filmes[], int *total) {
    // Como total é um ponteiro (int*), usamos o asterisco (*total) para acessar/desreferenciar seu valor numérico
    if (*total >= MAX_FILMES) { 
        printf("\nCatalogo cheio!!\n");
        return; // Sai da função mais cedo caso não haja espaço
    }

    int cod;
    printf("\n----- Cadastrar Filme -----");
    printf("\nCodigo: ");
    scanf("%i", &cod);
    getchar(); // Limpa o '\n' gerado pelo enter no scanf

    // Verifica se o código digitado já pertence a algum filme cadastrado
    if (existeFilme(filmes, *total, cod)) {
        printf("Ja existe um filme com o codigo %i!!\n", cod);
        return; // Impede o cadastro duplicado
    }

    // Como o filme é válido, começamos a preencher os dados na última posição disponível (*total)
    filmes[*total].codigo = cod;

    printf("Titulo: ");
    // fgets é mais seguro que scanf para ler textos com espaços. Lê até 100 caracteres da entrada padrão (stdin)
    fgets(filmes[*total].nome, 100, stdin);
    // strcspn localiza a posição onde o '\n' (gerado ao apertar Enter) está e o substitui por '\0' (fim de string)
    filmes[*total].nome[strcspn(filmes[*total].nome, "\n")] = 0;

    printf("Genero: ");
    fgets(filmes[*total].genero, 50, stdin);
    filmes[*total].genero[strcspn(filmes[*total].genero, "\n")] = 0;

    printf("Ano de Lancamento: ");
    scanf("%d", &filmes[*total].ano);

    printf("Duracao (em minutos): ");
    scanf("%d", &filmes[*total].duracao);

    int disp;
    printf("Disponivel? (1 - Sim / 0 - Nao): ");
    scanf("%d", &disp);
    // Se digitou 1, salva true (1). Se digitou qualquer outra coisa, salva false (0)
    filmes[*total].disponivel = (disp == 1);

    // Incrementa o número total de filmes cadastrados usando o ponteiro, refletindo a mudança na main()
    (*total)++;
    printf("\nFilme cadastrado com sucesso!\n");
}

// Exibe na tela todos os filmes inseridos no sistema
void listarFilmes(Filme filmes[], int total) {
    if (total == 0) {
        printf("\nNenhum filme no catalogo!\n");
        return;
    }
    printf("\n----- Lista de Filmes -----\n");
    // Percorre o vetor de 0 até total - 1
    for (int i = 0; i < total; i++) {
        // Formatações como %-25s reservam 25 caracteres alinhados à esquerda para o nome, deixando a tabela organizada
        printf("ID: %-4d | %-25s | Genero: %-12s | Ano: %d | %d min | Status: %s\n",
               filmes[i].codigo, filmes[i].nome, filmes[i].genero,
               filmes[i].ano, filmes[i].duracao, filmes[i].disponivel ? "Disponivel" : "Indisponivel");
    }
}

// Algoritmo de Busca Linear: procura um filme pelo código e retorna o índice onde ele está guardado
int pesquisarFilme(Filme filmes[], int total, int cod) {
    for (int i = 0; i < total; i++) {
        if (filmes[i].codigo == cod) {
            return i; // Retorna a posição do filme no vetor (ex: 0, 1, 2...)
        }
    }   
    return -1; // Retorna -1 se percorreu todo o vetor e não encontrou nada
}

// Função utilitária rápida: retorna true se o filme existir, ou false caso contrário
bool existeFilme(Filme filmes[], int total, int codigo) {
    return pesquisarFilme(filmes, total, codigo) != -1;
}

// Modifica os dados de um filme já existente
void alterarFilme(Filme filmes[], int total) {
    int cod;
    printf("\n--- Alterar Filme ---\n");
    printf("Digite o codigo do filme que deseja alterar: ");
    scanf("%d", &cod);
    getchar(); // Limpa o buffer para não pular o fgets seguinte

    // Localiza a posição do filme no vetor
    int indice = pesquisarFilme(filmes, total, cod);

    if (indice == -1) {
        printf("Filme nao encontrado.\n");
        return; // Aborta a alteração
    }

    printf("\nEditando o filme: %s\n", filmes[indice].nome);
    
    // Sobrescreve as variáveis correspondentes ao filme localizado no 'indice'
    printf("Novo Titulo: ");
    fgets(filmes[indice].nome, 100, stdin);
    filmes[indice].nome[strcspn(filmes[indice].nome, "\n")] = 0; 

    printf("Novo Genero: ");
    fgets(filmes[indice].genero, 50, stdin);
    filmes[indice].genero[strcspn(filmes[indice].genero, "\n")] = 0;

    printf("Novo Ano: ");
    scanf("%d", &filmes[indice].ano);

    printf("Nova Duracao (min): ");
    scanf("%d", &filmes[indice].duracao);

    int disp;
    printf("Disponivel? (1 - Sim / 0 - Nao): ");
    scanf("%d", &disp);
    filmes[indice].disponivel = (disp == 1);

    printf("\nInformacoes atualizadas com sucesso!\n");
}

// Remove um filme reorganizando as posições do vetor
void removerFilme(Filme filmes[], int *total) {
    int cod;
    printf("\n--- Remover Filme ---\n");
    printf("Digite o codigo do filme a ser removido: ");
    scanf("%d", &cod);

    int indice = pesquisarFilme(filmes, *total, cod);

    if (indice == -1) {
        printf("Filme nao encontrado.\n");
        return;
    }

    // "Puxa" todos os filmes que estão à direita do removido uma posição para a esquerda.
    // Isso apaga o registro indesejado sem deixar um espaço vazio no meio do vetor.
    for (int i = indice; i < (*total) - 1; i++) {
        filmes[i] = filmes[i + 1];
    }

    // Reduz o número de filmes ativos no catálogo diretamente na main()
    (*total)--; 
    printf("\nFilme removido com sucesso!\n");
}

// Mostra apenas os filmes cujo atributo 'disponivel' seja verdadeiro
void listarDisponiveis(Filme filmes[], int total) {
    int cadastradosDisponiveis = quantidadeDisponiveis(filmes, total);
    
    if (cadastradosDisponiveis == 0) {
        printf("\nNao ha filmes disponiveis no momento.\n");
        return;
    }

    printf("\n--- FILMES DISPONIVEIS EM CARTAZ ---\n");
    for (int i = 0; i < total; i++) {
        if (filmes[i].disponivel) { // Verifica se é verdadeiro (igual a 1)
            printf("ID: %-4d | %-25s | Genero: %-12s | %d min\n",
                   filmes[i].codigo, filmes[i].nome, filmes[i].genero, filmes[i].duracao);
        }
    }
}

// Função simples que apenas retorna o número total enviado
int quantidadeFilmes(int total) {
    return total;
}

// Conta individualmente quantos filmes possuem o campo 'disponivel' ativado
int quantidadeDisponiveis(Filme filmes[], int total) {
    int cont = 0;
    for (int i = 0; i < total; i++) {
        if (filmes[i].disponivel) {
            cont++; // Incrementa o contador local
        }
    }
    return cont; // Retorna o valor calculado
}

// Realiza e exibe cálculos rápidos sobre as proporções do catálogo atual
void apresentarEstatisticas(Filme filmes[], int total) {
    printf("\n--- ESTATISTICAS DO CATALOGO ---\n");
    printf("Total de filmes cadastrados: %d\n", quantidadeFilmes(total));
    printf("Total de filmes disponiveis: %d\n", quantidadeDisponiveis(filmes, total));
    
    // Calcula a quantidade de indisponíveis/alugados fazendo uma subtração matemática básica
    int indisponiveis = quantidadeFilmes(total) - quantidadeDisponiveis(filmes, total);
    printf("Total de filmes alugados/indisponiveis: %d\n", indisponiveis);
}
