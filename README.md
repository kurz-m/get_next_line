<h1 align="center">
    <p>
        📓 get_next_line
    </p>
</h1>

<p align="center">
    <b><i>Repo for the get_next_line project at 42 Heilbronn</i></b>
</p>

<p align="center">
    This repository is coded in&nbsp&nbsp
    <a href="https://skillicons.dev">
        <img src="https://skillicons.dev/icons?i=c" />
    </a>
     &nbsp&nbspwith&nbsp&nbsp
    <a href="https://skillicons.dev">
        <img src="https://skillicons.dev/icons?i=neovim" />
    </a>
</p>

<h3 align="center">
    Status
</h3>

<p align="center">
    Finished: 12/04/2023<br>
    Grade: 125%
</p>

---

## 💾 About
> The task of the get_next_line project is to code a C function that extracts _one line at a time_ from a text file the file descriptor is pointing to.

## Usage
The _get_next_function_ is not a stand-alone function. It has to be 
included in another project/main function to test and run it.

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argc)
{
    int     fd;
    char    *line;

    (void) argc;
    fd = open(argv[1], O_RDONLY);
    line = "";
    while (line != NULL)
    {
        line = get_next_line(fd);
        printf("%s", line);
    }
    fd = close(fd);
    return (0);
}
```

## Compilation
```c
gcc main.c get_next_line.c get_next_line_utils.c
```
