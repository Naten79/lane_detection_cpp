# lane_detection_cpp

## Installation

Sous Windows avec [MSYS2](https://www.msys2.org/), dans le terminal **MSYS2 UCRT64** :

```bash
pacman -S --needed mingw-w64-ucrt-x86_64-toolchain mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja mingw-w64-ucrt-x86_64-opencv
```

## Compilation et lancement

Depuis la racine du projet :

| Commande | Quand l'utiliser |
|---|---|
| `cmake -S . -B build -G Ninja` | Une seule fois au début, puis après chaque modification du `CMakeLists.txt` (par exemple pour ajouter un `.cpp`) |
| `cmake --build build` | Après chaque modification du code |
| `.\build\lane_detection.exe` | Pour lancer le programme (il ne recompile pas, il faut compiler avant) |