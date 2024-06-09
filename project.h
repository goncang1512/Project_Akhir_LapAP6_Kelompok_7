#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Feature {
    string featureName;
    string deadline;
    vector<string> assignedMembers;
};

struct TeamMember {
    string name;
};

class Project {
private:
    string projectName;
    vector<TeamMember> teamMembers;
    vector<Feature> features;

public:
    Project(string name) : projectName(name) {}

    void addTeamMember(const string& memberName) {
        teamMembers.push_back(TeamMember{memberName});
    }

    void addFeature(const string& featureName, const string& deadline, const vector<string>& assignedMembers) {
        features.push_back(Feature{featureName, deadline, assignedMembers});
    }

    void displayProjectInfo() const {
        cout << endl;
        cout << "Nama Proyek: " << projectName << endl;
        cout << "Anggota Tim:" << endl;
        for (const auto& member : teamMembers) {
            cout << "- " << member.name << endl;
        }
        cout << "Fitur-Fitur:" << endl;
        for (const auto& feature : features) {
            cout << "- " << feature.featureName << " (Deadline: " << feature.deadline << ")" << endl;
            cout << "  Anggota yang mengerjakan:" << endl;
            for (const auto& member : feature.assignedMembers) {
                cout << "  - " << member << endl;
            }
        }
    }

    string getProjectName() const {
        return projectName;
    }
};