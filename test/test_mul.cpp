#include <time.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char *argv[]) {

    time_t start, end;

    start = time(NULL);

    long long len = 10000000000;
    double *r = new double[len];

    omp_set_num_threads(40);
    #pragma omp parallel for
    for(long long i=0; i<10000000000; i++) {
        r[i] += 1;
        r[i] *= 1.0000001;
    }
    end = time(NULL);

    cout << "time: " << end - start << "s" << endl;

    return 1;
}
