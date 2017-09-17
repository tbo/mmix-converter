# mmix-converter

This command line tool illustrates the memory reprentations of decimal numbers in Donald Knuth's [MMIX architecture](http://mmix.cs.hm.edu/).

## Usage

```
./mmix-converter *decimal number*
```

## Example output

```
 $ ./mmix-convert 42
 byte                                                           00101010                      #2A
 wyde                                                   0000000000101010                    #002A
 tetra                                  00000000000000000000000000101010                #0000002A
 octa   0000000000000000000000000000000000000000000000000000000000101010        #000000000000002A
```
