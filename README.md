# Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force
TUGAS KECIL 1 IF2211 STRATEGI ALGORITMA 2023

# Deskripsi Singkat
Permainan kartu 24 adalah permainan kartu aritmatika dengan tujuan mencari cara untuk mengubah 4 buah angka random sehingga mendapatkan hasil akhir sejumlah 24. Permainan ini menarik cukup banyak peminat dikarenakan dapat meningkatkan kemampuan berhitung serta mengasah otak agar dapat berpikir dengan cepat dan akurat. Permainan Kartu 24 biasa dimainkan dengan menggunakan kartu remi. Kartu remi terdiri dari 52 kartu yang terbagi menjadi empat suit (sekop, hati, keriting, dan wajik) yang masing-masing terdiri dari 13 kartu (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). Yang perlu diperhatikan hanyalah nilai kartu yang didapat (As, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, dan King). As bernilai 1, Jack bernilai 11, Queen bernilai 12, King bernilai 13, sedangkan kartu bilangan memiliki nilai dari bilangan itu sendiri. Pada awal permainan moderator atau salah satu pemain mengambil 4 kartu dari dek yang sudah dikocok secara random. Permainan berakhir ketika pemain berhasil menemukan solusi untuk membuat kumpulan nilainya menjadi 24. Pengubahan nilai tersebut dapat dilakukan menggunakan operasi dasar matematika penjumlahan (+), pengurangan (-), perkalian (×), divisi (/) dan tanda kurung ( () ). Tiap kartu harus digunakan tepat sekali dan urutan penggunaannya bebas.

Terdapat banyak kemungkinan cara untuk menentukan operasi mendapatkan hasil 24. Saya akan membagi kemungkinan tersebut kedalam 3 bagian :
1. Susunan angka-angka dalam operasi 
Dalam permainan 24, jumlah angka yang dapat digunakan dalam operasi haruslah 4. Maka dari itu, dengan menggunakan permutasi, terdapat 4! = 24 kemungkinan susunan angka yang mungkin menghasilkan angka 24. Namun, ada kemungkinan terdapat duplikat. 
2. Susunan operator-operator dalam operasi 
Terdapat 4 buah operator yang dapat digunakan dalam permainan 24, yaitu tambah, kurang, kali, dan bagi. Karena terdapat 4 buah angka dalam permainan ini, maka terdapat 3 tempat di mana operator harus dimasukkan untuk menghasilkan operasi aritmatika, yaitu 1 di antara 2 angka. 
Karena terdapat 4 operator dan 3 buah tempat yang tersedia, dengan aturan perkalian, maka kita mendapatkan 4x4x4 = 64 buah kemungkinan susunan operator yang mungkin menghasilkan angka 24. 
Namun, jika terdapat angka yang sama dari keempat angka tersebut, maka akan terdapat solusi yang sama dari solusi-solusi yang dihasilkan. 
3. Susunan penempatan tanda kurung dalam operasi 
Penempatan tanda kurung dalam operasi aritmatika berfungsi untuk menentukan urutan operasi mana yang dikerjakan terlebih dahulu. Dari penempatan tanda kurung tersebut, terdapat 5 buah jenis solusi yang ada. 
Jika dimisalkan salah satu susunan bilangan tersebut adalah a, b, c, dan d serta operasi yang digunakan adalah 3 operasi penjumlahan, maka susunan tanda kurung tersebut adalah sebagai berikut. 
1.	a + (b + (c + d)) 
2.	a + ((b + c) + d) 
3.	(a + b) + (c + d) 
4.	(a + (b + c)) + d 
5.	((a + b) + c) + d 

Dari ketiga poin di atas, maka dapat disimpulkan bahwa jumlah seluruh kemungkinan solusi dari program yang dibuat adalah 24 x 64 x 5 = 7.680 buah kemungkinan solusi. Namun, hasilnya akan kurang dari 7.680 karena beberapa solusi tidak menghasilkan angka 24.

# Requirement program
- Pastikan komputer telah terinstall compiler C++ contohnya GCC (Gnu Compiler Collection)
- Cloning Repositori

# Cara menggunakan program
1. Buka Program di Visual Studio Code
2. Jalankan program dengan klik simbol Run Code pad main.cpp

# Identitas pembuat
- Nama : Satria Octavianus Nababan
- NIM  : 13521168
- Kelas : K02
