# 🌱 Automatyczne Podlewanie Roślin – Raspberry Pi + Node-RED

System automatycznego podlewania roślin oparty na Raspberry Pi z wizualnym schematem blokowym w Node-RED. Urządzenie monitoruje wilgotność gleby i automatycznie aktywuje pompę wodną, gdy rośliny potrzebują podlewania.

---

### 1. Instrukcja uruchomienia
Podłącz elementy ze sobą jak w dokumentacji załączonej tutaj: 

Raspberry Pi wyświetl poprzez HDMI na monitorze, np. na telewizorze.
Po uruchomieniu się Raspberry, co może zająć do 3min, uruchom 2 terminale.

Pierwszy terminal:
```
python doniczka3.py
```

Drugi terminal:
```
1. W terminalu wpisz: node-red
2. Otwórz przeglądarkę i przejdź pod adres: `http://127.0.0.1:1880/ui`
```

## 📸 Zdjęcia poglądowe

### 2. Okablowanie – czujnik wilgotności i pompa
![Schemat okablowania](https://github.com/HelenaMaslowska/Water-pot/blob/main/Photos/fritzig.png)

*Połączenie czujnika wilgotności gleby z pinami GPIO Raspberry Pi oraz podłączenie pompy przez przekaźnik.*

---

### 3. Gotowe urządzenie
<details open>
  <summary>📸 Kliknij, aby zobaczyć zrzuty ekranu</summary>
  <br>
  <p align="center">
    <img src="https://github.com/HelenaMaslowska/Water-pot/blob/main/Photos/IMG_6929.jpg" alt="1" height="400">
    <img src="https://github.com/HelenaMaslowska/Water-pot/blob/main/Photos/IMG_6933.jpg" alt="2" height="400">
    <img src="https://github.com/HelenaMaslowska/Water-pot/blob/main/Photos/terminal.png" alt="3" height="400">
  </p>
</details>

*Kompletne urządzenie zainstalowane przy pojemniku do testów – Raspberry Pi, czujnik napięcia i wąż doprowadzający wodę.*

---

Zobaczysz panel z:
- aktualnym poziomem wilgotności gleby
- historycznym wykresem pomiarów
- przyciskiem ręcznego podlewania
- ustawieniami progu automatycznego podlewania

---

## 🔧 Konfiguracja

| Parametr | Domyślna wartość | Opis |
|---|---|---|
| `PROG_WILGOTNOSCI` | `30` | Próg (%) poniżej którego uruchamia się pompa |
| `CZAS_PODLEWANIA` | `1` | Czas pracy pompy w sekundach |
| `INTERWAL_POMIARU` | `20` | Co ile sekund odczytywany jest czujnik |

---

## 📋 Schemat blokowy algorytmu

```
START
  │
  ▼
Odczyt czujnika wilgotności (co sekundę)
  │
  ▼
Wilgotność < 30%? ── NIE ── ► Czekaj do następnego pomiaru
  │
 TAK
  │
  ▼
Włącz pompę
  │
  ▼
Odczekaj 1 sekundę
  │
  ▼
Wyłącz pompę
  │
  ▼
Zapisz log + wyślij powiadomienie (opcjonalnie)
  │
  ▼
Czekaj do następnego pomiaru
```

---
