//
// Created by Acer on 21-11-2024.
//

#include "PatternDatabase.h"

using namespace std;

PatternDatabase::PatternDatabase(const size_t size) :
        database(size, 0xFF), size(size), numItems(0) {
}

PatternDatabase::PatternDatabase(const size_t size, uint8_t init_val) :
        database(size, init_val), size(size), numItems(0) {
}

// If the index is already set, it does nothing and returns false
// Else it sets ind and returns true

bool PatternDatabase::setNumMoves(const uint32_t ind, const uint8_t numMoves) {
    uint8_t oldMoves = this->getNumMoves(ind);

//    New item is getting added
    if(oldMoves == 0xF){
        ++this->numItems;
    }

    if(oldMoves > numMoves){
        this->database.set(ind, numMoves);
        return true;
    }
    return false;

}

bool PatternDatabase::setNumMoves(const RubiksCube &cube, const uint8_t numMoves) {
    return this->setNumMoves(this->getDatabaseIndex(cube), numMoves);
}

uint8_t PatternDatabase::getNumMoves(const uint32_t ind) const {
    // cout<<"Ind: "<<ind<<endl;
    // cout<<this->database.get(ind)<<endl;
    return this->database.get(ind);
}

uint8_t PatternDatabase::getNumMoves(const RubiksCube &cube) const {
    return this->getNumMoves(this->getDatabaseIndex(cube));
}

size_t PatternDatabase::getSize() const {
    return this->size;
}

size_t PatternDatabase::getNumItems() const {
    return this->numItems;
}

bool PatternDatabase::isFull() const {
    return this->numItems == this->size;
}

void PatternDatabase::toFile(const string &filePath) const {

    // Open file in binary mode with truncation
    std::ofstream writer(filePath, std::ios::out | std::ios::binary | std::ios::trunc);

    // Check if the file was opened successfully
    if (!writer.is_open()) {
        throw std::runtime_error("Failed to open the file to write");
    }

    // Output database size for debugging
    std::cout << "Database size: " << this->database.storageSize() << std::endl;

    // Ensure data pointer and size are valid before writing
    const char* dataPtr = reinterpret_cast<const char*>(this->database.data());
    std::size_t dataSize = this->database.storageSize();

    // Check if data pointer is not null and size is greater than zero
    if (dataPtr == nullptr || dataSize == 0) {
        throw std::runtime_error("Invalid database data or size");
    }

    // Write data to the file
    writer.write(dataPtr, dataSize);

    // Optionally check for write errors
    if (!writer) {
        throw std::runtime_error("Failed to write data to the file");
    }

    // The writer will be closed automatically when it goes out of scope
}

// Returns true of database is loaded successfully
// else return false

bool PatternDatabase::fromFile(const string &filePath) {
    ifstream reader(filePath, ios::in | ios::ate);

    if(!reader.is_open())
        return false;

    size_t fileSize = reader.tellg();

    if(fileSize != this->database.storageSize()){
        reader.close();
        throw "Database corrupt! Failed to open Reader";
    }

    reader.seekg(0, ios::beg);
    reader.read(
            reinterpret_cast<char*> (this->database.data()),
            this->database.storageSize()
            );
    reader.close();
    this->numItems = this->size;
    return true;
}

vector<uint8_t> PatternDatabase::inflate() const {
    vector<uint8_t> inflated;
    this->database.inflate(inflated);
    return inflated;
}

void PatternDatabase::reset() {
    if(this->numItems != 0){
        this->database.reset(0xFF);
        this->numItems = 0;
    }
}