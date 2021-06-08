#include <time.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char *argv[]) {

    time_t start, end;

    start = time(NULL);

    int r = 1;
//    #pragma omp parallel for
    for(long long i=0; i<1000000000; i++)
        r += 1;

    end = time(NULL);

    cout << "sum: " << r << "   time: " << end - start << "s" << endl;

    return 1;
}
