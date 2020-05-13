using namespace std;

double* differentialModel() {
    int Sv0 = 10; // Suspected Vector
    int Sh0 = 10; // Suspected Host
    int Iv0 = 10; // Infected Vector
    int Ih0 = 10; // Infected Host
    int Dv0 = 10; // Death rate Vector
    int Dh0 = 10; // Death rate Host
    int Bv0 = 10; // Transmission Rate vector
    int Bh0 = 10; // Transmission Rate Host

    // dIv/dt = BvSvIh - dvIv
    double dt = 0.01;
    double n = 1 / dt + 1;
    
    double Iv[(int)n];

    Iv[0] = Iv0;

    int prev = 1;
    int next;
    for(int i = 1; i < n; i++) {
        // dIv/dt = BvSvIh - dvIv
        next = prev + Bv0*Sv0*Ih0 - Dv0*Iv(i - 1);
        Iv[i] = next;
        prev = next;
    }
    
    return Iv;
}