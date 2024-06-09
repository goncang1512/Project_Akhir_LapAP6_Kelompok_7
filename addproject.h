#include <iostream>
#include "project.h"
using namespace std;

void addProject(vector<Project*>& projects) {
    string projectName;
    cout << "Masukkan nama proyek: ";
    cin.ignore();
    getline(cin, projectName);

    Project* newProject = new Project(projectName);

    int memberCount;
    cout << "Masukkan jumlah anggota tim: ";
    cin >> memberCount;
    cin.ignore();
    for (int i = 0; i < memberCount; ++i) {
        string memberName;
        cout << "Masukkan nama anggota tim ke-" << i + 1 << ": ";
        getline(cin, memberName);
        newProject->addTeamMember(memberName);
    }

    cout << endl;
    int featureCount;
    cout << "Masukkan jumlah fitur: ";
    cin >> featureCount;
    cin.ignore();
    for (int i = 0; i < featureCount; ++i) {
        string featureName, deadline;
        vector<string> assignedMembers;
        cout << "Masukkan nama fitur ke-" << i + 1 << ": ";
        getline(cin, featureName);
        cout << "Masukkan deadline fitur ke-" << i + 1 << ": ";
        getline(cin, deadline);

        int assignedMemberCount;
        cout << "Masukkan jumlah anggota yang mengerjakan fitur ini: ";
        cin >> assignedMemberCount;
        cin.ignore();
        for (int j = 0; j < assignedMemberCount; ++j) {
            string memberName;
            cout << "Masukkan nama anggota yang mengerjakan fitur ini ke-" << j + 1 << ": ";
            getline(cin, memberName);
            assignedMembers.push_back(memberName);
        }

        newProject->addFeature(featureName, deadline, assignedMembers);
    }

    projects.push_back(newProject);
}

void displayProjects(const vector<Project*>& projects) {
    if (projects.empty()) {
        cout << endl <<  "Tidak ada proyek yang sedang dikerjakan." << endl;
        return;
    }

    for (const auto& project : projects) {
        project->displayProjectInfo();
        cout << endl;
    }
}