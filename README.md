*This project has been created as part of the 42 curriculum by lernst.*

# ft_printf

> Because `ft_putnbr()` and `ft_putstr()` aren't enough.

## Description

`ft_printf` is a re-implementation of the C standard library function `printf()`. It handles a variable number of arguments using variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`) and outputs formatted text to standard output, returning the total number of characters printed — exactly like the original.

Supported conversions: `%c` `%s` `%d` `%i` `%u` `%x` `%X` `%p` `%%`

## Algorithm & Data Structure

The core of `ft_printf` is a **linear format-string parser** combined with a **dispatch function**.

The main loop walks the format string character by character. When it encounters a `%` followed by a valid specifier, it calls `dispatch()`, which uses a chain of `if` statements to route to the correct handler function. Each handler extracts the next variadic argument via `va_arg`, formats it, writes it with `write`, and returns the number of characters written. The return values are accumulated into a running total that is returned at the end.

This approach was chosen for its clarity and simplicity — each specifier maps directly to one small, testable function, making the code easy to understand, debug, and extend.

## Instructions

**Requirements:** `cc`, `make`, `ar`

```bash
# Clone and build the library
git clone 
cd ft_printf
make

# This produces libftprintf.a at the root of the repository
```

To use `ft_printf` in another project, include the header and link against the library:

```bash
cc main.c -L/path/to/ft_printf -lftprintf -I/path/to/ft_printf -o program
```

**Makefile rules:**

| Rule     | Effect                              |
|----------|-------------------------------------|
| `make`   | Builds `libftprintf.a`              |
| `make clean` | Removes object files            |
| `make fclean` | Removes objects + library      |
| `make re` | Full rebuild                       |

## Resources

- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference — va_list / variadic functions](https://en.cppreference.com/w/c/variadic)
- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [42 Norm](https://github.com/42School/norminette)
- [Wikipedia](https://de.wikipedia.org/wiki/Printf)

### AI Usage

AI (Claude) was used in the following ways during this project:

- **Understanding concepts**: clarifying how `va_list`, `va_start`, `va_arg`, and `va_end` work together
- **Debugging**: identifying edge cases such as `NULL` string handling, `INT_MIN` formatting, and `%p` with a null pointer
- **Writing the tester**: building a comprehensive test file that captures and compares both output and return value against the real `printf`
- **Writing part of the README**

All implementation decisions, algorithm design, and final code were reasoned through and written by me. AI was used as a reference tool, not as a full code generator for the project itself.
