## Features

-   Miryoku inspired
-   [home-row mods](https://precondition.github.io/home-row-mods)
-   one-shot [⇧] in left thumb, double tap to caps-lock
-   double role tap [⌘ ␣] and hold [⌘] in left thumb
-   double role tap [⌥ ␣] and hold [⌥] in left thumb
-   [Achordion](https://getreuer.info/posts/keyboards/achordion/index.html)
-   [Select Word](https://getreuer.info/posts/keyboards/select-word/index.html)

## Flashing

-   Flash both halves
-   Enter bootloader mode by pressing the keyboard reset button
-   Run

The Kyria uses an Elite-PI microcontroller, running `qmk flash` will not work.

```
qmk compile -kb splitkb/kyria/rev2 -km GiacomoRandazzo
qmk flash -c -kb splitkb/kyria/rev2 -km GiacomoRandazzo -e CONVERT_TO=elite_pi
```

### Refs

-   (Which half to flash) https://docs.splitkb.com/hc/en-us/articles/360011949679-When-do-I-need-to-flash-my-microcontroller-
-   (Elite PI) https://docs.keeb.io/elite-pi-guide
