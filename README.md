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

## compile library MLX42

```shell
cd MLX42
cmake -B build # build here refers to the outputfolder.
cmake --build build -j4 # or do make -C build -j4
```

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

## cosiderations for leaks

==192925== LEAK SUMMARY:
==192925==    definitely lost: 5,630 bytes in 33 blocks    -> herea es 0 bytes in 0 block
==192925==    indirectly lost: 410,078 bytes in 33 blocks
==192925==      possibly lost: 0 bytes in 0 blocks
==192925==    still reachable: 317,955 bytes in 3,106 blocks -> this is correct
==192925==         suppressed: 0 bytes in 0 blocks
==192925== Reachable blocks (those to which a pointer was found) are not shown.
==192925== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==192925== 
==192925== For lists of detected and suppressed errors, rerun with: -s
==192925== ERROR SUMMARY: 12 errors from 12 contexts (suppressed: 0 from 0)

==294654== LEAK SUMMARY:
==294654==    definitely lost: 22,718 bytes in 645 blocks
==294654==    indirectly lost: 10,355,166 bytes in 640 blocks
==294654==      possibly lost: 81,920 bytes in 5 blocks
==294654==    still reachable: 317,955 bytes in 3,106 blocks
==294654==         suppressed: 0 bytes in 0 blocks
==294654== Reachable blocks (those to which a pointer was found) are not shown.
==294654== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==294654== 
==294654== For lists of detected and suppressed errors, rerun with: -s
==294654== ERROR SUMMARY: 18 errors from 18 contexts (suppressed: 0 from 0)

==297874== LEAK SUMMARY:
==297874==    definitely lost: 12,542 bytes in 221 blocks
==297874==    indirectly lost: 3,473,886 bytes in 220 blocks
==297874==      possibly lost: 16,384 bytes in 1 blocks
==297874==    still reachable: 317,955 bytes in 3,106 blocks
==297874==         suppressed: 0 bytes in 0 blocks
==297874== Reachable blocks (those to which a pointer was found) are not shown.
==297874== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==297874== 
==297874== For lists of detected and suppressed errors, rerun with: -s
==297874== ERROR SUMMARY: 16 errors from 16 contexts (suppressed: 0 from 0)

==700749== LEAK SUMMARY:
==700749==    definitely lost: 7,782 bytes in 19 blocks
==700749==    indirectly lost: 82,391 bytes in 13 blocks
==700749==      possibly lost: 0 bytes in 0 blocks
==700749==    still reachable: 317,955 bytes in 3,106 blocks
==700749==         suppressed: 0 bytes in 0 blocks
==700749== Reachable blocks (those to which a pointer was found) are not shown.
==700749== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==700749== 
==700749== ERROR SUMMARY: 15 errors from 15 contexts (suppressed: 0 from 0)

AFTER REFACTORING: 497304b4fc04ef06b6c687dc30292e6aee6ad724
==3007285== LEAK SUMMARY:
==3007285==    definitely lost: 6,287 bytes in 19 blocks
==3007285==    indirectly lost: 32,574 bytes in 1,309 blocks
==3007285==      possibly lost: 7,862 bytes in 37 blocks
==3007285==    still reachable: 2,910,020 bytes in 30,302 blocks
==3007285==         suppressed: 616 bytes in 3 blocks
==3007285== Reachable blocks (those to which a pointer was found) are not shown.
==3007285== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==3007285== 
==3007285== For lists of detected and suppressed errors, rerun with: -s
==3007285== ERROR SUMMARY: 35 errors from 35 contexts (suppressed: 0 from 0)

==3620929== LEAK SUMMARY:
==3620929==    definitely lost: 6,069 bytes in 14 blocks
==3620929==    indirectly lost: 32,150 bytes in 1,306 blocks
==3620929==      possibly lost: 7,526 bytes in 36 blocks
==3620929==    still reachable: 2,911,478 bytes in 30,323 blocks
==3620929==         suppressed: 616 bytes in 3 blocks
==3620929== Reachable blocks (those to which a pointer was found) are not shown.
==3620929== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==3620929== 
==3620929== For lists of detected and suppressed errors, rerun with: -s
==3620929== ERROR SUMMARY: 33 errors from 33 contexts (suppressed: 0 from 0)

==2032940== LEAK SUMMARY:
==2032940==    definitely lost: 145 bytes in 4 blocks
==2032940==    indirectly lost: 526 bytes in 13 blocks
==2032940==      possibly lost: 92,991 bytes in 275 blocks
==2032940==    still reachable: 7,494,144 bytes in 11,656 blocks
==2032940==                       of which reachable via heuristic:
==2032940==                         newarray           : 768,888 bytes in 9 blocks
==2032940==                         multipleinheritance: 19,200 bytes in 28 blocks
==2032940==         suppressed: 0 bytes in 0 blocks
==2032940== Reachable blocks (those to which a pointer was found) are not shown.
==2032940== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==2032940== 
==2032940== For lists of detected and suppressed errors, rerun with: -s
==2032940== ERROR SUMMARY: 202 errors from 202 contexts (suppressed: 0 from 0)

==2058131== LEAK SUMMARY:
==2058131==    definitely lost: 64 bytes in 1 blocks
==2058131==    indirectly lost: 231 bytes in 6 blocks
==2058131==      possibly lost: 0 bytes in 0 blocks
==2058131==    still reachable: 335 bytes in 8 blocks
==2058131==         suppressed: 0 bytes in 0 blocks
==2058131== Reachable blocks (those to which a pointer was found) are not shown.
==2058131== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==2058131== 
==2058131== For lists of detected and suppressed errors, rerun with: -s
==2058131== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
make: *** [Makefile:83: val] Error 1
