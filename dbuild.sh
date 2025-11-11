# c
gcc -o c/hello_world.c.o c/hello_world.c -std=c23;

# --------------------------------------------------------- #

# cc
g++ -o cc/hello_world.cc.o cc/hello_world.cc -std=c++23;

# --------------------------------------------------------- #

# go
go build -o go/hello_world.go.o go/hello_world.go;

# --------------------------------------------------------- #

# rust
rustc -o rust/hello_world.rs.o rust/hello_world.rs;

# --------------------------------------------------------- #

# zig
zig build-exe -femit-bin=zig/hello_world.zig.o zig/hello_world.zig;

# --------------------------------------------------------- #

