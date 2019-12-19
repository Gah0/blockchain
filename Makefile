# Gblockchain anthor Gah0 on 2019

 subsystem:
  $(MAKE) -C sha256

objects = client.o block.o block_verify.o block_priv.o 
src:$(objects)
	cc -o src:$(objects)

block.o: block.h
block_verify.o: block_verify.h
block_priv.o: block_priv.h

.PHONY:clean

clean:
	-rm src $(objects)
	make clean 