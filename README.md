
<div align=center >
<h1>ft_printf</h1>
<img src="https://raw.githubusercontent.com/viruskizz/viruskizz-myutils/main/ft_printf_badge.png" alt="printft_badge" />
</div>

## _42cursus' project_



The **printf** function is one of the most versatile and well-known functions in the C language.From a testing aid to tabulation method, printf is a very powerful and important tool in everydev's kit. This project aims to recreate the behaviour of the original MacOS's printf, includingits basic error management, some of its flags, minimum field width stipulation and most of itsbasic conversions.

### Features

- Passed 3 tester
  - [Sanatana Tester](https://github.com/paulo-santana/ft_printf_tester/)
  - [Tripouille Tester](https://github.com/paulo-santana/ft_printf_tester/)
  - [Mazoise Tester](https://github.com/Mazoise/42TESTERS-PRINTF/)
- Support Linux and Mac environment
- Cover all bonus flag and `*` flag

<div align=center>
   <img src="https://raw.githubusercontent.com/viruskizz/viruskizz-myutils/main/printf_point.png" alt="printft_point" alt="printft_point" width=85% />
</div>

---

## Subject

Write a lib with ft_printf function that will mimic the real printf

#### Allow Function

```c
malloc(), free(), write(), va_start(), va_arg(), va_copy(), va_end()
```

### Mandatory

> <i>A small description of the required conversion:
>
> - `%c` print a single character.
> - `%s` print a string of characters.
> - `%p` The void * pointer argument is printed in hexadecimal.
> - `%d` print a decimal (base 10) number.
> - `%i` print an integer in base 10.
> - `%u` print an unsigned decimal (base 10) number.
> - `%x` print a number in hexadecimal (base 16).
> - `%%` print a percent sign.</i>

### Bonus

> _Manage any combination of the following flags:_
>
> - _`-0.` and minimum field width with all conversions_
> - _Manage all the following flags: `# +`(yes, one of them is a space)_

---

## What is ft_printf?

This project is about recoding the famous printf C function to learn variadic functions and improve algorithmic methodology.

```c
int ft_printf(const char * (restrict) format, ...);
```

ft_printf can print different contents depending on conversions and flags. You can print using the following syntax:

```txt
%[flag][min-width].[precision][length modifier][conversion specifier]
```

min-width depending on cases, will add empty spaces. Precision, depending on cases, will add '0'.

See below what are flags, length modifier and conversions.

## Conversions & Flags & Expected Order

| Conversion  | Description														 			| Project 		|
|-------|-----------------------------------------------------------------------------------|---------------|
| **c** | Single ascii character         													|Mandatory		|
| **s** | String of characters NULL terminated												|Mandatory		|
| **p** | Pointer location converted to hexadecimal value									|Mandatory		|
| **d** | Decimal number 																	|Mandatory		|
| **i** | Integer in decimal base                 											|Mandatory		|
| **u** | Unsigned integer in decimal base                									|Mandatory		|
| **x** | Unsigned number printed in lowercase hexadecimal base                				|Mandatory		|
| **X** | Unsigned number printed in uppercase hexadecimal base                				|Mandatory		|
| **%** | The '%' ascii character                 											|Mandatory		|
| **o** | Unsigned number printed in octal base                 							|Extra			|

| Flag  | Description														 				| Project 		|
|-------|-----------------------------------------------------------------------------------|---------------|
| **-** | Left align the argument passed	         										|Bonus 1		|
| **0** | Add '0' as a padding character in numeric conversions (single space is default)	|Bonus 1		|
| **.** | Precision definition, followed by a number 										|Bonus 1		|
| **+** | Add a plus sign ('+') in the front of positive numeric conversions 				|Bonus 2		|
| **' '** | Add a single space (' ') in the front of positive numeric conversions 			|Bonus 2		|
| **#** | Add the corresponding prefix in front of x, X and o conversions                 	|Bonus 2		|
| **\*** | Add a placeholder for numeric values that shall be passed through the variadic arguments  |Extra			|


| Holder key  | Prefix and justification flags *| Minimum Width *| Precision *	| Conversion 	|
|-------------|---------------------------------|---------------|---------------|---------------|
|`%`		  | `-` , `0` , `+` ,  ...			| `10`, `5` , ... | `.`, `.10`, `.5`, ... | `c`, `d`, `i`, `s`, ... |  

##### * : optional flags and definitions

---

## Usage

You can try our project with the following commands:

First, clone the repository

```sh
git clone https://github.com/viruskizz/42bangkok-ft_printf
cd ft_printf
make
```

---

## Algorithm and Concept

My concept printf is write read character ordering and grab `%`. write a normal character and coverting placeholder format to write coverted string.

Discovery this sheet to understand more about printf using case.
- [Conversion Formatter Table](https://docs.google.com/spreadsheets/d/10TEAQ8u5zbZmiY-rXugwbE9cI32G5E-DAooVszB93ro/edit#gid=0)

### Implementation

<br/>
<div align=center>
   <img src="https://raw.githubusercontent.com/viruskizz/viruskizz-myutils/main/printf_concept_dark.png" alt="printft_concept" alt="printft_concept" width=80% />
</div>
<br/>

1. Read character in ordering
   - [`ft_printf.c`](srcs/ft_printf.c)
2. Check and set formatter string as `t_format`
   - [`format_utils.c`](srcs/format_utils.c)
3. Write a character is not found `format`
   - `write(1, &c, 1)`
4. Convert format to converted string (`cstr`)
   - [`conversion_type.c`](srcs/conversion_type.c)
   - [`conversion_flag.c`](srcs/conversion_flag.c)
   - [`conversion_pcs.c`](srcs/conversion_pcs.c)
   - [`conversion_width.c`](srcs/conversion_width.c)
5. Write `cstr` with `print_str` or `print_char`
   - [`ft_printf_utils.c`](srcs/ft_printf_utils.c)
6. Shift read cursur equal format string length
7. Continue to read next character [(to step 1)](#/)

#### Conversion type

- [`conversion_c`](srcs/misc/conversion_c.c)
- [`conversion_d`](srcs/misc/conversion_d.c)
- [`conversion_p`](srcs/misc/conversion_p.c)
- [`conversion_s`](srcs/misc/conversion_s.c)
- [`conversion_u`](srcs/misc/conversion_u.c)
- [`conversion_x`](srcs/misc/conversion_x.c)

---

## Credit

README Inspiration:
- [_caroldanie_](https://github.com/caroldanie)
- [_TaKouMyS_](https://git.42l.fr/amamy/Ft_printf)
