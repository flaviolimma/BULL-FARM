#include <iostream>
#include <cstring>
#include <windows.h>
#include <cstdlib>

using namespace std;

struct dados 
{
    int codigo;
    string nome;
    char sexo;
    string raca;
    float peso;
    
    const char* imagem;
};

int mostrarImagem(const char* caminho)
{
    HINSTANCE result = ShellExecuteA
	(
        NULL,
        "open",
        caminho,
        NULL,
        NULL,
        SW_SHOWNORMAL
    );
 
    if ((int)result <= 32) 
	{
        MessageBoxA(NULL, "Falha ao abrir a imagem.", "Erro", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

int main() 
{
    {
        dados vacas[10];
        int qtd = 0, opcao, i, codigoBusca, encontrada = 0;

        do 
        {
            cout << "CODIGO PARA CADASTRO DE VACAS" << endl;
            cout << endl;
            cout << "Escolha uma opcao: " << endl;
            cout << endl;
            cout << "1 - Cadastrar nova vaca" << endl;
            cout << "2 - Listar vacas cadastradas" << endl;
            cout << "3 - Buscar vaca por codigo" << endl;
            cout << "4 - Sair do cadastrado e ver foto do animal" << endl;
            cin >> opcao;
            cout << endl;

            if (opcao == 1) 
            {
                cout << "CADASTRO DE NOVA VACA" << endl;
                cout << endl;
                cout << "Codigo do animal: ";
                cin >> vacas[qtd].codigo;
                cout << endl;

                cout << "Nome: ";
                getline(cin >> ws, vacas[qtd].nome);
                cout << endl;

                cout << "Sexo (M/F): ";
                cin >> vacas[qtd].sexo;
                cout << endl;

                cout << "Raca: ";
                getline(cin>> ws, vacas[qtd].raca);
                cout << endl;

                cout << "Peso (kg): ";
                cin >> vacas[qtd].peso;
                cout << endl;

                qtd++;

                cout << "Animal cadastrado!" << endl;
                cout << endl;
            }

            else if (opcao == 2) 
            {
                cout << "LISTA DE VACAS CADASTRADAS" << endl;
                
      	  	  	  for (i=0; i<qtd; i++)
      	  	  	  {
					cout << endl;
					cout << "Codigo: " << vacas[i].codigo << endl;
					cout << "Nome: " << vacas[i].nome << endl;
					cout << "Sexo: " << vacas[i].sexo << endl;
					cout << "Raca: " << vacas[i].raca << endl;
					cout << "Peso: " << vacas[i].peso << " kg" << endl;
					cout << endl;		
							
	  	  	  	  }	
            }

            else if (opcao == 3) 
            {
                cout << "Digite o codigo da vaca: " << endl;
                cin >> codigoBusca;

                for (i=0; i<qtd; i++) 
                {
                    if (vacas[i].codigo == codigoBusca) 
                    {
                    	cout << endl;
                        cout << "INFORMACOES DO ANIMAL" << endl;
                        cout << endl;
                        cout << "Codigo: " << vacas[i].codigo << endl;
                        cout << "Nome: " << vacas[i].nome << endl;
                        cout << "Sexo: " << vacas[i].sexo << endl;
                        cout << "Raca: " << vacas[i].raca << endl;
                        cout << "Peso: " << vacas[i].peso << " kg" << endl;
                        cout << endl;
                        encontrada = 1;
                        break;
                    }
                }

                if (encontrada == 0) 
                {
                    cout << " Nenhuma vaca foi encontrada com esse codigo." << endl;
                }
            }

            else if (opcao == 4) 
            {
                cout << "Fechar programa" << endl;
            }

            else 
            {
                cout << "Opcao invalida!" << endl;
            }

        } while (opcao != 4);
    }
	
   {
	   const char* holandesa = "imagens\\holandesa.jpeg";
	   const char* gir = "imagens\\gir.jpg";
	   const char* nelore = "imagens\\nelore.jpg";
	   const char* mini = "imagens\\mini.jpg";
		
		int op;
				
	   cout << "Escolha uma opcao para ver a foto do animal: \n\n 1) Holandesa \n 2) Gir \n 3) Nelore \n 4) Mini Vaca" << endl;
	   cin >> op;
		
	   if (op == 1) mostrarImagem(holandesa);
	   if (op == 2) mostrarImagem(gir);
	   if (op == 3) mostrarImagem(nelore);
	   if (op == 4) mostrarImagem(mini);
   }

    return 0;
}