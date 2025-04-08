#include <iostream>
#include <thread>
#include <vector>
#include <time.h>
using namespace std;

char alphabetic[] = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&*()_+=-,./?\\';:][}{|йцукенгшщзхъфывапролджэячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";
constexpr int length = sizeof(alphabetic) - 1;
bool taskDone = false;
string password = "";

bool isvalidPwd(const char* pwd)
{
    return strcmp(pwd, "JrcЮ") == 0;
    //return pwd == "JrcЮ";
}

void hackPwd(int lo, int hi)
{
    char pwd[5] = { '\0','\0', '\0', '\0', '\0', };
    size_t iter = 0;
    for (int i = lo; i < hi; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (taskDone)
            {
                return;
            }
            for (int k = 0; k < length; k++)
            {
                for (int l = 0; l < length; l++)
                {
                    pwd[0] = alphabetic[i];
                    pwd[1] = alphabetic[j];
                    pwd[2] = alphabetic[k];
                    pwd[3] = alphabetic[l];
                    iter++;
                    if (isvalidPwd(pwd))
                    {
                        taskDone = true;
                        password = string(pwd);
                        cout << alphabetic[lo] << " " << alphabetic[hi - 1] << endl;
                        cout << "Iterations count: " << iter << endl;
                        return;
                    }
                }
            }
        }
    }

}

int main()
{
    setlocale(LC_CTYPE, "");
    unsigned int maxThreads = thread::hardware_concurrency();
    auto start = clock();
    if (maxThreads > 1)
    {
        int chunk = length / maxThreads;
        vector<thread> threads;
        for (int i = 0; i < maxThreads; i++)
        {
            int start = i * chunk;
            int end;
            if (i < maxThreads - 1)
                end = start + chunk;
            else
                end = length;
            threads.emplace_back(hackPwd, start, end);
        }
        for (int i = 0; i < maxThreads; i++)
            if (threads[i].joinable())
                threads[i].join();
    }
    else
    {
        hackPwd(0, length);
    }
    auto end = clock();
    cout << password << endl;
    cout << "Time elapsed: " << end - start << " ms\n";
}

