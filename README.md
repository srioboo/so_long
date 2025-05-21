# so_long

**Instalation:**

- go to minilibx-linux dir and do 'make'
	- if error are shown install x11 libs
	```shell
	sudo apt install libxext-dev libx11-dev
	```

- go to main directory and do 'make'
- 'make test' for testing with default map

To ejecute another maps, do make and

```shell
./so_long maps/choose_one_map.ber
```

# utils

- **sudo showkey -k** show pressed key (-a for ascii)
- **convert svg to png**: mogrify -format png *.svg or mogrify -format xpm *.svg
- **scale image**: convert small.xpm -scale 16x16 bigger.xpm
- **mirrow image**: convert -flop input.png output.png

## compile library MLX42

```shell
cd MLX42
cmake -B build # build here refers to the outputfolder.
cmake --build build -j4 # or do make -C build -j4
```

## suppresion files

```shell
valgrind --leak-check=full --track-origins=yes --gen-suppressions=all ./so_long ./maps/map0.ber

# use with
valgrind --leak-check=full --track-origins=yes --suppressions=valgrind.supp ./so_long ./maps/map0.ber
```
file example, put in ...
```shell
{
   radeonsi_dri.so memory leak
   Memcheck:Leak
   match-leak-kinds: possible
   fun:malloc
   obj:/usr/lib/x86_64-linux-gnu/dri/radeonsi_dri.so
   ...
}
```
Use the following regex to clean:

```shell
==.*$\n
```

# test exit message

to test exit message use, this show the exit status of the last command launched

```shell
echo $?
```

## cosiderations for leaks

```shell
OK ==2733011==    definitely lost: 0 bytes in 1 blocks
OK ==2733011==    indirectly lost: 0 bytes in 0 blocks
KO ==2733011==      possibly lost: 92,991 bytes in 275 blocks (must be 0 blocks)
KO ==2733011==    still reachable: 7,494,024 bytes in 11,653 blocks (3106)

==2733011== LEAK SUMMARY:
==2733011==    definitely lost: 0 bytes in 1 blocks
==2733011==    indirectly lost: 0 bytes in 0 blocks
==2733011==      possibly lost: 92,991 bytes in 275 blocks
==2733011==    still reachable: 7,494,024 bytes in 11,653 blocks
==2733011==                       of which reachable via heuristic:
==2733011==                         newarray           : 768,888 bytes in 9 blocks
==2733011==                         multipleinheritance: 19,200 bytes in 28 blocks
==2733011==         suppressed: 0 bytes in 0 blocks
==2733011== Reachable blocks (those to which a pointer was found) are not shown.
==2733011== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==2733011== 
==2733011== For lists of detected and suppressed errors, rerun with: -s
==2733011== ERROR SUMMARY: 199 errors from 199 contexts (suppressed: 0 from 0)
```

## version cc 42

Ubuntu clang version 12.0.1-19ubuntu3
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin

INFO
https://phoenixnap.com/kb/install-gcc-ubuntu

## Resources

- https://harm-smits.github.io/42docs/
- https://iconoir.com/
- https://github.com/codam-coding-college/MLX42
- https://itch.io/
- https://convertio.co/
- https://www.freepik.com/