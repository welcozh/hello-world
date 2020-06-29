#include <time.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char *argv[]) {

    time_t start, end;

    start = time(NULL);

    long long r = 1;
//    #pragma omp parallel for
    for(long long i=0; i<10000000000; i++)
        r *= 1.0000001;

    end = time(NULL);

    cout << "mul: " << r << "   time: " << end - start << "s" << endl;

    return 1;
}
