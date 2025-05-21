# so_long

**Instalation:**

- go to minilibx-linux dir and do 'make'
	- if error are shown install x11 libs
	```shell
	sudo apt install libxext-dev libx11-dev
	```

- go to main directorio and do 'make'
- 'make test' for testing

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

## vesion cc 42

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


## TODO

- [x] program parameter is ber file
- [x] recolect all object and go out
- [] shorter route?
- [x] move with W, A, S y D and move in this directions
- [x] player can't enter walls 
- [x] show real moves count

- [] can clean change windows, minimize
- [x] ESC close windows clean
- [x] close with X clean
- [] clean exit?
- [x] use images

- [x] map need have
	- [x] an exit
	- [x] an object at least
	- [x] an initial position (player)
- [x] map must be rectagular
- [] map must be rounded by walls, if not, return error
- [x] must control a valid exit route
- [x] process each correct map
- [x] In case of error must return "Error\n" and a message

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

## cosiderations for leaks

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

# test exit

to test exit message use, this show the exit status of the last command launched

```shell
echo $?
```