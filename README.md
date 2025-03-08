# bicycle 🚲
![Static Badge](https://img.shields.io/badge/cmake-%3E%3D3.28.3-blue)
![Static Badge](https://img.shields.io/badge/make-%3E%3D4.3-blue)
![Static Badge](https://img.shields.io/badge/License-GNU_AGPL--3.0-yellow)

> A command line utility for playing with cards

# Usage
```bash
bicycle [-r, --row-size <size>] [-c, --cards <amount>] [-n, --no-shuffle] [-h, --help]
```
* `-r, --row-size <size>` The maximum number of cards that will be displayed in one row
* `-c, --cards <amount>` The amount of cards that will be dealt out
* `-n, --no-shuffle` If enabled, the deck will not be shuffled before cards are dealt out
* `-h, --help` Displays this help message

# Installation
## Binaries
Pre-compiled binaries can be found in the [Releases](https://github.com/youkononame/bicycle/releases/) tab

Move the binary into `/bin/` or `/usr/bin`, or any other folder in your `PATH`  for easy use from any directory

## Build from source
### Prerequisites
- cmake >= 3.28.3
- make >= 4.3

Although other versions may work, compatability cannot be guaranteed.

### Instructions
```bash
git clone https://github.com/youkononame/bicycle
cd bicycle/
cmake ./
make
```

# License
This project is licensed under GNU AGPL-3.0 - see the `LICENSE` file for more details.
