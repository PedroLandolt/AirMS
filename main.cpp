/*! \file */

/**
 * @brief Ficheiro onde estão implementados os diferentes menus com as funcionalidades pedidas no enunciado do projeto
 */

#include <bits/stdc++.h>

#include "../headers/Ler.h"

using namespace std;

Ler lfile;
Graph g;

void clearScreen();
void wait();

// Checks
bool checkInteiro(const string& s);
bool checkAeroporto(const string& s);
bool checkCidade(const string& s);
bool checkPais(const string& s);
bool checkCoordenadas(double lat, double lon);
bool checkRaio(const string& s);
bool checkDouble(const string& s);
vector<int> checkPaisCidade(const string& cidade);

// Other Menu Functions
void menu_me_aerop_dest(const string& aerop);
vector<int> aeroportos_pais(const string& pais);
string aeroporto_mais_proximo(double lat, double lon);
vector<int> aeroportos_num_raio_x(double lat, double lon, double raio);

// Prints de Menu Informacao
void print_info_aeroporto(int id, const Aeroporto& aeroporto, string aerop);
void print_info_cidade(const string& cidade);
void print_info_aeroporto_cidade(const string& cidade);
void print_info_aeroporto_cidade_pais(const string& cidade, const string& pais);
void print_info_pais(const string& pais);
void print_info_aeroporto_pais(const string& pais, vector<int> aeroportos);
void print_info_aeroporto_num_raio_x(double latitude, double longitude, double raio);
void print_voos(int origem, int destino);


int main(){

    system("Color 09");

    lfile.ler_aeroportos();
    g = Graph((int) lfile.getAeroportos().size());
    lfile.ler_companhias();
    lfile.ler_voos(g);

    int diametro = g.diametro();

    // vector<int> aeroportos com maximo de voos
    vector<pair<int,int>> aeroportos_max_voos; //partida e chegada

    for(int x = 1; x <= g.n; x++) {
        g.bfs(x);
        for (int i = 1; i <= g.n; i++) {
            if (g.nodes[i].distance == diametro) {
                pair<int,int> aeroporto = make_pair(x,i);
                aeroportos_max_voos.push_back(aeroporto);
            }
        }
    }



    int choice;
    string op_menu;
    string aerop, cidade, pais;

    // Variaveis para o menu 1 - 1
    Aeroporto aeroporto;
    int id;

    // Variaveis para o menu 1 - 4
    double lat, lon;
    double raio;
    string raio_s;

    string batata;

    vector<int> pais_cidade;
    vector<int> aeroportos_pais_v;
    vector<int> aeroportos_raio;

    vector<pair<int,string>> aeroportos_companhias;

    vector<pair<string, int>> voos_por_aeroporto_v;

    unordered_set<int> companhias_pais;

    vector<string> aero_codigo_temp;

    int contador_companhias_pais;
    int cont_partida_voos;
    int cont_chegada_voos;
    int cont_voos_partida_temp, cont_voos_chegada_temp;

    unordered_map<string, int> paises_num_aeroporto;

    string pais_est_temp;
    int destinos_est_temp = 0;
    int paises_tmp_total = 0;
    int companhias_est_temp = 0;

    int rnd;

    string n_voos;

    vector<int> voos_n_dist;

    set<int> ap;

    int index = 1;
    stack<int> node_stack;
    list<list<int>> sccs;
    int scc = 0;
    int min = INT_MAX;
    int max = 0;

    do {
        /**
         * Menu Principal
         */
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

        /** Leitura do input do utilizador **/

        cin >> op_menu;

        while(!checkInteiro(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 3){
            cout << endl;
            cout << "Opcao invalida! Tente novamente: ";
            cin >> op_menu;
            cout << endl;
        }

        choice = stoi(op_menu);
        cout << endl;

        /** Estrutura utillizada para realizar as varias funçoes disponibilizadas no menu. */

        switch (choice) {

            case 0:

                choice = 0;
                /** Opção para sair do programa. */
                break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            case 1:

                int ch1;
                choice = 1;
                /** Opção para aceder ao menu de informação. */

                do{
                    /**
                     * Menu Informacao
                     */
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

                    /** Leitura do input do utilizador **/

                    cin >> op_menu;

                    /** Verifica se o input é um inteiro e se está dentro do intervalo de opções disponiveis. */

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
                            /** Opção para sair do menu de informação. */
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 1:

                            /** Opção para aceder ao menu de informação de um aeroporto. */

                            cout << "Aeroporto: ";
                            cin >> aerop;
                            /** Leitura do input do utilizador */

                            /** Verifica se o aeroporto existe. */
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

                            /** Imprime as informações do aeroporto. */
                            print_info_aeroporto(id, aeroporto, aerop);

                            ch1 = 1;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 2:

                            cout << "Cidade: ";
                            getline(cin >> ws, cidade);
                            /** Leitura do input do utilizador */

                            /** Verifica se a cidade existe. */

                            while(!checkCidade(cidade)){
                                clearScreen();
                                cout << endl;
                                cout << "Cidade invalida! Tente novamente: ";
                                getline(cin >> ws, cidade);
                                cout << endl;
                            }

                            transform(cidade.begin(), cidade.end(), cidade.begin(), ::toupper);


                            /** Imprime as informações da cidade. */
                            print_info_cidade(cidade);

                            ch1 = 2;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 3:

                            cout << "Pais: ";
                            getline(cin >> ws, pais);
                            /** Leitura do input do utilizador */

                            /** Verifica se o pais existe. */
                            while(!checkPais(pais)){
                                clearScreen();
                                cout << endl;
                                cout << "Pais invalido! Tente novamente: ";
                                getline(cin >> ws, pais);
                                cout << endl;
                            }

                            transform(pais.begin(), pais.end(), pais.begin(), ::toupper);

                            /** Imprime as informações do pais. */
                            print_info_pais(pais);

                            ch1 = 3;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 4:

                            cout << "Coordenadas: " << endl;
                            cout << "  - Latitude: ";
                            cin >> lat;
                            cout << endl;
                            cout << "  - Longitude: ";
                            cin >> lon;

                            /** Leitura do input do utilizador */


                            /** Verifica se as coordenadas estão dentro do intervalo de valores possiveis. */
                            while(!checkCoordenadas(lat, lon)){
                                clearScreen();
                                cout << endl;
                                cout << "Coordenadas invalidas! Tente novamente: " << endl;
                                cout << "  - Latitude: ";
                                cin >> lat;
                                cout << endl;
                                cout << "  - Longitude: ";
                                cin >> lon;
                            }

                            cout << endl;
                            cout << "  - Raio a pesquisar (Km): ";
                            cin >> raio;
                            /** Leitura do input do utilizador */

                            raio_s = to_string(raio);

                            while(!checkRaio(raio_s)){
                                clearScreen();
                                cout << endl;
                                cout << "Raio invalido! Tente novamente: " << endl;
                                cout << "  - Raio a pesquisar (Km): ";
                                cin >> raio_s;
                            }
                            /** Verifica se o raio é válido. */
                            raio = stoi(raio_s);

                            print_info_aeroporto_num_raio_x(lat, lon, raio);
                            /** Imprime as informações dos aeroportos dentro do raio. */

                            ch1 = 4;
                            break;

/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        default:
                            clearScreen();
                            cout << "Opcao invalida! Tente novamente." << endl;
                            wait();
                            break;
                            /** Opção default caso o input do utilizador não seja válido. */
                    }

                } while (ch1 != 0);
                break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


            case 2:

                /** Opção para aceder ao menu de pesquisa de rotas. */
                int ch2;
                choice = 2;

                do{
                    /** Menu de pesquisa de rotas. */
                    clearScreen();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||---------------------- PESQUISA -----------------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Rota com menos escalas                          ||" << endl;
                    cout << "||   2 - Destinos com menos de n voos                    ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Sair                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> op_menu;
                    /** Leitura do input do utilizador */

                    while(!checkInteiro(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 2){
                        cout << endl;
                        cout << "Opcao invalida! Tente novamente: ";
                        cin >> op_menu;
                        cout << endl;
                    }
                    /** Verifica se o input do utilizador é válido. */

                    ch2 = stoi(op_menu);

                    switch (ch2) {

                        case 0:
                            /** Opção para sair do menu de pesquisa de rotas. */
                            ch2 = 0;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 1:
                            /** Opção para pesquisar a rota com menos escalas. */

                            ch2 = 1;
                            int ch2_1;

                            do{

                                /** Menu de pesquisa de rotas com menos escalas. */
                                clearScreen();
                                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                cout << "||---------------------- PESQUISA -----------------------||" << endl;
                                cout << "|| Origem do Voo:                        (Menos Escalas) ||" << endl;
                                cout << "||_______________________________________________________||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   1 - Um Aeroporto                                    ||" << endl;
                                cout << "||   2 - Uma Cidade                                      ||" << endl;
                                cout << "||   3 - Um Pais                                         ||" << endl;
                                cout << "||   4 - O Aeroporto mais proximo de umas coordenadas    ||" << endl;
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
                                /** Verifica se o input do utilizador é válido. */

                                ch2_1 = stoi(op_menu);

                                switch (ch2_1) {

                                    case 0:
                                        /** Opção para sair do menu de pesquisa de rotas com menos escalas. */

                                        ch2_1 = 0;
                                        break;

/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 1:
                                        /** Opção para pesquisar a rota com menos escalas a partir de um aeroporto. */

                                        cout << "Aeroporto: ";
                                        cin >> aerop;
                                        /** Leitura do input do utilizador */

                                        while(!checkAeroporto(aerop)){
                                            clearScreen();
                                            cout << endl;
                                            cout << "Aeroporto invalido! Tente novamente: ";
                                            cin >> aerop;
                                            cout << endl;
                                        }
                                        /** Verifica se o aeroporto é válido. */

                                        transform(aerop.begin(), aerop.end(), aerop.begin(), ::toupper);

                                        menu_me_aerop_dest(aerop);


                                        ch2_1 = 1;
                                        break;

/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 2:
                                        /** Opção para pesquisar a rota com menos escalas a partir de uma cidade. */

                                        cout << "Cidade: ";
                                        getline(cin >> ws, cidade);
                                        /** Leitura do input do utilizador */

                                        while(!checkCidade(cidade)){
                                            clearScreen();
                                            cout << endl;
                                            cout << "Cidade invalida! Tente novamente: ";
                                            getline(cin >> ws, cidade);
                                            cout << endl;
                                        }
                                        /** Verifica se a cidade é válida. */

                                        transform(cidade.begin(), cidade.end(), cidade.begin(), ::toupper);

                                        pais_cidade = checkPaisCidade(cidade);
                                        /** Verifica se a cidade pertence a algum país. */

                                        if(lfile.getCidadesAeroportos().find(cidade)->second.size() == 1){
                                            aerop =  lfile.getAeroportos().find(lfile.getCidadesAeroportos().find(cidade)->second[0])->second.getCodigo();
                                            menu_me_aerop_dest(aerop);
                                        } /** Verifica se a cidade tem apenas um aeroporto */
                                        else{
                                            clearScreen();
                                            cout << "===========================================================" << endl;
                                            cout << "  Cidade com mais de um aeroporto. Escolha um: " << endl;
                                            for(auto i : pais_cidade){
                                                cout << lfile.getAeroportos().find(i)->second.getCodigo() << " - " << lfile.getAeroportos().find(i)->second.getNome() << endl;
                                            } /** Imprime todos os aeroportos da cidade */
                                            cout << "===========================================================" << endl;
                                            cout << endl;
                                            cout << "Aeroporto: ";
                                            cin >> aerop;
                                            /** Leitura do input do utilizador */

                                            while(!checkAeroporto(aerop)){
                                                clearScreen();
                                                cout << endl;
                                                cout << "Aeroporto invalido! Tente novamente: ";
                                                cin >> aerop;
                                                cout << endl;
                                            }
                                            /** Verifica se o aeroporto é válido. */

                                            transform(aerop.begin(), aerop.end(), aerop.begin(), ::toupper);

                                            menu_me_aerop_dest(aerop);

                                        }

                                        ch2_1 = 2;
                                        break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 3:

                                        cout << "Pais: ";
                                        getline(cin >> ws, pais);
                                        /** Leitura do input do utilizador */

                                        while(!checkPais(pais)){
                                            clearScreen();
                                            cout << endl;
                                            cout << "Pais invalido! Tente novamente: ";
                                            getline(cin >> ws, pais);
                                            cout << endl;
                                        }
                                        /** Verifica se o país é válido. */

                                        transform(pais.begin(), pais.end(), pais.begin(), ::toupper);

                                        aeroportos_pais_v = aeroportos_pais(pais);

                                        if(aeroportos_pais_v.size() == 1) {
                                            aerop = to_string(aeroportos_pais_v[0]);
                                            menu_me_aerop_dest(aerop);
                                        } /** Verifica se o país tem apenas um aeroporto */
                                        else{
                                            clearScreen();
                                            cout << "===========================================================" << endl;
                                            cout << "  Pais com mais de um aeroporto. Escolha um: " << endl;
                                            for(auto i : aeroportos_pais_v){
                                                cout << lfile.getAeroportos().find(i)->second.getCodigo() << " - " << lfile.getAeroportos().find(i)->second.getNome() << endl;
                                            } /** Imprime todos os aeroportos do país */
                                            cout << "===========================================================" << endl;
                                            cout << endl;
                                            cout << "Aeroporto: ";
                                            cin >> aerop;
                                            /** Leitura do input do utilizador */

                                            while(!checkAeroporto(aerop)){
                                                clearScreen();
                                                cout << endl;
                                                cout << "Aeroporto invalido! Tente novamente: ";
                                                cin >> aerop;
                                                cout << endl;
                                            } /** Verifica se o aeroporto é válido. */

                                            transform(aerop.begin(), aerop.end(), aerop.begin(), ::toupper);

                                            menu_me_aerop_dest(aerop);
                                        }

                                        ch2_1 = 3;
                                        break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 4:

                                        cout << "Coordenadas: " << endl;
                                        cout << "  - Latitude: ";
                                        cin >> lat;
                                        cout << endl;
                                        cout << "  - Longitude: ";
                                        cin >> lon;
                                        /** Leitura do input do utilizador */

                                        while(!checkCoordenadas(lat, lon)){
                                            clearScreen();
                                            cout << endl;
                                            cout << "Coordenadas invalidas! Tente novamente: " << endl;
                                            cout << "  - Latitude: ";
                                            cin >> lat;
                                            cout << endl;
                                            cout << "  - Longitude: ";
                                            cin >> lon;
                                        } /** Verifica se as coordenadas são válidas. */

                                        aerop = aeroporto_mais_proximo(lat, lon);

                                        clearScreen();
                                        cout << "===========================================================" << endl;
                                        cout << "  Cidade mais proxima: " << lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aerop)->second)->second.getCidade() << endl;
                                        cout << endl;
                                        cout << "  Aeroporto mais proximo: " << endl;
                                        cout << "  [" << lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aerop)->second)->second.getCodigo()
                                        << "] - " << lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aerop)->second)->second.getNome() << endl;
                                        cout << endl;
                                        cout << "  Distancia: " << distancia(lat, lon, lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aerop)->second)->second.getLatitude(),lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aerop)->second)->second.getLongitude());
                                        cout << " km" << endl;
                                        cout << "===========================================================" << endl;

                                        wait();

                                        menu_me_aerop_dest(aerop);

                                        ch2_1 = 4;
                                        break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 5:

                                        cout << "Coordenadas: " << endl;
                                        cout << "  - Latitude: ";
                                        cin >> lat;
                                        cout << endl;
                                        cout << "  - Longitude: ";
                                        cin >> lon;
                                        /** Leitura do input do utilizador */

                                        while(!checkCoordenadas(lat, lon)){
                                            clearScreen();
                                            cout << endl;
                                            cout << "Coordenadas invalidas! Tente novamente: " << endl;
                                            cout << "  - Latitude: ";
                                            cin >> lat;
                                            cout << endl;
                                            cout << "  - Longitude: ";
                                            cin >> lon;
                                        } /** Verifica se as coordenadas são válidas. */

                                        cout << endl;
                                        cout << "  - Raio a pesquisar (Km): ";
                                        cin >> raio;

                                        raio_s = to_string(raio);

                                        while(!checkRaio(raio_s)){
                                            clearScreen();
                                            cout << endl;
                                            cout << "Raio invalido! Tente novamente: " << endl;
                                            cout << "  - Raio a pesquisar (Km): ";
                                            cin >> raio_s;
                                        } /** Verifica se o raio é válido. */
                                        raio = stoi(raio_s);

                                        aeroportos_raio = aeroportos_num_raio_x(lat, lon, raio);

                                        if(aeroportos_raio.empty()){
                                            clearScreen();
                                            cout << "===========================================================" << endl;
                                            cout << "  Nao existem aeroportos no raio indicado!" << endl;
                                            cout << "===========================================================" << endl;
                                            wait();
                                            ch2_1 = 5;
                                            break;
                                        } /** Verifica se existem aeroportos no raio indicado. */

                                        clearScreen();
                                        cout << "===========================================================" << endl;
                                        cout << "  Aeroportos no raio de " << raio << " km: " << endl;
                                        cout << endl;
                                        for(auto i : aeroportos_raio){
                                            cout << "  [" << lfile.getAeroportos().find(i)->second.getCodigo()
                                                 << "] - " << lfile.getAeroportos().find(i)->second.getNome() << endl;
                                        } /** Imprime os aeroportos no raio indicado. */
                                        cout << endl;
                                        cout << "===========================================================" << endl;
                                        cout << "|  Escollha um aeroporto:                                 |" << endl;
                                        cout << "===========================================================" << endl;
                                        cout << endl;
                                        cout << "Aeroporto: ";
                                        cin >> aerop;
                                        /** Leitura do input do utilizador */

                                        while(!checkAeroporto(aerop)){
                                            clearScreen();
                                            cout << endl;
                                            cout << "Aeroporto invalido! Tente novamente: ";
                                            cin >> aerop;
                                            cout << endl;
                                        } /** Verifica se o aeroporto é válido. */

                                        transform(aerop.begin(), aerop.end(), aerop.begin(), ::toupper);

                                        menu_me_aerop_dest(aerop);

                                        ch2_1 = 5;
                                        break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/

                                    default:
                                        clearScreen();
                                        cout << "Opcao invalida! Tente novamente." << endl;
                                        wait();
                                        break;
                                        /** Caso o utilizador insira uma opção inválida. */

                                }

                            } while (ch2_1 != 0);

                            break;

                        case 2:
                            /** opção destinos com menos de n voos */

                            cout << "Aeroporto de partida: ";
                            cin >> aerop;
                            cout << endl;
                            /** Leitura do input do utilizador */

                            while(!checkAeroporto(aerop)){
                                clearScreen();
                                cout << endl;
                                cout << "Aeroporto invalido! Tente novamente: ";
                                cin >> aerop;
                                cout << endl;
                            }
                            /** Verifica se o aeroporto é válido. */

                            transform(aerop.begin(), aerop.end(), aerop.begin(), ::toupper);

                            cout << "Numero de voos: ";
                            cin >> n_voos;
                            /** Leitura do input do utilizador */

                            while(!checkInteiro(n_voos)){
                                clearScreen();
                                cout << endl;
                                cout << "Numero de voos invalido! Tente novamente: ";
                                cin >> n_voos;
                                cout << endl;
                            } /** Verifica se o número de voos é válido. */

                            g.bfs((int) lfile.getAeroportosCodigos().find(aerop)->second);

                            for(int i = 1; i <= g.n; i++){
                                if(g.nodes[i].distance <= stoi(n_voos)){
                                    voos_n_dist.push_back(i);
                                }
                            }

                            clearScreen();
                            cout << "===========================================================" << endl;
                            cout << "|------------------------- INFO --------------------------|" << endl;
                            cout << "|  Aeroporto de origem: " + aerop + "                               |" << endl;
                            cout << "|=========================================================|" << endl;
                            cout << "   Consegue chegar a " << voos_n_dist.size() << " aeroportos em " << n_voos << " voos ou menos." << endl;
                            cout << endl;
                            cout << "   Aeroportos:" << endl;
                            cout << endl;
                            for(int i : voos_n_dist){
                                cout << "    - [" << lfile.getAeroportos().at(i).getCodigo() << "] -> " << lfile.getAeroportos().at(i).getNome() << endl;
                            }
                            cout << endl;
                            cout << "|                                                         |" << endl;
                            cout << "===========================================================" << endl;

                            voos_n_dist.clear();

                            wait();

                            ch1 = 5;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/

                        default:
                            clearScreen();
                            cout << "Opcao invalida!" << endl;
                            wait();
                            break;
                            /** Caso o utilizador insira uma opção inválida. */
                    }

                } while (ch2 != 0);

                break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            case 3:
                /** Abre o menu de estatisticas */

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
                    cout << "||   3 - De um Aeroporto                                 ||" << endl;
                    cout << "||   4 - Pontos de Articulacao                           ||" << endl;
                    cout << "||   5 - Componentes Fortemente Conexos                  ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Sair                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> op_menu;
                    /** Leitura do input do utilizador */

                    while(!checkInteiro(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 5){
                        cout << endl;
                        cout << "Opcao invalida! Tente novamente: ";
                        cin >> op_menu;
                        cout << endl;
                    } /** Verifica se a opção é válida. */

                    ch3= stoi(op_menu);

                    switch (ch3) {

                        case 1:
                            /** opção estatisticas globais */

                            rnd = (rand() % (10 - 3 + 1) + 3);



                            clearScreen();
                            cout << "===========================================================" << endl;
                            cout << "|--------------------- ESTATISTICAS ----------------------|" << endl;
                            cout << "|                        Globais                          |" << endl;
                            cout << "|=========================================================|" << endl;
                            cout << "                                                           " << endl;
                            cout << "    Paises com aeroportos: " << lfile.getPaisCidades().size() <<  "                             " << endl;
                            cout << "    Aeroportos totais: " << lfile.getAeroportos().size() << "                                " << endl;
                            cout << "    Companhias: " << lfile.getCompanhias().size() << "                                        " << endl;
                            cout << "    Diametro da Rede: " << diametro << "                                                   " << endl;
                            cout << endl;
                            cout << "    Top " << rnd  <<" Aeroportos com mais companhias aereas:           " << endl;
                            for(auto& elem : lfile.getAeroportosCompanhias()) {
                                aeroportos_companhias.emplace_back(elem.second.size(), elem.first);
                            }
                            sort(aeroportos_companhias.begin(), aeroportos_companhias.end(), [](const pair<int, string>& a, const pair<int, string>& b) {return a.first > b.first;});

                            for(int i = 0; i < rnd; i++) {
                                cout << "      " << i+1 << " -> "
                                     << lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aeroportos_companhias[i].second)->second)->second.getNome() << ", "
                                     << lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aeroportos_companhias[i].second)->second)->second.getPais()
                                     << " - " << aeroportos_companhias[i].first << endl;
                            }
                            cout << endl;
                            if(aeroportos_max_voos.size() > 1 ){
                                if(aeroportos_max_voos.size() > 5) rnd = (rand() % (5 - 2 + 1) + 2);
                                else (rand() % (aeroportos_max_voos.size() - 2 + 1) + 2);
                                cout << "    As " << rnd  <<" maiores viagens na rede global:           " << endl;
                                for(int i = 0; i < rnd; i++){
                                    cout << "      " << i+1
                                    << " -> [" << lfile.getAeroportos().find(aeroportos_max_voos[i].first)->second.getCodigo()
                                    << "] -> [" << lfile.getAeroportos().find(aeroportos_max_voos[i].second)->second.getCodigo() << "]" << endl
                                            << "        " << lfile.getAeroportos().find(aeroportos_max_voos[i].first)->second.getNome() << ", "
                                         << lfile.getAeroportos().find(aeroportos_max_voos[i].first)->second.getPais()
                                         << " - "
                                         << lfile.getAeroportos().find(aeroportos_max_voos[i].second)->second.getNome() << ", "
                                         << lfile.getAeroportos().find(aeroportos_max_voos[i].second)->second.getPais();
                                    cout << endl;
                                }
                            }
                            else{
                                cout << "    A maiore viagem na rede global:           " << endl;
                                cout << "      " << 1
                                << " -> [" << lfile.getAeroportos().find(aeroportos_max_voos[0].first)->second.getCodigo()
                                << "] -> [" << lfile.getAeroportos().find(aeroportos_max_voos[0].second)->second.getCodigo() << "]" << endl
                                     << "        " << lfile.getAeroportos().find(aeroportos_max_voos[0].first)->second.getNome() << ", "
                                     << lfile.getAeroportos().find(aeroportos_max_voos[0].first)->second.getPais()
                                     << " -> "
                                     << lfile.getAeroportos().find(aeroportos_max_voos[0].second)->second.getNome() << ", "
                                     << lfile.getAeroportos().find(aeroportos_max_voos[0].second)->second.getPais();
                                cout << endl;
                            }

                            cout << "|                                                         |" << endl;
                            cout << "===========================================================" << endl;
                            cout << endl;

                            aeroportos_companhias.clear();

                            wait();
                            break;

                        case 2:
                            /** opção estatisticas por pais */

                            cout << "Pais: ";
                            getline(cin >> ws, pais);

                            while(!checkPais(pais)){
                                clearScreen();
                                cout << endl;
                                cout << "Pais invalido! Tente novamente: ";
                                getline(cin >> ws, pais);
                                cout << endl;
                            }

                            transform(pais.begin(), pais.end(), pais.begin(), ::toupper);

                            aeroportos_pais_v = aeroportos_pais(pais);


                            if(aeroportos_pais_v.size() < 5){
                                rnd = (int)(rand() % (aeroportos_pais_v.size() - 1 + 1)+1);
                            }
                            else{
                                rnd = (rand() % (5 - 3 + 1) + 3);
                            }


                            contador_companhias_pais = 0;

                            for(const auto& c : lfile.getCompanhias()){
                                batata = c.second.getPais();
                                transform(batata.begin(), batata.end(), batata.begin(), ::toupper);
                                if(batata == pais){
                                    contador_companhias_pais++;
                                }
                            }

                            cont_partida_voos = 0;
                            cont_chegada_voos = 0;
                            cont_voos_chegada_temp = 0;
                            cont_voos_partida_temp = 0;

                            voos_por_aeroporto_v.clear();

                            for(const auto& a : aero_codigo_temp){

                                for(const auto& v : lfile.getChegadaPartidaCompanhia()){
                                    if(v.first.first == a){
                                        cont_partida_voos++;
                                        cont_voos_partida_temp++;
                                    }
                                    if(v.first.second == a){
                                        cont_chegada_voos++;
                                        cont_voos_chegada_temp++;
                                    }
                                }
                                voos_por_aeroporto_v.emplace_back(a,cont_chegada_voos + cont_partida_voos);
                                cont_partida_voos = 0;
                                cont_chegada_voos = 0;
                            }

                            sort(voos_por_aeroporto_v.begin(), voos_por_aeroporto_v.end(), [](const pair<string, int>& a, const pair<string , int>& b) {return a.second > b.second;});

                            clearScreen();
                            cout << "===========================================================" << endl;
                            cout << "|--------------------- ESTATISTICAS ----------------------|" << endl;
                            cout << "|                          Pais                           |" << endl;
                            cout << "|=========================================================|" << endl;
                            cout << "                                                           " << endl;
                            cout << "    Pais - " << pais << "                                        " << endl;
                            cout << "    Existem " << aeroportos_pais_v.size() << " Aeroportos   " << endl;
                            cout << "    Existem " << contador_companhias_pais << " companhias de " << pais <<"                                      " << endl;
                            cout << "    Partem " << cont_voos_partida_temp << " voos de " << pais << "                             " << endl;
                            cout << "    Chegam " << cont_voos_chegada_temp << " voos a " << pais << "                             " << endl;
                            cout << endl;
                            cout << "    Top " << rnd << " Aeroportos com mais voos:           " << endl;

                            for(int i = 0; i < rnd; i++) {
                                cout << "      " << i+1 << " -> "
                                     << lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(voos_por_aeroporto_v[i].first)->second)->second.getNome() << ", "
                                     << " - " << voos_por_aeroporto_v[i].second << endl;
                            }
                            cout << "|                                                         |" << endl;
                            cout << "===========================================================" << endl;
                            cout << endl;

                            voos_por_aeroporto_v.clear();
                            aeroportos_pais_v.clear();

                            wait();

                            break;


                        case 3:
                            /** opção estatisticas por aeroporto */

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




                            destinos_est_temp = 0;
                            paises_tmp_total = 0;
                            companhias_est_temp = 0;
                            cont_partida_voos = 0;
                            cont_chegada_voos = 0;

                            aeroporto = lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aerop)->second)->second;


                            for(const auto& v : lfile.getChegadaPartidaCompanhia()){
                                if(v.first.first == aerop){
                                    cont_partida_voos++;
                                    cont_voos_partida_temp++;
                                }
                                if(v.first.second == aerop){
                                    cont_chegada_voos++;
                                    cont_voos_chegada_temp++;
                                }
                            }



                            for(auto& ligacao : g.nodes[lfile.getAeroportosCodigos().find(aerop)->second].adj) {
                                pais_est_temp = lfile.getAeroportos().find(ligacao.dest)->second.getPais();
                                paises_num_aeroporto[pais_est_temp]++;
                            }
                            paises_tmp_total = (int) paises_num_aeroporto.size();

                            companhias_est_temp = (int) lfile.getAeroportosCompanhias()[aerop].size();
                            destinos_est_temp = (int) g.nodes[lfile.getAeroportosCodigos().find(aerop)->second].adj.size();


                            clearScreen();
                            cout << "===========================================================" << endl;
                            cout << "|--------------------- ESTATISTICAS ----------------------|" << endl;
                            cout << "|  Aeroporto escolhido: " + aerop + "                               |" << endl;
                            cout << "===========================================================" << endl;
                            cout << "|                                                         |" << endl;
                            cout << "   Nome:   " + aeroporto.getNome()                         << endl;
                            cout << "   Cidade: " + aeroporto.getCidade()                       << endl;
                            cout << "   Pais:   " + aeroporto.getPais()                         << endl;
                            cout << "   Numero total de voos: " << cont_partida_voos + cont_chegada_voos                         << endl;
                            cout << "   Numero de Voos de chegada: " << cont_chegada_voos                 << endl;
                            cout << "   Numero de Voos de partida: " << cont_partida_voos                 << endl;
                            cout << "   Numero de Companhias aereas: " << companhias_est_temp            << endl;
                            cout << "   Existem " << destinos_est_temp <<" destinos: "     << endl;
                            cout << "   Pode chegar ate " << paises_tmp_total  << " paises" << endl;

                            cout << "|                                                         |" << endl;
                            cout << "===========================================================" << endl;
                            cout << endl;

                            wait();

                            break;

                        case 4:
                            /** opção estatisticas pontos de articulação */

                            ap = g.getArticulationPoints();
                            if(ap.empty()) {
                                cout << "Sem pontos de articulacao" << endl;
                            }
                            else {
                                clearScreen();
                                cout << "===========================================================" << endl;
                                cout << "|--------------------- ESTATISTICAS ----------------------|" << endl;
                                cout << "|                  Pontos de Articulacao                  |" << endl;
                                cout << "|=========================================================|" << endl;
                                cout << endl;
                                cout << "    Existem " << ap.size() << " pontos de articulacao" << endl;
                                cout << endl;
                                cout << "    Aeroportos com pontos de articulacao:                 " << endl;
                                for(auto& elem : ap) {
                                    cout << "      [" << lfile.getAeroportos().find(elem)->second.getCodigo() << "] -> " << lfile.getAeroportos().find(elem)->second.getNome() << ", "
                                         << lfile.getAeroportos().find(elem)->second.getPais() << endl;
                                }
                                cout << endl;
                                cout << "|                                                         |" << endl;
                                cout << "===========================================================" << endl;
                                cout << endl;
                            }
                            wait();
                            break;

                        case 5:
                            /** opção estatisticas componentes fortemente conexos */

                            for(auto& node : g.nodes) {
                                node.visited = false;
                                node.in_stack = false;
                            }

                            for(int v = 1; v <= g.n; v++) {
                                if(!g.nodes[v].visited) {
                                    scc += g.dfs_scc(v, index);
                                }
                            }

                            for(auto& node : g.nodes) {
                                node.visited = false;
                                node.in_stack = false;
                            }

                            for(int v = 1; v <= g.n; v++) {
                                if(!g.nodes[v].visited) {
                                    g.dfs_scc2(v, index, & node_stack, &sccs);
                                }
                            }

                            for(auto& comp : sccs) {
                                if(comp.size() < min) {
                                    min = (int)comp.size();
                                }
                                else if (comp.size() > max) {
                                    max = (int)comp.size();
                                }
                            }

                            clearScreen();
                            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                            cout << "||-------------------- ESTATISTICAS ---------------------||" << endl;
                            cout << "||_______________________________________________________||" << endl;
                            cout << "     Numero de componentes fortemente conexos: " << scc << endl;
                            cout << "                                                           " << endl;
                            cout << "     Menor componentes fortemente conexo: " << min << endl;
                            cout << "     Maior componentes fortemente conexo: " << max << endl;
                            cout << "|                                                         |" << endl;
                            cout << "||_______________________________________________________||" << endl;

                            wait();

                            ch3 = 6;
                            break;

                        default:
                            break;
                    }

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

bool checkCoordenadas(double lat, double lon) {

    if(lat < -90 || lat > 90 || lon < -180 || lon > 180){
        clearScreen();
        cout << "Coordenadas invalidas!" << endl;
        wait();
        return false;
    }

    return true;
}

bool checkRaio(const string& s){

    if(!checkDouble(s)){
        return false;
    }

    double raio = stod(s);

    if(raio < 0){
        clearScreen();
        cout << "Raio invalido!" << endl;
        wait();
        return false;
    }

    return true;
}

bool checkDouble(const string& s){

    int count = 0;

    for(auto y : s){
        if(!isdigit(y) && y != '.' && y != ','){
            return false;
        }
        if(y == '.' || y == ','){
            count++;
        }
    }

    if(count > 1){
        return false;
    }

    return true;
}

vector<int> checkPaisCidade(const string& cidade) {

    string opcao;
    int pais_escolhido;
    vector<int> aeroportos;
    string nome_pais;
    vector<string> countries;

    for (auto &elem: lfile.getPaisCidades()) {
        for (auto &city: elem.second) {
            if (city == cidade) {
                countries.push_back(elem.first);
            }
        }
    }

    //Quando existem cidades com o mesmo nome em paises diferentes
    if(countries.size() > 1){
        clearScreen();
        cout << "===========================================================" << endl;
        cout << "|----------------------- PESQUISA ------------------------|" << endl;
        cout << "  Existem " << countries.size() << " paises com a cidade " + cidade + "                  " << endl;
        cout << "===========================================================" << endl;
        cout << "                                                       " << endl;
        cout << "  Escolha o pais:                                      " << endl;
        cout << "                                                       " << endl;
        for (int i = 0; i < countries.size(); i++) {
            cout << "  " << i + 1 << " - " << countries[i] << endl;
        }
        cout << "                                                       " << endl;
        cout << "===========================================================" << endl;
        cout << endl;

        cout << "Opcao: ";
        cin >> pais_escolhido;

        while (!checkInteiro(to_string(pais_escolhido)) || pais_escolhido < 1 || pais_escolhido > countries.size()) {
            cout << endl;
            cout << "Opcao invalida! Tente novamente: ";
            cin >> pais_escolhido;
            cout << endl;
        }

        nome_pais = countries[pais_escolhido - 1];

        pair<string, string> pais_cidade = make_pair(nome_pais, cidade);

        aeroportos = lfile.getPaisCidadeAeroportos().find(pais_cidade)->second;

        return aeroportos;
    }
    else{
        nome_pais = countries[0];
        pair<string, string> pais_cidade = make_pair(nome_pais, cidade);

        aeroportos = lfile.getPaisCidadeAeroportos().find(pais_cidade)->second;

        return aeroportos;
    }
}



// Other Menu Functions

void menu_me_aerop_dest(const string& aerop) {

    string op_menu;
    string cidade;
    vector<int> pais_cidade;
    string pais;
    vector<int> aeroportos_pais_v;
    double lat, lon, raio;
    string raio_s;
    vector<int> aeroportos_raio;




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
    cout << "||   4 - O Aeroporto mais proximo de umas coordenadas    ||" << endl;
    cout << "||   5 - Todos os pontos num raio de X Km                ||" << endl;
    cout << "||                                                       ||" << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << endl;

    cin >> op_menu;

    while (!checkInteiro(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 5) {
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

            while (!checkAeroporto(aerop_destino)) {
                clearScreen();
                cout << endl;
                cout << "Aeroporto invalido! Tente novamente: ";
                cin >> aerop_destino;
                cout << endl;
            }

            transform(aerop_destino.begin(), aerop_destino.end(), aerop_destino.begin(), ::toupper);

            destino = lfile.getAeroportosCodigos().find(aerop_destino)->second;
            print_voos(origem, destino);

            break;

        case 2:

            cout << "Cidade: ";
            getline(cin >> ws, cidade);

            while (!checkCidade(cidade)) {
                clearScreen();
                cout << endl;
                cout << "Cidade invalida! Tente novamente: ";
                getline(cin >> ws, cidade);
                cout << endl;
            }

            transform(cidade.begin(), cidade.end(), cidade.begin(), ::toupper);

            pais_cidade = checkPaisCidade(cidade);

            if (lfile.getCidadesAeroportos().find(cidade)->second.size() == 1) {
                aerop_destino = lfile.getAeroportos().find(
                        lfile.getCidadesAeroportos().find(cidade)->second[0])->second.getCodigo();
                destino = lfile.getAeroportosCodigos().find(aerop_destino)->second;
                print_voos(origem, destino);
            } else {
                clearScreen();
                cout << "===========================================================" << endl;
                cout << "  Cidade com mais de um aeroporto. Escolha um: " << endl;
                for (auto i: pais_cidade) {
                    cout << lfile.getAeroportos().find(i)->second.getCodigo() << " - "
                         << lfile.getAeroportos().find(i)->second.getNome() << endl;
                }
                cout << "===========================================================" << endl;
                cout << endl;
                cout << "Aeroporto: ";
                cin >> aerop_destino;

                while (!checkAeroporto(aerop_destino)) {
                    clearScreen();
                    cout << endl;
                    cout << "Aeroporto invalido! Tente novamente: ";
                    cin >> aerop_destino;
                    cout << endl;
                }

                transform(aerop_destino.begin(), aerop_destino.end(), aerop_destino.begin(), ::toupper);

                destino = lfile.getAeroportosCodigos().find(aerop_destino)->second;
                print_voos(origem, destino);


            }

            break;


        case 3:

            cout << "Pais: ";
            getline(cin >> ws, pais);

            while(!checkPais(pais)){
                clearScreen();
                cout << endl;
                cout << "Pais invalido! Tente novamente: ";
                getline(cin >> ws, pais);
                cout << endl;
            }

            transform(pais.begin(), pais.end(), pais.begin(), ::toupper);

            aeroportos_pais_v = aeroportos_pais(pais);

            if(aeroportos_pais_v.size() == 1){
                aerop_destino = to_string(aeroportos_pais_v[0]);
                destino = lfile.getAeroportosCodigos().find(aerop_destino)->second;
                print_voos(origem, destino);
            }
            else{
                clearScreen();
                cout << "===========================================================" << endl;
                cout << "  Pais com mais de um aeroporto. Escolha um: " << endl;
                for(auto i : aeroportos_pais_v){
                    cout << lfile.getAeroportos().find(i)->second.getCodigo() << " - " << lfile.getAeroportos().find(i)->second.getNome() << endl;
                }
                cout << "===========================================================" << endl;
                cout << endl;
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
                print_voos(origem, destino);


            }
            break;

        case 4:

            cout << "Coordenadas: " << endl;
            cout << "  - Latitude: ";
            cin >> lat;
            cout << endl;
            cout << "  - Longitude: ";
            cin >> lon;

            while(!checkCoordenadas(lat, lon)){
                clearScreen();
                cout << endl;
                cout << "Coordenadas invalidas! Tente novamente: " << endl;
                cout << "  - Latitude: ";
                cin >> lat;
                cout << endl;
                cout << "  - Longitude: ";
                cin >> lon;
            }

            aerop_destino = aeroporto_mais_proximo(lat, lon);

            clearScreen();
            cout << "===========================================================" << endl;
            cout << "  Cidade mais proxima: " << lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aerop_destino)->second)->second.getCidade() << endl;
            cout << endl;
            cout << "  Aeroporto mais proximo: " << endl;
            cout << "  [" << lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aerop_destino)->second)->second.getCodigo()
                 << "] - " << lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aerop_destino)->second)->second.getNome() << endl;
            cout << endl;
            cout << "  Distancia: " << distancia(lat, lon, lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aerop_destino)->second)->second.getLatitude(),lfile.getAeroportos().find(lfile.getAeroportosCodigos().find(aerop_destino)->second)->second.getLongitude());
            cout << " km" << endl;
            cout << "===========================================================" << endl;

            wait();

            destino = lfile.getAeroportosCodigos().find(aerop_destino)->second;
            print_voos(origem, destino);

            break;

        case 5:

            cout << "Coordenadas: " << endl;
            cout << "  - Latitude: ";
            cin >> lat;
            cout << endl;
            cout << "  - Longitude: ";
            cin >> lon;

            while(!checkCoordenadas(lat, lon)){
                clearScreen();
                cout << endl;
                cout << "Coordenadas invalidas! Tente novamente: " << endl;
                cout << "  - Latitude: ";
                cin >> lat;
                cout << endl;
                cout << "  - Longitude: ";
                cin >> lon;
            }

            cout << endl;
            cout << "  - Raio a pesquisar (Km): ";
            cin >> raio;

            raio_s = to_string(raio);

            while(!checkRaio(raio_s)){
                clearScreen();
                cout << endl;
                cout << "Raio invalido! Tente novamente: " << endl;
                cout << "  - Raio a pesquisar (Km): ";
                cin >> raio_s;
            }
            raio = stoi(raio_s);

            aeroportos_raio = aeroportos_num_raio_x(lat, lon, raio);

            clearScreen();
            cout << "===========================================================" << endl;
            cout << "  Aeroportos no raio de " << raio << " km: " << endl;
            cout << endl;
            for(auto i : aeroportos_raio){
                cout << "  [" << lfile.getAeroportos().find(i)->second.getCodigo()
                     << "] - " << lfile.getAeroportos().find(i)->second.getNome() << endl;
            }
            cout << endl;
            cout << "===========================================================" << endl;
            cout << "|  Escollha um aeroporto:                                 |" << endl;
            cout << "===========================================================" << endl;
            cout << endl;
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
            print_voos(origem, destino);

        default:
            break;


    }
}

string aeroporto_mais_proximo(double lat, double lon){

    double latitude = lat, longitude = lon;

    double aeroporto_mais_proximo = INT_MAX;

    int aeroporto_mais_proximo_id;

    for (const auto &aerop: lfile.getAeroportosCoords()) {
        if (distancia(latitude, longitude, aerop.first.first, aerop.first.second) < aeroporto_mais_proximo) {
            aeroporto_mais_proximo = distancia(latitude, longitude, aerop.first.first, aerop.first.second);
            aeroporto_mais_proximo_id = aerop.second;
        }
    }

    for(const auto& x : lfile.getAeroportos()){
        if(aeroporto_mais_proximo_id == x.first){
            return x.second.getCodigo();
        }
    }

    return "";

}

vector<int> aeroportos_pais(const string& pais){

    unordered_set<string> cidades = lfile.getPaisCidades().find(pais)->second;

    vector<string> cidades_v(cidades.begin(), cidades.end());

    vector<int> aeroportos;

    vector<pair<string, string>> pais_cidade;

    pais_cidade.reserve(cidades_v.size());
    for(auto & i : cidades_v){
        pais_cidade.emplace_back(pais, i);
    }

    for(const auto& i : pais_cidade){
        vector<int> tmp = lfile.getPaisCidadeAeroportos().find(i)->second;
        aeroportos.insert(aeroportos.end(), tmp.begin(), tmp.end());
    }

    return aeroportos;
}

vector<int> aeroportos_num_raio_x(double lat, double lon, double raio){

    double latitude = lat, longitude = lon;

    vector<int> aeroportos;

    for (const auto &aerop: lfile.getAeroportosCoords()) {
        if (distancia(latitude, longitude, aerop.first.first, aerop.first.second) <= raio) {
            aeroportos.push_back(aerop.second);
        }
    }

    return aeroportos;
}

// Prints de Menu Informacao

void print_info_aeroporto(int id, const Aeroporto& aeroporto, string aerop){

    int companhias;

    transform(aerop.begin(), aerop.end(), aerop.begin(), ::toupper);


    companhias = (int) lfile.getAeroportosCompanhias()[aerop].size();


    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "|  Aeroporto escolhido: " + aerop + "                               |" << endl;
    cout << "|=========================================================|" << endl;
    cout << "                                                           " << endl;
    cout << "   Nome:   " + aeroporto.getNome()                         << endl;
    cout << "   Cidade: " + aeroporto.getCidade()                       << endl;
    cout << "   Pais:   " + aeroporto.getPais()                         << endl;
    cout << "   Numero de Companhias aereas: " << companhias            << endl;
    cout << "|                                                         |" << endl;
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

    pais_cidade.reserve(cidades_v.size());
    for(auto & i : cidades_v){
        pais_cidade.emplace_back(pais, i);
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


void print_info_aeroporto_num_raio_x(double latitude, double longitude, double raio) {

    vector<int> aeroportos;
    set<pair<string, string>> pais_cidade;
    string opcao;
    unordered_set<string> pais;

    for (const auto &aerop: lfile.getAeroportosCoords()) {
        if (distancia(latitude, longitude, aerop.first.first, aerop.first.second) <= raio) {
            aeroportos.push_back(aerop.second);
        }
    }

    for(auto x : aeroportos){
        for(const auto& y : lfile.getPaisCidadeAeroportos()){
            for(auto z : y.second){
                if(z == x){
                    pais_cidade.insert(y.first);
                }
            }
        }
    }

    //contar o numero de paises
    for(const auto& i : pais_cidade){
        pais.insert(i.first);
    }

    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "   Latitude: " << latitude << "                                 " << endl;
    cout << "   Longitude: " << longitude << "                                 " << endl;
    cout << "   Raio: " << raio << "                                 " << endl;
    cout << "===========================================================" << endl;
    cout << "                                                       " << endl;
    cout << "   Numero de Paises: " << pais.size() << endl;
    cout << "   Numero de Cidades: " << pais_cidade.size() << endl;
    cout << "   Numero de aeroportos: " << aeroportos.size() << endl;
    cout << "                                                       " << endl;
    cout << "===========================================================" << endl;
    cout << "|                                                         |" << endl;
    cout << "|   Deseja listar os aeroportos? s/n                      |" << endl;
    cout << "|                                                         |" << endl;
    cout << "===========================================================" << endl;
    cout << endl;

    cout << "Opcao: ";
    cin >> opcao;

    while (opcao != "s" && opcao != "n" && opcao != "S" && opcao != "N") {
        cout << endl;
        cout << "Opcao invalida! Tente novamente: ";
        cin >> opcao;
        cout << endl;
    }

    if (opcao == "s" || opcao == "S") {
        clearScreen();
        cout << "===========================================================" << endl;
        cout << "|------------------------- INFO --------------------------|" << endl;
        cout << "   Latitude: " << latitude << "                                 " << endl;
        cout << "   Longitude: " << longitude << "                                 " << endl;
        cout << "   Raio: " << raio << "                                 " << endl;
        cout << "===========================================================" << endl;
        cout << "                                                       " << endl;

        for (int i = 0; i < aeroportos.size(); i++) {
            cout << "   Aeroporto " << i + 1 << ": " << lfile.getAeroportos().find(aeroportos[i])->second.getCodigo()
                 << " - " << lfile.getAeroportos().find(aeroportos[i])->second.getNome() << endl;
        }

        cout << "                                                           " << endl;
        cout << "===========================================================" << endl;

        wait();

    }
}

void print_voos(int origem, int destino){

    string op_menu;

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
            cout << "===========================================================" << endl;
            cout << "Nao existe voo entre os aeroportos indicados usando estas companhias: " << endl;
            cout << endl;
            cout << "Aeroporto de Origem: ["<< lfile.getAeroportos().find(origem)->second.getCodigo() << "] - " << lfile.getAeroportos().find(origem)->second.getNome() << endl;
            cout << "Aeroporto de Destino: ["<< lfile.getAeroportos().find(destino)->second.getCodigo() << "] - " << lfile.getAeroportos().find(destino)->second.getNome() << endl;
            cout << endl;
            cout << "Companhias: " << endl;
            for(const auto & comp : companhias){
                cout << "  -> [" << comp << "] - " << lfile.getCompanhias().find(lfile.getCompanhiasCodigos().find(comp)->second)->second.getNome() << endl;
            }
            cout << "===========================================================" << endl;
            wait();
        }
        else{

            clearScreen();
            cout << "===========================================================" << endl;
            cout << "Aeroporto de Origem: [" << lfile.getAeroportos().find(origem)->second.getCodigo() << "] - "
                 << lfile.getAeroportos().find(origem)->second.getNome() << endl;
            cout << "Aeroporto de Destino: [" << lfile.getAeroportos().find(destino)->second.getCodigo() << "] - "
                 << lfile.getAeroportos().find(destino)->second.getNome() << endl;
            cout << endl;
            cout << "Um dos caminhos possiveis com companhias especificas:" << endl;
            cout << endl;
            cout << lfile.getAeroportos().find(origem)->second.getCodigo() << " -> ";
            for (int i = (int) voo_companhia.size() - 1; i >= 0; i--) {
                if (i == 0) {
                    cout << lfile.getAeroportos().find(destino)->second.getCodigo() << endl;
                } else {
                    cout << lfile.getAeroportos().find(voo_companhia[i])->second.getCodigo() << " -> ";
                }
            }
            cout << endl;
            cout << "Companhias especificadas: " << endl;

            for(auto & comp : companhias){
                cout << "  -> [" << comp << "] - " << lfile.getCompanhias().find(lfile.getCompanhiasCodigos().find(comp)->second)->second.getNome() << endl;
            }
            cout << "===========================================================" << endl;
            wait();

        }

    }
    else {

        vector<int> voo = g.bfs_me(origem, destino);

        if(voo.empty()){
            clearScreen();
            cout << "===========================================================" << endl;
            cout << "Nao existe voo entre os aeroportos indicados usando estas companhias: " << endl;
            cout << endl;
            cout << "Aeroporto de Origem: ["<< lfile.getAeroportos().find(origem)->second.getCodigo() << "] - " << lfile.getAeroportos().find(origem)->second.getNome() << endl;
            cout << "Aeroporto de Destino: ["<< lfile.getAeroportos().find(destino)->second.getCodigo() << "] - " << lfile.getAeroportos().find(destino)->second.getNome() << endl;
            cout << endl;
            cout << "===========================================================" << endl;
            wait();

        }
        else{

            clearScreen();
            cout << "===========================================================" << endl;
            cout << "Aeroporto de Origem: [" << lfile.getAeroportos().find(origem)->second.getCodigo() << "] - "
                 << lfile.getAeroportos().find(origem)->second.getNome() << endl;
            cout << "Aeroporto de Destino: [" << lfile.getAeroportos().find(destino)->second.getCodigo() << "] - "
                 << lfile.getAeroportos().find(destino)->second.getNome() << endl;
            cout << endl;
            cout << "Um dos caminhos possiveis sem companhias especificas:" << endl;
            cout << endl;
            cout << lfile.getAeroportos().find(origem)->second.getCodigo() << " -> ";
            for (int i = (int) voo.size() - 1; i >= 0; i--) {
                if (i == 0) {
                    cout << lfile.getAeroportos().find(destino)->second.getCodigo() << endl;
                } else {
                    cout << lfile.getAeroportos().find(voo[i])->second.getCodigo() << " -> ";
                }
            }
            cout << "===========================================================" << endl;

            wait();
        }
    }
}




// Funcoes de clear screen e wait
void clearScreen() {
    for (int i = 0; i < 50; i++) {
        cout << endl;
    }
}

void wait() {
    cout << endl;
    int c; do c = getchar(); while ((c != '\n') && (c != EOF));
    cout << "Pressione ENTER para continuar...";
    cout << endl;
    do{ c = getchar(); }while ((c != '\n') && (c != EOF));
}
