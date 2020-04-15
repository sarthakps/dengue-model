using namespace std;

class Host{

    public:
    bool isImmune;

    public: Host(bool isImmune){
        this->isImmune = isImmune;
    }

};


//to make given number of hosts
void makeHosts(vector<Host> &hosts, int amount){

    for(int i = 0; i<amount; i++){
        if(i<200){
            Host host(true);
            hosts.push_back(host);
        } else {
            Host host(false);
            hosts.push_back(host);
        }
    }

    random_shuffle(hosts.begin(), hosts.end());
}