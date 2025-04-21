# Sistem Monitoring dan Control Level Air Sungai menggunakan sensor level
Proyek ini bertujuan merancang sistem monitoring dan kontrol level air sungai menggunakan sensor level dan mikrokontroler STM32. Data tinggi air dikirim secara real-time melalui Wi-Fi, dan jika melebihi batas, relay akan mengaktifkan motor AC untuk tindakan pengendalian. Sistem ini menggunakan panel surya sebagai sumber daya dan dapat diakses oleh admin maupun user melalui fitur monitoring, kontrol, dan notifikasi.

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
3. Real-Time Processing
Proses dijalankan secara terus menerus dalam loop utama dengan delay 200 ms.
4. Modular Code Structure
File terpisah seperti Level.c, Jarak.c, dan Relay.c membuat kode lebih mudah dipelihara dan dikembangkan.

## Kebutuhan
### Hardware
1. STM32F4xx Development Board
2. Sensor Level Air (Analog Input ke ADC)
3. Sensor Jarak Ultrasonik (dengan output analog/digital melalui I2C/UART)
4. Relay Module
5. Power Supply

### Software
1. STM32CubeMX
2. STM32CubeIDE
3. HAL Library
4. Driver Level, Jarak, dan Relay

## Instalasi 
1. Clone Repository
bash
git clone https://github.com/NamaKamu/Sistem-Monitoring-Level-Air-STM32
2. Buka Proyek di STM32CubeIDE
3. Pastikan semua konfigurasi peripheral sesuai (ADC, I2C, UART, Timer).
4. Kompilasi & Flash ke Board
bash
Build > Run > Debug > Flash
5. Monitoring Output via UART Output status relay atau level air dapat ditampilkan melalui komunikasi serial.

## Struktur
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
├── .project, .cproject, .ioc   # File konfigurasi CubeMX/IDE
└── README.md                   # Dokumentasi proyek
