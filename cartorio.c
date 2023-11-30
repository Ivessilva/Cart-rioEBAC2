#include <stdio.h>//biblioteca de comunicação com usuário
#include <stdlib.h>// biblioteca de colocação de espaço em memória
#include <locale.h>//biblioteca de alocaçção de texto por região
#include <string.h> // biblioteca responsável por cuidar das string



int registro() // Funcão responsável por cadastrar os usuarios no sistema

{
	//Inicio da criação de variavel/string
	char arquivo[40];                                                                             
    char cpf[40];  //essa é uma string tipo 40                                                     
    char nome[40];                                                                                
    char sobrenome[40];                                                                           
    char cargo[40];  
	// Final da criação de variavel/string                                                                              
    
    printf(" Digite o Cpf a ser cadastrado: "); // coletando informação do usuario                                                  
    scanf("%s", cpf); //"%s" refere-se ao salvamento da string                                                                             
    
    strcpy(arquivo, cpf); //responsável por copiar os dados no arquivo                             
    
    FILE *file; //procurar estrutura "FILE" para arquivo "file"                                    
    file = fopen(arquivo, "w");//cria o arquivo seguido da escrita com o comando "w"                                                                 
    fprintf(file,cpf); // salva o valor da vareavel                                                 
    fclose(file); //fecha o arquivo                                                                
    
    file = fopen(arquivo,"a"); //acessar e atualizar o arquivo, seguindo a logica é File = fopen>(faça),arquivo> (local, ambiente),"a">(alimente e atualize com novas informações)                                                                       
    fprintf(file,","); // salva o valor da vareavel 
    fclose(file); //fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: ");//mensagem ao usuario
    scanf("%s",nome); //string que escaneia a categoria "nome"
    
    file = fopen(arquivo, "a"); //acessar e atualizar o arquivo, seguindo a logica é File = fopen>(faça),arquivo> (local, ambiente),"a">(alimente e atualize com novas informações)
    fprintf(file,nome);// salva o valor da vareavel "nome"
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); // coletando informação do usuario 
    scanf("%s" ,sobrenome);//string que escaneia a categoria "sobrenome"
    
    file = fopen(arquivo,"a");//acessar e atualizar o arquivo, seguindo a logica é File = fopen>(faça),arquivo> (local, ambiente),"a">(alimente e atualize com novas informações)
    fprintf(file, sobrenome);// salva o valor da vareavel "sobrenome"
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //acessar e atualizar o arquivo, seguindo a logica é File = fopen>(faça),arquivo> (local, ambiente),"a">(alimente e atualize com novas informações)
    fprintf(file,","); // salva o valor da vareavel ","
    fclose(file);//fecha o arquivo	
    
    printf("Digite o cargo a ser cadastrado: "); // coletando informação do usuario 
    scanf("%s", cargo);//string que escaneia a categoria "cargo"
    file = fopen(arquivo, "a");//acessar e atualizar o arquivo, seguindo a logica é File = fopen>(faça),arquivo> (local, ambiente),"a">(alimente e atualize com novas informações)
    fprintf(file, cargo); // salva o valor da vareavel "cargo"
    fclose(file);//fecha o arquivo
    
    
    
    system("pause"); //Pausa o sistema até obter uma resposta   
    
}



int consultar()
{
	 setlocale(LC_ALL, "portuguese");   //Seleção de idioma
	 //inicio da vareavel/string
     char cpf[40];
     char conteudo[200];
     //fim da vareavel/string
     
     printf(" Digite o cpf a ser consultado: ");// mensagem de chamada e coleta de dados
     scanf("%s", cpf); //escanear informações no banco de dados
     
     FILE *file; // aquivo dentro da estrutura
     file = fopen(cpf,"r"); // na pasta arquivo
     if(file == NULL) //comando "se" não tiver a informações na relação do sistema
     {
     	printf("Não foi possível abrir o arquivo, verifique as informações se estão corretas!");// mensagem de retorno de falha
	 }
     
     while(fgets(conteudo,200,file) != NULL)//função de repetição,enquanto
      {
      	printf("\n Essas são as informações do usuário: "); //Mensagem de retorno sobre a consulta
      	printf("%s", conteudo); //string que escaneia a categoria "conteudo"
      	printf("\n\n");
      	
	  }
     
     system("pause");// pausa do sistema até a obtenção de respostas
	
}



int deletar()
{
	//inicio da vareavel/string
    char cpf[40];
    //final da vareavel/string
	printf("Digite o cpf a ser deletado: "); //mensagem para comando
	scanf("%s",cpf); //string que escaneia a categoria "cpf" 
		
	
	remove (cpf); //Comando de remoção do cpf
	
	FILE *file; //aquivo dentro da estrutura
	file = fopen(cpf,"r"); //abrir cpf na estrutura "r"
	
	if(file == NULL) //comando de falha em caso de não encontrar
	{
		printf("O usuario não se encontra no sistema!\n");//mensagem de notificação ao usuário
		system("pause");//pausa do sistema até obtenção de resposta
		
	}
	
}



int main()//Inicio do comando

{
	
	int opcao=0;    // Vareavel de armazenamento (utilizado apenas 1 sinal de igual para tribuição)
	int loop=1;// comando for, para efetuar loop em todo processo de comando, voltando ao inicio sempre que concluir a pesquisa
	
	for(loop=1;loop=1;) //ex:(x=1;x=10;x++) loop de 10 unidades, "x" na formula pode ser substituido pelo nome desejado
	
	{
		
	 system("cls"); //limpar tela

     setlocale(LC_ALL, "portuguese");   //Seleção de idioma
   
      printf("### Cartório IVESSILVA ###\n\n");   //nome do projeto ou titulo de cabeçalho
      printf("Escolha a opção desejada do menu:\n\n");  //Nota de chamada
      printf("\t1 - Registrar Nomes\n");  //opção de menu
      printf("\t2 - Consultar Nomes\n");  //opção de menu
      printf("\t3 - Deletar Nomes\n\n");  //opção de menu
      printf("\t4 - Sair do sistema\n\n");//Opção de teste para interação com o GITHUB
      printf("escolha a opção desejada:");  //Barra de seleção
   
     scanf("%d", &opcao);  // Escanear opção selecionada
      
     system("cls"); //limpa a tela após o preenchimento da opção
   
     switch(opcao)  //uso para compactação do código
     
     //inicio do menu de opções, visão compactada com o comando switch, tambem possivel elaborar esse comando com a funsão "if"
     {
   	case 1:
   		registro();//opção de comando "registro"
   		break;//parada do comando, substitui o comando "system ("pause") dentro da comando switch
   		
   	 case 2:
   	 	consultar();//opção de comando "consulta"
   	    break; //parada do comando, substitui o comando "system ("pause") dentro da comando switch
   		
   	 case 3:
   	 	deletar();//opção de comando "deletar"
   	    break;//parada do comando, substitui o comando "system ("pause") dentro da comando switch
   	    
     case  4:
     	printf("Obrigao por utilizar o sistema!\n");
     	return 0;
     	break;
   	    
   	 default:
   		printf("##Essa opção não está disponível.\n\n Escolha uma das opções destacada acima\n\n");//mensagem de retorno
   	    break;//parada do comando, substitui o comando "system ("pause") dentro da comando switch
   }
 
   }
    
    
   }
   
   
 
  
   
  
   
   
   
   
   
   
   
   
   
   
  

 
   	
   
 
   

   
     
   
   
