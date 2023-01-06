#include <bits/stdc++.h>

#include "../headers/Ler.h"

using namespace std;

Ler lfile;
Graph g;

void clearScreen();

void wait() {
    cout << endl;
    int c; do c = getchar(); while ((c != '\n') && (c != EOF));
    cout << "Pressione ENTER para continuar...";
    cout << endl;
    do{ c = getchar(); }while ((c != '\n') && (c != EOF));
}

// Checks
bool checkInteiro(const string& s);
bool checkAeroporto(const string& s);
bool checkCidade(const string& s);
bool checkPais(const string& s);

// Other Menu Functions
void menu_me_aerop_dest(const string& aerop);

// Prints de Menu Informacao
void print_info_aeroporto(int id, const Aeroporto& aeroporto, string aerop);
void print_info_cidade(const string& cidade);
void print_info_aeroporto_cidade(const string& cidade);
void print_info_aeroporto_cidade_pais(const string& cidade, const string& pais);
void print_info_pais(const string& pais);
void print_info_aeroporto_pais(const string& pais, vector<int> aeroportos);

//void print_voo_me(vector<int> voo);



int main(){

    system("Color 09");

    lfile.ler_aeroportos();
    g = Graph((int) lfile.getAeroportos().size());
    lfile.ler_companhias();
    lfile.ler_voos(g);


    int choice;
    string op_menu;
    string aerop, cidade, pais;

    // Variaveis para o menu 1 - 1
    Aeroporto aeroporto;
    int id;



    do {
        clearScreen();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "||------------------------ MENU -------------------------||" << endl;
        cout << "|| Escolha uma opcao:                                    ||" << endl;
        cout << "||_______________________________________________________||" << endl;
        cout << "||                                                       ||" << endl;
        cout << "||   1 - Informacoes                                     ||" << endl;
        cout << "||   2 - Pesquisa                                        ||" << endl;
        cout << "||   3 - Estatisticas                                    ||" << endl;
        cout << "||                                                       ||" << endl;
        cout << "||   0 - Sair                                            ||" << endl;
        cout << "||                                                       ||" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;



        cin >> op_menu;

        while(!checkInteiro(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 3){
            cout << endl;
            cout << "Opcao invalida! Tente novamente: ";
            cin >> op_menu;
            cout << endl;
        }

        choice = stoi(op_menu);
        cout << endl;

        switch (choice) {

            case 0:

                choice = 0;
                break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            case 1:

                int ch1;
                choice = 1;

                do{
                    clearScreen();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||------------------------ INFO -------------------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - De um Aeroporto                                 ||" << endl;
                    cout << "||   2 - De uma Cidade                                   ||" << endl;
                    cout << "||   3 - De um Pais                                      ||" << endl;
                    cout << "||   4 - De um raio de X Km de uma coordenada            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Sair                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> op_menu;

                    while(!checkInteiro(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 4){
                        cout << endl;
                        cout << "Opcao invalida! Tente novamente: ";
                        cin >> op_menu;
                        cout << endl;
                    }

                    ch1 = stoi(op_menu);

                    switch (ch1) {

                        case 0:

                            ch1 = 0;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 1:

                            cout << "Aeroporto: ";
                            cin >> aerop;

                            while(!checkAeroporto(aerop)){
                                clearScreen();
                                cout << endl;
                                cout << "Aeroporto invalido! Tente novamente: ";
                                cin >> aerop;
                                cout << endl;
                            }

                            transform(aerop.begin(), aerop.end(), aerop.begin(), ::toupper);

                            id = lfile.getAeroportosCodigos()[aerop];
                            aeroporto = lfile.getAeroportos().at(id);

                            print_info_aeroporto(id, aeroporto, aerop);

                            ch1 = 1;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 2:

                            cout << "Cidade: ";
                            cin >> cidade;

                            while(!checkCidade(cidade)){
                                clearScreen();
                                cout << endl;
                                cout << "Cidade invalida! Tente novamente: ";
                                cin >> cidade;
                                cout << endl;
                            }

                            transform(cidade.begin(), cidade.end(), cidade.begin(), ::toupper);

                            print_info_cidade(cidade);

                            ch1 = 2;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 3:

                            cout << "Pais: ";
                            getline(cin >> ws, pais);

                            while(!checkPais(pais)){
                                clearScreen();
                                cout << endl;
                                cout << "Pais invalido! Tente novamente: ";
                                cin >> pais;
                                cout << endl;
                            }

                            transform(pais.begin(), pais.end(), pais.begin(), ::toupper);

                            print_info_pais(pais);

                            ch1 = 3;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 4:

                            ch1 = 4;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        default:
                            clearScreen();
                            cout << "Opcao invalida! Tente novamente." << endl;
                            wait();
                            break;
                    }

                } while (ch1 != 0);
                break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


            case 2:

                int ch2;
                choice = 2;

                do{
                    clearScreen();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||---------------------- PESQUISA -----------------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Rota com menos escalas                          ||" << endl;
                    cout << "||   2 - Rota com menos distancia percorrida             ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Sair                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> op_menu;

                    while(!checkInteiro(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 2){
                        cout << endl;
                        cout << "Opcao invalida! Tente novamente: ";
                        cin >> op_menu;
                        cout << endl;
                    }

                    ch2 = stoi(op_menu);

                    switch (ch2) {

                        case 0:

                            ch2 = 0;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 1:

                            ch2 = 1;
                            int ch2_1;

                            do{
                                clearScreen();
                                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                cout << "||---------------------- PESQUISA -----------------------||" << endl;
                                cout << "|| Origem do Voo:                        (Menos Escalas) ||" << endl;
                                cout << "||_______________________________________________________||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   1 - Um Aeroporto                                    ||" << endl;
                                cout << "||   2 - Uma Cidade                                      ||" << endl;
                                cout << "||   3 - Um Pais                                         ||" << endl;
                                cout << "||   4 - O ponto mais proximo de umas coordenadas        ||" << endl;
                                cout << "||   5 - Todos os pontos num raio de X Km                ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   0 - Sair                                            ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                cout << endl;

                                cin >> op_menu;

                                while(!checkInteiro(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 5){
                                    cout << endl;
                                    cout << "Opcao invalida! Tente novamente: ";
                                    cin >> op_menu;
                                    cout << endl;
                                }

                                ch2_1 = stoi(op_menu);

                                switch (ch2_1) {

                                    case 0:

                                        ch2_1 = 0;
                                        break;

/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 1:

                                        cout << "Aeroporto: ";
                                        cin >> aerop;

                                        while(!checkAeroporto(aerop)){
                                            clearScreen();
                                            cout << endl;
                                            cout << "Aeroporto invalido! Tente novamente: ";
                                            cin >> aerop;
                                            cout << endl;
                                        }

                                        transform(aerop.begin(), aerop.end(), aerop.begin(), ::toupper);

                                        menu_me_aerop_dest(aerop);

                                        ch2_1 = 1;
                                        break;

/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 2:

                                        cout << "Cidade: ";
                                        cin >> cidade;

                                        while(!checkCidade(cidade)){
                                            clearScreen();
                                            cout << endl;
                                            cout << "Cidade invalida! Tente novamente: ";
                                            cin >> cidade;
                                            cout << endl;
                                        }

                                        transform(cidade.begin(), cidade.end(), cidade.begin(), ::toupper);

                                        ch2_1 = 2;
                                        break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 3:

                                        cout << "Pais: ";
                                        cin >> pais;

                                        while(!checkPais(pais)){
                                            clearScreen();
                                            cout << endl;
                                            cout << "Pais invalido! Tente novamente: ";
                                            cin >> pais;
                                            cout << endl;
                                        }

                                        transform(pais.begin(), pais.end(), pais.begin(), ::toupper);

                                        ch2_1 = 3;
                                        break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 4:

                                        ch2_1 = 4;
                                        break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 5:

                                        ch2_1 = 5;
                                        break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/

                                    default:
                                        clearScreen();
                                        cout << "Opcao invalida! Tente novamente." << endl;
                                        wait();
                                        break;

                                }

                            } while (ch2_1 != 0);

                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 2:

                            ch2 = 2;
                            int ch2_2;

                            do{
                                clearScreen();
                                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                cout << "||---------------------- PESQUISA -----------------------||" << endl;
                                cout << "|| Origem do Voo:                      (Menos Distancia) ||" << endl;
                                cout << "||_______________________________________________________||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   1 - Um Aeroporto                                    ||" << endl;
                                cout << "||   2 - Uma Cidade                                      ||" << endl;
                                cout << "||   3 - Um Pais                                         ||" << endl;
                                cout << "||   4 - O ponto mais proximo de umas coordenadas        ||" << endl;
                                cout << "||   5 - Todos os pontos num raio de X Km                ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   0 - Sair                                            ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                cout << endl;

                                cin >> op_menu;

                                while(!checkInteiro(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 5){
                                    cout << endl;
                                    cout << "Opcao invalida! Tente novamente: ";
                                    cin >> op_menu;
                                    cout << endl;
                                }

                                ch2_2 = stoi(op_menu);

                            } while (ch2_2 != 0);

                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        default:
                            clearScreen();
                            cout << "Opcao invalida!" << endl;
                            wait();
                            break;
                    }

                } while (ch2 != 0);

                break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            case 3:

                choice = 3;
                int ch3;

                do{
                    clearScreen();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||-------------------- ESTATISTICAS ---------------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Globais                                         ||" << endl;
                    cout << "||   2 - De um Pais                                      ||" << endl;
                    cout << "||   3 - De uma Cidade                                   ||" << endl;
                    cout << "||   4 - De um Aeroporto                                 ||" << endl;
                    cout << "||   5 - Pontos de Articulacao                           ||" << endl;
                    cout << "||   6 - Componentes Fortemente Conexos                  ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Sair                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> op_menu;

                    while(!checkInteiro(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 6){
                        cout << endl;
                        cout << "Opcao invalida! Tente novamente: ";
                        cin >> op_menu;
                        cout << endl;
                    }

                    ch3= stoi(op_menu);

                } while (ch3 != 0);

                break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            default:
                clearScreen();
                cout << "Opcao invalida!" << endl;
                wait();
                break;
        }


    } while (choice != 0);


    return 0;
}


// Checks

bool checkInteiro(const string& s){

    for(auto y : s){
        if(!isdigit(y)){
            return false;
        }
    }
    return true;
}

bool checkAeroporto(const string& s){

    string aerop = s;

    transform(aerop.begin(), aerop.end(), aerop.begin(), ::toupper);

    unordered_map<string, int> check = lfile.getAeroportosCodigos();

    if(check.find(aerop) == check.end()){
        clearScreen();
        cout << "Aeroporto nao existe!" << endl;
        wait();
        return false;
    }

    return true;
}

bool checkCidade(const string& s){

    string cidade = s;

    transform(cidade.begin(), cidade.end(), cidade.begin(), ::toupper);

    unordered_map<string, vector<int>> check = lfile.getCidadesAeroportos();

    if(check.find(cidade) == check.end()){
        clearScreen();
        cout << "Cidade nao existe!" << endl;
        wait();
        return false;
    }

    return true;
}

bool checkPais(const string& s){

    string pais = s;

    transform(pais.begin(), pais.end(), pais.begin(), ::toupper);

    unordered_map<string, unordered_set<string>> check = lfile.getPaisCidades();

    if(check.find(pais) == check.end()){
        clearScreen();
        cout << "Pais nao existe!" << endl;
        wait();
        return false;
    }

    return true;
}

// Other Menu Functions

void menu_me_aerop_dest(const string& aerop){

    string op_menu;


    string aerop_destino;
    int origem = lfile.getAeroportosCodigos().find(aerop)->second;
    int destino;

    clearScreen();
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||---------------------- PESQUISA -----------------------||" << endl;
    cout << "|| Destino do Voo:                       (Menos Escalas) ||" << endl;
    cout << "||_______________________________________________________||" << endl;
    cout << "||                                                       ||" << endl;
    cout << "||   1 - Um Aeroporto                                    ||" << endl;
    cout << "||   2 - Uma Cidade                                      ||" << endl;
    cout << "||   3 - Um Pais                                         ||" << endl;
    cout << "||   4 - O ponto mais proximo de umas coordenadas        ||" << endl;
    cout << "||   5 - Todos os pontos num raio de X Km                ||" << endl;
    cout << "||                                                       ||" << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << endl;

    cin >> op_menu;

    while(!checkInteiro(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 5){
        cout << endl;
        cout << "Opcao invalida! Tente novamente: ";
        cin >> op_menu;
        cout << endl;
    }

    int ch = stoi(op_menu);

    switch (ch) {

        case 1:

            cout << "Aeroporto: ";
            cin >> aerop_destino;

            while(!checkAeroporto(aerop_destino)){
                clearScreen();
                cout << endl;
                cout << "Aeroporto invalido! Tente novamente: ";
                cin >> aerop_destino;
                cout << endl;
            }

            transform(aerop_destino.begin(), aerop_destino.end(), aerop_destino.begin(), ::toupper);



            destino = lfile.getAeroportosCodigos().find(aerop_destino)->second;


            clearScreen();
            cout << "===========================================================" << endl;
            cout << "|                                                         |" << endl;
            cout << "|   Deseja viajar em alguma Companhia especifica? s/n     |" << endl;
            cout << "|                                                         |" << endl;
            cout << "===========================================================" << endl;
            cout << endl;
            cout << "Opcao: ";
            cin >> op_menu;

            while(op_menu != "s" && op_menu != "n" && op_menu != "S" && op_menu != "N"){
                cout << endl;
                cout << "Opcao invalida! Tente novamente: ";
                cin >> op_menu;
                cout << endl;
            }

            if(op_menu == "s" || op_menu == "S"){
                set<string> companhias;
                string companhia;

                cout << "Indique as companhias que deseja, no fim escreva done: " << endl;
                while(cin >> companhia && companhia != "done" && companhia != "DONE"){
                    if(lfile.getCompanhiasCodigos().find(companhia) != lfile.getCompanhiasCodigos().end()){
                        companhias.insert(companhia);
                    }
                    else{
                        cout << "Companhia nao existe! Tente novamente: ";
                    }
                }

                vector<int> voo_companhia = g.bfs_me_companhias(origem, destino, companhias);

                if(voo_companhia.empty()){
                    clearScreen();
                    cout << "Nao existe voo entre os aeroportos indicados usando estas companhias: " << endl;
                    cout << endl;
                    cout << "Aeroporto de Origem: ["<< lfile.getAeroportos().find(origem)->second.getCodigo() << "] - " << lfile.getAeroportos().find(origem)->second.getNome() << endl;
                    cout << "Aeroporto de Destino: ["<< lfile.getAeroportos().find(destino)->second.getCodigo() << "] - " << lfile.getAeroportos().find(destino)->second.getNome() << endl;
                    cout << endl;
                    cout << "Companhias: " << endl;
                    for(const auto & comp : companhias){
                        cout << "  -> [" << comp << "] - " << lfile.getCompanhias().find(lfile.getCompanhiasCodigos().find(comp)->second)->second.getNome() << endl;
                    }
                    wait();
                    break;
                }

                clearScreen();
                cout << "Um caminho possivel:" << endl;
                cout << endl;
                cout << lfile.getAeroportos().find(origem)->second.getCodigo() << " -> ";
                for(int i = (int) voo_companhia.size()-1; i >= 0; i--){
                    if(i == 0){
                        cout << lfile.getAeroportos().find(destino)->second.getCodigo() << endl;
                    }
                    else{
                        cout << lfile.getAeroportos().find(voo_companhia[i])->second.getCodigo() << " -> ";
                    }
                }
                wait();

            }
            else {

                vector<int> voo = g.bfs_me(origem, destino);

                clearScreen();
                cout << "Um caminho possivel:" << endl;
                cout << endl;
                cout << lfile.getAeroportos().find(origem)->second.getCodigo() << " -> ";
                for (int i = (int) voo.size() - 1; i >= 0; i--) {
                    if (i == 0) {
                        cout << lfile.getAeroportos().find(destino)->second.getCodigo() << endl;
                    } else {
                        cout << lfile.getAeroportos().find(voo[i])->second.getCodigo() << " -> ";
                    }
                }
                wait();
            }
            //print_voo_me(voo);

            break;

        case 2:

            cout << "Cidade: ";

            break;

        default:
            break;

    }


}

// Prints de Menu Informacao

void print_info_aeroporto(int id, const Aeroporto& aeroporto, string aerop){

    int voos = 0;
    int companhias;
    unordered_map<string, int> companhias_num_aeroporto;
    unordered_map<string, int> paises_num_aeroporto;
    int destinos;
    int paises;

    transform(aerop.begin(), aerop.end(), aerop.begin(), ::toupper);

    for(auto& ligacao : g.nodes[id].adj) {
        voos += (int) ligacao.companhias.size();
    }

    for(auto& ligacao : g.nodes[id].adj) {
        int aer = ligacao.dest;
        auto it = lfile.getAeroportos().find(aer);
        string pais = it->second.getPais();
        paises_num_aeroporto[pais]++;
    }
    paises = (int) paises_num_aeroporto.size();

    companhias = (int) lfile.getAeroportosCompanhias()[aerop].size();
    destinos = (int) g.nodes[id].adj.size();


    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "|  Aeroporto escolhido: " + aerop + "                               |" << endl;
    cout << "===========================================================" << endl;
    cout << "                                                           " << endl;
    cout << "   Nome:   " + aeroporto.getNome()                         << endl;
    cout << "   Cidade: " + aeroporto.getCidade()                       << endl;
    cout << "   Pais:   " + aeroporto.getPais()                         << endl;
    cout << "   Numero total de voos: " << voos                         << endl;
    cout << "   Numero de Companhias aereas: " << companhias            << endl;
    cout << "   Destinos: " << destinos                                 << endl;
    cout << "   Paises: " << paises                                     << endl;
    cout << "                                                           " << endl;
    cout << "===========================================================" << endl;
    cout << endl;

    wait();
}

void print_info_cidade(const string& cidade){


    string opcao;
    int pais_escolhido;
    int num_aeroportos;
    string nome_pais;
    vector<string> countries;

    for(auto& elem : lfile.getPaisCidades()) {
        for(auto& city : elem.second) {
            if(city == cidade) {
                countries.push_back(elem.first);
            }
        }
    }

    //Quando existem cidades com o mesmo nome em paises diferentes
    if (countries.size() > 1) {
        clearScreen();
        cout << "===========================================================" << endl;
        cout << "|------------------------- INFO --------------------------|" << endl;
        cout << "  Existem " << countries.size() << " paises com a cidade " + cidade + "                  " << endl;
        cout << "===========================================================" << endl;
        cout << "                                                       " << endl;
        cout << "  Escolha o pais:                                      " << endl;
        cout << "                                                       " << endl;
        for(int i = 0; i < countries.size(); i++) {
            cout << "  " << i+1 << " - " << countries[i] << endl;
        }
        cout << "                                                       " << endl;
        cout << "===========================================================" << endl;
        cout << endl;

        cout << "Opcao: ";
        cin >> pais_escolhido;

        while(!checkInteiro(to_string(pais_escolhido)) || pais_escolhido < 1 || pais_escolhido > countries.size()){
            cout << endl;
            cout << "Opcao invalida! Tente novamente: ";
            cin >> pais_escolhido;
            cout << endl;
        }

        nome_pais = countries[pais_escolhido-1];

        pair<string, string> pais_cidade = make_pair(nome_pais, cidade);

        num_aeroportos = (int) lfile.getPaisCidadeAeroportos().find(pais_cidade)->second.size();

        clearScreen();
        cout << "===========================================================" << endl;
        cout << "|------------------------- INFO --------------------------|" << endl;
        cout << "   Cidade escolhido: " + cidade +     "                                 " << endl;
        cout << "===========================================================" << endl;
        cout << "                                                       " << endl;
        cout << "   Pais: " + nome_pais << endl;
        cout << "   Numero de aeroportos: " << num_aeroportos << endl;
        cout << "                                                       " << endl;
        cout << "===========================================================" << endl;
        cout << "|                                                         |" << endl;
        cout << "|   Deseja listar os aeroportos? s/n                      |" << endl;
        cout << "|                                                         |" << endl;
        cout << "===========================================================" << endl;
        cout << endl;

        cout << "Opcao: ";
        cin >> opcao;

        while(opcao != "s" && opcao != "n" && opcao != "S" && opcao != "N"){
            cout << endl;
            cout << "Opcao invalida! Tente novamente: ";
            cin >> opcao;
            cout << endl;
        }

        if(opcao == "s" || opcao == "S") print_info_aeroporto_cidade_pais(cidade, nome_pais);
    }
    else {
        nome_pais = countries[0];

        num_aeroportos = (int) lfile.getCidadesAeroportos().find(cidade)->second.size();

        clearScreen();
        cout << "===========================================================" << endl;
        cout << "|------------------------- INFO --------------------------|" << endl;
        cout << "   Cidade escolhido: " + cidade + "                                 " << endl;
        cout << "===========================================================" << endl;
        cout << "                                                       " << endl;
        cout << "   Pais: " + nome_pais << endl;
        cout << "   Numero de aeroportos: " << num_aeroportos << endl;
        cout << "                                                       " << endl;
        cout << "===========================================================" << endl;
        cout << "|                                                         |" << endl;
        cout << "|   Deseja listar os aeroportos? s/n                      |" << endl;
        cout << "|                                                         |" << endl;
        cout << "===========================================================" << endl;
        cout << endl;

        cout << "Opcao: ";
        cin >> opcao;

        while(opcao != "s" && opcao != "n" && opcao != "S" && opcao != "N"){
            cout << endl;
            cout << "Opcao invalida! Tente novamente: ";
            cin >> opcao;
            cout << endl;
        }

        if(opcao == "s" || opcao == "S") print_info_aeroporto_cidade(cidade);

    }

}

void print_info_aeroporto_cidade_pais(const string& cidade, const string& pais){

    pair<string, string> pais_cidade = make_pair(pais, cidade);

    vector<int> aeroportos = lfile.getPaisCidadeAeroportos().find(pais_cidade)->second;

    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "   Cidade escolhida: " + cidade + ", do pais : "+ pais + "                               " << endl;
    cout << "===========================================================" << endl;
    cout << "                                                       " << endl;
    cout << "   Numero de aeroportos: " << aeroportos.size() << endl;
    cout << "                                                       " << endl;

    for(int i = 0; i < aeroportos.size(); i++){
        cout << "   Aeroporto " << i+1 << ": " << lfile.getAeroportos().find(aeroportos[i])->second.getCodigo() << " - "  << lfile.getAeroportos().find(aeroportos[i])->second.getNome() << endl;
    }

    cout << "                                                           " << endl;
    cout << "===========================================================" << endl;

    wait();

}

void print_info_aeroporto_cidade(const string& cidade){

    vector<int> aeroportos = lfile.getCidadesAeroportos().find(cidade)->second;

    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "   Cidade escolhida: " + cidade + "                                 " << endl;
    cout << "===========================================================" << endl;
    cout << "                                                       " << endl;
    cout << "   Numero de aeroportos: " << aeroportos.size() << endl;
    cout << "                                                       " << endl;

    for(int i = 0; i < aeroportos.size(); i++){
        cout << "   Aeroporto " << i+1 << ": " << lfile.getAeroportos().find(aeroportos[i])->second.getCodigo() << " - "  << lfile.getAeroportos().find(aeroportos[i])->second.getNome() << endl;
    }

    cout << "                                                           " << endl;
    cout << "===========================================================" << endl;

    wait();

}

void print_info_pais(const string& pais){

    string opcao;

    unordered_set<string> cidades = lfile.getPaisCidades().find(pais)->second;

    vector<string> cidades_v(cidades.begin(), cidades.end());

    vector<int> aeroportos;

    vector<pair<string, string>> pais_cidade;

    for(int i = 0; i < cidades_v.size(); i++){
        pais_cidade.emplace_back(pais, cidades_v[i]);
        cout<<pais_cidade[i].first<<" "<<pais_cidade[i].second<<endl;
    }

    for(const auto& i : pais_cidade){
        vector<int> tmp = lfile.getPaisCidadeAeroportos().find(i)->second;
        aeroportos.insert(aeroportos.end(), tmp.begin(), tmp.end());
    }

    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "   Pais escolhido: " + pais + "                                 " << endl;
    cout << "===========================================================" << endl;
    cout << "                                                       " << endl;
    cout << "   Numero de cidades: " << cidades.size() << endl;
    cout << "   Numero de aeroportos: "  << aeroportos.size() << endl;
    cout << "                                                           " << endl;
    cout << "===========================================================" << endl;
    cout << "|                                                         |" << endl;
    cout << "|   Deseja listar os aeroportos? s/n                      |" << endl;
    cout << "|                                                         |" << endl;
    cout << "===========================================================" << endl;
    cout << endl;


    cout << "Opcao: ";
    cin >> opcao;

    while(opcao != "s" && opcao != "n" && opcao != "S" && opcao != "N"){
        cout << endl;
        cout << "Opcao invalida! Tente novamente: ";
        cin >> opcao;
        cout << endl;
    }

    if(opcao == "s" || opcao == "S") print_info_aeroporto_pais(pais, aeroportos);

}

void print_info_aeroporto_pais(const string& pais, vector<int> aeroportos){

    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "   Pais escolhido: " + pais + "                                 " << endl;
    cout << "===========================================================" << endl;
    cout << "                                                       " << endl;
    cout << "   Numero de aeroportos: " << aeroportos.size() << endl;
    cout << "                                                       " << endl;

    for(int i = 0; i < aeroportos.size(); i++){
        cout << "   Aeroporto " << i+1 << ": " << lfile.getAeroportos().find(aeroportos[i])->second.getCodigo() << " - "  << lfile.getAeroportos().find(aeroportos[i])->second.getNome() << endl;
    }

    cout << "                                                           " << endl;
    cout << "===========================================================" << endl;

    wait();

}

void clearScreen() {
    for (int i = 0; i < 50; i++) {
        cout << endl;
    }
}