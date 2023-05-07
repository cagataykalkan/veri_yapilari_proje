//
//  main.cpp
//  veri_yapilari_proje_1
//
//  Created by Çağatay KALKAN on 7.05.2023.
//

#include <iostream>
#include <queue>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

struct kisi {
    int id;
    int islem_suresi;
};

//işlem süresi en kısa olan kişiyi öncelikli hale getirir
struct karsılastırma {
    bool operator()(const kisi& p1, const kisi& p2) const {
        return p1.islem_suresi > p2.islem_suresi;
    }
};

int main() {
    
    // kuyruktaki kişi sayısı
    int kisi_sayisi;
    cout<<"*---------------------------------------------------------*";
    cout <<endl<<endl<< "\t\tKargo subesindeki kisi sayisini girin: ";
    cin >> kisi_sayisi;

    cout<<endl;

    
    cout<<"\t\t"<< kisi_sayisi<<" Kisilik kuyruk oluşturuluyor..."<<endl<<endl;
    cout<<"\t\t"<<"                 |"<<endl;
    cout<<"\t\t"<<"                 |"<<endl;
    cout<<"\t\t"<<"                 V"<<endl<<endl;

    // Kuyruk ve yığın tanımlama
    priority_queue<kisi, vector<kisi>, karsılastırma> os;  //os = öncelik sırası
    
    vector<int> id_yıgın; // Yığın
    vector<int> sure_yıgın; // Yığın
    
    // Kişilerin işlem sürelerini ve sıra numaralarını oluştur
    for (int i = 0; i < kisi_sayisi; i++) {
        int islem_suresi = rand() % 271 + 30; // rastgele işlem süresi hesaplanıyor
        cout <<"\t\t"<< i+1 << ". kisinin islem suresi: " << islem_suresi << " sn" << endl;
        os.push({i+1, islem_suresi});
    }

    // Kuyruktan kişileri çıkar ve işlem sürelerini hesapla
    int toplam_sure = 0;
    while (!os.empty()) {
        kisi p = os.top();
        os.pop();
        toplam_sure += p.islem_suresi;
        id_yıgın.push_back(p.id);
        sure_yıgın.push_back(p.islem_suresi);
    }
    
    cout<<endl;

    // Ortalama işlem süresi hesaplama
    double ortalama_sure = static_cast<double>(toplam_sure) / kisi_sayisi;
    cout <<"\t\t"<< "Ortalama islem suresi: " << ortalama_sure << " sn" << endl;
    
    cout<<endl;

    //daha fazla bekleyen kişileri listeleyerek sıra numaralarını ve işlem sürelerini yazdır
    cout<<"\t\t"<< "daha fazla bekleyen kisiler: " << endl;
    int bekleme_suresi = 0;
    for (int i = 0; i < kisi_sayisi; i++) {
        bekleme_suresi += os.top().islem_suresi;
        os.pop();
        if (bekleme_suresi > i * ortalama_sure) {
            cout<<"\t\t"<< "Kisi #" << id_yıgın[i] << ", islem suresi: " << sure_yıgın[i] << " sn" << endl;
        }
    }

    return 0;
}
