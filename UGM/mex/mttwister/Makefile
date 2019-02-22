INCDIR = -I./inc
PGIFLAGS = -ta=nvidia:time -fast -Msafeptr -mp -Minfo=loop,accel,vect,mp -lOpenCL
#PGIFLAGS = -ta=nvidia:time,cc20 -fast -Msafeptr -mp -Minfo=loop,accel,vect,mp -lOpenCL 
NVCCFLAGS = -O3 -arch=sm_13
#NVCCFLAGS = -O3 -arch=sm_20
SRCS := $(wildcard $(SRC_DIR)*.c)
OBJS := $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LDFLAGS = 
LDLIBS = -L/usr/lib
EXECUTABLE = mersenneTwister

all:
	pgcc $(PGIFLAGS) $(SRCS) $(INCDIR) -o $(EXECUTABLE)
	nvcc mersenneTwisterCUDA.cu $(NVCCFLAGS) $(INCDIR) -o $(EXECUTABLE)_cuda

clean:
	rm -f *.o *.oo $(EXECUTABLE) $(EXECUTABLE)_cuda

