#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main() {
    // Size (in bytes) of shared memory object
    const int SIZE = 4096;
    // Name of shared memory object
    const char* name = "OS";
    // String written to shared memory object
    const char* message_0 = "Hello";
    const char* message_1 = "World";

    // Shared memory file descriptor
    int shm_fd;

    // Pointer to shared memory object
    void* ptr;

    // Create shared memory object
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(1);
    }

    // Configure the size of shared memory object
    if (ftruncate(shm_fd, SIZE) == -1) {
        perror("ftruncate");
        exit(1);
    }

    // Map the shared memory object
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Write to shared memory object
    char* char_ptr = (char*)ptr;  // Cast the pointer to char*
    sprintf(char_ptr, "%s", message_0);
    char_ptr += strlen(message_0) + 1; // Include the null terminator
    sprintf(char_ptr, "%s", message_1);
    char_ptr += strlen(message_1) + 1; // Include the null terminator

    // Clean up
    close(shm_fd);

    return 0;
}
