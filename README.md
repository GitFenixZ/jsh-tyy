# jsh-tyy - Linux Job Control Shell

## Description

This project was carried out as part of our Operating Systems course, where our team developed a simple yet functional shell with extensive features including job control tailored for Linux systems, demonstrating our ability to harness the power of the C programming language and Linux system calls.

To thoroughly develop this project, our team of three established and followed efficient development workflow including proper testing practices by leveraging a Git workflow and tools such as :

- The `GNU Compiler Collection (gcc)` and `GNU Make (make)` to facilitate compilation and build processes.
- The `GNU Debugger (gdb)` and `valgrind` to debug memory and file descriptor issues.
- The simple [`cinta`](https://github.com/Yag000/cinta) test framework developed by [Yago Iglesias](https://github.com/Yag000), along with scripts to establish unit tests.
  
As part of our development and testing process, we also used a continuous integration (CI) pipeline, hosted and managed via GitLab.

These practices allowed us to deliver a comprehensive, stable, and reliable product that fulfilled the imposed requirements in a timely and efficient manner, earning us a grade of 20 out of 20.

## Table of Contents
- [jsh-tyy - Linux Job Control Shell](#jsh-tyy---linux-job-control-shell)
  - [Description](#description)
  - [Table of Contents](#table-of-contents)
  - [Features](#features)
  - [Running the shell](#running-the-shell)
    - [Prerequisites](#prerequisites)
    - [Compilation](#compilation)
    - [Execution](#execution)
  - [Testing](#testing)
  - [More information (in French)](#more-information-in-french)
  - [Authors](#authors)

## Features

This is a non-exhaustive list of the features of our shell:

- Built-in commands: `cd`, `exit`, `jobs`, `fg`, `bg`, `kill` and `?` (environment variables are not updated, so this is the same as `echo $?`)
- Redirections: `>`, `>|`, `>>`, `2>`, `2>|`, `2>>`, `<`
- Pipelines: `|`
- Command substitution: `<()`
- Background jobs: `&`
- Job control

## Running the shell

### Prerequisites

This project requires `gcc` and `make` to be installed on your system, along with the `readline` library.
It should run on any Linux distribution, but it's sadly not `POSIX` compliant,
we use the `proc` virtual filesystem to get some pieces of information about the processes
and for named pipes, maybe one day we'll change that, should be fun.

For those of you who are interested on running the tests, you will need `valgrind` installed on your system (explained later).

### Compilation

To compile the project, execute the command

```sh
make
```

or

```sh
make jsh
```

### Execution

To run the project, execute the following command after compiling it

```sh
./jsh
```

## Testing

You can run the tests using the following commands, some may require `valgrind` to be installed and some may
take a while to run (should be less than 2 minutes).

```sh
make test-unit        # our unit tests
make test-valgrind    # our unit tests with valgrind
make test-tyy         # our tests using the professors' framework
make test-professor   # our professors' test framework
make test             # all the tests
```

## More information (in French)

You can see the project's formal specification in the [project.md](./project.md) file.

We have also written a small report on our architecture and the choices we made,
you can find it in the [ARCHITECTURE.md](./ARCHITECTURE.md) file.

## Authors

See [AUTHORS.md](./AUTHORS.md)
