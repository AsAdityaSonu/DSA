#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    /* the size (in bytes) of the shared memory object */
    const int SIZE = 4096;
    /* name of the shared memory object */
    const char* name = "OS";
    /* shared memory file descriptor */
    int shm_fd;
    /* pointer to shared memory object */
    void* ptr;

    /* open the shared memory object */
    shm_fd = shm_open(name, O_RDONLY, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(1);
    }

    /* memory map the shared memory object */
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    /* read from the shared memory object */
    printf("%s", (char*)ptr);

    /* unmap the shared memory and close the file descriptor */
    if (munmap(ptr, SIZE) == -1) {
        perror("munmap");
        exit(1);
    }
    if (close(shm_fd) == -1) {
        perror("close");
        exit(1);
    }

    /* remove the shared memory object */
    if (shm_unlink(name) == -1) {
        perror("shm_unlink");
        exit(1);
    }

    return 0;
}
