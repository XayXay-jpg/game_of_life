# game_of_life

### install

###### ssh

```bash
git clone git@github.com:XayXay-jpg/game_of_life.git
```


###### https
```bash
git clone https://github.com/XayXay-jpg/game_of_life.git
```

### how to start

<details>
<summary>Linux</summary>

```bash
sudo apt install libncurses5-dev
make
```


</details>

<details>
<summary>WINDOWS</summary>
1. Установить MSYS2 (https://www.msys2.org/)

2. В MSYS2 MSYS выполнить: 

```bash
pacman -Syu
```

3. В MSYS2 MinGW64 выполнить: 

```bash
pacman -S mingw-w64-x86_64-ncurses
```

4. Установить компилятор: 

```bash
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```

</details>