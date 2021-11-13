all:
	$(CC) -o $@ $^

%.o: %.c $(thing)
	$(CC) -c -o $@ $<

clean:
	rm *.o