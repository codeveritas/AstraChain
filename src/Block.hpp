#ifndef ASTRACHAIN_BLOCK_HPP
#define ASTRACHAIN_BLOCK_HPP

#include <string>

#include "BlockContent.hpp"

/**
 * Block with a block content and a hash to its ancestor
 */
class Block {

// private:
public:
    BlockContent blockContent;
    std::string hash;

public:

    Block();

    Block(BlockContent _blockContent, std::string _hash);

    ~Block();

};

#endif //ASTRACHAIN_BLOCK_HPP
