# projectcpp-agents

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Compiler](https://img.shields.io/badge/Compiler-MinGW--W64%20g%2B%2B-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-2EA44F?style=for-the-badge)

Repositori belajar bahasa **C++** (`projectcpp-agents`) berisi mini-projek terstruktur yang dikerjakan melalui kolaborasi bersama AI coding agent.

---

## Profil

| Keterangan | Informasi |
| :--- | :--- |
| **Nama** | Naufal Ilham Fauzan |
| **NIM** | 2502106 |
| **Kelas** | 3B |
| **Program Studi** | Pendidikan Multimedia |
| **Fakultas / Kamda** | Kampus UPI Di Cibiru |
| **Universitas** | Universitas Pendidikan Indonesia |

---

## Alur Kerja

Setiap projek terstruktur di repositori ini dijalankan melalui empat tahap berurutan:

| Tahap | Fokus | Keluaran |
|:---:|:---|:---|
| **1. Spesifikasi** | Menetapkan tujuan, fitur inti, batasan teknis, dan kriteria selesai | `SPEC.md` (lokal) |
| **2. Eksekusi** | Membangun program C++ sesuai acuan awal dan eksplorasi di chat | Kode `.cpp` / `.hpp` |
| **3. Review** | Mengompilasi, menguji kasus batas, dan mencatat evaluasi mandiri | `REVIEW.md` |
| **4. Dokumentasi** | Menulis panduan pakai projek, lalu commit ke repositori | `README.md` |

---

## Daftar Projek

| No | Projek | Ringkasan | Status |
|:---:|:---|:---|:---:|
| `001` | [001_game-tebak-angka](./001_game-tebak-angka) | Permainan tebak angka acak 1-10 dengan 3 kali percobaan dan validasi `std::cin` | Dalam Review |

---

## Struktur Direktori

```text
projectcpp-agents/
├── 001_game-tebak-angka/          # Game tebak angka terminal
│   └── main.cpp                   # Sumber kode utama
├── .gitattributes                 # Pengaturan konsistensi akhir baris (LF/CRLF)
├── .gitignore                     # Pengecualian binary, cache, dan berkas agent lokal
└── README.md                      # Dokumentasi utama repositori
```

Di dalam setiap folder projek selesai (`NNN_nama-projek/`):

```text
NNN_nama-projek/
├── README.md                      # Panduan kompilasi, cara pakai, dan catatan pelajaran
├── REVIEW.md                      # Hasil evaluasi mandiri terhadap spesifikasi dan kode
└── (berkas sumber .cpp / .hpp)
```

> Berkas `AGENTS.md`, `.agents/`, `SPEC.md`, dan seluruh hasil kompilasi (`*.exe`, `*.o`) sengaja diabaikan melalui `.gitignore`.

---

## Lingkungan & Standar Teknis

- **Sistem operasi & terminal:** Windows 11 (64-bit) menggunakan PowerShell
- **Compiler:** `g++` (MinGW-W64) dengan standar `-std=c++17 -Wall -Wextra`
- **Pustaka:** C++ Standard Library (`std::vector`, `std::string`, `std::map`, dll.) tanpa dependensi eksternal kecuali ditentukan
- **Keterbacaan kode:** Fungsi kecil bertanggung jawab tunggal, penamaan deskriptif, komentar berbahasa Indonesia, dan validasi masukan `std::cin`

---

## Cara Menjalankan di PowerShell

Kloning repositori lalu kompilasi dan jalankan projek:

```powershell
git clone https://github.com/nflilham/projectcpp-agents.git
cd projectcpp-agents\001_game-tebak-angka
g++ -std=c++17 -Wall -Wextra main.cpp -o app.exe
.\app.exe
```
