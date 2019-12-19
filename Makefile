# Gblockchain anthor Gah0 on 2019

SHA_DIR = ./sha256
MAKE = make
 subsystem:
  cd %(SHA_DIR)&& $(MAKE)

src-objs = client.o block.o block_verify.o block_priv.o 

src:$(src-objs)
	cc- o src$(src-objs)

client.o: client.c
block.o: block.c block.h
block_verify.o: block_verify.c block_verify.h
block_priv.o: block_priv.c block_priv.o

.PHONY:clean

clean:
	rm src(src-objs)
 $(make) -c sha256/make clean
