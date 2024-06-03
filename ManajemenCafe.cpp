#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Untuk format output dengan rupiah

using namespace std;

// Struktur untuk merepresentasikan menu makanan atau minuman
struct Menu {
    string nama;
    string kategori;
    int harga;
};

// Kelas untuk mengelola menu restoran atau kafe
class ManajemenMenu {
private:
    vector<Menu> daftarMenu;

public:
    // Konstruktor untuk menginisialisasi daftar menu
    ManajemenMenu() {
        // Menambahkan beberapa menu ke dalam daftar menu
        tambahMenu("Nasi Goreng", "Makanan", 15000);
        tambahMenu("Sate Ayam", "Makanan", 20000);
        tambahMenu("Mie Ayam", "Makanan", 12000);
        tambahMenu("Ayam Goreng", "Makanan", 18000);
        tambahMenu("Bakso", "Makanan", 15000);
        tambahMenu("Soto Ayam", "Makanan", 17000);
        tambahMenu("Es Teh Manis", "Minuman", 5000);
        tambahMenu("Es Jeruk", "Minuman", 6000);
        tambahMenu("Jus Alpukat", "Minuman", 12000);
        tambahMenu("Kopi Hitam", "Minuman", 8000);
    }

    // Fungsi untuk menambah menu baru ke dalam daftar menu
    void tambahMenu(string nama, string kategori, int harga) {
        Menu menu;
        menu.nama = nama;
        menu.kategori = kategori;
        menu.harga = harga;
        daftarMenu.push_back(menu);
    }

    // Fungsi untuk menampilkan seluruh menu yang tersedia
    void tampilkanDaftarMenu() {
        cout << "Daftar Menu:\n";
        cout << "Makanan:\n";
        for (int i = 0; i < daftarMenu.size(); ++i) {
            if (daftarMenu[i].kategori == "Makanan") {
                cout << i+1 << ". Nama: " << daftarMenu[i].nama << ", Kategori: " << daftarMenu[i].kategori << ", Harga: Rp" << fixed << setprecision(0) << daftarMenu[i].harga << endl;
            }
        }
        cout << "Minuman:\n";
        for (int i = 0; i < daftarMenu.size(); ++i) {
            if (daftarMenu[i].kategori == "Minuman") {
                cout << i+1 << ". Nama: " << daftarMenu[i].nama << ", Kategori: " << daftarMenu[i].kategori << ", Harga: Rp" << fixed << setprecision(0) << daftarMenu[i].harga << endl;
            }
        }
    }

    // Metode publik untuk mendapatkan daftar menu
    vector<Menu> getDaftarMenu() {
        return daftarMenu;
    }

    // Fungsi untuk memesan menu dan menghitung total belanjaan
    int pesanMenu(vector<int> pesanan) {
        int total = 0;
        for (int idx : pesanan) {
            if (idx >= 1 && idx <= daftarMenu.size()) {
                total += daftarMenu[idx - 1].harga;
            }
        }
        return total;
    }
};

int main() {
    ManajemenMenu manajemen;

    // Variabel untuk menyimpan pilihan pesanan pengguna
    vector<int> pesanan;

    // Memasukkan pilihan pengguna
    cout << "Selamat datang di Kafe Kami!\n";
    int pilihan;
    char selesai;
    do {
        cout << "\nSilakan pilih menu yang Anda inginkan (masukkan nomor menu), ketik 'y' jika pesanan Anda sudah selesai:\n";
        manajemen.tampilkanDaftarMenu();
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        if (pilihan >= 1 && pilihan <= manajemen.getDaftarMenu().size()) {
            pesanan.push_back(pilihan);
        } else if (pilihan < 1 || pilihan > manajemen.getDaftarMenu().size()) {
            cout << "Menu tidak tersedia. Silakan masukkan nomor menu yang benar.\n";
        }
        cout << "Pesanan sudah selesai? (y/n): ";
        cin >> selesai;
    } while (selesai != 'y' && selesai != 'Y');

    // Menghitung total belanjaan
    int total = manajemen.pesanMenu(pesanan);

    // Menampilkan total belanjaan dalam rupiah
    cout << "\nTotal belanjaan Anda: Rp" << fixed << setprecision(0) << total << endl;

    return 0;
}
