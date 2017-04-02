//
// Created by Krzysiek on 30.03.2017.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>

namespace memorychunk {

    class MemoryChunk {
        MemoryChunk(size_t sz);
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;
    };

}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
