#include <iostream>
#include <queue>
using namespace std;

struct Packet {
    int at, pt, rt;
    Packet(): rt(-1) {}
};

int main() {
    int bc, np; cin>>bc>>np;
    Packet pkt[np];
    for(int i = 0; i<np; i++) 
        cin>>pkt[i].at>>pkt[i].pt;
    queue<Packet*> kyu;
    int bs = 0, i = 0, t = 0;
    for(t = 0; i<np; t++) {
        if(bs && (kyu.front()->rt+kyu.front()->pt)<=t){
            if((kyu.front()->rt+kyu.front()->pt)<t) 
                t = kyu.front()->rt+kyu.front()->pt;
            kyu.pop();
            bs--;
        } 
        while(i<np && pkt[i].at==t && bs<bc) {
            kyu.push(&pkt[i++]);
            bs++;
        } 
        while(i<np && kyu.front()->pt && pkt[i].at==t)
            pkt[i++].rt=-1;
        if(bs && kyu.front()->rt==-1) 
            kyu.front()->rt = t; 
    }
    while(bs) {
        t = kyu.front()->pt+kyu.front()->rt;
        kyu.pop();
        bs--;
        if(bs) {
            kyu.front()->rt = t;
            t+=kyu.front()->pt;
        }
    }
    for(auto& p : pkt) 
        cout<<p.rt<<endl;
    return 0;
}
