// Grupo 13, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues
#include "kmp.h" //Como os includes necessários já estão no kmp.h, não é necessário outros includes

int main(){
    FILE *padroesVirus, *baseDadosDna;
    
    
    char dnaVirus[71]; //Variavel que vai receber cada linha do arquivo do virus
    char nomeAnimal[71]; //Variavel que recebe o nome do animal
    char dnaAnimal[71]; //Variavel para receber cada linha do arquivo dos animais
    int linhaVariante = 1; //flag para saber que estou na linha do nome do vírus, pode ser 1 ou -1
    int linhaNomeAnimal = 1;//flag para saber que estou na linha do nome do animal, pode ser 1 ou -1
    Lista *l; //Inicia minha lista que conterá os indices de cada ocorrencia. O primeiro nó guarda a quantidade de ocorrencias

    // Abertura do arquivo PadroesVirus.txt, apenas para leitura, o arquivo deve existir para funcionar.
    padroesVirus = fopen("PadroesVirus.txt", "r");
    if(padroesVirus == NULL){
        printf("Erro, arquivo PadroesVirus nao pode ser aberto!");
        system("pause");
        exit(1);
    }
    

    
    //loop para percorrer o arquivo de virus
    while(strcmp(dnaVirus, ">EOF") != 0){ 
        fgets(dnaVirus, 71, padroesVirus);
        if(dnaVirus[0] == '\n') continue;
        if(linhaVariante == 1){ //Essa linha refere-se ao nome de uma variante do vírus
            linhaVariante *= -1;
            printf("%s", dnaVirus+1);
            continue;
        }
        

        
        baseDadosDna = fopen("BaseDadosDNA.txt", "r"); //Abertura do arquivo "BaseDadosDNA.txt" apenas para leitura, o arquivo deve existir para funcionar. baseDadosDna é o ponteiro do arquivo
        if(baseDadosDna == NULL){
            printf("Erro, arquivo BaseDadosDNA nao pode ser aberto!");
            system("pause");
            exit(1);
        }

        do{//percorrendo o arquivo de animais
            fgets(dnaAnimal, 71, baseDadosDna);
            if(linhaNomeAnimal == 1){//salva o nome do animal e tira o '\n' do final, isso ocorre somente na primeira percorrida do loop
                strcpy(nomeAnimal, dnaAnimal+1); 
                linhaNomeAnimal *= -1;
                nomeAnimal[strcspn(nomeAnimal, "\n")] = '\0';
                continue;
            }
            
            l = criaLista();
            int indiceArquivo = 0; //Variavel para saber qual o número do indíce atual, já que a comparação é feita linha por linha
            insereNo(0, l);//Insere o primeiro nó na lista, sendo este responsavel por ser a variavel contadora
            
            do{//Looping para percorrer todo o dna do animal e fazer as comparações
                
                kmp(dnaAnimal, dnaVirus, l, indiceArquivo); //As posições são colocadas direto na lista de ocorrencias
                fgets(dnaAnimal, 71, baseDadosDna); //Lê a próxima linha do arquivo

                if(strcspn(dnaAnimal, "\n") == 0){ //Lógica para caso a linha contenha somente \n, que sobrou de outra leitura
                    fgets(dnaAnimal, 71, baseDadosDna);
                }
                indiceArquivo += sizeof(dnaAnimal) - 1; //Adicionando o tamanho da linha nova lida, contudo é preciso do -1 por causa do tamanho a mais das variaveis de leitura de linha (+1)
                
            }while (dnaAnimal[0] != '>'); //Caso tenha o símbolo '>' significa que chegou na linha do nome de um novo animal
            
            
            if(l->inicio->chave > 0){ //Caso a variante tenha ocorrencias no animal, o programa faz o print
                printf("[%s]", nomeAnimal);
                printf(" no. de ocorrencias: %d posicoes: ", l->inicio->chave); //Primeiro nó contém a quantidade total de ocorrencias
                No *aux = l->inicio->prox; //Variavel para percorrer a lista, como o primeiro nó não é um indice, ele começa percorrendo a próxima
                
                while(aux != NULL){
                    
                    printf("%d ", aux->chave);
                    aux = aux->prox;
                }
                printf("\n"); //Para formatação correta na saida
            }
            free(l); //Após utilizar a lista, é preciso liberar a memória usada
            
            strcpy(nomeAnimal, dnaAnimal + 1); //Como o padrão de saída é o inicio do nome do animal, é preciso salvar isso na variavel de nome
            nomeAnimal[strcspn(nomeAnimal, "\n")] = '\0';//Retirando o \n do final da string lida

        }while(strcmp(dnaAnimal, ">EOF") != 0); //Caso a última palavra seja ">EOF" o arquivo para. Neste caso é necessário usar pois o começo do nome pode ser E
        //Fecha o arquivo de base de dados e verifica se a operação ocorreu corretamente
        if(fclose(baseDadosDna) != 0){
            perror("Erro ao fechar o arquivo BaseDadosDNA.txt");
            exit(1);
        }
        linhaNomeAnimal *= -1; //Manipulação da flag, proxima linha é o nome do animal
        linhaVariante *= -1;//Manipulação da flag, proxima linha é o nome do virus
        printf("\n"); //Formatação de saida
        

        
    };
    
   
   if(fclose(padroesVirus) != 0){ //fecha o arquivo e verifica se o arquivo foi fechado corretamente
            perror("Erro ao fechar o arquivo PadroesVirus.txt");
            exit(1);
        }

    return 0;
}
