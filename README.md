# Sistem Control Level Air Sungai menggunakan sensor level
Proyek ini bertujuan merancang sistem kontrol level air sungai menggunakan sensor level dan mikrokontroler STM32. Data tinggi air dikirim melalui Wi-Fi, dan jika melebihi batas, relay akan mengaktifkan motor AC untuk tindakan pengendalian. Sistem ini menggunakan panel surya sebagai sumber daya dan dapat diakses oleh admin maupun user melalui fitur monitoring, kontrol, dan notifikasi.

## Penulis
1. Galuh Pandu Satrio (2042231019)
2. Karina Lailatul Maghfiroh Maharani (2042231035)
3. Syahira Arliya Putri Subekti (2042231051)
4. Ahmad Radhy (Penguji)

Teknik Instrumentasi - Institut Teknologi Sepuluh Nopember

## Fitur
1. Level & Distance Monitoring 
Membaca level air dan jarak gate menggunakan sensor analog dan ultrasonik melalui ADC dan I2C.
2. Relay Control
Otomatis mengaktifkan atau menonaktifkan relay berdasarkan kondisi level air dan posisi gate.
3. Looping Processing
Proses dijalankan secara terus menerus dalam loop utama dengan delay 200 ms.
4. Modular Code Structure
File terpisah seperti Level.c, Jarak.c, dan Relay.c membuat kode lebih mudah dipelihara dan dikembangkan.

## Kebutuhan
### Hardware
1. STM32 NUCLEO Development Board
2. Sensor Level Air (Analog Input ke ADC)
3. Sensor Jarak Ultrasonik (dengan output analog/digital melalui I2C/UART)
4. Relay Module
5. Power Supply
6. Module Wifi

### Software
1. STM32CubeMX
2. HAL Library
3. Driver Level, Jarak, dan Relay

## Instalasi Program ke STM32 NUCLEO
1. Install STM32CubeMX
2. Pilih Board STM32
3. Clone Repository
```bash
git clone https://github.com/NamaKamu/Sistem-Monitoring-Level-Air-STM32
```
4. Buka Proyek di STM32CubeMX
5. Pastikan semua konfigurasi peripheral sesuai (ADC, I2C, UART, Timer).
6. Sambungkan board STM32 ke pc/laptop menggunakan kabel USB 
7. Upload program ke STM32 dan amati hasilnya
```bash
Build > Run > Debug > Flash
```
8. Monitoring Output via UART Output status relay atau level air dapat ditampilkan melalui komunikasi serial.

### Cara Kerja Program
1. Sensor level air membaca kondisi ketinggian air.
   - Jika air belum mencapai batas level → output sensor LOW.
   - Jika air melewati batas level → output sensor HIGH.
2. Mikrokontroler STM32 terus membaca data dari sensor secara berkala.
3. Berdasarkan pembacaan sensor:
   - Jika level air tinggi (HIGH) maka mikrokontroler mengaktifkan relay untuk menyalakan pompa air (mengalirkan/menguras air). Buzzer juga diaktifkan sebagai alarm peringatan.
   - Jika level air normal (LOW) maka pompa dan buzzer dinonaktifkan otomatis.
4. Program ini menggunakan prinsip looping untuk terus menerus memonitor kondisi air.
5. Semua pengaturan berjalan otomatis tanpa intervensi manual.

## Struktur
```
STM32-WaterLevel-Control/
├── Core/
│   ├── Src/
│   │   ├── main.c              # Program utama
│   │   ├── Level.c             # Fungsi pembacaan sensor level
│   │   ├── Jarak.c             # Fungsi pembacaan sensor jarak
│   │   └── Relay.c             # Fungsi kontrol relay
│   └── Inc/
│       ├── Level.h
│       ├── Jarak.h
│       └── Relay.h
├── Drivers/                    # Driver HAL bawaan STM32
├── .project, .cproject, .ioc   # File konfigurasi CubeMX
└── README.md                   # Dokumentasi proyek
```
