# 42-Minitalk

A communication program using UNIX signals, developed as part of the 42 School curriculum.

## Description

Minitalk is a data exchange program using UNIX signals. It consists of a server and a client that communicate using `SIGUSR1` and `SIGUSR2` signals.

## How it works

- **Server**: Displays its PID upon launch and waits for signals from the client. When it receives a complete character (8 bits), it displays it.
- **Client**: Takes the server PID and a string as arguments, then sends the string character by character using signals.

## Installation

```bash
make
```

## Usage

1. Start the server:
```bash
./server
```

2. In another terminal, send a message:
```bash
./client <server_pid> "your message"
```

## Files

```
.
├── Makefile
├── README.md
├── includes/
│   └── minitalk.h
├── srcs/
│   ├── client.c
│   ├── server.c
│   └── utils.c
├── libs/
│   └── ft_printf/
└── tests/
    └── test*.txt
```

## Makefile targets

| Target | Description |
|--------|-------------|
| `all` | Build server and client |
| `clean` | Remove object files |
| `fclean` | Remove object files and executables |
| `re` | Rebuild the project |
| `norm` | Check norminette |

## Author

**tkhemniw** - [Gxmestk](https://github.com/Gxmestk)
