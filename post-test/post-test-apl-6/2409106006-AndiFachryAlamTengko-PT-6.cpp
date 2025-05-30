#include <iostream>
#include <string>
using namespace std;

const int MAKS_TIKET = 100;

string namaPemesan[MAKS_TIKET];
string tujuanPenerbangan[MAKS_TIKET];
string tanggalPenerbangan[MAKS_TIKET];
int jumlahTiket = 0;

void login(string namaBenar, string nimBenar) {
    string namaInput, nimInput;
    int attempts = 0;
    bool loginBerhasil = false;
    while (attempts < 3) {
        cout << "Masukkan Nama: ";
        getline(cin, namaInput);
        cout << "Masukkan NIM: ";
        cin >> nimInput;
        cin.ignore();
        if (namaInput == namaBenar && nimInput == nimBenar) {
            loginBerhasil = true;
            break;
        } else {
            cout << "Nama atau NIM salah! Coba lagi.\n";
            attempts++;
        }
    }
    if (!loginBerhasil) {
        cout << "Login gagal setelah 3 kali percobaan. Program berhenti.\n";
        exit(0);
    }
}

void tambahJumlahTiket(int* jumlah) {
    if (*jumlah < MAKS_TIKET) {
        (*jumlah)++;
    } else {
        cout << "Jumlah tiket telah mencapai batas maksimum.\n";
    }
}

void tambahTiket(string nama, string tujuan, string tanggal) {
    namaPemesan[jumlahTiket] = nama;
    tujuanPenerbangan[jumlahTiket] = tujuan;
    tanggalPenerbangan[jumlahTiket] = tanggal;
    tambahJumlahTiket(&jumlahTiket);
}

void tambahTiket() {
    if (jumlahTiket >= MAKS_TIKET) {
        cout << "Tiket sudah penuh!\n";
        return;
    }
    string nama, tujuan, tanggal;
    cout << "Masukkan Nama Pemesan: ";
    getline(cin, nama);
    cout << "Masukkan Tujuan: ";
    getline(cin, tujuan);
    cout << "Masukkan Tanggal Penerbangan (DD-MM-YYYY): ";
    getline(cin, tanggal);
    tambahTiket(nama, tujuan, tanggal);
    cout << "Tiket berhasil dipesan!\n";
}

void tampilkanTiket() {
    if (jumlahTiket == 0) {
        cout << "Belum ada tiket yang dipesan.\n";
        return;
    }
    cout << "Daftar Tiket yang sudah dipesan:\n";
    for (int i = 0; i < jumlahTiket; i++) {
        cout << "Tiket " << (i + 1)
             << " - Nama: " << namaPemesan[i]
             << ", Tujuan: " << tujuanPenerbangan[i]
             << ", Tanggal: " << tanggalPenerbangan[i] << endl;
    }
}

void tampilkanTiketPtr(int* index) {
    if (*index < 0 || *index >= jumlahTiket) {
        cout << "Nomor tiket tidak valid.\n";
        return;
    }
    cout << "Detail Tiket ke-" << (*index + 1) << ":\n";
    cout << "Nama: " << namaPemesan[*index] << endl;
    cout << "Tujuan: " << tujuanPenerbangan[*index] << endl;
    cout << "Tanggal: " << tanggalPenerbangan[*index] << endl;
}

void ubahTiket(int nomor) {
    if (nomor < 1 || nomor > jumlahTiket) {
        cout << "Tiket tidak ditemukan.\n";
        return;
    }
    cout << "Data tiket yang akan diubah:\n";
    cout << "Nama: " << namaPemesan[nomor - 1] << endl;
    cout << "Tujuan: " << tujuanPenerbangan[nomor - 1] << endl;
    cout << "Tanggal: " << tanggalPenerbangan[nomor - 1] << endl;
    cout << "Masukkan Nama Baru: ";
    getline(cin, namaPemesan[nomor - 1]);
    cout << "Masukkan Tujuan Baru: ";
    getline(cin, tujuanPenerbangan[nomor - 1]);
    cout << "Masukkan Tanggal Baru: ";
    getline(cin, tanggalPenerbangan[nomor - 1]);
    cout << "Tiket berhasil diperbarui!\n";
}

void hapusTiketRekursif(int index) {
    if (index >= jumlahTiket - 1) return;

    namaPemesan[index] = namaPemesan[index + 1];
    tujuanPenerbangan[index] = tujuanPenerbangan[index + 1];
    tanggalPenerbangan[index] = tanggalPenerbangan[index + 1];
    hapusTiketRekursif(index + 1);
}

void hapusTiket(int nomor) {
    if (nomor < 1 || nomor > jumlahTiket) {
        cout << "Tiket tidak ditemukan.\n";
        return;
    }
    hapusTiketRekursif(nomor - 1);
    jumlahTiket--;
    cout << "Tiket berhasil dihapus!\n";
}

void sortNamaDescending() {
    for (int i = 0; i < jumlahTiket - 1; i++) {
        for (int j = 0; j < jumlahTiket - i - 1; j++) {
            if (namaPemesan[j] < namaPemesan[j + 1]) {
                swap(namaPemesan[j], namaPemesan[j + 1]);
                swap(tujuanPenerbangan[j], tujuanPenerbangan[j + 1]);
                swap(tanggalPenerbangan[j], tanggalPenerbangan[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Nama (Z ke A).\n";
}

void sortNomorTiketAscending() {
    cout << "Menampilkan data berdasarkan urutan input (nomor tiket) ascending.\n";
    tampilkanTiket();
}

void sortTanggalAscending() {
    for (int i = 0; i < jumlahTiket - 1; i++) {
        for (int j = 0; j < jumlahTiket - i - 1; j++) {
            if (tanggalPenerbangan[j] > tanggalPenerbangan[j + 1]) {
                swap(namaPemesan[j], namaPemesan[j + 1]);
                swap(tujuanPenerbangan[j], tujuanPenerbangan[j + 1]);
                swap(tanggalPenerbangan[j], tanggalPenerbangan[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Tanggal (ascending).\n";
}

int main() {
    login("Andi Fachry Alam Tengko", "006");
    int pilihan;
    do {
        cout << "\nMenu Sistem Pemesanan Tiket Pesawat\n";
        cout << "1. Membeli Tiket\n";
        cout << "2. Melihat Daftar Tiket\n";
        cout << "3. Mengubah Data Pemesanan\n";
        cout << "4. Menghapus Tiket\n";
        cout << "5. Keluar\n";
        cout << "6. Sorting Data\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                tambahTiket();
                break;
            case 2: {
                int subPilihan;
                cout << "1. Tampilkan Semua Tiket\n";
                cout << "2. Tampilkan Tiket Tertentu\n";
                cout << "Pilih opsi: ";
                cin >> subPilihan;
                cin.ignore();
                if (subPilihan == 1) {
                    tampilkanTiket();
                } else if (subPilihan == 2) {
                    int nomor;
                    cout << "Masukkan nomor tiket yang ingin ditampilkan: ";
                    cin >> nomor;
                    cin.ignore();
                    nomor--;
                    tampilkanTiketPtr(&nomor);
                } else {
                    cout << "Pilihan tidak valid.\n";
                }
                break;
            }
            case 3: {
                int nomor;
                cout << "Masukkan nomor tiket yang ingin diubah: ";
                cin >> nomor;
                cin.ignore();
                ubahTiket(nomor);
                break;
            }
            case 4: {
                int nomor;
                cout << "Masukkan nomor tiket yang ingin dihapus: ";
                cin >> nomor;
                cin.ignore();
                hapusTiket(nomor);
                break;
            }
            case 5:
                cout << "Terima kasih, program selesai.\n";
                break;
            case 6: {
                int sortPilihan;
                cout << "\nMenu Sorting\n";
                cout << "1. Urutkan Nama (Z - A)\n";
                cout << "2. Urutkan berdasarkan Nomor Tiket (ascending)\n";
                cout << "3. Urutkan Tanggal Penerbangan (ascending)\n";
                cout << "Pilih opsi sorting: ";
                cin >> sortPilihan;
                cin.ignore();
                switch (sortPilihan) {
                    case 1:
                        sortNamaDescending();
                        break;
                    case 2:
                        sortNomorTiketAscending();
                        break;
                    case 3:
                        sortTanggalAscending();
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                }
                break;
            }
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    } while (pilihan != 5);
    return 0;
}