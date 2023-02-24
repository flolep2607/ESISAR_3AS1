---
title: CS351@ Esisar -- MIPS Emulator Developer Documentation
subtitle: Step 2, 2021-2022 
author: Laure Gonnord
papersize: a4
geometry: margin=1.5cm
fontsize: 12pt
lang: fr
---


# Structure of the code
* display.[c|h] : useful functions to input/output files in hex format
* main.c : ...

# Encoding choices


For the `instruction` datastructure, I chose to use a sum type (struct) since: ...




# Known bugs/undef behavior 
* for `SLL` assembler I decided to accept negative offsets and to encode them into 2's complement.
* There was an issue for the `BGTZ` that I think is a bug blablablabla


