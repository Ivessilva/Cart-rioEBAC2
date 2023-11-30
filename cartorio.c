#include <stdio.h>//biblioteca de comunica��o com usu�rio
#include <stdlib.h>// biblioteca de coloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca���o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string



int registro() // Func�o respons�vel por cadastrar os usuarios no sistema

{
	//Inicio da cria��o de variavel/string
	char arquivo[40];                                                                             
    char cpf[40];  //essa � uma string tipo 40                                                     
    char nome[40];                                                                                
    char sobrenome[40];                                                                           
    char cargo[40];  
	// Final da cria��o de variavel/string                                                                              
    
    printf(" Digite o Cpf a ser cadastrado: "); // coletando informa��o do usuario                                                  
    scanf("%s", cpf); //"%s" refere-se ao salvamento da string                                                                             
    
    strcpy(arquivo, cpf); //respons�vel por copiar os dados no arquivo                             
    
    FILE *file; //procurar estrutura "FILE" para arquivo "file"                                    
    file = fopen(arquivo, "w");//cria o arquivo seguido da escrita com o comando "w"                                                                 
    fprintf(file,cpf); // salva o valor da vareavel                                                 
    fclose(file); //fecha o arquivo                                                                
    
    file = fopen(arquivo,"a"); //acessar e atualizar o arquivo, seguindo a logica � File = fopen>(fa�a),arquivo> (local, ambiente),"a">(alimente e atualize com novas informa��es)                                                                       
    fprintf(file,","); // salva o valor da vareavel 
    fclose(file); //fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: ");//mensagem ao usuario
    scanf("%s",nome); //string que escaneia a categoria "nome"
    
    file = fopen(arquivo, "a"); //acessar e atualizar o arquivo, seguindo a logica � File = fopen>(fa�a),arquivo> (local, ambiente),"a">(alimente e atualize com novas informa��es)
    fprintf(file,nome);// salva o valor da vareavel "nome"
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); // coletando informa��o do usuario 
    scanf("%s" ,sobrenome);//string que escaneia a categoria "sobrenome"
    
    file = fopen(arquivo,"a");//acessar e atualizar o arquivo, seguindo a logica � File = fopen>(fa�a),arquivo> (local, ambiente),"a">(alimente e atualize com novas informa��es)
    fprintf(file, sobrenome);// salva o valor da vareavel "sobrenome"
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //acessar e atualizar o arquivo, seguindo a logica � File = fopen>(fa�a),arquivo> (local, ambiente),"a">(alimente e atualize com novas informa��es)
    fprintf(file,","); // salva o valor da vareavel ","
    fclose(file);//fecha o arquivo	
    
    printf("Digite o cargo a ser cadastrado: "); // coletando informa��o do usuario 
    scanf("%s", cargo);//string que escaneia a categoria "cargo"
    file = fopen(arquivo, "a");//acessar e atualizar o arquivo, seguindo a logica � File = fopen>(fa�a),arquivo> (local, ambiente),"a">(alimente e atualize com novas informa��es)
    fprintf(file, cargo); // salva o valor da vareavel "cargo"
    fclose(file);//fecha o arquivo
    
    
    
    system("pause"); //Pausa o sistema at� obter uma resposta   
    
}



int consultar()
{
	 setlocale(LC_ALL, "portuguese");   //Sele��o de idioma
	 //inicio da vareavel/string
     char cpf[40];
     char conteudo[200];
     //fim da vareavel/string
     
     printf(" Digite o cpf a ser consultado: ");// mensagem de chamada e coleta de dados
     scanf("%s", cpf); //escanear informa��es no banco de dados
     
     FILE *file; // aquivo dentro da estrutura
     file = fopen(cpf,"r"); // na pasta arquivo
     if(file == NULL) //comando "se" n�o tiver a informa��es na rela��o do sistema
     {
     	printf("N�o foi poss�vel abrir o arquivo, verifique as informa��es se est�o corretas!");// mensagem de retorno de falha
	 }
     
     while(fgets(conteudo,200,file) != NULL)//fun��o de repeti��o,enquanto
      {
      	printf("\n Essas s�o as informa��es do usu�rio: "); //Mensagem de retorno sobre a consulta
      	printf("%s", conteudo); //string que escaneia a categoria "conteudo"
      	printf("\n\n");
      	
	  }
     
     system("pause");// pausa do sistema at� a obten��o de respostas
	
}



int deletar()
{
	//inicio da vareavel/string
    char cpf[40];
    //final da vareavel/string
	printf("Digite o cpf a ser deletado: "); //mensagem para comando
	scanf("%s",cpf); //string que escaneia a categoria "cpf" 
		
	
	remove (cpf); //Comando de remo��o do cpf
	
	FILE *file; //aquivo dentro da estrutura
	file = fopen(cpf,"r"); //abrir cpf na estrutura "r"
	
	if(file == NULL) //comando de falha em caso de n�o encontrar
	{
		printf("O usuario n�o se encontra no sistema!\n");//mensagem de notifica��o ao usu�rio
		system("pause");//pausa do sistema at� obten��o de resposta
		
	}
	
}



int main()//Inicio do comando

{
	
	int opcao=0;    // Vareavel de armazenamento (utilizado apenas 1 sinal de igual para tribui��o)
	int loop=1;// comando for, para efetuar loop em todo processo de comando, voltando ao inicio sempre que concluir a pesquisa
	
	for(loop=1;loop=1;) //ex:(x=1;x=10;x++) loop de 10 unidades, "x" na formula pode ser substituido pelo nome desejado
	
	{
		
	 system("cls"); //limpar tela

     setlocale(LC_ALL, "portuguese");   //Sele��o de idioma
   
      printf("### Cart�rio IVESSILVA ###\n\n");   //nome do projeto ou titulo de cabe�alho
      printf("Escolha a op��o desejada do menu:\n\n");  //Nota de chamada
      printf("\t1 - Registrar Nomes\n");  //op��o de menu
      printf("\t2 - Consultar Nomes\n");  //op��o de menu
      printf("\t3 - Deletar Nomes\n\n");  //op��o de menu
      printf("\t4 - Sair do sistema\n\n");//Op��o de teste para intera��o com o GITHUB
      printf("escolha a op��o desejada:");  //Barra de sele��o
   
     scanf("%d", &opcao);  // Escanear op��o selecionada
      
     system("cls"); //limpa a tela ap�s o preenchimento da op��o
   
     switch(opcao)  //uso para compacta��o do c�digo
     
     //inicio do menu de op��es, vis�o compactada com o comando switch, tambem possivel elaborar esse comando com a funs�o "if"
     {
   	case 1:
   		registro();//op��o de comando "registro"
   		break;//parada do comando, substitui o comando "system ("pause") dentro da comando switch
   		
   	 case 2:
   	 	consultar();//op��o de comando "consulta"
   	    break; //parada do comando, substitui o comando "system ("pause") dentro da comando switch
   		
   	 case 3:
   	 	deletar();//op��o de comando "deletar"
   	    break;//parada do comando, substitui o comando "system ("pause") dentro da comando switch
   	    
     case  4:
     	printf("Obrigao por utilizar o sistema!\n");
     	return 0;
     	break;
   	    
   	 default:
   		printf("##Essa op��o n�o est� dispon�vel.\n\n Escolha uma das op��es destacada acima\n\n");//mensagem de retorno
   	    break;//parada do comando, substitui o comando "system ("pause") dentro da comando switch
   }
 
   }
    
    
   }
   
   
 
  
   
  
   
   
   
   
   
   
   
   
   
   
  

 
   	
   
 
   

   
     
   
   
