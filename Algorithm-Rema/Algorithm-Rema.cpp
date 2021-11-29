#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void Graf(int** G, int m) 
{
   // G[0][0] = 0; G[0][ 1] = 0;   //первые [] номер пары рёбер, вторые [] 0-влево 1-вправо
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            G[i][j] = rand()%10;
        }

    }
}

int bezhitr(int* comp, int** e, int n, int m) 
{
    int cou = 0;
    for (int i = 0; i < n; i++)
    {
        comp[i] = i;
        cou++;
    }
    int q = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
        {
            q = min(comp[e[j][0]], comp[e[j][1]]);
            comp[e[j][0]] = q;
            comp[e[j][1]] = q;
            cou++;
        }
    return cou;
}


/*int reb(int n, int& x1, int& y1) // создает  случайное  ребро .
{
    return 0;
}

//graf(int** e, int n, int m) // процедура создания случайного графа G(n, m) с заданными параметрами.

void rebrplus(int** e, int n, int m) // процедура  добавления  случайного ребра.
{

}*/

void sozd(int* p, int i) // создание синглетона{ i }.
{
    p[i] = i;
}

void obed(int* p, int i, int j) // объединение множества коллекции K с именами i и j.
{
    for (int n = 0; n < sizeof(p) / sizeof(p[0]); n++)
    {
        if (p[n] == p[j])
        {
            p[n] = i;
        }
    }
}

int search(int* p, int x) // найти имя множества коллекции K, содержащее элемент x.
{
    if (p[x])
        return p[x];
    return 0;
}

int Rem(int* comp, int** e, int n, int m)
{
    int n1, n2,cou=0;
    int* p = new int[n];
    for (int i = 0; i < n; i++)
    {
        sozd(p, i);
        cou++;
    }
    for (int j = 0; j < m; j++)
    {
        n1 = search(p, e[j][0]);
        n2 = search(p, e[j][1]);
        if (n1 != n2) 
            obed(p, n1, n2);
        cou++;
    }
    for (int i = 0; i < n; i++)
    {
        comp[i] = search(p, i);
        cou++;
    }
    return cou;
}

void main()
{
    setlocale(LC_ALL, "rus");
    unsigned int start_time;
    unsigned int end_time;
    unsigned int search_time;
    while (true)  
    {
        cout << "Выберите нужный пункт при n=1,...,10^3+1:" << endl;
        cout << "1. m=n^2/10" << endl;
        cout << "2. m=n-1" << endl;
        cout << "3. m=log2(n)" << endl;
        cout << "4. m=rand()%n" << endl;
        cout << "5. Завершить" << endl;
        int flag = 0;
        cin >> flag;
        if (flag == 1)
        {
            for (int n = 1; n <= (pow(10,3) + 1);n+=10)
            {
                int m = (n ^ 2) / 10;
                int** G = new  int* [m];
                for (int i = 0; i < m; i++)
                    G[i] = new int[2];
                Graf(G, m);
                int* comp = new int[n], * com = new int[n];
                start_time = clock();
                int coubez=bezhitr(comp, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << coubez<<",";
                cout<<search_time;
                cout << "   ";
                start_time = clock();
                int couRem=Rem(com, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << couRem << ",";
                cout<<search_time << endl;
                for (int i = 0; i < m; i++)
                    delete[] G[i];
                delete[]G; 
            }
            cout << "До запятой количество тиков, после время" << endl;
            cout << "Первый столбец - бесхитростный алгоритм" << endl;
            cout << "Второй столбец - алгоритм Рэма" << endl;
            cout << "Алгоритм Рэма выполняется быстрее" << endl;
            cout << endl;
        }
        if (flag == 2)
        {
            for (int n = 1; n <= (pow(10, 3) + 1); n += 10)
            {
                int m = n-1;
                int** G = new  int* [m];
                for (int i = 0; i < m; i++)
                    G[i] = new int[2];
                Graf(G, m);
                int* comp = new int[n], * com = new int[n];
                start_time = clock();
                int coubez = bezhitr(comp, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << coubez << ",";
                cout << search_time;
                cout << "   ";
                start_time = clock();
                int couRem = Rem(com, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << couRem << ",";
                cout << search_time << endl;
                for (int i = 0; i < m; i++)
                    delete[] G[i];
                delete[]G;
            }
            cout << "До запятой количество тиков, после время" << endl;
            cout << "Первый столбец - бесхитростный алгоритм" << endl;
            cout << "Второй столбец - алгоритм Рэма" << endl;
            cout << "Алгоритм Рэма выполняется быстрее" << endl;
            cout << endl;
        }
        if (flag == 3)
        {
            for (int n = 1; n <= (pow(10, 3) + 1); n += 10)
            {
                int m = log2(n);
                int** G = new  int* [m];
                for (int i = 0; i < m; i++)
                    G[i] = new int[2];
                Graf(G, m);
                int* comp = new int[n], * com = new int[n];
                start_time = clock();
                int coubez = bezhitr(comp, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << coubez << ",";
                cout << search_time;
                cout << "   ";
                start_time = clock();
                int couRem = Rem(com, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << couRem << ",";
                cout << search_time << endl;
                for (int i = 0; i < m; i++)
                    delete[] G[i];
                delete[]G;
            }
            cout << "До запятой количество тиков, после время" << endl;
            cout << "Первый столбец - бесхитростный алгоритм" << endl;
            cout << "Второй столбец - алгоритм Рэма" << endl;
            cout << "Алгоритм Рэма выполняется быстрее" << endl;
            cout << endl;
        }
        if (flag ==4)
        {
            for (int n = 1; n <= (pow(10, 3) + 1); n += 10)
            {
                int m = rand()%n;
                int** G = new  int* [m];
                for (int i = 0; i < m; i++)
                    G[i] = new int[2];
                Graf(G, m);
                int* comp = new int[n], * com = new int[n];
                start_time = clock();
                int coubez = bezhitr(comp, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << coubez << ",";
                cout << search_time;
                cout << "   ";
                start_time = clock();
                int couRem = Rem(com, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << couRem << ",";
                cout << search_time << endl;
                for (int i = 0; i < m; i++)
                    delete[] G[i];
                delete[]G;
            }
            cout << "До запятой количество тиков, после время" << endl;
            cout << "Первый столбец - бесхитростный алгоритм" << endl;
            cout << "Второй столбец - алгоритм Рэма" << endl;
            cout << "Алгоритм Рэма выполняется быстрее" << endl;
            cout << endl;
        }
        if (flag == 5)
            break;
    }
}