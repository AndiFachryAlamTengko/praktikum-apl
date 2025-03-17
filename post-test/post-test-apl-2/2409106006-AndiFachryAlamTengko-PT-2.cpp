#include <iostream>
#include <string>
using namespace std;

// Array untuk menyimpan data tiket
string namaPemesan[100];
string tujuanPenerbangan[100];
string tanggalPenerbangan[100];

int jumlahTiket = 0;  // Jumlah tiket yang sudah dipesan

int main() {
    // Proses login
    string namaInput, nimInput;
     string namaBenar = "Andi Fachry Alam Tengko";
    string nimBenar = "006";
    int attempts = 0;
    bool loginBerhasil = false;

    // Percobaan login sebanyak 3 kali
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
        return 0;
    }

    int pilihan;
    do {
        cout << "\nMenu Sistem Pemesanan Tiket Pesawat\n";
        cout << "1. Membeli Tiket\n";
        cout << "2. Melihat Daftar Tiket\n";
        cout << "3. Mengubah Data Pemesanan\n";
        cout << "4. Menghapus Tiket\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                if (jumlahTiket >= 100) {
                    cout << "Tiket sudah penuh!\n";
                    break;
                }

                cout << "Masukkan Nama Pemesan: ";
                getline(cin, namaPemesan[jumlahTiket]);

                cout << "Masukkan Tujuan: ";
                getline(cin, tujuanPenerbangan[jumlahTiket]);

                cout << "Masukkan Tanggal Penerbangan (DD-MM-YYYY): ";
                getline(cin, tanggalPenerbangan[jumlahTiket]);

                jumlahTiket++;  
                cout << "Tiket berhasil dipesan!\n";
                break;
            }
            case 2: {
                if (jumlahTiket == 0) {
                    cout << "Belum ada tiket yang dipesan.\n";
                    break;
                }

                cout << "Daftar Tiket yang sudah dipesan:\n";
                for (int i = 0; i < jumlahTiket; i++) {
                    cout << "Tiket " << (i + 1) << " - Nama: " << namaPemesan[i]
                        << ", Tujuan: " << tujuanPenerbangan[i]
                        << ", Tanggal: " << tanggalPenerbangan[i] << endl;
                }
                break;
            }
            case 3: {
                int nomor;
                cout << "Masukkan nomor tiket yang ingin diubah (1-" << jumlahTiket << "): ";
                cin >> nomor;
                cin.ignore();

                if (nomor < 1 || nomor > jumlahTiket) {
                    cout << "Tiket tidak ditemukan.\n";
                    break;
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
                break;
            }
            case 4: {
                int nomor;
                cout << "Masukkan nomor tiket yang ingin dihapus (1-" << jumlahTiket << "): ";
                cin >> nomor;
                cin.ignore();

                if (nomor < 1 || nomor > jumlahTiket) {
                    cout << "Tiket tidak ditemukan.\n";
                    break;
                }

                for (int i = nomor - 1; i < jumlahTiket - 1; i++) {
                    namaPemesan[i] = namaPemesan[i + 1];
                    tujuanPenerbangan[i] = tujuanPenerbangan[i + 1];
                    tanggalPenerbangan[i] = tanggalPenerbangan[i + 1];
                }

                jumlahTiket--;  
                cout << "Tiket berhasil dihapus!\n";
                break;
            }
            case 5: {
                cout << "Terima kasih, program selesai.\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid, coba lagi.\n";
            }
        }
    } while (pilihan != 5);

    return 0;
}
