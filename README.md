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