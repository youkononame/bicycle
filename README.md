# bicycle 🚲
![Static Badge](https://img.shields.io/badge/cmake-%3E%3D3.28.3-blue)
![Static Badge](https://img.shields.io/badge/License-GNU_AGPL--3.0-yellow)
![Static Badge](https://img.shields.io/badge/this%20aint-texas-red)

> A command line utility for playing with cards
>
> Submission for Hack Club's [TerminalCraft](https://terminalcraft.hackclub.com)

# Usage
```bash
bicycle [OPTION]...
```
* `-r, --row-size=SIZE` Maximum cards displayed in one row
* `-c, --cards=NUMBER` Number of cards dealt
* `-d, --decks=NUMBER` Number of decks in the shoe
* `-s, --seed=SEED` RNG seed for shuffling
* `-b, --baccarat` Play a game of baccarat
* `-n, --no-shuffle` Deal cards without shuffling
* `-h, --help` Displays this help message

The row size, hand size, number of decks and seed all must be at least 1.

# Installation
## Binaries
Pre-compiled binaries can be found in the [Releases](https://github.com/youkononame/bicycle/releases/) tab

For ease of access, add the file to your `PATH` environment variable to be usable from any directory

## Build from source
Instructions to build from source are currently only available for Unix systems.

### Prerequisites
- cmake >= 3.28.3
- A build tool of your choosing

### Instructions
```bash
git clone https://github.com/youkononame/bicycle
cd bicycle/
cmake -S . -B build
cmake --build build
./build/bicycle
```
By default, the --build option will use `make` to compile.

# License
This project is licensed under GNU AGPL-3.0

See the [LICENSE](LICENSE) file for more details.

> [!NOTE]
> This project relies on [cargs](https://github.com/likle/cargs), which is released under the MIT License
>
> See the [cargs LICENSE.md file](src/cargs/LICENSE.md) for more details
