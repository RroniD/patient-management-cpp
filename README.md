# Patient Management System (PMS) — C++ (CLI)

**Patient Management System (PMS)** është një aplikacion i thjeshtë **C++** në formë **CLI (Console Menu)** për menaxhimin e **pacientëve** dhe **termineve** në një klinikë të vogël. Projekti është realizuar në kuadër të lëndës **Vegla bazë softuerike (Projekti 4)** dhe fokusohet në përdorimin korrekt të **Git/GitHub** (repo, branches, PR, commits, dokumentim).

---

## Përmbajtja
- [Përmbledhje e Projektit](#përmbledhje-e-projektit)
- [Funksionalitetet Kryesore](#funksionalitetet-kryesore)
- [Arkitektura Teknike](#arkitektura-teknike)
- [Instalimi dhe Ekzekutimi](#instalimi-dhe-ekzekutimi)
- [Përdorimi](#përdorimi)
- [Struktura e Projektit](#struktura-e-projektit)
- [Kontributi](#kontributi)
- [Autorët](#autorët)
- [Licenca](#licenca)

---

## Përmbledhje e Projektit
Ky sistem ofron:
- regjistrim dhe menaxhim të pacientëve (p.sh. emër, moshë, diagnozë),
- regjistrim dhe menaxhim të termineve (p.sh. datë/orë, status),
- lidhje **one-to-many**: një pacient mund të ketë shumë termine.

---

## Funksionalitetet Kryesore
### Menaxhimi i pacientëve
- Shtimi i pacientëve
- Shfaqja e listës së pacientëve
- Kërkimi i pacientit sipas **ID**
- Fshirja e pacientit (me trajtim të të dhënave të lidhura)

### Menaxhimi i termineve
- Shtimi i termineve për pacient
- Shfaqja e listës së termineve
- Përditësimi i statusit (p.sh. completed / canceled)

---

## Arkitektura Teknike
Implementimi përdor:
- `struct Patient` dhe `struct Appointment` për modelimin e të dhënave,
- ruajtje të të dhënave në **arrays** (kapacitet i kufizuar),
- ID auto-increment për pacientët/terminet,
- menu në console me opsione dhe rrjedhë të thjeshtë.

> Qëllimi i projektit është të demonstrojë qartë **workflow me Git/GitHub** dhe dokumentim, duke ruajtur një kod të thjeshtë.

---

## Instalimi dhe Ekzekutimi

### Klonimi i repository
```bash
git clone https://github.com/RroniD/patient-management-cpp.git
cd patient-management-cpp
```

### Kompilimi (g++)
**Linux/macOS/WSL:**
```bash
g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o PatientManager
./PatientManager
```

**Windows (MinGW g++):**
```powershell
g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o PatientManager.exe
.\PatientManager.exe
```

> Nëse më vonë kodi zhvendoset në `src/main.cpp`, zëvendëso `main.cpp` me `src/main.cpp` në komandat e mësipërme.

---

## Përdorimi
Pas ekzekutimit, programi shfaq një **menu** ku mund të:
- shtosh pacientë,
- shikosh/listosh pacientë,
- kërkosh pacient sipas ID,
- menaxhosh termine (shtim/listim/ndryshim statusi),
- dalësh nga programi.

---

## Struktura e Projektit
Struktura minimale e repo-s (aktuale / e rekomanduar):

```
patient-management-cpp/
  main.cpp
  README.md
  CONTRIBUTING.md
  .gitignore                # rekomandohet
  .github/
    pull_request_template.md # rekomandohet (PR template)
    workflows/
      build.yml              # rekomandohet (CI build)
  LICENSE                    # opsionale, por profesionale
```

---

## Kontributi
Për mënyrën standarde të punës me **branches**, **Pull Requests** dhe **commits**, shiko:
- **[CONTRIBUTING.md](CONTRIBUTING.md)**

Rregulli kryesor:
- `main` duhet të jetë gjithmonë i qëndrueshëm (kompilohet).
- Çdo ndryshim bëhet në branch dhe futet në `main` me PR.

---

## Autorët
- Rron Dervishaj  
- Erin Berisha  
- Arjon Morina  
- Ardian Ramaj  

---

## Licenca
Ky projekt mund të licencohet nën **MIT License**.  
Nëse në repo ekziston file-i `LICENSE`, ai është burimi zyrtar i licencës.
