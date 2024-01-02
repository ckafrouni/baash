# Baash

Baash is a basic implementation of a bash-like shell. It supports a few basic builtin commands like `cd`, `exit`, `clear`, and `pwd`.

## Example

Here is an example of how to use Baash:

![Usage Example](docs/usage-example.png)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

- GCC
- Make

### Building

To build the project, run the following command in the root directory of the project:

```sh
make all
```

This will compile the source files and link them into an executable in the `build` directory.

### Running

To run the built executable, use the following command:

```sh
make run # or ./build/baash
```

## Features

- `cd <path>`: Change the current directory to `<path>`.
- `exit`: Exit the shell.
- `clear`: Clear the terminal screen.
- `pwd`: Print the current working directory.

## Todo

- `./<program>`: spawn a child process to execute the program.
- `cd`: Change the current directory to `$HOME`
