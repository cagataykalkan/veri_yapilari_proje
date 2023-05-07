//
//  main.cpp
//  veri_yapilari_proje
//
//  Created by Çağatay KALKAN on 4.05.2023.
//

#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <list>
#include <stack>
#include <queue>


using namespace std;

int main() {

    // kuyruktaki kişi sayısı
    int kisi_sayisi;
    cout<<"*----------------------------------------------------------*";
    cout <<endl<< "\t\tKargo subesindeki kisi sayisini girin: ";
    cin >> kisi_sayisi;
    
    cout<<endl;

    cout<<"\t\t"<< kisi_sayisi<<" Kisilik kuyruk oluşturuluyor..."<<endl<<endl;
    cout<<"\t\t"<<"                 |"<<endl;
    cout<<"\t\t"<<"                 |"<<endl;
    cout<<"\t\t"<<"                 V"<<endl<<endl;
    
    // kişi listesi
    list<int> liste;
    for (int i = 1; i <= kisi_sayisi; i++) {
        
        // rastgele işlem süresi hesaplanıyor
        int sure = rand() % 271 + 30;
        
        // kişi listeye ekleniyor
        liste.push_back(i);
        
        cout<<"\t\t" << i << ". kisinin islem suresi: " << sure << " sn\n";
    }
    
    cout<<endl;
    
   
    
    //yığın oluşturma
    stack<int> yıgın;
    
    // Listeyi yığına ekleyin
        for (auto it = liste.rbegin(); it != liste.rend(); ++it) {
            yıgın.push(*it);
        }
    
    //kuyruk oluşturma
    queue<int> kuyruk;
    
    // yığındaki elemanları kuyruğa ekle
    while (!yıgın.empty()) {
            kuyruk.push(yıgın.top());
            yıgın.pop();
        }
    
    //kişiler arasında dolaşmak için iterator oluşturuldu
    list<int>::iterator itr;
    
    // işlem süresi hesaplamak için kullanılacak toplam zaman değişkeni
    int zaman = 0;
    
    itr = liste.begin();
    
    for (itr; itr != liste.end(); itr++) {
        
        // rastgele işlem süresi hesaplanıyor
        int sure = rand() % 271 + 30;
        
        // kişinin işlemi bitme zamanı hesaplanıyor
        int bitis_zamani = zaman + sure;
        
        cout<<"\t\t" << *itr << ". kisi islem Baslangic zamani: " << zaman << " sn, "<< "Bitis zamani: " << bitis_zamani << " sn, "<< "Toplam sure: " << bitis_zamani - zaman << " sn\n";
        
        // toplam zaman güncelleniyor
        zaman = bitis_zamani;
    }
    
    cout<<endl;
    
    // ortalama işlem süresi hesaplanıyor
    double ortalama = (double)zaman / kisi_sayisi;
    cout <<"\t\t" <<"Ortalama islem tamamlanma suresi: " << ortalama << " sn\n";
    
    cout<<endl<<endl;
    
     
     
     
     
     

    return 0;
}
