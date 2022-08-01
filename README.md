# pride-flags
A WIP C based pride flag displayer.

Currently flags are different widths in order to keep a similar aspect ratio,
if you want to use the program I recommend modifying the code to achieve the behaviour you want.

## How to compile
Compile using `make` or `make compile`, and then install it to /usr/local/bin by running `make install` as root.

## How to use
Run program with command `pride`.
- if not given input, displays a random flag
- if given one of the codes "rainbow", "les", "gay",
  "bi", "trans", "nb", or "ace", displays the corresponding flag.
- otherwise displays nothing
