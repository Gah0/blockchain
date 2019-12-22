# Gblockchain anthor Gah0 on 2019

objects = client.o block.o block_verify.o

src:$(objects)
	cc -o src:$(objects)

block.o: block.h
block_verify.o: block_verify.h

.PHONY:clean

clean:
	-rm src $(objects)
	make clean 
