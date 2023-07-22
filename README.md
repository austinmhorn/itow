<h1><p align="center">ntot</p></h1>
<p align="center"><i>"Number-To-Orthograpic-Text"</i></p>
<p align="center">A tool for transliterating numerical values into orthographic text</p>

---

Example:


    23456 -> Twenty three thousand four hundred fifty six

---

Build:

    cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
    cmake --build build --config Release

Run:

    ./bin/ntot
