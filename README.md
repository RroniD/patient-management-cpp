🏥 Sistemi i Menaxhimit të Pacientëve (PMS)
Patient Management System (PMS) është një zgjidhje softuerike e bazuar në konsolë (CLI), e zhvilluar për të digjitalizuar procesin e administrimit të pacientëve dhe planifikimit të termineve mjekësore. Projekti fokusohet në efikasitetin e përpunimit të të dhënave dhe integritetin referencial.



📑 Përmbajtja

Përmbledhje e Projektit
Arkitektura Teknike
Funksionalitetet Kryesore
Instalimi dhe Ekzekutimi
Struktura e Projektit
Roadmap (Zhvillimi i Ardhshëm)




🔭 Përmbledhje e Projektit
Ky projekt është zhvilluar si pjesë e kurrikulës akademike (Projekti 4) për të demonstruar zotërimin e koncepteve thelbësore të gjuhës C++. Ai ofron një ndërfaqe të qëndrueshme për operacionet CRUD (Create, Read, Update, Delete) mbi entitetet e pacientëve dhe termineve, duke simuluar një mjedis real të menaxhimit mjekësor.

Sistemi përdor menaxhim statik të memories për performancë të parashikueshme dhe shpejtësi maksimale të ekzekutimit.




⚙️ Arkitektura Teknike
Projekti bazohet në një arkitekturë procedurale modulare.

Strukturat e të Dhënave (Data Structures): Përdorimi i struct për modelimin e entiteteve Patient dhe Appointment.

Menaxhimi i Memories: Përdorimi i vargjeve statike (arrays) me kufij të paracaktuar (MAX_PATIENTS = 50, MAX_APPS = 100) për të garantuar alokim të sigurtë të memories (Stack allocation).

Relacionet: Lidhja logjike One-to-Many midis Pacientit dhe Termineve realizohet përmes patientId si çelës i jashtëm (Foreign Key simulim).




🚀 Funksionalitetet Kryesore

1. Administrimi i Pacientëve
Funksioni:  Përshkrimi
Regjistrimi:  "Shtimi i pacientëve të rinj me validim të dhënash (Emri, Mosha, Tel)."
Kërkimi:  Algoritëm kërkimi linear për gjetjen e pacientit sipas ID-së unike.
Fshirja Kaskadë:  Fshirja e një pacienti largon automatikisht të gjitha terminet e lidhura me të për të ruajtur integritetin e të dhënave.

2. Menaxhimi i Termineve
Planifikimi: Caktimi i orareve (Data/Ora) vetëm për pacientët ekzistues (validim ID-je).
Gjurmimi i Statusit: Cikli i jetës së terminit: Scheduled $\rightarrow$ Completed ose Canceled.
Raportimi: Gjenerimi i listës së plotë të termineve aktive dhe historike.




💻 Instalimi dhe Ekzekutimi
Për të ekzekutuar këtë projekt në mjedisin tuaj lokal, ndiqni hapat e mëposhtëm:

Parakushtet:
C++ Compiler: GCC (G++), Clang, ose MSVC.
Terminal: Git Bash, PowerShell, ose Terminali i Linux/Mac.

Hapat:
1. Klononi repozitorin:
git clone https://github.com/emri-juaj/patient-management-system.git
cd patient-management-system

2. Kompiloni kodin burimor:
g++ main.cpp -o PatientManager

3. Ekzekutoni aplikacionin:
Në Windows:.\PatientManager.exe
Në Linux/macOS:./PatientManager




📂 Struktura e Projektit

/patient-management-system
│
├── main.cpp            # Kodi kryesor burimor (Entry Point)
├── README.md           # Dokumentacioni zyrtar i projektit
├── .gitignore          # Konfigurimi për injorimin e skedarëve të përkohshëm
└── bin/                # (Opsionale) Dosja për skedarët e ekzekutueshëm




🗺️ Roadmap
Plani për përmirësimin e projektit në versionet e ardhshme (v2.0):

[ ] File Persistence: Ruajtja e të dhënave në skedarë .txt ose .csv që të dhënat të mos humbasin pas mbylljes.

[ ] Dynamic Memory: Zëvendësimi i vargjeve statike me std::vector për kapacitet të pakufizuar.

[ ] Advanced Search: Kërkimi sipas emrit ose mbiemrit, jo vetëm ID-së.

[ ] GUI Interface: Implementimi i ndërfaqes grafike duke përdorur Qt ose wxWidgets.




🤝 Kontributi & Licenca
Ky projekt është "Open Source". Çdo kontribut përmes Pull Requests është i mirëpritur. Shpërndahet nën licencën MIT.

Zhvilluar nga Rron Dervishaj, Ardian Ramaj, Erin Berisha, Arjon Morina - Fakulteti i Inxhinieriesë Kompjuterike dhe Softuerike