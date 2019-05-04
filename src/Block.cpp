#include "Block.hpp"

Block::Block() {}

Block::Block(BlockContent _blockContent, std::string _hash) : blockContent(_blockContent), hash(_hash) {}

Block::~Block() {}