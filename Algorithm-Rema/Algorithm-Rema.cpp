#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void Graf(int** G, int n, int m) 
{
    G[0][0] = 0; G[0][ 1] = 0;   //первые [] номер пвры рёбер, вторые [] 0-влево 1-вправо
    int sum=0;
    for (int i = 1; i <= m/2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum += 1;
            G[i][j] = sum;
        }

    }
}

void bezhitr(int* comp, int** e, int n, int m) 
{
    for (int i = 0; i < n; i++)
        comp[i] = i;
    int q = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m/2; j++)
        {
            q = min(comp[e[j][0]], comp[e[j][1]]);
            comp[e[j][0]] = q;
            comp[e[j][1]] = q;
        }
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

void Rem(int* comp, int** e, int n, int m)
{
    int n1, n2;
    int* p = new int[n];
    for (int i = 0; i < n; i++)
        sozd(p, i);
    for (int j = 0; j < m/2; j++)
    {
        n1 = search(p, e[j][0]);
        n2 = search(p, e[j][1]);
        if (n1 != n2) 
            obed(p, n1, n2);
    }
    for (int i = 0; i < n; i++)
    {
        comp[i] = search(p, i);
    }
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
        cout << "4. Завершить" << endl;
        int flag = 0;
        cin >> flag;
        if (flag == 1)
        {
            for (int n = 1; n <= (pow(10,3) + 1);n+=10)
            {
                int m;
                m = (n ^ 2) / 10;
                int** G = new  int* [(m / 2) + 1];
                for (int i = 0; i <= m / 2; i++)
                    G[i] = new int[3];
                Graf(G, n, m);
                int* comp = new int[n], * com = new int[n];
                start_time = clock();
                bezhitr(comp, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << search_time;
                cout << "   ";
                start_time = clock();
                Rem(com, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << search_time << endl;
                for (int i = 0; i <( m / 2)+1; i++)
                    delete[] G[i];
                delete[]G;
            }
            cout << "Первый столбец - время выполнения бесхитростного алгоритма" << endl;
            cout << "Второй столбец - время выполнения алгоритма Рэма" << endl;
            cout << "Алгоритм Рэма выполняется быстрее" << endl;
            cout << endl;
        }
        if (flag == 2)
        {
            for (int n = 1; n <= (pow(10, 3) + 1); n += 10)
            {
                int m;
                m = n-1;
                int** G = new  int* [(m / 2) + 1];
                for (int i = 0; i <= m / 2; i++)
                    G[i] = new int[3];
                Graf(G, n, m);
                int* comp = new int[n], * com = new int[n];
                start_time = clock();
                bezhitr(comp, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << search_time;
                cout << "   ";
                start_time = clock();
                Rem(com, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << search_time << endl;
                for (int i = 0; i < m / 2; i++)
                    delete[] G[i];
                delete[]G;
            }
            cout << "Первый столбец - время выполнения бесхитростного алгоритма" << endl;
            cout << "Второй столбец - время выполнения алгоритма Рэма" << endl;
            cout << "Алгоритм Рэма выполняется быстрее" << endl;
            cout << endl;
        }
        if (flag == 3)
        {
            for (int n = 1; n <= (pow(10, 3) + 1); n += 10)
            {
                int m;
                m = log2(n);
                int** G = new  int* [(m / 2) + 1];
                for (int i = 0; i <= m / 2; i++)
                    G[i] = new int[3];
                Graf(G, n, m);
                int* comp = new int[n], * com = new int[n];
                start_time = clock();
                bezhitr(comp, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << search_time;
                cout << "   ";
                start_time = clock();
                Rem(com, G, n, m);
                end_time = clock();
                search_time = end_time - start_time;
                cout << search_time << endl;
                for (int i = 0; i < m / 2; i++)
                    delete[] G[i];
                delete[]G;
            }
            cout << "Первый столбец - время выполнения бесхитростного алгоритма" << endl;
            cout << "Второй столбец - время выполнения алгоритма Рэма" << endl;
            cout << "Алгоритм Рэма выполняется быстрее" << endl;
            cout << endl;
        }
        if (flag == 4)
            break;
    }
}