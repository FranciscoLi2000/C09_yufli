#!/bin/sh
LIB_NAME="libft.a"
CC="cc"
CFLAGS="-Wall -Wextra -Werror"
rm -f $LIB_NAME
echo "compile the source file..."
for src_file in *.c; do
	$CC $CFLAGS $src_file
done
ar rcs $LIB_NAME *.o
rm -f *.o
echo "static library $LIB_NAME have been created."
