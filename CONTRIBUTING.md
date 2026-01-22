# CONTRIBUTING.md
**Sistemi i Menaxhimit të Pacientëve (PMS)** – Udhëzues për kontribut dhe workflow në Git/GitHub

Ky dokument është pjesë e **Projektit 4 – Veglat bazë softuerike** dhe ka për qëllim të demonstrojë:
- menaxhim korrekt të kodit burimor në **GitHub Repository**,
- zhvillim bashkëpunues me **branches** dhe **merge në main**,
- përdorim të **Pull Requests** për *code review / diskutim / integrim*,
- **commits të rregullta, të qarta, domethënëse** dhe sinkronizim me **push/pull**,
- dokumentim të qartë për nisjen lokale të projektit.

---

## 1) Rregullat bazë (të detyrueshme për këtë projekt)
1. **Mos puno direkt në `main`.**  
   Çdo ndryshim zhvillohet në një branch (feature/fix/docs) dhe futet në `main` vetëm përmes PR.
2. **Çdo ndryshim hyn në `main` me Pull Request (PR).**  
   PR duhet të ketë përshkrim + mënyrën e testimit (komandat e build/run).
3. **Commits të rregullta dhe të strukturuara.**  
   Shmang commit-in “all-in-one”. Bëj commits të vegjël, secili për një ndryshim logjik.
4. **Push/Pull të rregullta.**  
   Para se të fillosh punën, bëj `pull`. Pas commits, bëj `push`.

---

## 2) Setup lokal (Clone + Build/Run)

### 2.1 Clone repository
```bash
git clone <REPO_URL>
cd <PROJECT_FOLDER>
```

### 2.2 Build & Run (C++)
> Projekti aktual është një aplikacion C++ (CLI). Komanda varet nga struktura e repo-s.

**Nëse `main.cpp` është në root:**
```bash
g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o app
./app
```

**Nëse kodi është në `src/main.cpp`:**
```bash
g++ -std=c++17 -O2 -Wall -Wextra src/main.cpp -o app
./app
```

**Windows (MinGW):**
```powershell
g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o app.exe
.pp.exe
```

---

## 3) Workflow standard: Branch → PR → Merge

### 3.1 Krijo një branch të ri
Përdor këto prefikse:
- `feature/<pershkrim>` për funksionalitete të reja
- `fix/<pershkrim>` për bugfix
- `docs/<pershkrim>` për dokumentim
- `chore/<pershkrim>` për pastrim/konfigurim

Shembull:
```bash
git checkout main
git pull origin main
git checkout -b feature/patient-crud
```

### 3.2 Puno, testo, commit
- Bëj ndryshime të vogla
- Kompilo/ekzekuto (shiko Seksionin 2)
- Pastaj commit

```bash
git status
git add .
git commit -m "feat: implement patient add and list"
```

### 3.3 Push branch-in
```bash
git push -u origin feature/patient-crud
```

### 3.4 Hape Pull Request (PR) në GitHub
- Base: `main`
- Compare: branch-i yt (p.sh. `feature/patient-crud`)
- Përfshi përshkrim + testim + checklist.

**Template për PR (kopjo në body):**
- **Çfarë u ndryshua / u shtua**
  - [ ] ...
- **Si u testua**
  - [ ] `g++ ...` (komanda)
  - [ ] Manual test: (skenarët)
- **Checklist**
  - [ ] Nuk kam punuar direkt në `main`
  - [ ] Commits të vogla dhe me mesazhe të qarta
  - [ ] Projekti kompilohet pa errors
  - [ ] README/Dokumentimi u përditësua (nëse ishte e nevojshme)

### 3.5 Merge në `main`
Pas review/diskutimit:
- Merge PR në `main` (merge commit ose squash janë ok).
- Pastaj në kompjuter:
```bash
git checkout main
git pull origin main
```

---

## 4) Rregulla për commits (Conventional Commits)
Përdor formatin:
- `feat: ...` (funksionalitet i ri)
- `fix: ...` (rregullim bug-u)
- `docs: ...` (dokumentim)
- `refactor: ...` (ristrukturim pa ndryshim sjelljeje)
- `chore: ...` (konfigurime/pastrime)

Shembuj:
- `feat: add appointment creation flow`
- `fix: validate patient age input`
- `docs: update README build instructions`
- `refactor: extract menu printing into function`

**Rregull praktik:** 1 commit ≈ 1 ndryshim logjik.

---

## 5) Sinkronizimi (push/pull) dhe zgjidhja e konflikteve
### 5.1 Para punës
```bash
git checkout main
git pull origin main
```

### 5.2 Kur `main` ndryshon gjatë punës tënde
```bash
git checkout feature/patient-crud
git fetch origin
git merge origin/main
```

Nëse ka konflikte:
1. Hape file-t me konflikt dhe rregullo manualisht
2. `git add .`
3. `git commit -m "fix: resolve merge conflicts"`
4. `git push`

---

## 6) Standard minimal i cilësisë së kodit (C++)
- Kodi duhet të kompilohet me `-std=c++17`.
- Mos shto code që prish rrjedhën ekzistuese (menu/opsione) pa e dokumentuar.
- Nëse lexon input numerik, kontrollo `cin.fail()` dhe pastro input-in kur ka gabim.
- Ruaj konsistencën e stilit (indentim, emërtim funksionesh/variablash).

---

## 7) Dokumentimi në repo (skedarë ndihmës)
Ky projekt kërkon që repository të përmbajë:
- **source code** 
- **README.md** (përshkrimi, udhëzime për nisje lokale, si kontribuohet)
- **CONTRIBUTING.md**
-  `.gitignore`, `LICENSE`, templates / CI

---

**Autorët:** Rron Dervishaj, Ardian Ramaj, Erin Berisha, Arjon Morina
