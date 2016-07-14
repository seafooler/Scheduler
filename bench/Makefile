objects = benchmark_cfs.o benchmark_cfs_normal.o \
benchmark_cfs_uniform.o generate_random.o

benchmark_cfs : $(objects)
	gcc -o benchmark_cfs $(objects) -lm

#benchmark_cfs.o : benchmark_cfs.h benchmark_cfs_uniform.h \
#benchmark_cfs_normal.h file_oper.h
#benchmark_cfs_normal.o : benchmark_cfs_normal.h generate_random.h
#benchmark_cfs_unifrom.o : benchmark_cfs_uniform.h generate_random.h
#generate_random.o : generate_random.h

benchmark_cfs.o : benchmark_cfs.c benchmark_cfs.h benchmark_cfs_uniform.h \
benchmark_cfs_normal.h file_oper.h
	gcc -g -c benchmark_cfs.c
benchmark_cfs_normal.o : benchmark_cfs_normal.c benchmark_cfs_normal.h generate_random.h
	gcc -g -c benchmark_cfs_normal.c
benchmark_cfs_uniform.o : benchmark_cfs_uniform.c benchmark_cfs_uniform.h generate_random.h
	gcc -g -c benchmark_cfs_uniform.c
generate_random.o : generate_random.c generate_random.h
	gcc -g -c generate_random.c



#.PHONY : debug
#debug:
#	gcc -g -o benchmark_cfs $(objects) -lm

.PHONY : clean
clean:
	rm benchmark_cfs $(objects)
