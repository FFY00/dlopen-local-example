### GLIBC

```
$ docker run -it -v .:/src archlinux:base-devel /bin/bash
[root@0d2394626aa9 /]# cd src
[root@0d2394626aa9 src]# make clean
rm *.so main
[root@0d2394626aa9 src]# make
cc main.c -o main
cc foo.c -o libfoo.so -Wl,-soname,libfoo.so -shared
cc bar.c -o libbar.so -Wl,-soname,libbar.so -shared -L. -lfoo
[root@0d2394626aa9 src]# ./main
libfoo at 0x584227c4c2c0
libbar at 0x584227c4d620
calling bar()
foo
```

### Musl

```
$ docker run -it -v .:/src alpine /bin/sh
/ # apk add make gcc musl-dev
fetch https://dl-cdn.alpinelinux.org/alpine/v3.17/main/x86_64/APKINDEX.tar.gz
fetch https://dl-cdn.alpinelinux.org/alpine/v3.17/community/x86_64/APKINDEX.tar.gz
(1/13) Upgrading musl (1.2.3-r4 -> 1.2.3-r5)
(2/13) Installing libgcc (12.2.1_git20220924-r4)
(3/13) Installing libstdc++ (12.2.1_git20220924-r4)
(4/13) Installing binutils (2.39-r2)
(5/13) Installing libgomp (12.2.1_git20220924-r4)
(6/13) Installing libatomic (12.2.1_git20220924-r4)
(7/13) Installing gmp (6.2.1-r2)
(8/13) Installing isl25 (0.25-r1)
(9/13) Installing mpfr4 (4.1.0-r0)
(10/13) Installing mpc1 (1.2.1-r1)
(11/13) Installing gcc (12.2.1_git20220924-r4)
(12/13) Installing make (4.3-r1)
(13/13) Installing musl-dev (1.2.3-r5)
Executing busybox-1.35.0-r29.trigger
OK: 152 MiB in 27 packages
/ # cd src
/src # make clean
rm *.so main
/src # make
cc main.c -o main
cc foo.c -o libfoo.so -Wl,-soname,libfoo.so -shared
cc bar.c -o libbar.so -Wl,-soname,libbar.so -shared -L. -lfoo
/src # ./main
libfoo at 0x74b3d566ccc0
error: Error loading shared library libfoo.so: No such file or directory (needed by ./libbar.so)
```
