#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

int main() {
    // Get the current working directory
    char buffer[MAX_PATH];
    DWORD result = GetCurrentDirectoryA(MAX_PATH, buffer);

    if (result == 0) {
        std::cerr << "Error getting current working directory\n";
        return 1;
    }

    std::cout << "Current working directory: " << buffer << std::endl;

    // Opening image file for reading in binary mode
    std::ifstream imageFile("C:\\Users\\kunal\\OneDrive\\CODE FOR LIFE\\DSA repo github\\File_Handling_C++\\File_functions.jpg", std::ios::binary);
    if (!imageFile) {
        std::cout << "Error opening image file\n";
        return 1;
    }

    // Opening binary file for writing in binary mode
    std::ofstream binFile("output.bin", std::ios::binary);
    if (!binFile) {
        std::cout << "Error opening binary file\n";
        imageFile.close(); // Close the image file if the binary file opening fails
        return 1;
    }

    // Reading image file into a vector
    std::vector<char> fileBuffer(std::istreambuf_iterator<char>(imageFile), {});

    // Write the vector to the binary file
    binFile.write(fileBuffer.data(), fileBuffer.size());

    // Close both the image and binary files
    imageFile.close();
    binFile.close();

    // Display a success message
    std::cout << "Conversion successful!\n";

    return 0;
}
