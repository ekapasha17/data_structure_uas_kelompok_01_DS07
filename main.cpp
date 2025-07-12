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