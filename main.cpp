#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_PATIENTS = 50;
const int MAX_APPS = 100;

struct Patient {
    int id;
    string first;
    string last;
    int age;
    string phone;
};

struct Appointment {
    int id;
    int patientId;
    string date;   // YYYY-MM-DD
    string time;   // HH:MM
    string status; // scheduled / canceled / completed
};

Patient patients[MAX_PATIENTS];
Appointment apps[MAX_APPS];

int patientCount = 0;
int appCount = 0;

int nextPatientId = 1;
int nextAppId = 1;

int FindPatientIndexById(int id) {
    for (int i = 0; i < patientCount; i++)
        if (patients[i].id == id) return i;
    return -1;
}

void ListPatients() {
    cout << "\n" << setw(50) << setfill('-') << "" << "\n";
    cout << "PACIENTET\n";
    cout << setw(50) << setfill('-') << "" << "\n";

    if (patientCount == 0) { cout << "Nuk ka paciente.\n"; return; }

    for (int i = 0; i < patientCount; i++) {
        cout << "ID: " << patients[i].id << " | "
             << patients[i].first << " " << patients[i].last
             << " | Age: " << patients[i].age
             << " | Phone: " << patients[i].phone << "\n";
    }
}

void AddPatient() {
    if (patientCount >= MAX_PATIENTS) {
        cout << "Nuk ka hapesire per paciente te rinj.\n";
        return;
    }

    Patient p;
    p.id = nextPatientId++;

    cout << "\nEmri: ";
    cin >> p.first;
    cout << "Mbiemri: ";
    cin >> p.last;
    cout << "Mosha: ";
    cin >> p.age;
    cout << "Telefoni: ";
    cin >> p.phone;

    if (p.first == "" || p.last == "" || p.age <= 0) {
        cout << "Te dhenat jo valide.\n";
        return;
    }

    patients[patientCount++] = p;
    cout << "Pacienti u shtua me ID: " << p.id << "\n";
}

void SearchPatient() {
    int id;
    cout << "\nShkruaj ID: ";
    cin >> id;

    int idx = FindPatientIndexById(id);
    if (idx == -1) {
        cout << "Nuk u gjet pacient.\n";
        return;
    }

    cout << "GJETUR: " << patients[idx].first << " " << patients[idx].last
         << " | Age: " << patients[idx].age
         << " | Phone: " << patients[idx].phone << "\n";
}

void DeletePatient() {
    int id;
    cout << "\nShkruaj ID per fshirje: ";
    cin >> id;

    int idx = FindPatientIndexById(id);
    if (idx == -1) { cout << "Nuk u gjet pacient.\n"; return; }

    for (int i = idx; i < patientCount - 1; i++)
        patients[i] = patients[i + 1];
    patientCount--;

    for (int i = 0; i < appCount; ) {
        if (apps[i].patientId == id) {
            for (int j = i; j < appCount - 1; j++)
                apps[j] = apps[j + 1];
            appCount--;
        } else {
            i++;
        }
    }

    cout << "Pacienti (dhe terminet e tij) u fshine.\n";
}

void ListAppointments() {
    cout << "\n" << setw(50) << setfill('-') << "" << "\n";
    cout << "TERMINET\n";
    cout << setw(50) << setfill('-') << "" << "\n";

    if (appCount == 0) { cout << "Nuk ka termine.\n"; return; }

    for (int i = 0; i < appCount; i++) {
        cout << "ID: " << apps[i].id
             << " | PatientID: " << apps[i].patientId
             << " | " << apps[i].date << " " << apps[i].time
             << " | " << apps[i].status << "\n";
    }
}

bool PatientExists(int pid) {
    return FindPatientIndexById(pid) != -1;
}

void AddAppointment() {
    if (appCount >= MAX_APPS) {
        cout << "Nuk ka hapesire per termine te reja.\n";
        return;
    }

    int pid;
    cout << "\nPatient ID: ";
    cin >> pid;

    if (!PatientExists(pid)) {
        cout << "Pacienti nuk ekziston.\n";
        return;
    }

    Appointment a;
    a.id = nextAppId++;
    a.patientId = pid;

    cout << "Data (YYYY-MM-DD): ";
    cin >> a.date;
    cout << "Ora (HH:MM): ";
    cin >> a.time;

    a.status = "scheduled";

    if (a.date == "" || a.time == "") {
        cout << "Data/Ora jo valide.\n";
        return;
    }

    apps[appCount++] = a;
    cout << "Termini u krijua me ID: " << a.id << "\n";
}

void UpdateAppointmentStatus(const string& newStatus) {
    int id;
    cout << "\nAppointment ID: ";
    cin >> id;

    for (int i = 0; i < appCount; i++) {
        if (apps[i].id == id) {
            apps[i].status = newStatus;
            cout << "Status u ndryshua ne: " << newStatus << "\n";
            return;
        }
    }
    cout << "Nuk u gjet termin.\n";
}

void MainMenu() {
    cout << "\n============================\n";
    cout << " Patient Management (Simple)\n";
    cout << "============================\n";
    cout << "1) Listo pacientet\n";
    cout << "2) Shto pacient\n";
    cout << "3) Kerko pacient (ID)\n";
    cout << "4) Fshij pacient\n";
    cout << "5) Listo terminet\n";
    cout << "6) Cakto termin\n";
    cout << "7) Anulo termin\n";
    cout << "8) Sheno termin completed\n";
    cout << "0) Dil\n";
    cout << "Zgjedh: ";
}

int main() {
    cout << "Welcome!\n";

    int ch;
    do {
        MainMenu();
        cin >> ch;

        switch (ch) {
            case 1: ListPatients(); break;
            case 2: AddPatient(); break;
            case 3: SearchPatient(); break;
            case 4: DeletePatient(); break;
            case 5: ListAppointments(); break;
            case 6: AddAppointment(); break;
            case 7: UpdateAppointmentStatus("canceled"); break;
            case 8: UpdateAppointmentStatus("completed"); break;
            case 0: cout << "Dalje.\n"; break;
            default: cout << "Opsion i pavlefshem.\n";
        }
    } while (ch != 0);

    return 0;
}
