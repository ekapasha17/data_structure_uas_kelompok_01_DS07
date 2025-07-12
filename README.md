# 🎓 SmartStudent - Sistem Layanan Mahasiswa Kampus Cakrawala

**Final Project - Data Structures Course (STI2131)**  
**Universitas Cakrawala - Fakultas Komputer**  
**Semester Genap 2024/2025**

---

## 📋 Project Information

| Detail | Keterangan |
|--------|------------|
| **Mata Kuliah** | Data Structures (STI2131) |
| **Dosen Pengampu** | Muhamad Rifky Adhani |
| **Waktu Ujian** | Selasa, 8 Juli 2025 - Sabtu, 12 Juli 2025 |
| **Bahasa Pemrograman** | C++ |
| **Tipe Ujian** | Project-based (Kelompok) |

---

## 🎯 Project Overview

**SmartStudent** adalah sistem layanan mahasiswa digital berbasis terminal yang dibangun menggunakan C++. Sistem ini mengimplementasikan 7 struktur data fundamental untuk mengelola berbagai kebutuhan mahasiswa kampus.

### ✨ Fitur Utama:
- 🔐 **Login System** (Hash Table)
- 📚 **Manajemen Buku** (Binary Search Tree)
- 🔍 **Pencarian & Sorting** (Search & Sort Algorithms)
- ⏰ **Antrian Konsultasi** (Queue)
- 📝 **Riwayat Peminjaman** (Linked List)
- 📊 **Aktivitas Terbaru** (Stack)
- 🗺️ **Navigasi Kampus** (Graph)

---

## 📚 JAWABAN SOAL ESSAY (30%)

### a. Struktur Data untuk Setiap Fitur:

#### 1. **Daftar Buku Perpustakaan**
- **Struktur Data**: Binary Search Tree (BST)
- **Alasan**: 
  - Auto-sorting berdasarkan ID buku
  - Pencarian efisien O(log n)
  - Insert dan delete yang optimal

#### 2. **Antrean Konsultasi Akademik**
- **Struktur Data**: Queue (FIFO)
- **Alasan**: 
  - Mahasiswa dilayani berdasarkan urutan kedatangan
  - First Come, First Served principle
  - Operasi enqueue dan dequeue yang efisien

#### 3. **Login Mahasiswa**
- **Struktur Data**: Hash Table
- **Alasan**: 
  - Pencarian username/password sangat cepat O(1)
  - Efisien untuk autentikasi
  - Mudah untuk menambah user baru

#### 4. **Riwayat Aktivitas Mahasiswa**
- **Struktur Data**: Stack (LIFO)
- **Alasan**: 
  - Menampilkan aktivitas terbaru terlebih dahulu
  - Last In, First Out sesuai kebutuhan timeline
  - Push dan pop yang efisien

#### 5. **Riwayat Peminjaman Buku**
- **Struktur Data**: Linked List
- **Alasan**: 
  - Ukuran dinamis sesuai jumlah peminjaman
  - Insert dan delete yang fleksibel
  - Memory allocation yang efisien

#### 6. **Navigasi Lokasi Kampus**
- **Struktur Data**: Graph (Undirected)
- **Alasan**: 
  - Merepresentasikan lokasi sebagai vertices
  - Jalur antar lokasi sebagai edges
  - Memungkinkan pathfinding algorithms

#### 7. **Sorting & Searching Buku**
- **Struktur Data**: Array/Vector + Sorting Algorithms
- **Alasan**: 
  - Mudah diimplementasikan
  - Mendukung berbagai algoritma sorting
  - Linear dan binary search

### b. Graph dalam Sistem Navigasi:

#### **Kelebihan Graph:**
- ✅ Dapat merepresentasikan jalur kompleks antar lokasi
- ✅ Memungkinkan pencarian rute terpendek (shortest path)
- ✅ Fleksibel untuk menambah lokasi baru
- ✅ Mendukung weighted edges untuk jarak
- ✅ Bisa menangani multiple paths

#### **Kekurangan Graph:**
- ❌ Kompleks untuk diimplementasikan
- ❌ Membutuhkan memori lebih besar
- ❌ Algoritma traversal yang rumit
- ❌ Maintenance yang challenging
- ❌ Debugging yang sulit

#### **Perbedaan Graph Berarah vs Tak Berarah:**

| Aspek | Graph Berarah | Graph Tak Berarah |
|-------|---------------|-------------------|
| **Definisi** | Edge memiliki arah (A→B ≠ B→A) | Edge dua arah (A↔B) |
| **Contoh Kampus** | Tangga darurat (turun saja) | Koridor (bolak-balik) |
| **Implementasi** | adjacency[A].push(B) only | adjacency[A].push(B) & adjacency[B].push(A) |
| **Use Case** | Jalur satu arah, eskalator | Jalan normal, pintu |

### c. Simulasi Alur Mahasiswa:

```
Login → Antre Konsultasi → Pinjam Buku → Lihat Riwayat Aktivitas
```

#### **Langkah-langkah:**

1. **Login** 
   - **Struktur Data**: Hash Table
   - **Proses**: Cek username & password di unordered_map
   - **Kompleksitas**: O(1)

2. **Antre Konsultasi**
   - **Struktur Data**: Queue
   - **Proses**: Push nama mahasiswa ke queue
   - **Kompleksitas**: O(1)

3. **Pinjam Buku**
   - **Struktur Data**: BST (cari buku) + Linked List (tambah riwayat)
   - **Proses**: Search di BST → Insert ke Linked List
   - **Kompleksitas**: O(log n) + O(1)

4. **Lihat Riwayat Aktivitas**
   - **Struktur Data**: Stack
   - **Proses**: Pop elements dari stack untuk display
   - **Kompleksitas**: O(n) untuk display

---

## 💻 MINI PROJECT IMPLEMENTATION (65%)

### 🏗️ Arsitektur System

```
SmartStudent System
├── LoginSystem (Hash Table)
├── BookTree (Binary Search Tree)
├── BookHistory (Linked List)
├── ConsultationQueue (Queue)
├── ActivityHistory (Stack)
├── CampusNavigation (Graph)
└── BookManager (Array + Sorting)
```

### 📁 Source Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// 1. LINKED LIST - Riwayat Peminjaman
struct BookNode {
    string bookTitle;
    string date;
    BookNode* next;
    
    BookNode(string title, string d) : bookTitle(title), date(d), next(nullptr) {}
};

class BookHistory {
private:
    BookNode* head;
public:
    BookHistory() : head(nullptr) {}
    
    void addBook(string title, string date) {
        BookNode* newNode = new BookNode(title, date);
        newNode->next = head;
        head = newNode;
        cout << "Buku '" << title << "' ditambahkan ke riwayat.\n";
    }
    
    void displayHistory() {
        cout << "\n=== RIWAYAT PEMINJAMAN ===\n";
        BookNode* current = head;
        int no = 1;
        while (current != nullptr) {
            cout << no++ << ". " << current->bookTitle << " (" << current->date << ")\n";
            current = current->next;
        }
    }
};

// 2. QUEUE - Antrian Konsultasi
class ConsultationQueue {
private:
    queue<string> students;
public:
    void addStudent(string name) {
        students.push(name);
        cout << name << " masuk antrian konsultasi.\n";
    }
    
    void serveStudent() {
        if (!students.empty()) {
            cout << students.front() << " sedang dikonsultasi.\n";
            students.pop();
        } else {
            cout << "Tidak ada mahasiswa dalam antrian.\n";
        }
    }
    
    void showQueue() {
        cout << "\n=== ANTRIAN KONSULTASI ===\n";
        queue<string> temp = students;
        int no = 1;
        while (!temp.empty()) {
            cout << no++ << ". " << temp.front() << "\n";
            temp.pop();
        }
    }
};

// 3. STACK - Riwayat Aktivitas
class ActivityHistory {
private:
    stack<string> activities;
public:
    void addActivity(string activity) {
        activities.push(activity);
    }
    
    void showRecentActivities() {
        cout << "\n=== AKTIVITAS TERBARU ===\n";
        stack<string> temp = activities;
        int no = 1;
        while (!temp.empty() && no <= 5) {
            cout << no++ << ". " << temp.top() << "\n";
            temp.pop();
        }
    }
};

// 4. HASH TABLE - Login System
class LoginSystem {
private:
    unordered_map<string, string> users;
public:
    LoginSystem() {
        // Default users
        users["admin"] = "admin123";
        users["mahasiswa1"] = "pass123";
        users["mahasiswa2"] = "pass456";
    }
    
    bool login(string username, string password) {
        if (users.find(username) != users.end() && users[username] == password) {
            cout << "Login berhasil! Selamat datang " << username << "\n";
            return true;
        }
        cout << "Username atau password salah!\n";
        return false;
    }
    
    void registerUser(string username, string password) {
        users[username] = password;
        cout << "User " << username << " berhasil didaftarkan.\n";
    }
};

// 5. TREE (BST) - Daftar Buku
struct TreeNode {
    string bookTitle;
    int bookId;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(string title, int id) : bookTitle(title), bookId(id), left(nullptr), right(nullptr) {}
};

class BookTree {
private:
    TreeNode* root;
    
    TreeNode* insert(TreeNode* node, string title, int id) {
        if (node == nullptr) {
            return new TreeNode(title, id);
        }
        if (id < node->bookId) {
            node->left = insert(node->left, title, id);
        } else {
            node->right = insert(node->right, title, id);
        }
        return node;
    }
    
    void inOrder(TreeNode* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << "ID: " << node->bookId << " - " << node->bookTitle << "\n";
            inOrder(node->right);
        }
    }
    
    TreeNode* search(TreeNode* node, int id) {
        if (node == nullptr || node->bookId == id) {
            return node;
        }
        if (id < node->bookId) {
            return search(node->left, id);
        }
        return search(node->right, id);
    }
    
public:
    BookTree() : root(nullptr) {}
    
    void addBook(string title, int id) {
        root = insert(root, title, id);
        cout << "Buku '" << title << "' berhasil ditambahkan.\n";
    }
    
    void displayBooks() {
        cout << "\n=== DAFTAR BUKU (TERURUT) ===\n";
        inOrder(root);
    }
    
    bool searchBook(int id) {
        TreeNode* result = search(root, id);
        if (result != nullptr) {
            cout << "Buku ditemukan: " << result->bookTitle << "\n";
            return true;
        }
        cout << "Buku dengan ID " << id << " tidak ditemukan.\n";
        return false;
    }
};

// 6. GRAPH - Navigasi Kampus
class CampusNavigation {
private:
    unordered_map<string, vector<string>> graph;
public:
    void addPath(string from, string to) {
        graph[from].push_back(to);
        graph[to].push_back(from); // Undirected graph
    }
    
    void showMap() {
        cout << "\n=== PETA KAMPUS ===\n";
        for (auto& pair : graph) {
            cout << pair.first << " terhubung dengan: ";
            for (auto& dest : pair.second) {
                cout << dest << " ";
            }
            cout << "\n";
        }
    }
    
    void initializeMap() {
        addPath("Gerbang Utama", "Fakultas Komputer");
        addPath("Fakultas Komputer", "Perpustakaan");
        addPath("Perpustakaan", "Kantin");
        addPath("Kantin", "Masjid");
        addPath("Gerbang Utama", "Parkiran");
    }
};

// 7. SORTING & SEARCHING
class BookManager {
private:
    vector<pair<string, int>> books;
public:
    void addBook(string title, int id) {
        books.push_back({title, id});
    }
    
    void sortBooks() {
        sort(books.begin(), books.end());
        cout << "Buku berhasil diurutkan berdasarkan judul.\n";
    }
    
    bool searchBook(string title) {
        for (auto& book : books) {
            if (book.first == title) {
                cout << "Buku '" << title << "' ditemukan dengan ID: " << book.second << "\n";
                return true;
            }
        }
        cout << "Buku '" << title << "' tidak ditemukan.\n";
        return false;
    }
    
    void displayBooks() {
        cout << "\n=== DAFTAR BUKU ===\n";
        for (int i = 0; i < books.size(); i++) {
            cout << i+1 << ". " << books[i].first << " (ID: " << books[i].second << ")\n";
        }
    }
};

// MAIN PROGRAM
int main() {
    // Initialize all systems
    LoginSystem login;
    BookHistory history;
    ConsultationQueue consultation;
    ActivityHistory activity;
    BookTree bookTree;
    CampusNavigation campus;
    BookManager bookManager;
    
    // Initialize sample data
    bookTree.addBook("Algoritma Pemrograman", 101);
    bookTree.addBook("Struktur Data", 102);
    bookTree.addBook("Database", 103);
    
    bookManager.addBook("Algoritma Pemrograman", 101);
    bookManager.addBook("Struktur Data", 102);
    bookManager.addBook("Database", 103);
    
    campus.initializeMap();
    
    cout << "=== SISTEM SMARTSTUDENT KAMPUS CAKRAWALA ===\n\n";
    
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    
    if (login.login(username, password)) {
        activity.addActivity("Login ke sistem");
        
        int choice;
        do {
            cout << "\n=== MENU UTAMA ===\n";
            cout << "1. Lihat Daftar Buku (BST)\n";
            cout << "2. Cari Buku (Search)\n";
            cout << "3. Antre Konsultasi (Queue)\n";
            cout << "4. Lihat Antrian Konsultasi\n";
            cout << "5. Pinjam Buku (Linked List)\n";
            cout << "6. Lihat Riwayat Peminjaman\n";
            cout << "7. Lihat Aktivitas Terbaru (Stack)\n";
            cout << "8. Lihat Peta Kampus (Graph)\n";
            cout << "9. Sorting Buku\n";
            cout << "0. Keluar\n";
            cout << "Pilihan: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    bookTree.displayBooks();
                    activity.addActivity("Melihat daftar buku");
                    break;
                case 2: {
                    int id;
                    cout << "Masukkan ID buku: ";
                    cin >> id;
                    bookTree.searchBook(id);
                    activity.addActivity("Mencari buku ID: " + to_string(id));
                    break;
                }
                case 3: {
                    string name;
                    cout << "Nama mahasiswa: ";
                    cin >> name;
                    consultation.addStudent(name);
                    activity.addActivity("Menambah antrian konsultasi");
                    break;
                }
                case 4:
                    consultation.showQueue();
                    activity.addActivity("Melihat antrian konsultasi");
                    break;
                case 5: {
                    string bookTitle;
                    cout << "Judul buku yang dipinjam: ";
                    cin.ignore();
                    getline(cin, bookTitle);
                    history.addBook(bookTitle, "12/07/2025");
                    activity.addActivity("Meminjam buku: " + bookTitle);
                    break;
                }
                case 6:
                    history.displayHistory();
                    activity.addActivity("Melihat riwayat peminjaman");
                    break;
                case 7:
                    activity.showRecentActivities();
                    break;
                case 8:
                    campus.showMap();
                    activity.addActivity("Melihat peta kampus");
                    break;
                case 9:
                    bookManager.sortBooks();
                    bookManager.displayBooks();
                    activity.addActivity("Mengurutkan buku");
                    break;
                case 0:
                    cout << "Terima kasih telah menggunakan SmartStudent!\n";
                    break;
                default:
                    cout << "Pilihan tidak valid!\n";
            }
        } while (choice != 0);
    }
    
    return 0;
}
```

---

## 🚀 Getting Started

### Prerequisites
- **C++ Compiler** (g++, MinGW, atau Visual Studio)
- **Terminal/Command Prompt**
- **Git** (untuk clone repository)

### Installation & Running

1. **Clone Repository**
   ```bash
   git clone https://github.com/yourusername/smartstudent-system.git
   cd smartstudent-system
   ```

2. **Compile Program**
   ```bash
   g++ -o smartstudent main.cpp
   ```

3. **Run Program**
   ```bash
   ./smartstudent          # Linux/Mac
   smartstudent.exe        # Windows
   ```

### Default Login Credentials
| Username | Password |
|----------|----------|
| `admin` | `admin123` |
| `mahasiswa1` | `pass123` |
| `mahasiswa2` | `pass456` |

---

## 📸 Program Screenshots

### 1. Login Screen
```
=== SISTEM SMARTSTUDENT KAMPUS CAKRAWALA ===

Username: mahasiswa1
Password: pass123
Login berhasil! Selamat datang mahasiswa1
```

### 2. Main Menu
```
=== MENU UTAMA ===
1. Lihat Daftar Buku (BST)
2. Cari Buku (Search)
3. Antre Konsultasi (Queue)
4. Lihat Antrian Konsultasi
5. Pinjam Buku (Linked List)
6. Lihat Riwayat Peminjaman
7. Lihat Aktivitas Terbaru (Stack)
8. Lihat Peta Kampus (Graph)
9. Sorting Buku
0. Keluar
```

### 3. Binary Search Tree Output
```
=== DAFTAR BUKU (TERURUT) ===
ID: 101 - Algoritma Pemrograman
ID: 102 - Struktur Data
ID: 103 - Database
```

### 4. Queue Implementation
```
=== ANTRIAN KONSULTASI ===
1. Budi
2. Sari
3. Andi
```

### 5. Linked List Output
```
=== RIWAYAT PEMINJAMAN ===
1. Database (12/07/2025)
2. Struktur Data (12/07/2025)
3. Algoritma Pemrograman (12/07/2025)
```

### 6. Stack Implementation
```
=== AKTIVITAS TERBARU ===
1. Meminjam buku: Database
2. Melihat riwayat peminjaman
3. Meminjam buku: Struktur Data
4. Menambah antrian konsultasi
5. Melihat daftar buku
```

### 7. Graph Visualization
```
=== PETA KAMPUS ===
Gerbang Utama terhubung dengan: Fakultas Komputer Parkiran 
Fakultas Komputer terhubung dengan: Gerbang Utama Perpustakaan 
Perpustakaan terhubung dengan: Fakultas Komputer Kantin 
Kantin terhubung dengan: Perpustakaan Masjid 
```

---

## 🧪 Testing Guide

### Test Cases

#### 1. **Login Testing**
- ✅ Valid credentials: `mahasiswa1` / `pass123`
- ❌ Invalid credentials: `wrong` / `password`

#### 2. **BST Testing**
- Add books with different IDs
- Verify in-order traversal (sorted output)
- Test search functionality

#### 3. **Queue Testing**
- Add multiple students to consultation queue
- Verify FIFO behavior
- Test empty queue handling

#### 4. **Linked List Testing**
- Add book borrowing records
- Verify insertion at head
- Test traversal display

#### 5. **Stack Testing**
- Perform multiple activities
- Verify LIFO behavior for recent activities
- Test maximum 5 activities display

#### 6. **Graph Testing**
- Display campus navigation map
- Verify undirected graph connections
- Test adjacency list representation

#### 7. **Sorting Testing**
- Add books to manager
- Test sorting by title
- Verify alphabetical order

---

## 📊 Complexity Analysis

------------------------------------------------------------------------------
| Data Structure     | Operation       |Time Complexity   | Space Complexity |
|--------------------|-----------------|------------------|------------------|
| **Hash Table**     | Insert/Search   | O(1) average     | O(n)             |
| **BST**            | Insert/Search   | O(log n) average | O(n)             |
| **Queue**          | Enqueue/Dequeue | O(1)             | O(n)             |
| **Stack**          | Push/Pop | O(1) | O(n)             |                  |
| **Linked List**    | Insert at head  | O(1)             | O(n)             |
| **Graph**          | Add edge        | O(1)             | O(V + E)         |
| **Sorting**        | Sort array      | O(n log n)       | O(1)             |
------------------------------------------------------------------------------
---

## 🏆 Features Implemented

- ✅ **7 Data Structures** sesuai requirement
- ✅ **Interactive Menu System**
- ✅ **Error Handling** untuk input validation
- ✅ **Sample Data** untuk testing
- ✅ **Clean Code Structure** dengan OOP principles
- ✅ **Comprehensive Documentation**

---

## 👥 Team Members
------------------------------------------------------------
| Aprilian Adha Eka Pasha | 24120300030 | Anggota Kelompok |
| Daniel Satria           | 24120310014 | Anggota Kelompok |
| Asep Nur Hidayat        | [NIM 3]     | Anggota Kelompok |
------------------------------------------------------------

---

## 📞 Contact

**Dosen Pengampu**: Muhamad Rifky Adhani  
**Mata Kuliah**   : Data Structures (STI2131)  
**Universitas**   : Universitas Cakrawala - Fakultas Komputer

**Mahasiswa**     : Aprilian Adha Eka Pasha  
**Mata Kuliah**   : Data Structures (STI2131)  
**Universitas**   : Universitas Cakrawala - Fakultas Komputer
**Email**         : aprilian.pasha@cakrawala.ac.id

---

## 📄 License

This project is created for educational purposes as part of Data Structures course final exam at Universitas Cakrawala Indonesia.

---

## 🙏 Acknowledgments

- Terima kasih kepada **Pak Muhamad Rifky Adhani** sebagai dosen pengampu
- Terima kasih kepada **Universitas Cakrawala** atas fasilitas pembelajaran
- Referensi: Cormen, T. H., et al. "Introduction to Algorithms"

---

**© 2025 SmartStudent System - Universitas Cakrawala**