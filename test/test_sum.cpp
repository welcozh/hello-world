#include <time.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char *argv[]) {

    time_t start, end;

    start = time(NULL);

    long long len = 1000000000;

    long long *r = new long long[len];

//    omp_set_num_threads(40);    
//#pragma omp parallel for
    for(long i=0; i<len; i++)
        r[i] += i;

    end = time(NULL);

    cout << "time: " << end - start << "s" << endl;

    return 1;
}
