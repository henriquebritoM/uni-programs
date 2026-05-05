how to compile to asm?

cargo rustc --release --bins -- --emit asm

where the asm goes?

./target/release/deps/<some hash>.s
