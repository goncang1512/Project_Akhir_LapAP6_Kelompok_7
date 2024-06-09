#include <iostream>
#include "addproject.h"
using namespace std;

int main() {
    vector<Project*> projects;
    int choice;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Tampilkan Proyek yang Ada\n";
        cout << "2. Tambahkan Proyek Baru\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi (1-3): ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayProjects(projects);
            break;
        case 2:
            addProject(projects);
            break;
        case 3:
            for (auto project : projects) {
                delete project;
            }
            projects.clear();
            return 0;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            break;
        }
    }

    return 0;
}
