using namespace std;

vector<double> differentialModel() {
    double Sv0 = 10; // Suspected Vector
    double Sh0 = 10; // Suspected Host
    double Iv0 = 10; // Infected Vector
    double Ih0 = 10; // Infected Host
    double Dv0 = 10; // Death rate Vector
    double Dh0 = 10; // Death rate Host
    double Bv0 = 10; // Transmission Rate vector
    double Bh0 = 10; // Transmission Rate Host
    double R0 = 10; // No. of Recovered Patients
    double r = 10; // Recovery Rate of Patients

    // dSh/dt = -BhShIv;
    // dIh/dt = BhShIv - rIh;
    // dR/dt = +rIh;
    // dIv/dt = BvSvIh - dvIv;

    double dt = 0.01;
    double n = 1 / dt + 1;
    
    vector<double> Sh;
    vector<double> Ih;
    vector<double> R;
    vector<double> Iv;

    Sh.push_back(Sh0);
    Ih.push_back(Ih0);
    R.push_back(R0);
    Iv.push_back(Iv0);

    for(int i = 1; i <= (int)n; i++) {
        double prev_Sh = Sh.back();
        double prev_Ih = Ih.back();
        double prev_R = R.back();
        double prev_Iv = Iv.back();

        // dSh/dt = -BhShIv;
        // (next_Sh - prev_Sh) / dt = - Bh0 * prev_Sh * prev_Iv;
        // next_Sh = prev_Sh - Bh0 * prev_Sh * prev_Iv * dt;
        double next_Sh = prev_Sh - Bh0 * prev_Sh * prev_Iv * dt;
        Sh.push_back(next_Sh);

        // dIh/dt = BhShIv - rIh;
        // (next_Ih - prev_Ih) / dt = Bh0 * prev_Sh * prev_Iv * dt - r * prev_Ih;
        // next_Ih = prev_Ih + (Bh0 * prev_Sh * prev_Iv * dt - r * prev_Ih) * dt;
        double next_Ih = prev_Ih + (Bh0 * prev_Sh * prev_Iv * dt - r * prev_Ih) * dt;
        Ih.push_back(next_Ih);

        // dR/dt = +rIh;
        // (next_R - prev_R) / dt = r * prev_Ih;
        // next_R = prev_R + r * prev_Ih * dt;
        double next_R = prev_R + r * prev_Ih * dt;
        R.push_back(next_R);

        // dIv/dt = BvSvIh - DvIv;
        // (next_Iv - prev_Iv) / dt = Bv0 * Sv0 * prev_Ih - Dv0 * prev_Iv;
        // next_Iv = prev_IV + (Bv0 * Sv0 * prev_Ih - Dv0 * prev_Iv) * dt;
        double next_Iv = prev_IV + (Bv0 * Sv0 * prev_Ih - Dv0 * prev_Iv) * dt;
        Iv.push_back(next_Iv);
    }
    
    return Iv;
}