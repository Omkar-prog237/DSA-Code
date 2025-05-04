#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct patient {
    string name;
    int priority;
    patient(const string& name, int priority) : name(name), priority(priority) {}
};

auto compare = [](const patient& p1, const patient& p2) {
    return p1.priority > p2.priority;
};

int main() {
    priority_queue<patient, vector<patient>, decltype(compare)> PQ(compare);

    int n;
    cout << "Enter number of patients: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int p;
        string name;
        cout << "Enter the patient's name: ";
        cin >> ws;
        getline(cin, name);
        cout << "Enter priority: ";
        cin >> p;
        PQ.push(patient(name, p));
    }

    cout << "\nPatients in order of priority:\n";
    while (!PQ.empty()) {
        patient p = PQ.top();
        cout << "Name: " << p.name << ", Priority: " << p.priority << endl;
        PQ.pop();
    }

    return 0;
}
