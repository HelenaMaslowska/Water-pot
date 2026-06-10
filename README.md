# 🌱 Automatyczne Podlewanie Roślin – Raspberry Pi + Node-RED

System automatycznego podlewania roślin oparty na Raspberry Pi z wizualnym schematem blokowym w Node-RED. Urządzenie monitoruje wilgotność gleby i automatycznie aktywuje pompę wodną, gdy rośliny potrzebują podlewania.

---

## 📸 Zdjęcia poglądowe

### 1. Okablowanie – czujnik wilgotności i pompa
![Schemat okablowania]()

*Połączenie czujnika wilgotności gleby z pinami GPIO Raspberry Pi oraz podłączenie pompy przez przekaźnik.*

---

### 2. Gotowe urządzenie
![Gotowe urządzenie](https://github.com/HelenaMaslowska/Water-pot/blob/main/Photos/IMG_6929.jpg)
![Caly widok](https://github.com/HelenaMaslowska/Water-pot/blob/main/Photos/IMG_6933.jpg)

*Kompletne urządzenie zainstalowane przy pojemniku do testów – Raspberry Pi, czujnik napięcia i wąż doprowadzający wodę.*

---

```

### Krok 2 – Włącz Node-RED jako usługę systemową

```bash
# Uruchom Node-RED przy starcie systemu
sudo systemctl enable nodered.service

# Uruchom natychmiast
sudo systemctl start nodered.service
```

### Krok 3 – Zainstaluj wymagane węzły (nodes)

```bash
cd ~/.node-red

# Węzły GPIO dla Raspberry Pi
npm install node-red-node-pi-gpio

# Węzły dashboardu (panel wizualny)
npm install node-red-dashboard

# Opcjonalnie: powiadomienia MQTT
npm install node-red-contrib-mqtt-broker
```

### Krok 4 – Importuj schemat blokowy (flows)
1. W terminalu wpisz: node-red
2. Otwórz przeglądarkę i przejdź pod adres: `http://127.0.0.1:1880/ui`


### Krok 5 – Podłącz hardware

Sprawdź schemat w `docs/okablowanie.pdf` i podłącz:

```
Czujnik wilgotności  →  GPIO 4  (wejście cyfrowe)
Przekaźnik (pompa)   →  GPIO 17 (wyjście cyfrowe)
GND                  →  Pin 6
3.3V                 →  Pin 1
```

### Krok 6 – Otwórz dashboard

Przejdź pod adres:

```
http://<adres-ip-raspberry>:1880/ui
```

Zobaczysz panel z:
- aktualnym poziomem wilgotności gleby
- historycznym wykresem pomiarów
- przyciskiem ręcznego podlewania
- ustawieniami progu automatycznego podlewania

---

## 🔧 Konfiguracja

Główne parametry edytujesz bezpośrednio w węźle **„Konfiguracja"** w Node-RED lub w pliku `docs/konfiguracja.md`:

| Parametr | Domyślna wartość | Opis |
|---|---|---|
| `PROG_WILGOTNOSCI` | `30` | Próg (%) poniżej którego uruchamia się pompa |
| `CZAS_PODLEWANIA` | `5` | Czas pracy pompy w sekundach |
| `INTERWAL_POMIARU` | `60` | Co ile sekund odczytywany jest czujnik |
| `TRYB` | `auto` | Tryb pracy: `auto` lub `manual` |

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
