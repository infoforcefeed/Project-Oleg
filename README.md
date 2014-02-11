Project Oleg
============

[![Build Status](https://drone.io/github.com/infoforcefeed/Project-Oleg/status.png)](https://drone.io/github.com/infoforcefeed/Project-Oleg/latest)

Alternate title: "How far can we push a mayonnaise metaphor?"

````
$ pgrep olegdb | xargs kill
olegdb: No.
````

OlegDB is a single-threaded, non-concurrent, transactionless NoSQL database
written by bitter SQL-lovers in a futile attempt to hop on the schemaless trend
before everyone realizes it was a bad move.

Dependencies
============

* A healthy fear of the end
* Erlang

Installation
============

OlegDB consists of a server written in Erlang and a C library for all of the
heavy lifting. Binaries are in `build/bin/` and the library is in `build/lib/`.
Beam files are also thrown in `build/bin/`.

```bash
# Building everything:
make
# Just the erlang beam files:
make erlang
# Just the C library:
make liboleg
```

To run tests:

```bash
./run_tests.sh
```

To run the erlang server:

```bash
./run_server.sh
```

curl2sudo® install script coming soon.

Documentation
=============

Documentation exists primarily on the [the website](https://olegdb.org/documentation.html),
but also in the [./docs](./docs/) directory.

Roadmap
=======

0.1
---

* Persistence
* Speaks HTTP with a heavy accent
* 32 byte hard keysize limit
* Working database

0.2
---
* Non-guaranteed record expiry
* Lists/Queues
* pub/sub (events)

1.0
---

* Distributed fault-tolerant store

2.0
---
* BSP Export
