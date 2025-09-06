#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <iomanip> 
#include <chrono>


using namespace std;

int sı() {
	int sıra = 0;
	ifstream d("kayıt.txt");
	string sır;
	if (d.is_open()) {
		while (getline(d, sır)) {
			sıra++;
		}
	}
	else {
		cout << "dosya bulamadı";
	}
	d.close();
	return sıra;
}
void reg() {
	string kull, pass;
	cout << "Lütfen kayıt etmek istediğiniz kullanıcı adını girin:\t";
	cin >> kull;
	cout << "Lütfen kayıt etmek istediğiniz şifreyi girin\t";
	cin >> pass;
	ofstream y("kayıt.txt", ios::app);
	string yaz;
	y << sı() << "." << kull << ":" << pass<<"\n";
	cout << "İşlem Başarılı" << endl;
}
string loga() {
	vector<string>veer;
	string kul, pas,oku;
	string verkull[100], verpas[100];
	ifstream x("kayıt.txt");
	if (x.is_open()) {
		while (getline(x, oku)) {
			veer.push_back(oku);
		}
	}
	x.close();
	for (int a = 0; sı() > a; a++) {
		size_t nokta = veer[a].find('.');
		size_t ıkınokta = veer[a].find(':');
		verkull[a] = veer[a].substr(nokta+1, ıkınokta - nokta-1);
		verpas[a] = veer[a].substr(ıkınokta + 1);
	}
	cout << "Lütfen kullanıcı adını girin:\t";
	cin >> kul;
	int kontrol = 0;
	int denemeSayisi = 0;
	int maxDenemeSayisi = 3;

	while (kontrol != 1) {
		for (int c = 0; c < sizeof(verkull) / sizeof(verkull[0]); c++) {
			if (kul == verkull[c]) {
				while (kontrol != 1 && denemeSayisi < maxDenemeSayisi) {
					cout << "Şifrenizi girin: ";
					cin >> pas;
					if (pas == verpas[c]) {
						kontrol = 1;
						cout << "Giriş başarılı!" << endl;
						return kul; 
					}
					else {
						denemeSayisi++;
						cout << "Şifre yanlış, tekrar deneyin. Kalan deneme hakkı: " << maxDenemeSayisi - denemeSayisi << endl;
					}
				}
				if (denemeSayisi >= maxDenemeSayisi) {
					cout << "3 yanlış deneme yaptınız. Giriş başarısız!" << endl;
					return 0;
				}
				break;  
			}
		}

		if (kontrol != 1) {
			cout << "Kullanıcı bulunamadı, tekrar girin:\t";
			cin >> kul;
		}
	}
}
void kıtapreg() {
	setlocale(LC_ALL, "Turkish");
	string kıtaoo;
	ifstream y("kıtap.txt");
	string dev;
	int kıtapss = 0;
	while (getline(y, dev)) {
		kıtapss++;
	}
	y.close();
	cout << "Kitap listesine hoş geldiniz\n";
	cout << "Kayıt etmek istediğiniz kitap adını girin : \t";
	cin >> kıtaoo;
	ofstream t("kıtap.txt", ios::app);
	t<<"\n" << kıtapss<< "." << " " << kıtaoo;
	t.close();
	cout << "kitap başarılı ile kaydedildi";
}
string kıtapsec() {
	setlocale(LC_ALL, "Turkish");
	vector<string>kıtaplar;
	int sec=0;
	cout << "Kitap listesine hoş geldiniz\n";
	cout << "Seçmek istediğiniz kitabın numarasını tuşlayın : \n";
	ifstream u("kıtap.txt");
	string oku;
	int kıtapsay = 0;
	while (getline(u, oku)) {
		kıtapsay++;
		kıtaplar.push_back(oku);
	}
	u.close();
	for (int a = 0; kıtapsay > a; a++) {
		cout << kıtaplar[a]<<endl;
	}
	cin >> sec;
	return kıtaplar[sec];
	
}
void kıtapver(string kul) {
	string numra,kıtap;
	cout << "Lütfen kitap vermek istediğiniz öğrenci numarasını griin:\t";
	cin >> numra;
	auto now = chrono::system_clock::now();

	// Zamanı sistem saatine dönüştür
	time_t now_c = chrono::system_clock::to_time_t(now);

	// Zamanı struct tm formatına güvenli bir şekilde çevir
	tm now_tm;
	localtime_s(&now_tm, &now_c);  // Güvenli versiyon olan localtime_s kullanılıyor
	kıtap = kıtapsec();
	string yaz = numra + ".txt";
	ofstream x(yaz,ios::app);
	x << kıtap <<"::::::" <<"Veriliş tarihi\t" << put_time(&now_tm, "%Y-%m-%d %H:%M:%S")<<":::Veren kullanıcı:"<<kul<< "\n";

}
int ogrsı() {
	int sıra = 0;
	ifstream d("ogrkayıt.txt");
	string sır;
	if (d.is_open()) {
		while (getline(d, sır)) {
			sıra++;
		}
	}
	else {
		cout << "dosya bulamadı";
	}
	d.close();
	return sıra;
}
void ogrreg() {
	vector<string>numara;
	string num[100];
	string kull, pass,number;
	cout << "Lütfen kayıt etmek istediğiniz öğrenci adını girin:\t";
	cin >> kull;
	ifstream t("ogrkayıt.txt");
	string deneme;
	while (getline(t, deneme)) {
		numara.push_back(deneme);
	}
	t.close();
	for (int p = 0; ogrsı() > p; p++) {
		size_t vırgul = numara[p].find(',');
		num[p] = numara[p].substr(vırgul+1);
	}
	cout << "Lütfen kayıt etmek istediğiniz öğrenci numarasnı girin:\t";
	cin >> number;
	for (int g = 0; ogrsı() > g; g++) {
		while (num[g] == number) {
			cout << "Aynı numara bulundu tekrar griin:\t";
			cin >> number;
		}
	}
	while (number.length() != 5) {
		cout << "Lütfen 5 haneli olacak şekilde numarayı girin";
		cin >> number;
	}
	
	ofstream y("ogrkayıt.txt", ios::app);
	string yaz;
	y << ogrsı() << "." << kull << "," << number << "\n";
	y.close();
	cout << "İşlem Başarılı" << endl;
	
}


int main() {
	setlocale(LC_ALL, "Turkish");
	string kulla = loga();  // Kullanıcı adı ve şifre ile giriş yapılacak
	if (kulla == "0") {
		cout << "Giriş başarısız, program sonlandırılıyor." << endl;
		return 0;
	}

	int secim;
	do {
		// Ana menü
		cout << "\nAna Menü:\n";
		cout << "1. Kullanıcı kaydı\n";
		cout << "2. Kitap kaydı\n";
		cout << "3. Kitap verme\n";
		cout << "4. Öğrenci kaydı\n";
		cout << "5. Çıkış\n";
		cout << "Seçiminizi yapın: ";
		cin >> secim;

		switch (secim) {
		case 1:
			reg();  // Kullanıcı kaydı
			break;
		case 2:
			kıtapreg();  // Kitap kaydı
			break;
		case 3:
			kıtapver(kulla);  // Kitap verme
			break;
		case 4:
			ogrreg();  // Öğrenci kaydı
			break;
		case 5:
			cout << "Çıkış yapılıyor..." << endl;
			break;
		default:
			cout << "Geçersiz seçim, tekrar deneyin." << endl;
			break;
		}
	} while (secim != 5);  // Çıkış seçeneği seçilene kadar menü tekrar gösterilecek

	return 0;
}