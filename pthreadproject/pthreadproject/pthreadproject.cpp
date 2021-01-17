#include "pch.h"
#include <iostream>
#include <pthread.h> //в Visual Studio нет, скачал из Интернета и подключил; нужные файлы находятся в папке libpthread; для обоих проектов прописаны пути доп. библиотек вида "C:\Users\Болычев Леонид\C++\pthreadproject\libpthread\lib\x86", и чтобы запустить на другом компьютере в Visual Studio, может понадобиться редактировать пути
#include <fstream>
#include <windows.h>
#include <string>
#include <thread>
#include <sstream>

using namespace std;

void* summfunction(void* i)
{
    long long filesumm = 0;
    long long summ = 0;
    int j = (int)i;
    ifstream finput;
         if (j == 0) { finput.open("inputfile0.txt"); }
    else if (j == 1) { finput.open("inputfile1.txt"); }
    else if (j == 2) { finput.open("inputfile2.txt"); }
    else if (j == 3) { finput.open("inputfile3.txt"); }
    else if (j == 4) { finput.open("inputfile4.txt"); }
    else if (j == 5) { finput.open("inputfile5.txt"); }
    else if (j == 6) { finput.open("inputfile6.txt"); }
    else if (j == 7) { finput.open("inputfile7.txt"); }
    else if (j == 8) { finput.open("inputfile8.txt"); }
    else if (j == 9) { finput.open("inputfile9.txt"); }

    while (!finput.eof())
    {
        finput >> summ;
        filesumm = filesumm+summ;
    }

    finput.close();
    return (void*)filesumm;
}

int onethreadsumm()
{
    long long finalsumm = 0;
    int begintime = clock();

    for (int i = 0; i < 10; ++i)
    {
        finalsumm = finalsumm + (int)summfunction((void*)i);
    }

    int endtime = clock();
    cout << "Time (one  thread):  " << endtime-begintime << endl;
    cout << "Summ (one  thread):  " << finalsumm << endl << endl;
    return finalsumm;

}

int manythreadsumm()
{

    long long finalsumm = 0;
    int begintime = clock();
 
    pthread_t thread[10];
    int sum;
    for (int i = 0; i < 10; ++i)
    {
        pthread_create (&thread[i], NULL, summfunction, (void*)i);
        finalsumm = finalsumm + (int)summfunction((void*)i);
    }
    for (int i = 0; i < 10; ++i)
    {
        pthread_join (thread[i], NULL);
    }



    int endtime = clock();
    cout << "Time (many threads): " << endtime - begintime << endl;
    cout << "Summ (many threads): " << finalsumm << endl << endl;
    
    return finalsumm;
}