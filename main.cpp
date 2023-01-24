/* Nama        : Satria Octavianus Nababan
   NIM         : 13521168
   Mata Kuliah : STRATEGI ALGORITMA
   Kelas       : 02                         */

#include <iostream>   // Input dan output
#include <time.h>     // Menghitung lama waktu eksekusi
#include <fstream>    // save File
#include <vector>
using namespace std;

// KAMUS GLOBAL
string a, b, c, d;
int count = 0, pilKartu;
bool saveFile = false, flag = false;
string inputPil;
string namaFile;
vector<string> resultlist;
float waktu;

// Float ini berfungsi menyimpan hasil kemungkinan perhitungan
float result;

int e[22], f[25], g[25], h[25];
int Neff = 0;

// DEKLARASI FUNGSI DAN PROSEDUR
void generateArray(int a, int b, int c, int d);
// Mencari tahu apakah susunan angka a, b, c, dan d terdapat dalam array

void readCards();
// Membaca input 4 kartu

void check24 (int w, int x, int y, int z);
// Mengecek apakah hasilnya mendapatkan angka 24 atau tidak

void countResult (int w, int x, int y, int z, int i, int j, int k);
// Menghitung hasil dari kombinasi input dan operator yang direpresentasikan oleh angka
// w, x, y, z adalah keempat masukan yang diberikan user
// i, j, k adalah operator-operator yang dihasilkan

float calculate (float a, float b, int ops);
// Menghitung operasi dengan 2 buah float dan 1 operator yang diwakili angka

char sign (int ops);
// Mengembalikan char operator yang direpresentasikan oleh angka

// MAIN PROGRAM
int main()
{
  // KAMUS LOKAL
  int i;

  // ALGORITMA
  cout << " ________   _____     ________                          _________      .__                     " << endl;
	cout << " \\_____  \\ /  |  |   /  _____/_____    _____   ____    /   _____/ ____ |  |___  __ ___________" << endl;
	cout << " /   ____//   |  |_ /   \\  ___\\__  \\  /     \\_/ __ \\   \\_____  \\ /  _ \\|  |\\  \\/ // __ \\_  __ \\ " << endl;
	cout << "/       \\/    ^   / \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/   /        (  <_> )  |_\\   /\\  ___/|  | \\/" << endl;
	cout << "\\_______ \\____   |   \\______  (____  /__|_|  /\\___  > /_______  /\\____/|____/\\_/  \\___  >__|   " << endl;
	cout << "        \\/    |__|          \\/     \\/      \\/     \\/          \\/                      \\/       " << endl;
  
  cout << "By Satria Octavianus Nababan - 13521168" << endl;

  cout << "\nPilih sistem permainan:\n    (1) Input nilai kartu sendiri\n    (2) Pilih kartu secara acak\nInput answer : ";
  while (!flag)
  { // Validasi masukkan user
      cin >> pilKartu;
      if (pilKartu == 1 or pilKartu == 2)
          flag = true;
      else
          cout << "\nMasukkan tidak sesuai! Ulangi (1/2)\nInput answer : ";
  }

  if (pilKartu == 2)
  { // Mengacak 4 kartu
      string number[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
      cout << "Kartu :";
          srand(time(0));
          a = to_string(rand()%13+1);
          b = to_string(rand()%13+1);
          c = to_string(rand()%13+1);
          d = to_string(rand()%13+1);
           string e,f,g,h;
           e = a;
           f = b;
           g = c;
           h= d;
           if (a=="1"){
            e = "A";
           }
           if (a=="11"){
            e = "J";
           }
           if (a=="12"){
            e = "Q";
           }
           if (a=="13"){
            e = "K";
           }
           if (b=="1"){
            f = "A";
           }
           if (b=="11"){
            f = "J";
           }
           if (b=="12"){
            f = "Q";
           }
           if (b=="13"){
            f = "K";
           }
           if (c=="1"){
            g = "A";
           }
           if (c=="11"){
            g = "J";
           }
           if (c=="12"){
            g = "Q";
           }
           if (c=="13"){
            g = "K";
           }
           if (d=="1"){
            h = "A";
           }
           if (d=="11"){
            h = "J";
           }
           if (d=="12"){
            h = "Q";
           }
           if (d=="13"){
            h = "K";
           }
          cout << " " << e <<  " " << f  << " " <<  g << " " << h;
      
      cout << "\n";
  }

  if (pilKartu == 1)
  {
    // input 4 kartu
    readCards();
  }
    // Mencari solusi
    cout << "Mencari solusi..." << endl;
    clock_t start = clock();

    // Men-generate semua kemungkinan sususnan angka, terdapat 4! = 24 kemungkinan 
    generateArray(std::stof(a), std::stof(b), std::stof(c), std::stof(d));
    generateArray(std::stof(a), std::stof(b), std::stof(d), std::stof(c));
    generateArray(std::stof(a), std::stof(c), std::stof(b), std::stof(d));
    generateArray(std::stof(a), std::stof(c), std::stof(d), std::stof(b));
    generateArray(std::stof(a), std::stof(d), std::stof(b), std::stof(c));
    generateArray(std::stof(a), std::stof(d), std::stof(c), std::stof(b));
    generateArray(std::stof(b), std::stof(a), std::stof(c), std::stof(d));
    generateArray(std::stof(b), std::stof(a), std::stof(d), std::stof(c));
    generateArray(std::stof(b), std::stof(c), std::stof(a), std::stof(d));
    generateArray(std::stof(b), std::stof(c), std::stof(d), std::stof(a));
    generateArray(std::stof(b), std::stof(d), std::stof(a), std::stof(c));
    generateArray(std::stof(b), std::stof(d), std::stof(c), std::stof(a));
    generateArray(std::stof(c), std::stof(b), std::stof(b), std::stof(d));
    generateArray(std::stof(c), std::stof(a), std::stof(d), std::stof(b));
    generateArray(std::stof(c), std::stof(b), std::stof(a), std::stof(d));
    generateArray(std::stof(c), std::stof(b), std::stof(d), std::stof(a));
    generateArray(std::stof(c), std::stof(d), std::stof(a), std::stof(b));
    generateArray(std::stof(c), std::stof(d), std::stof(b), std::stof(a));
    generateArray(std::stof(d), std::stof(a), std::stof(b), std::stof(c));
    generateArray(std::stof(d), std::stof(a), std::stof(c), std::stof(b));
    generateArray(std::stof(d), std::stof(b), std::stof(a), std::stof(c));
    generateArray(std::stof(d), std::stof(b), std::stof(c), std::stof(a));
    generateArray(std::stof(d), std::stof(c), std::stof(a), std::stof(b));
    generateArray(std::stof(d), std::stof(c), std::stof(b), std::stof(a));

    for (i = 1; i <= Neff; i++)
    {
      check24(e[i], f[i], g[i], h[i]);
    }
    cout << endl << "Terdapat " << count << " buah solusi" << endl;

    // Print lama waktu eksekusi
    waktu = (float)(clock() - start)/CLOCKS_PER_SEC;
    printf("Lama Waktu eksekusi: %.5fs\n", (float)(clock() - start)/CLOCKS_PER_SEC);

    // simpan solusi ke file .txt
    saveFile = false;
    cout << "\nApakah Anda ingin menyimpan hasil ? (Y/N)\nInput answer : ";
    while (!saveFile )
    {
        cin >> inputPil;
        if (inputPil == "Y" or inputPil == "y")
        {
            saveFile = true;
            cout << "Masukkan nama file : ";
            cin >> namaFile;
            ofstream file;
            file.open("../test/" + namaFile + ".txt");
            file << "Kartu : " << a << " " << b << " " << c << " " << d << "\n";
            if (count != 0)
            {
                file << count << " Solution Found!\n";
                for (auto i : resultlist) 
                {
                    file << i << "\n";
                }
            }
            else
            {
                file << "No solution found\n";
            }
            file << "Lama Waktu eksekusi: "<< waktu << "s";
            file.close();
            cout << "Berhasil menyimpan solusi di '../test/" + namaFile + ".txt'\n";
        }
        else if (inputPil == "N" or inputPil == "n")
            saveFile = true;
        else
        {
            cout << "\nMasukkan tidak sesuai! Ulangi (Y/N)\n Masukkan Pilihan : ";
        }
    }


    return 0;
  
}

void readCards()
// Membaca keempat angka untuk permainian 24
{
bool valid = true;
bool loop = true;
while (loop){
  if (!valid) cout << "input tidak valid" << endl << "input yang valid yaitu (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K)" << endl;
  cout << "Masukkan keempat kartu yang mungkin" << endl;
  cin >> a >> b >> c >> d;
  if (!(a=="A"|| a=="K" || a =="Q" || a=="J" || (std::stof(a)>=2 && std::stof(a)<=10))){
    valid=false;
    continue;
  }
  if (!(b=="A"|| b=="K" || b =="Q" || b=="J" || (std::stof(b)>=2 && std::stof(b)<=10))){
    valid=false;
    continue;
  }
  if (!(c=="A"|| c=="K" || c =="Q" || c=="J" || (std::stof(c)>=2 && std::stof(c)<=10))){
    valid=false;
    continue;
  }
  if (!(d=="A"|| d=="K" || d =="Q" || d=="J" || (std::stof(d)>=2 && std::stof(d)<=10))){
    valid=false;
    continue;
  }
  if (a=="A") a="1";
  if (a=="K") a ="13";
  if (a =="Q") a="12";
  if (a=="J") a ="11";

  if (b=="A") b="1";
  if (b=="K") b ="13";
  if (b =="Q") b="12";
  if (b=="J") b ="11";
  
  if (c=="A") c="1";
  if (c=="K") c ="13";
  if (c =="Q") c="12";
  if (c=="J") c ="11";

  if (d=="A") d="1";
  if (d=="K") d ="13";
  if (d =="Q") d="12";
  if (d=="J") d ="11";
  
  cout << "Angka yang diproses adalah..." << endl;
  cout << a << ", " << b << ", " << c << ", dan " << d << endl << endl;
  loop = false;
}

}

void generateArray(int a, int b, int c, int d)
// Mencari tahu apakah susunan angka a, b, c, dan d terdapat dalam array
// Jika ada, maka angka tersebut tidak dimasukkan ke dalam array
// Jika tidak, maka angka tersebut dimasukkan ke dalam array dan Neff ditambah 1
{
  // Kamus lokal
  int i;
  bool found;

  // Algoritma
  found = false;
  i = 1;

  while (i <= Neff && not found)
  {
    if (a == e[i] && b == f[i] && c == g[i] && d == h[i])
    {
      found = true;
    }
    else
    {
      i++;
    }
  }
  if (not found)
  {
    Neff++;
    e[Neff] = a;
    f[Neff] = b;
    g[Neff] = c;
    h[Neff] = d;
  }
}

void check24 (int w, int x, int y, int z)
// Mengecek apakah hasilnya dapat mendapatkan 24 atau tidak
{
  // Operator
  int i, j, k;

  // Terdapat 3 buah operator yang membatasi keempat angka karena
  // di antara 2 angka, terdapat 1 operator
  for (i = 1; i <= 4; i++)
  {
    for (j = 1; j <= 4; j++)
    {
      for (k = 1; k <= 4; k++)
      {
        countResult (w, x, y, z, i, j, k);
      }
    }
  }
}

void countResult (int w, int x, int y, int z, int i, int j, int k)
// Menghitung hasil dari kombinasi angka dan operator yang direpresentasikan oleh angka
// w, x, y, z adalah keempat masukan dari user
// i, j, k adalah operator-operator yang ada
{

  // ((w + x) + y) + z
  result = calculate(calculate(calculate((float)w, (float)x, i), (float) y, j), (float)z, k);
  if (result > 23.99999 && result < 24.00001)
  {
    count++;
    // string haha = "aa" "aaa"
    resultlist.push_back("((" +to_string(w)+ " " + sign(i) + " " +to_string(x) + ") " + sign(j) + " " + to_string(y)+") " + sign(k) + " " +to_string(z));
    cout << "((" << w << " " << sign(i) << " " << x << ") " <<
      sign(j) << " " << y << ") " << sign(k) << " " << z << endl;
  }
  // (w + x) + (y + z)
  result = calculate(calculate((float)w, (float)x, i), calculate((float) y, (float) z, k), j);
  if (result > 23.99999 && result < 24.00001)
  {
    count++;
    resultlist.push_back("(" +to_string(w)+ " " + sign(i) + " " +to_string(x) + ") " + sign(j) + "(" + to_string(y)+" " + sign(k) + " " +to_string(z) + ")");
    cout << "(" << w << " " << sign(i) << " " << x << ") " <<
      sign(j) << " (" << y << " " << sign(k) << " " << z << ")" << endl;
  }
  // (w + (x + y)) + z
  result = calculate(calculate((float)w, calculate((float)x, (float)y, j), i), (float) z, k);
  if (result > 23.99999 && result < 24.00001)
  {
    count++;
    resultlist.push_back("(" +to_string(w)+ " " + sign(i) + "(" +to_string(x) + " " + sign(j) + " " + to_string(y)+"))" + sign(k) + " " +to_string(z));
    cout << "(" << w << " " << sign(i) << " (" << x << " " << sign(j) <<
      " " << y << "))" << sign(k) << " " << z << endl;
  }
  // w + ((x + y) + z)
  result = calculate((float)w, calculate(calculate((float)x, (float)y, j), (float)z, k), i);
  if (result > 23.99999 && result < 24.00001)
  {
    count++;
    resultlist.push_back(to_string(w)+" "+ sign(i) + "((" +to_string(x) +" "+ sign(j) +" " + ")" + sign(k) + " " +to_string(z) + ")");
    cout << w << " " << sign(i) << " ((" << x << " " << sign(j) << " " <<
      y << ") " << sign(k) << " " << z << ")" << endl;
  }
  // w + (x + (y + z))
  result = calculate((float)w, calculate((float)x, calculate((float)y, (float)z, k), j), i);
  if (result > 23.99999 && result < 24.00001)
  {
    count++;
    resultlist.push_back(to_string(w)+" "+ sign(i) + "(" +to_string(x) + " " + sign(j) + "(" + to_string(y)+" "+ sign(k) + " " +to_string(z) + "))");
    cout << w << " " << sign(i) << " (" << x << " " << sign(j) << " (" <<
      y << " " << sign(k) << " " << z << "))" << endl;
  }
}

float calculate (float a, float b, int ops)
// Menghitung operasi dengan 2 buah float dan 1 operator yang diwakili angka
{
  if (ops == 1)
  {
    return (a + b);
  }
  else if (ops == 2)
  {
    return (a - b);
  }
  else if (ops == 3)
  {
    return (a * b);
  }
  else if (ops == 4)
  {
    return ((float)a / (float)b);
  }
}

char sign (int ops)
// Mengembalikan char operator yang direpresentasikan oleh angka
{
  if (ops == 1)
  {
    return ('+');
  }
  if (ops == 2)
  {
    return ('-');
  }
  if (ops == 3)
  {
    return ('*');
  }
  if (ops == 4)
  {
    return ('/');
  }
}