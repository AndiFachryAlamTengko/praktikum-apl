#include <iostream>
using namespace std;

int main() {
    string namaPengguna, nomorIndukMahasiswa;
    int jumlahPercobaanLogin = 0;
    while (jumlahPercobaanLogin < 3) {
        cout << "Masukkan Nama Pengguna: ";
        getline(cin, namaPengguna);
        cout << "Masukkan NIM: ";
        cin >> nomorIndukMahasiswa;

        if (namaPengguna == "Andi Fachry Alam Tengko" && nomorIndukMahasiswa == "006") {
            cout << "Login berhasil!\n";
            break;
        } else {
            cout << "Nama Pengguna atau NIM salah. Coba lagi.\n";
            jumlahPercobaanLogin++;
        }

        if (jumlahPercobaanLogin == 3) {
            cout << "Anda gagal login 3 kali. Program selesai.\n";
            return 0;
        }
    }

    int pilihanMenu;
    while (true) {
        cout << "\nMenu Konversi Panjang:\n1. Konversi dari Meter\n2. Konversi dari Centimeter\n3. Konversi dari Mile\n4. Konversi dari Foot\n5. Keluar\nPilih menu (1/2/3/4/5): ";
        cin >> pilihanMenu;
        if (pilihanMenu == 1) {
            int pilihanKonversiMeter;
            cout << "\nPilih konversi dari Meter:\n";
            cout << "1. Meter ke Centimeter\n";
            cout << "2. Meter ke Mile\n";
            cout << "3. Meter ke Foot\n";
            cout << "Pilih pilihan (1/2/3): ";
            cin >> pilihanKonversiMeter;

            float nilaiMeter;
            if (pilihanKonversiMeter == 1) {
                cout << "Masukkan nilai dalam meter: ";
                cin >> nilaiMeter;
                cout << nilaiMeter << " meter = " << nilaiMeter * 100 << " centimeter\n";
            } else if (pilihanKonversiMeter == 2) {
                cout << "Masukkan nilai dalam meter: ";
                cin >> nilaiMeter;
                cout << nilaiMeter << " meter = " << nilaiMeter / 1609.34 << " mile\n";
            } else if (pilihanKonversiMeter == 3) {
                cout << "Masukkan nilai dalam meter: ";
                cin >> nilaiMeter;
                cout << nilaiMeter << " meter = " << nilaiMeter * 3.28084 << " foot\n";
            } else {
                cout << "Pilihan tidak valid!\n";
            }
        } else if (pilihanMenu == 2) {
            int pilihanKonversiCentimeter;
            cout << "\nPilih konversi dari Centimeter:\n";
            cout << "1. Centimeter ke Meter\n";
            cout << "2. Centimeter ke Mile\n";
            cout << "3. Centimeter ke Foot\n";
            cout << "Pilih pilihan (1/2/3): ";
            cin >> pilihanKonversiCentimeter;

            float nilaiCentimeter;
            if (pilihanKonversiCentimeter == 1) {
                cout << "Masukkan nilai dalam centimeter: ";
                cin >> nilaiCentimeter;
                cout << nilaiCentimeter << " centimeter = " << nilaiCentimeter / 100 << " meter\n";
            } else if (pilihanKonversiCentimeter == 2) {
                cout << "Masukkan nilai dalam centimeter: ";
                cin >> nilaiCentimeter;
                cout << nilaiCentimeter << " centimeter = " << nilaiCentimeter / 160934 << " mile\n";
            } else if (pilihanKonversiCentimeter == 3) {
                cout << "Masukkan nilai dalam centimeter: ";
                cin >> nilaiCentimeter;
                cout << nilaiCentimeter << " centimeter = " << nilaiCentimeter / 30.48 << " foot\n";
            } else {
                cout << "Pilihan tidak valid!\n";
            }
        } else if (pilihanMenu == 3) {
            int pilihanKonversiMile;
            cout << "\nPilih konversi dari Mile:\n";
            cout << "1. Mile ke Meter\n";
            cout << "2. Mile ke Centimeter\n";
            cout << "3. Mile ke Foot\n";
            cout << "Pilih pilihan (1/2/3): ";
            cin >> pilihanKonversiMile;

            float nilaiMile;
            if (pilihanKonversiMile == 1) {
                cout << "Masukkan nilai dalam mile: ";
                cin >> nilaiMile;
                cout << nilaiMile << " mile = " << nilaiMile * 1609.34 << " meter\n";
            } else if (pilihanKonversiMile == 2) {
                cout << "Masukkan nilai dalam mile: ";
                cin >> nilaiMile;
                cout << nilaiMile << " mile = " << nilaiMile * 160934 << " centimeter\n";
            } else if (pilihanKonversiMile == 3) {
                cout << "Masukkan nilai dalam mile: ";
                cin >> nilaiMile;
                cout << nilaiMile << " mile = " << nilaiMile * 5280 << " foot\n";
            } else {
                cout << "Pilihan tidak valid!\n";
            }
        } else if (pilihanMenu == 4) {
            int pilihanKonversiFoot;
            cout << "\nPilih konversi dari Foot:\n";
            cout << "1. Foot ke Meter\n";
            cout << "2. Foot ke Centimeter\n";
            cout << "3. Foot ke Mile\n";
            cout << "Pilih pilihan (1/2/3): ";
            cin >> pilihanKonversiFoot;

            float nilaiFoot;
            if (pilihanKonversiFoot == 1) {
                cout << "Masukkan nilai dalam foot: ";
                cin >> nilaiFoot;
                cout << nilaiFoot << " foot = " << nilaiFoot / 3.28084 << " meter\n";
            } else if (pilihanKonversiFoot == 2) {
                cout << "Masukkan nilai dalam foot: ";
                cin >> nilaiFoot;
                cout << nilaiFoot << " foot = " << nilaiFoot * 30.48 << " centimeter\n";
            } else if (pilihanKonversiFoot == 3) {
                cout << "Masukkan nilai dalam foot: ";
                cin >> nilaiFoot;
                cout << nilaiFoot << " foot = " << nilaiFoot / 5280 << " mile\n";
            } else {
                cout << "Pilihan tidak valid!\n";
            }
        } else if (pilihanMenu == 5) {
            cout << "Terima kasih! Program selesai.\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}