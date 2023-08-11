<h1><p align="center">itow</p></h1>
<p align="center"><i>"Integer-To-Words"</i></p>
<p align="center">A high-speed, lightweight conversion tool for transliterating numerical values into orthographic text</p>

---

<h4><p align="center"><i>Translation Range</i></p></h4>
<p align="center"><i>0 to +18,446,744,073,709,551,615</i></p>

<h4><p align="center"><i>Average Translation Speed</i></p></h4>
<p align="center"><i>0.00s user 0.00s system 57% cpu 0.007 total</i></p>

---

Example Output:

    23456 -> Twenty Three Thousand Four Hundred Fifty Six

    444265 -> Four Hundred Fourty Four Thousand Two Hundred Sixty Five

    2398592602632 -> Two Trillion Three Hundred Ninety Eight Billion Five Hundred Ninety Two Million Six Hundred Two Thousand Six Hundred Thirty Two

---

<h4>Build:</h4>

    cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
    cmake --build build --config Release

<h4>Run:</h4>

    ./bin/itow



(Optional) - Run using command line argument:

    ./bin/itow 78341
