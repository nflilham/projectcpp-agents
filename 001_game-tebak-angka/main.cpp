#include <cctype>
#include <iostream>
#include <limits>
#include <random>
#include <string>

constexpr int MIN_ANGKA = 1;
constexpr int MAX_ANGKA = 10;
constexpr int MAKS_PERCOBAAN = 3;

enum class HasilTebakan {
    TerlaluKecil,
    Benar,
    TerlaluBesar
};

// Menghasilkan satu angka acak inklusif di antara min_nilai dan max_nilai.
int acak_angka(std::mt19937& generator, int min_nilai, int max_nilai) {
    std::uniform_int_distribution<int> distribusi(min_nilai, max_nilai);
    return distribusi(generator);
}

// Membandingkan tebakan pemain terhadap angka rahasia (logika inti tanpa I/O).
HasilTebakan cek_tebakan(int tebakan, int angka_rahasia) {
    if (tebakan < angka_rahasia) {
        return HasilTebakan::TerlaluKecil;
    }
    if (tebakan > angka_rahasia) {
        return HasilTebakan::TerlaluBesar;
    }
    return HasilTebakan::Benar;
}

// Memeriksa apakah string hanya berisi karakter spasi atau kosong.
bool hanya_spasi(const std::string& teks) {
    for (char ch : teks) {
        if (!std::isspace(static_cast<unsigned char>(ch))) {
            return false;
        }
    }
    return true;
}

// Menghapus spasi di awal dan akhir string untuk validasi masukan teks.
std::string pangkas_spasi(const std::string& teks) {
    std::size_t awal = 0;
    while (awal < teks.size() && std::isspace(static_cast<unsigned char>(teks[awal]))) {
        ++awal;
    }
    std::size_t akhir = teks.size();
    while (akhir > awal && std::isspace(static_cast<unsigned char>(teks[akhir - 1]))) {
        --akhir;
    }
    return teks.substr(awal, akhir - awal);
}

// Membaca tebakan bilangan bulat 1-10 sampai valid; mengembalikan false jika EOF.
bool baca_tebakan(int percobaan_ke, int& tebakan_keluar) {
    while (true) {
        std::cout << "Percobaan ke-" << percobaan_ke << "/" << MAKS_PERCOBAAN
                  << " - Masukkan tebakan (" << MIN_ANGKA << "-" << MAX_ANGKA << "): ";

        int angka = 0;
        if (!(std::cin >> angka)) {
            if (std::cin.eof()) {
                return false;
            }
            // Bersihkan status error dan sisa buffer agar tidak terjadi infinite loop.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Masukan tidak valid. Harap masukkan angka bulat "
                      << MIN_ANGKA << " sampai " << MAX_ANGKA << ".\n";
            continue;
        }

        // Ambil sisa karakter di baris yang sama untuk menolak format seperti "5abc".
        std::string sisa_baris;
        std::getline(std::cin, sisa_baris);
        if (!hanya_spasi(sisa_baris)) {
            std::cout << "Masukan tidak valid. Harap masukkan angka bulat utuh.\n";
            continue;
        }

        if (angka < MIN_ANGKA || angka > MAX_ANGKA) {
            std::cout << "Angka di luar rentang. Pilih antara "
                      << MIN_ANGKA << " sampai " << MAX_ANGKA << ".\n";
            continue;
        }

        tebakan_keluar = angka;
        return true;
    }
}

// Menjalankan satu ronde permainan dengan 3 kali percobaan; mengembalikan false jika EOF.
bool jalankan_ronde(std::mt19937& generator) {
    const int angka_rahasia = acak_angka(generator, MIN_ANGKA, MAX_ANGKA);

    std::cout << "\n--- Ronde Baru ---\n";
    std::cout << "Tebak angka rahasia antara " << MIN_ANGKA << " sampai " << MAX_ANGKA
              << ". Kamu punya " << MAKS_PERCOBAAN << " kali percobaan.\n";

    for (int percobaan = 1; percobaan <= MAKS_PERCOBAAN; ++percobaan) {
        int tebakan = 0;
        if (!baca_tebakan(percobaan, tebakan)) {
            std::cout << "\nMasukan dihentikan.\n";
            return false;
        }

        const HasilTebakan hasil = cek_tebakan(tebakan, angka_rahasia);
        if (hasil == HasilTebakan::Benar) {
            std::cout << "Selamat! Tebakanmu benar (" << angka_rahasia
                      << ") pada percobaan ke-" << percobaan << ".\n";
            return true;
        }

        if (hasil == HasilTebakan::TerlaluBesar) {
            std::cout << "Terlalu besar.\n";
        } else {
            std::cout << "Terlalu kecil.\n";
        }
    }

    std::cout << "Kesempatan habis! Kamu kalah. Angka rahasia yang benar adalah "
              << angka_rahasia << ".\n";
    return true;
}

// Meminta konfirmasi main lagi (y/n); mengembalikan false untuk berhenti atau saat EOF.
bool tanya_main_lagi() {
    while (true) {
        std::cout << "\nIngin bermain lagi? (y/n): ";
        std::string baris;
        if (!std::getline(std::cin, baris)) {
            return false;
        }

        const std::string jawaban = pangkas_spasi(baris);
        if (jawaban.size() == 1) {
            const char huruf = static_cast<char>(std::tolower(static_cast<unsigned char>(jawaban[0])));
            if (huruf == 'y') {
                return true;
            }
            if (huruf == 'n') {
                return false;
            }
        }

        std::cout << "Pilihan tidak valid. Ketik 'y' untuk main lagi atau 'n' untuk keluar.\n";
    }
}

int main() {
    // Inisialisasi generator acak satu kali agar setiap ronde mendapat angka baru.
    std::random_device perangkat_acak;
    std::mt19937 generator(perangkat_acak());

    std::cout << "=== Game Tebak Angka ===\n";

    do {
        if (!jalankan_ronde(generator)) {
            break;
        }
    } while (tanya_main_lagi());

    std::cout << "Terima kasih sudah bermain.\n";
    return 0;
}
