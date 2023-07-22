<h1><p align="center">ntot</p></h1>
<p align="center"><i>"Number-To-Orthograpic-Text"</i></p>
<p align="center">A high-speed, lightweight conversion tool for transliterating numerical values into orthographic text</p>

---

<h4><p align="center"><i>Average Translation Speed</i></p></h4>
<p align="center"><i>0.00s user 0.00s system 57% cpu 0.007 total</i></p>

---

Example Output:

    23456 -> Twenty three thousand four hundred fifty six

---

<h4>Build:</h4>

    cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
    cmake --build build --config Release

<h4>Run:</h4>

    ./bin/ntot
