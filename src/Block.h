#pragma once
#include "BlockContent.h"
#include <string>

using namespace std;

struct Block {
    BlockContent blockContent;
    string blockHash;
};
